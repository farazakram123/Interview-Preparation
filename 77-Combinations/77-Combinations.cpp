#include<bits/stdc++.h>
using namespace std;

class Solution1 {
private:
    void solve(int n, int k, vector<vector<int>>& ans, vector<int> v, int i){
        //base case
        if(k>n-i+1){
            return;
        }
        if(i>n){
            if(k==0){
                ans.push_back(v);
            }
            return;
        }
        if(k==0){
            ans.push_back(v);
            return;
        }
        //including
        v.push_back(i);
        solve(n, k-1, ans, v, i+1);
        v.pop_back();
        
        //excluding
        solve(n, k, ans , v, i+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int i=1;
        vector<int> v;
        solve(n, k, ans, v, i);
        return ans;
    }
};



// Solution 2
class Solution2 {
private:
    void solve(int n, int k, vector<vector<int>>& ans, vector<int>& v){
        //base case
        if(k==0){
            ans.push_back(v);
            return;
        }
        if(k==n){
            auto copy = v;
            for(int i=1; i<=n; i++){
                copy.push_back(i);
            }
            ans.push_back(copy);
            return;
        }
        //including
        v.push_back(n);
        solve(n-1, k-1, ans, v);
        v.pop_back();
        
        //excluding
        solve(n-1, k, ans , v);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(n, k, ans, v);
        return ans;
    }
};



// Solution 3
class Solution3 {
private:
    void solve(int n, int k, vector<vector<int>>& ans, vector<int>& v){
        //base case
        if(k==0){
            ans.push_back(v);
            return;
        }
        if(k==n){
            for(int i=1; i<=n; i++){
                v.push_back(i);
            }
            ans.push_back(v);
            for(int i=1; i<=n; i++){
                v.pop_back();
            }
            return;
        }
        //including
        v.push_back(n);
        solve(n-1, k-1, ans, v);
        v.pop_back();
        
        //excluding
        solve(n-1, k, ans , v);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(n, k, ans, v);
        return ans;
    }
};



// Solution 4
class Solution {
private:
    void solve(int n, int k, vector<vector<int>>& ans, vector<int>& v){
        //base case
        if(k==0){
            ans.push_back(v);
            return;
        }
        else if(n==0){
            // not feasible
        }
        else{
            //including
            v.push_back(n);
            solve(n-1, k-1, ans, v);
            v.pop_back();

            //excluding
            solve(n-1, k, ans , v);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(n, k, ans, v);
        return ans;
    }
};

int main(){
    Solution s;
    int n, k;
    cin>>n>>k;
    auto ans = s.combine(n, k);
    for(auto &i : ans){
        cout<<"[";
        for(auto j : i){
            cout<<j<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}