/*
ID: brokard1
TASK: prefix
LANG: C++
*/

// THe main hackery apart from using DP is to note that the primitives are at most 10 long

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



int main() {
    ifstream fin ("prefix.in");
    ofstream fout ("prefix.out");

    vector<string> primitives;
    while (true) {
        string S;
        fin >> S;
        if (S == ".") {
            break;
        }
        primitives.push_back(S);
    }

    // Code to read the sequence, because you can't
    // just cin, as this is a multiline input due to
    // dumb ioi convention
    string sequence = "";
    string line;
    while (getline(fin, line)) {
        // Process each line of input here
        sequence += line;
    }

    bool prefixable[sequence.size() + 1];
    for (int i=0; i < sequence.size() + 1; i++){
        prefixable[i] = false;
    }
    prefixable[0] = true;

    for (int k = 1; k < sequence.size() + 1; k++) {
        string firstk;
        // orignially no distinction was made between k <= 10 and all other k.
        // The issue is that string access takes O(k) time if you dont make a distinction.
        // The key idea is to note that you dont need all the first k characters of the string
        // since the primitives have length at most 10, so you only need indexes k-10, ..., k-1. 
        // to perform the DP step. 
      
        if (k <= 10) {
            firstk = sequence.substr(0, k);
        } else {
            firstk = sequence.substr(k-10, 10);
        }

        for (string prim : primitives) {
            if (prim.size() <= k) {
                // check if it fits the back
                string ending = firstk.substr(firstk.size() - prim.size());
                if (ending == prim && !prefixable[k]) {
                    prefixable[k] = prefixable[k - prim.size()];
                    if (prefixable[k]) {
                        break;
                    }
                }
            }
        }
    }

    for (int k = sequence.size(); k >= 0; k--) {
        if (prefixable[k]) {
            fout << k << endl;
            break;
        }
    }
}
