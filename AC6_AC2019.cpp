#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
pair<int, int> a[55];
int color[55];

int numtest;
int candi, man;
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second > b.second);
}

int main()
{
    cin >> numtest;
    for (int i = 0; i < numtest; i++)
    {
        cin >> candi >> man;
        for (int i = 0; i < candi; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        sort(a, a + candi, sortbysec);
        // sort by deliciousness - second field => most delicous at top
        /*
                for (int i = 0; i < candi; i++)
                {
                    int n = a[i].second;
                    cout << n << endl;
                }
        */
        // at this point we have an array of sorted candi. => we run 1->k
        // keep a sum. at each k, we give out two candi. if color[a[i].first] > k => skip
        int ans = 0;
        int num_candi = 0;
        memset(color, 0, sizeof(color)); // make sure
        // we want to loop thru all candies possible and pick out 2k candies.
        // num_candi will make sure it hits 2k
        for (int i = 0; i < candi; i++) //
        {
            if (num_candi == 2 * man)
            {
                break;
            }
            if (color[a[i].first] >= man)
            {
                continue;
            }
            ans += a[i].second;
            color[a[i].first]++;
            num_candi++;
        }
        if (num_candi < 2 * man)
        {
            cout << "myans is " << -1 << endl;
            continue;
        }
        cout << "my ans is: " << ans << endl;
    }
}