#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
int dp[200][200];
 
int main() {
  string s1,s2,aux;  
  while(cin>>s1>>s2){
	int m = s1.size(), n = s2.size();
    memset(dp,0,sizeof(dp));
	
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
		  (s1[i-1] == s2[j-1])  ? dp[i][j] = 1 + dp[i-1][j-1] : dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    vector<char> ans; int nlcs = dp[m][n];
 
    while(m>0 && n>0){
      if(s1[m-1] == s2[n-1]){
        ans.pb(s1[m-1]);
        m--; n--;
      }
      else{
        if(dp[m][n] == dp[m-1][n]){
          ans.pb(s1[m-1]);
          m--;
        }
        else{
          ans.pb(s2[n-1]);
          n--;
        }
      }
    }
      
    while(m>0){ans.pb(s1[m-1]); m--;}
    while(n>0){ans.pb(s2[n-1]); n--;}
 
    int count = ans.size();
    for(int i=count; i>0; i--)
      cout<<ans[i-1];
    cout<<'\n'<<'\n';
  }
}  