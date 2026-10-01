/**
 * Exercise 7: Parallel Dot Product with OpenMP
 * 
 * Description:
 *   Computes the scalar dot product of two large vectors (N = 10,000,000).
 *   Implements both sequential and parallel approaches using OpenMP's reduction
 *   clause. Uses omp_get_thread_num() and omp_get_num_threads() to identify
 *   all worker threads contributing to the computation.
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

#define N 10000000L // 10 million elements

int main(void) {
    printf("========================================================\n");
    printf("     Exercise 7: Parallel Dot Product with OpenMP       \n");
    printf("========================================================\n");
    printf("Vector size (N):  %ld elements\n", N);
    printf("Memory for vectors: 2 x %.2f MB = %.2f MB\n\n", 
           (double)(N * sizeof(double)) / (1024.0 * 1024.0),
           (double)(2 * N * sizeof(double)) / (1024.0 * 1024.0));

    // Dynamic allocation of vectors
    double *vec_a = (double *)malloc(N * sizeof(double));
    double *vec_b = (double *)malloc(N * sizeof(double));

    if (vec_a == NULL || vec_b == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for vectors of size %ld.\n", N);
        free(vec_a);
        free(vec_b);
        return 1;
    }

    // Initialize vectors with predictable values
    for (long i = 0; i < N; i++) {
        vec_a[i] = 1.0 + (double)(i % 5) * 0.1;
        vec_b[i] = 2.0 - (double)(i % 3) * 0.1;
    }

    // -------------------------------------------------------------
    // 1. Sequential computation
    // -------------------------------------------------------------
    printf("Running sequential dot product...\n");
    double seq_dot = 0.0;
    double t_seq_start = omp_get_wtime();

    for (long i = 0; i < N; i++) {
        seq_dot += vec_a[i] * vec_b[i];
    }

    double t_seq_end = omp_get_wtime();
    double t_seq = t_seq_end - t_seq_start;

    // -------------------------------------------------------------
    // 2. Parallel computation with OpenMP
    // -------------------------------------------------------------
    printf("\nRunning parallel dot product with OpenMP...\n");
    printf("Participating OpenMP threads:\n");
    double par_dot = 0.0;
    int num_threads = 0;
    double t_par_start = omp_get_wtime();

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int total = omp_get_num_threads();

        // Print thread diagnostic information safely using critical section
        #pragma omp critical
        {
            printf("  [Thread %2d of %2d] Active and calculating partial dot product\n", 
                   tid, total);
        }

        #pragma omp single
        {
            num_threads = total;
        }

        // Parallel loop with reduction for accumulated sum
        #pragma omp for reduction(+:par_dot)
        for (long i = 0; i < N; i++) {
            par_dot += vec_a[i] * vec_b[i];
        }
    }

    double t_par_end = omp_get_wtime();
    double t_par = t_par_end - t_par_start;

    // -------------------------------------------------------------
    // 3. Validation and Metrics Calculation
    // -------------------------------------------------------------
    // Note: Due to floating-point non-associativity in parallel reduction,
    // sequential and parallel sums may have minute rounding discrepancies.
    double difference = fabs(seq_dot - par_dot);
    double rel_error = (seq_dot != 0.0) ? (difference / fabs(seq_dot)) : difference;
    int is_correct = (rel_error < 1e-6); // Standard numerical relative tolerance
    double speedup = (t_par > 0.0) ? (t_seq / t_par) : 0.0;
    double efficiency = (num_threads > 0) ? (speedup / num_threads) : 0.0;

    printf("\n========================================================\n");
    printf("                   RESULTS & METRICS                    \n");
    printf("========================================================\n");
    printf("Sequential Dot Product: %.6f\n", seq_dot);
    printf("Parallel Dot Product:   %.6f\n", par_dot);
    printf("Absolute Difference:    %.6e\n", difference);
    printf("Relative Difference:    %.6e\n", rel_error);
    printf("Validation:             %s (Rel. error < 1e-6)\n", is_correct ? "PASSED" : "FAILED");
    printf("--------------------------------------------------------\n");
    printf("Sequential Time (Ts):   %.6f seconds\n", t_seq);
    printf("Parallel Time (Tp):     %.6f seconds\n", t_par);
    printf("Number of Threads (P):  %d\n", num_threads);
    printf("Experimental Speedup:   %.4fx (S = Ts / Tp)\n", speedup);
    printf("Parallel Efficiency:    %.2f%% (E = S / P)\n", efficiency * 100.0);
    printf("========================================================\n");

    // Clean up allocated heap memory
    free(vec_a);
    free(vec_b);
    vec_a = NULL;
    vec_b = NULL;

    return 0;
}
