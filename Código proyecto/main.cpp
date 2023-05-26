#include <iostream>
#include "Campus.h"

using namespace std;

int main() {
    Estudiante daniel("Daniel", 18, "Queretaro", "ITC", true, 0.7);
    daniel.agregarClases("espanol");
    Estudiante ricardo("Ricardo", 18, "IRS", false);
    ricardo.setLugar("CDMX");
    Estudiante galo("Galo", 19, "IRS", false);

    Campus qro("Queretaro");
    qro.agregarEstudiante(ricardo);
    qro.agregarEstudiante(galo);
    qro.agregarEstudiante(daniel);
    qro.mostrarEstudiantes();

    Profesor benji("Benji", 40, 4000);
    benji.setSalario(1);
    benji.setLugar("Sonora");
    benji.agregarClases("OOP");
    benji.agregarClases("IOT");
    qro.agregarProfesor(benji);
    qro.mostrarProfesores();

    Empleado ezzat("Ezzat", 18, 150, "cajero", "playera azul");
    ezzat.setLugar("veracruz");
    qro.agregarEmpleado(ezzat);
    qro.mostrarEmpleados();

    return 0;
}