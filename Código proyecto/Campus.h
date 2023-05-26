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
        Estudiante arrEstudiantes[100];
        Profesor arrProfesores[100];
        Empleado arrEmpleados[100];

    public:
        Campus(){}
        Campus(string nom);

        void agregarEstudiante(Estudiante estudiante);
        void mostrarEstudiantes();
        void agregarProfesor(Profesor profesor);
        void mostrarProfesores();
        void agregarEmpleado(Empleado empleado);
        void mostrarEmpleados();

};

Campus::Campus(string nom) {
    nombre = nom;
}
//Estudiantes
void Campus::agregarEstudiante(Estudiante estudiante) {
    arrEstudiantes[matriculaEst] = Estudiante(estudiante);
    matriculaEst++;
}

void Campus::mostrarEstudiantes() {
    for(int i = 0 ; i <matriculaEst; i++){
        cout<<"Matricula del estudiante: A" << i<<endl;
        arrEstudiantes[i].mostrarInfo();
        cout<<"\n\n";
    }
}

//Profesores
void Campus::agregarProfesor(Profesor profesor) {
    arrProfesores[matriculaProf] = Profesor(profesor);
    matriculaProf++;
}

void Campus::mostrarProfesores() {
    for(int i = 0 ; i <matriculaProf; i++){
        cout<<"Matricula del profesor: P" << i<<endl;
        arrProfesores[i].mostrarInfo();
        cout<<"\n\n";
    }
}

//Empleados
void Campus::agregarEmpleado(Empleado empleado) {
    arrEmpleados[emplID] = Empleado(empleado);
    emplID++;
}

void Campus::mostrarEmpleados() {
    for(int i = 0 ; i <emplID; i++){
        cout<<"ID del empleado: ID" << i<<endl;
        arrEmpleados[i].mostrarInfo();
        cout<<"\n\n";
    }
}

#endif //CAMPUS_H
