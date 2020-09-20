#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "Choferes.h"
#include "viajes.h"
#include "validaciones.h"
const char archivoviajes[] = ("viajes.dat");

void menuViaje() {
    int opc;
    do
    {
        system("cls");
        cout << "--------------MENU VIAJES----------------" << endl;
        cout << "--------------" << endl << endl;

        cout << "1) NUEVO VIAJE" << endl;
        cout << "2) LISTAR VIAJE POR ID VIAJE" << endl;
        cout << "3) LISTAR TODOS LOS VIAJES" << endl << endl;;
        cout << "4) ELIMINAR VIAJE" << endl;
        cout << "----------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
        cout << "INGRESE SU OPCION: " << endl << ">";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1: altaViaje();
            break;
        case 2: listarPorIdViaje();
            break;
        case 3: listarViajes();
            break;
        case 4: bajaViaje();
            break;
        case 0:
            break;
        }
    } while (opc != 0);
}
/******************************************************************/
void altaViaje() {
    int pos;
    viajes reg;
    choferes chof;

    reg = cargarViaje();
    if (reg.viajeEstado == true) {
        pos = buscarDni(chof.dni);
        if (pos != -1) {
            cout << "EL DNI YA EXISTE" << endl << endl;
            system("pause");
            return;
        }
        guardarViaje(reg);
    }
}
/********************************************************************/
viajes cargarViaje() {
    viajes viaj;
    char DNI[10];
    int d;
    viaj.id= 1 + cantRegistroViaje();
    cout << "ID: "<<viaj.id<<endl;
    cout << "INGRESE EL DNI DEL CHOFER: ";
    cin.ignore();
    cargarCadena(DNI, 10);
    d=buscarDni(DNI);
    if (d!=-1)
    {
        strcpy(viaj.dni,DNI);
    }
    cout << "ID DE CLIENTE: ";
    cin >> viaj.idCliente;
    cout << "FECHA DE VIAJE: "; // menor o igual a fecha actual
    cout << "DIA: ";
    cin >> viaj.viaje.dia;
    cout << "MES: ";
    cin >> viaj.viaje.mes;
    cout << "A" << (char)165 << "O: ";
    cin >> viaj.viaje.año;
    cout << "INGRESAR LA HORA: ";
    cin >> viaj.hora;
    cout << "KILOMETROS: ";
    cin >> viaj.km;
    cout << "IMPORTE: ";
    cin >> viaj.importe;
    cout << "PATENTE: ";
    cin.ignore();
    cargarCadena(viaj.patente, 10);
    cout << "CALIFICACION: ";
    cin >> viaj.calificacion;

    viaj.viajeEstado = true;

    system("cls");

    return viaj;
}
/***********************************************************/
bool guardarViaje(viajes viaj) {

    FILE* p;
    p = fopen(archivoviajes, "ab");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO de viajes";
        system("pause");
        system("cls");
        return false;
    }
    if (fwrite(&viaj, sizeof(viaj), 1, p) == true) {

        fclose(p);
        cout << "REGISTRO GUARDADO CON EXITO";
        system("pause");
        return true;
    }

    fclose(p);
}/**************************************************************/
int cantRegistroViaje() {

    FILE* p;
    p = fopen(archivoviajes, "rb");
    if (p == NULL) {
        return 0;
    }
    int cant;
    viajes aux;
    fseek(p, 0, 2);
    //0 INICIO SEEK_SET
    //1 cursor SEEL_CUT
    //2 FIN SEEK_END
    cant = ftell(p);
    fclose(p);

    return cant / sizeof(aux);
}
/********************************************************************/
void listarViajes() {

    FILE* p;
    p = fopen(archivoviajes, "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO";
        system("pause");
        system("cls");
        return;
    }
    viajes viaj;
    int cant;
    cant = cantRegistroViaje();
    for (int i = 0; i < cant; i++)
    {
        viaj = leerRegistroV(i);
        mostrarViajes(viaj);
    }
    system("pause");
    fclose(p);
}
/***********************************************************************/
viajes leerRegistroV(int pos) {

    FILE* p;
    p = fopen(archivoviajes, "rb");
    viajes aux;
    fseek(p, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1, p);
    fclose(p);

    return aux;
}
/****************************************************************************/
void mostrarViajes(viajes viaj) {

    if (viaj.viajeEstado == false) return;
    cout << "ID:" << viaj.id << endl;
    cout << "DNI CHOFER:" << viaj.dni << endl;
    cout << "ID CLIENTE: " << viaj.idCliente<< endl;
    cout << "FECHA DE VIAJE: " << viaj.viaje.dia << "/" << viaj.viaje.mes << "/" << viaj.viaje.año << endl;
    cout << "HORA: " <<viaj.hora << endl;
    cout << "KILOMETROS: " << viaj.km << endl;
    cout << "IMPORTE: " << viaj.importe << endl;
    cout << "PATENTE: " << viaj.patente << endl;
    cout << "CALIFICACION: " << viaj.calificacion << endl;
    cout << "--------------------------------------------------" << endl << endl;
}
/***********************************************************************************/
void listarPorIdViaje() {
    int pos;
    viajes aux;
    int id;
    cout << "INGRESE EL ID A LISTAR: ";
    cin >> id;
    pos=buscarID(id);
    aux = leerRegistroV(pos);
    mostrarViajes(aux);
    system("pause");
}
/*************************************************************************************/
int buscarID(int id) {
    FILE* p;
    int pos = 0;
    p = fopen(archivoviajes, "rb");
    if (p==NULL)
    {
        cout << "NO SE PUEDE ABRIR";
        return -1;
    }
    viajes viaj;
    while (fread(&viaj, sizeof(viajes), 1, p) == 1) {
        if (viaj.id== id) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
/*****************************************************************/
void bajaViaje() {
    FILE* p;
    int pos;
    int id;
    viajes viaj;
    p = fopen(archivoviajes, "rb+");
    if (p == NULL)
    {
        cout << "ERROR AL CARGAR ARCHIVO";
        system("pause");
        system("cls");
        return;
    }
    cout << "INGRESE EL ID DE VIAJE A DAR DE BAJA" << endl;
    cin >> id;
    pos = buscarID(id);
    if (pos != -1)
    {
        fseek(p, pos * sizeof(viaj), SEEK_SET);
        viaj.viajeEstado = false;
        fwrite(&viaj, sizeof(viaj), 1, p);
        fclose(p);
        cout << "EL VIAJE SE DIO DE BAJA CORRECTAMENTE" << endl;
        system("pause");
        return;
    }
    else
    {
        cout << "NO EXISTE EL ID" << endl;
        system("pause");
        return;
    }
}
