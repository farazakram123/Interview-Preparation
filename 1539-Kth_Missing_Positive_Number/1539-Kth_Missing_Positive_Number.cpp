#include<bits/stdc++.h>
using namespace std;

// O(n) time + O(n) space
class Solution1 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());
        int num = 1;
        for(num = 1; num<=1000; num++){
            if(k==1 && s.count(num)==0) return num;
            if(s.count(num)==0){
                k--;
            }
        }
        while(k>1){
            num++;
            k--;
        }
        return num;
    }
};


// O(logn) time + O(1) space
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int noOfMiss = arr[mid] - (mid+1);
            
            if(noOfMiss < k) low = mid + 1;
            else high = mid-1;
        }
        return low + k;
    }
};


int main(){
    Solution s;
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout<<s.findKthPositive(arr, k)<<endl;
    return 0;
}