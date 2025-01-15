#include <iostream>
using namespace std;

int minimizeXor(int num1, int num2)
{
    // Step 1: Count the number of set bits in num2
    int count2 = __builtin_popcount(num2); // Built-in function to count set bits

    // Step 2: Create x by preserving bits from num1 and adjusting
    int x = 0;

    // First, set the bits in x to match the most significant set bits of num1
    for (int i = 31; i >= 0 && count2 > 0; --i)
    {
        if (num1 & (1 << i))
        {                  // Check if the i-th bit is set in num1
            x |= (1 << i); // Set the i-th bit in x
            --count2;      // Decrease the count of required set bits
        }
    }

    // If more set bits are needed, add them from the least significant bits
    for (int i = 0; i < 32 && count2 > 0; ++i)
    {
        if (!(x & (1 << i)))
        {                  // Check if the i-th bit is unset in x
            x |= (1 << i); // Set the i-th bit in x
            --count2;      // Decrease the count of required set bits
        }
    }

    return x;
}

int main()
{
    // Example test cases
    int num1 = 3, num2 = 5;
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Output: " << minimizeXor(num1, num2) << endl; // Expected output: 3

    num1 = 1, num2 = 12;
    cout << "\nInput: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Output: " << minimizeXor(num1, num2) << endl; // Expected output: 3

    return 0;
}
