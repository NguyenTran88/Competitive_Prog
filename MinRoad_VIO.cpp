#include <iostream>
#include <algorithm>
int n, tung, truc;
int a[200005];
/*7 2 2
20 2
30 1*/
int main()
{
    std::cin >> n >> tung >> truc;
    int spot, type, maxspot;
    maxspot = 0;
    for (int i = 0; i <= n; i++) // n = so cay
    {
        std::cin >> spot >> type;
        if (type == 1)
        {
            a[spot] = 1; // tung
        }
        else
        {
            a[spot] = 2; // truc
        }
        maxspot = std::max(maxspot, spot);
    }
    // index = khoang cach. VD: a[10] = 1 => cay tung cach dau duong 10m
    //
    // std::cout << "rando" << std::endl;
    int l = 1, r = 1;
    int num1 = 0, num2 = 0; // count so tung, so truc
    while (num1 < tung || num2 < truc)
    {
        if (a[r] == 1)
        {
            num1++;
        }
        else if (a[r] == 2)
        {
            num2++;
        }
        r++;
    }
    r--;                         // get first window
    std::cout << r << std::endl; // 60 ?

    // num1 = tung, num2 = truc; //reset
    while (r < maxspot)
    {
        if (a[l] == 1)
        {
            num1--;
        }
        else if (a[l] == 2)
        {
            num2--;
        }
        l++;
    }
}