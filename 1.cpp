#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int PROBLEM_A = 10e8 - 1;
const int PROBLEM_B = 10e18 - 1;
const int MODULO = 10e9 + 7;

vector<int> removeConsecutiveDuplicates(int n) {
    vector<int> result;
    for (int i = 0; i <= n; ++i) {
        int num = i;
        bool hasConsecutive = false;
        int prevDigit = -1;

        while (num > 0) {
            int currentDigit = num % 10;
            if (currentDigit == prevDigit) {
                hasConsecutive = true;
                break;
            }
            prevDigit = currentDigit;
            num /= 10;
        }

        if (!hasConsecutive) {
            result.push_back(i);
        }
    }
    return result;
}

int sumDigits(int num) {
    int rs = 0;
    while (num) {
        rs += (num % 10);
        num /= 10;
    }
    return rs;
}

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

#include <chrono>

int main() {
    auto start = chrono::high_resolution_clock::now();

    int test = PROBLEM_A;
    vector<int> notConsecutiveDuplicatesList = removeConsecutiveDuplicates(test);

    int n = notConsecutiveDuplicatesList.size();
    int rs = 0;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    // cout << "End get num list time: " << duration.count() * 1000 << " miliseconds" << endl;

    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        int sum = sumDigits(notConsecutiveDuplicatesList[i]);
        notConsecutiveDuplicatesList[i] = sum;
        maxVal = max(maxVal, sum);
    }
    vector<bool> isPrime = sieveOfEratosthenes(maxVal);

    for (auto num : notConsecutiveDuplicatesList) {
        if (isPrime[num]) {
            rs++;
            if (rs >= MODULO) {
                rs -= MODULO;
            }
        }
    }

    end = chrono::high_resolution_clock::now();
    duration = end - start;
    // cout << "End sum digits time: " << duration.count() * 1000 << " miliseconds" << endl;


    cout << "Result: " << rs << endl;

    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}