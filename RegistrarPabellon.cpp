#include <stdio.h>
#include <string.h>

struct Pabellon {
    int IdPabellon;
    int numero;
    char Pabellon;
    int capacidad;
    float costo;
    char estado[20];  // Cambio en esta línea
};

int main() {
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
    
    return 0;
}
