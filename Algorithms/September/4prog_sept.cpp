#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int A[n];
    int B[m];
    int r = 0;
    int k = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i];              
    for (int i = 0; i < m; i++)
        cin >> B[i];

    int i = 0, j = 0;
    while (i != n && j != m)
    {
        if (A[i] < B[j])
            i++;
        else
          if (A[i] > B[j])
            j++;
        else
        {
            i++;
            j++;
            r++;
        }
    }
    k = n + m - (r * 2);
    cout << k << endl;
    return 0;
}
