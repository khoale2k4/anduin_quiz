#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <chrono>
#include <tuple>

using namespace std;

const int PROBLEM_A = 1e8 - 1;
const long long PROBLEM_B = 1e18 - 1;
const int MODULO = 1e9 + 7;

vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

int generateNumbersBFS(long long n, vector<bool>& isPrime) {
    unordered_set<long long> visited; 
    queue<tuple<long long, int, int>> q;  
    int count = 0;

    for (int digit = 1; digit <= 9; digit++) {
        q.push(make_tuple(digit, digit, digit));
        visited.insert(digit);
    }

    while (!q.empty()) {
        auto [currentNumber, prevDigit, currentSum] = q.front();
        q.pop();

        if (isPrime[currentSum]) {
            count = (count + 1) % MODULO;
        }

        for (int digit = 0; digit <= 9; digit++) {
            if (digit != prevDigit) {
                long long newNumber = currentNumber * 10LL + digit;
                if (newNumber <= n && visited.find(newNumber) == visited.end()) {
                    q.push(make_tuple(newNumber, digit, currentSum + digit));
                    visited.insert(newNumber);
                }
            }
        }
    }

    return count;
}

void process(long long test) {
    auto start = chrono::high_resolution_clock::now();

    vector<bool> isPrime = sieveOfEratosthenes(81);
    int result = generateNumbersBFS(test, isPrime);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Result: " << result << endl;
    cout << "Execution time: " << duration.count() << " seconds" << endl;
}

int main() {
    cout << "1a: " << PROBLEM_A << endl;
    process(PROBLEM_A);
    
    cout << "1b: " << PROBLEM_B << endl;
    process(PROBLEM_B);

    return 0;
}
