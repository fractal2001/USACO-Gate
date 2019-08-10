/*
ID: brokard1
TASK: subset
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
int tot = 0;
int N;
int target;
int b;

map<tuple<int,int>,long long> vals;
long long DFS(int lowerB, int cur, long long ans){ // low = highest number of elements
    for (int i = lowerB; i <= N; i++){
        if (cur+i < target){
            tuple<int,int> T = make_tuple(i+1,cur+i);
            if (vals.find(T) == vals.end()){
                ans += DFS(i+1, cur+i,0);
            } else {
                ans += vals[T];
            }
        } else if (cur+i == target){
            ans++;
        } else {
            break;
        }
    }
    vals[make_tuple(lowerB,cur)] = ans;
    return ans;
}

int main(){
    ifstream fin ("subset.in");
    ofstream fout ("subset.out");
    fin >> N;
    b = int((sqrt(2*N*N+2*N+1)-1)/2);
    target = N*(N+1)/4;
    if ((N+1)*N%4 != 0){
        fout << 0 << endl;
    } else {
        fout << DFS(1,0,0)/2 << endl;
        //fout << cnt << " " << vals.size();
    }
}
