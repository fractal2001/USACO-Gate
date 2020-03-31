/*
ID: brokard1
TASK: nocows
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <tuple>
#include <map>
using namespace std;

typedef long long ll;
typedef double dd;
typedef vector<ll> vll;
typedef vector<dd> vd;

int main(){
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");
  ll N, K; fin >> N >> K;
  ll dp[K+1][N+1] = {};
  dp[1][1] = 1;
  for (int k=2; k<= K; k++){
    for (int n=1; n<=N; n+=2){
      //to get dp[k][n]
      for (int x=1; x<n-1; x+=2){
        for (int j=1; j<k-1; j++){
          dp[k][n]+= 2*dp[k-1][x]*dp[j][n-1-x];
        }
      }
      for (int x=1; x<n-1; x+=2){
        dp[k][n]+=dp[k-1][x]*dp[k-1][n-1-x];
      }
      dp[k][n]=dp[k][n]%9901;
    }
  }
  fout << dp[K][N]%9901 << endl;
}
