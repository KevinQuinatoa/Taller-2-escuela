#include <stdio.h>

int main() {
    char nombre[5][20];
    char asignatura[3][30];
    float PromedioC[5][3] = {0}; // calificaciones por estudiante y asignatura y cambio
    float PromedioF[5] = {0};    // promedio final por estudiante

    float maxEstudiante[5], minEstudiante[5];
    int aprobados[3] = {0}, reprobados[3] = {0};
    int opcion, continuar;
    int cantidadE = 0, asignaturaI = 0, calificacionE = 0; // verificar  si se ingresaron los datos del case 1, 2 y 3

    do {
        // menú principal
        do {
            printf("\nSeleccione una opcion:\n");
            printf("1. Ingresar los nombres de los estudiantes\n");
            printf("2. Ingresar los nombres de las asignaturas\n");
            printf("3. Ingresar las calificaciones\n");
            printf("4. Mostrar tabla de calificaciones con promedio final\n");
            printf("5. Mostrar nota maxima y minima por estudiante\n");
            printf("6. Mostrar aprobados y reprobados por asignatura\n");
            printf("7. Salir\n");
            printf("Ingrese su opcion: ");

            if (scanf("%d", &opcion) != 1) {
                printf("Error: ingrese un numero valido (no letras).\n");
                while (getchar() != '\n');
                continue;
            }

            if (opcion < 1 || opcion > 7) {
                printf("Opción no valida, por favor intente de nuevo.\n");
            }

        } while (opcion < 1 || opcion > 7);

        switch (opcion) {

        case 1:
            // Ingresar nombres de estudiantes
            do {
                printf("Cuantos estudiantes desea ingresar (1-5): ");
                if (scanf("%d", &cantidadE) != 1) {// validar entrada
                    printf("Error: ingrese un numero valido.\n");
                    while (getchar() != '\n');// limpiar buffer
                    continue;
                }
                if (cantidadE < 1 || cantidadE > 5) {
                    printf("Cantidad no valida. Debe ser entre 1 y 5.\n");
                }
            } while (cantidadE < 1 || cantidadE > 5);

            for (int i = 0; i < cantidadE; i++) {
                printf("Ingrese el nombre del estudiante %d: ", i + 1);
                scanf("%s", nombre[i]);
            }
            break;

        case 2:
            // Ingresar nombres de asignaturas
            for (int j = 0; j < 3; j++) {
                printf("Ingrese el nombre de la asignatura %d: ", j + 1);
                scanf("%s", asignatura[j]);
            }
            asignaturaI = 1;
            break;

        case 3:
            if (cantidadE == 0) {
                printf("Primero debe ingresar los estudiantes (opcion 1).\n");
                break;
            }
            if (asignaturaI == 0) {
                printf("Primero debe ingresar las asignaturas (opcion 2).\n");
                break;
            }

            int materiaSeleccionada;
            while (1) { // filtro para los caracteres no numericos y fuera de rango
                printf("\nSeleccione la asignatura para ingresar calificaciones:\n");
                for (int j = 0; j < 3; j++) {
                    printf("%d. %s\n", j + 1, asignatura[j]);
                }
                printf("Ingrese el numero de la asignatura (1-3): ");

                if (scanf("%d", &materiaSeleccionada) != 1) {
                    printf("Error: ingrese un numero valido (no letras).\n");
                    while (getchar() != '\n');// limpiar buffer
                    continue;
                }

                if (materiaSeleccionada < 1 || materiaSeleccionada > 3) {
                    printf("Error: ingrese un numero entre 1 y 3.\n");
                    continue;
                }

                break;
            }

            {
                int indiceMateria = materiaSeleccionada - 1;
                printf("\nIngresando calificaciones para: %s\n", asignatura[indiceMateria]);

                for (int i = 0; i < cantidadE; i++) {
                    float suma = 0;
                    printf("\nEstudiante: %s\n", nombre[i]);

                    for (int n = 0; n < 2; n++) {
                        float nota;
                        while (1) {
                            printf("  Calificacion %d: ", n + 1);
                            if (scanf("%f", &nota) != 1) {
                                printf("Error: ingrese un numero valido.\n");
                                while (getchar() != '\n');
                                continue;
                            }
                            if (nota < 0 || nota > 10) {
                                printf("Error: la nota debe estar entre 0 y 10.\n");
                                continue;
                            }
                            break;
                        }
                        suma += nota;
                    }
                    PromedioC[i][indiceMateria] = suma / 2.0;
                }

                // Calcular promedio final de cada estudiante
                for (int i = 0; i < cantidadE; i++) {
                    float total = 0;
                    int materias = 0;
                    for (int k = 0; k < 3; k++) {
                        if (PromedioC[i][k] > 0) {
                            total += PromedioC[i][k];
                            materias++;
                        }
                    }
                    PromedioF[i] = (materias > 0) ? total / materias : 0;
                }

                calificacionE = 1;
                printf("\n Calificaciones registradas correctamente para %s.\n", asignatura[indiceMateria]);
            }
            break;

        case 4:
            if (!cantidadE || !asignaturaI || !calificacionE) {
                printf("Debe completar las opciones 1, 2 y 3 primero.\n");
                break;
            }
            // imprimir la tabla de calificacioness

            printf("\n---------------------------------- CALIFICACIONES ----------------------------------\n");
            printf("#\t%-15s\t%s\t%s\t%s\tPromedioF\n", "Estudiante", asignatura[0], asignatura[1], asignatura[2]);
            for (int i = 0; i < cantidadE; i++) {
                printf("%d\t%-15s\t%.2f\t%.2f\t%.2f\t%.2f\n", i + 1, nombre[i],
                       PromedioC[i][0], PromedioC[i][1], PromedioC[i][2], PromedioF[i]);
            }
            break;

        case 5:
            if (!cantidadE || !asignaturaI || !calificacionE) {
                printf("Debe completar las opciones 1, 2 y 3 primero.\n");
                break;
            }
            // calcular y mostrar nota maxima y minima por estudiante
            printf("\n--------------- NOTA MAXIMA Y MINIMA POR ESTUDIANTE ---------------\n");
            for (int i = 0; i < cantidadE; i++) {
                float max = PromedioC[i][0], min = PromedioC[i][0];
                for (int k = 1; k < 3; k++) {
                    if (PromedioC[i][k] > max) max = PromedioC[i][k];
                    if (PromedioC[i][k] < min) min = PromedioC[i][k];
                }
                printf("%-15s\tMax: %.2f\tMin: %.2f\n", nombre[i], max, min);
            }
            break;

        case 6: {
            if (!cantidadE || !asignaturaI || !calificacionE) {
                printf("Debe completar las opciones 1, 2 y 3 primero.\n");
                break;
            }

            int materiaSeleccionada6;
            while (1) { // filtro para los caracteres no numericos y fuera de rango permite hacer varias consultas
                printf("\nSeleccione la asignatura que desea consultar:\n");
                for (int a = 0; a < 3; a++) {
                    printf("%d. %s\n", a + 1, asignatura[a]);
                }
                printf("Ingrese el numero de la asignatura (1-3): ");

                if (scanf("%d", &materiaSeleccionada6) != 1) { // validar entrada solo una vez
                    printf("Error: ingrese un numero valido (no letras).\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (materiaSeleccionada6 < 1 || materiaSeleccionada6 > 3) {
                    printf("Error: numero fuera de rango.\n");
                    continue;
                }
                break;
            }

            int idx = materiaSeleccionada6 - 1;
            aprobados[idx] = 0;
            reprobados[idx] = 0;

            printf("\n---------------------- RESULTADOS DE %s ----------------------\n", asignatura[idx]);
            printf("#   %-15s %-15s %-10s\n", "Estudiante", "Promedio", "Estado");
            printf("-------------------------------------------------------------\n");

            for (int i = 0; i < cantidadE; i++) {
                char estado[12];
                if (PromedioC[i][idx] >= 6.0) {
                    sprintf(estado, "Aprobado");
                    aprobados[idx]++;
                } else {
                    sprintf(estado, "Reprobado");
                    reprobados[idx]++;
                }
                printf("%-3d %-15s %-15.2f %-10s\n", i + 1, nombre[i], PromedioC[i][idx], estado);
            }
            printf("-------------------------------------------------------------\n");
            printf("Aprobados: %d   Reprobados: %d\n", aprobados[idx], reprobados[idx]);
            break;
        }

        case 7:
            printf("\nSaliendo del programa...\n");
            return 0;
        }

        // preguntar si desea continuar (solo si no eligió 7)
        do {
            printf("\nDesea continuar en el programa? 1 = Si, 2 = No: ");
            if (scanf("%d", &continuar) != 1) {
                printf("Error: ingrese un numero válido.\n");
                while (getchar() != '\n');
                continue;
            }
        } while (continuar != 1 && continuar != 2);

    } while (continuar == 1);

    return 0;
}
