/*
ID: brokard1
TASK: preface
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
using namespace std;

vector<string> gen(string A, string B, string C){ //N=2 -> tens
    vector<string> ans= { "",A,A+A,A+A+A,A+B,B,B+A,B+A+A,B+A+A+A,A+C };
    return ans;
}

vector<string> digits[4] = {gen("I","V","X"), gen("X","L","C"), gen("C","D","M"), {"","M","MM","MMM"}};
string roman(string S, int len){
    if (len == 1){
        return digits[len-1][stoi(S)];
    }
    char f = S[0];
    string K = "";
    K += digits[len-1][f-'0'];
    S.erase(S.begin());
    K += roman(S,len-1);
    return K;
}
char dig[7] = {'I','V','X','L','C','D','M'};
map<char,int> cnt;

int main(){
    ifstream fin ("preface.in");
    ofstream fout ("preface.out");
    int N; fin >> N;
    //vector<string> digits[4] = {gen("I","V","X"), gen("X","L","C"), gen("C","D","M"), {"M","MM","MMM"}};
    for (int i=1; i<=N; i++){
        string S = to_string(i);
        for (char const&c:roman(S,S.size())){
            cnt[c]++;
        }
    }
    for (char const&c:dig){
        if (cnt[c] != 0){
            fout << c << " " << cnt[c] << endl;
        }
    }
}
