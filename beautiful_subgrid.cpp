#pragma GCC target("popcnt")
#include <iostream>
#include <bitset>
#include <string>
std::bitset<3000> S[3000]; // array of 3K bitset, each bitset sized 3K
int n;

int main()
{
    std::cin >> n; // n = 5 lines => grid has 5 rows
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; i++) // length row  = n
        {
            if (s[j] == '1')
            {
                S[i].set(j, 1); // S[i] is one bitset sized 3K. Now we set pos j of that to 1
            }
        }
    }

    // after this step, we have the square matrix S filled up with 1 and 0
    // now go over each row of the matrix, compare it with the subsequent row
    long long ans = 0LL;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; i++)
        {
            int cnt = (S[i] & S[j]).count(); // how many 1s are there after and.
            ans += cnt * (cnt - 1) / 2;      // each row compare with k-1 other rows, this double-count.
        }
    }
    std::cout << ans << std::endl;
    return 0;
}