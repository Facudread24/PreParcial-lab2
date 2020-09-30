#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;
using namespace std;
#include "Choferes.h"
#include "viajes.h"
#include "validaciones.h"
#include "reportes.h"

const char archivoReporte1[] = ("reporte1.dat");

void menuReportes() {
	int opc;
	do
	{
		setColor(BLUE);
		setBackgroundColor(WHITE);
		system("cls");

		locate(45, 7);
		cout << "-------------------------------------------" << endl;
		locate(45, 8);
		cout << "----------------MENU REPORTES--------------" << endl;
		locate(45, 9);
		cout << "-------------------------------------------" << endl;
		locate(52, 10);
		cout<<"1)REPORTE 1" << endl;
		locate(52, 11);
		cout<<"2)REPORTE 2" << endl;
		locate(52, 12);
		cout<<"3)REPORTE 3" << endl;
		locate(45, 13);
		cout << "-------------------------------------------" << endl;
		locate(52, 14);
		cout<<"0) VOLVER AL MENU PRINCIPAL" << endl <<endl;
		locate(45, 15);
		cout << "-------------------------------------------" << endl;
		locate(52, 16);
		cout<<"INGRESE LA OPCION >";
		locate(73, 16);
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:reporte11();
			break;
		case 2:
			break;
		case 3:
			break;
		}
	} while (opc!=0);
}
/*Viajes
1.generar un archivo que tenga los datos de cada chofer, y la cantidad de viajes que haya realizado. No deben aparecer los choferes sin viajes.
2.Calcular e informar el viaje de mayor promedio de importe por kilómetro.
*/
//
void reporte11() {

	reporte1 aux;
	viajes x;
	int cantchof;
	
	FILE* p;

	p = fopen(archivoReporte1, "ab");
	if (p == NULL) {
		return;
	}
	cantchof=cantRegistro();

	for (int i = 0; i < cantchof; i++)
	{
		int cantviaj = 0;
		aux.chof = leerRegistro(i);
		for (int y = 0; y < cantRegistroViaje(); y++)
		{
			x = leerRegistroV(y);
			if (strcmp(aux.chof.dni, x.dni)==0) {
				cantviaj++;
			}

		}
		if (cantviaj>0)
		{
			aux.cantviajes = cantviaj;
			guardarReporte1(aux);
			mostrarChoferes(aux.chof);
			cout << "CANTIDAD DE VIAJES " <<aux.cantviajes << endl;
			system("pause");
			cout << endl<<endl;
			
		}
	}
	fclose(p);
}
void guardarReporte1(reporte1 aux) {

	FILE* p;

	p = fopen(archivoReporte1, "ab");
	if (p==NULL)
	{
		return;
	}
	if(fwrite(&aux,sizeof (reporte1),1,p)==1){
			fclose(p);
			//cout << "REPORTE GUARDADO CON EXITO";
			//system("pause");
			return;
	}
	fclose(p);
}