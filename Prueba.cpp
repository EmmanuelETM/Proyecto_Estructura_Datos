/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

typedef struct {
    int front, rear, size;
    unsigned capacity;
    Employee* array; // Use a single pointer for array
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (Employee*)malloc(queue->capacity * sizeof(Employee));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Employee item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Employee with ID %d enqueued to queue\n", item.id);
}

Employee dequeue(Queue* queue) {
    Employee emptyEmployee = {0, "", 0.0};
    if (isEmpty(queue))
        return emptyEmployee;
    Employee item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

Employee front(Queue* queue) {
    Employee emptyEmployee = {0, "", 0.0};
    if (isEmpty(queue))
        return emptyEmployee;
    return queue->array[queue->front];
}

Employee rear(Queue* queue) {
    Employee emptyEmployee = {0, "", 0.0};
    if (isEmpty(queue))
        return emptyEmployee;
    return queue->array[queue->rear];
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    Queue* queue = createQueue(1000);

    Employee emp1 = {1, "John Doe", 50000.0};
    Employee emp2 = {2, "Jane Smith", 55000.0};
    Employee emp3 = {3, "Mike Johnson", 60000.0};

    enqueue(queue, emp1);
    enqueue(queue, emp2);
    enqueue(queue, emp3);

    Employee dequeuedEmp = dequeue(queue);
    printf("Employee with ID %d dequeued from queue\n", dequeuedEmp.id);

    printf("Front item: ID: %d, Name: %s, Salary: %.2f\n", front(queue).id, front(queue).name, front(queue).salary);
    printf("Rear item: ID: %d, Name: %s, Salary: %.2f\n", rear(queue).id, rear(queue).name, rear(queue).salary);
	
    freeQueue(queue);
    return 0;
}

*/


#include <stdio.h>
#include <string.h>
#include <time.h>

struct Pabellon {
    int IdPabellon;
    int numero;
    char Pabellon;
    int capacidad;
    float costo;
    char estado[20];
};

struct Asistencia {
    int IdAsistencias, IdFanatico, IdPabellon;
    char HoraIngreso[110], HoraSalida[110];
    char asistente[50], estado[20];
};

int main(){
	//Registro de la hora
	time_t tiempoActual;
    struct tm *infoTiempo;
    char buffer[110];

    time(&tiempoActual);

    infoTiempo = localtime(&tiempoActual);
	
	//Registro de los pabellones
	struct Pabellon pabellones[2];
    
    for (int i = 0; i < 2; i++) {
        printf("Pabellon %d\n", i + 1);
        
        pabellones[i].IdPabellon = i + 1;
        
        printf("Ingresa el numero del pabellon: ");
        scanf("%d", &pabellones[i].numero);
        
        printf("Ingresa el Pabellon (A o B): ");
        scanf(" %c", &pabellones[i].Pabellon);
        
        pabellones[i].capacidad = 3;
        printf("La capacidad predeterminada del pabellon es: %d \n", pabellones[i].capacidad);
		
        printf("Ingrese el Costo del pabellon: ");
        scanf("%f", &pabellones[i].costo);
        
        strcpy(pabellones[i].estado, "Disponible");
        
        printf("\n");
    }
	
	//Registro de las asistencias
    struct Asistencia asistencias[6];

    for (int i = 0; i < 2; i++) {
        printf("Asistencia %d\n", i + 1);

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
	
	return 0;
}



