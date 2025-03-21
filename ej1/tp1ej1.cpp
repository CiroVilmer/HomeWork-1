#include <iostream>
using namespace std;
#include <fstream>
#include <string>

/*A) Para crear la matriz base reservamos memoria con new int*[num], luego, la llenamos de listas. Una vez creada la matriz, la recorremos
    con 2 bucles y vamos asignando los numeros de manera ascendente. Finalmente, retornamos la matriz. 
    Para no perder memoria, cree la función free_matriz, que libera toda la memoria utilizada por la matriz
  B) Para recorrer la matriz con 1 solo bucle, primero calculamos la cantidad total de elementos de la matriz (num*num). Luego, recorremos
    la matriz en orden inverso (para poder imprimirla en órden inverso como pide la consigna), calculando la fila y columna de cada elemento con las operaciones i/num, para obtener
    la fila, y i%num, para obtener la columna. Por último, printeamos el elemento de la matriz en la posición [fila][columna].
*/

int** devolver_matriz(int num);
void free_matriz(int** matriz, int num);
void print_matriz(int num, int** matriz);

int main(){
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;

    int** matriz = devolver_matriz(num);
    print_matriz(num, matriz);
    free_matriz(matriz, num);

    return 0;
}

/*Devuelve una matriz cuadrada de tamaño num*num y llena de números en forma ascendente.*/
int** devolver_matriz(int num){
    int** matriz = new int*[num];

    for(int i = 0; i < num; i++){
        matriz[i] = new int[num];
    }
    int c = 1;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            matriz[i][j] = c;
            c++;
        }
    }

    return matriz;
}

/*Libera toda la memoria utilizada por la matriz "matriz".*/
void free_matriz(int** matriz, int num){
    for(int i = 0; i < num; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

/*Imprime la matriz en órden inverso.*/
void print_matriz(int num, int** matriz){
    int total_elementos = num*num;
    
    for(int i = total_elementos - 1; i >= 0; i--){
        int fila = i/num;
        int columna = i%num;
        cout << "M" << num << "[" << fila << "][" << columna << "] = " << matriz[fila][columna] << endl;
    }

}