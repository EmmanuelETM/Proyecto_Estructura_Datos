#include <stdio.h>
#include <conio.h>  // Solo para Windows, en otros sistemas usar curses.h o biblioteca equivalente

int main() {
    int opcion = 1;
    char tecla;

    do {
        // Imprime el menú
        system("cls");  // Solo para Windows, en otros sistemas usar "clear"
        printf("===== Menú =====\n");
        printf("%s Opción 1\n", (opcion == 1) ? "->" : "  ");
        printf("%s Opción 2\n", (opcion == 2) ? "->" : "  ");
        printf("%s Opción 3\n", (opcion == 3) ? "->" : "  ");
        printf("================\n");

        // Leer la tecla sin necesidad de presionar Enter
        tecla = getch();

        // Comprobar qué tecla se presionó
        switch (tecla) {
            case 72:  // Flecha arriba
                opcion = (opcion > 1) ? opcion - 1 : 3;
                break;
            case 80:  // Flecha abajo
                opcion = (opcion < 3) ? opcion + 1 : 1;
                break;
            default:
                break;
        }
    } while (tecla != 13);  // 13 es el código ASCII para la tecla Enter

    // Ejecutar la opción seleccionada
    switch (opcion) {
        case 1:
            printf("\nSeleccionaste la opción 1.\n");
            break;
        case 2:
            printf("\nSeleccionaste la opción 2.\n");
            break;
        case 3:
            printf("\nSeleccionaste la opción 3.\n");
            break;
        default:
            printf("\nOpción inválida.\n");
            break;
    }

    return 0;
}
