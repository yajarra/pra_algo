#include <iostream>
#include <vector>
#include <algorithm>   // std::max

// Devuelve el beneficio máximo. En s deja 1/0 según si se elige cada elemento.
int mochila(const std::vector<int>& p, const std::vector<int>& b,
            int m, std::vector<int>& s)
{
    int n = p.size();

    // Tabla T de (n+1) x (m+1), toda a 0.
    // La fila 0 es "ningún elemento disponible": beneficio 0 siempre.
    // La columna 0 es "capacidad 0": beneficio 0 siempre.
    std::vector<std::vector<int>> T(n + 1, std::vector<int>(m + 1, 0));

    // ---- Rellenar la tabla ----
    for (int i = 1; i <= n; i++)             // elemento i de la tabla = p[i-1], b[i-1]
    {
        for (int j = 0; j <= m; j++)         // j = capacidad disponible
        {
            if (p[i - 1] > j)
                // No cabe: copio lo de arriba
                T[i][j] = T[i - 1][j];
            else
                // Cabe: elijo entre no cogerlo (arriba) o cogerlo
                T[i][j] = std::max(T[i - 1][j],
                                   T[i - 1][j - p[i - 1]] + b[i - 1]);
        }
    }

    // ---- Recuperar la solución ----
    s.assign(n, 0);
    int j = m;
    for (int i = n; i >= 1; i--)
    {
        if (T[i][j] != T[i - 1][j])          // distinto que arriba: lo cogí
        {
            s[i - 1] = 1;
            j -= p[i - 1];                   // me queda menos capacidad
        }
    }
    return T[n][m];
}

int main()
{
    // Ejemplo 1 del PDF
    std::vector<int> p = {9, 6, 5};
    std::vector<int> b = {38, 40, 24};
    std::vector<int> s;
    int beneficio = mochila(p, b, 15, s);
    std::cout << "Beneficio: " << beneficio << "\nElegidos: ";
    for (int x : s) std::cout << x << ' ';     // 1 1 0
    std::cout << "\n\n";

    // Ejemplo 2 del PDF
    std::vector<int> p2 = {1, 3, 2, 4};
    std::vector<int> b2 = {10, 20, 15, 20};
    beneficio = mochila(p2, b2, 5, s);
    std::cout << "Beneficio: " << beneficio << "\nElegidos: ";
    for (int x : s) std::cout << x << ' ';     // 0 1 1 0
    std::cout << "\n";
}
