#include <stdio.h>
#include <string.h>

  struct datosPaciente{
        char nombre [30];
        char sexo[15];
        char direccion[150];
        int edad[10];
        int id[5];
 }datosPaciente[100];

int main(int argc, char const *argv[]){
    
    FILE *archivo;
    memset (datosPaciente,0,sizeof(struct datosPaciente)*100);

    int cantidad;
    printf("Digite la cantidad de pacientes que desea agregar: ");
    scanf("%i", &cantidad);

    int i;

    for (i = 0; i <cantidad; i++)
    {
        fflush(stdin);

        printf("\n datosPaciente[%i] - Digite el nombre: ", i);
        gets(datosPaciente[i].nombre);

        printf("\n datosPaciente[%i] - Digite el sexo: ", i);
        gets(datosPaciente[i].sexo);

        printf("\n datosPaciente[%i] - Digite la direccion: ", i);
        gets(datosPaciente[i].direccion);

        printf("\n datosPaciente[%i] - Digite la edad: ", i);
        scanf("%i", &datosPaciente[i].edad);
    
        printf("\n datosPaciente[%i] - Digite el ID: ", i);
        scanf("%i",&datosPaciente[i].id);

    }

    for (i = 0; i < cantidad; i++)
    {
        printf("\n datosPaciente[%i] - Nombre:  %s", datosPaciente[i].nombre);
        printf("\n datosPaciente[%i] - Sexo: %s", datosPaciente[i].sexo);
        printf("\n datosPaciente[%i] - Direccion: %s", datosPaciente[i].direccion);
        printf("\n datosPaciente[%i] - Edad: %i", datosPaciente[i].edad);
        printf("\n datosPaciente[%i] - ID: %i ", datosPaciente[i].nombre);
    }
    
    archivo = fopen("datosPaciente.db","w");
    if (archivo)
    {
        fwrite(datosPaciente, sizeof(struct datosPaciente), 100, archivo);
        fclose(archivo);
    }
    
    return 0;

}