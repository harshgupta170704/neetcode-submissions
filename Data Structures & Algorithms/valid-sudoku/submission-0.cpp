class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // row[i][num] -> num already exists in row i
        vector<vector<int>> row(9, vector<int>(9, 0));

        // col[j][num] -> num already exists in column j
        vector<vector<int>> col(9, vector<int>(9, 0));

        // box[k][num] -> num already exists in 3x3 box k
        vector<vector<int>> box(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.')
                    continue;

                // Convert '1' - '9' into 0 - 8
                int num = board[i][j] - '1';

                // Find which 3x3 box this cell belongs to
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check row
                if (row[i][num] > 0)
                    return false;

                // Check column
                if (col[j][num] > 0)
                    return false;

                // Check 3x3 box
                if (box[boxIndex][num] > 0)
                    return false;

                row[i][num]++;
                col[j][num]++;
                box[boxIndex][num]++;
            }
        }

        return true;
    }
};