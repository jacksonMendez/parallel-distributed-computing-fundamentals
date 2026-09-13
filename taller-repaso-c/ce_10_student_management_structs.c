/*
 ============================================================================
 File         : ce_10_student_management_structs.c
 Author       : Jeison Mendez
 Date         : 2026-09-12
 Description  : Implements a student management system using structures (struct),
                dynamic array memory allocation, and functions to compute grade
                averages and identify passing students.
 
 Key Concepts:
   - C structures (typedef struct)
   - Array of structures with dynamic memory allocation
   - Function parameter passing for struct pointers

 Compilation:
   gcc ce_10_student_management_structs.c -o ce_10_student_management_structs
 
 Execution:
   ./ce_10_student_management_structs
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_GRADES 3
#define PASSING_GRADE 3.0f

typedef struct {
    int id;
    char name[50];
    float grades[NUM_GRADES];
    float average;
} Student;

float calculateAverage(const float grades[NUM_GRADES]) {
    float sum = 0.0f;
    for (int i = 0; i < NUM_GRADES; i++) {
        sum += grades[i];
    }
    return sum / NUM_GRADES;
}

void displayReport(const Student *students, int count) {
    printf("\n====================================================================\n");
    printf("%-5s | %-20s | %-18s | %-7s | %-8s\n", "ID", "Nombre", "Notas", "Promedio", "Estado");
    printf("--------------------------------------------------------------------\n");

    int passedCount = 0;
    for (int i = 0; i < count; i++) {
        const Student *s = &students[i];
        printf("%-5d | %-20s | %4.1f, %4.1f, %4.1f | %7.2f | %s\n",
               s->id,
               s->name,
               s->grades[0], s->grades[1], s->grades[2],
               s->average,
               (s->average >= PASSING_GRADE) ? "APROBADO" : "REPROBADO");

        if (s->average >= PASSING_GRADE) {
            passedCount++;
        }
    }
    printf("====================================================================\n");
    printf("Total Estudiantes: %d | Aprobados: %d | Reprobados: %d\n", count, passedCount, count - passedCount);
}

int main() {
    int totalStudents = 4;

    printf("=== Ejercicio 10: Gestión de Estudiantes con Estructuras ===\n");
    printf("Reservando memoria dinámicamente para %d estudiantes...\n", totalStudents);

    Student *students = (Student *)malloc((size_t)totalStudents * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "¡Error al reservar memoria para los estudiantes!\n");
        return 1;
    }

    students[0].id = 101;
    strcpy(students[0].name, "Ana Gomez");
    students[0].grades[0] = 4.5f; students[0].grades[1] = 3.8f; students[0].grades[2] = 4.2f;

    students[1].id = 102;
    strcpy(students[1].name, "Carlos Rodriguez");
    students[1].grades[0] = 2.5f; students[1].grades[1] = 2.8f; students[1].grades[2] = 3.1f;

    students[2].id = 103;
    strcpy(students[2].name, "Jeison Mendez");
    students[2].grades[0] = 5.0f; students[2].grades[1] = 4.8f; students[2].grades[2] = 4.9f;

    students[3].id = 104;
    strcpy(students[3].name, "Laura Martinez");
    students[3].grades[0] = 3.0f; students[3].grades[1] = 3.2f; students[3].grades[2] = 2.9f;

    for (int i = 0; i < totalStudents; i++) {
        students[i].average = calculateAverage(students[i].grades);
    }

    displayReport(students, totalStudents);

    free(students);
    students = NULL;

    return 0;
}
