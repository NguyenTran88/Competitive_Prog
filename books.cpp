#include <iostream>
int n, t;
/* Ans: 3
4 5
3 1 2 1*/
int main()
{
    std::cin >> n >> t;
    int l = 0, r = 0, ans = 0;
    int arr[n]; // array contains all book
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int sum = 0;
    while (r < n)
    { // r could be = n-1 => r is at last index, after that we stop
        if (arr[r] + sum > t)
        {
            std::cout << "r is now" << r << std::endl;
            std::cout << "sum is now" << sum << std::endl;
            sum -= arr[l];
            l++;
        }
        sum += arr[r];
        ans = std::max(ans, r - l + 1);
        r++;
    }
    // 2 3 4 35 3 6 . limit : 10
    std::cout << ans << std::endl;
}