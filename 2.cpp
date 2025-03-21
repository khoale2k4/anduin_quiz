#include <iostream>
#include <vector>

using namespace std;

const int UPPER_BOUND = 2097152;

vector<int> getWeights(int mass, int base) {
    if (base == 1) {
        return vector<int>(1, -1);
    }
    int pro = 1;
    vector<int> nums;
    while(pro < UPPER_BOUND) {
        nums.push_back(pro);
        pro *= base;
    }

    int r = nums.size() - 1;
    vector<int> rs;
    while(mass > 0 && r >= 0) {
        if(nums[r] <= mass) {
            mass -= nums[r];
            rs.push_back(nums[r]);
        } else {
            r--;
        }
    }

    if(mass == 0) {
        return rs;
    } else {
        return vector<int>(1, -1);
    }
}

int process(int mass, int base) {
    // cout << "Mass: " << mass << " Base: " << base << endl;
    vector<int> weights = getWeights(mass, base);
    int n = weights.size();
    return n;
    // cout << "Number of weights: " << n << endl << "Weights: ";
    // for(int i = 0; i < n; i++) {
    //     cout << weights[i] << " ";
    // }
}


int main() {
    // int maxVal = 1;
    // for(int mass = 1; mass < UPPER_BOUND; mass++) {
    //     maxVal = max(maxVal, process(mass, 3));
    // }
    // cout << maxVal;

    cout << process(1594323, 3);

    return 0;
}