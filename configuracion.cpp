#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>

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
		case 1:bkprealiz();
			break;
		case 2:bkprest();
			break;
		case 3:datoini();
			break;
		}
	} while (opc != 0);
}
void bkprealiz() {
	char d;
	cout << "¿ PROCEDE A REALIZAR EL BACKUPS ? (S/N)" << endl;
	cin >> d;
	if (d == 's' || d == 'S') {

		if (system("copy choferes.dat choferes.bkp") == false) {
		
			cout << " EL BACKUPS DE CHOFERES SE REALIZO CORRECTAMENTE " << endl;
			
		}
		if (system("copy viajes.dat viajes.bkp") == false) {
		
			cout << " EL BACKUPS DE LOS VIAJES SE REALIZO CORRECTAMENTE " << endl;
			
		}
		system("pause");
	}
	else if (d == 'n' || d == 'N') return;
	else
	{
		cout << "EL CARACTER INGRESADO NO ES VALIDO" << endl;
		system("pause");
		return;
	}
}
void bkprest() {
	char d;
	cout << " ¿ PROCEDE A RESTAURAR LOS ARCHIVOS? (S/N)" << endl;
	cin >> d;
	if (d == 's' || d == 'S') {

		if (system("copy choferes.bkp choferes.dat") == false) {
		
			cout << " LOS DATOS DE LOS CHOFERES SE RESTAURARON CORRECTAMENTE " << endl;
		}
		if (system("copy viajes.bkp viajes.dat") == false) {
		
			cout << " LOS DATOS DE LOS VIAJES SE RESTAURARON CORRECTAMENTE " << endl;
		}
		system("pause");
	}
	else if (d == 'n' || d == 'N') return;
	else
	{
		cout << "EL CARACTER INGRESADO NO ES VALIDO" << endl;
		system("pause");
		return;
	}
}
void datoini() {
	char d;
	cout << " ¿ CARGAR DATOS DE INICIO ? (S/N)" << endl;
	cin >> d;
	if (d == 's' || d == 'S') {

		if (system("copy choferes.ini choferes.dat")==false) {
			
			cout << " LA CARGA DE LOS DATOS DE INICIO DE CHOFERES SE REALIZO CORRECTAMENTE " << endl;
			
		}
		if (system("copy viajes.ini viajes.dat") == false) {
		
			cout << " LA CARGA DE LOS DATOS DE INICIO DE LOS VIAJES SE REALIZO CORRECTAMENTE " << endl;

		}
		
		system("pause");
	}
	else if (d == 'n' || d == 'N') return;
	else
	{
		cout << "EL CARACTER INGRESADO NO ES VALIDO" << endl;
		system("pause");
		return;
	}
}