#include <vector>
#include <algorithm>

using namespace std;

double minAverageWaitingTime(vector<vector<int>>& customers) {
    sort(customers.begin(), customers.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    double totalWaitTime = 0;
    long long currentTime = 0;

    for (const auto& customer : customers) {
        int arrivalTime = customer[0];
        int processingTime = customer[1];

        if (currentTime < arrivalTime) {
            currentTime = arrivalTime;
        }

        long long completionTime = currentTime + processingTime;
        totalWaitTime += completionTime - arrivalTime;
        currentTime = completionTime;
    }

    return totalWaitTime / customers.size();
}