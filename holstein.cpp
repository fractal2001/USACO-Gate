/*
ID: brokard1
TASK: holstein
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<string> bin;

bool compare(string A, string B){
    return count(A.begin(),A.end(),'1') < count(B.begin(),B.end(),'1');
}

void iden(int N){ //binary strings of length N
    if (N == 1){
        bin.push_back("0");
        bin.push_back("1");
        return;
    }
    iden(N-1);
    for (int i=0; i<pow(2,N-1); i++){
        bin.push_back(bin[i]+"1");
        bin[i] += "0"; // sort based on number of ones by creating comparator
    }
    sort(bin.begin(),bin.end(),compare);
}

vector<int> add(vector<int> A, vector<int> B){
    vector<int> C;
    for (int i=0; i<A.size(); i++){
        C.push_back(A[i]+B[i]);
    }
    return C;
}

bool check(vector<int> A, vector<int> B){ //want A<B i.e. minReq should be 1st param
    for (int i=0; i<A.size(); i++){
        if (A[i] > B[i]) return false;
    }
    return true;
}

int main(){
    ifstream fin ("holstein.in");
    ofstream fout ("holstein.out");
    int V; fin >> V;
    vector<int> req(V);
    for (int i=0; i<V; i++){
        int vitReq; fin >> vitReq;
        req[i] = vitReq;
    }
    int G; fin >> G;
    vector<vector<int>> feeds;
    for (int i=0; i<G; i++){
        vector<int> scoop;
        for (int j=0; j<V; j++){
            int amt; fin >> amt;
            scoop.push_back(amt);
        }
        feeds.push_back(scoop);
    }
    iden(G);
    bin.erase(bin.begin());
    for (auto const&str:bin){
        vector<int> addition(V,0);
        int i = 0;
        int num = 0;
        vector<int> used;
        for (char const&c:str){
            if (c == '1'){
                num ++;
                addition = add(addition,feeds[i]);
                used.push_back(i);
            }
            i++;
        }
        if (check(req,addition)) {
            fout << num << " ";
            for (int i=0; i<used.size()-1; i++){
                fout << used[i]+1 << " ";
            }
            fout << used[used.size()-1]+1 << endl;
            break;
        }
    }
    return 0;
}