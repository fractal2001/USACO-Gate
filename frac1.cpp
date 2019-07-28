/*
ID: brokard1
TASK: frac1
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int gcd(int A, int B){
    if (A == 0 or B == 0) return A+B;
    else if (A>B) return gcd(A-B,B);
    else return gcd(A,B-A);
}

bool compare(pair<int,int> A, pair <int,int> B){
    return (A.first * B.second < A.second * B.first);
}

set<pair<int,int>, decltype(&compare)> S(&compare);

void classN(int N){
    for (int i=0; i<=N; i++){
        if (gcd(i,N) == 1){
            S.insert(make_pair(i,N));
        }
    }
}

int main(){
    ifstream fin ("frac1.in");
    ofstream fout ("frac1.out");
    int N; fin >> N;
    for (int i=1; i<= N; i++){
        classN(i);
    }
    for (auto const&c:S){
        fout << c.first << "/" << c.second << endl;
    }
}
