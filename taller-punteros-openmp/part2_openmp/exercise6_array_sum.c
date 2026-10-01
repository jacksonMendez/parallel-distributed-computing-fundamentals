/**
 * Exercise 6: Parallel Array Sum Using OpenMP
 * 
 * Description:
 *   Computes the sum of elements in a large array (N = 10,000,000) using both
 *   a sequential approach and a parallel approach with OpenMP.
 *   Uses: #pragma omp parallel for reduction(+:sum)
 *   Measures execution times with omp_get_wtime() and reports:
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
#include <omp.h>

#define N 10000000L // 10 million elements

int main(void) {
    printf("========================================================\n");
    printf("     Exercise 6: Parallel Array Sum with OpenMP         \n");
    printf("========================================================\n");
    printf("Problem size (N): %ld elements\n", N);
    printf("Memory required: %.2f MB\n\n", (double)(N * sizeof(int)) / (1024.0 * 1024.0));

    // Allocate memory on the heap to avoid stack overflow
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for array of size %ld.\n", N);
        return 1;
    }

    // Initialize the array (deterministic values for reproducibility)
    for (long i = 0; i < N; i++) {
        array[i] = (int)((i % 10) + 1); // Values between 1 and 10
    }

    // -------------------------------------------------------------
    // 1. Sequential execution
    // -------------------------------------------------------------
    printf("Running sequential execution...\n");
    long long seq_sum = 0;
    double t_seq_start = omp_get_wtime();

    for (long i = 0; i < N; i++) {
        seq_sum += array[i];
    }

    double t_seq_end = omp_get_wtime();
    double t_seq = t_seq_end - t_seq_start;

    // -------------------------------------------------------------
    // 2. Parallel execution with OpenMP
    // -------------------------------------------------------------
    printf("Running parallel execution with OpenMP...\n");
    long long par_sum = 0;
    int num_threads = 0;
    double t_par_start = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            num_threads = omp_get_num_threads();
        }

        #pragma omp for reduction(+:par_sum)
        for (long i = 0; i < N; i++) {
            par_sum += array[i];
        }
    }

    double t_par_end = omp_get_wtime();
    double t_par = t_par_end - t_par_start;

    // -------------------------------------------------------------
    // 3. Validation and Metrics Calculation
    // -------------------------------------------------------------
    int is_correct = (seq_sum == par_sum);
    double speedup = (t_par > 0.0) ? (t_seq / t_par) : 0.0;
    double efficiency = (num_threads > 0) ? (speedup / num_threads) : 0.0;

    printf("\n========================================================\n");
    printf("                   RESULTS & METRICS                    \n");
    printf("========================================================\n");
    printf("Sequential Sum:        %lld\n", seq_sum);
    printf("Parallel Sum:          %lld\n", par_sum);
    printf("Validation:            %s\n", is_correct ? "PASSED (Results match)" : "FAILED (Mismatch)");
    printf("--------------------------------------------------------\n");
    printf("Sequential Time (Ts):  %.6f seconds\n", t_seq);
    printf("Parallel Time (Tp):    %.6f seconds\n", t_par);
    printf("Number of Threads (P): %d\n", num_threads);
    printf("Experimental Speedup:  %.4fx (S = Ts / Tp)\n", speedup);
    printf("Parallel Efficiency:   %.2f%% (E = S / P)\n", efficiency * 100.0);
    printf("========================================================\n");

    // Clean up allocated heap memory
    free(array);
    array = NULL;

    return 0;
}
