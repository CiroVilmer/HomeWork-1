#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <chrono>

/* Para encontrar si dos frases son iguales o no, pense en implementar una función que vaya comparando sus primeras letras de forma recursiva. 
    Si las primeras letras son iguales, la función recursiva se vuelve a llamar, sacándole la primera letra a ambas frases. En caso de no ser la misma letra,
    se retorna false. Si ambos strings quedan vacios, eso quiere decir que eran iguales y retorna true.
    
    Luego implemente las funciones pedidas sin mucho cambio, mas que la función test_input_match que pide al usuario dos palabras o frases para comparar.
*/

/* Encuentra si dos palabras o frases, word1 y word2, son iguales. Devuelve true si son iguales y false si no lo son */
bool find_match(string word1, string word2)
{
    if (word1 == "" && word2 == "")
        return true;
    else if (word1[0] != word2[0])
        return false;

    return find_match(word1.erase(0, 1), word2.erase(0, 1));
}

/* Imprime si los textos coinciden o no */
void print_response(bool res)
{
    if (res == true)
        cout << "¡Los textos coinciden! :D" << endl;
    else
        cout << "Los textos no coinciden :o" << endl;
}

/* Testea la función find_match con dos palabras o frases ingresadas por el usuario */
void test_input_match()
{
    cout << "Ingrese la primera palabra" << endl;
    string word1;
    cin >> word1;

    cout << "Ingrese la segunda palabra" << endl;
    string word2;
    cin >> word2;

    bool res = find_match(word1, word2);
    print_response(res);
}

/* Testea la función find_match con dos frases predefinidas.*/
void test_match()
{   
    string text_1 = "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programación esta muy bueno.";
    string text_2 = "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programación esta muy bueno.";

    bool res = find_match(text_1, text_2);
    print_response(res);

    text_1 = "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programación esta muy bueno.";
    text_2 = "Hola buenas tardes, mi nombre es Facundo Alberto y estudio Naturaleza y medioambienta en la facultad de UTN.";

    bool res2 = find_match(text_1, text_2);
    print_response(res2);
}

/* Testea la función find_match con dos frases predefinidas y mide el tiempo que tarda en ejecutarse */
void test_match_and_time()
{
    auto startTime = std::chrono::high_resolution_clock::now();
    string text_1 = "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programación esta muy bueno.";
    string text_2 = "Hola buenas tardes, mi nombre es Ciro y estudio ingenieria en la facultad de Udesa. Curso en el campus Victoria y paradigmas de programación esta muy bueno.";

    bool res = find_match(text_1, text_2);
    print_response(res);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "A (find_match) le tomó : " << elapsedTime.count() << " nanosegundos " << std::endl;
}

int main()
{
    test_match_and_time();

    return 0;
}
