/*
    Created by Daniel Queijeiro A01710441 on 24/05/2023.
    Esta clase nos sirve para definir al objeto Campus, el cual almacenara mediante composición
    a estudiantes, profesores y empleados.
    Sus atributos son: nombre del campus, matriculas únicas para estudiantes y profesores, e ID's
    para los empleados.
    Al igual que la parte mas importante, un arreglo único para Personas.
*/

#ifndef CAMPUS_H
#define CAMPUS_H

#include "Personas.h"
//Incluimos el archivo Personas.h para poder trabajar con el

class Campus{
    private://Atributos
        string nombre;
        int matriculaEst,matriculaProf,emplID;
        //Usamos apuntador para poder usar polimorfismo mas adelante
        Personas *arrPersonas[299];//0-99 estudiantes, 100-199 profesores, 200-299 empleados
        //299 porque los arreglos empiezan en 0, en total son 300

    public://Métodos
        Campus(){//Constructor base
            nombre = ""; matriculaEst = 0; matriculaProf = 100; emplID=200;//Habra un limite de 100 estudiantes, profesores y empleados registrados
        }
        Campus(string nom);//Constructor

        string getNombre();

        void agregarPersonas(string,string,int,string);
        void mostrarTotalPersonas();
        void mostrarInfoPersona(int);
        void mostrarTotalEstudiantes();
        void mostrarTotalProfesores();
        void mostrarTotalEmpleados();

        void crearPersonasBase();

};

Campus::Campus(string nom) {
    nombre = nom;matriculaEst = 0; matriculaProf = 100; emplID=200;
}

//Getter
string Campus::getNombre() {
    return nombre;
}

/*Con este metodo podemos agregar nuestras clases al arreglo de personas
    @param string, string, int, y string
    @return void
*/
void Campus::agregarPersonas(string persona, string nom, int age, string ciudad) {
    //dependiendo del tipo de persona que se desee agregar se cumple el condicional
    if(persona == "estudiante") {
        string career,auxApoyo;
        bool apoyo;
        int clases;
        float becaPorc;
        //Pedimos el resto de datos para crear a un Estudiante
        cout << "Carrera" << endl;getline(cin,career);
        cout<<"Numero de clases"<<endl;cin>>clases;
        cout << "Tiene beca (y/n)" << endl;cin >> auxApoyo;
        if (auxApoyo == "y") {
            apoyo = true;
        } else { apoyo = false; becaPorc=0; }
        if (apoyo) {
            cout << "Porcentaje de beca (En decimales)" << endl;
            cin >> becaPorc;
        }
        //Y lo creamos en el heap
        arrPersonas[matriculaEst] = new Estudiante(nom, age, ciudad, career, clases, apoyo, becaPorc);
        matriculaEst++;
    }
    else if(persona=="profesor"){
        int clases,salarioInd;
        //Pedimos el resto de datos para crear a un Profesor
        cout<<"Numero de clases"<<endl;cin>>clases;
        cout<<"Salario"<<endl;cin>>salarioInd;
        //Y lo creamos en el heap
        arrPersonas[matriculaProf]= new Profesor(nom,age,ciudad,clases,salarioInd);
        matriculaProf++;
    }
    else if(persona=="empleado"){
        int salarioInd;
        string puesto, uniforme;
        //Pedimos el resto de datos para crear a un Empleado
        cout<<"Salario"<<endl;cin>>salarioInd;
        cin.ignore();
        cout<<"Puesto"<<endl;getline(cin,puesto);
        cout<<"Uniforme"<<endl;getline(cin,uniforme);
        //Y lo creamos en el heap
        arrPersonas[emplID]= new Empleado(nom,age,ciudad,salarioInd,puesto,uniforme);
        emplID++;
    }
}

