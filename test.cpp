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

vector<int> find_common(vector<int> vect1, vector<int> vect2);

vector<int> fill_vector(int (*matrix)[2], vector<int> vect);

int fill_matrix(vector<int> &X, vector<int> &Y);

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

int fill_matrix(vector<int> &X, vector<int> &Y) {
    int v1, v2;
    int matrix[Y[0]][2];
    vector<int> vect1 = {X[0]}, vect2 = {X[1]}, vect3 = {};

    for (int i = 1; i <= Y[1]; ++i) {
        if (scanf("%d%d", &v1, &v2) != 2)
            return 0;
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
    vect1 = fill_vector(matrix, vect1);
    vect2 = fill_vector(matrix, vect2);
    vect3 = find_common(vect1, vect2);
    if (vect3.size() == 0){
        printf("-\n");
        return 1;
    }
    for (auto element : vect3) 
        printf("%d ", element);
    printf("\n");
    return 1;
}

vector<int> fill_vector(int (*matrix)[2], vector<int> vect) {
    int aux = 0;
    while (true){
        if (matrix[vect.back() - 1][0] == 0){
            break;
        }
        if (matrix[vect.back() - 1][1] == 0) {
            if (find(vect.begin(), vect.end(), matrix[vect.back() - 1][0]) == vect.end()) {
                vect.push_back(matrix[vect.back() - 1][0]);
                continue;
            }
            break;
        }
        if (find(vect.begin(), vect.end(), matrix[aux - 1][0]) != vect.end() && 
        find(vect.begin(), vect.end(), matrix[aux - 1][1]) != vect.end())
            break;
        aux = vect.back();
        if (find(vect.begin(), vect.end(), matrix[vect.back() - 1][0]) == vect.end()){
            vect.push_back(matrix[vect.back() - 1][0]);
            vect = fill_vector(matrix, vect);
        }
        if (find(vect.begin(), vect.end(), matrix[aux - 1][1]) == vect.end()){
            vect.push_back(matrix[aux - 1][1]);
        }      
    }
    return vect;
}

vector<int> find_common(vector<int> vect1, vector<int> vect2) {
    vector<int> vect3 = {};
    
    for (int i = 0; i < (int) vect1.size(); i++) {
        if (find(vect2.begin(), vect2.end(), vect1[i]) != vect2.end()){
            auto aux = find(vect2.begin(), vect2.end(), vect1[i]);
            int index = aux - vect2.begin();
            vect3.push_back(vect1[i]);
            while (vect1[i] == vect2[index]) {
                i++;
                aux++;
            }
        }
    }
    return vect3;
}
