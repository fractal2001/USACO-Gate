/*
ID: brokard1
TASK: zerosum
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

int parse_str(string S, int sum = 0){ //WHILE PUTTING THE STRING IN HERE REMEMBER TO PUT THE PLUS 
    S.erase(remove(S.begin(), S.end(), ' '), S.end()); 
	if (S.size() == 0) return sum;
    if (S[0] == '+'){
        S.erase(S.begin());
        string num = "";
        while (S.size() > 0){
            if (S[0] != '+' and S[0] != '-') {num += S[0]; S.erase(S.begin());}
            else break;
        }
        sum += stoi(num);
        return parse_str(S,sum);
    } else {
        S.erase(S.begin());
        string num = "";
        while (S.size() > 0){
            if (S[0] != '+' and S[0] != '-') {num += S[0]; S.erase(S.begin());}
            else break;
        }
        sum -= stoi(num);
        return parse_str(S,sum);
    }
}

set<string> gen(int N){
    if (N == 1) return {" ","+","-"};
    set<string> X = gen(N-1);
    set<string> ans;
    for (auto const&c:X){
        ans.insert(c+' ');
        ans.insert(c+'+');
        ans.insert(c+'-');
    }
    return ans;
}

int main(){
	ifstream fin ("zerosum.in");
	ofstream fout ("zerosum.out");
	int N; fin >> N;
	string arr = "";
	for (int i=1; i<=N; i++){
	    arr += to_string(i);
	}
    for (auto const&c:gen(N-1)){
        string k = '+' + c;
        string str = "";
        for (int i=0; i<N; i++){
            str += k[i];
            str += arr[i];
        }
        if (parse_str(str) == 0) {str.erase(str.begin()); fout << str << endl;}
    }
}
