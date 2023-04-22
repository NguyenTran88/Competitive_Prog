#include <iostream>
#include <map>
#include <queue>

int numTest;
long long n, k;
/*5
4 2
5 2
6 2
1000 1000
1000 1*/

int main()
{
    std::cin >> numTest;
    for (size_t i = 0; i < numTest; i++)
    {
        std::cin >> n >> k;
        std::cout << "Case #" << i + 1 << ": ";
        std::priority_queue<long> pq;
        std::map<long, long> cnt;
        pq.push(n);
        cnt[n] = 1;

        while (!pq.empty())
        {
            long curr_max = pq.top();
            pq.pop(); // lmao why didnt you pop
            long num_max = cnt[curr_max];
            long smol = (curr_max - 1) / 2; // 4 => 2 and 1 => smol = 1
            long big = curr_max - 1 - smol;

            // add to count of small and big, if they are null => they are not seen yet => not in pq
            if (cnt.find(smol) == cnt.end())
            {
                pq.push(smol);
            }
            cnt[smol] += num_max; // if curr_max = 6, and there are 5 6s. after this, we will have 5 3s and 5 2s
            if (cnt.find(big) == cnt.end())
            {
                pq.push(big);
            }
            cnt[big] += num_max;
            k -= num_max; // we put in 5 6s => now k reduces by 5 seats
            // _ x x _
            // _ x _ _
            // u adjusted k for the number (6) of this iteration
            // now check if this is the last iteration
            if (k < cnt[big]) // euqivalen to k + num_max <= cnt[curr_max]
            {

                // std::cout << big << ' ' << smol << std::endl;
                std::cout << std::max(big, smol) << ' ' << std::min(big, smol) << std::endl;
                break;
            }
            /*
            if (k <= cnt[curr_max])
            {
                std::cout << std::max(big, smol) << ' ' << std::min(big, smol) << std::endl;
                break;
            }
            else
            {
                k -= cnt[curr_max];
            }*/
        }
    }
    return 0;
}
