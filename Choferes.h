#pragma once
#include "tipos.h"
void menuChoferes();
void altaChofer();
bool guardarChofer(choferes chof);
choferes cargarChofer();
choferes leerRegistro(int pos);
int buscarDni(char *chof);
void listarChoferes();
void mostrarChoferes (choferes chof);
int cantRegistro();
void bajaChofer();
void modificarchofer();
bool ChoferMod(choferes chof, int pos);
void listarPorDni();
bool guardar(choferes chof, int pos);