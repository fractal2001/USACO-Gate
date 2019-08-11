/*
ID: brokard1
TASK: runround
LANG: C++                 
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

//NEW IDEA. 
//GENERATE ALL NUMBERS WITH NONZERO DISTINCT DIGITS
//CHECK WHICH ONES WORK
//HAT EASY

vector<string> noRepeats(int N){ //N = number of digits
    if (N == 1){
        vector<string> ans;
        for (int i=1; i<10; i++){
            ans.push_back(to_string(i));
        }
        return ans;
    } else {
        vector<string> X = noRepeats(N-1);
        vector<string> ans;
        for (int i = 0; i<X.size(); i++){
            string c = X[i];
            for (int i=1; i<=9; i++){
                char k = i+ '0';
                if (c.find(k) == string::npos){
                    ans.push_back(c+k);
                }
            }
        }
        return ans;
    }
}

bool runRnd(string S){
    int curInd = 0;
    set<int> digits; //list of indexes
    for (int i=0; i<S.size(); i++){
        int curD = S[curInd]-'0';
        if (digits.find(curD) == digits.end()){
            digits.insert(curD);
            curInd += curD;
            curInd = (curInd+S.size())% S.size();
        } else {
            return false;
        }
    }
    if (curInd == 0) return true;
    else return false;
}

int main() {
    ifstream fin ("runround.in");
    ofstream fout ("runround.out");
    unsigned int M; fin >> M;
    vector<int> rounds;
    for (int i=1; i<=7; i++){
        for (auto const&c:noRepeats(i)){
            if (runRnd(c)) rounds.push_back(stoi(c));
        }
    }
    auto it = upper_bound(rounds.begin(), rounds.end(), M);
    fout << *it << endl;
}
