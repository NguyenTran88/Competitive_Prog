#include <iostream>
#include <set>
std::set<long long> myset;
long long p[200005];
int n;

int main()
{
    long long ans = -10000000000;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        // cant' myset.insert(p[i]) here since if we call uppr_bound later
        // and we want the smallest of the bigg we have seen TILL NOW not the whole arr
        // => if 8 6 => upr_bound(6) = 8 tho 8 is previous to 6
        // 20 7 8 2 5   5-7=-2  => to get loss, we take the bigger-smaller => it - p[i]
    }
    std::set<long long>::iterator it;
    long long curr;
    for (int i = 1; i < n; i++)
    {
        it = myset.upper_bound(p[i]); // smallest of bigger we have seen

        curr = p[i] - *it; // this is bound to be negative

        ans = std::max(curr, ans);

        myset.insert(p[i]);
    }
    std::cout << ans;
    return 0;
}