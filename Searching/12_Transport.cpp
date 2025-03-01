// Transport:
/*
N passengers arrive at your transport service. The ith passenger arrives at time ti. You have M buses at your service and each bus can hold C
passengers. A bus can depart with any number of passengers from 0 to C in it. It is guaranteed that you have sufficient buses to transport all the passengers to their destination i.e. M∗C≥N
A bus can leave when the last passenger onboard the bus arrives. The other passengers have to wait for the last passenger to arrive to leave. The passengers don't like waiting. So your task is to calculate the smallest possible value of the maximum waiting time of the passengers if the bus departures are scheduled optimally.

*/

// Minimax pattern of BS
// TC: O(log (maxvalue of array - minvalue of array)) + O(predicate()) =  O(log(1e9)) + O(N)


#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int predicate(ll maxWaitTime, vector<ll>& arrivalTimes, ll buses, ll capacity) {
    ll busesUsed = 1, currentCap = 1;
    ll lastPassengerTime = arrivalTimes[0];
    
    for (int i = 1; i < arrivalTimes.size(); i++) {
        currentCap++;
        if (arrivalTimes[i] - lastPassengerTime > maxWaitTime  || currentCap > capacity) {
            busesUsed++;
            lastPassengerTime = arrivalTimes[i];
            currentCap = 1;
        }
    }
    // if asked smallest value of maximun
    // we use the logic of first occurance
    if(busesUsed > buses) return 0; // we need to increase the waiting time to decrease the number of busesUsed, hence move to the right
    else return 1;
}

int main() {
    eff;
    ll N, M, C;
    cin >> N >> M >> C;

    vector<ll> arrivalTimes(N);
    for (int i = 0; i < N; ++i) {
        cin >> arrivalTimes[i];
    }

    sort(arrivalTimes.begin(), arrivalTimes.end());

    ll L = 0, R = arrivalTimes[N - 1] - arrivalTimes[0]; // Maximum possible waiting time
    while (L + 1 < R) {
        ll mid = L + (R - L)/2;

        if (predicate(mid, arrivalTimes, M, C) == 0)  L = mid;
        else R = mid;
    }

    cout << R << endl;

    return 0;
}
