#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& time, long long mid, int totalTrips){
        long long trips = 0;
        for(auto &t : time){
            trips += mid/t;
        }
        return trips >= totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minimum = (long long)*min_element(time.begin(), time.end());
        long long s = minimum;
        long long e = totalTrips;
        e *= minimum;
        long long ans = -1;
        
        while(s <= e){
            long long mid = s + (e-s)/2;
            if(isPossible(time, mid, totalTrips)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> time = {1,2,3};
    int totalTrips = 5;
    cout<<s.minimumTime(time, totalTrips)<<endl;
    return 0;
}