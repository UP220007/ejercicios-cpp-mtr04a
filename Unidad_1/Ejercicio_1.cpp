#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    bool salida = false;
    int renta = 0;
    printf("Bienvenido al sistema calculador de impuestos\n");
    while (!salida)
    {
        printf("ingrese el valor de su renta\n");
        scanf("%i",&renta);
        printf("%i",renta);
        if (renta < 10000)
        {
            printf("concidcional 1\n");
            printf("El impuesto basandonos en su renta de $%i que le corresponde es del 05%\n",renta);
        }
        else if ((renta >= 10000) && (renta <= 20000))
        {
            printf("concidcional 2\n");
            printf("El impuesto basandonos en su renta de $%i que le corresponde es del 15%\n",renta);
        }
        else if ((renta > 20000) && (renta <= 35000))
        {
            printf("concidcional 3\n");
            printf("El impuesto basandonos en su renta de $%i que le corresponde es del 20%\n",renta);
        }
        else if ((renta > 35000) && (renta <= 60000))
        {
            printf("concidcional 4\n");
            printf("El impuesto basandonos en su renta de $%i que le corresponde es del 30%\n",renta);
        }
        else if (renta > 60000)
        {
            printf("concidcional 5\n");
            printf("El impuesto basandonos en su renta de $%i que le corresponde es del 45%\n",renta);
        }
        else
        {
            printf("exepcion\n");
            printf("fuera de rango ingrese un numero valido\n");
        }
        printf("deseas seguir calculando impuestos?\n");
        char out = 'p';
        do
        {
            scanf("%s",&out);
            if (out == 's' || out == 'S')
            {
                salida = false;
                printf("Sigamos calculando entonces\n");
            }
            else if (out == 'n' || out == 'N')
            {
                salida =  true;
                renta = 0;
                printf("nos vemos pasa un ecelente dia\n");
            }
        }while (out != 'n'&& out != 's' && out != 'N' && out != 'S');
    }
    return 0;
}
