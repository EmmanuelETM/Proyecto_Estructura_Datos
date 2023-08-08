#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void mostrarBarraCarga(int duracion) {
    int i, j;
    printf("Cargando: ");
    
    for (i = 0; i < 10; i++) {
        printf("   | [");
        for (j = 0; j < i; j++) {
			printf("=");
        }
        printf(">");
        for (j = i + 1; j < 10; j++) {
            printf(" ");
        }
        printf("   ] %d%%", (i + 1) * 10);
        fflush(stdout);
        usleep(duracion * 1000000 / 10);
        printf("\r");
    }
    
    printf("Cargando: [==========>] 100%%\n");
}

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
            int duracion = 3;
			mostrarBienvenida();
		    mostrarBarraCarga(duracion);
		    printf("Carga completa.\n");
            break;
        } else {
            printf("\nCredenciales incorrectas. Intentos restantes: %d\n", intentos - 1);
            intentos--;
        }
    }
    
    if (intentos == 0) {
        printf("\nHas excedido el numero de intentos permitidos. El programa ha terminado.\n");
    }
}



