#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> notas = {85, 92, 78, 64, 90, 88, 73, 95};

    std::cout << "--- NOTAS ORIGINALES ---\n";
    for (int n : notas) std::cout << n << " ";
    std::cout << "\n\n";

    // Ordenar de mayor a menor usando std::sort
    std::sort(notas.begin(), notas.end(), std::greater<int>());

    // Calcular promedio usando std::accumulate
    double suma = std::accumulate(notas.begin(), notas.end(), 0.0);
    double promedio = suma / notas.size();

    // Encontrar nota mas alta y mas baja usando std::minmax_element
    auto [min_it, max_it] = std::minmax_element(notas.begin(), notas.end());

    std::cout << "Notas ordenadas (mayor a menor): ";
    for (int n : notas) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "Nota mas alta: " << *max_it << "\n";
    std::cout << "Nota mas baja: " << *min_it << "\n";
    std::cout << "Promedio general: " << promedio << "\n";

    return 0;
}