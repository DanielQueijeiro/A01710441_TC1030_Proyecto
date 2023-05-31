//
// Created by Daniel Queijeiro on 25/05/2023.
//

#ifndef TEC_H
#define TEC_H

#include "Campus.h"

class Tec {
    private:
        string nombre;
        int numCampus;
        Campus arrCampus[25];

    public:
        Tec(){}
        Tec(string nom){nombre=nom;}

        void agregarCampus(Campus campus);
        void mostrarCampus();
        string getCampus(Campus campus);

};

string Tec::getCampus(Campus campus) {
    return campus.getNombre();
}

void Tec::agregarCampus(Campus campus) {
    arrCampus[numCampus] = Campus(campus);
    numCampus++;
}

void Tec::mostrarCampus() {
    for(int i = 0 ; i <numCampus; i++){
        cout<<"Campus: " << arrCampus[i].getNombre()<<endl;
        cout<<"Alumnos inscritos: " <<arrCampus[i].getTotalEstudiantes();
        cout<<"\n\n";
    }
}
#endif //TEC_H
