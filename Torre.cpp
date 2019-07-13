#include <iostream>
#include <time.h>

/*
José Pablo Ramírez Mayorga 
*/

using namespace std;

int contadorMovimientos = 0;

void jugar(int disco, int pTorre, int sTorre, int tTorre)
{
    contadorMovimientos++;
    if (disco == 1)
    {
        cout << "Moviendo el disco de la torre numero => " << pTorre << " hacia la torre numero => " << tTorre << endl;
    }
    else
    {
        jugar(disco - 1, pTorre, tTorre, sTorre);
        cout << "Moviendo el disco de la torre numero => " << pTorre << " hacia la torre numero => " << tTorre << endl;
        jugar(disco - 1, sTorre, pTorre, tTorre);
    }
};

void iniciarJuego()
{
    char continuar;

    clock_t tiempo;
    tiempo = clock();
    int primeraTorre = 1;
    int segundaTorre = 2;
    int terceraTorre = 3;
    int disco = 0;

    cout << "Digite la cantidad de discos con la que quiere jugar => ";
    cin >> disco;

    jugar(disco, primeraTorre, segundaTorre, terceraTorre);
    tiempo = clock() - tiempo;
    cout << "Cantidad de movimientos => " << contadorMovimientos << endl;
    cout << "Duracion del juego => " << ((float)tiempo / CLOCKS_PER_SEC) << " segundos " << endl;

    cout << "Desea continuar?";
    cin >> continuar;

    contadorMovimientos = 0;
    if (continuar == 'y')
    {
        iniciarJuego();
    }
    else
    {
        exit(0);
    }
}

int main(int argc, char const *argv[])
{
    iniciarJuego();
    return 0;
}
