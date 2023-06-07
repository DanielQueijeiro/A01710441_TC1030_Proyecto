/*
    Created by Daniel Queijeiro A01710441 on 24/05/2023.
    Esta clase nos sirve para definir al objeto Campus, el cual almacenara mediante agregación
    a estudiantes, profesores y empleados.
    Sus atributos son: nombre del campus, matriculas únicas para estudiantes y profesores, e ID's
    para los empleados.
    Al igual que la parte mas importante, arreglos de cada subclase de Persona que será registrada.
*/

#ifndef CAMPUS_H
#define CAMPUS_H

#include "Personas.h"
//Incluimos el archivo Personas.h para poder trabajar con el

class Campus{
    private://Atributos
        string nombre;
        int matriculaEst;
        int matriculaProf;
        int emplID;
        Estudiante arrEstudiantes[1000];
        Profesor arrProfesores[1000];
        Empleado arrEmpleados[1000];

    public://Métodos
        Campus(){//Constructor base
            nombre = ""; matriculaEst = 0; matriculaProf = 0; emplID = 0;
        }
        Campus(string nom);//Constructor

        string getNombre();

        void agregarEstudiante(Estudiante estudiante);
        void mostrarEstudiantes();

        void agregarProfesor(Profesor profesor);
        void mostrarProfesores();

        void agregarEmpleado(Empleado empleado);
        void mostrarEmpleados();

        void mostrarPersonas();

};

Campus::Campus(string nom) {
    nombre = nom;
}

//Getter
string Campus::getNombre() {
    return nombre;
}


//Métodos relacionados a estudiantes
//Agregar estudiante al campus
void Campus::agregarEstudiante(Estudiante estudiante){
    arrEstudiantes[matriculaEst] = estudiante;//Se le asigna una matricula al alumno
    matriculaEst++;
}

//Muestra la información de todos los estudiantes en el campus
void Campus::mostrarEstudiantes(){
    if (matriculaEst == 0) {
        cout << "No hay estudiantes registrados " << endl;
    } else {
        for (int i = 0; i < matriculaEst; i++) {
            cout << "Matricula del estudiante: A" << i << endl;
            //Usamos método de estudiante para mostrar su información
            arrEstudiantes[i].mostrarInfo();
            cout << "\n";
        }
    }
}


//Métodos relacionados a profesores

//Agregar profesores al campus
void Campus::agregarProfesor(Profesor profesor) {
    arrProfesores[matriculaProf] = profesor;//Se le asigna una matrícula al profesor
    matriculaProf++;
}

//Muestra la información de todos los profesores en el campus
void Campus::mostrarProfesores() {
    if (matriculaProf == 0) {
        cout << "No hay profesores registrados " << endl;
    } else {
        for (int i = 0; i < matriculaProf; i++) {
            cout << "Matricula del profesor: P" << i << endl;
            //Usamos método de profesor para mostrar su información
            arrProfesores[i].mostrarInfo();
            cout << "\n";
        }
    }
}



//Métodos relacionados a empleados

//Agregar empleados al campus
void Campus::agregarEmpleado(Empleado empleado) {
    arrEmpleados[emplID] = empleado;
    emplID++;
}

//Muestra la información de todos los empleados en el campus
void Campus::mostrarEmpleados() {
    if (matriculaProf == 0) {
        cout << "No hay empleados registrados " << endl;
    }
    else {
        for (int i = 0; i < emplID; i++) {
            cout << "ID del empleado: ID" << i << endl;
            //Usamos método de empleado para mostrar su información
            arrEmpleados[i].mostrarInfo();
            cout << "\n";
        }
    }
}

//Muestra el número total de personas en el campus, divididas por subclase
void Campus::mostrarPersonas() {
    //Estudiantes
    if (matriculaEst == 0) {
        cout << "No hay estudiantes registrados " << endl;
    } else {
        cout << "Total de estudiantes registrados: " << matriculaEst << endl;
        for (int i = 0; i < matriculaEst; i++) {
            //Usamos método de estudiante para obtener nombre
            cout << arrEstudiantes[i].getNombre() << endl<<endl;
        }
    }

    //Profesores
    if (matriculaProf == 0) {
        cout << "No hay profesores registrados " << endl;
    } else {
        cout <<"Total de profesores registrados: " << matriculaProf << endl;
        for (int i = 0; i < matriculaProf; i++) {
            //Usamos método de profesor para obtener nombre
            cout << arrProfesores[i].getNombre() << endl<<endl;
        }
    }

    //Empleados
    if (emplID == 0) {
        cout << "No hay empleados registrados " << endl;
    }
    else {
        cout << "Total de empleados registrados: " << emplID << endl;
        for (int i = 0; i < emplID; i++) {
            cout << arrEmpleados[i].getNombre() << endl<<endl;
            }
        }
}
#endif //CAMPUS_H
