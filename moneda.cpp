#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

int monedas(const std::vector<int>& m, int d, std::vector<int>& s)
{
    int n = m.size();

    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, INF));

    for (int i = 0; i < n; i++)
        T[i][0] = 0;

    for (int j = 1; j <= d; j++)
        if (j >= m[0] && T[0][j - m[0]] != INF)
            T[0][j] = 1 + T[0][j - m[0]];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (j < m[i] || T[i][j - m[i]] == INF)
                T[i][j] = T[i - 1][j];
            else if (T[i - 1][j] != INF)
                T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - m[i]]);
            else
                T[i][j] = 1 + T[i][j - m[i]];
        }
    }

    s.assign(n, 0);
    if (T[n - 1][d] == INF)
        return -1;                       

    int i = n - 1, j = d;
    while (j > 0)
    {
        if (i == 0 || T[i][j] != T[i - 1][j])
        {
            s[i]++;     
            j -= m[i];              
        }
        else
            i--;                        
    }
    return T[n - 1][d];
}

int main()
{
    std::vector<int> m = {1, 4, 6};
    std::vector<int> s;
    int d = 8;

    int total = monedas(m, d, s);
    std::cout << "Minimo de monedas: " << total << "\n";
    for (size_t i = 0; i < m.size(); i++)
        std::cout << s[i] << " moneda(s) de " << m[i] << "\n";

}
