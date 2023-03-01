#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen = 0, len = 0, n = nums.size(), i=0;
        while(i < n){
            while(i<n && nums[i] == 0) i++;
            while(i<n && nums[i] == 1){
                len++, i++;
            }
            maxlen = max(maxlen, len);
            len = 0;
        }
        return maxlen;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}