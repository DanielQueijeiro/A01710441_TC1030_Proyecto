//
// Created by Daniel Queijeiro on 24/05/2023.
//

#ifndef CAMPUS_H
#define CAMPUS_H

#include "Personas.h"

class Campus{
    private:
        string nombre;
        int matriculaEst;
        int matriculaProf;
        int emplID;
        Estudiante arrEstudiantes[1000];
        Profesor arrProfesores[1000];
        Empleado arrEmpleados[1000];

    public:
        Campus(){
            nombre = ""; matriculaEst = 0; matriculaProf = 0; emplID = 0;
        }
        Campus(string nom);

        string getNombre();

        void agregarEstudiante(Estudiante estudiante);
        void mostrarEstudiantes();
        void getTotalEstudiantes();

        void agregarProfesor(Profesor profesor);
        void mostrarProfesores();
        void getTotalProfesores();

        void agregarEmpleado(Empleado empleado);
        void mostrarEmpleados();
        void getTotalEmpleados();

        void mostrarPersonas();

};

Campus::Campus(string nom) {
    nombre = nom;
}

string Campus::getNombre() {
    return nombre;
}


//Estudiantes
void Campus::agregarEstudiante(Estudiante estudiante){
    arrEstudiantes[matriculaEst] = estudiante;
    matriculaEst++;
}

void Campus::mostrarEstudiantes(){
    if (matriculaEst == 0) {
        cout << "No hay estudiantes registrados " << endl;
    } else {
        for (int i = 0; i < matriculaEst; i++) {
            cout << "Matricula del estudiante: A" << i << endl;
            arrEstudiantes[i].mostrarInfo();
            cout << "\n";
        }
    }
}

void Campus::getTotalEstudiantes() {
    cout<<"Total de estudiantes inscritos: "<<matriculaEst;
    cout<<"\n\n";
}


//Profesores
void Campus::agregarProfesor(Profesor profesor) {
    arrProfesores[matriculaProf] = profesor;
    matriculaProf++;
}

void Campus::mostrarProfesores() {
    if (matriculaProf == 0) {
        cout << "No hay profesores registrados " << endl;
    } else {
        for (int i = 0; i < matriculaProf; i++) {
            cout << "Matricula del profesor: P" << i << endl;
            arrProfesores[i].mostrarInfo();
            cout << "\n";
        }
    }
}

void Campus::getTotalProfesores() {
    cout<<"Total de profesores contratados: "<<matriculaProf;
    cout<<"\n\n";
}


//Empleados
void Campus::agregarEmpleado(Empleado empleado) {
    arrEmpleados[emplID] = empleado;
    emplID++;
}

void Campus::mostrarEmpleados() {
    if (matriculaProf == 0) {
        cout << "No hay empleados registrados " << endl;
    }
    else {
        for (int i = 0; i < emplID; i++) {
            cout << "ID del empleado: ID" << i << endl;
            arrEmpleados[i].mostrarInfo();
            cout << "\n";
        }
    }
}

void Campus::getTotalEmpleados() {
    cout<<"Total de empleados contratados: "<<emplID;
    cout<<"\n\n";
}

void Campus::mostrarPersonas() {
    if (matriculaEst == 0) {
        cout << "No hay estudiantes registrados " << endl;
    } else {
        cout << "Total de estudiantes registrados: " << matriculaEst << endl;
        for (int i = 0; i < matriculaEst; i++) {
            cout << arrEstudiantes[i].getNombre() << endl<<endl;
        }
    }

    if (matriculaProf == 0) {
        cout << "No hay profesores registrados " << endl;
    } else {
        cout <<"Total de profesores registrados: " << matriculaProf << endl;
        for (int i = 0; i < matriculaProf; i++) {
            cout << arrProfesores[i].getNombre() << endl<<endl;
        }
    }

    if (matriculaProf == 0) {
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
