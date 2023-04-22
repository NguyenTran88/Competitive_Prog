#include <iostream>
#include <algorithm>
#include <vector>
/*Input:
4 8         array sized 4 with sum 8
2 7 5 1
=> 7+1 = 8 => index 2 and 4
*/
int arsize, targ;
int arr[10005];
int main()
{
    std::cin >> arsize >> targ;
    for (int i = 0; i < arsize; i++)
    {
        std::cin >> arr[i];
    }
    // Done w reading in data, we know we want binary search => need to sort:
    //  1 2 5 7
    //  how to get 8 ? also, after sorting, how tf do i get index 2 and 4 outta values 1 and 7 ?
    // std::<std::pair<int, int>>a;
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < arsize; i++)
    {
        // a.push_back(std::make_pair(a[i], i)); // create pairs of value - index
        std::pair<int, int> pair = std::make_pair(a[i], i);
        // a.push_back(std::make_pair(a[i], i));
        a.push_back(pair);
    }
    std::sort(a.begin(), a.end()); // sort based on a[i]

    int l = 0, r = arsize - 1;
    for (int i = 0; i < arsize; i++)
    {
        int look = targ - a[i].first; // we need to search for this value among the array
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid].first == look && a[mid].second != i)
            {
                std::cout << a[mid].second + 1 << i + 1 << std::endl;
            }
            else if (a[mid].first < look)
            {
                l = i + 1;
            }
            else
            {
                r = i - 1;
            }
        }
    }
}