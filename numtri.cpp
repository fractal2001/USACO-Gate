/*
ID: brokard1
TASK: numtri
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

vector<int> merge(vector<int> A, vector<int> B, int N){ // A has size N-1, B has size N. modify B
    B[0] += A[0]; B[N-1] += A[N-2];
    for (int i=1; i<= N-2; i++){
        B[i] += max(A[i-1], A[i]);
    }
    return B;
}

int main(){
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int N; fin >> N;
    vector<int> prev;
    int x; fin >> x; prev.push_back(x);
    for (int i=2; i<=N; i++){
        vector<int> next;
        for (int j=0; j<i; j++){
            int x; fin >> x; next.push_back(x);
        }
        next = merge(prev,next,i);
        prev = next;
    }
    fout << *max_element(prev.begin(), prev.end()) << endl;
}

