#include <iostream>
#include <map>
#include <fstream>
int numTest;
int a[100005];
std::map<int, int> mymap;
int n;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::cin >> numTest;
    int n;
    for (size_t i = 0; i < numTest; i++)
    {
        std::cin >> n;
        mymap.clear(); // multi-cases => clear
        for (size_t i = 0; i < n; i++)
        {
            std::cin >> a[i];
            mymap[a[i]]++; // idea: key is rating, value is how many people w that rating
            // if later we check and value > 1 => ok. if not => complicated
        }
        for (size_t i = 0; i < n; i++)
        {
            int lim = a[i] * 2;
            std::map<int, int>::iterator it = mymap.upper_bound(lim); // it points at smallest value >=lim
            it--;                                                     // points at largest value <= lim
            if (it->second == 1 && it->first == a[i])                 // the largest value possible is itself => we try to take the 2nd smallest value then
            {
                if (it == mymap.begin())
                { // if it is the smallest one already => can't find 2nd smallest
                    std::cout << "-1" << std::endl;
                }
                else
                {
                    it--; // find the 2nd smallest value samller then lim
                    std::cout << it->first << std::endl;
                }
            }
            else
            {
                std::cout << it->first << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}