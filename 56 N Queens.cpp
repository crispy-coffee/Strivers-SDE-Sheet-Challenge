#include <unordered_map>

bool isQueenSafe(unordered_map<int, bool> &rowQueens, unordered_map<int, bool> &upperDigonalQueens,
                 unordered_map<int, bool> &lowerDigonalQueens, int n, int row, int col)
{
    // Time Complexity: O(1)
    // same row
    if (rowQueens[row])
        return false;
    // same upper diagonal
    if (upperDigonalQueens[n + row - col])
        return false;
    // same lower diagonal
    if (lowerDigonalQueens[row + col])
        return false;
    return true;
}

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> flat;
    for (auto r : board)
    {
        flat.insert(flat.end(), r.begin(), r.end());
    }
    ans.push_back(flat);
}

void backtracking(vector<vector<int>> &ans, vector<vector<int>> &board, unordered_map<int, bool> &rowQueens,
                  unordered_map<int, bool> &upperDigonalQueens, unordered_map<int, bool> &lowerDigonalQueens, int n, int col)
{
    // Base Case
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }
    // check all possibilities
    for (int i = 0; i < n; i++)
    {
        if (isQueenSafe(rowQueens, upperDigonalQueens, lowerDigonalQueens, n, i, col))
        {
            board[i][col] = 1;
            rowQueens[i] = true;
            upperDigonalQueens[n + i - col] = true;
            lowerDigonalQueens[i + col] = true;
            backtracking(ans, board, rowQueens, upperDigonalQueens, lowerDigonalQueens, n, col + 1);
            board[i][col] = 0;
            rowQueens[i] = false;
            upperDigonalQueens[n + i - col] = false;
            lowerDigonalQueens[i + col] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Approach: Backtracking
    // Time Complexity: O(4^N)
    // Space Complexity: O(N*N)
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    unordered_map<int, bool> rowQueens;
    unordered_map<int, bool> upperDigonalQueens;
    unordered_map<int, bool> lowerDigonalQueens;
    backtracking(ans, board, rowQueens, upperDigonalQueens, lowerDigonalQueens, n, 0);
    return ans;
}