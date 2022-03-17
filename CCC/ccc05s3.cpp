// Problem: https://dmoj.ca/problem/ccc05s3
#include <bits/stdc++.h>
using namespace std;
int N, r, c, ai, out;
int prodRow = 1;
int prodCol = 1;
vector<int> temp, ans, rowsums, colsums;
int main(){
    ios::sync_with_stdio(0);
    cin >> N;
    int rs[N], cs[N];
    vector<vector<int>> x(N);
    for (int i = 0; i < N; i++){
        cin >> r >> c;
        rs[i] = r;
        cs[i] = c;
        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                cin >> ai;
                x[i].push_back(ai);
            }
        }
    }
    temp = x[0];
    for (int i = 0; i < N-1; i++){
        ans.clear();
        prodRow *= rs[i];
        prodCol *= cs[i];
        int jcount = 0;
        for (int a = 0; a < prodRow; a++){
            int kcount = 0;
            for (int b = 0; b < rs[i+1]; b++){
                for (int j = 0; j < prodCol; j++){
                    for (int k = 0; k < cs[i+1]; k++){
                        out = temp[j+jcount] * x[i+1][k+kcount];
                        ans.push_back(out);
                    }
                }
                kcount += cs[i+1];
            }
            jcount += prodCol;
        }
        temp = ans;
    }
    prodCol *= cs[N-1];
    prodRow *= rs[N-1];
    for (int j = 0; j < prodCol; j++){
        int sum = 0;
        for (int i = 0; i < prodRow; i++){
            sum += ans[i * prodCol + j];
        }
        colsums.push_back(sum);
    }
    for (int j = 0; j < prodRow; j++){
        int sum = 0;
        for (int i = 0; i < prodCol; i++){
            sum += ans[i+prodCol*j];
        }
        rowsums.push_back(sum);
    }
    auto maxMin = minmax_element(ans.begin(), ans.end());
    int max = *maxMin.second;
    int min = *maxMin.first;
    auto maxRows = minmax_element(rowsums.begin(), rowsums.end());
    int maxRow = *maxRows.second;
    int minRow = *maxRows.first;
    auto maxCols = minmax_element(colsums.begin(), colsums.end());
    int maxCol = *maxCols.second;
    int minCol = *maxCols.first;
    cout << max << "\n"; 
    cout << min << "\n";
    cout << maxRow << "\n" << minRow << "\n" << maxCol << "\n" << minCol;
}
