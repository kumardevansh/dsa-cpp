#include <iostream>
using namespace std;

long long count_k_divisible(long long k, long long a, long long b) {
    // Calculate the number of multiples of k in the range [a, b]
    long long count = (b / k) - ((a - 1) / k);
    return count;
}

int main() {
    long long k, a, b;
    // Read the input
    cin >> k >> a >> b;

    // Calculate and print the result
    cout << count_k_divisible(k, a, b) << endl;
    return 0;
}
