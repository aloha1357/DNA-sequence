# UVa 10130_Super Sale_
## menu
[TOC]
## Description
A DNA molecule consists of two strands that wrap around each other to resemble a twisted ladder whose sides,made of sugar and phosphate molecules, are connected by rungs of nitrogen-containing chemicals called bases.Each strand is linear arrangement of repeating similar units called nucleotides, which are each composed of one sugar,one phosphate, and a nitrogenous base.Four different bases are present in DNA: adenine (A), thymine (T), cytosine (C), and guanine (G).The particular order of the bases arranged along the sugar-phosphate backbone is called the DNA sequence;the sequence specifies the exact genetic instructions required to create a particular organism with its own unique traits.

Geneticists often compare DNA strands and are interested in finding the longest common base sequence in the two strands.Note that these strands can be represented as strings consisting of the letters a, t, c and g.So, the longest common sequence in the two strandsatgcandtgaistg.It is entirely possible that two different common sequences exist that are the same length and are the longest possible common sequences.For example in the strandsatgsandgctg, the longest common sequences aregcandtg.

Write a program that accepts as input two strings representing DNA strands, and print as output the longest common sequence(s) in lexicographical order.
## Input
The input file contains several test cases with a blank line between two consecutive.

The string are at most 300 characters-long.

## Output
For each test case, print all the longest common sequences, one per line, in lexicographical order.

If there isn't any common sequence between the two strings, just print: 'No common sequence.'

Print a blank line between the output of consecutive datasets.
## Think_and_How    思路
-

# Solution
```C++=
#include <bits/stdc++.h>
using namespace std;
struct item{
  public:
  item(){
    price=0;
    weight=0;
  }
  int price;
  int weight;
};
int main(){

  int T=0;
  cin>>T;
  while(T--&&T>=0)
  {
    int n=0;
    cin>>n;
    item items[n];
    for(int i=0;i<n;i++)
        cin>>items[i].price>>items[i].weight;
    int fam=0;
    cin>>fam;
    int fams_weight[fam];
    memset(fams_weight,0,sizeof(fams_weight[0]));

    for(int i=0;i<fam;i++)
      cin>>fams_weight[i];

    int ans=0;
    for(int h=0;h<fam;h++)
    {
      int W=fams_weight[h]+1;
      int dp[n+1][W];
      memset(dp,0,sizeof(dp[0][0])*(n+1)*W );
      for(int i=1;i<=n;i++)
      {
        int iw=items[i-1].weight;//weight of this item
        int ip=items[i-1].price;//price of this item
        for(int w=1;w<W;w++)
        {
            dp[i][w]=dp[i-1][w];
            if(iw<=w)
            {
              dp[i][w]=max(dp[i][w],ip+dp[i-1][w-iw]);
                //cout<<dp[i][w]<<"$$$$\n";

            }

        }
      }
      ans+=dp[n][W-1];
    }
    cout<<ans<<"\n";

  };

  return 0;
}
```
# Dynamic programming
## Average
### Time complexity

-
   	The algorithm check n*money times; n is length of wish lists; monet is the limit of a budget card.
-	So the time complexity should be O(N*money)


### Space complexity
-    Owing to use the wish lists array( n ) arrays plus item lists plus n*budget cap arrays So… n+lists+n*budget cap belows to n*(budget cap) is O(n*budget)
 - The space complexity is O(n*budget).

# Super Sale _ac

 ![](https://i.imgur.com/zh65XCy.png)

 :::info
Asighment   4
Student_id:410821317 
Name:蔡明翰
:::