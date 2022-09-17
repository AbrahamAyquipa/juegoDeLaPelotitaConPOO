#include "pch.h"
#include "Lanzador.h"
#include <conio.h>

using namespace System;

int main() {
	//tamaño de la consola
	Console::SetWindowSize(80, 40);
	//eliminar cursor
	Console::CursorVisible = false;

	//dibuja el lanzador
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(30, 0); cout << "Juego de la pelota";
	Console::ForegroundColor = ConsoleColor::White;

	//define punteros
	Lanzador* ObjetoLanzador;
	Pelota* ObjetoPelota;
	//crear instancia para usar los metodos publicos
	ObjetoLanzador = new Lanzador();

	while (true) {
		//detectar presion en una tecla
		if (_kbhit()) {
			char tecla = getch();//captura la tecla presionada
			tecla = toupper(tecla);
			if (tecla == 'L') {
				ObjetoPelota = new Pelota();
				ObjetoLanzador->AgregarPelota(ObjetoPelota);
			}
		}
		//muestra
		if (ObjetoLanzador->getN() > 0) {
			ObjetoLanzador->MostrarPelotas();
		}
		_sleep(100);
	}
	return 0;
}
