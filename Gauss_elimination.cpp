#include<bits/stdc++.h>
using namespace std;

void gaussElimination(vector<vector<double>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            cout << "Error." << endl;
            return;
        }

        for (int j = i + 1; j < n; j++) {
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    cout << "Solution: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << solution[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix coefficients:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    gaussElimination(matrix, n);
    return 0;
}

