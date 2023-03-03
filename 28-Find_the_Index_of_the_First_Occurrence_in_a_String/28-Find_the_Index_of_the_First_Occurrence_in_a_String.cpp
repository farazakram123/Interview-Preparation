#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(string& s, string& t, int n, int m, int ind){
        int i=0, j=ind;
        while(i<m){
            if(j >= n){
                return false;
            }
            else if(s[j] != t[i]) return false;
            i++, j++;
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m>n) return -1;
        for(int i=0; i<n; i++){
            if(check(haystack, needle, n, m, i)) return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    string s1, s2;
    cin>>s1>>s2;
    cout<<s.strStr(s1, s2)<<endl;
    return 0;
}