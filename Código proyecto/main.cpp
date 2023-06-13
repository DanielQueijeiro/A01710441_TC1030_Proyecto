/*
    Created by Daniel Queijeiro A01710441 on 26/05/2023.
    En el main podremos crear nuestro campus para poder empezar a añadir personas
    y administrarlas. Ya sea añadiendo clases o calculando salarios.
    También podremos ver la información de cada persona registrada en el sistema.
*/
#include <iostream>
#include <zconf.h>
#include "Campus.h"//Incluimos el archivo Campus.h para trabajar
//con nuestras clases Campus, personas, estudiante, profesor y empleado.


using namespace std;


int main() {
    //Definimos nuestros arreglos de tipo estudiante, profesor, y empleado
    //Usamos apuntadores para poder emplear polimorfismo

    //Definimos nuestras variables
    int op;
    string nomCampus;
    bool menu = true;

    //Damos la bienvenida al usuario y solicitamos nombre para crear al campus
    cout<<"Bienvenido al sistema del Tec"<<endl;
    cout<<"Por favor ingrese el campus que se va a administrar"<<endl;
    cin>>nomCampus;
    Campus campus(nomCampus);

    //Empezamos menu
    while(menu){
        cout<<"\n\n\n\n";
        cout<<"Bienvenido al sistema administrativo del Tec campus "<<campus.getNombre()<<endl;
        cout<<"Por favor ingrese la opcion que desee realizar"<<endl;
        cout<<"1.- Administrar estudiantes"<<endl;
        cout<<"2.- Administrar profesores"<<endl;
        cout<<"3.- Administrar empleados"<<endl;
        cout<<"4.- Mostrar todas las personas registradas en el campus"<<endl;
        cout<<"5.- Crear personas predeterminadas"<<endl;
        cout<<"6.- Salir"<<endl;
        cin>>op;//El usuario elije una opción

        //Administrar estudiantes
        if(op==1) {
            cout<<"\n\n\n\n";
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar estudiantes" << endl;
            cout << "2.- Mostrar estudiantes registrados" << endl;
            cout << "3.- Mostrar informacion de un estudiante" << endl;
            cout << "4.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;

            //Agregar estudiantes
            if (op == 1) {
                op = 0;
                cout<<"\n\n\n\n";
                cout << "Por favor ingrese el numero de estudiantes que agregara" << endl;
                //Variable auxiliar para usar en el for
                int auxEst;
                cin >> auxEst;
                cout << "Ingrese los datos de los alumnos" << endl;
                //Ciclo para poder crear los alumnos que el usuario quiere
                for (int i = 0; i < auxEst; i++) {
                    string nom,ciudad, rol="estudiante";
                    int age;
                    //Solicitamos los datos requeridos para crear un alumno
                    cout << "Nombre" << endl;cin >> nom;
                    cout << "Edad" << endl;cin >> age;
                    cout << "Ciudad" << endl;cin >> ciudad;
                        //Los agregamos al campus
                        campus.agregarPersonas(rol,nom, age, ciudad);
                        cout << endl;
                        cout << "Estudiantes registrados" << endl;
                }
                
            }

            //Mostrar estudiantes
            else if(op==2){
                op = 0;
                cout<<"\n\n\n\n";
                campus.mostrarTotalEstudiantes();
                
            }

            //Mostrar informacion de un estudiante
            else if(op==3){
                op = 0;
                int auxMatricula;
                string auxNombre;
                cout<<"\n\n\n\n";
                cout << "Por favor ingrese la matricula del estudiante al que desea seleccionar:" << endl;
                cout << "Recordar que las matriculas de estudiantes empiezan en 0 y llegan hasta 99" << endl;
                cout<<"A";
                //La variable nos servira para buscar al estudiante que se desea
                cin>>auxMatricula;
                cout<<"\n\n\n\n";
                if(auxMatricula<0 || auxMatricula>99){
                    cout<<"Matricula invalida"<<endl;
                }
                //Usamos método de clase Estudiante para obtener el nombre
                else {
                    cout << "Matricula del estudiante: A" << auxMatricula << endl;
                    campus.mostrarInfoPersona(auxMatricula);
                }
            }

            //Regresar al menu principal
            else if(op==4){op=0;}
        }

        //Administrar profesores
        else if(op==2) {
            op = 0;
            cout<<"\n\n\n\n";
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar profesores" << endl;
            cout << "2.- Mostrar profesores registrados" << endl;
            cout << "3.- Mostrar informacion de un profesor" << endl;
            cout << "4.- Regresar al menu principal"<< endl;
            cin>>op;

                //Agregar profesores
                if(op==1){
                    op = 0;
                    cout<<"\n\n\n\n";
                    cout<<"Por favor ingrese el numero de profesores que agregara"<<endl;
                    //Variable auxiliar que nos ayuda en el for
                    int auxProf;
                    cin>>auxProf;
                    cout<<"Ingrese los datos de los profesores"<<endl;
                    //Ciclo para agregar todos los profesores que el usuario quiere
                    for(int i=0;i<auxProf;i++){
                        string nom, ciudad, rol="profesor";
                        int age;
                        //Solicitamos información para crear un profesor
                        cout<<"Nombre"<<endl;cin>>nom;
                        cout<<"Edad"<<endl;cin>>age;
                        cout<<"Ciudad"<<endl;cin>>ciudad;
                        //Los agregamos al campus
                        campus.agregarPersonas(rol,nom, age, ciudad);
                        }
                    cout<<"Profesores registrados"<<endl;
                }

                //Mostrar todos los profesores
                else if(op==2){
                    op = 0;
                    cout<<"\n\n\n\n";
                    campus.mostrarTotalProfesores();
                }

                //Mostrar informacion de un profesor
                else if(op==3) {
                    op = 0;
                    int auxMatricula;
                    string auxNombre;
                    cout << "\n\n\n\n";
                    cout << "Por favor ingrese la matricula del profesor al que desea seleccionar:" << endl;
                    cout << "Recordar que las matriculas de profesores empiezan en 100 y llegan hasta 199" << endl;
                    cout << "P";
                    //La variable nos servira para buscar al profesor que se desea
                    cin >> auxMatricula;
                    cout << "\n\n\n\n";
                    if (auxMatricula < 100 || auxMatricula > 199) {
                        cout << "Matricula invalida" << endl;
                    }
                    else{
                        cout << "Matricula del profesor: P" << auxMatricula << endl;
                    //Usamos método de clase Profesor para obtener informacion
                        campus.mostrarInfoPersona(auxMatricula);
                    }
                }

                //Regresar a menu principal
                else if(op==4){op=0;}
        }

        //Administrar empleados
        else if(op==3) {
            cout << "\n\n\n\n";
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar empleados" << endl;
            cout << "2.- Mostrar empleados" << endl;
            cout << "3.- Mostrar informacion de un empleado" << endl;
            cout << "4.- Regresar al menu principal" << endl;
            op = 0;
            cin >> op;

            //Agregar empleado
            if (op == 1) {
                op = 0;
                cout << "\n\n\n\n";
                cout << "Por favor ingrese el numero de empleados que agregara" << endl;
                int auxEmpl; //Variable para ciclo for
                cin >> auxEmpl;
                cout << "Ingrese los datos de los empleados" << endl;
                for (int i = 0; i < auxEmpl; i++) {
                    //Creamos empleado
                    string nom, ciudad, rol = "empleado";
                    int age;
                    cout << "Nombre" << endl;
                    cin >> nom;
                    cout << "Edad" << endl;
                    cin >> age;
                    cout << "Ciudad" << endl;
                    cin >> ciudad;
                    //Lo agregamos al campus
                    campus.agregarPersonas(rol, nom, age, ciudad);
                }
                cout << "Empleados registrados" << endl;

            }

                //Mostrar empleados
            else if (op == 2) {
                op = 0;
                cout << "\n\n\n\n";
                campus.mostrarTotalEmpleados();

            }

                //Mostrar informacion de un profesor
            else if (op == 3) {
                op = 0;
                int auxID;
                string auxNombre;
                cout << "\n\n\n\n";
                cout << "Por favor ingrese el ID del empleado al que desea seleccionar:" << endl;
                cout << "Recordar que los ID de empleados empiezan en 200 y llegan hasta 299" << endl;
                cout << "ID";
                //La variable nos servira para buscar al profesor que se desea
                cin >> auxID;
                cout << "\n\n\n\n";
                if(auxID<200 || auxID>299) {
                    cout << "ID invalido" << endl;
                }
                //Usamos método de clase Profesor para obtener informacion
                else {
                    cout << "ID del empleado: ID" << auxID << endl;
                    campus.mostrarInfoPersona(auxID);
                }
            }
                //Regresar a menu
            else if (op == 4) {}
        }

        //Mostrar todas las personas registradas en el campus
        else if(op==4){
            op=0;
            cout<<"\n\n\n\n";
            campus.mostrarTotalPersonas();
            }

        //Crear un par de personas en el campus para ver que si funciona bien el codigo
        else if(op==5){
            op=0;
            cout<<"\n\n\n\n";
            cout<<"Se crearan 2 estudiantes, 2 profesores y 2 empleados"<<endl;
            campus.crearPersonasBase();
        }

        //Salir
        else if(op==6) {
            menu = false;
        }
    }

    return 0;
}