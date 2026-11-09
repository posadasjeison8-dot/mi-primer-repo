#include <iostream>

using namespace std;

// Función esPar que acepta un número entero por valor y devuelve true si es par, false si es impar
bool esPar(int numero) {
    return (numero % 2 == 0);
}

int main() {
    int numeroUsuario;

    // Solicitar al usuario que ingrese un número
    cout << "Ingrese un numero entero: ";
    cin >> numeroUsuario;

    // Llamar a la función esPar y mostrar el resultado en la consola
    if (esPar(numeroUsuario)) {
        cout << "El numero " << numeroUsuario << " es par (true)." << endl;
    } else {
        cout << "El numero " << numeroUsuario << " es impar (false)." << endl;
    }

    return 0;
}