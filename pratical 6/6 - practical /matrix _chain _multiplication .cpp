
#include <iostream>
#include <climits>
using namespace std;

void matrixChainMultiplication(int p[], int n)
{
    int m[100][100];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    cout << "Minimum number of multiplications: "
         << m[1][n - 1] << endl;
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    matrixChainMultiplication(p, n + 1);

    return 0;
}
