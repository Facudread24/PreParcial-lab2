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
	}
	
}
int compFecha(int i, int x, int z)
{
	int Mes, Dia, A�o, pos;
	time_t t = time(NULL);
	struct tm today = *localtime(&t);
	Mes = today.tm_mon + 1;
	Dia = today.tm_mday;
	A�o = (today.tm_year + 1900);

	if (z < A�o || z == A�o && x == Mes && i < Dia || z == A�o && x < Mes)
	{
		pos = -1;
		return pos;
	}
	else
		if (i == Dia && x == Mes && z == A�o)
		{
			pos = 0;
			return pos;
		}
		else {
			pos = 1;
			return pos;
		}
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