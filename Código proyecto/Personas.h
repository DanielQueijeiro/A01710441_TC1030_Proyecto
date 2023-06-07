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
        string clases[10];
        int numClases;
        int *ptr_numClases = &numClases;

    public://Métodos
        Estudiante(): Personas(){}//Constructor base

        //Constructor
        Estudiante(string nom, int age, string ciudad, string career, bool apoyo, float becaPorc): Personas(nom, age, ciudad){
            carrera = career;
            beca = apoyo;
            porcBeca = becaPorc;
        }

        string getCarrera();
        string getBeca();
        float getPorcBeca();

        void agregarClases(string claseInd);
        float obtenerColegiatura();
        void mostrarClases();
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

/*Método para agregar clases al estudiante
 * Aquí es importante señalar el uso de apuntadores para aumentar numClases, porque en caso de no usar apuntadores
 * estaríamos creando una variable temporal y no realmente aumentando el valor de numClases, lo cual ocasionaria problemas
 * con otros métodos que ocupan numClases.
*/
void Estudiante::agregarClases(string claseInd) {
    clases[numClases] = claseInd;
    *ptr_numClases = *ptr_numClases+1;
}

//Método para calcular colegiatura
//Igual usamos el apuntador para acceder al valor de numClases
float Estudiante::obtenerColegiatura() {
    //Costo de clase $8,105
    if(*ptr_numClases==0){return 0;}
    else{
        float totalColegiatura = (*ptr_numClases * 8105)*(1-porcBeca);
        return totalColegiatura;
    }
}

//Método para mostrar todas las clases registradas del alumno
void Estudiante::mostrarClases() {
    cout<<"Las clases registradas son: "<<endl;
    for(int i; i<*ptr_numClases; i++){
        cout<<clases[i]<<endl;
    }
}

//Método de polimorfismo donde se muestra la información básica y única de la clase estudiante.
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
    int *ptr_numClases = &numClases;
    int salarioClase;

public://Métodos
    Profesor(): Personas(){};//Constructor base

    //Constructor
    Profesor(string nom, int age, string ciudad, int salarioInd) : Personas(nom, age, ciudad) {
        numClases = 0;
        salarioClase = salarioInd;
    }

    void agregarClases (string claseInd);
    void mostrarClases();
    int obtenerSalario();
    void mostrarInfo();

};

//Método para agregar clases al profesor
void Profesor::agregarClases(string claseInd) {
    clases[numClases] = claseInd;
    *ptr_numClases = *ptr_numClases+1;
}

//Método para mostrar todas las clases del profesor
void Profesor::mostrarClases() {
    cout<<"Las clases registradas son: "<<endl;
    for(int i; i<numClases; i++){
        cout<<clases[i]<<endl;
    }
    cout<<"\n";
}

//Método para calcular el salario total del profesor dependiendo de clases registradas
int Profesor::obtenerSalario() {
    int salarioTotal = *ptr_numClases*salarioClase;
    return salarioTotal;
}

//Método de polimorfismo donde se muestra la información básica y única de la clase profesor
void Profesor::mostrarInfo() {
    cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
    cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Clases que da: "<<*ptr_numClases<<"\n";
    cout<<"Salario mensual: "<<obtenerSalario()<<"\n\n";
}



/*
    Clase hija Empleado
    Esta clase tendra atributos adicionales que puede tener un empleado:
    un salario mensual, uniforme y rol a cumplir.
    Y tendrá métodos que permitan obtener información del empleado
    al igual que métodos para mostrar su información y su salario.
*/
class Empleado:public Personas{
    private://Atributos
        int salarioMensual;
        string uniforme;
        string rol;

    public://Métodos
        Empleado(): Personas(){};//Constructor base

        //Constructor
        Empleado(string nom, int age, string ciudad, int salarioInd, string role, string uniform): Personas(nom, age, ciudad){
            salarioMensual = salarioInd;
            uniforme = uniform;
            rol = role;
        }


    string getUniforme();
    string getRol();
    int getSalario();
    void mostrarInfo();
};

//Getters
    string Empleado::getUniforme(){
        return uniforme;
    }

    string Empleado::getRol() {
        return rol;
    }

    int Empleado::getSalario(){
        return salarioMensual;
    }

//Método de polimorfismo donde se muestra la información básica y única de la clase empleado.
    void Empleado::mostrarInfo() {
        cout<<"Nombre: "<<getNombre()<<"\n"<<"Edad: "<<getEdad()<<"\n";
        cout<<"Lugar natal: "<<getLugar()<<"\n"<<"Rol: "<<getRol()<<"\n";
        cout<<"Uniforme: "<<getUniforme()<<"\n"<<"Salario mensual: "<<getSalario()<<"\n\n";
    }

#endif //PERSONAS_H
