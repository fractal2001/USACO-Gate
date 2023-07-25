/*
ID: brokard1
TASK: concom
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <map>

using namespace std;

int n;

vector<int> dfs(int root, vector<pair<int, int>> graph[]) {
    vector<int> owned_comps;
    for (int j=0; j <100; j++) {
        owned_comps.push_back(0);
    }

    owned_comps[root] = 100;
    stack<int> fringe;
    fringe.push(root);
    bool marked[100] = {false};

    while (!fringe.empty()) {
        int node = fringe.top();
        fringe.pop();
        marked[node] = true;
        for (pair<int, int> neighbor : graph[node]) {
            if (!marked[neighbor.first]) {
                owned_comps[neighbor.first] += neighbor.second;
                if (owned_comps[neighbor.first] > 50) {
                    fringe.push(neighbor.first);
                }
            }
        }
    }
    return owned_comps;
}

int main() {
    ifstream fin ("concom.in");
    ofstream fout ("concom.out");

    fin >> n;
    vector<pair<int, int>> graph[100];

    for (int i = 0; i < n; i++){
        int ii, j, p;
        fin >> ii >> j >> p;
        graph[ii-1].push_back(make_pair(j-1, p));
    }

    for (int i = 0; i < 100; i ++ ){
        if (!graph[i].empty()) {
            vector<int> owned_comps = dfs(i, graph);
            for (int k = 0; k<100; k++) {
                if (owned_comps[k] > 50 && k != i) {
                    fout << i + 1 << " " << k + 1 << endl;
                }
            }
        }

    }
    return 0;

}
