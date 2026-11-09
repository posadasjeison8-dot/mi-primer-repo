#include <iostream>
#include <string>

using namespace std;

// Función para mostrar el menú principal de categorías
void mostrarMenuPrincipal() {
    cout << "\n========================================\n";
    cout << "     TIENDA DE ROPA \"PUMA MEGAPACA\"     \n";
    cout << "========================================\n";
    cout << "1. Ropa Casual\n";
    cout << "2. Ropa de Oficina\n";
    cout << "3. Calzado\n";
    cout << "4. Accesorios\n";
    cout << "5. Ver Carrito de Compras / Facturar\n";
    cout << "6. Salir / Finalizar Dia (Estadisticas)\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    // Variables acumuladoras globales para estadísticas del día
    int totalClientesAtendidos = 0;
    double totalVentasLpsDia = 0;
    double totalDescuentosDia = 0;
    double totalIsvDia = 0;
    
    // Contadores de unidades vendidas por producto
    int vCamiseta = 0, vJeans = 0, vSudera = 0;
    int vCamisaForm = 0, vPantVestir = 0, vBlazer = 0;
    int vTenis = 0, vZapatosForm = 0, vSandalias = 0;
    int vCinturon = 0, vGorra = 0, vBolso = 0;

    // Ganancias netas por categoría (sin ISV)
    double gananciaCasual = 0;
    double gananciaOficina = 0;
    double gananciaCalzado = 0;
    double gananciaAccesorios = 0;

    // Métodos de pago (Contadores)
    int pagosEfectivo = 0;
    int pagosTransferencia = 0;

    char continuarDia = 'S';
    while (continuarDia == 'S' || continuarDia == 's') {
        cout << "\n----------------------------------------\n";
        cout << "         REGISTRO DE NUEVO CLIENTE      \n";
        cout << "----------------------------------------\n";
        
        // Validación de Nombre (No permite que sean solo números o esté vacío)
        string nombreCliente = "";
        bool nombreValido = false;
        while (!nombreValido) {
            cout << "Ingrese el nombre del cliente: ";
            cin >> ws; 
            getline(cin, nombreCliente);

            if (nombreCliente.empty()) {
                cout << "¡Error! El nombre no puede estar vacio.\n";
                continue;
            }

            bool esSoloNumeros = true;
            for (int i = 0; i < nombreCliente.length(); i++) {
                if (nombreCliente[i] != '0' && nombreCliente[i] != '1' && nombreCliente[i] != '2' && 
                    nombreCliente[i] != '3' && nombreCliente[i] != '4' && nombreCliente[i] != '5' && 
                    nombreCliente[i] != '6' && nombreCliente[i] != '7' && nombreCliente[i] != '8' && 
                    nombreCliente[i] != '9' && nombreCliente[i] != ' ' && nombreCliente[i] != '\t') {
                    esSoloNumeros = false;
                    break;
                }
            }

            if (esSoloNumeros) {
                cout << "¡Ingrese un nombre valido (no se permiten solo numeros)!\n";
            } else {
                nombreValido = true;
            }
        }

        // Validación de Edad (Estrictamente entre 18 y 100 años)
        int edadCliente = 0;
        while (edadCliente < 18 || edadCliente > 100) {
            cout << "Ingrese la edad del cliente: ";
            cin >> edadCliente;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                edadCliente = 0;
            }
            if (edadCliente < 18 || edadCliente > 100) {
                cout << "¡Edad incorrecta! Debe ingresar una edad valida entre 18 y 100.\n";
            }
        }

        // Validación de Sexo (Estrictamente M o F)
        char sexoCliente = ' ';
        while (sexoCliente != 'M' && sexoCliente != 'm' && sexoCliente != 'F' && sexoCliente != 'f') {
            cout << "Ingrese el sexo del cliente (M para Masculino / F para Femenino): ";
            cin >> sexoCliente;
            if (sexoCliente != 'M' && sexoCliente != 'm' && sexoCliente != 'F' && sexoCliente != 'f') {
                cout << "¡Opcion incorrecta! Por favor ingrese un sexo valido (M o F).\n";
            }
        }

        // Validación de Tipo de Cliente (1, 2 o 3)
        int tipoCliente = 0;
        while (tipoCliente < 1 || tipoCliente > 3) {
            cout << "\nElija el Tipo de Cliente:\n";
            cout << "1. Regular (5% de descuento en Ropa Casual)\n";
            cout << "2. Premium (10% de descuento en Calzado y Accesorios)\n";
            cout << "3. Mayorista (12% de descuento en Ropa de Oficina)\n";
            cout << "Seleccione opcion (1-3): ";
            cin >> tipoCliente;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                tipoCliente = 0;
            }
            if (tipoCliente < 1 || tipoCliente > 3) {
                cout << "¡Error! Opcion invalida. Ingrese un numero entre 1 y 3.\n";
            }
        }

        // Mensaje de Bienvenida obligatorio
        cout << "\n========================================\n";
        cout << " ¡Bienvenido/a, " << nombreCliente << " a PUMA MEGAPACA! \n";
        cout << "========================================\n";

        // Variables de la compra actual del cliente
        int cCamiseta = 0, cJeans = 0, cSudera = 0;
        int cCamisaForm = 0, cPantVestir = 0, cBlazer = 0;
        int cTenis = 0, cZapatosForm = 0, cSandalias = 0;
        int cCinturon = 0, cGorra = 0, cBolso = 0;

        // Inventario inicial fijo por cliente
        int invCamiseta = 40, invJeans = 30, invSudera = 20;
        int invCamisaForm = 18, invPantVestir = 15, invBlazer = 10;
        int invTenis = 16, invZapatosForm = 12, invSandalias = 25;
        int invCinturon = 35, invGorra = 30, invBolso = 14;

        int opcionMenu = 0;
        while (opcionMenu != 6) {
            mostrarMenuPrincipal();
            cin >> opcionMenu;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                opcionMenu = 0;
            }

            if (opcionMenu == 1) { // Ropa Casual
                int opSub = 0;
                while (opSub != 4) {
                    cout << "\n--- ROPA CASUAL ---\n";
                    cout << "1. Camiseta basica    | Cod: C01 | Precio: Lps. 180.00 | Stock: " << invCamiseta << " | Puntos: 10\n";
                    cout << "2. Jeans clasico      | Cod: C02 | Precio: Lps. 450.00 | Stock: " << invJeans << " | Puntos: 25\n";
                    cout << "3. Sudadera           | Cod: C03 | Precio: Lps. 520.00 | Stock: " << invSudera << " | Puntos: 30\n";
                    cout << "4. Regresar al menu principal\n";
                    cout << "Seleccione producto: ";
                    cin >> opSub;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        opSub = 0;
                    }

                    if (opSub >= 1 && opSub <= 3) {
                        int cant = -1;
                        while (cant < 0) {
                            cout << "Ingrese la cantidad a comprar (Presione 0 para cancelar y regresar): ";
                            cin >> cant;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cant = -1;
                            }
                            if (cant < 0) {
                                cout << "¡Error! La cantidad no puede ser negativa.\n";
                            }
                        }

                        if (cant == 0) {
                            cout << "[!] Operacion cancelada. Regresando al menu...\n";
                        } else {
                            if (opSub == 1) {
                                if (cant <= invCamiseta) { cCamiseta += cant; invCamiseta -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invCamiseta << "\n"; }
                            } else if (opSub == 2) {
                                if (cant <= invJeans) { cJeans += cant; invJeans -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invJeans << "\n"; }
                            } else if (opSub == 3) {
                                if (cant <= invSudera) { cSudera += cant; invSudera -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invSudera << "\n"; }
                            }
                        }
                    } else if (opSub != 4) {
                        cout << "Opcion invalida.\n";
                    }
                }
            } 
            else if (opcionMenu == 2) { // Ropa de Oficina
                int opSub = 0;
                while (opSub != 4) {
                    cout << "\n--- ROPA DE OFICINA ---\n";
                    cout << "1. Camisa formal      | Cod: O01 | Precio: Lps. 650.00  | Stock: " << invCamisaForm << " | Puntos: 40\n";
                    cout << "2. Pantalon de vestir | Cod: O02 | Precio: Lps. 750.00  | Stock: " << invPantVestir << " | Puntos: 45\n";
                    cout << "3. Blazer             | Cod: O03 | Precio: Lps. 1,200.00| Stock: " << invBlazer << " | Puntos: 70\n";
                    cout << "4. Regresar al menu principal\n";
                    cout << "Seleccione producto: ";
                    cin >> opSub;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        opSub = 0;
                    }

                    if (opSub >= 1 && opSub <= 3) {
                        int cant = -1;
                        while (cant < 0) {
                            cout << "Ingrese la cantidad a comprar (Presione 0 para cancelar y regresar): ";
                            cin >> cant;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cant = -1;
                            }
                            if (cant < 0) {
                                cout << "¡Error! La cantidad no puede ser negativa.\n";
                            }
                        }

                        if (cant == 0) {
                            cout << "[!] Operacion cancelada. Regresando al menu...\n";
                        } else {
                            if (opSub == 1) {
                                if (cant <= invCamisaForm) { cCamisaForm += cant; invCamisaForm -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invCamisaForm << "\n"; }
                            } else if (opSub == 2) {
                                if (cant <= invPantVestir) { cPantVestir += cant; invPantVestir -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invPantVestir << "\n"; }
                            } else if (opSub == 3) {
                                if (cant <= invBlazer) { cBlazer += cant; invBlazer -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invBlazer << "\n"; }
                            }
                        }
                    } else if (opSub != 4) {
                        cout << "Opcion invalida.\n";
                    }
                }
            }
            else if (opcionMenu == 3) { // Calzado
                int opSub = 0;
                while (opSub != 4) {
                    cout << "\n--- CALZADO ---\n";
                    cout << "1. Tenis deportivos   | Cod: Z01 | Precio: Lps. 980.00  | Stock: " << invTenis << " | Puntos: 60\n";
                    cout << "2. Zapatos formales   | Cod: Z02 | Precio: Lps. 1,100.00| Stock: " << invZapatosForm << " | Puntos: 65\n";
                    cout << "3. Sandalias          | Cod: Z03 | Precio: Lps. 420.00  | Stock: " << invSandalias << " | Puntos: 20\n";
                    cout << "4. Regresar al menu principal\n";
                    cout << "Seleccione producto: ";
                    cin >> opSub;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        opSub = 0;
                    }

                    if (opSub >= 1 && opSub <= 3) {
                        int cant = -1;
                        while (cant < 0) {
                            cout << "Ingrese la cantidad a comprar (Presione 0 para cancelar y regresar): ";
                            cin >> cant;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cant = -1;
                            }
                            if (cant < 0) {
                                cout << "¡Error! La cantidad no puede ser negativa.\n";
                            }
                        }

                        if (cant == 0) {
                            cout << "[!] Operacion cancelada. Regresando al menu...\n";
                        } else {
                            if (opSub == 1) {
                                if (cant <= invTenis) { cTenis += cant; invTenis -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invTenis << "\n"; }
                            } else if (opSub == 2) {
                                if (cant <= invZapatosForm) { cZapatosForm += cant; invZapatosForm -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invZapatosForm << "\n"; }
                            } else if (opSub == 3) {
                                if (cant <= invSandalias) { cSandalias += cant; invSandalias -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invSandalias << "\n"; }
                            }
                        }
                    } else if (opSub != 4) {
                        cout << "Opcion invalida.\n";
                    }
                }
            }
            else if (opcionMenu == 4) { // Accesorios
                int opSub = 0;
                while (opSub != 4) {
                    cout << "\n--- ACCESORIOS ---\n";
                    cout << "1. Cinturon           | Cod: A01 | Precio: Lps. 220.00  | Stock: " << invCinturon << " | Puntos: 12\n";
                    cout << "2. Gorra              | Cod: A02 | Precio: Lps. 160.00  | Stock: " << invGorra << " | Puntos: 8\n";
                    cout << "3. Bolso              | Cod: A03 | Precio: Lps. 850.00  | Stock: " << invBolso << " | Puntos: 50\n";
                    cout << "4. Regresar al menu principal\n";
                    cout << "Seleccione producto: ";
                    cin >> opSub;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        opSub = 0;
                    }

                    if (opSub >= 1 && opSub <= 3) {
                        int cant = -1;
                        while (cant < 0) {
                            cout << "Ingrese la cantidad a comprar (Presione 0 para cancelar y regresar): ";
                            cin >> cant;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cant = -1;
                            }
                            if (cant < 0) {
                                cout << "¡Error! La cantidad no puede ser negativa.\n";
                            }
                        }

                        if (cant == 0) {
                            cout << "[!] Operacion cancelada. Regresando al menu...\n";
                        } else {
                            if (opSub == 1) {
                                if (cant <= invCinturon) { cCinturon += cant; invCinturon -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invCinturon << "\n"; }
                            } else if (opSub == 2) {
                                if (cant <= invGorra) { cGorra += cant; invGorra -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invGorra << "\n"; }
                            } else if (opSub == 3) {
                                if (cant <= invBolso) { cBolso += cant; invBolso -= cant; cout << "¡Agregado con exito!\n"; }
                                else { cout << "Stock insuficiente. Stock disponible: " << invBolso << "\n"; }
                            }
                        }
                    } else if (opSub != 4) {
                        cout << "Opcion invalida.\n";
                    }
                }
            }
            else if (opcionMenu == 5) { // Carrito de compras / Facturación
                int totalArticulos = cCamiseta + cJeans + cSudera + cCamisaForm + cPantVestir + cBlazer + cTenis + cZapatosForm + cSandalias + cCinturon + cGorra + cBolso;

                if (totalArticulos == 0) {
                    cout << "\n[!] El carrito esta vacio. No puede facturar si no lleva ningun producto.\n";
                } else {
                    // Cálculo de Subtotales por categoría
                    double subCasual = (cCamiseta * 180.0) + (cJeans * 450.0) + (cSudera * 520.0);
                    double subOficina = (cCamisaForm * 650.0) + (cPantVestir * 750.0) + (cBlazer * 1200.0);
                    double subCalzado = (cTenis * 980.0) + (cZapatosForm * 1100.0) + (cSandalias * 420.0);
                    double subAccesorios = (cCinturon * 220.0) + (cGorra * 160.0) + (cBolso * 850.0);

                    double subtotalGeneral = subCasual + subOficina + subCalzado + subAccesorios;

                    // Descuentos por tipo de cliente
                    double descTipoClienteLps = 0;
                    string descTipoStr = "Ninguno";
                    if (tipoCliente == 1) { 
                        descTipoClienteLps = subCasual * 0.05;
                        descTipoStr = "5% en Ropa Casual (Regular)";
                    } else if (tipoCliente == 2) { 
                        descTipoClienteLps = (subCalzado + subAccesorios) * 0.10;
                        descTipoStr = "10% en Calzado/Accesorios (Premium)";
                    } else if (tipoCliente == 3) { 
                        descTipoClienteLps = subOficina * 0.12;
                        descTipoStr = "12% en Ropa de Oficina (Mayorista)";
                    }

                    // Descuentos adicionales por género
                    double descGeneroLps = 0;
                    string descGeneroStr = "Ninguno";
                    if ((sexoCliente == 'F' || sexoCliente == 'f') && subAccesorios > 0) {
                        descGeneroLps = subAccesorios * 0.08; 
                        descGeneroStr = "8% adicional en Accesorios (Mujeres)";
                    } else if ((sexoCliente == 'M' || sexoCliente == 'm') && subCalzado > 0) {
                        descGeneroLps = subCalzado * 0.05; 
                        descGeneroStr = "5% adicional en Calzado (Hombres)";
                    }

                    // Descuento por tercera edad (>= 60 años)
                    double descTerceraEdadLps = 0;
                    string descTerceraStr = "No aplica";
                    if (edadCliente >= 60) {
                        descTerceraEdadLps = subtotalGeneral * 0.10; 
                        descTerceraStr = "10% Tercera Edad";
                    }

                    // Promociones especiales acumulables
                    double descPromoLps = 0;
                    string descPromoStr = "Ninguna";
                    if (cCamiseta > 0 && cJeans > 0) {
                        double subOutfit = (cCamiseta * 180.0) + (cJeans * 450.0);
                        descPromoLps += subOutfit * 0.06; 
                        descPromoStr = "Outfit Completo (Camiseta+Jeans)";
                    }
                    if (cCamisaForm > 0 && cPantVestir > 0) {
                        double subOficinaPro = (cCamisaForm * 650.0) + (cPantVestir * 750.0);
                        descPromoLps += subOficinaPro * 0.07; 
                        if (descPromoStr == "Ninguna") descPromoStr = "Oficina Pro";
                        else descPromoStr += " + Oficina Pro";
                    }

                    // Descuento por volumen (> 3 unidades del mismo producto)
                    if (cCamiseta > 3) descPromoLps += (cCamiseta * 180.0) * 0.04;
                    if (cJeans > 3) descPromoLps += (cJeans * 450.0) * 0.04;
                    if (cSudera > 3) descPromoLps += (cSudera * 520.0) * 0.04;
                    if (cCamisaForm > 3) descPromoLps += (cCamisaForm * 650.0) * 0.04;
                    if (cPantVestir > 3) descPromoLps += (cPantVestir * 750.0) * 0.04;
                    if (cBlazer > 3) descPromoLps += (cBlazer * 1200.0) * 0.04;
                    if (cTenis > 3) descPromoLps += (cTenis * 980.0) * 0.04;
                    if (cZapatosForm > 3) descPromoLps += (cZapatosForm * 1100.0) * 0.04;
                    if (cSandalias > 3) descPromoLps += (cSandalias * 420.0) * 0.04;
                    if (cCinturon > 3) descPromoLps += (cCinturon * 220.0) * 0.04;
                    if (cGorra > 3) descPromoLps += (cGorra * 160.0) * 0.04;
                    if (cBolso > 3) descPromoLps += (cBolso * 850.0) * 0.04;

                    double totalDescuentos = descTipoClienteLps + descGeneroLps + descTerceraEdadLps + descPromoLps;
                    double subtotalConDescuento = subtotalGeneral - totalDescuentos;
                    if (subtotalConDescuento < 0) subtotalConDescuento = 0;

                    double isv = subtotalConDescuento * 0.15; 
                    double totalPagarLps = subtotalConDescuento + isv;
                    double totalPagarUsd = totalPagarLps / 26.42; 

                    // Cálculo de puntos acumulados
                    int puntosCliente = (cCamiseta * 10) + (cJeans * 25) + (cSudera * 30) +
                                        (cCamisaForm * 40) + (cPantVestir * 45) + (cBlazer * 70) +
                                        (cTenis * 60) + (cZapatosForm * 65) + (cSandalias * 20) +
                                        (cCinturon * 12) + (cGorra * 8) + (cBolso * 50);

                    // Vista previa del Carrito
                    cout << "\n========================================\n";
                    cout << "          CARRITO DE COMPRAS            \n";
                    cout << "========================================\n";
                    cout << "Articulos en total: " << totalArticulos << "\n";
                    cout << "Subtotal en Lps: Lps. " << subtotalGeneral << "\n";
                    cout << "Subtotal en USD: $ " << (subtotalGeneral / 26.42) << "\n";
                    cout << "Descuentos Aplicados:\n";
                    cout << " - Tipo de Cliente: Lps. " << descTipoClienteLps << "\n";
                    cout << " - Genero: Lps. " << descGeneroLps << "\n";
                    cout << " - Tercera Edad: Lps. " << descTerceraEdadLps << "\n";
                    cout << " - Promociones: Lps. " << descPromoLps << "\n";
                    cout << "Total Descuentos: Lps. " << totalDescuentos << "\n";
                    cout << "ISV (15%): Lps. " << isv << "\n";
                    cout << "TOTAL A PAGAR: Lps. " << totalPagarLps << "  |  $ " << totalPagarUsd << "\n";
                    cout << "Puntos a acumular: " << puntosCliente << "\n";
                    cout << "----------------------------------------\n";
                    
                    int opcionFacturar = 0;
                    while (opcionFacturar != 1 && opcionFacturar != 2) {
                        cout << "¿Desea proceder a facturar? (1. Si / 2. No, seguir comprando): ";
                        cin >> opcionFacturar;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            opcionFacturar = 0;
                        }
                        if (opcionFacturar != 1 && opcionFacturar != 2) {
                            cout << "¡Opcion invalida! Ingrese 1 para Si o 2 para No.\n";
                        }
                    }

                    if (opcionFacturar == 1) {
                        // Selección de Método de Pago
                        int metodoPago = 0;
                        while (metodoPago != 1 && metodoPago != 2) {
                            cout << "\n--- METODOS DE PAGO ---\n";
                            cout << "1. Efectivo (Ingresar monto recibido y calcular cambio)\n";
                            cout << "2. Transferencia (Comprobante, banco de emision y destino)\n";
                            cout << "Seleccione metodo de pago: ";
                            cin >> metodoPago;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                metodoPago = 0;
                            }
                        }

                        if (metodoPago == 1) {
                            double efectivoRecibido = 0;
                            while (efectivoRecibido < totalPagarLps) {
                                cout << "Ingrese monto recibido en efectivo (Lps.): ";
                                cin >> efectivoRecibido;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    efectivoRecibido = 0;
                                }
                                if (efectivoRecibido < totalPagarLps) {
                                    cout << "El monto es menor al total a pagar. Intente de nuevo.\n";
                                }
                            }
                            double cambio = efectivoRecibido - totalPagarLps;
                            cout << "Cambio a entregar: Lps. " << cambio << "\n";
                            pagosEfectivo++;
                        } else {
                            string numComprobante = "";
                            // Validación estricta: el comprobante debe tener entre 6 y 30 dígitos
                            while (numComprobante.length() < 6 || numComprobante.length() > 30) {
                                cout << "Ingrese numero de comprobante/referencia (debe tener entre 6 y 30 caracteres): ";
                                cin >> numComprobante;
                                if (numComprobante.length() < 6 || numComprobante.length() > 30) {
                                    cout << "¡Numero de comprobante incorrecto! Debe tener entre 6 y 30 digitos.\n";
                                }
                            }

                            string bancoEmision, bancoDestino;
                            cout << "Ingrese banco de emision: ";
                            cin >> ws;
                            getline(cin, bancoEmision);
                            cout << "Ingrese banco de destino: ";
                            getline(cin, bancoDestino);
                            cout << "Transferencia registrada con exito.\n";
                            pagosTransferencia++;
                        }

                        // Generación de Factura Oficial
                        cout << "\n\n========================================\n";
                        cout << "        PUMA MEGAPACA - FACTURA         \n";
                        cout << "========================================\n";
                        cout << "Cliente: " << nombreCliente << "\n";
                        cout << "Edad: " << edadCliente << " años  |  Sexo: " << sexoCliente << "\n";
                        cout << "Tipo de Cliente: ";
                        if (tipoCliente == 1) cout << "Regular\n";
                        else if (tipoCliente == 2) cout << "Premium\n";
                        else cout << "Mayorista\n";
                        cout << "----------------------------------------\n";
                        cout << "DESCRIPCION DE ARTICULOS:\n";
                        
                        if (cCamiseta > 0) cout << cCamiseta << " x Camiseta basica (Cod: C01) - Lps. " << (cCamiseta * 180.0) << "\n";
                        if (cJeans > 0) cout << cJeans << " x Jeans clasico (Cod: C02) - Lps. " << (cJeans * 450.0) << "\n";
                        if (cSudera > 0) cout << cSudera << " x Sudadera (Cod: C03) - Lps. " << (cSudera * 520.0) << "\n";
                        if (cCamisaForm > 0) cout << cCamisaForm << " x Camisa formal (Cod: O01) - Lps. " << (cCamisaForm * 650.0) << "\n";
                        if (cPantVestir > 0) cout << cPantVestir << " x Pantalon de vestir (Cod: O02) - Lps. " << (cPantVestir * 750.0) << "\n";
                        if (cBlazer > 0) cout << cBlazer << " x Blazer (Cod: O03) - Lps. " << (cBlazer * 1200.0) << "\n";
                        if (cTenis > 0) cout << cTenis << " x Tenis deportivos (Cod: Z01) - Lps. " << (cTenis * 980.0) << "\n";
                        if (cZapatosForm > 0) cout << cZapatosForm << " x Zapatos formales (Cod: Z02) - Lps. " << (cZapatosForm * 1100.0) << "\n";
                        if (cSandalias > 0) cout << cSandalias << " x Sandalias (Cod: Z03) - Lps. " << (cSandalias * 420.0) << "\n";
                        if (cCinturon > 0) cout << cCinturon << " x Cinturon (Cod: A01) - Lps. " << (cCinturon * 220.0) << "\n";
                        if (cGorra > 0) cout << cGorra << " x Gorra (Cod: A02) - Lps. " << (cGorra * 160.0) << "\n";
                        if (cBolso > 0) cout << cBolso << " x Bolso (Cod: A03) - Lps. " << (cBolso * 850.0) << "\n";

                        cout << "----------------------------------------\n";
                        cout << "Subtotal General: Lps. " << subtotalGeneral << "\n";
                        cout << "Descuento Tipo de Cliente: - Lps. " << descTipoClienteLps << "\n";
                        cout << "Descuento Genero: - Lps. " << descGeneroLps << "\n";
                        cout << "Descuento Tercera Edad (" << descTerceraStr << "): - Lps. " << descTerceraEdadLps << "\n";
                        cout << "Descuento Promociones (" << descPromoStr << "): - Lps. " << descPromoLps << "\n";
                        cout << "Total Descuentos: - Lps. " << totalDescuentos << "\n";
                        cout << "ISV (15%): Lps. " << isv << "\n";
                        cout << "========================================\n";
                        cout << "TOTAL A PAGAR (Lps): Lps. " << totalPagarLps << "\n";
                        cout << "TOTAL A PAGAR (USD): $ " << totalPagarUsd << "\n";
                        cout << "----------------------------------------\n";
                        cout << "PUNTOS ACUMULADOS EN ESTA COMPRA: " << puntosCliente << " pts\n";
                        cout << "========================================\n";
                        cout << "¡Gracias por su compra en PUMA MEGAPACA!\n";
                        cout << "========================================\n\n";

                        // Actualizar estadísticas globales del día
                        totalClientesAtendidos++;
                        totalVentasLpsDia += totalPagarLps;
                        totalDescuentosDia += totalDescuentos;
                        totalIsvDia += isv;

                        // Acumular unidades vendidas
                        vCamiseta += cCamiseta; vJeans += cJeans; vSudera += cSudera;
                        vCamisaForm += cCamisaForm; vPantVestir += cPantVestir; vBlazer += cBlazer;
                        vTenis += cTenis; vZapatosForm += cZapatosForm; vSandalias += cSandalias;
                        vCinturon += cCinturon; vGorra += cGorra; vBolso += cBolso;

                        // Acumular ganancias por categoría (sin ISV)
                        gananciaCasual += subCasual;
                        gananciaOficina += subOficina;
                        gananciaCalzado += subCalzado;
                        gananciaAccesorios += subAccesorios;

                        // Romper el ciclo del menú para pasar al siguiente cliente
                        opcionMenu = 6; 
                    }
                }
            }
        }

        cout << "¿Desea ingresar otro cliente? (S/N): ";
        cin >> continuarDia;
    }

    // MÓDULO DE ESTADÍSTICAS FINALES Y DE INVENTARIO RESTANTE (Al indicar N)
    cout << "\n\n========================================\n";
    cout << "     MODULO DE ESTADISTICAS DEL DIA     \n";
    cout << "========================================\n";
    cout << "Total de clientes atendidos: " << totalClientesAtendidos << "\n";
    
    cout << "\n-- Unidades vendidas por producto --\n";
    cout << "Camiseta basica: " << vCamiseta << "\n";
    cout << "Jeans clasico: " << vJeans << "\n";
    cout << "Sudadera: " << vSudera << "\n";
    cout << "Camisa formal: " << vCamisaForm << "\n";
    cout << "Pantalon de vestir: " << vPantVestir << "\n";
    cout << "Blazer: " << vBlazer << "\n";
    cout << "Tenis deportivos: " << vTenis << "\n";
    cout << "Zapatos formales: " << vZapatosForm << "\n";
    cout << "Sandalias: " << vSandalias << "\n";
    cout << "Cinturon: " << vCinturon << "\n";
    cout << "Gorra: " << vGorra << "\n";
    cout << "Bolso: " << vBolso << "\n";

    // REPORTE DE INVENTARIO RESTANTE EN BODEGA
    cout << "\n-- Inventario Restante en Bodega --\n";
    cout << "Camiseta basica (Stock inicial 40): " << (40 - vCamiseta) << " disponibles\n";
    cout << "Jeans clasico (Stock inicial 30): " << (30 - vJeans) << " disponibles\n";
    cout << "Sudadera (Stock inicial 20): " << (20 - vSudera) << " disponibles\n";
    cout << "Camisa formal (Stock inicial 18): " << (18 - vCamisaForm) << " disponibles\n";
    cout << "Pantalon de vestir (Stock inicial 15): " << (15 - vPantVestir) << " disponibles\n";
    cout << "Blazer (Stock inicial 10): " << (10 - vBlazer) << " disponibles\n";
    cout << "Tenis deportivos (Stock inicial 16): " << (16 - vTenis) << " disponibles\n";
    cout << "Zapatos formales (Stock inicial 12): " << (12 - vZapatosForm) << " disponibles\n";
    cout << "Sandalias (Stock inicial 25): " << (25 - vSandalias) << " disponibles\n";
    cout << "Cinturon (Stock inicial 35): " << (35 - vCinturon) << " disponibles\n";
    cout << "Gorra (Stock inicial 30): " << (30 - vGorra) << " disponibles\n";
    cout << "Bolso (Stock inicial 14): " << (14 - vBolso) << " disponibles\n";

    cout << "\n-- Ganancias por Categoria (Sin ISV) --\n";
    cout << "Ropa Casual: Lps. " << gananciaCasual << "\n";
    cout << "Ropa de Oficina: Lps. " << gananciaOficina << "\n";
    cout << "Calzado: Lps. " << gananciaCalzado << "\n";
    cout << "Accesorios: Lps. " << gananciaAccesorios << "\n";

    cout << "\nTotal de descuentos aplicados en el dia: Lps. " << totalDescuentosDia << "\n";
    cout << "Total ISV recaudado: Lps. " << totalIsvDia << "\n";
    cout << "Total general vendido en Lps.: Lps. " << totalVentasLpsDia << "\n";
    cout << "Total general vendido en USD: $ " << (totalVentasLpsDia / 26.42) << "\n";

    cout << "\n-- Metodos de Pago Utilizados --\n";
    cout << "Pagos en Efectivo: " << pagosEfectivo << "\n";
    cout << "Pagos por Transferencia: " << pagosTransferencia << "\n";
    if (pagosEfectivo > pagosTransferencia) {
        cout << "Metodo de pago mas utilizado: EFECTIVO\n";
    } else if (pagosTransferencia > pagosEfectivo) {
        cout << "Metodo de pago mas utilizado: TRANSFERENCIA\n";
    } else {
        cout << "Empate en metodos de pago.\n";
    }
    cout << "========================================\n";
    cout << "Programa finalizado con exito.\n";

    return 0;
}