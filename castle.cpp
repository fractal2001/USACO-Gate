/*
ID: brokard1
TASK: castle
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

int grid[50][50];
int M, N;

bool priority(pair<int,int> A, pair<int,int> B){// A<B ->true A>B -> false
    if (A.first != B.first) return A.first < B.first;
    else return A.second > B.second;
}

bool wall(int X, int Y, int dir){ //0 -> W; 1-> N; 2->E; 3->S
    // EVERYTHING WRT X. dir = Y's pos wrt X
    string x = bitset<4>(X).to_string();
    string y = bitset<4>(Y).to_string();
    if (dir == 0){
        if ('0' == y[1] && x[3] == '0'){
            return true;
        }
        return false;
    } else if (dir == 1){
        if ('0' == y[0] && x[2] == '0'){
            return true;
        } 
        return false;
    } else if (dir == 2) {
        if ('0' == x[1] && y[3] == '0'){
            return true;
        }
        return false;
    } else {
        if ('0' == x[0] && y[2] == '0'){
            return true; // true if no wall exists
        }
        return false;
    }
}

map<int,set<int>> neighbors; //checks what are neighbors of int after the flood 
map<int,int> areas;
int floodfill(int r, int c, int num, int area){
    int orig = grid[r][c];
    area ++;
    grid[r][c] = num; //BC UR CHANGING THE GRID VALUE RIGHT AWAY. THATS WHY IT WAS WRONG B4
    int dr[4] = {0,0,-1,1};
    int dc[4] = {1,-1,0,0};
    for (int k=0; k<4; k++){
        int i = dr[k];
        int j = dc[k];
        if (0 <= r+i && r+i<N && c+j >= 0 && c+j<M){
            if (j == 1){
                if (wall(orig,grid[r][c+1],2)){
                    if (grid[r][c+1] < 16) area += floodfill(r,c+1,num,0);
                }
            } else if (j == -1){
                if (wall(orig,grid[r][c-1],0)){
                    if (grid[r][c-1] < 16) area += floodfill(r,c-1,num,0);
                }
            } else if (i == 1){
                if (wall(orig,grid[r+1][c],3)){
                    if (grid[r+1][c] < 16) area += floodfill(r+1,c,num,0);
                }
            } else if (i == -1){
                if (wall(orig,grid[r-1][c],1)){
                    if (grid[r-1][c] < 16) area += floodfill(r-1,c,num,0);
                }
            }
        }
    }
    return area;
}

void get_neighbors(){
    //TO BE CALLED AFTER FLOOD
    for (int i=0; i<N; i++){
        for (int j=0; j<M-1; j++){
            if (grid[i][j] != grid[i][j+1]) {neighbors[grid[i][j+1]].insert(grid[i][j]); neighbors[grid[i][j]].insert(grid[i][j+1]);}
        }
    }
    for (int i=0; i<N-1; i++){
        for (int j=0; j<M; j++){
            if (grid[i][j] != grid[i+1][j]) {neighbors[grid[i+1][j]].insert(grid[i][j]); neighbors[grid[i][j]].insert(grid[i+1][j]);}
        }
    }
}

int main(){
    ifstream fin ("castle.in");
    ofstream fout ("castle.out");
    fin >> M >> N;
    int restore[N][M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            int inf; fin >> inf;
            grid[i][j] = inf;
            restore[i][j] = inf;
        }
    }
    int num = 16;
    int maxA = 0;
    for (int j=0; j<M; j++){ //wierd hack to get the wall bc this problem is dumb
        for (int i=N-1; i>-1; i--){
            if (grid[i][j] < 16) {
                int K = floodfill(i,j,num,0);
                areas[num] = K;
                if (maxA < K){
                    maxA = K;
                } 
                num++;
            }
        }
    }
    get_neighbors();
    int maxNew = 0;
    for (auto const&c:neighbors){
        int localM = 0;
        for (auto const&k:c.second){
            localM = max(localM,areas[k]);
        }
        maxNew = max(maxNew,areas[c.first] + localM);
    }
    pair<int,int> ans1;
    for (int j=0; j<M; j++){ //wierd hack to get the wall bc this problem is dumb
        bool sw = false;
        for (int i=N-1; i>0; i--){
            if (grid[i][j] != grid[i-1][j]){
                if (areas[grid[i][j]] + areas[grid[i-1][j]] == maxNew){
                    ans1 = make_pair(i+1,j+1);
                    sw = true;
                    break;
                }
            }
        }
        if (sw) break;
    }
    pair<int,int> ans2;
    for (int j=0; j<M-1; j++){ //wierd hack to get the wall bc this problem is dumb
        bool sw = false;
        for (int i=N-1; i>-1; i--){
            if (grid[i][j] != grid[i][j+1]){
                if (areas[grid[i][j]] + areas[grid[i][j+1]] == maxNew){
                    ans2 = make_pair(i+1,j+1);
                    sw = true;
                    break;
                }
            }
        }
        if (sw) break;
    }
    fout << num-16 << endl;
    fout << maxA << endl;
    fout << maxNew << endl;
    if (ans1 == ans2){
        fout << ans1.first << " " << ans1.second << " N" << endl;
    } else if (ans1.first > ans2.first){
        fout << ans1.first << " " << ans1.second << " N" << endl;
    } else if (ans1.first < ans2.first){
        fout << ans2.first << " " << ans2.second << " E" << endl;
    } else if (ans1.first == ans2.first){
        if (ans1.second < ans2.second){
            fout << ans1.first << " " << ans1.second << " N" << endl;
        } else {
            fout << ans2.first << " " << ans2.second << " E" << endl;
        }
    }
}
