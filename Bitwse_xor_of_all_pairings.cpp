#include <bits/stdc++.h>
using namespace std;

int bitwiseXor(vector<int> &nums1, vector<int> &nums2)
{
    int xor1 = 0, xor2 = 0;
    for (int num : nums1)
    {
        xor1 ^= num;
    }
    for (int num : nums2)
    {
        xor2 ^= num;
    }
    int result = 0;
    if (nums1.size() % 2 != 0)
    {
        result ^= xor2;
    }
    if (nums2.size() % 2 != 0)
    {
        result ^= xor1;
    }
    return result;
}

int main()
{
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    int result = bitwiseXor(nums1, nums2);
    cout << "result is:" << result << endl;
}