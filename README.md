# AC Arquitectura Computadures UGR

Prácticas de Arquitectura de Computadores (AC), Grado en Ingeniería Informática, UGR 2015-2016

## Descripción de las prácticas

## Práctica 0. Entorno de programación

Objetivos:

1. Usar ssh (secure shell) para conectarse desde un PC del aula a su home del nodo front-end del cluster atcgrid con el objetivo de ejecutar comandos.
2. Usar sftp (secure file transfer protocol) para conectarse desde un PC del aula a su home del front-end de atcgrid con el objetivo de cargar y descargar ficheros.
3. Enviar desde el front-end, usando las colas de TORQUE, trabajos a los dos nodos servidores de atcgrid usando qsub, comprobar el estado del trabajo en las colas con qstat, borrar trabajos de las colas con qdel y leer los dos ficheros de resultados (errores y salida del trabajo ejecutado) que devuelve qsub.
4. Obtener información del procesador (número de encapsulados, número de cores, denominación de marca, frecuencia de reloj, flag de características,…) en Linux.
5. Distinguir entre variables locales, globales y dinámicas en C/C++.
6. Usar la función clock_gettime()para obtener el tiempo de ejecución de un trozo de código de un programa.

## Práctica 1. Programación paralela I: Directivas OpenMP.

Objetivos:

1. Definir OpenMP y caracterizarlo dentro de las herramientas de programación.
2. Distinguir entre los tres componentes de OpenMP: directivas, funciones y variables de entorno.
3. Escribir código fuente OpenMP añadiendo, a código fuente C, directivas y funciones OpenMP.
4. Generar código ejecutable paralelo a partir de código fuente OpenMP usando el compilador gcc desde la línea de comandos.
5. Escribir código fuente OpenMP a partir del cual se pueda generar código ejecutable secuencial (código fuente OpenMP portable).
6. Fijar, modificando variables de entorno, el número de threads que se va a utilizar en la ejecución de código ejecutable paralelo.
7. Distinguir entre directiva ejecutable y directiva declarativa.
8. Distinguir entre bloque estructurado, construcción y región.
9. Describir la acción que realiza y utilizar la directiva parallel.
10. Describir las acciones que realizan y utilizar las directivas de trabajo compartido de OpenMP for, sections y single.
11. Describir las acciones que realizan y utilizar las directivas para comunicación y sincronización critical, atomic y barrier.
12. Distinguir entre las directivas single y master.
13. Usar la directiva parallel y las directivas de trabajo compartido de OpenMP para paralelizar un código paralelo.
14. Generar el código ensamblador de un programa fuente usando la opción -S de gcc.
15. Obtener el tiempo de ejecución (elapsed time), tiempo de CPU, los MIPS y los MFLOPS de un código.

## Práctica 2. Programación paralela II: Cláusulas OpenMP.

Objetivos:

1. Distinguir entre directivas y cláusulas.
2. Describir la acción que realizan las cláusulas que determinan el ámbito de variables (shared, private, lastprivate, firstprivate, default) y explicar las diferencias entre ellas.
3. Describir la acción que realizan las cláusulas para comunicación y sincronización reduction y copyprivate.
4. Usar cláusulas de ámbito de variables: shared, private, lastprivate, firstprivate, default.
5. Discernir el ámbito de una variable en un código.
6. Usar la cláusula de comunicación y sincronización reduction.
7. Estudiar la escalabilidad de un programa en una plataforma

## Práctica 3. Programación paralela III: Interacción con el entorno en OpenMP.

Objetivos:

1. Definir las variables de control de OpenMP nthreads-var, dyn-var, nest-var, run-sched-var, def-sched-var
2. Usar las variables de entorno OMP_NUM_THREADS, OMP_DYNAMIC, OMP_SCHEDULE para modificar y consultar variables de control.
3. Usar las funciones de OpenMP 2.5 para modificar y consultar las variables de control: omp_get_dynamic(), omp_set_dynamic(), omp_get_num_threads(), omp_set_num_threads(), omp_get_thread_num(), omp_get_max_threads(), omp_get_num_procs(), omp_in_parallel().
4. Usar las siguientes funciones de OpenMP 3.0 que modifican y consultan las variables de control: omp_get_thread_limit, omp_get_schedule(kind,modifier) y omp_set_schedule(kind, modifier)
5. Describir la diferencia entre las dos cláusulas que influyen en el número de threads de una región paralela (if, num_threads) y ser capaz de usarlas.
6. Describir la acción que realizan las diferentes variantes de la cláusula schedule de la versión 2.5 de OpenMP que determinan la planificación de bucles (static, dynamic, guided, runtime), y ser capaz de usarlas.
7. Deducir el número de threads que va a ejecutar un trozo de código en paralelo.

## Práctica 4. Optimización de código.

Se aprenderán alternativas para optimizar código teniendo en cuenta las características de la microarquitectura y la arquitectura del computador. Se pretende poner de manifiesto la importancia que en el proceso de optimización tiene el conocimiento de la máquina donde se ejecuta el programa. Si bien es posible escribir programas correctos para un computador a partir del modelo de programación propio del lenguaje de alto nivel que se utiliza, y sin conocer prácticamente nada de las características de la máquina, la generación de código eficaz, que extraiga el máximo partido de las características del computador, requiere que se tengan en cuenta detalles de la arquitectura (realizando ciertas optimizaciones a nivel ensamblador) y de la forma en que se ejecutan las instrucciones máquina (características de la microarquitectura).
