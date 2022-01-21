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

using namespace std;

void checkCom(vector<int> &X, vector<int> &Y) {
    int v1, v2;
    vector<list<int>> adjacencyList(Y[0] + 1);
    for (int i = 1; i <= Y[1]; ++i) {
        scanf("%d %d", &v1, &v2);
        adjacencyList[v1].push_back(v2);
    }
    
    
}

int main() {
    string apexs, sizes, split;
    vector<int> numbers_apex, numbers_size;

    getline(cin, apexs);
    stringstream X(apexs);
    
    getline(cin, sizes);
    stringstream X(sizes);

    while(getline(X, split, ' ')) {
        numbers_apex.push_back(atoi(split.c_str()));
    }

    while(getline(X, split, ' ')) {
        numbers_size.push_back(atoi(split.c_str()));
    }

    checkCom(numbers_apex, numbers_size);

    return 0;
}
