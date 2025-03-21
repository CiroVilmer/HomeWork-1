#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <chrono>

/*En este ejercicio tuve que cambiar find_match a una función constexpr para que se ejecute en tiempo de compilación. 
  Para esto, tuve que cambiar los strings a punteros de char (ya que no se permitian strings en constexpr), y cambiar la función find_match a una función constexpr que 
  compare los punteros de char recursivamente hasta que ambos sean '\0' o hasta que se encuentren chars distintos. Si en algún momento los punteros no son iguales, 
  se retorna false. Si ambos punteros son '\0', se retorna true.

    Luego, cree una variable comparison_result que guarda el resultado de la comparación de dos frases predefinidas dentro del tiempo de compilación.
    Por último, cree una función print_response que imprime si los textos coinciden o no.
*/


/* Encuentra si dos palabras o frases, word1 y word2, son iguales. Devuelve true si son iguales y false si no lo son */
constexpr bool find_match_constexpr(const char* word1, const char* word2)
{
    if (*word1 == '\0' && *word2 == '\0')
        return true;
    if (*word1 != *word2)
        return false;
    return find_match_constexpr(word1 + 1, word2 + 1);
}

constexpr bool comparison_result = find_match_constexpr(
    "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programacion esta muy bueno.",
    "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programacion esta muy bueno."
);

/* Imprime si los textos coinciden o no */
void print_response(bool res)
{
    if (res == true)
        cout << "¡Los textos coinciden! :D" << endl;
    else
        cout << "Los textos no coinciden :o" << endl;
}

int main()
{
    auto startTime = std::chrono::high_resolution_clock::now();
    print_response(comparison_result); // La comparación ya ocurrió en tiempo de compilación
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    
    std::cout << "Tiempo de ejecución en main: " << elapsedTime.count() << " nanosegundos" << std::endl;
    return 0;
}
