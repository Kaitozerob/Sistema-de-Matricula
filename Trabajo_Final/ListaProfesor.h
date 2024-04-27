#pragma once
#include <iostream>
#include <functional>
#include <conio.h>
#include "Usuario.h"

typedef unsigned int uint;
using namespace std;
using namespace System;

template<class T>
class Nodo {

public:

	T valor;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* sig = NULL) {
		valor = v;
		siguiente = sig;
	}
};

template<class T>
class ListaProfesor
{
private:

	Nodo<T>* inicio;
	Nodo<T>* fin;
	uint lon;

public:
	ListaProfesor()
	{
		inicio = NULL;
		fin = NULL;
		lon = 0;
	}

	T Buscar(int v)
	{
		short pos = 0;
		Nodo<T>* temp = inicio;
		while (inicio->siguiente != NULL)
		{
			Profesor* doc = (Profesor*)(temp->valor);
			if (doc->getId() == v) return (doc);
			temp = temp->siguiente;
			pos++;
		}
	}

	bool esVacia()
	{
		return (inicio == NULL);
	}

	void InsertarInicio(T v)
	{

		if (inicio == NULL)
		{
			Nodo<T>* temp = new Nodo<T>(v, NULL);
			inicio = temp;
			fin = inicio;

		}
		else {

			Nodo<T>* temp = new Nodo<T>(v, inicio);
			inicio = temp;

		}

		lon++;

	}

	void InsertarPosicion(T v, uint pos)
	{
		if (pos > lon) return;

		if (pos == 0)
		{
			InsertarInicio(v); return;
		}
		else
		{
			Nodo<T>* aux = inicio;
			for (short i = 1; i < pos; i++)
			{
				aux = aux->siguiente;
			}

			Nodo<T>* nuevo = new Nodo<T>(v, aux->siguiente);

			aux->siguiente = nuevo;

			lon++;
		}
	}

	void InsertarFinal(T v)
	{
		InsertarPosicion(v, lon);
	}
	
	void MostrarListaProfesor()
	{
		Nodo<T>* temp = inicio;
		while (temp != NULL)
		{
			Profesor* doc = (Profesor*)(temp->valor);
			doc->toString();
		    temp = temp->siguiente;
		    cout << "\n";
		}

	}
};
