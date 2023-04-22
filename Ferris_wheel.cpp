#include <iostream>
#include <algorithm>
int n, x;
int a[200005];

int main()
{
    std::cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    int l, r;
    l = 1, r = n;
    int count = 0;
    while (l < r)
    { // check
        if (a[l] + a[r] > x)
        {
            r--;
            count++;
        }
        else
        {
            r--;
            l++;
            count++;
        }
    }
    if (l == r)
    {
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}