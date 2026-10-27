#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <utility>   


template<typename T>
int Partition(std::vector<T>& V, int ini, int fin)
{
    T x = V[fin];                 
    int i = ini;                  
    for (int j = ini; j <= fin - 1; j++)
    {
        if (V[j] <= x)
        {
            std::swap(V[i], V[j]);
            i++;
        }
    }
    std::swap(V[i], V[fin]);      
    return i;
}

template<typename T>
void QuickSort(std::vector<T>& V, int ini, int fin)
{
    if (ini < fin)
    {
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}


template<typename T>
int BusquedaBinaria(const T& X, const std::vector<T>& V, int ini, int fin)
{
    if (ini > fin)
        return -1;                

    int medio = (ini + fin) / 2;
    if (V[medio] == X)
        return medio;
    else if (V[medio] > X)
        return BusquedaBinaria(X, V, ini, medio - 1);
    else
        return BusquedaBinaria(X, V, medio + 1, fin);
}

// ---------- Prueba ----------

int main()
{
    // 1) El ejemplo de la diapositiva
    std::vector<int> v = {9, -4, 3, 6, 1, 5};
    QuickSort(v, 0, (int)v.size() - 1);
    for (int x : v) std::cout << x << " ";      // -4 1 3 5 6 9
    std::cout << "\n";

    std::cout << "Posicion del 6: "
              << BusquedaBinaria(6, v, 0, (int)v.size() - 1) << "\n"
    std::vector<int> grande(100000);
    for (int& x : grande) x = std::rand() % 1000000;

    auto t0 = std::chrono::high_resolution_clock::now();#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <utility>   // std::swap

// ---------- QuickSort ----------

// Coloca el pivote (V[fin]) en su posición final y devuelve esa posición.
// A la izquierda quedan los elementos <= pivote, a la derecha los mayores.
template<typename T>
int Partition(std::vector<T>& V, int ini, int fin)
{
    T x = V[fin];                 // pivote = último elemento
    int i = ini;                  // frontera de la zona de "menores o iguales"
    for (int j = ini; j <= fin - 1; j++)
    {
        if (V[j] <= x)
        {
            std::swap(V[i], V[j]);
            i++;
        }
    }
    std::swap(V[i], V[fin]);      // el pivote va a su sitio
    return i;
}

template<typename T>
void QuickSort(std::vector<T>& V, int ini, int fin)
{
    if (ini < fin)
    {
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}

// ---------- Búsqueda binaria (el vector debe estar ordenado) ----------

// Devuelve la posición de X, o -1 si no está.
template<typename T>
int BusquedaBinaria(const T& X, const std::vector<T>& V, int ini, int fin)
{
    if (ini > fin)
        return -1;                

    int medio = (ini + fin) / 2;
    if (V[medio] == X)
        return medio;
    else if (V[medio] > X)
        return BusquedaBinaria(X, V, ini, medio - 1);
    else
        return BusquedaBinaria(X, V, medio + 1, fin);
}



int main()
{

    std::vector<int> v = {9, -4, 3, 6, 1, 5};
    QuickSort(v, 0, (int)v.size() - 1);
    for (int x : v) std::cout << x << " ";      
    std::cout << "\n";

    std::cout << "Posicion del 6: "
              << BusquedaBinaria(6, v, 0, (int)v.size() - 1) << "\n";   
    
    std::vector<int> grande(100000);
    for (int& x : grande) x = std::rand() % 1000000;

    auto t0 = std::chrono::high_resolution_clock::now();
    QuickSort(grande, 0, (int)grande.size() - 1);
    auto t1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> ms = t1 - t0;
    std::cout << "QuickSort de " << grande.size()
              << " elementos: " << ms.count() << " ms\n";
}
    QuickSort(grande, 0, (int)grande.size() - 1);
    auto t1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> ms = t1 - t0;
    std::cout << "QuickSort de " << grande.size()
              << " elementos: " << ms.count() << " ms\n";
}
