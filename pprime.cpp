/*
ID: brokard1
TASK: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(int N){
  for (int d=2; pow(d,2) <= N; d++){
    if (N%d==0) return false;
  }
  return true;
}

string start[4] {"1","3","7","9"};
string poss[10] {"0","1","2","3","4","5","6","7","8","9"};

int main(){
  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in");
  int a, b; fin >> a >> b;
  for (int digits = 1; digits <= 7; digits +=2){
    if (digits == 1){
      for (int i=0;i<10;i++){
        if (a<=i && i<= b){
          if (is_prime(i)){
            fout << i << endl;
          }
        }
      }
      if (a <= 11 && b >= 11) fout << 11 << endl;
    } else if (digits == 3){
      for (string const&c : start){
        for (string const&k : poss){
          string s = c+k+c;
          int x = stoi(s);
          if (is_prime(x) && x >= a && x <= b) fout << x << endl;
        }
      }
    } else if (digits == 5){
      for (string const&c : start){
        for (string const&k : poss){
          for (string const&h : poss){
            string s = c+k+h+k+c;
            int x = stoi(s);
            if (is_prime(x) && x >= a && x<=b) fout << x << endl;
          }
        }
      }
    } else {
      for (string const&c : start){
        for (string const&k : poss){
          for (string const&h : poss){
            for (string const&l : poss){
              string s = c+k+h+l+h+k+c;
              int x = stoi(s);
              if (is_prime(x) && x >= a && x <= b) fout << x << endl;
          }
        }
      }
    }
  }
}
}
