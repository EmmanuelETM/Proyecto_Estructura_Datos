#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int IdP = 0, IdF = 0, IdA = 0;



struct Pabellon{
	int IdPabellon;
	int numero;
	char Pabellon;
	int capacidad;
	float costo;
	char *estado;
};

typedef struct{
	int IdFanatico;
	int edad;
	char *nombre;
	char *sexo;
	char *estado;
}fanatico;

struct asistencias{
	int IdAsistencias, IdFanatico, IdPabellon;
	char *HoraIngreso, HoraSalida;
	char *asistente, *estado;	
};


typedef struct {
	fanatico *array;
	int frente, cola, size;
	unsigned capacidad;
}Queue;


Queue* crearQueue(unsigned capacidad) {
	
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacidad = capacidad;
    queue->frente = queue->size = 0;
    queue->cola = capacidad - 1;
    queue->array = (fanatico*)malloc(queue->capacidad * sizeof(fanatico));
    return queue;
    
}

int lleno(Queue* queue){
	return(queue->size == queue->capacidad);
}
int vacio(Queue* queue){
	return(queue->size == 0);
}

void enqueue(Queue *queue, fanatico fan){
	if(lleno(queue)){
		return;
	}
	
	queue->cola = (queue->cola + 1) % queue->capacidad;
	queue->array[queue->cola] = fan;
	queue->size++;
	printf("Agregado con exito");
	
	
}

fanatico dequeue (Queue* queue){
	
	fanatico emptyFanatico = {0, 0, "", "", ""};
	
	if(vacio(queue)){
		return emptyFanatico;
	}
	
	fanatico fan = queue->array[queue->frente];
	queue->frente = (queue->frente + 1) %queue->capacidad;
	queue->size--;
	return fan;
	
}

/*
void especifico(Queue *queue, int id) {
    Queue tmp;
    crearQueue(&tmp);

    while (!vacio(queue)) {
        fanatico *fan = dequeue(queue);
        if (fan->IdFanatico != id) {
            enqueue(&tmp, fan);
        }
    }
    
    while (!vacio(&tmp)) {
        fanatico *fan = dequeue(&tmp);
        enqueue(queue, fan);
    }
}

*/
fanatico frente(Queue* queue){
	
	fanatico emptyFanatico = {0, 0, "", "", ""};
	
	if(vacio(queue)){
		return emptyFanatico;
	}
	
	return queue->array[queue->frente];
}

fanatico cola(Queue* queue){
	
	fanatico emptyFanatico = {0,0,"", "", ""};
	
	if(vacio(queue)){
		return emptyFanatico;
	}
	
	return queue->array[queue->cola];
}

void liberar(Queue* queue){
	free(queue->array);
	free(queue);
}

fanatico* Elementos(Queue* queue){
	fanatico* elementos = (fanatico*)malloc(queue->size * sizeof(fanatico));
	
	int index = 0;
	int i = queue->frente;
	while (index < queue->size){
		elementos[index++] = queue->array[i];
		i= (i+1) %queue->capacidad;
	}
	return elementos;
}

void liberarElementos(fanatico* elementos){
	free(elementos);
}


int NIdFanatico(){
	IdF++;
	return IdF;
}

int NidAsistente(){
	IdA++;
	return IdA;
}

void limpiar(int x, int y){
	printf("\033[%d;%dH\033[K", y, x);
}

fanatico RegistrarFanatico(){
	
	fanatico fan;
		
	printf("\nIngrese el nombre del Fanatico: ");
	scanf("%s", &fan.nombre);
	printf("\nIngrese la edad: ");
	scanf("%d", &fan.edad);
	printf("\nIngrese el sexo: ");
	scanf("%s", &fan.sexo);
	
	fan.IdFanatico = NIdFanatico();
				
	printf("\nFanatico Registrado exitosamente.");
	
	return fan;
				
}


