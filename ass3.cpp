//3. Simple Columnar Transposition
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string columnarTransposition(string text, string key) {
    int col = key.length();
    int row = (text.length() + col - 1) / col;

    vector<vector<char>> grid(row, vector<char>(col, ' '));

    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (k < text.length())
                grid[i][j] = text[k++];
        }
    }

    vector<pair<char, int>> order;
    for (int i = 0; i < col; i++)
        order.push_back(make_pair(key[i], i));

    sort(order.begin(), order.end());

    string result = "";
    for (auto p : order) {
        for (int i = 0; i < row; i++) {
            if (grid[i][p.second] != ' ')
                result += grid[i][p.second];
        }
    }

    return result;
}

int main() {
    string text = "HELLO";
    string key = "3142";
    cout << "Ciphertext: " << columnarTransposition(text, key);
    return 0;
}
