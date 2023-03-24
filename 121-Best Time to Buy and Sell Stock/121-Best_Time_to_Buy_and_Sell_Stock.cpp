#include<bits/stdc++.h>
using namespace std;

class Solution1 {
private:
    int f1(int i, const vector<int>& prices, vector<int>& f2tbl, int n){
        if(i == n-1) return 0;
        return max(f1(i+1, prices, f2tbl, n), f2(i+1, prices, f2tbl, n)-prices[i]);
    }
    int f2(int i, const vector<int>& prices, vector<int>& f2tbl, int n){
        if(i == n-1) return prices[n-1];
        if(f2tbl[i] != INT_MIN) return f2tbl[i];
        return f2tbl[i] = max(prices[i], f2(i+1, prices, f2tbl, n));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f2tbl(n, INT_MIN);
        return f1(0, prices, f2tbl, n);
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f2tbl(n, INT_MIN);
        int f1 = 0; // f1(n-1) = 0
        f2tbl[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            f1 = max(f1, f2tbl[i+1]-prices[i]);
            f2tbl[i] = max(prices[i], f2tbl[i+1]);
        }
        return f1;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f2 = prices.back(); // f2(n-1)
        int f1 = 0; // f1(n-1) = 0
        
        for(int i=n-2; i>=0; i--){
            f1 = max(f1, f2-prices[i]);
            f2= max(prices[i], f2);
        }
        return f1;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}