#pragma once
#include <fstream>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <string>
#include "ListaProfesor.h"
#include "ListaEstudiante.h"
#include "Usuario.h"
#include "Arbol.h"
#include "Horarios.h"
#include "Estudiante.h"
#include "Profesor.h"

using namespace std;
using namespace System;

string nombresss[] = { "Luis", "Ana", "Pedro", "María", "Carlos", "Laura",
"Juan", "Isabella", "Diego", "Valentina", "Miguel", "Camila", "Javier", "Sofía", "Andrés", "Julia", "Fernando", "Lucía", "Gabriel", "Elena" };
string apellidosss[] = { "García", "Rodríguez", "López", "Martínez", "González",
"Pérez", "Sánchez", "Romero", "Ramírez", "Torres", "Flores", "Gómez", "Vargas", "Morales", "Castro", "Herrera", "Mendoza", "Silva", "Ortega", "Rios" };

class Inicio
{
private:
    Estudiante* principal;
    ListaEstudiante<Estudiante*> pacs;
    ListaProfesor<Profesor*> docs;
    Heap<Horarios>* colaprioridad;

    int i;

public:

    Inicio()
    {
        i = -1;
        colaprioridad = new Heap<Horarios>(
            [](Horarios a, Horarios b) {
                return a.getHorario() < b.getHorario();
            }
        );
    }

    bool esNumero(string str, int index = 0) {
        if (index == str.length()) {
            return true;
        }
        if (!isdigit(str[index])) {
            return false;
        }
        return esNumero(str, index + 1);
    }

    void main()
    {
        string opcion;

        do {
            do {
                system("cls");

                cout << "1. <Iniciar Sesion>" << endl;
                cout << "2. <Registrarse>" << endl;
                cout << "3. <Salir>" << endl;
                cout << "\n\n";

                cout << "Elija una opcion: "; cin >> opcion;


            } while (!(opcion >= "1" && opcion <= "3"));

            cin.ignore();

            switch (stoi(opcion))
            {
            case 1: IniciarSesion(); break;
            case 2: Registro(); break;
            case 3: return; break;
            default:
                break;
            }

        } while (true);


    }

    bool archivoVacio()
    {
        bool vacio;

        ifstream archivo("Estudiantes.txt");  // Abre el archivo en modo lectura

        archivo.seekg(0, ios::end);  // Mueve el puntero de lectura al final del archivo

        if (archivo.tellg() == streampos(0)) {
            vacio = true; // No hay Datos
        }
        else {
            vacio = false; // Hay datos
        }

        archivo.close();  // Cierra el archivo

        return vacio;
    }

    void IniciarSesion()
    {
        system("cls");

        if (!archivoVacio())
        {
            ifstream archivo("Estudiantes.txt");

            string line;

            while (getline(archivo, line)) {

                stringstream s(line);
                string nombre, apellido, numero, sede, correo, edad, dni, prioridad, usuario1, contraseña;
                string aux;
                getline(s, nombre, ';');
                getline(s, apellido, ';');
                getline(s, numero, ';');
                getline(s, sede, ';');
                getline(s, correo, ';');
                getline(s, edad, ';');
                getline(s, dni, ';');
                getline(s, usuario1, ';');
                getline(s, contraseña, ';');
                Estudiante* pac = new Estudiante(nombre, apellido, numero, sede, correo, edad, dni, usuario1, contraseña);
                pacs.InsertarFinal(pac);
            }
            archivo.close();

            // Luego de que se guardo en la lista, comparamos con lo que escribe el usuario

            string us, con;
            bool entro = false;

            do {
                Console::ForegroundColor = ConsoleColor::DarkRed;
                Console::SetCursorPosition(10, 2); cout << "INTRANET";
                Console::SetCursorPosition(10, 3); cout << "SOCRATES";
                int alto = 12;
                int ancho = 25;
                int x = 35;
                int y = 9;
                Console::ForegroundColor = ConsoleColor::White;
                Console::SetCursorPosition(x, y);
                for (int i = 0; i < alto; ++i) {
                    Console::SetCursorPosition(x, y);
                    for (int j = 0; j < ancho; ++j) {
                        if (i == 0 || i == alto - 1 || i == 2) {
                            cout << "- ";
                        }
                        else if (j == 0 || j == ancho - 1) {
                            cout << "| ";
                        }
                        else {
                            cout << "  ";
                        }
                    }
                    cout << endl;
                    y++;
                }
                Console::SetCursorPosition(52, 10); cout << "Ingreso a Intranet";
                Console::SetCursorPosition(50, 13); cout << "Usuario: "; getline(cin, us);
                Console::SetCursorPosition(50, 15); cout << "Contraseña: "; getline(cin, con);


                entro = pacs.Buscar(us, con);
                principal = pacs.Principal(us, con);

            } while (!(entro));

            if (entro) Interfaz();
        }
        else {

            cout << "No hay nadie registrado" << endl;
            cout << "\n";
            system("pause");
        }


    }

