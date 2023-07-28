class Solution {
public:

bool dfs(int ind, int row, int col, vector<vector<char>> &board, string word, vector<vector<int>> &visited)
{
    int n = board.size();
    int m = board[0].size();

    if (ind == word.size())
    {
        return true;
    }
    visited[row][col] = 1;

    for (int i = -1; i <=1; i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(abs(i)+abs(j)==2)
            {
                continue;
            }
        
            int r=row+i;
            int c=col+j;

            if (r < n && r >= 0 && c < m && c >= 0 && !visited[r][c] && word[ind] == board[r][c])
            {
                if (dfs(ind + 1, r, c, board, word, visited) == true)
                {
                    return true;
                }
            }
        }
    }
    visited[row][col] = 0;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                bool ans = dfs(1, i, j, board, word, visited);
                if (ans)
                {
                    return ans;
                }
            }
        }
    }
    return false;
}
};
