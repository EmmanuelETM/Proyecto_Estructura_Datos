#include <stdio.h>
#include <string.h>

int verificarCredenciales() {
    char nombreCorrecto[] = "admin";
    char claveCorrecta[] = "123456";
    char nombre[50];
    char clave[50];
    
    printf("Ingrese su Nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su Clave: ");
    scanf("%s", clave);
    
    if (strcmp(nombre, nombreCorrecto) == 0 && strcmp(clave, claveCorrecta) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void mostrarBienvenida() {
    printf("\nBienvenido(a) a la aplicacion \n");
    printf("Docente de Teoria: Diego Matias \n");
    printf("Docente de Laboratorio: Diego Matias \n");
}

int main() {
    int intentos = 3;
    
    while (intentos > 0) {
        if (verificarCredenciales()) {
            mostrarBienvenida();
            printf("\nCargando...");
            for (int i = 0; i <= 10; i++) {
                printf("\n%d%% completado", i * 10);
            }
            printf("\n Presione ENTER para continuar el programa \n");
            printf("\n");
            break;
        } else {
            printf("\nCredenciales incorrectas. Intentos restantes: %d\n", intentos - 1);
            intentos--;
        }
    }
    
    if (intentos == 0) {
        printf("\nHas excedido el numero de intentos permitidos. El programa ha terminado.\n");
    }
    
    return 0;
}

