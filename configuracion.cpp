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

		system ("copy choferes.dat choferes.bkp");
		system("copy viajes.dat viajes.bkp");
		cout << " EL BACKUPS SE REALIZO CORRECTAMENTE " << endl;
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
	cout << "¿ PROCEDE A RESTAURAR LOS ARCHIVOS? (S/N)" << endl;
	cin >> d;
	if (d == 's' || d == 'S') {

		system("copy choferes.bkp choferes.dat");
		system("copy viajes.bkp viajes.dat");
		cout << " EL BACKUPS SE REALIZO CORRECTAMENTE " << endl;
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
	cout << "¿ CARGAR DATOS DE INICIO ? (S/N)" << endl;
	cin >> d;
	if (d == 's' || d == 'S') {

		system("copy choferes.ini choferes.dat");
		system("copy viajes.ini viajes.dat");
		cout << " EL BACKUPS SE REALIZO CORRECTAMENTE " << endl;
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