class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int arr[10] = {0};
        int checkarr[3] = {0, 3, 6};

        //checking each box
        for(int i: checkarr) {
            for(int j: checkarr) {
                for(int l = i; l < i + 3; l++) {
                    for(int k = j; k < j + 3; k++) {
                        if (board[l][k] == '.') continue;
                        else 
                            arr[board[l][k] - '1']++;
                    }
                }
                for(int i = 0; i < 9; i++) {
                    if(arr[i] > 1) return false;
                    arr[i] = 0;
                }
            }
        }

        //checking each row
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                arr[board[i][j] - '1']++;
            }
            for(int j = 0; j < 9; j++) {
                if(arr[j] > 1) return false;
                arr[j] = 0;
            }
        }

        //checking each column
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') continue;
                arr[board[j][i] - '1']++;
            }
            for(int j = 0; j < 9; j++) {
                if(arr[j] > 1) return false;
                arr[j] = 0;
            }
        }

        return true;
    }
};