//Muestra el número total de personas en el campus, divididas por subclase
//@param
//@return
void Campus::mostrarTotalPersonas() {
//Estudiantes
    if (matriculaEst != 0) {
        cout << "Total de estudiantes registrados: " << matriculaEst << endl;
        for (int i = 0; i < matriculaEst; i++) {
            //Usamos método de persona para obtener nombre
            cout << arrPersonas[i]->getNombre() << "  Matricula: "<< i << endl;
        }
        cout<<endl;
    } else {
        cout << "No hay estudiantes registrados " << endl <<endl;
    }

    //Profesores
    if (matriculaProf != 100) {
        cout << "Total de profesores registrados: " << matriculaProf-100 << endl;
        for (int i = 100; i < matriculaProf; i++) {
            //Usamos método de persona para obtener nombre
            cout << arrPersonas[i]->getNombre() << "  Matricula: "<< i << endl;
        }
        cout<<endl;
    } else {
        cout << "No hay profesores registrados " << endl <<endl;
    }

    //Empleados
    if (emplID != 200) {
        cout << "Total de empleados registrados: " << emplID-200 << endl;
        for (int i = 200; i < emplID; i++) {
            //Usamos método de persona para obtener nombre
            cout << arrPersonas[i]->getNombre() << " ID: "<< i << endl;
        }
        cout<<endl;
    } else {
        cout << "No hay empleados registrados " << endl <<endl;
    }
}

//Muestra la informacion de una persona en especifico
//@param int
//@return
void Campus::mostrarInfoPersona(int auxMatricula) {
    arrPersonas[auxMatricula]->mostrarInfo();
}


//Muestra todos los estudiantes registrados junto con sus datos
//@param
//@return
void Campus::mostrarTotalEstudiantes(){
    if (matriculaEst == 0) {
        cout << "No hay estudiantes registrados " << endl;
    } else {
        for (int i = 0; i < matriculaEst; i++) {
            cout << "Matricula del estudiante: A" << i << endl;
            //Usamos método de estudiante para mostrar su información
            arrPersonas[i]->mostrarInfo();
            cout << "\n";
        }
    }
}

//Muestra todos los profesores registrados junto con sus datos
//@param
//@return
void Campus::mostrarTotalProfesores() {
    if (matriculaProf == 100) {
        cout << "No hay profesores registrados " << endl;
    } else {
        for (int i = 100; i < matriculaProf; i++) {
            cout << "Matricula del profesor: P" << i << endl;
            //Usamos método de profesor para mostrar su información
            arrPersonas[i]->mostrarInfo();
            cout << "\n";
        }
    }
}

//Muestra todos los empleados registrados junto con sus datos
//@param
//@return
void Campus::mostrarTotalEmpleados() {
    if (matriculaProf == 200) {
        cout << "No hay empleados registrados " << endl;
    }
    else {
        for (int i = 200; i < emplID; i++) {
            cout << "ID del empleado: ID" << i << endl;
            //Usamos método de empleado para mostrar su información
            arrPersonas[i]->mostrarInfo();
            cout << "\n";
        }
    }
}

//Crea un conjunto de personas predeterminadas para facilitar la prueba del programa
//@param
//@return
void Campus::crearPersonasBase() {
    //Estudiantes
    arrPersonas[matriculaEst] = new Estudiante("Ricardo", 19, "Qro", "IRS",5, true, 0.5);
    matriculaEst++;
    arrPersonas[matriculaEst] = new Estudiante("Daniel", 19, "Qro", "ITC",0, true, 0.7);
    matriculaEst++;
    cout<<"Estudiantes registrados"<<endl;

    //Profesores
    arrPersonas[matriculaProf] = new Profesor("Benji", 33, "Qro",5, 1000);
    matriculaProf++;
    arrPersonas[matriculaProf] = new Profesor("Pedro", 45, "Qro",0, 1000);
    matriculaProf++;
    cout<<"Profesores registrados"<<endl;

    //Empleados
    arrPersonas[emplID]= new Empleado("Juan",20,"CDMX",500,"Cajero", "Playera roja");
    emplID++;
    arrPersonas[emplID]= new Empleado("Jose",23,"Veracruz",800,"Seguridad", "Camisa blanca");
    emplID++;
    cout<<"Empleados registrados"<<endl;
}

#endif //CAMPUS_H
