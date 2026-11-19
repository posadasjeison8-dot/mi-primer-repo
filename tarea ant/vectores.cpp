#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <stdexcept> // Para out_of_range

using namespace std;

struct Estudiante {
    string nombre;
    long long numeroCuenta;
    int edad;
    char sexo;
    string carrera;

    double nota1, nota2, nota3;
    double pond1, pond2, pond3;
    double notaFinal;
    string obs1, obs2, obs3, obsFinal;
};

bool esTextoValido(const string &texto) {
    if (texto.empty()) {
        return false;
    }

    bool tieneLetra = false;
    for (unsigned char c : texto) {
        if (isdigit(c)) {
            return false;
        }
        if (isalpha(c)) {
            tieneLetra = true;
        } else if (c != ' ') {
            return false;
        }
    }
    return tieneLetra;
}

void procesarCalificaciones(Estudiante &est) {
    est.pond1 = est.nota1 * 0.25;
    est.pond2 = est.nota2 * 0.35;
    est.pond3 = est.nota3 * 0.40;

    est.notaFinal = est.pond1 + est.pond2 + est.pond3;

    est.obs1 = (est.nota1 >= 65.0) ? "Aprobado" : "Reprobado";
    est.obs2 = (est.nota2 >= 65.0) ? "Aprobado" : "Reprobado";
    est.obs3 = (est.nota3 >= 65.0) ? "Aprobado" : "Reprobado";
    est.obsFinal = (est.notaFinal >= 65.0) ? "Aprobado" : "Reprobado";
}

void mostrarEstudiante(const Estudiante &est, const string &titulo) {
    cout << "\n==================================================" << endl;
    cout << " " << titulo << endl;
    cout << "==================================================" << endl;
    cout << "Nombre: " << est.nombre << " | Cuenta: " << est.numeroCuenta << endl;
    cout << "Edad: " << est.edad << " | Sexo: " << est.sexo << " | Carrera: " << est.carrera << endl;
    cout << "--------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "I Parcial (25%):   " << est.nota1 << " -> Pond: " << est.pond1 << " (" << est.obs1 << ")" << endl;
    cout << "II Parcial (35%):  " << est.nota2 << " -> Pond: " << est.pond2 << " (" << est.obs2 << ")" << endl;
    cout << "III Parcial (40%): " << est.nota3 << " -> Pond: " << est.pond3 << " (" << est.obs3 << ")" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "NOTA FINAL: " << est.notaFinal << " -> " << est.obsFinal << endl;
    cout << "==================================================" << endl;
}

int main() {
    vector<Estudiante> estudiantes;
    int opcion;

    do {
        cout << "\n=== MENU PRINCIPAL (Registrados: " << estudiantes.size() << ") ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver todos los estudiantes" << endl;
        cout << "3. Ver PRIMER estudiante registrado" << endl;
        cout << "4. Ver ULTIMO estudiante registrado" << endl;
        cout << "5. Limpiar / borrar todos los registros" << endl;
        cout << "6. Ver estudiante por numero de registro / posicion" << endl;
        cout << "0. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                Estudiante nuevo;

                cout << "\n--- Nuevo Estudiante ---" << endl;

                do {
                    cout << "Nombre completo: ";
                    getline(cin, nuevo.nombre);

                    if (!esTextoValido(nuevo.nombre)) {
                        cout << "[!] Error: El nombre no puede contener numeros ni quedar vacio. Intenta de nuevo." << endl;
                    }
                } while (!esTextoValido(nuevo.nombre));

                cout << "Numero de cuenta: ";
                cin >> nuevo.numeroCuenta;

                cout << "Edad: ";
                cin >> nuevo.edad;

                do {
                    cout << "Sexo: ";
                    cin >> nuevo.sexo;
                    nuevo.sexo = toupper(static_cast<unsigned char>(nuevo.sexo));

                    if (nuevo.sexo != 'M' && nuevo.sexo != 'F') {
                        cout << "[!] Error: Solo se permite 'M' o 'F'. Intenta de nuevo." << endl;
                    }
                } while (nuevo.sexo != 'M' && nuevo.sexo != 'F');
                cin.ignore();

                do {
                    cout << "Carrera: ";
                    getline(cin, nuevo.carrera);

                    if (!esTextoValido(nuevo.carrera)) {
                        cout << "[!] Error: La carrera no puede contener numeros ni quedar vacia. Intenta de nuevo." << endl;
                    }
                } while (!esTextoValido(nuevo.carrera));

                cout << "Nota 1 - I Parcial (0-100): ";
                cin >> nuevo.nota1;
                cout << "Nota 2 - II Parcial (0-100): ";
                cin >> nuevo.nota2;
                cout << "Nota 3 - III Parcial (0-100): ";
                cin >> nuevo.nota3;
                cin.ignore();

                procesarCalificaciones(nuevo);

                estudiantes.push_back(nuevo);
                cout << "\n[OK] Estudiante agregado. Total en vector: " << estudiantes.size() << endl;
                break;
            }

            case 2: {
                if (estudiantes.empty()) {
                    cout << "\n[!] No hay estudiantes registrados en el vector." << endl;
                } else {
                    for (size_t i = 0; i < estudiantes.size(); i++) {
                        mostrarEstudiante(estudiantes[i], "ESTUDIANTE #" + to_string(i + 1));
                    }
                }
                break;
            }

            case 3: {
                if (estudiantes.empty()) {
                    cout << "\n[!] El vector esta vacio. No existe un primer estudiante." << endl;
                } else {
                    mostrarEstudiante(estudiantes.front(), "PRIMER ESTUDIANTE REGISTRADO (front)");
                }
                break;
            }

            case 4: {
                if (estudiantes.empty()) {
                    cout << "\n[!] El vector esta vacio. No existe un ultimo estudiante." << endl;
                } else {
                    mostrarEstudiante(estudiantes.back(), "ULTIMO ESTUDIANTE REGISTRADO (back)");
                }
                break;
            }

            case 5: {
                if (estudiantes.empty()) {
                    cout << "\n[!] El vector ya esta vacio." << endl;
                } else {
                    estudiantes.clear();
                    cout << "\n[OK] Todos los registros fueron eliminados con clear()." << endl;
                    cout << "Tamano actual del vector: " << estudiantes.size() << endl;
                }
                break;
            }

            case 6: {
                if (estudiantes.empty()) {
                    cout << "\n[!] El vector esta vacio. No hay estudiantes para consultar." << endl;
                } else {
                    int posicion;
                    cout << "Ingrese el numero de estudiante a ver (1 a " << estudiantes.size() << "): ";
                    cin >> posicion;
                    cin.ignore();

                    if (posicion < 1 || static_cast<size_t>(posicion) > estudiantes.size()) {
                        cout << "\n[!] Error: El estudiante #" << posicion
                             << " no existe. Hay " << estudiantes.size() << " registrados." << endl;
                    } else {
                        try {
                            size_t indice = static_cast<size_t>(posicion - 1);
                            mostrarEstudiante(estudiantes.at(indice), "ESTUDIANTE #" + to_string(posicion) + " (at)");
                        } catch (const out_of_range &e) {
                            cout << "\n[!] Error de rango: " << e.what() << endl;
                        }
                    }
                }
                break;
            }

            case 0:
                cout << "\nSaliendo del programa..." << endl;
                break;

            default:
                cout << "\n[!] Opcion no valida. Intenta de nuevo." << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}