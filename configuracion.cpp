#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "Choferes.h"
#include "viajes.h"
#include "validaciones.h"
#include "configuracion.h"

void configuracion() {

	int opc;
	do
	{
		system("cls");
		cout << "-----------------------MENU CONFIGURACION--------------------" << endl;
		cout << "1)REALIZAR BACKUP" << endl;
		cout << "2)RESTAURAR BACKUP" << endl;
		cout << "3)CARGAR DATOS INICIALES" << endl;
		cout << "----------------------------------"<< endl;
		cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
		cout << "INGRESE LA OPCION" << endl << ">";
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	} while (opc != 0);
}
