#include <iostream>

// Códigos ANSI para colores
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

int main() {
    std::cout << BOLD << CYAN << "=== BIENVENIDO AL PROGRAMA ===" << RESET << "\n\n";

    std::cout << GREEN  << "[CORRECTO] El proceso se ejecuto correctamente." << RESET << "\n";
    std::cout << YELLOW << "[ADVERTENCIA] Revisa la configuracion del sistema." << RESET << "\n";
    std::cout << RED    << "[ERROR] No se pudo encontrar el archivo." << RESET << "\n";

    return 0;
}