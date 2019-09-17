/*
ID: brokard1
TASK: lamps
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

void b1(vector<int> &lights,int N, char t){
	if (t == '1'){
		for (int i=0; i < N; i++){
			lights[i] = 1-lights[i];
		}
	}
}
void b2(vector<int> &lights,int N, char t){
	if (t == '1'){
		for (int i=0; i < N; i+=2){
			lights[i] = 1-lights[i];
		}
	}
}
void b3(vector<int> &lights,int N, char t){
	if (t == '1'){
		for (int i=1; i < N; i+=2){
			lights[i] = 1-lights[i];
		}
	}
}
void b4(vector<int> &lights,int N, char t){
	if (t == '1'){
		for (int i=0; i < N; i+=3){
			lights[i] = 1-lights[i];
		}
	}
}

string make_str(vector<int> A){
    string str = "";
    for (auto const&c:A){
        str += (c+'0');
    }
    return str;
}

int main(){
	ifstream fin ("lamps.in");
	ofstream fout ("lamps.out");
	int N, C; fin >> N >> C;
	vector<int> lights(N,1);
	vector<int> reset(N,1);
	set<string> reachStates;
	vector<int> on;
	vector<int> off;
	while (true) {
		int c; fin >> c;
		if (c == -1) break;
		else on.push_back(c-1);
	}
	while (true) {
		int c; fin >> c;
		if (c == -1) break;
		else off.push_back(c-1);
	}
	if (C == 0){
		reachStates.insert(make_str(lights));
	} else if (C == 1){
		string poss[4] = {"0001","0010","0100","1000"};
		for (auto const&c:poss){
			b1(lights,N,c[0]);
			b2(lights,N,c[1]);
			b3(lights,N,c[2]);
			b4(lights,N,c[3]);
			reachStates.insert(make_str(lights));
			lights = reset;
		}
	} else if (C == 2){
		string poss[] = {"0000","0011","0110","1100","1001","0101","1010"};
		for (auto const&c:poss){
			b1(lights,N,c[0]);
			b2(lights,N,c[1]);
			b3(lights,N,c[2]);
			b4(lights,N,c[3]);
			reachStates.insert(make_str(lights));
			lights = reset;
		}
	} else if (C == 3){
		string poss[] = {"0001","0010","0100","1000","1110","1101","1011","0111"};
		for (auto const&c:poss){
			b1(lights,N,c[0]);
			b2(lights,N,c[1]);
			b3(lights,N,c[2]);
			b4(lights,N,c[3]);
			reachStates.insert(make_str(lights));
			lights = reset;
		}
	} else if (C%2 == 0){
		string poss[] = {"0000","0011","0110","1100","1001","0101","1010","1111"};
		for (auto const&c:poss){
			b1(lights,N,c[0]);
			b2(lights,N,c[1]);
			b3(lights,N,c[2]);
			b4(lights,N,c[3]);
			reachStates.insert(make_str(lights));
			lights = reset;
		}
	} else {
		string poss[] = {"0001","0010","0100","1000","1110","1101","1011","0111"};
		for (auto const&c:poss){
			b1(lights,N,c[0]);
			b2(lights,N,c[1]);
			b3(lights,N,c[2]);
			b4(lights,N,c[3]);
			reachStates.insert(make_str(lights));
			lights = reset;
		}
	}
	int cnt = 0;
	for (auto const&c:reachStates){
		bool OK = true;
		for (auto const&k:on){
		    if (c[k] == '0') {OK = false; break;}
		}
		for (auto const&k:off){
		    if (c[k] == '1') {OK = false; break;}
		}
		if (OK) {fout << c << endl; cnt++;}
	}
	if (cnt == 0){
		fout << "IMPOSSIBLE\n";
	}
}
