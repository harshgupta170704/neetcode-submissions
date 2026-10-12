
class Solution {
public:
    bool fun(int n, int m, vector<vector<char>>& board,
             string& word, int i, int j, int index,
             vector<vector<int>>& freq) {

        if (index == word.size())
            return true;

        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (freq[i][j] == 1 || board[i][j] != word[index])
            return false;

        freq[i][j] = 1;

        bool found =
            fun(n, m, board, word, i + 1, j, index + 1, freq) ||
            fun(n, m, board, word, i - 1, j, index + 1, freq) ||
            fun(n, m, board, word, i, j + 1, index + 1, freq) ||
            fun(n, m, board, word, i, j - 1, index + 1, freq);

        freq[i][j] = 0;  // Backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> freq(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (fun(n, m, board, word, i, j, 0, freq))
                    return true;
            }
        }

        return false;
    }
};
