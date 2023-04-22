/*#include <iostream>
#include <algorithm>
int numTest;
int n, C;
int x[100005];

int main()
{
    std::cin >> numTest;
    for (int testCase = 1; testCase <= numTest; testCase++)
    {
        std::cin >> n >> C;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> x[i];
        }
        std::sort(x + 1, x + n + 1);
        int lo = 1;
        int hi = 1000000000;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int lastPosition = x[1];

            int numbCows = 1;
            for (int i = 2; i <= n; i++)
            {
                if (x[i] - lastPosition >= mid)
                {
                    numbCows++;
                    lastPosition = x[i];
                }
            }

            int numbCows = 0;
            for (int i = 01; i < n; i++)
            {
                sum += gap[i];
                if (sum > mid) //or >=
                {
                    count++;
                    sum = gap[i];
                }
            }

            if (numbCows >= C)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}*/

#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int numTest;
int n, k; // n = number of elements, k = # of additional sess
int a[100005];

void dbg(int x)
{
    cout << x << endl;
}

int main()
{
    cin >> numTest;
    for (int i = 0; i < numTest; i++)
    {
        cin >> n >> k;

        int max_diff = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        std::sort(a, a + n); // n = 2
        cout << "Case #" << i + 1 << ": ";
        int lo = 1;
        int hi = 1000000007;
        int ans = -1;
        int gap[n];
        for (int i = 1; i < n; i++)
        {
            gap[i] = a[i] - a[i - 1];
        }
        // gap:  200 30
        // gap[i] = a[i+1] - a[i], but we read into gap[1] to n
        while (lo <= hi)
        {
            int sum = 0;
            int mid = lo + (hi - lo) / 2;
            int count = 01; // we start with 1 since always a cow at x[0]

            for (int i = 01; i < n; i++)
            {
                if (sum >= mid)
                {
                    count++;
                    sum = 0;
                    continue;
                }
                sum += gap[i];
                if (sum < mid)
                {
                    continue; // do we need update
                }
                else
                {
                    count++;
                    cout << count << " gap[i] = " << gap[i] << "at index i =" << i << endl;
                    cout << "sum " << sum << endl;
                    sum = gap[i];
                }
            }

            if (count < k)
            {

                hi = mid - 1;
            }
            else
            {
                ans = mid;
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}