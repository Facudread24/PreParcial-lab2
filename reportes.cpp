#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "Choferes.h"
#include "viajes.h"
#include "validaciones.h"

void menuReportes() {
	int opc;
	do
	{
		system("cls");
		cout << "-----------------------MENU REPORTES--------------------" << endl;
		cout<<"1)REPORTE 1" << endl;
		cout<<"2)REPORTE 2" << endl;
		cout<<"3)REPORTE 3" << endl;
		cout<<"----------------------------------" << endl;
		cout<<"0) VOLVER AL MENU PRINCIPAL" << endl <<endl;
		cout<<"INGRESE LA OPCION"<<endl << ">";
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
	} while (opc!=0);
}