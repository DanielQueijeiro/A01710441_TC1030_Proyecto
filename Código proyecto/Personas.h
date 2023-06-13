/*
    Created by Daniel Queijeiro A01710441 on 18/05/2023.
    Esta clase abstracta nos servira para definir al objeto Persona,
    de la cuál crearemos las clases hijas: Estudiante, Profesor, y Empleado.
    La clase tendrá atributos básicos que cualquier persona tiene:
    Nombre, edad, y lugar natal.
    Al igual que tendrá métodos para acceder a esos datos.
    Y un método con el que podremos aplicar polimorfismo.
*/
#ifndef PERSONAS_H
#define PERSONAS_H

#include <sstream>
#include <iostream>

using namespace std;

class Personas {
private: //Atributos
    string nombre;
    int edad;
    string lugarNatal;

public: //Métodos
    Personas(){}//Constructor base
    Personas(string nom, int age, string lugar);//Constructor
    string getNombre();
    int getEdad();
    string getLugar();
    virtual float calcularPago()=0;
    virtual void mostrarInfo()=0;
};

//Definimos constructores
Personas::Personas(string nom, int age, string lugar) {
    nombre = nom;
    edad = age;
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

//Método para polimorfismo
void Personas::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar: "<<getLugar()<<"\n\n";
}



/*
    Clase hija Estudiante
    Esta clase tendra atributos adicionales que puede tener un estudiante:
    carrera, beca, porcentaje de beca, un arreglo con sus clases, número de clases.
    Y tendrá métodos que permitan obtener información del estudiante
    al igual que métodos para añadirle clases al alumno, y calcular su pago de colegiatura.
*/
class Estudiante : public Personas{
    private://Atributos
        string carrera;
        bool beca;
        float porcBeca;
        int numClases;

    public://Métodos
        Estudiante(): Personas(){}//Constructor base

        //Constructor
        Estudiante(string nom, int age, string ciudad, string career,int clases, bool apoyo, float becaPorc): Personas(nom, age, ciudad){
            numClases = clases;
            carrera = career;
            beca = apoyo;
            porcBeca = becaPorc;
        }

        string getCarrera();
        string getBeca();
        float getPorcBeca();
        int getClases();
        float calcularPago();
        void mostrarInfo();
};

//Getters
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

int Estudiante::getClases() {
    return numClases;
}

/*Método para agregar clases al estudiante
//Método para calcular colegiatura
Igual usamos el apuntador para acceder al valor de numClases
*/
float Estudiante::calcularPago() {
    //Costo de clase $8,105
    if(numClases==0){return 0;}
    else{
        float totalColegiatura = (numClases * 8105)*(1-porcBeca);
        return totalColegiatura;
    }
}


//Método de polimorfismo donde se muestra la información básica y única de la clase estudiante.
void Estudiante::mostrarInfo() {
    cout << "Nombre: " << getNombre() << "\n" << "Edad: " << getEdad() << "\n";
    cout << "Lugar natal: " << getLugar() << "\n" << "Carrera: " << getCarrera() << "\n";
    cout << "Clases inscritas: " << getClases() << "\n";
    cout << getBeca() << "\n";
    if(beca){
        cout<<"Porcentaje de beca: " << getPorcBeca() << "\n";
    }
    if (numClases == 0) {
        cout<<"No hay clases registradas, no se puede calcular el pago mensual \n";
    }
    else {
        cout << "Pago mensual de colegiatura es: " << calcularPago() << "\n\n";
    }
}



/*
    Clase hija Profesor
    Esta clase tendra atributos adicionales que puede tener un profesor:
    un arreglo con sus clases, número de clases, y un salario por clase.
    Y tendrá métodos que permitan obtener información del profesor
    al igual que métodos para añadirle clases al profesor, y calcular su salario total.
*/
class Profesor: public Personas {
private://Atributos
    string clases[10];
    int numClases;
    int salarioClase;

public://Métodos
    Profesor(): Personas(){};//Constructor base

    //Constructor
    Profesor(string nom, int age, string ciudad,int clases, int salarioInd) : Personas(nom, age, ciudad) {
        numClases = clases;
        salarioClase = salarioInd;
    }

    int getClases();
    float calcularPago();
    void mostrarInfo();

};

int Profesor::getClases() {
    return numClases;
}

//Método para calcular el salario total del profesor dependiendo de clases registradas
float Profesor::calcularPago() {
    int salarioTotal = numClases*salarioClase;
    return salarioTotal;
}

//Método de polimorfismo donde se muestra la información básica y única de la clase profesor
void Profesor::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Clases que da: "<<getClases()<<"\n";
    cout<<"Salario mensual: "<<calcularPago()<<"\n\n";
}



/*
    Clase hija Empleado
    Esta clase tendra atributos adicionales que puede tener un empleado:
    un salario mensual, uniforme y Puesto a cumplir.
    Y tendrá métodos que permitan obtener información del empleado
    al igual que métodos para mostrar su información y su salario.
*/
class Empleado:public Personas{
    private://Atributos
        int salarioMensual;
        string uniforme;
        string puesto;

    public://Métodos
        Empleado(): Personas(){};//Constructor base

        //Constructor
        Empleado(string nom, int age, string ciudad, int salarioInd, string _puesto, string uniform): Personas(nom, age, ciudad){
            salarioMensual = salarioInd;
            uniforme = uniform;
            puesto = _puesto;
        }


    string getUniforme();
    string getPuesto();
    float calcularPago();
    void mostrarInfo();
};

//Getters
    string Empleado::getUniforme(){
        return uniforme;
    }

    string Empleado::getPuesto() {
        return puesto;
    }

    float Empleado::calcularPago(){
        return salarioMensual;
    }

//Método de polimorfismo donde se muestra la información básica y única de la clase empleado.
    void Empleado::mostrarInfo() {
        cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
        cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Puesto: "<<getPuesto()<<"\n";
        cout<<"Uniforme: "<<getUniforme()<<"\n"<<"Salario mensual: "<<calcularPago()<<"\n\n";
    }

#endif //PERSONAS_H
