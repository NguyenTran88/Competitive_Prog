#include <iostream>

int size, r;
int cnt[10005];
int freq[10005];
int mex = 0;

int main()
{
    std::cin >> size >> r;

    for (int i = 0; i < size; i++)
    {
        std::cin >> cnt[i];
    }

    for (int i = 0; i < size; i++)
    {
        int cur_rmd = cnt[i] % r;
        freq[cur_rmd]++;
        while (true)
        {
            int rmd = mex % r;

            // std::cout << "remainder of mex: " << rmd << " cur_rmd is " << cur_rmd << std::endl;
            // std::cout << "freq[cur_rmd]:  " << freq[cur_rmd] << " freq[rmd] is " << freq[rmd] << std::endl;

            if (freq[rmd] > 0)
            {
                freq[rmd]--;
                mex = mex + 1;
            }
            else
            {
                break;
            }
        }

        std::cout << mex << std::endl;
    }
    return 0;
}