#include <string>
#include<iostream>
#include<ctime>
#include <cstdio>
#include "validaciones.h"
using namespace std;
bool espaciosVac(char *aux,int num) {
	choferes chof;
	int x;
	char *n;
	switch (num)
	{
	case 1:
		x = strlen(aux);
		if (x == 8) {
			for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if (aux[i] == '\0') {
					cout << "NO INGRESAR ESPACIOS VACIOS"<<endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}
		}

		cout << "DEBE INGRESAR 8 CARACTERES "<< endl;
		system("pause");
		system("cls");
		return false;
	case 2:
		x = strlen(aux);
		if (x <= 50) {
			for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if (aux[i] == '\0') {
					cout << "NO INGRESAR ESPACIOS VACIOS" << endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}
		}
		cout << "DEBE INGRESAR HASTA 50 CARACTERES " << endl;
		system("pause");
		system("cls");
		return false;

	case 3:
		x = strlen(aux);
		if (x <= 50) {
			for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if (aux[i] == '\0') {
					cout << "NO INGRESAR ESPACIOS VACIOS" << endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}
		}

		cout << "DEBE INGRESAR HASTA 50 CARACTERES " << endl;
		system("pause");
		system("cls");
		return false;
		break;

	case 4: 
		x = strlen(aux);
		if (x == 11) {
			for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if (aux[i] == '\0') {
					cout << "NO INGRESAR ESPACIOS VACIOS" << endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}
		}

		cout << "DEBE INGRESAR 11 CARACTERES " << endl;
		system("pause");
		system("cls");
		return false;
	case 5:
		x = strlen(aux);
		if (x == 15) {
			for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if (aux[i] == '\0') {
					cout << "NO INGRESAR ESPACIOS VACIOS" << endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}
		}

		cout << "DEBE INGRESAR 15 CARACTERES " << endl;
		system("pause");
		system("cls");
		return false;
	}
	
}
void fechaActual() {
	time_t tiempo;
	char cad[80];
	struct tm* tmPtr;

	tiempo = time(NULL);
	tmPtr = localtime(&tiempo);

	printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon + 1, 1900 + tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
	strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
	printf("\n\n%s", cad);
}
void cargarCadena(char* pal, int tam) {
	int i;
	fflush(stdin);
	for (i = 0;i < tam;i++) {
		pal[i] = cin.get();
		if (pal[i] == '\n') break;
	}
	pal[i] = '\0';
	fflush(stdin);
}