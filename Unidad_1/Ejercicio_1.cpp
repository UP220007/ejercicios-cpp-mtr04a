#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <cstdlib>
#endif
void limpiarPantalla();
void salir();
double calculo(double renta, double impuessto);
bool verifier(int lecturas,double renta);
bool salida = false;
double renta = 0;
int lecturas;
int main(int argc, char const *argv[])
{
    printf("Bienvenido al sistema calculador de impuestos\n");
    do
    {
        do {
            printf("Ingrese el valor de su renta: ");
            lecturas = scanf("%lf", &renta);
        } while (!verifier(lecturas,renta));
        if (renta < 10000)
        {
            double impuesto = calculo(renta,5.0);
            double total = impuesto + renta;
            limpiarPantalla();
            printf("El impuesto basandonos en su renta de $%0.02lf que le corresponde es del 05%% por lo tanto su impuesto es $%0.02lf y su total es de %0.02lf \n",renta,impuesto,total);
        }
        else if ((renta >= 10000) && (renta <= 20000))
        {
            double impuesto = calculo(renta,15.0);
            double total = impuesto + renta;
            limpiarPantalla();
            printf("El impuesto basandonos en su renta de $%0.02lf que le corresponde es del 15%% por lo tanto su impuesto es $%0.02lf y su total es de %0.02lf \n",renta,impuesto,total);
        }
        else if ((renta > 20000) && (renta <= 35000))
        {
            double impuesto = calculo(renta,20.0);
            double total = impuesto + renta;
            printf("El impuesto basandonos en su renta de $%0.02lf que le corresponde es del 20%% por lo tanto su impuesto es $%0.02lf y su total es de %0.02lf \n",renta,impuesto,total);
        }
        else if ((renta > 35000) && (renta <= 60000))
        {
            double impuesto = calculo(renta,30.0);
            double total = impuesto + renta;
            limpiarPantalla();
            printf("El impuesto basandonos en su renta de $%0.02lf que le corresponde es del 30%% por lo tanto su impuesto es $%0.02lf y su total es de %0.02lf \n",renta,impuesto,total);
        }
        else if (renta > 60000)
        {
            double impuesto = calculo(renta,45.0);
            double total = impuesto + renta;
            limpiarPantalla();
            printf("El impuesto basandonos en su renta de $%0.02lf que le corresponde es del 45%% por lo tanto su impuesto es $%0.02lf y su total es de %0.02lf \n",renta,impuesto,total);
        }
        printf("deseas seguir calculando impuestos? (s = si / n=no): ");
        salir();
    }while (!salida);
    return 0;
}

double calculo(double renta, double impuessto){
    double imp = impuessto/100.0*renta;
    return imp;
}

bool verifier(int lecturas, double renta){
    if (lecturas != 1) {
        while (getchar() != '\n'){
            limpiarPantalla();
            printf("Error: Por favor, ingrese un número válido y no un caracter.\n");
        }
        return false;
    } else if (renta < 0) {
        limpiarPantalla();
        printf("Error: Por favor, ingrese un número positivo válido.\n");
        return false;
    } else {
        return  true;
    }
}

void salir(){
    char out = 'p';
    do
    {
        scanf("%c",&out);
        if (out == 's' || out == 'S')
        {
            salida = false;
            limpiarPantalla();
            printf("Sigamos calculando entonces\n");
        }
        else if (out == 'n' || out == 'N')
        {
            salida =  true;
            renta = 0;
            limpiarPantalla();
            printf("nos vemos pasa un ecelente dia\n");
        }else if(out != 'n'&& out != 's' && out != 'N' && out != 'S' && out != ' ' && out != '\n')
        {
            limpiarPantalla();
            printf("Caracter no valido\n");
            printf("deseas seguir calculando impuestos? (s = si / n=no): ");
        }
        
    }while (out != 'n'&& out != 's' && out != 'N' && out != 'S');
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}