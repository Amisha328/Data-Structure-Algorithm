// Find Winner on a Tic Tac Toe Game
// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> winPatterns = {
            {0, 1, 2},
            {0, 3, 6},
            {0, 4, 8},
            {1, 4, 7},
            {2, 5, 8},
            {2, 4, 6},
            {3, 4, 5},
            {6, 7, 8}
        };

        vector<string> pos(9, "");
        bool turnA = true;

        for(int i = 0; i < moves.size(); i++){
            int idx = moves[i][0] * 3 + moves[i][1];
            if(turnA){
                pos[idx] = "A";
                turnA = false;
            }
            else{
                pos[idx] = "B";
                turnA = true;
            }
        }

        for(int i = 0; i < 8; i++){
            if(pos[winPatterns[i][0]] != "" && pos[winPatterns[i][1]] != ""  && pos[winPatterns[i][2]] != ""){
                if(pos[winPatterns[i][0]] == pos[winPatterns[i][1]] && pos[winPatterns[i][1]] == pos[winPatterns[i][2]])
                    return pos[winPatterns[i][0]];
            }
        }

        return moves.size() == 9 ? "Draw":"Pending";
    }
};
