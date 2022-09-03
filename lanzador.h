//clase controladora->controla el movimiento

#pragma once
#include "pelota.h"
#include <iostream>
using namespace std;

class Lanzador {
private:
	Pelota** arreglo_pelotas; //arreglo que contiene los atributos de pelota
	int* numero_pelotas; //tamaño del arreglo
public:
	Lanzador();
	~Lanzador();
	//metodos de servicio
	void AgregarPelota(Pelota* obj);
	void MostrarPelota();
	int getNumeroPelotas();
};

Lanzador::Lanzador() {
	arreglo_pelotas = nullptr;//arreglo vacio
	numero_pelotas = new int;//asignarle memoria
	*numero_pelotas = 0;//apunta a 0
}

Lanzador::~Lanzador() {}

void Lanzador::AgregarPelota(Pelota* objeto) {
	//crear un arreglo temporal del mismo tipo  y tamaño + 1;
	Pelota** temporal = new Pelota * [*numero_pelotas + 1];
	//copiar todo el arreglo al temporal
	if (arreglo_pelotas != nullptr) {
		for (int i = 0; i < *numero_pelotas; i++)
			temporal[i] = arreglo_pelotas[i];
	}
	//agregar el nuevo elemento
	temporal[*numero_pelotas] = objeto;
	//actualizar el tamaño del arreglo
	*numero_pelotas = *numero_pelotas + 1;
	//eliminar el arreglo original
	if (arreglo_pelotas != nullptr) delete arreglo_pelotas;
	arreglo_pelotas = temporal;
}

void Lanzador::MostrarPelota() {
	for (int i = 0; i < *numero_pelotas; i++) {
		arreglo_pelotas[i]->borrar();
		arreglo_pelotas[i]->mover();
		arreglo_pelotas[i]->dibujar();
	}
}

int Lanzador::getNumeroPelotas() {
	return *numero_pelotas;
}
