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

int fill_matrix(vector<int> &X, vector<int> &Y) {
    int v1, v2;
    int matrix[Y[0]][2];
    vector<int> vect1 = {X[0]}, vect2 = {X[1]};

    for (int i = 1; i <= Y[1]; ++i) {
        scanf("%d%d", &v1, &v2);
        if (matrix[v2-1][0] == 0){
            matrix[v2-1][0] = v1;
            continue;
        }
        if (matrix[v2-1][1] == 0){
            matrix[v2-1][1] = v1;
            continue;
        }
        else
            return 0;
    }
    while (true){
        if (matrix[vect1.back() - 1][0] == 0 && matrix[vect1.back() - 1][1] == 0){
            break;
        }
        if (matrix[vect1.back() - 1][0] == 0)
            continue;
        vect1.push_back(matrix[vect1.back() - 1][0]);
        if (matrix[vect1.back() - 1][1] == 0)
            continue;
        
    }

    return 1;
}

int main() {
    string apexs, sizes, split;
    vector<int> numbers_apex, numbers_size;

    getline(cin, apexs);
    stringstream X(apexs);
    
    getline(cin, sizes);
    stringstream Y(sizes);

    while(getline(X, split, ' ')) {
        numbers_apex.push_back(atoi(split.c_str()));
    }

    while(getline(Y, split, ' ')) {
        numbers_size.push_back(atoi(split.c_str()));
    }
    
    if (fill_matrix(numbers_apex, numbers_size) == 0)
        printf("0\n");
    
    return 0;
}
