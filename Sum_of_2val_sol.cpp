#include <iostream>
#include <algorithm>
int n, x;
struct element
{
    int value;
    int position;
};
element a[200005];
bool compare(const element &a, const element &b)
{
    return (a.value < b.value);
}

int main()
{
    std::cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].value;
        a[i].position = i;
    }
    std::sort(a, a + n, compare); // a+n points 1 past

    for (int i = 0; i < n; i++)
    {
        // int lo = i + 1;
        // int hi = n - 1;
        // std::cout << i << std::endl;
        int lo = 0;
        int hi = n - 1;

        std::cout << i << std::endl;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (i == 2 && a[i].value == 4)
            {
                std::cout << a[mid].value << std::endl;
            }
            if (a[mid].value == x - a[i].value)
            {
                if (mid == i)
                {
                    std::cout << "dup at " << i + 1 << std::endl;
                    lo = mid + 1; // have to move lo or infitnie loop
                    break;        // have to break so that we don't continue printing
                }
                std::cout << a[mid].position + 1 << ' ' << a[i].position + 1;
                return 0;
            }
            else if (a[mid].value < x - a[i].value)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    std::cout << "IMPOSSIBLE";
    return 0;
}