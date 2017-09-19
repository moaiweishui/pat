#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double num_buf;
    double res = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> num_buf;
        res += num_buf * (n - i) * (i + 1);
    }

    printf("%.2lf\n", res);

    return 0;
}
