#include<bits/stdc++.h>
using namespace std;
int dp[512][512]={0};

void I_love( set<char> on,string orchestra_for,string players )
{
 int ur_moms_butt=orchestra_for.length();
 int and_her_hole=players.length();
  for(int i=1;i<=ur_moms_butt;i++)
  {
    for(int u=1;u<=and_her_hole;u++)
    {
      
      if(orchestra_for[i-1]==players[u-1])
      {
        dp[i][u]=dp[i-1][u-1]+1;
      }
      else
      {
        dp[i][u]=max(dp[i-1][u],dp[i][u-1]);
      }
    }
  }
}
//幹....寫不完啦...QAQ
int main(){
set<char> fuck;
string s1,s2;
while(cin>>s1){
      cin>>s2;
string ur=s1,mom=s2;

I_love(fuck,ur,mom);

}

return 0;
}
