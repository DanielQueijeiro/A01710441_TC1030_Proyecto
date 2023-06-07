# Proyecto TC1030 
## Daniel Queijeiro Albo / A01710441

#### Contexto
El proyecto se basa en crear un sistema con el cual el Tecnológico de Monterrey pueda monitorear de manera más eficiente y correcta a las personas quienes son integrantes de la comunidad del Tec (estudiantes, profesores y empleados).

#### Funcionalidad
Se espera que con el código se optimize la manera en que el Tec administre a los integrantes de su comunidad, siendo capaces de agregar y acomodarlos por su rol dentro de la institución, o en caso de que sea necesario, también poder eliminarlos del sistema. Con esto se podrá tener en un solo sistema la información de todos los campus para su acceso y modificación rápida.

El programa solo permite:
- Ingreso de nuevos integrantes de la comunidad Tec.
- Eliminación de integrantes ingresados en el sistema.
- Obtener información sobre cualquier persona registrada en el sistema. 
- El cálculo de diferentes tipos de sueldos: Sueldo por clase para profesores, y sueldo por hora a empleados.
- El cálculo de colegiatura para estudiantes según el porcentaje de beca que tengan.

Consta de un menu con las opciones iniciales y corre sobre consola.

### Limitaciones (Casos que harían que el programa deje de funcionar)
- En caso de intentar ingresar un número total de Personas en un Campus como negativo.
- En caso de intentar obtener la colegiatura de un estudiante con una beca negativa.
- En caso de intentar obtener el sueldo de un profesor o empleado con clases negativas.

### Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

- compilar con: "g++ main.cpp"

- correr en linux: "/a.out"

- correr en windows: "a.exe"
