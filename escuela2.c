#include <stdio.h>
#include <string.h>


int main() {
    char nombre[5][20];
    char asignatura[3][30];
    float PromedioC[5][3]; // 5 estudiantes, 3 asignaturas
    float PromedioF[5]; // Promedio final de cada estudiante
    float maxEstudiante[5], minEstudiante[5];
    float maxAsignatura[3], minAsignatura[3];
    int aprobados[3] = {0}, reprobados[3] = {0};
    int opcion, continuar;
    // valores para controlar si se ingresaron estudiante, asignaturas y calificaciones 
    //anteriormente
    int cantidadE = 0;
    int asignaturaI = 0;
    int calificacionE = 0;

    // continuar con el programa
    do {
        // menu de opciones
         do {
        printf("seleccione una opcion: \n");
        printf("1. ingresar los nombres de los estudiantes\n");
        printf("2. ingrese los nombres de las asignaturas\n");
        printf("3. ingresar las calificaciones\n");
        printf("4. mostrar la tabla de calificaciones con el promedio final\n");
        printf("5. mostrar la nota maxima y minima por estudiante\n");
        printf("6. mostrar el numero de aprobados y reprobados por asignatura\n");
        printf("7. salir\n");
        printf("Ingrese su opcion: ");
         if (scanf("%d", &opcion) != 1) 
         {
            printf("Error: ingrese un numero valido (no letras).\n");
            while (getchar() != '\n'); // limpia el búfer
            continue; // volver a pedir la nota
        }
        if (opcion <1 || opcion>7)
        {
            printf("Opcion no valida, por favor intente de nuevo.\n");
        }
        
       
    } while(opcion <1 || opcion>7);

switch (opcion)
{
case 1:
    // Leer nombres de estudiantes
    do {
        printf("Cuantos estudiantes desea ingresar (max 5): ");
         if (scanf ("%d", &cantidadE) != 1) 
         {
            printf("Error: ingrese un numero valido (no letras).\n");
            while (getchar() != '\n'); // limpia el búfer
            continue; // volver a pedir la cantidad de estudiantes
        }

        if (cantidadE<1 || cantidadE>5){
            printf("cantidad no valida, ingrese un numero entre 1 y 5\n");
            cantidadE=0;
        }

    } while(cantidadE<1 || cantidadE>5); 
    
    for(int i = 0; i < cantidadE; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i+1);
        if (scanf("%d", &nombre[i]) == 1) {
            fflush(stdin);
            printf("Error al leer el nombre\n");
            i--; // Reintentar el mismo estudiante
        }
            else{
            scanf("%s", &nombre[i]);
        }
        
    }
    break;
case 2:
    // Leer nombres de asignaturas
    for(int j = 0; j < 3; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j+1);
        if (scanf("%d", &asignatura[j]) ==1){
            fflush(stdin);
            printf("Error al leer la asignatura\n");
            j--; // Reintentar la misma asignatura
        }
        else{
            scanf("%s", asignatura[j]);
        }
    }
    asignaturaI=1; // controla que las asignaturas fueran ingresadas
    break;

case 3:
// Leer calificaciones por estudiante y asignatura
    if (cantidadE == 0) { // verificar si los estudiantes fueron ingresados con anterioridad
                printf("Primero debe ingresar los estudiantes (opcion 1).\n");
                break;
            }
    

    float calificacion[5][3][2]; // 5 estudiantes, 3 asignaturas, 2 notas por asignatura
    for (int i = 0; i < cantidadE; i++) {
        printf("Ingrese las calificaciones del estudiante %s:\n", nombre[i]);
        float sumaMaterias = 0;

        for (int j = 0; j < 3; j++) {
            float sumaNotas = 0;

            for (int q = 0; q < 2; q++) {
                int valido = 0;
                while (!valido) {
                    printf("  Calificacion %d para %s: ", q + 1, asignatura[j]);
                    int resultado = scanf("%f", &calificacion[i][j][q]);

                    if (resultado != 1) {
                        printf("Error: ingrese un numero valido (no letras).\n");
                        while (getchar() != '\n'); // limpia el búfer
                        continue; // volver a pedir la nota
                    }

                    if (calificacion[i][j][q] < 0 || calificacion[i][j][q] > 10) {
                        printf("Error: la nota debe estar entre 0 y 10.\n");
                        continue;
                    }

                    valido = 1; // si llegó aquí, la nota es válida
                }

                sumaNotas += calificacion[i][j][q];
            }

            PromedioC[i][j] = sumaNotas / 2.0;
            sumaMaterias += PromedioC[i][j];
        }

        PromedioF[i] = sumaMaterias / 3.0;
    }
    calificacionE=1; // controla que las calificaciones fueran ingresadas
    break;

    case 4:
    if (cantidadE == 0) { // verificar si los estudiantes fueron ingresados con anterioridad
                printf("Primero debe ingresar los estudiantes (opcion 1).\n");
                break;
            }
    if (asignaturaI == 0) { // verificar si las asignaturas fueron ingresados con anterioridad
                printf("Ingrese las asignaturas (opcion 2).\n");
                break;
            }
    if (calificacionE == 0) { // verificar si las calificaciones fueron ingresados con anterioridad
                printf("Ingrese las calificaciones (opcion 3).\n");
                break;
            }
    // Imprimir tabla de calificaciones
     printf("\n-------------------------------------Calificaciones------------------------------------\n");
    printf("#\tEstudiante\t\t%s\t%s\t%s\tPromedioF\n", asignatura[0], asignatura[1], asignatura[2]);
    for(int i = 0; i < cantidadE; i++) {
        printf("%d\t%s\t\t\t%.2f\t%.2f\t%.2f\t%.2f\n", i+1, nombre[i], PromedioC[i][0], PromedioC[i][1], PromedioC[i][2], PromedioF[i]);
    }
    break;

    case 5:
    if (cantidadE == 0) { // verificar si los estudiantes fueron ingresados con anterioridad
                printf("Primero debe ingresar los estudiantes (opcion 1).\n");
                break;
            }
    if (asignaturaI == 0) { // verificar si las asignaturas fueron ingresados con anterioridad
                printf("Ingrese las asignaturas (opcion 2).\n");
                break;
            }
    if (calificacionE == 0) { // verificar si las calificaciones fueron ingresados con anterioridad
                printf("Ingrese las calificaciones (opcion 3).\n");
                break;
            }
    // Calcular promedios, máximos y mínimos por estudiante
    for (int i = 0; i < 5; i++) {
        float max = PromedioC[i][0];
        float min = PromedioC[i][0];
        for (int j = 1; j < 3; j++) {
            if (PromedioC[i][j] > max) max = PromedioC[i][j];
            if (PromedioC[i][j] < min) min = PromedioC[i][j];
        }
        maxEstudiante[i] = max;
        minEstudiante[i] = min;
    }
    printf("\n---------------------- NOTA MAXIMA Y MINIMA POR ESTUDIANTE ----------------------\n"); 
    for (int i = 0; i < 5; i++) { 
    printf("%-20s\tMax: %.2f\tMin: %.2f\n", nombre[i], maxEstudiante[i], minEstudiante[i]);
    };
    break;
    case 6:
    if (cantidadE == 0) { // verificar si los estudiantes fueron ingresados con anterioridad
                printf("Primero debe ingresar los estudiantes (opcion 1).\n");
                break;
            }
    if (asignaturaI == 0) { // verificar si las asignaturas fueron ingresados con anterioridad
                printf("Ingrese las asignaturas (opcion 2).\n");
                break;
            }
    if (calificacionE == 0) { // verificar si las calificaciones fueron ingresados con anterioridad
                printf("Ingrese las calificaciones (opcion 3).\n");
                break;
            }
    // Calcular promedio, máximo, mínimo y aprobados/reprobados por asignatura
    for (int j = 0; j < 3; j++) {
        float suma = 0;
        float max = PromedioC[0][j];
        float min = PromedioC[0][j];
 
        for (int i = 0; i < 5; i++) {
            suma += PromedioC[i][j];
 
            if (PromedioC[i][j] > max) max = PromedioC[i][j];
            if (PromedioC[i][j] < min) min = PromedioC[i][j];
 
            if (PromedioC[i][j] >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }
 
        PromedioF[j] = suma / 5;
        maxAsignatura[j] = max;
        minAsignatura[j] = min;
    }

    
    
    printf("\n---------------------- APROBADOS Y REPROBADOS POR ASIGNATURA ----------------------\n");
    for (int j = 0; j < 3; j++) {
        printf("%-15s\tAprobados: %d\tReprobados: %d\n", asignatura[j], aprobados[j], reprobados[j]);
    }
    break;
    case 7:
    printf("saliendo del programa...\n");
    break;
} 
printf("desea continuar en el programa 1=si 2=no : ");
scanf("%d", &continuar);
    } while(continuar==1);
   
}    