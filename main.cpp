#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Choferes.h"
#include "viajes.h"
#include "reportes.h"
#include "configuracion.h"
#include "validaciones.h"

int main() {
    
    int opc;
    do
    {
        system("cls");
        cout << "--------------MENU PRINCIPAL----------------" << endl;
        cout << "--------------" << endl << endl;

        cout << "1) CHOFERES" << endl;
        cout << "2) VIAJES" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACION" << endl << endl;;
        cout << "----------------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl << endl;
        cout << "INGRESE SU OPCION: "<<endl<<">";
        cin >> opc;

        switch (opc)
        {
            system("cls");
        case 1: menuChoferes();
            break;
        case 2: menuViaje();
            break;
        case 3: menuReportes();
            break;
        case 4: configuracion();
            break;
        case 0:
            break;

        }
    } while (opc != 0);
return 0;
}
