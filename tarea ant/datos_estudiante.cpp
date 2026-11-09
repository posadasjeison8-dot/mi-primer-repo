#include <iostream>
#include <string>
#include <vector>

struct Estudiante {
    std::string nombre;
    int edad;
    std::vector<std::string> materias;
    bool activo;
};

int main() {
    Estudiante e1 = {
        "Yeison",
        21,
        {"Programacion C++", "Base de Datos", "Estructuras de Datos"},
        true
    };

    std::cout << "--- INFORMACION DEL ESTUDIANTE ---\n";
    std::cout << "Nombre: " << e1.nombre << "\n";
    std::cout << "Edad: " << e1.edad << " anos\n";
    std::cout << "Estado: " << (e1.activo ? "Activo" : "Inactivo") << "\n";
    std::cout << "Materias inscritas:\n";

    for (size_t i = 0; i < e1.materias.size(); ++i) {
        std::cout << "  " << i + 1 << ". " << e1.materias[i] << "\n";
    }

    return 0;
}