/**
 * Exercise 8: Parallel Matrix Multiplication with OpenMP
 * 
 * Description:
 *   Multiplies two square matrices A and B of size N x N (N = 600) using 1D
 *   contiguous dynamic heap memory to prevent stack overflow.
 *   Compares sequential multiplication against OpenMP parallelization on the
 *   outermost loop (#pragma omp parallel for).
 *   Uses omp_get_thread_num() to monitor and display which threads process
 *   the rows of the resulting matrix.
 *   Reports:
 *     - Sequential time (Ts)
 *     - Parallel time (Tp)
 *     - Number of threads (P)
 *     - Experimental Speedup (S = Ts / Tp)
 *     - Parallel Efficiency (E = S / P)
 * 
 * Course: Parallel and Distributed Computing Fundamentals
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 600 // Matrix dimension N x N

int main(void) {
    printf("========================================================\n");
    printf("     Exercise 8: Parallel Matrix Multiplication (OpenMP)\n");
    printf("========================================================\n");
    printf("Matrix dimension (N x N): %d x %d\n", N, N);
    size_t total_elements = (size_t)N * N;
    double mem_per_matrix = (double)(total_elements * sizeof(double)) / (1024.0 * 1024.0);
    printf("Heap memory per matrix:   %.2f MB (Total: 4 x %.2f MB = %.2f MB)\n\n",
           mem_per_matrix, mem_per_matrix, mem_per_matrix * 4.0);

    // 1D contiguous dynamic allocations
    double *A     = (double *)malloc(total_elements * sizeof(double));
    double *B     = (double *)malloc(total_elements * sizeof(double));
    double *C_seq = (double *)malloc(total_elements * sizeof(double));
    double *C_par = (double *)malloc(total_elements * sizeof(double));

    if (A == NULL || B == NULL || C_seq == NULL || C_par == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for matrices.\n");
        free(A); free(B); free(C_seq); free(C_par);
        return 1;
    }

    // Initialize input matrices with predictable values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i * N + j] = ((i + j) % 10) * 0.1;
            B[i * N + j] = ((i * j) % 7) * 0.1;
            C_seq[i * N + j] = 0.0;
            C_par[i * N + j] = 0.0;
        }
    }

    // -------------------------------------------------------------
    // 1. Sequential Matrix Multiplication
    // -------------------------------------------------------------
    printf("Running sequential matrix multiplication...\n");
    double t_seq_start = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C_seq[i * N + j] = sum;
        }
    }

    double t_seq_end = omp_get_wtime();
    double t_seq = t_seq_end - t_seq_start;

    // -------------------------------------------------------------
    // 2. Parallel Matrix Multiplication with OpenMP
    // -------------------------------------------------------------
    printf("Running parallel matrix multiplication with OpenMP...\n");

    int max_threads = omp_get_max_threads();
    int *rows_per_thread = (int *)calloc(max_threads, sizeof(int));
    int *first_row_thread = (int *)malloc(max_threads * sizeof(int));
    int *last_row_thread = (int *)malloc(max_threads * sizeof(int));

    for (int t = 0; t < max_threads; t++) {
        first_row_thread[t] = -1;
        last_row_thread[t] = -1;
    }

    int num_threads_used = 0;
    double t_par_start = omp_get_wtime();

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int total = omp_get_num_threads();

        #pragma omp single
        {
            num_threads_used = total;
        }

        #pragma omp for
        for (int i = 0; i < N; i++) {
            // Track thread distribution across matrix rows
            if (first_row_thread[tid] == -1) {
                first_row_thread[tid] = i;
            }
            last_row_thread[tid] = i;
            rows_per_thread[tid]++;

            // Matrix multiplication for row i
            for (int j = 0; j < N; j++) {
                double sum = 0.0;
                for (int k = 0; k < N; k++) {
                    sum += A[i * N + k] * B[k * N + j];
                }
                C_par[i * N + j] = sum;
            }
        }
    }

    double t_par_end = omp_get_wtime();
    double t_par = t_par_end - t_par_start;

    // Display thread-to-row distribution mapping
    printf("\nThread distribution across matrix rows (omp_get_thread_num):\n");
    printf("%-10s | %-12s | %-10s | %-12s\n", "Thread ID", "First Row", "Last Row", "Total Rows");
    printf("----------------------------------------------------\n");
    for (int t = 0; t < num_threads_used; t++) {
        printf("Thread %2d  | Row %-7d | Row %-5d | %-10d\n",
               t, first_row_thread[t], last_row_thread[t], rows_per_thread[t]);
    }
    printf("----------------------------------------------------\n");

    // -------------------------------------------------------------
    // 3. Validation and Metrics Calculation
    // -------------------------------------------------------------
    double max_diff = 0.0;
    for (size_t idx = 0; idx < total_elements; idx++) {
        double diff = fabs(C_seq[idx] - C_par[idx]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    int is_correct = (max_diff < 1e-5);
    double speedup = (t_par > 0.0) ? (t_seq / t_par) : 0.0;
    double efficiency = (num_threads_used > 0) ? (speedup / num_threads_used) : 0.0;

    printf("\n========================================================\n");
    printf("                   RESULTS & METRICS                    \n");
    printf("========================================================\n");
    printf("Max Absolute Difference: %.6e\n", max_diff);
    printf("Validation:              %s\n", is_correct ? "PASSED (Matrices match)" : "FAILED (Mismatch)");
    printf("--------------------------------------------------------\n");
    printf("Sequential Time (Ts):    %.6f seconds\n", t_seq);
    printf("Parallel Time (Tp):      %.6f seconds\n", t_par);
    printf("Number of Threads (P):   %d\n", num_threads_used);
    printf("Experimental Speedup:    %.4fx (S = Ts / Tp)\n", speedup);
    printf("Parallel Efficiency:     %.2f%% (E = S / P)\n", efficiency * 100.0);
    printf("========================================================\n");

    // Clean up allocated heap memory
    free(rows_per_thread);
    free(first_row_thread);
    free(last_row_thread);
    free(A);
    free(B);
    free(C_seq);
    free(C_par);

    return 0;
}
