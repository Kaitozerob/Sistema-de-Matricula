#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Horarios
{
private:
	string nombreEstudiante;
	string nombreProfesor;
	string curso;
	int horario;
public:
	Horarios()
	{
		nombreEstudiante = "";
		nombreProfesor = "";
		curso = "";
		horario = 0;
	}

	Horarios(string ne, string np, string cur, int hor)
	{
		// Fecha
		stringstream ss; 

		time_t tiempoActual = time(nullptr);
		tm* op = localtime(&tiempoActual);

		int dia = op->tm_mday;
		int mes = op->tm_mon + 1;
		int anio = op->tm_year + 1900;

		ss << dia << "/" << mes << "/" << anio;

		// Otros

		nombreEstudiante = ne;
		nombreProfesor = np;
		curso = cur;
		horario = hor;
	}

	void MostrarHorario()
	{
		cout << "+--------------------------------------------------------+" << endl;
		cout << "  Nombre del Profesor: " << nombreProfesor << endl;
		cout << "  Curso: " << curso << endl;
		cout << "  Horario: " << horario << ":00 - " << horario+2 << ":00" << endl;
		cout << "+--------------------------------------------------------+";
	}

	int getHorario() { return horario; }
	void setHorario(int dato) { horario = dato; }

	bool operator>(Horarios r) {
		return horario < r.getHorario();
	}
};

