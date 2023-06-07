//
// Created by Daniel Queijeiro on 18/05/2023.
//
#ifndef PERSONAS_H
#define PERSONAS_H

#include <sstream>
#include <iostream>

using namespace std;

class Personas {
private:
    string nombre;
    int edad;
    string lugarNatal;

public:
    Personas(){}
    Personas(string nom, int age);
    Personas(string nom, int age, string lugar);
    void setNombre(string nom);
    void setEdad(int age);
    void setLugar(string lugar);
    string getNombre();
    int getEdad();
    string getLugar();
    virtual void mostrarInfo()=0;
};

//Constructores
Personas::Personas(string nom, int age){
    nombre = nom;
    edad = age;
    lugarNatal = "No hay lugar natal registrado";
}
Personas::Personas(string nom, int age, string lugar) {
    nombre = nom;
    edad = age;
    lugarNatal = lugar;
}

//Setters
void Personas::setNombre(string nom) {
    nombre = nom;
}

void Personas::setEdad(int age) {
    edad = age;
}

void Personas::setLugar(string lugar) {
    lugarNatal = lugar;
}

//Getters
string Personas::getNombre() {
    return nombre;
}

int Personas::getEdad() {
    return edad;
}

string Personas::getLugar() {
    return lugarNatal;
}

void Personas::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar: "<<getLugar()<<"\n\n";
}



//Clase hija Estudiante
class Estudiante : public Personas{
    private:
        string carrera;
        bool beca;
        float porcBeca;
        string clases[10];
        int numClases;
        int *ptr_numClases = &numClases;

    public:
        Estudiante(): Personas(){}

        Estudiante(string nom, int age, string ciudad, string career, bool apoyo, float becaPorc): Personas(nom, age, ciudad){
            carrera = career;
            beca = apoyo;
            porcBeca = becaPorc;
        }
        void setCarrera(string career);
        void setBeca(bool apoyo);
        void setPorcBeca(float becaPorc);

        string getCarrera();
        string getBeca();
        float getPorcBeca();
        int getClases();

        void agregarClases(string claseInd);
        float obtenerColegiatura();
        void mostrarClases();
        void mostrarInfo();
};

string Estudiante::getCarrera() {
    return carrera;
}

string Estudiante::getBeca() {
    if(beca){
        return "Tiene beca";
    }
    else{
        return "No tiene beca";
    }
}

float Estudiante::getPorcBeca() {
    if(beca){
        return porcBeca;
    }
    else{
        return 0;
    }
}

int Estudiante::getClases(){
    return numClases;
}

void Estudiante::setCarrera(string career) {
    carrera = career;
}

void Estudiante::setBeca(bool apoyo) {
    beca = apoyo;
}

void Estudiante::setPorcBeca(float becaPorc) {
    porcBeca = becaPorc;
}

void Estudiante::agregarClases(string claseInd) {
    clases[numClases] = claseInd;
    *ptr_numClases = *ptr_numClases+1;
}

float Estudiante::obtenerColegiatura() {
    //Costo de clase $8,105
    if(*ptr_numClases==0){return 0;}
    else{
        float totalColegiatura = (*ptr_numClases * 8105)*(1-porcBeca);
        return totalColegiatura;
    }
}

void Estudiante::mostrarClases() {
    cout<<"Las clases registradas son: "<<endl;
    for(int i; i<*ptr_numClases; i++){
        cout<<clases[i]<<endl;
    }
}

void Estudiante::mostrarInfo() {
    cout << "Nombre: " << getNombre() << "\n" << "Edad: " << getEdad() << "\n";
    cout << "Lugar natal: " << getLugar() << "\n" << "Carrera: " << getCarrera() << "\n";
    cout << "Clases inscritas: " << *ptr_numClases << "\n";
    cout << getBeca() << "\n";
    if(beca){
        cout<<"Porcentaje de beca: " << getPorcBeca() << "\n";
    }
    if (*ptr_numClases == 0) {
        cout<<"No hay clases registradas, no se puede calcular el pago mensual \n";
    }
    else {
        cout << "Pago mensual de colegiatura es: " << obtenerColegiatura() << "\n\n";
    }
}



//Clase hija Profesor
class Profesor: public Personas {
private:
    string clases[10];
    int numClases;
    int *ptr_numClases = &numClases;
    int salarioClase;

public:
    Profesor(): Personas(){};

    Profesor(string nom, int age, string ciudad, int salarioInd) : Personas(nom, age, ciudad) {
        numClases = 0;
        salarioClase = salarioInd;
    }

    void agregarClases (string claseInd);
    void mostrarClases();
    int obtenerSalario();
    void mostrarInfo();

};

void Profesor::agregarClases(string claseInd) {
    clases[numClases] = claseInd;
    *ptr_numClases = *ptr_numClases+1;
}

void Profesor::mostrarClases() {
    cout<<"Las clases registradas son: ";
    for(int i; i<numClases; i++){
        cout<<clases[i]<<endl;
    }
    cout<<"\n";
}

int Profesor::obtenerSalario() {
    int salarioTotal = *ptr_numClases*salarioClase;
    return salarioTotal;
}

void Profesor::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Clases que da: "<<*ptr_numClases<<"\n";
    cout<<"Salario mensual: "<<obtenerSalario()<<"\n\n";
}



//Clase hija Empleado
class Empleado:public Personas{
    private:
        int salarioMensual;
        string uniforme;
        string rol;

    public:
        Empleado(): Personas(){};

        Empleado(string nom, int age, string ciudad, int salarioInd, string role, string uniform): Personas(nom, age, ciudad){
            salarioMensual = salarioInd;
            uniforme = uniform;
            rol = role;
        }


    string getUniforme();
    string getRol();
    int obtenerSalario();
    void mostrarInfo();
};

    string Empleado::getUniforme(){
        return uniforme;
    }

    string Empleado::getRol() {
        return rol;
    }

    int Empleado::obtenerSalario(){
        return salarioMensual;
    }

    void Empleado::mostrarInfo() {
        cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
        cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Rol: "<<getRol()<<"\n";
        cout<<"Uniforme: "<<getUniforme()<<"\n"<<"Salario mensual: "<<obtenerSalario()<<"\n\n";
    }

#endif //PERSONAS_H
