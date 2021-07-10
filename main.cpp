#include <iostream>

#include "0_example.h"

using namespace std;


int main()
{
    vector<int> nums{1, 2, 3, 4, -1, -7, 0};
    int target = 0;
    Example solu;
    auto ans = solu.run(nums, target);

    system("pause");
}