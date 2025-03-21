#include <iostream>
using namespace std;
#include <fstream>
#include <string>

/* En este ejercicio, use la sobrecarga de funciones para llevar a cabo cada punto.
    A) Hice la funcion logMessage que recibe un mensaje y un nivel de severidad (que se obtiene a partir de un switch) y lo imprime en la consola.
    B) i) La función test_logMessage1() ejecuta logMessage con sus 7 severidades.
       ii) Hice la función logMessage que recibe un mensaje de error, un archivo y una línea de código y lo imprime en la consola.
       iii) Hice la función logMessage que recibe un mensaje de acceso y un nombre de usuario y lo imprime en la consola.
       iv) La función test runtime_error(), al encontrarse con un error, lanza una excepción de tipo runtime_error y la captura en un catch.
           Además, cree las funciones test_logMessage2() y test_logMessage3() que ejecutan logMessage con 4 mensajes de error y 4 mensajes de acceso, respectivamente, para comprobar su funcionalidad
       */

void logMessage(string mensaje, int nivel);
void logMessage(string mensaje_de_error, string archivo, int linea_de_código);
void logMessage(string mensaje_de_acceso, string nombre_de_usuario);
void test_logMessage1();
void test_logMessage2();
void test_logMessage3();
void test_runtime_error();

int main(){
    test_logMessage1();
    test_logMessage2();
    test_logMessage3();

    test_runtime_error();

    
    return 0;
}

/* Imprime un mensaje "mensaje" en la consola con el nivel de severidad correspondiente.
 * Los niveles de severidad son:
 * 0: DEBUG
 * 1: INFO
 * 2: WARNING
 * 3: ERROR
 * 4: CRITICAL
 * 5: SECURITY
 * 
 * en caso de que el nivel no sea ninguno de los anteriores, se imprime "UNKNOWN" como nivel de severidad. */
void logMessage(string mensaje, int nivel){
    string severidad;
    switch(nivel){
        case 0:
            severidad = "DEBUG";
            break;
        case 1:
            severidad = "INFO";
            break;
        case 2:
            severidad = "WARNING";
            break;
        case 3:
            severidad = "ERROR";
            break;
        case 4:
            severidad = "CRITICAL";
            break;
        case 5:
            severidad = "SECURITY";
            break;
        default:
            severidad = "UNKNOWN";
            break;
    }

    cout << "[" << severidad << "] <" << mensaje << ">" << endl;
}

/* Test que ejecuta log message con sus 7 severidades.*/
void test_logMessage1(){
    logMessage("Inicio del programa", 0);
    logMessage("Programa corriendo correctamente", 1);
    logMessage("No se pudo abrir el archivo", 2);
    logMessage("No se pudo leer el archivo", 3);
    logMessage("Archivo corrupto encontrado", 4);

    logMessage("Acceso concedido a admin", 5);

    logMessage("Error desconocido en runtime", 6);
}

/* Imprime un mensaje de error "mensaje_de_error" en la consola con el archivo y la línea de código donde ocurrió el error. */
void logMessage(string mensaje_de_error, string archivo, int linea_de_código){
    cout << "[ERROR] <" << mensaje_de_error << "> en el archivo " << archivo << " en la línea " << linea_de_código << endl;
}

/* Test que ejecuta logMessage con 4 mensajes de error. */
void test_logMessage2(){
    logMessage("Error en el bucle for", "programa.cpp", 10);
    logMessage("Error en la función main", "programa.cpp", 20);
    logMessage("Error en la función logMessage", "programa.cpp", 30);
    logMessage("Error en la función test_logMessage", "programa.cpp", 40);
}

/* Imprime un mensaje de acceso "mensaje_de_acceso" en la consola con el nombre de usuario que intentó acceder. */
void logMessage(string mensaje_de_acceso, string nombre_de_usuario){
    if(mensaje_de_acceso == "Access granted"){
        logMessage("Acceso concedido a " + nombre_de_usuario, 5);
    }else if(mensaje_de_acceso == "Access denied"){
        logMessage("Acceso denegado a " + nombre_de_usuario, 5);
    }else{
        logMessage("Acceso desconocido a " + nombre_de_usuario, 5);
    }
}


/* Test que ejecuta logMessage con 4 mensajes de acceso. */
void test_logMessage3(){
    logMessage("Access granted", "admin");
    logMessage("Access denied", "user");
    logMessage("Access granted", "root");
    logMessage("Access denied", "guest");
}

/* Test que lanza una excepción de tipo runtime_error y la captura en un catch. */
void test_runtime_error() {
    try {
        throw runtime_error("Se ha producido un error crítico en runtime.");
    } catch (const exception &e) {
        logMessage(e.what(), "main.cpp", 99); 
        exit(1); 
    }
}
