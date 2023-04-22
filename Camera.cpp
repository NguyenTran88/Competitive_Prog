#include <iostream>
int a[10005];

int n, k, r; // k is kamera, r is range that have 2
int count = 0;
int ans = 0;
int main()
{
    std::cin >> n >> k >> r;
    for (int i = 1; i <= k; i++)
    {
        int house;
        std::cin >> house;
        a[house] = 1; // i am dumbass
    }

    for (int i = 1; i <= r; i++)
    {
        if (a[i] == 1)
        {
            count++; // count keeps track of how many camera there already are in r first houses
        }
    }
    if (count == 1)
    {
        if (a[r] != 1)
        {
            a[r] = 1;
        }
        else
        {
            a[r - 1] = 1;
        }
        count++;
        ans++; // remeber this
    }
    else if (count == 0)
    {
        a[r - 1] = 1;
        a[r] = 1;
        ans += 2; // remeber this
        count += 2;
    }
    // done with k first spots, here we find first le and right. At this point, ans = 1 or 2 or 0

    int le, ri;
    for (size_t i = 1; i <= r; i++)
    {
        if (a[i] == 1)
        {
            le = i; // left is the first 1 we have, right is the last index of the window
            ri = i + r - 1;
            break;
        }
    }
    std::cout << "l = " << le << " r  = " << ri << " ans = " << ans << "also this should be 1 " << a[r] << std::endl;
    // _ x _ x x _ x _ _ x _ _ x _ _
    // int start = ri;
    // count still keeps track

    // int temp = count;                // temp and count now keeps the number of 1, now if we change the number of 1 in there afterwards, we r doing too much !
    std::cout << "count is = " << count << std::endl;
    for (int i = ri + 1; i < n; i++) // notice ri+1
    {
        if (a[le] == 1)
        {
            // print lef
            count--;
        }
        if (a[i] == 1)
        {
            count++;
        }
        if (count < 2) // if this happen, a[i] must be 0 and le must be 1
        {
            a[i] = 1;
            ans++;
            count = 2;
        }
        // how would current change in a[i] being 1 or 0 affect count
        // if a[i] ==1 => count++, if ==0. no change.
        le++;
    }

    /*
    int numbCamera = 2;
    int g = 1;
    for (int i = r + 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            numbCamera++;
        }
        if (a[g] == 1)
        {
            numbCamera--;
        }
        g++;
        if (numbCamera < 2)
        {
            a[i] = 1;
            ans++;
            numbCamera = 2;
        }
    }*/
    std::cout << ans << std::endl;
    return 0;
}