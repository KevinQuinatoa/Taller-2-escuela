#include <stdio.h>
#include <string.h>

int main() {
    char nombre[5][20];
    char asignatura[3][30];
    float PromedioC[5][3]; // 5 estudiantes, 3 asignaturas
    float PromedioF[5]; // Promedio final de cada estudiante
    

    // Leer nombres de estudiantes
    for(int i = 0; i < 5; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i+1);
        scanf("%s", nombre[i]);
    }

    // Leer nombres de asignaturas
    for(int j = 0; j < 3; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j+1);
        scanf("%s", asignatura[j]);
    }

    // Leer calificaciones por estudiante y asignatura
    for(int i = 0; i < 5; i++) {
        printf("Ingrese las calificaciones del estudiante %s:\n", nombre[i]);
        float sumaMaterias = 0;
        for(int j = 0; j < 3; j++) {
            float sumaNotas = 0;
            for (int q = 0; q < 2; q++) {
                float calificacion = 0;
                printf("  Calificación %d para %s: ", q+1, asignatura[j]);
                scanf("%f", &calificacion);
                sumaNotas += calificacion;
            }
            PromedioC[i][j] = sumaNotas / 2.0;
            sumaMaterias += PromedioC[i][j];
        }
        PromedioF[i] = sumaMaterias / 3.0;
    }

    // Imprimir tabla de calificaciones
    printf("\n-------------------------------------Calificaciones------------------------------------\n");
    printf("#\tEstudiante\t\t%s\t%s\t%s\tPromedioF\n", asignatura[0], asignatura[1], asignatura[2]);
    for(int i = 0; i < 5; i++) {
        printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\t%.2f\n", i+1, nombre[i], PromedioC[i][0], PromedioC[i][1], PromedioC[i][2], PromedioF[i]);
    }
    return 0;
}