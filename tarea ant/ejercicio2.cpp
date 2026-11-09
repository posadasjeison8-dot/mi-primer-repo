#include <iostream>

using namespace std;

// Función calcularAreaRectangulo que acepta la base y la altura por valor y devuelve el área
int calcularAreaRectangulo(int base, int altura) {
    return base * altura;
}

int main() {
    int base, altura;

    // Solicitar al usuario que ingrese la base y la altura
    cout << "Ingrese la base del rectangulo: ";
    cin >> base;
    
    cout << "Ingrese la altura del rectangulo: ";
    cin >> altura;

    // Llamar a la función calcularAreaRectangulo y mostrar el resultado en consola
    int area = calcularAreaRectangulo(base, altura);
    cout << "El area del rectangulo es: " << area << endl;

    return 0;
}