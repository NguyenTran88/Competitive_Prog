#include <iostream>
// using namespace std;

int a[1005];
int num, max;
int res = 0;

int main()
{
    std::cin >> num >> max;

    for (size_t i = 0; i < num; i++)
    {
        std::cin >> a[i];
        /* code */
    }
    for (size_t i = 0; i < num; i++)
    {
        if (a[i] > max)
        {
            res = res + 2;
        }
        else
        {
            res++;
        }
        /* code */
    }
    std::cout << res;
    return 0;
}