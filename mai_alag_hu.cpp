#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int minOperations(vector<int>& pencils, int k) {
    unordered_set<int> distinctHeights;
    
    for (int height : pencils) {
        if (height < k) {
            return -1;  // Impossible to cut to height k
        }
        if (height > k) {
            distinctHeights.insert(height - k);  // Store the differences
        }
    }
    
    return distinctHeights.size();
}

int main() {
    int T;
    cin >> T;  // Number of test cases
    
    while (T--) {
        int N, k;
        cin >> N >> k;  // Number of pencils and target height
        
        vector<int> pencils(N);
        for (int i = 0; i < N; ++i) {
            cin >> pencils[i];
        }
        
        int result = minOperations(pencils, k);
        cout << result << endl;
    }
    
    return 0;
}
