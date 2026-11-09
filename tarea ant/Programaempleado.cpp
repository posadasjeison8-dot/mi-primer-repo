#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 

using namespace std;

int main() {

// Definir e inicializar variables
string nombreEmpleado;
int edadEmpleado;
char sexoEmpleado;
double salarioEmpleado;
int tipoEmpleado;


double horasSemanalesTotales = 0;
    double sueldoPorHora = 0;
    double sueldoPorMinuto = 0;
    double sueldoPorSegundo = 0;
    double sueldoDiarioLV = 0;
    double sueldoSabado = 0;
    double sueldoSemanalLV = 0;
    double sueldoSemanalTotal = 0;
    double sueldoQuincenal = 0;
    double horasMensualesTotales = 0;



cout << "========== PILLOFON ===========" << endl;
cout << "Ingrese el nombre del empleado: ";
getline(cin >> ws, nombreEmpleado);
cout << "Ingrese la edad del empleado: ";
cin >> edadEmpleado;  
while (edadEmpleado < 18 or edadEmpleado > 65) {
    cout << "Edad fuera de rango" << endl;
    cout << "Ingrese la edad del empleado: ";
    cin >> edadEmpleado;
}
cout << "Ingrese el sexo del empleado (M/F): ";
cin >> sexoEmpleado;

cout << "Ingrese el salario del empleado: ";
cin >> salarioEmpleado; 
while (salarioEmpleado < 16000 or salarioEmpleado > 100000) {
    cout << "salario fuera de rango" <<endl;
    cout << "ingrese el salario del empleado:";
    cin >> salarioEmpleado;

    }
    cout << "\n--- TIPO DE EMPLEADO ---\n";
    cout << "1. Empleado de planta\n";
    cout << "2. Empleado de medio tiempo\n";
    cout << "3. Empleado por contrato\n";
    cout << "Seleccione el tipo de empleado (1-3): ";
    cin >> tipoEmpleado;

    // Validar tipo de empleado y calcular horas
    switch (tipoEmpleado) {
        case 1: // Planta
            // Lunes a Viernes: 7:00 am a 5:30 pm = 10.5h - 1h almuerzo = 9.5h diarias
            // Sábado: 8:00 am a 3:00 pm = 7h - 1h almuerzo = 6h
            horasSemanalesTotales = (9.5 * 5) + 6.0; // 47.5 + 6 = 53.5 horas semanales
            break;
            
        case 2: // Medio tiempo
            // Lunes a Sábado: 7:00 am a 1:30 pm = 6.5h - 1h almuerzo = 5.5h diarias
            horasSemanalesTotales = 5.5 * 6; // 33 horas semanales
            break;
            
        case 3: // Contrato
            cout << "Ingrese las horas semanales trabajadas (30 a 40): ";
            cin >> horasSemanalesTotales;
            while (horasSemanalesTotales < 30 || horasSemanalesTotales > 40) {
                cout << "ERROR: horas fuera de rango permitido" << endl;
                cout << "Ingrese nuevamente las horas semanales (30 a 40): ";
                cin >> horasSemanalesTotales;
            }
            break;
            
        default:
            cout << "Opcion de empleado no valida." << endl;
            return 1;
    }

    // Cálculos basados en 4 semanas al mes
    double sueldoSemanal = salarioEmpleado / 4.0;
    sueldoPorHora = sueldoSemanal / horasSemanalesTotales;
    sueldoPorMinuto = sueldoPorHora / 60.0;
    sueldoPorSegundo = sueldoPorMinuto / 60.0;
    
    // Cálculos específicos por tipo
    if (tipoEmpleado == 1) {
        sueldoDiarioLV = sueldoPorHora * 9.5;
        sueldoSabado = sueldoPorHora * 6.0;
        sueldoSemanalLV = sueldoDiarioLV * 5;
        sueldoSemanalTotal = sueldoSemanalLV + sueldoSabado;
    } else if (tipoEmpleado == 2) {
        sueldoDiarioLV = sueldoPorHora * 5.5;
        sueldoSabado = sueldoPorHora * 5.5;
        sueldoSemanalLV = sueldoDiarioLV * 5;
        sueldoSemanalTotal = sueldoSemanalLV + sueldoSabado;
    } else { // Contrato (distribuido de forma general o proporcional)
        sueldoDiarioLV = sueldoPorHora * (horasSemanalesTotales / 6.0); // Estimado diario
        sueldoSabado = 0;
        sueldoSemanalLV = sueldoSemanal;
        sueldoSemanalTotal = sueldoSemanal;
    }

    sueldoQuincenal = salarioEmpleado / 2.0;
    horasMensualesTotales = horasSemanalesTotales * 4.0;

    // Mostrar el reporte final desglosado
    cout << "\n=========================================" << endl;
    cout << "           REPORTE DE SALARIOS           " << endl;
    cout << "=========================================" << endl;
    cout << "Empleado: " << nombreEmpleado << endl;
    cout << "Edad: " << edadEmpleado << " anios | Sexo: " << sexoEmpleado << endl;
    cout << fixed << setprecision(2);
    cout << "Salario Mensual Base: L. " << salarioEmpleado << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Sueldo diario (Lunes a Viernes): L. " << sueldoDiarioLV << endl;
    cout << "2. Sueldo de los sabados: L. " << sueldoSabado << endl;
    cout << "3. Sueldo por Hora: L. " << sueldoPorHora << endl;
    cout << "4. Sueldo por minuto: L. " << sueldoPorMinuto << endl;
    cout << "5. Sueldo por segundo: L. " << sueldoPorSegundo << endl;
    cout << "6. Sueldo semanal (Lunes a Viernes): L. " << sueldoSemanalLV << endl;
    cout << "7. Sueldo semanal total (Lunes a Sabado): L. " << sueldoSemanalTotal << endl;
    cout << "8. Sueldo quincenal: L. " << sueldoQuincenal << endl;
    cout << "9. Horas trabajadas totales (Mensuales): " << horasMensualesTotales << " hrs" << endl;
    cout << "=========================================" << endl;

    return 0;
}

