#include <stdio.h>
#include <time.h>

int main() {
	time_t tiempoActual;
    struct tm *infoTiempo;
    char buffer[110];

    time(&tiempoActual);

    infoTiempo = localtime(&tiempoActual);

	char EstadoA1[20] = "Disponible";
	char EstadoA2[20] = " Ocupado  ";
	char EstadoA3[20] = "Disponible";
	char EstadoB1[20] = " Ocupado  ";
	char EstadoB2[20] = "Disponible";
	char EstadoB3[20] = "Disponible";
	
	
printf("\n                                        Universidad Catolica del Cibao \n");
printf("                                                    UCATECI \n");
printf("                                              Cuatrimestre P2-2023 \n");
printf("                               Control de asistencias al Bajo Techo Fernando Teruel \n");
printf("                             Emmanuel Torres 2021-1097 AND Jeyllon Sandoval 2021-1155 \n");
strftime(buffer, sizeof(buffer), "                                    Fecha: %Y-%m-%d            Hora: %H:%M:%S", infoTiempo);
printf("%s\n", buffer);
printf("_______________________________________________________________________________________________________________________ \n");
printf(" ------ Menu Principal ------ |            Pabellon A  |       A1       |       A2      |       A3      | \n");
printf("  - Registrar Pabellones      |              Estado    |   %s   |   %s  |   %s  | \n", EstadoA1, EstadoA2, EstadoA3);
printf("  - Registrar Fanaticos       |         ____________________________________________________________________\n");
printf("  - Ingresar Fanaticos        |\n");
printf("  - Retirar Fanaticos         |            Pabellon B  |       B1       |       B2      |       B3      | \n");
printf("  - Salir                     |              Estado    |   %s   |   %s  |   %s  | \n", EstadoB1, EstadoB2, EstadoB3);
printf("_______________________________________________________________________________________________________________________\n");
printf("\n");
printf("       ENTRADA DE DATOS");
printf("\n\n\n\n\n\n\n\n\n");
    return 0;
}
