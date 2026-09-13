/*
 ============================================================================
 File         : ce_08_grade_assignment.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Converts a numeric score (0 to 100) into a letter grade (A, B,
                C, D, F) using nested conditionals and logical operators.
 
 Key Concepts:
   - Range validation and input bounds checking
   - Nested if-else conditional branches
   - Logical operators (&&, ||)

 Compilation:
   gcc ce_08_grade_assignment.c -o ce_08_grade_assignment
 
 Execution:
   ./ce_08_grade_assignment
 ============================================================================
*/

#include <stdio.h>

char getLetterGrade(double score) {
    if (score < 0.0 || score > 100.0) {
        return 'X';
    }

    if (score >= 90.0) {
        return 'A';
    } else if (score >= 80.0) {
        return 'B';
    } else if (score >= 70.0) {
        return 'C';
    } else if (score >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    double sampleScores[] = {95.5, 83.0, 74.2, 61.8, 45.0, 105.0, -5.0};
    int totalSamples = sizeof(sampleScores) / sizeof(sampleScores[0]);

    printf("=== Ejercicio 8: Notas y Calificaciones ===\n");

    for (int i = 0; i < totalSamples; i++) {
        double score = sampleScores[i];
        char grade = getLetterGrade(score);

        if (grade == 'X') {
            printf("Nota: %6.1f -> ¡Nota inválida! Debe estar entre 0 y 100.\n", score);
        } else {
            printf("Nota: %6.1f -> Calificación en letra: '%c'\n", score, grade);
        }
    }

    return 0;
}
