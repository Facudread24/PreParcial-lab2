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
				if (isdigit(aux[i]==false)) {
					cout << "NO INGRESAR ESPACIOS VACIOS NI LETRAS"<<endl;
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
			/*for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if ((aux[i] == false)) {
					cout << "NO INGRESAR ESPACIOS VACIOS" << endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}*/
			return true;
		}

		cout << "DEBE INGRESAR HASTA 50 CARACTERES " << endl;
		system("pause");
		system("cls");
		return false;

	case 3:
		x = strlen(aux);
		if (x <= 50) {
			/*for (int i = 0; i < x; i++)
			{
				//n=strchr(aux, (char)32);
				if (isdigit(aux[i] == false)) {
					cout << "NO INGRESAR ESPACIOS VACIOS" << endl;
					system("pause");
					system("cls");
					return false;
				}
				return true;
			}*/
			return true;
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
				if (isdigit(aux[i] == false)) {
					cout << "NO INGRESAR ESPACIOS VACIOS NI LETRAS" << endl;
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
				if (isdigit(aux[i] == false)) {
					cout << "NO INGRESAR ESPACIOS VACIOS NI LETRAS" << endl;
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
	}
	
}
bool fechaActual(choferes chof) {
	time_t tiempo;
	char cad[80];
	struct tm* tmPtr;

	tiempo = time(NULL);
	tmPtr = localtime(&tiempo);

	fecha a;

	a.dia = tmPtr->tm_mday;
	a.mes = tmPtr->tm_mon + 1;
	a.año = 1900 + tmPtr->tm_year;
	
	if (chof.fechaIng.dia <= a.dia && chof.fechaIng.mes <= a.mes && chof.fechaIng.año <= a.año) {
		return true;
	}
	if (chof.fechaVen.dia >= a.dia && chof.fechaVen.mes >= a.mes && chof.fechaVen.año > a.año) {
		return true;
	}
	return false;

	/*tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec*/;
	//strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
	//printf("\n\n%s", cad);
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