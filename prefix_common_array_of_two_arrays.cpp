#include <bits/stdc++.h>
using namespace std;

vector<int> prefixCommon(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int commonCount = 0;
    unordered_set<int> seenInA;     // numbers seen so far in A
    unordered_set<int> seenInB;     // number seen so far in B
    vector<int> prefixcommon(n, 0); // result array

    for (int i = 0; i < n; i++)
    {                            // add cuurent elemnets of A and B arrays to their respectiove sets
        if (seenInA.count(B[i])) // if number at B is already seeb in set A , increase common count
        {
            commonCount++;
        }
        seenInB.insert(B[i]);

        if (seenInB.count(A[i]))
        {
            commonCount++;
        }
        seenInA.insert(A[i]);
        prefixcommon[i] = commonCount; // update result array
    }
    return prefixcommon;
}

int main()
{
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    vector<int> result = prefixCommon(A, B);
    for (int val : result)
    {
        cout << val << " ";
    }
}