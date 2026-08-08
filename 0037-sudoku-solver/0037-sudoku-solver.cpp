#include <vector>
using namespace std;

class Solution
{
private:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
                return false;

            if (board[i][col] == c)
                return false;

            if (board[3 * (row / 3) + i / 3]
                     [3 * (col / 3) + i % 3] == c)
                return false;
        }

        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9)
            return true;

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9)
        {
            nextRow++;
            nextCol = 0;
        }

        if (board[row][col] != '.')
        {
            return helper(board, nextRow, nextCol);
        }

        for (char c = '1'; c <= '9'; c++)
        {
            if (isValid(board, row, col, c))
            {
                board[row][col] = c;

                if (helper(board, nextRow, nextCol))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board, 0, 0);
    }
};