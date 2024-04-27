#include <conio.h>
#include "Usuario.h"

typedef unsigned int uint;
using namespace std;
using namespace System;

template<class T>
class Node {

public:

	T valor;
	Node<T>* siguiente;

	Node(T v, Node<T>* sig = NULL) {
		valor = v;
		siguiente = sig;
	}
};

template<class T>
class ListaEstudiante
{
private:

	Node<T>* inicio;
	Node<T>* fin;
	uint lon;

public:
	ListaEstudiante()
	{
		inicio = NULL;
		fin = NULL;
		lon = 0;
	}

	bool Buscar(string us, string cont)
	{
		short pos = 0;
		Node<T>* temp = inicio;
		while (temp != NULL)
		{
			Estudiante* pac = (Estudiante*)(temp->valor);
			if (pac->getUsuario() == us && pac->getContraseña() == cont) 
				return true;
			temp = temp->siguiente;
			pos++;
						
		}

		return false;
	}

	T Principal(string us, string cont)
	{
		short pos = 0;
		Node<T>* temp = inicio;
		while (temp != NULL)
		{
			Estudiante* pac = (Estudiante*)(temp->valor);
			if (pac->getUsuario() == us && pac->getContraseña() == cont)
				return pac;
			temp = temp->siguiente;
			pos++;

		}

		return false;
	}

	bool esVacia()
	{
		return (inicio == NULL);
	}

	void InsertarInicio(T v)
	{
		if (inicio == NULL)
		{
			Node<T>* temp = new Node<T>(v, NULL);
			inicio = temp;
			fin = inicio;

		}
		else {

			Node<T>* temp = new Node<T>(v, inicio);
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
			Node<T>* aux = inicio;
			for (short i = 1; i < pos; i++)
			{
				aux = aux->siguiente;
			}

			Node<T>* nuevo = new Node<T>(v, aux->siguiente);

			aux->siguiente = nuevo;

			lon++;
		}
	}

	void InsertarFinal(T v)
	{
		InsertarPosicion(v, lon);
	}
	
	void MostrarListaEstudiante()
	{
		Node<T>* temp = inicio;
		while (temp != NULL)
		{
			Estudiante* doc = (Estudiante*)(temp->valor);
			doc->MostrarEstudiante();
			temp = temp->siguiente;
			cout << "\n\n\n";
		}
		cout << "\n";

	}
};
