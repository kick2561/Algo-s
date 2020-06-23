#include <bits/stdc++.h>
using namespace std;

int findancestors(vector<int> &temp,int ele){
    int cnt = 0;
    for(auto x : temp){
        if(x>ele) cnt++;
    }
    return cnt;
}

void dfs(int s,vector<int> &temp,vector<vector<int>> &g,vector<int> &A,vector<int> &vis,vector<int> &ans){
    vis[s] = 1;
    for(auto x : g[s]){
        if(vis[x]==0){
            int count = findancestors(temp,A[x-1]);
            ans[x-1] = count;
            temp.push_back(A[x-1]);
            dfs(x,temp,g,A,vis,ans);
            temp.pop_back();
        }
    }
}

vector<int> solve(vector<int> &A,vector<int> &B, vector<int> &C){
    int n = B.size();
    int sz = A.size();
    vector<vector<int>>g(sz+1);
    vector<int> ans(sz,0);
    vector<int> vis(sz+1,0);
    vector<int> temp;
    for(int i = 0;i<n;i++){
        g[B[i]].push_back(C[i]);
    }
    temp.push_back(A[0]);
    dfs(1,temp,g,A,vis,ans);
    return ans;
}

int main() {
    vector<int> A,B,C;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        A.push_back(x);
    }
    int edges;
    cin>>edges;
    for(int i = 0; i < edges; i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    for(int i = 0; i < edges; i++){
        int x;
        cin>>x;
        C.push_back(x);
    }
    vector<int> ans = solve(A,B,C);
    for(auto x : ans){
        cout<<x<<"  ";
    }
    return 0;
}
