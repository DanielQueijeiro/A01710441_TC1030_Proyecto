#include <iostream>
#include <windows.h>
#include "Campus.h"


using namespace std;


int main() {
    system( "Title Sistema Tec" );

    Estudiante *estudiantes[100];
    Profesor *profesores[100];
    Empleado *empleados[100];

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
        cout<<"4.- Mostrar todas las personas registradas en el campus"<<endl;
        cout<<"5.- Salir"<<endl;
        cin>>op;

        //Administrar estudiantes
        if(op==1) {
            system("cls");
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar estudiantes" << endl;
            cout << "2.- Agregar clases a un estudiante" << endl;
            cout << "3.- Mostrar estudiantes" << endl;
            cout << "4.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;

            //Agregar estudiantes
            if (op == 1) {
                op = 0;
                system("cls");
                cout << "Por favor ingrese el numero de estudiantes que agregara" << endl;
                int auxEst;
                cin >> auxEst;
                cout << "Ingrese los datos de los alumnos" << endl;
                for (int i = 0; i < auxEst; i++) {
                    string nom, ciudad, career, auxApoyo;
                    int age;
                    bool apoyo;
                    float becaPorc;
                    cout << "Nombre" << endl;cin >> nom;
                    cout << "Edad" << endl;cin >> age;
                    cout << "Ciudad" << endl;cin >> ciudad;
                    cout << "Carrera" << endl;cin >> career;
                    cout << "Tiene beca (y/n)" << endl;cin >> auxApoyo;
                    if (auxApoyo == "y") {
                        apoyo = true;
                    } else { apoyo = false; }
                    if (apoyo == true) {
                        cout << "Porcentaje de beca (En decimales)" << endl;
                        cin >> becaPorc;
                    } else { becaPorc = 0; }

                    estudiantes[i] = new Estudiante(nom, age, ciudad, career, apoyo, becaPorc);
                    campus.agregarEstudiante(*estudiantes[i]);
                    cout<<endl;
                }
                cout << "Estudiantes registrados" << endl;
                system("pause");
            }

            //Agregar clases a un estudiante
            else if(op==2){
                op = 0;
                int auxMatricula, auxClases;
                string auxNombre;
                system("cls");
                cout << "Por favor ingrese la matricula del estudiante al que agregara clases:" << endl;
                cout << "Recordar que las matriculas empiezan en 0" << endl;
                cout<<"A";
                cin>>auxMatricula;
                system("cls");
                cout<<"Estudiante: "<<estudiantes[auxMatricula]->getNombre()<<endl;
                cout<<"Por favor ingrese la cantidad de clases que va agregar:"<<endl;
                cin>>auxClases;
                cout<<"Ingrese las clases que desea agregar:"<<endl;
                for(int i=0;i<auxClases;i++){
                    cin>>auxNombre;
                    estudiantes[auxMatricula]->agregarClases(auxNombre);
                }
                estudiantes[auxMatricula]->mostrarClases();
                system("pause");
            }

            //Mostrar estudiantes
            else if(op==3){
                op = 0;
                system("cls");
                campus.mostrarEstudiantes();
                system("pause");
            }

            //Regresar al menu principal
            else if(op==4){op=0;}
        }

        //Administrar profesores
        else if(op==2) {
            op = 0;
            system("cls");
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar profesores" << endl;
            cout << "2.- Agregar clases a un profesor" << endl;
            cout << "3.- Mostrar profesores" << endl;
            cout << "4.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;

                if(op==1){
                    op = 0;
                    system("cls");
                    cout<<"Por favor ingrese el numero de profesores que agregara"<<endl;
                    int auxProf;
                    cin>>auxProf;
                    cout<<"Ingrese los datos de los profesores"<<endl;
                    for(int i=0;i<auxProf;i++){
                        string nom, ciudad;
                        int age, salarioInd;
                        cout<<"Nombre"<<endl;cin>>nom;
                        cout<<"Edad"<<endl;cin>>age;
                        cout<<"Ciudad"<<endl;cin>>ciudad;
                        cout<<"Salario"<<endl;cin>>salarioInd;
                        profesores[i] = new Profesor(nom, age, ciudad, salarioInd);
                        campus.agregarProfesor(*profesores[i]);
                        }
                    cout<<"Profesores registrados"<<endl;
                    system("pause");
                }

                else if(op==2){
                    op = 0;
                    int auxMatricula, auxClases;
                    string auxNombre;
                    system("cls");
                    cout << "Por favor ingrese la matricula del profesor al que agregara clases:" << endl;
                    cout << "Recordar que las matriculas empiezan en 0" << endl;
                    cout<<"P";
                    cin>>auxMatricula;
                    system("cls");
                    profesores[auxMatricula]->getNombre();
                    cout<<"Por favor ingrese la cantidad de clases que va agregar:"<<endl;
                    cin>>auxClases;
                    cout<<"Ingrese las clases que desea agregar:"<<endl;
                    for(int i=0;i<auxClases;i++){
                        cin>>auxNombre;
                        profesores[auxMatricula]->agregarClases(auxNombre);
                    }
                    profesores[auxMatricula]->mostrarClases();
                    system("pause");
                }

                else if(op==3){
                    op = 0;
                    system("cls");
                    campus.mostrarProfesores();
                    system("pause");
                }

                else if(op==4){op=0;}
        }

        //Administrar empleados
        else if(op==3){
            system("cls");
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar empleados" << endl;
            cout << "2.- Mostrar empleados" << endl;
            cout << "3.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;
        }
            if(op==1){
                op = 0;
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

            else if(op==2){
                op = 0;
                system("cls");
                campus.mostrarEmpleados();
                system("pause");
            }

            else if(op==3){}

        //Mostrar todas las personas registradas en el campus
        else if(op==4){
            system("cls");
            campus.mostrarPersonas();
            system("pause");
            }

        //Salir
        else if(op==5) {
            menu = false;
        }
    }

    return 0;
}