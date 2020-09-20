#pragma once
struct fecha
{
    int dia;
    int mes;
    int año;
};

struct choferes
{
    char dni[10];
    char apellido[50];
    char nombre[50];
    fecha fechaIng;
    char cuit[20];
    int tipoRegistro;
    fecha fechaVen;
    char telefono[15];
    bool propietario;
    bool estado;

};

struct viajes
{
    int id;
    char dni[10];
    int idCliente;
    fecha viaje;
    int hora;
    float km;
    float importe;
    char patente[10];
    int calificacion;
    bool viajeEstado;
};