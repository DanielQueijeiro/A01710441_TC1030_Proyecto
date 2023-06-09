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
    Estudiante *estudiantes[100];
    Profesor *profesores[100];
    Empleado *empleados[100];

    //Definimos nuestras variables
    int op;
    int estMatricula = 0;
    int profMatricula = 0;
    int emplID = 0;
    string nomCampus;
    bool menu = true;

    //Damos la bienvenida al usuario y solicitamos nombre para crear al campus
    cout<<"Bienvenido al sistema del Tec"<<endl;
    cout<<"Por favor ingrese el campus que se va a administrar"<<endl;
    cin>>nomCampus;
    Campus campus(nomCampus);

    //Empezamos menu
    while(menu){
        cout<<"\n\n";
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
            cout<<"\n\n";
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar estudiantes" << endl;
            cout << "2.- Agregar o mostrar clases de un estudiante" << endl;
            cout << "3.- Mostrar estudiantes" << endl;
            cout << "4.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;

            //Agregar estudiantes
            if (op == 1) {
                op = 0;
                cout<<"\n\n";
                cout << "Por favor ingrese el numero de estudiantes que agregara" << endl;
                //Variable auxiliar para usar en el for
                int auxEst;
                cin >> auxEst;
                cout << "Ingrese los datos de los alumnos" << endl;
                //Ciclo para poder crear los alumnos que el usuario quiere
                for (int i = 0; i < auxEst; i++) {
                    string nom, ciudad, career, auxApoyo;
                    int age;
                    bool apoyo;
                    float becaPorc;
                    //Solicitamos los datos requeridos para crear un alumno
                    cout << "Nombre" << endl;cin >> nom;
                    cout << "Edad" << endl;cin >> age;
                    cout << "Ciudad" << endl;cin >> ciudad;
                    cout << "Carrera" << endl;cin >> career;
                    cout << "Tiene beca (y/n)" << endl;cin >> auxApoyo;
                    if (auxApoyo == "y") {
                        apoyo = true;
                    } else { apoyo = false; }
                    if (apoyo) {
                        cout << "Porcentaje de beca (En decimales)" << endl;
                        cin >> becaPorc;
                    }
                        //Creamos los estudiantes
                        estudiantes[estMatricula] = new Estudiante(nom, age, ciudad, career, apoyo, becaPorc);
                        //Los agregamos al campus
                        campus.agregarEstudiante(*estudiantes[estMatricula]);
                        cout << endl;
                        cout << "Estudiantes registrados" << endl;
                    estMatricula++;
                }
                sleep(1);
            }

            //Mostrar o agregar clases a un estudiante
            else if(op==2){
                op = 0;
                int auxMatricula, auxClases, auxOp;
                string auxNombre;
                cout<<"\n\n";
                cout << "Por favor ingrese la matricula del estudiante al que desea seleccionar:" << endl;
                cout << "Recordar que las matriculas empiezan en 0" << endl;
                cout<<"A";
                //La variable nos servira para buscar al estudiante que se desea
                cin>>auxMatricula;
                cout<<"\n\n";
                //Usamos método de clase Estudiante para obtener el nombre
                cout<<"Estudiante: "<<estudiantes[auxMatricula]->getNombre()<<endl;
                cout<<"Desea agregar o mostrar clases? (Agregar = 0, Mostrar = 1)"<<endl;
                cin>>auxOp;
                if(auxOp==0) {
                    cout<<"\n\n";
                    cout<<"Estudiante: "<<estudiantes[auxMatricula]->getNombre()<<endl;
                    cout << "Por favor ingrese la cantidad de clases que va agregar:" << endl;
                    cin >> auxClases;
                    cout << "Ingrese las clases que desea agregar:" << endl;
                    //Ciclo para agregar todas las clases
                    for (int i = 0; i < auxClases; i++) {
                        cin >> auxNombre;
                        //Usamos método de Estudiante para agregar clases
                        estudiantes[auxMatricula]->agregarClases(auxNombre);
                    }
                    cout<<"Clases registradas"<<endl;
                }
                else if(auxOp == 1){
                    cout<<"\n\n";
                    cout<<"Clases registradas del estudiante: "<<estudiantes[auxMatricula]->getNombre()<<endl;
                    //Usamos método de Estudiante para mostrar el total de clases que el alumno tiene
                    estudiantes[auxMatricula]->mostrarClases();
                }
                else{cout<<"Opcion no valida"<<endl;}
                sleep(1);
            }

            //Mostrar estudiantes
            else if(op==3){
                op = 0;
                cout<<"\n\n";
                campus.mostrarEstudiantes();
                sleep(1);
            }

            //Regresar al menu principal
            else if(op==4){op=0;}
        }

        //Administrar profesores
        else if(op==2) {
            op = 0;
            cout<<"\n\n";
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar profesores" << endl;
            cout << "2.- Agregar o mostrar clases de un profesor" << endl;
            cout << "3.- Mostrar profesores" << endl;
            cout << "4.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;

                //Agregar profesores
                if(op==1){
                    op = 0;
                    cout<<"\n\n";
                    cout<<"Por favor ingrese el numero de profesores que agregara"<<endl;
                    //Variable auxiliar que nos ayuda en el for
                    int auxProf;
                    cin>>auxProf;
                    cout<<"Ingrese los datos de los profesores"<<endl;
                    //Ciclo para agregar todos los profesores que el usuario quiere
                    for(int i=0;i<auxProf;i++){
                        string nom, ciudad;
                        int age, salarioInd;
                        //Solicitamos información para crear un profesor
                        cout<<"Nombre"<<endl;cin>>nom;
                        cout<<"Edad"<<endl;cin>>age;
                        cout<<"Ciudad"<<endl;cin>>ciudad;
                        cout<<"Salario"<<endl;cin>>salarioInd;

                        //Creamos los profesores
                        profesores[profMatricula] = new Profesor(nom, age, ciudad, salarioInd);
                        //Los agregamos al campus
                        campus.agregarProfesor(*profesores[profMatricula]);
                        }
                    profMatricula++;
                    cout<<"Profesores registrados"<<endl;
                    sleep(1);
                }

                //Agregar o mostrar clases del profesor
                else if(op==2){
                    op = 0;
                    int auxMatricula, auxClases, auxOp;
                    string auxNombre;
                    cout<<"\n\n";
                    cout << "Por favor ingrese la matricula del profesor al que agregara clases:" << endl;
                    cout << "Recordar que las matriculas empiezan en 0" << endl;
                    cout<<"P";
                    cin>>auxMatricula;//Variable que nos ayudara a buscar al profesor
                    cout<<"\n\n";
                    //Obtenemos el nombre del profesor con un método de su clase
                    cout<<"Profesor: "<<profesores[auxMatricula]->getNombre()<<endl;
                    cout<<"Desea agregar o mostrar clases? (Agregar = 0, Mostrar = 1)"<<endl;
                    cin>>auxOp;
                    if(auxOp==0) {
                        cout<<"\n\n";
                        cout<<"Profesor: "<<profesores[auxMatricula]->getNombre()<<endl;
                        cout << "Por favor ingrese la cantidad de clases que va agregar:" << endl;
                        cin >> auxClases;
                        cout << "Ingrese las clases que desea agregar:" << endl;
                        //Ciclo para agregar todas las clases
                        for (int i = 0; i < auxClases; i++) {
                            cin >> auxNombre;
                            //Usamos método de Profesor para agregar clases
                            profesores[auxMatricula]->agregarClases(auxNombre);
                        }
                        cout<<"Clases registradas"<<endl;
                    }
                    else if(auxOp == 1){
                        cout<<"\n\n";
                        cout<<"Clases registradas del profesor: "<<profesores[auxMatricula]->getNombre()<<endl;
                        //Usamos método de Profesor para mostrar el total de clases que el profesor tiene
                        profesores[auxMatricula]->mostrarClases();
                    }
                    else{cout<<"Opcion no valida"<<endl;}
                    sleep(1);
                }

                //Mostrar profesores
                else if(op==3){
                    op = 0;
                    cout<<"\n\n";
                    campus.mostrarProfesores();
                    sleep(1);
                }

                //Regresar a menu principal
                else if(op==4){op=0;}
        }

        //Administrar empleados
        else if(op==3){
            cout<<"\n\n";
            cout << "Por favor ingrese la opcion que desee realizar" << endl;
            cout << "1.- Agregar empleados" << endl;
            cout << "2.- Mostrar empleados" << endl;
            cout << "3.- Regresar al menu principal"<< endl;
            op = 0;
            cin>>op;
        }

            //Agregar empleado
            if(op==1){
                op = 0;
                cout<<"\n\n";
                cout<<"Por favor ingrese el numero de empleados que agregara"<<endl;
                int auxEmpl; //Variable para ciclo for
                cin >> auxEmpl;
                cout<<"Ingrese los datos de los empleados"<<endl;
                for(int i=0; i < auxEmpl; i++){
                    int age, salarioInd;
                    string nom, ciudad, rol, uniforme;
                    //Solicitamos los datos necesarios para crear un empleado
                    cout<<"Nombre"<<endl;cin>>nom;
                    cout<<"Edad"<<endl;cin>>age;
                    cout<<"Ciudad"<<endl;cin>>ciudad;
                    cout<<"Salario"<<endl;cin>>salarioInd;
                    cout<<"Rol"<<endl;cin>>rol;
                    cout<<"Uniforme"<<endl;cin>>uniforme;
                    //Creamos empleado
                    empleados[emplID] = new Empleado(nom, age, ciudad, salarioInd, rol, uniforme);
                    //Lo agregamos al campus
                    campus.agregarEmpleado(*empleados[emplID]);
                }
                emplID++;
                cout<<"Empleados registrados"<<endl;
                sleep(1);
            }

            //Mostrar empleados
            else if(op==2){
                op = 0;
                cout<<"\n\n";
                campus.mostrarEmpleados();
                sleep(1);
            }
            //Regresar a menu
            else if(op==3){}


        //Mostrar todas las personas registradas en el campus
        else if(op==4){
            cout<<"\n\n";
            campus.mostrarPersonas();
            sleep(1);
            }

        //Crear un par de personas en el campus para ver que si funciona bien el codigo
        else if(op==5){
            op==0;
            cout<<"\n\n";
            cout<<"Se crearan 2 estudiantes, 2 profesores y 2 empleados"<<endl;
            //Estudiantes
            estudiantes[estMatricula] = new Estudiante("Ricardo", 19, "Qro", "IRS", true, 0.5);
            campus.agregarEstudiante(*estudiantes[estMatricula]);
            estMatricula++;
            estudiantes[estMatricula] = new Estudiante("Daniel", 19, "Qro", "ITC", true, 0.7);
            campus.agregarEstudiante(*estudiantes[estMatricula]);
            estMatricula++;
            cout << "Estudiantes registrados" << endl;

            //Profesores
            profesores[profMatricula] = new Profesor("Benji", 33, "Qro", 1000);
            campus.agregarProfesor(*profesores[profMatricula]);
            profMatricula++;
            profesores[profMatricula] = new Profesor("Pedro", 45, "Qro", 1000);
            campus.agregarProfesor(*profesores[profMatricula]);
            profMatricula++;
            cout<<"Profesores registrados"<<endl;

            //Empleados
            empleados[emplID]= new Empleado("Juan",20,"CDMX",500,"Cajero","Playera roja");
            campus.agregarEmpleado(*empleados[emplID]);
            emplID++;
            empleados[emplID]= new Empleado("Jose",23,"Veracruz",800,"Seguridad","Playera blanca");
            campus.agregarEmpleado(*empleados[emplID]);
            emplID++;
            cout<<"Empleados registrados"<<endl;

            sleep(1);
        }

        //Salir
        else if(op==6) {
            menu = false;
        }
    }

    return 0;
}