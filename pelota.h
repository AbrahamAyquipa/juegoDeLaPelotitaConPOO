#pragma once
#include <iostream>
using namespace std;
using namespace System;

//definicion de la clase
class Pelota {
private:
	short x, y;
	short dx, dy;
	char forma;

public:
	Pelota();
	~Pelota();
	//metodos de servicio
	void borrar();
	void mover();
	void dibujar();
};

Pelota::Pelota() {
	x = 2;
	y = 20;
	//velocidad
	dx = dy = 1;
	forma = 79; // O
}

Pelota::~Pelota() {}

//metodos de servicio
void Pelota::borrar() {
	//borrar circulo
	Console::SetCursorPosition(x, y); cout << " ";
}

//manejar el control dentro del recuadro
void Pelota::mover() {
	if (x > 78 || x < 1) dx *= -1;
	if (y > 38 || y < 1) dy *= -1;
	x = x + dx; //actualizar y
	y = y + dy; //actualizar x
}

//dibujar la forma
void Pelota::dibujar() {
	Console::SetCursorPosition(x, y); cout << forma;
}
