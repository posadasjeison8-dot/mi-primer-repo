#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string nombre = "Usuario";
    int repeticiones = 1;

    // Procesar parámetros recibidos por consola
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if ((arg == "-n" || arg == "--nombre") && i + 1 < argc) {
            nombre = argv[++i];
        } else if ((arg == "-r" || arg == "--repetir") && i + 1 < argc) {
            repeticiones = std::stoi(argv[++i]);
        }
    }

    std::cout << "--- ANALIZADOR DE ARGUMENTOS CLI ---\n";
    for (int i = 1; i <= repeticiones; ++i) {
        std::cout << i << ". Hola " << nombre << "!\n";
    }

    return 0;
}