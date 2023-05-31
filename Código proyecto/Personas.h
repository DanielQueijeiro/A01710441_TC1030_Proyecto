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
    virtual void mostrarInfo() = 0;
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
        int colegiatura;
        string clases[10];
        string claseInd;
        int numClases;

    public:
        Estudiante(): Personas(){}

        Estudiante(string nom, int age, string career, bool apoyo): Personas(nom, age){
            carrera = career;
            beca = apoyo;
            colegiatura = 0;
            numClases = 0;
            claseInd = "";
        }

        Estudiante(string nom, int age, string ciudad, string career, bool apoyo, float becaPorc): Personas(nom, age, ciudad){
            carrera = career;
            beca = apoyo;
            porcBeca = becaPorc;
            colegiatura = 0;
            numClases = 0;
            claseInd = "";
        }
        void setCarrera(string career);
        void setBeca(bool apoyo);
        void setPorcBeca(float becaPorc);

        string getCarrera();
        string getBeca();
        float getPorcBeca();

        void agregarClases(string claseInd);
        int obtenerColegiatura();
        void mostrarClases();
        void mostrarInfo();
};

string Estudiante::getCarrera() {
    return carrera;
}

string Estudiante::getBeca() {
    if(beca==true){
        return "Tiene beca";
    }
    else{
        return "No tiene beca";
    }
}

float Estudiante::getPorcBeca() {
    if(beca == true){
        return porcBeca;
    }
    else{
        return 0;
    }
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
    numClases++;
}

int Estudiante::obtenerColegiatura() {
    //Costo de clase $8,105
    if(numClases>0){
    int totalColegiatura = (numClases * 8105)*(1-porcBeca);
    return totalColegiatura;}
    else{
        return 0;
    }
}

void Estudiante::mostrarClases() {
    cout<<"Las clases registradas son: ";
    for(int i; i<numClases; i++){
        cout<<clases[i]<<"  ";
    }
    cout<<"\n";
}

void Estudiante::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Carrera: "<<getCarrera()<<"\n";
    cout<<"Clases inscritas: "<<numClases<<"\n";
    cout<<getBeca()<<"\n"<<"Porcentaje de beca: "<<getPorcBeca()<<"\n";
    cout<<"Pago mensual de colegiatura es: "<<obtenerColegiatura()<<"\n\n";
}




//Clase hija Profesor
class Profesor: public Personas {
private:
    string clases[10];
    int numClases;
    int salarioClase;

public:
    Profesor(): Personas(){};

    Profesor(string nom, int age, int salarioInd) : Personas(nom, age) {
        numClases = 0;
        salarioClase = salarioInd;
    }

    Profesor(string nom, int age, string ciudad, int salarioInd) : Personas(nom, age, ciudad) {
        numClases = 0;
        salarioClase = salarioInd;
    }

    void agregarClases (string claseInd);
    void mostrarClases();
    int obtenerSalario();
    void mostrarInfo();
    void setSalario(int salarioInd);

};

void Profesor::setSalario(int salarioInd) {
    salarioClase = salarioInd;
}

void Profesor::agregarClases(string claseInd) {
    clases[numClases] = claseInd;
    numClases++;
}

void Profesor::mostrarClases() {
    cout<<"Las clases registradas son: ";
    for(int i; i<numClases; i++){
        cout<<clases[i]<<"  ";
    }
    cout<<"\n";
}

int Profesor::obtenerSalario() {
    int salarioTotal = numClases*salarioClase;
    return salarioTotal;
}

void Profesor::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Clases que da: "<<numClases<<"\n";
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

        Empleado(string nom, int age, int salarioInd, string role, string uniform): Personas(nom, age){
            salarioMensual = salarioInd;
            uniforme = uniform;
            rol = role;
        }

    void setUniforme(string uniform);
    void setSalarioMensual(int salarioInd);
    string getUniforme();
    string getRol();
    int obtenerSalario();
    void mostrarInfo();
};

    void Empleado::setUniforme(string uniform){
        uniforme = uniform;
    }

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
