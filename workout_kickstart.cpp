#include <iostream>
using namespace std;
using ll = long long;

int numTest;
int n, k; // n = number of elements, k = # of additional sess
int a[100005];
/*1
3 1
100 200 230*/
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
        while (lo <= hi)
        {
            int count = 0; // should this be here
            int mid = lo + (hi - lo) / 2;

            for (int i = 01; i < n; i++)
            {
                count += gap[i] / mid;
                if (gap[i] % mid == 0)
                {
                    count--;
                }
            }
            if (count <= k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else if (count > k)
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
            }
        }
        cout << ans << endl;
    }
    return 0;
}