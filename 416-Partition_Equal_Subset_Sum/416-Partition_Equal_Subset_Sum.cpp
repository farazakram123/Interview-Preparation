#include<bits/stdc++.h>
using namespace std;

// O(2^n)
class Solution1 {
private:
    void search(const vector<int> &nums, int n, int sum1, int sum2, bool &isThereAValidSubset){
        // base case
        if(n == 0){
            if(sum1 == sum2) isThereAValidSubset = true;
            return;
        }
        
        search(nums, n-1, sum1+nums[n-1], sum2, isThereAValidSubset);
        search(nums, n-1, sum1, sum2+nums[n-1], isThereAValidSubset);
    }
public:
    bool canPartition(vector<int>& nums) {
        bool isThereAValidSubset = false;
        int sum1 = 0, sum2 = 0;
        search(nums, nums.size(), sum1, sum2, isThereAValidSubset);
        return isThereAValidSubset;
    }
};


//Memoization
class Solution2 {
private:
    vector<vector<int>> dp;
    
    bool search(const vector<int> &nums, int n, int sum1, int sum2){
        // base case
        if(n == 0){
            return sum1 == sum2;
        }
        if(dp[n][sum1] != -1) return dp[n][sum1];
        
        bool ans = false;
        if(sum1-nums[n-1] >= 0){
            ans = search(nums, n-1, sum1-nums[n-1], sum2);
        }
        if(!ans && sum2-nums[n-1] >= 0){
            ans = search(nums, n-1, sum1, sum2-nums[n-1]);
        }
        return dp[n][sum1] = ans;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        
        dp.resize(nums.size()+1, vector<int> (sum/2+1, -1));
        return search(nums, nums.size(), sum/2, sum/2);
    }
};

//Memoization with removing the sum2
class Solution {
private:
    vector<vector<int>> dp;
    
    bool search(const vector<int> &nums, int n, int sum1){
        // base case
        if(n == 0){
            return sum1 == 0;
        }
        if(dp[n][sum1] != -1) return dp[n][sum1];
        
        bool ans = false;
        if(sum1-nums[n-1] >= 0){
            ans = search(nums, n-1, sum1-nums[n-1]);
        }
        if(!ans){
            ans = search(nums, n-1, sum1);
        }
        return dp[n][sum1] = ans;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        
        dp.resize(nums.size()+1, vector<int> (sum/2+1, -1));
        return search(nums, nums.size(), sum/2);
    }
};

int main(){
    vector<int> nums = {1,5,11,5};
    Solution s;
    cout<<s.canPartition(nums)<<endl;
    return 0;
}