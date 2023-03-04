#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minKpos = -1, maxKpos = -1, culprit = -1;
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] < minK || nums[i] > maxK){ // out of range
                culprit = i;
            }
            if(nums[i] == minK){
                minKpos = i;
            }
            if(nums[i] == maxK){
                maxKpos = i;
            }
            long long smaller = min(minKpos, maxKpos);
            long long temp = smaller - culprit;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;
    cout<<s.countSubarrays(nums, minK, maxK)<<endl;
    return 0;
}