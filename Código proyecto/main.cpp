#include <iostream>
#include "Campus.h"

using namespace std;

int main() {

    Estudiante daniel("Daniel", 18, "Queretaro", "ITC", true, 0.7);
    daniel.agregarClases("espanol");
    Estudiante ricardo("Ricardo", 18, "IRS", false);
    ricardo.setLugar("CDMX");
    Estudiante galo("Galo", 19, "IRS", false);

/*    Campus qro("Queretaro");
    qro.agregarEstudiante(ricardo);
    qro.agregarEstudiante(galo);
    qro.agregarEstudiante(daniel);
    qro.mostrarEstudiantes();*/

    Profesor benji("Benji", 35, 4000);
    benji.setSalario(1);
    benji.setLugar("Sonora");
    benji.agregarClases("OOP");
    benji.agregarClases("IOT");

    Empleado ezzat("Ezzat", 18, 150, "cajero", "playera azul");
    ezzat.setLugar("veracruz");


    Campus *qro;
    qro = new Campus("Queretaro");
    qro -> getNombre();
    cout<<"\n";

    qro ->agregarEstudiante(daniel);
    qro ->mostrarEstudiantes();
    qro->getTotalEstudiantes();

    qro ->agregarProfesor(benji);
    qro ->mostrarProfesores();
    qro -> getTotalProfesores();

    qro ->agregarEmpleado(ezzat);
    qro ->mostrarEmpleados();
    qro ->getTotalEmpleados();


    return 0;
}