    void Registro()
    {
        system("cls");

        Estudiante* usuario;
        string nombre, apellido, numero, sede, correo, edad, dni, prioridad, usuario1, contraseña;


        cout << " ____            _     _          " << endl;
        cout << "|  _ \\ ___  __ _(_)___| |_ _ __ ___   " << endl;
        cout << "| |_) / _ \\/ _` | / __| __| '__/ _ \\  " << endl;
        cout << "|  _ <  __/ (_| | \\__ \\ |_| | | (_) | " << endl;
        cout << "|_| \\_\\___|\\__, |_|___/\\__|_|  \\___/  " << endl;
        cout << "           |___/                      " << endl;
        cout << "\n\n\n";

        cout << "Ingrese los siguientes datos: " << endl;
        cout << "\n\n\n";
        cout << "Nombre: "; getline(cin, nombre);
        cout << "Apellido: "; getline(cin, apellido);
        cout << "Numero: "; getline(cin, numero);
        cout << "Sede: "; getline(cin, sede);
        cout << "Dni: "; getline(cin, dni);
        cout << "Correo: "; getline(cin, correo);
        cout << "Edad: "; getline(cin, edad);
        cout << "\n";

        cout << "Ingrese un nombre de Usuario y Contraseña: " << endl;
        cout << "\n\n\n";
        cout << "Nombre de Usuario: "; getline(cin, usuario1);
        cout << "Contraseña: "; getline(cin, contraseña);

        usuario = new Estudiante(nombre, apellido, numero, sede, correo, dni, edad, usuario1, contraseña);

        principal = usuario;

        // Se guardan los datos del Estudiante

        ofstream file("Estudiantes.txt", ios::app);

        if (file.is_open()) {
            string nuevaInformacion;

            file << nombre << ";" << apellido << ";" << numero << ";" << sede << ";" << correo << ";" << dni << ";" << edad << ";" <<
                usuario1 << ";" << contraseña << endl;

            file.close();
        }

        // Se muestran los datos del Estudiante
        ifstream archivo1("Estudiantes.txt");

        if (archivo1) {
            string linea;

            while (getline(archivo1, linea)) {
                cout << linea << endl;
            }

            archivo1.close();
        }
    }

