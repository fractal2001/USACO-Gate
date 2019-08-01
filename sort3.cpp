/*
ID: brokard1
TASK: sort3
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;

int main(){
    ifstream fin ("sort3.in");
    ofstream fout ("sort3.out");
    int N; fin >> N;
    vector<int> sorted(N);
    vector<int> orig(N);
    for (int i=0; i<N; i++){
        int C; fin >> C;
        orig[i] = C;
        sorted[i] = C;
    }
    sort(sorted.begin(),sorted.end());
    vector<pair<int,int>> stack;
    int steps = 0;
    for (int i=0; i<N; i++){
        if (sorted[i] != orig[i]){
            auto it = find(stack.begin(), stack.end(), make_pair(sorted[i],orig[i]));
            if (it != stack.end()){
                stack.erase(it);
                steps++;
            } else {
                stack.push_back(make_pair(orig[i], sorted[i]));
            }
        }
    }
    fout << steps + 2*stack.size()/3 << endl;
}