void main(){

	time_t tiempoActual;
    struct tm *infoTiempo;
    char buffer[110];
    int opcion = 1;
    char tecla;
    struct Pabellon pabellones[2];
    struct asistencias asistencias[6];
    
    //Queues que se van a usar en el programa
    Queue* pA = crearQueue(3);
	Queue* pB = crearQueue(3);
	//Queue* ListaEspera = crearQueue(6);
	
	
    fanatico fanatico1, fanatico2, fanatico3, fanatico4;
    fanatico fan;
    fanatico* arrA;
	fanatico* arrB;

    

	char EstadoA1[20] = "Disponible";
	char EstadoA2[20] = " Ocupado  ";
	char EstadoA3[20] = "Disponible";
	char EstadoB1[20] = " Ocupado  ";
	char EstadoB2[20] = "Disponible";
	char EstadoB3[20] = "Disponible";


	while(1){
		
		
		
		arrA = Elementos(pA);
		arrB = Elementos(pB);
		
		
		do{
			time(&tiempoActual);
   			infoTiempo = localtime(&tiempoActual);
   			
			system("cls");
		
			printf("\n                                        Universidad Catolica del Cibao \n");
			printf("                                                    UCATECI \n");
			printf("                                              Cuatrimestre P2-2023 \n");
			printf("                               Control de asistencias al Bajo Techo Fernando Teruel \n");
			printf("                             Emmanuel Torres 2021-1097 AND Jeyllon Sandoval 2021-1155 \n");
			strftime(buffer, sizeof(buffer), "                                    Fecha: %Y-%m-%d            Hora: %H:%M:%S", infoTiempo);
			printf("%s\n", buffer);
			printf("_______________________________________________________________________________________________________________________ \n");
			printf(" ------- Menu Principal ------ |            Pabellon %s  |       A1       |      A2       |       A3      | \n", "A");
			printf(" [%s] Registrar Pabellones      |              Estado    |   %s   |   %s  |   %s  | \n", (opcion == 1) ? "X" : " ", EstadoA1, EstadoA2, EstadoA3);
			printf(" [%s] Registrar Fanaticos       |         ____________________________________________________________________\n", (opcion == 2) ? "X" : " ");
			printf(" [%s] Ingresar Fanaticos        |\n", (opcion == 3) ? "X" : " ");
			printf(" [%s] Retirar Fanaticos         |            Pabellon %s  |       B1       |       B2      |       B3      | \n", (opcion == 4) ? "X" : " ", "B");
			printf(" [%s] Salir                     |              Estado    |   %s   |   %s  |   %s  | \n", (opcion == 5) ? "X" : " ", EstadoB1, EstadoB2, EstadoB3);
			printf("_______________________________________________________________________________________________________________________\n");
			printf("\n");
			printf("|          ENTRADA DE DATOS          |");

			
			tecla = getch();
			
			switch(tecla){
				case 72:
					opcion = (opcion > 1) ? opcion -1: 5;
					break;
				case 80:
					opcion = (opcion < 5) ? opcion + 1: 1;
					break;
				default:
					break;
			}		
			
			
		    
	    
	   }while(tecla != 13); //13 codigo ASCII enter
	
	
		switch (opcion){
			case 1:
				printf("\n\n");
				
				for(int i = 0; i <= 2; i++){
					
					printf("\nPabellon %d\n", i + 1);
					pabellones[i].IdPabellon = i + 1;
					
					printf("Ingresa el numero del pabellon: ");
        			scanf("%d", &pabellones[i].numero);
        			
        			printf("Ingresa el pabellon (A o B): ");
        			scanf("%s", &pabellones[i].Pabellon);
        			
        			pabellones[i].capacidad = 3;
        			printf("La capacidad predeterminada del pabellon es: %d \n", pabellones[i].capacidad);
        			
        			printf("Ingrese el Costo del pabellon: ");
        			scanf("%f", &pabellones[i].costo);
        			
        			strcpy(pabellones[i].estado, "Disponible");
        			
        			printf("");
				}
				break;
			case 2:
				fan = RegistrarFanatico();
				Sleep(2000);
				
				break;
				
			case 3:

	    		for (int i = 0; i < 2; i++) {
			        printf("   Asistencia %d\n", i + 1);
			
			        asistencias[i].IdAsistencias = i + 1;
			        
			        int idPabellon;
			        struct Pabellon *pabellonEncontrado;
				do {
		            printf("Ingrese el IdPabellon para extraer sus valores: ");
		            scanf("%d", &idPabellon);
		
		            pabellonEncontrado = NULL;
		            for (int j = 0; j < 2; j++) {
		                if (pabellones[j].IdPabellon == idPabellon) {
		                    pabellonEncontrado = &pabellones[j];
		                    break;
		                }
		            }
		
		            if (pabellonEncontrado) {
		                if (strcmp(pabellonEncontrado->estado, "Ocupado") == 0) {
		                    printf("El pabellon con IdPabellon %d ya esta ocupado.\n", idPabellon);
		                    pabellonEncontrado = NULL;
		                } else {
		                    printf("Valores del pabellon encontrado:\n");
		                    printf("Numero: %d\n", pabellonEncontrado->numero);
		                    printf("Pabellon: %c\n", pabellonEncontrado->Pabellon);
		                    printf("Capacidad: %d\n", pabellonEncontrado->capacidad);
		                    printf("Costo: %.2f\n", pabellonEncontrado->costo);
		                    printf("Estado: %s\n", pabellonEncontrado->estado);
		
		                    
		                    strcpy(pabellonEncontrado->estado, "Ocupado");
		                    printf("Estado del pabellon cambiado a: %s\n", pabellonEncontrado->estado);
		                }
		            } else {
		                printf("El pabellon con IdPabellon %d no existe.\n", idPabellon);
		            }
		        } while (!pabellonEncontrado);
		
		    	printf("\n");
		
		        strftime(buffer, sizeof(buffer), "Hora de entrada: %H:%M:%S", infoTiempo);
		        strcpy(asistencias[i].HoraIngreso, buffer);
		        printf("Hora de entrada: %s \n", asistencias[i].HoraIngreso);
		        
		        printf("Ingrese el nombre del asistente acomodador: ");
		        scanf("%s", asistencias[i].asistente);
		        
		        strcpy(asistencias[i].estado, "Disponible");
		
		        printf("\n");
		}
					break;
				case 4:
					
					break;
				case 5:
					
					system("cls");
					
					printf("\n                                        Universidad Catolica del Cibao \n");
					printf("                                                    UCATECI \n");
					printf("                                              Cuatrimestre P2-2023 \n");
					printf("                               Control de asistencias al Bajo Techo Fernando Teruel \n");
					printf("                             Emmanuel Torres 2021-1097 AND Jeyllon Sandoval 2021-1155 \n");
					
					printf("\n\n                                    Muchas Gracias por usar nuestro sistema!      ");
					
					Sleep(2000);
					
					break;
			}
	}



	
	liberarElementos(arrA);
	liberarElementos(arrB);
	liberar(pA);
}