    void Interfaz()
    {
        system("cls");
        string opcion;

        do {
            do {
                system("cls");
                Console::ForegroundColor = ConsoleColor::Yellow;
                Console::SetCursorPosition(10, 2); cout << "INTRANET";
                Console::SetCursorPosition(80, 2); cout << "BIENVENIDO(A): " << principal->getNombre() << " " << principal->getApellido();


                Console::ForegroundColor = ConsoleColor::DarkRed;
                Console::SetCursorPosition(42, 5); cout << "¿Qué información deseas consultar?";

                Console::ForegroundColor = ConsoleColor::White;
                Console::SetCursorPosition(20, 9); cout << "+-----------------------+";
                Console::SetCursorPosition(20, 10); cout << "| 1. Matricula en linea |";
                Console::SetCursorPosition(20, 11); cout << "+-----------------------+";

                Console::SetCursorPosition(49, 9); cout << "+----------------------+";
                Console::SetCursorPosition(49, 10); cout << "| 2. Modificar Horario |";
                Console::SetCursorPosition(49, 11); cout << "+----------------------+";

                Console::SetCursorPosition(80, 9); cout << "+---------------------+";
                Console::SetCursorPosition(80, 10); cout << "| 3. Eliminar Horario |";
                Console::SetCursorPosition(80, 11); cout << "+---------------------+";

                Console::SetCursorPosition(35, 13); cout << "+-----------------+";
                Console::SetCursorPosition(35, 14); cout << "| 4. Ver Horarios |";
                Console::SetCursorPosition(35, 15); cout << "+-----------------+";

                Console::SetCursorPosition(70, 13); cout << "+----------+";
                Console::SetCursorPosition(70, 14); cout << "| 5. Salir |";
                Console::SetCursorPosition(70, 15); cout << "+----------+";

                Console::SetCursorPosition(49, 18); cout << "Escriba una Opcion: "; getline(cin, opcion);

            } while (!(opcion >= "1" && opcion <= "5"));

            switch (stoi(opcion))
            {
            case 1: SepararHorario(); break;
            case 2: ModificarHorario(); break;
            case 3: EliminarHorario(); break;
            case 4: VerHorarios(); break;
            case 5: return;
            default:
                break;
            }
            cout << "\n\n" << endl;
            system("pause");
            cin.ignore();

        } while (true);
    }

    void GenerarProfesor(string curso) // Solo para generar Profesores segun q tipo eliga el usuario
    {
        stringstream ss;
        Random f;
        string n, ap, num, sed, cor, cur;
        int hi;

        for (short j = 0; j < 4; j++)
        {
            i++;
            n = nombresss[rand() % 20];
            ap = apellidosss[f.Next(0, 20)];

            ss << f.Next(900000000, 999999999);
            num = ss.str();
            sed = "Monterrico";
            cor = n + "@gmail.com";

            cur = curso;
            hi = rand() % (8) + 8;

            Profesor* doc = new Profesor(n, ap, num, sed, cor, cur, i, hi);
            docs.InsertarFinal(doc);

            ss.str("");
            ss.clear();
        }
    }

