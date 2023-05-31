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

        void getNombre();
        void agregarEstudiante(Estudiante estudiante);
        void mostrarEstudiantes();
        void getTotalEstudiantes();

        void agregarProfesor(Profesor profesor);
        void mostrarProfesores();
        void getTotalProfesores();

        void agregarEmpleado(Empleado empleado);
        void mostrarEmpleados();
        void getTotalEmpleados();

};

Campus::Campus(string nom) {
    nombre = nom;
}

void Campus::getNombre() {
    cout<< nombre<<"\n";
}


//Estudiantes
void Campus::agregarEstudiante(Estudiante estudiante) {
    arrEstudiantes[matriculaEst] = estudiante;
    matriculaEst++;
}

void Campus::mostrarEstudiantes() {
    for(int i = 0 ; i <matriculaEst; i++){
        cout<<"Matricula del estudiante: A" << i<<endl;
        arrEstudiantes[i].mostrarInfo();
        cout<<"\n";
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
    for(int i = 0 ; i <matriculaProf; i++){
        cout<<"Matricula del profesor: P" << i<<endl;
        arrProfesores[i].mostrarInfo();
        cout<<"\n";
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
    for(int i = 0 ; i <emplID; i++){
        cout<<"ID del empleado: ID" << i<<endl;
        arrEmpleados[i].mostrarInfo();
        cout<<"\n";
    }
}

void Campus::getTotalEmpleados() {
    cout<<"Total de empleados contratados: "<<emplID;
    cout<<"\n\n";
}


#endif //CAMPUS_H
