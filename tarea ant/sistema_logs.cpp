#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>

void registrarLog(const std::string& nivel, const std::string& mensaje) {
    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempo = std::chrono::system_clock::to_time_t(ahora);
    std::string hora_str = std::ctime(&tiempo);
    
    if (!hora_str.empty()) hora_str.pop_back();

    std::string formato = "[" + hora_str + "] [" + nivel + "] " + mensaje;

    std::cout << formato << std::endl;

    std::ofstream archivo("app.log", std::ios::app);
    if (archivo.is_open()) {
        archivo << formato << "\n";
    }
}

int main() {
    std::cout << "--- SISTEMA DE REGISTRO DE LOGS ---\n\n";

    registrarLog("INFO", "Iniciando ejecucion de la aplicacion");
    registrarLog("DEBUG", "Cargando componentes de la interfaz");
    registrarLog("WARN", "Uso de memoria cercano al limite");
    registrarLog("ERROR", "No se pudo conectar al servidor secundario");

    std::cout << "\nLos eventos han sido guardados en 'app.log'.\n";

    return 0;
}