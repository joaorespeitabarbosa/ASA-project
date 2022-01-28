/*************************************
 *           ASA 2021/2022           *
 *    Joao Barbosa - ist199087       *
 *      Joao Pinto - ist199093       *
 *************************************/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <queue>

using namespace std;

void bfs(vector<int> &color, vector<vector<int>> &mat, int apex);

int main() {
    int apex1, apex2, n, m, x, y;

    if (scanf("%d %d\n", &apex1, &apex2) != 2)
        return 0;
    if (scanf("%d %d\n", &n, &m) != 2)
        return 0;
    vector<vector<int>> mat (n);
    vector<int> color1(n), color2(n), res, d(n);
    
    for (int i = 0; i < m; i++){
        if  (scanf("%d %d\n", &x, &y) != 2)
            return 0;
        mat[y - 1].push_back(x);
    }
    
    bfs(color1, mat, apex1);
    bfs(color2, mat, apex2);
    
    for (int i = 0; i < n; i++) {
        if (color1[i] == color2[i] && color1[i] == 2){
            res.push_back(i+1);
        }    
    }
    for (int i = 0; i < (int) res.size(); i++) {
        for (int j: mat[res[i]-1]){
            d[j] += 1;
        }    
    }
    for (int i = 0; i < (int) res.size(); i++){
        if (d[res[i]] == 0)
            printf("%d ", res[i]);
    }
    if (res.size() == 0){
        printf("-\n");
        return 0;
    }
    printf("\n");
    return 0;
}

void bfs(vector<int> &color, vector<vector<int>> &mat, int apex) {
    int u;
    queue<int> q;
    color[apex-1] = 1;
    q.push(apex);
    
    while (q.empty() == false) {
        u = q.front();
        q.pop();
        for (int i = 0; i < (int) mat[u-1].size(); i++) {
            if (color[mat[u-1][i]-1] == 0){
                color[mat[u-1][i]-1] = 1;
                q.push(mat[u-1][i]);
            }
        }
        color[u-1] = 2;
    }
}

