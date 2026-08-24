#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Step 1: Combine position and speed into a single vector of pairs
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        // Step 2: Sort by position in descending order
        // Uses a lambda function to sort from largest position to smallest
        sort(cars.rbegin(), cars.rend());

        // Step 3: Count fleets using the single max_time bottleneck tracker
        int fleets = 0;
        double max_time = 0.0;

        for (const auto& car : cars) {
            if (car.second > max_time) {
                fleets++;
                max_time = car.second; // New slowest fleet leader
            }
        }

        return fleets;
    }
};

