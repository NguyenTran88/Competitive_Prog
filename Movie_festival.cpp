#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
std::vector<std::pair<int, int>> a;
std::multiset<int> S;
int n, k;
/*5 2
1 5
8 10
3 6
2 5
6 9*/

bool comp(std::pair<int, int> pair1, std::pair<int, int> pair2)
{
    return (pair1.second < pair2.second);
}

int main()
{
    std::cin >> n >> k;            // 5 2
    for (size_t i = 0; i < n; i++) // add all the start-end time pairs to vector
    {
        std::pair<int, int> movie;
        std::cin >> movie.first >> movie.second; // pair has field 1st,2nd
        a.push_back(movie);
    }
    std::sort(a.begin(), a.end(), comp); // check back how to use sort w vector
    // done, now work with set, we want sth smaller than but biggest
    //  use lowerbound for >=. then minus iterator by 1.
    //  we want value in set that is smaller than the beginning time of next movei => movie.first
    for (int i = 1; i <= k; i++)
    {
        S.insert(0);
    }
    int ans = 0;
    for (size_t i = 0; i < n; i++) // traverse thru all the movies
    {
        std::pair<int, int> curr;
        curr = a[i];
        std::multiset<int>::iterator it = S.upper_bound(curr.first);
        if (it != S.begin())
        {
            ans++;
            it--;
            // do sth that deletes it and replace that with end time of new movie
            S.erase(it);
            S.insert(curr.second);
        }
    }
    std::cout << ans;
    return 0;
}