    void SepararHorario()
    {
        string curso;
        string espa;
        do {
            system("cls");

            Console::ForegroundColor = ConsoleColor::DarkRed;

            Console::SetCursorPosition(3, 0); cout << "INTRANET";
            Console::SetCursorPosition(30, 0); cout << "MATRICULA EN LINEA";

            Console::ForegroundColor = ConsoleColor::White;

            Console::SetCursorPosition(5, 2); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 3); cout << "| Cursos Disponibles:                                |";
            Console::SetCursorPosition(5, 4); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 5); cout << "| 1  <Calculo I>                                     |";
            Console::SetCursorPosition(5, 6); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 7); cout << "| 2  <Algoritmos y Estructura de Datos>              |";
            Console::SetCursorPosition(5, 8); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 9); cout << "| 3  <Diseño y Patrones de Software>                 |";
            Console::SetCursorPosition(5, 10); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 11); cout << "| 4  <Especificaciones y Analisis de Requerimientos> |";
            Console::SetCursorPosition(5, 12); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 13); cout << "| 5  <Fisica I>                                      |";
            Console::SetCursorPosition(5, 14); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 15); cout << "| 6  <Matematica Discreta>                           |";
            Console::SetCursorPosition(5, 16); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 17); cout << "| 7  <Seminario de Investigacion Academica>          |";
            Console::SetCursorPosition(5, 18); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 19); cout << "| 8  <Arquitectura de Computadoras>                  |";
            Console::SetCursorPosition(5, 20); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 21); cout << "| 9  <Diseño de Base de Datos>                       |";
            Console::SetCursorPosition(5, 22); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(5, 23); cout << "| 10 <Aplicaciones Web>                              |";
            Console::SetCursorPosition(5, 24); cout << "+----------------------------------------------------+";

            Console::SetCursorPosition(65, 4); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(65, 6); cout << "+----------------------------------------------------+";
            Console::SetCursorPosition(65, 5); cout << "| Escriba el numero de su curso: "; getline(cin, espa);


        } while (!(esNumero(espa) == true && (stoi(espa) >= 1 && stoi(espa) <= 10)));
        switch (stoi(espa))
        {
        case 1: curso = "Calculo I"; break;
        case 2: curso = "Algoritmos y Estructura de Datos"; break;
        case 3: curso = "Diseño y Patrones de Software"; break;
        case 4: curso = "Especificaciones y Analisis de Requerimientos"; break;
        case 5: curso = "Fisica I"; break;
        case 6: curso = "Matematica Discreta"; break;
        case 7: curso = "Seminario de Investigacion Academica"; break;
        case 8: curso = "Arquitectura de Computadoras"; break;
        case 9: curso = "Diseño de Base de Datos"; break;
        case 10: curso = "Aplicaciones Web"; break;

        default:
            break;
        }

        // Generar 
        GenerarProfesor(curso);

        string opcion;
        string correcto;
        Profesor* de1;
        do {
            do {
                system("cls");
                // Mostrar Lista de Profesores
                cout << "Profesores Disponibles: " << endl;
                cout << "\n";
                docs.MostrarListaProfesor();
                cout << "Escriba el indice del Profesor(a): "; getline(cin, opcion);
            } while (!(esNumero(opcion) == true && (stoi(opcion) > i - 3 && stoi(opcion) <= i)));
            system("cls");
            de1 = docs.Buscar(stoi(opcion));

            cout << "¿Es correcto?" << endl;
            cout << "\n";
            de1->toString();
            cout << "\n";
            cout << "Escriba(Si|No): "; getline(cin, correcto);
        } while (!(correcto == "Si"));

        // Guardar Horario 
        stringstream ssP;
        stringstream ssD;
        ssP << principal->getNombre() << " " << principal->getApellido();
        ssD << de1->getNombre() << " " << de1->getApellido();

        Horarios hor = Horarios(ssP.str(), ssD.str(), de1->getCurso(), de1->getHorario());
        colaprioridad->push(hor);

    }

    void ModificarHorario()
    {
        system("cls");

        if (colaprioridad->obtenerTamano() > 0)
        {
            string hora;
            string opcion;

            do {
                system("cls");
                cout << "Elija la Horario que desee modificar (solo hora): " << endl;
                cout << "\n\n";
                colaprioridad->MostrarHorarios();
                cout << "Escriba el NrHorario: "; getline(cin, opcion);

            } while (!(esNumero(opcion) == true && (stoi(opcion) > 0 && stoi(opcion) <= colaprioridad->obtenerTamano())));

            Horarios dec = colaprioridad->getHorariosAtPosition(stoi(opcion) - 1);

            do {
                system("cls");
                dec.MostrarHorario();
                cout << "\n\n";
                cout << "Escriba una hora entre (8-16): "; getline(cin, hora);

            } while (!(esNumero(hora) == true && (stoi(hora) >= 8 && stoi(hora) <= 16)));

            // Para cambiar el horario

            colaprioridad->setHorarioAtPosition(stoi(opcion) - 1, stoi(hora));
        }
        else {
            cout << "Aun no hay Horarios " << endl;
        }
    }

    void EliminarHorario()
    {
        system("cls");

        if (colaprioridad->obtenerTamano() > 0)
        {
            string opcion;

            do {

                system("cls");
                cout << "Elija la Horario que desee eliminar: " << endl;
                cout << "\n\n";
                colaprioridad->MostrarHorarios();

                cout << "Escriba el NrHorario: "; getline(cin, opcion);

            } while (!(esNumero(opcion) == true && (stoi(opcion) > 0 && stoi(opcion) <= colaprioridad->obtenerTamano())));

            colaprioridad->removeAtPosition(stoi(opcion) - 1);

            cout << "Se elimino el Horario" << endl;
        }
        else {
            cout << "Aun no hay Horarios..... " << endl;
        }
    }

    void VerHorarios()
    {
        system("cls");

        if (colaprioridad->obtenerTamano() > 0)
        {
            colaprioridad->print();
        }
        else {
            cout << "Aun no hay Horarios....." << endl;
        }

    }
};

