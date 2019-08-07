/*
ID: brokard1
TASK: hamming
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <fstream>
using namespace std;

bool OK = false;
vector<vector<string>> ans;
int N, B, D; //B = size
vector<string> bin;
ifstream fin ("hamming.in");
ofstream fout ("hamming.out");

bool compare(string S, string T){
    return stoi(S) < stoi(T);
}

void genBin(int N){ //binary strings of length N
    if (N == 1){
        bin.push_back("0");
        bin.push_back("1");
        return;
    }
    genBin(N-1);
    for (int i=0; i<pow(2,N-1); i++){
        bin.push_back(bin[i]+"1");
        bin[i] += "0"; // sort based on number of ones by creating comparator
    }
    sort(bin.begin(),bin.end(),compare);
}

bool hamming(string S, string K){
    int sum = 0;
    for (int i=0; i<S.size(); i++){
        if (S[i] != K[i]) sum++;
    }
    return sum >= D;
}

vector<string> hamGen(string cur){
    vector<string> nextLvl;
    for (auto const&c:bin){
        if (hamming(c,cur)){
            nextLvl.push_back(c);
        }
    }
    return nextLvl;
}

int read_bin(string S){
    int res = 0;
    for (int i=0; i<B; i++){
        res += (S[i]-'0')*pow(2,B-i-1);
    }
    return res;
}

void DFS(string node, unordered_set<string> visited, vector<string> path){
  if (OK == false){
    if (path.size() == N){
        bool sw = true;
        for (int i=0; i<N-1; i++){
            bool quit = false;
            for (int j=i+1; j<N; j++){
                if (!hamming(path[i],path[j])){
                    sw = false;
                    quit = true;
                    break;
                }
            }
            if (quit) break;
        }
        if (sw){
            OK = true;
            sort(path.begin(),path.end(),compare);
            for (int i=0; i<path.size(); i++){
              if ((i+1)%10 == 0 or i == path.size() -1) fout << read_bin(path[i]) << endl;
              else fout << read_bin(path[i]) << " ";
            }
            return;
        }
    }
    vector<string> next = hamGen(node);
    for (auto const&c:next){
        if (visited.find(c) != visited.end()){
            next.erase(remove(next.begin(),next.end(),c),next.end());
        }
    }
    sort(next.begin(),next.end(),compare);
    if (next.size() == 0) return;
    for (auto const&c:next){
        bool works = true;
        for (auto const&k:path){
            if (hamming(k,c) == false){
                works = false;
                break;
            }
        }
        if (works){
            path.push_back(c);
            visited.insert(c);
            DFS(c,visited,path);
            visited.erase(c);
            path.pop_back();
        }
    }
  }
}

int main(){
    fin >> N >> B >> D;
    string start(B,'0');
    genBin(B);
    unordered_set<string> visited;
    vector<string> path{ start };
    DFS(start,visited,path);
}
