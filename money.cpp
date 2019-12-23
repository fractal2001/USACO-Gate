/*
ID: brokard1
TASK: money
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

long long v, N;
vector<long long> V;

int main(){
	ifstream fin ("money.in");
	ofstream fout ("money.out");
	fin >> v >> N;
	for (long long i=0; i<v; i++){
		long long c; fin >> c; V.push_back(c);
	}
	sort(V.begin(),V.end());
	vector<long long> ways(N+1);
	ways[0] = 1;
	for (auto const&c:V){
		for (int i=c; i<N+1; i++){
			ways[i] += ways[i-c];
		}
	}
	fout << ways[N] << endl;
}
