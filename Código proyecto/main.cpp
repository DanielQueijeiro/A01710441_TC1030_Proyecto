#include <iostream>
#include <windows.h>
#include "Campus.h"


using namespace std;


int main() {
    system( "Title Sistema Tec" );
    int op;
    string nomCampus;
    int numEstudiantes;
    int numProfesores;
    int numEmpleados;
    bool menu = true;


    cout<<"Bienvenido al sistema del Tec"<<endl;
    cout<<"Por favor ingrese el campus que se va a administrar"<<endl;
    cin>>nomCampus;
    Campus campus(nomCampus);

    while(menu){
        system("cls");
        cout<<"Bienvenido al sistema administrativo del Tec campus "<<campus.getNombre()<<endl;
        cout<<"Por favor ingrese la opcion que desee realizar"<<endl;
        cout<<"1.- Administrar estudiantes"<<endl;
        cout<<"2.- Administrar profesores"<<endl;
        cout<<"3.- Administrar empleados"<<endl;
        cout<<"4.- Mostrar personas en el campus"<<endl;
        cout<<"5.- Mostrar estudiantes"<<endl;
        cout<<"6.- Mostrar profesores"<<endl;
        cout<<"7.- Mostrar empleados"<<endl;
        cout<<"8.- Salir"<<endl;
        cin>>op;

        if(op==1){
            system("cls");
            cout<<"Por favor ingrese la opcion que desee realizar"<<endl;
            cout<<"1.- Agregar estudiantes"<<endl;
            cout<<"2.- Agregar clases a un estudiante"<<endl;
            cout<<"3.- Mostrar estudiantes"<<endl;
            cout<<"3.- Eliminar estudiantes"<<endl;
        }


        if(op==1){
            system("cls");
            cout<<"Por favor ingrese el numero de estudiantes que agregara"<<endl;
            int auxEst;
            cin>>auxEst;
            cout<<"Ingrese los datos de los alumnos"<<endl;
            for(int i=0;i<auxEst;i++){
                string nom;
                int age;
                string ciudad;
                string career;
                bool apoyo;
                string auxApoyo;
                float becaPorc;
                cout<<"Nombre"<<endl;cin>>nom;
                cout<<"Edad"<<endl;cin>>age;
                cout<<"Ciudad"<<endl;cin>>ciudad;
                cout<<"Carrera"<<endl;cin>>career;
                cout<<"Tiene beca (y/n)"<<endl;cin>>auxApoyo;
                if(auxApoyo=="y"){
                    apoyo = true;
                }else{apoyo = false;}
                if(apoyo==true) {
                    cout << "Porc beca" << endl;
                    cin >> becaPorc;
                }else{becaPorc = 0;}
                Estudiante *estudiante[i];
                estudiante[i] = new Estudiante(nom, age, ciudad, career, apoyo, becaPorc);
                campus.agregarEstudiante(*estudiante[i]);
            }
            cout<<"Estudiantes registrados"<<endl;
            system("pause");
        }

        else if(op==2){
            system("cls");
            cout<<"Por favor ingrese el numero de profesores que agregara"<<endl;
            int auxProf;
            cin>>auxProf;
            cout<<"Ingrese los datos de los profesores"<<endl;
            for(int i=0;i<auxProf;i++){
                string nom;
                int age;
                string ciudad;
                int salarioInd;
                cout<<"Nombre"<<endl;cin>>nom;
                cout<<"Edad"<<endl;cin>>age;
                cout<<"Ciudad"<<endl;cin>>ciudad;
                cout<<"Salario"<<endl;cin>>salarioInd;
                Profesor *profesor[i];
                profesor[i] = new Profesor(nom, age, ciudad, salarioInd);
                campus.agregarProfesor(*profesor[i]);
            }
            cout<<"Profesores registrados"<<endl;
            system("pause");
        }

        else if(op==3){
            system("cls");
            cout<<"Por favor ingrese el numero de empleados que agregara"<<endl;
            int auxEmpl;
            cin >> auxEmpl;
            cout<<"Ingrese los datos de los empleados"<<endl;
            for(int i=0; i < auxEmpl; i++){
                int age, salarioInd;
                string nom, ciudad, rol, uniforme;
                cout<<"Nombre"<<endl;cin>>nom;
                cout<<"Edad"<<endl;cin>>age;
                cout<<"Ciudad"<<endl;cin>>ciudad;
                cout<<"Salario"<<endl;cin>>salarioInd;
                cout<<"Rol"<<endl;cin>>rol;
                cout<<"Uniforme"<<endl;cin>>uniforme;
                Empleado *empleado[i];
                empleado[i] = new Empleado(nom, age, ciudad, salarioInd, rol, uniforme);
                campus.agregarEmpleado(*empleado[i]);
            }
            cout<<"Empleados registrados"<<endl;
            system("pause");
        }

        else if(op==4){
            system("cls");
            cout<<"Personas registradas en el sistema"<<endl;
            campus.mostrarPersonas();
            system("pause");
        }

        else if(op==5){
            system("cls");
            cout<<"Estudiantes registrados en el sistema:"<<endl;
            campus.mostrarEstudiantes();
            system("pause");
        }

        else if(op==6){
            system("cls");
            cout<<"Profesores registrados en el sistema:"<<endl;
            campus.mostrarProfesores();
            system("pause");
        }

        else if(op==7){
            system("cls");
            cout<<"Empleados registrados en el sistema:"<<endl;
            campus.mostrarEmpleados();
            cout<<endl;
            system("pause");
        }

        else if(op==8) {
            menu = false;
        }
    }


/*    cout<<"Estudiantes: "<<endl;cin>>numEstudiantes;
    cout<<"Profesores: "<<endl;cin>>numProfesores;
    cout<<"Empleados: "<<endl;cin>>numEmpleados;

    Campus campus("Queretaro");

    for(int i = 0;i<numEstudiantes;i++) {
        Estudiante *estudiante[i];
        estudiante[i] = new Estudiante("daniel", 18, "ITC", false);
        campus.agregarEstudiante(*estudiante[i]);
    }
    campus.mostrarEstudiantes();*/

/*    Estudiante daniel("Daniel", 18, "Queretaro", "ITC", true, 0.7);
    daniel.agregarClases("espanol");
    Estudiante ricardo("Ricardo", 18, "IRS", false);
    ricardo.setLugar("CDMX");
    Estudiante galo("Galo", 19, "IRS", false);

    Campus qro("Queretaro");



    qro.agregarEstudiante(ricardo);
    qro.agregarEstudiante(galo);
    qro.agregarEstudiante(daniel);
    qro.mostrarEstudiantes();*/

/*    Profesor benji("Benji", 35, 4000);
    benji.setSalario(1);
    benji.setLugar("Sonora");
    benji.agregarClases("OOP");
    benji.agregarClases("IOT");

    Empleado ezzat("Ezzat", 18, 150, "cajero", "playera azul");
    ezzat.setLugar("veracruz");*/


/*    Campus *qro;
    qro = new Campus("Queretaro");
    qro -> getNombre();
    cout<<"\n";

    qro ->agregarEstudiante(daniel);
    qro ->agregarEstudiante(ricardo);
    qro ->agregarEstudiante((galo));
    qro ->mostrarEstudiantes();
    qro->getTotalEstudiantes();*/

/*    qro ->agregarProfesor(benji);
    qro ->mostrarProfesores();
    qro -> getTotalProfesores();

    qro ->agregarEmpleado(ezzat);
    qro ->mostrarEmpleados();
    qro ->getTotalEmpleados();*/




    return 0;
}