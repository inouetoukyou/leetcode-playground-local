//
// Created by Minghang Yang on 2019-07-20.
//

/*
 * this demo tests string vector
 * it is a solution for lintcode 1022. leetcode 794. Find Eventual Safe States
 * link https://leetcode.com/problems/valid-tic-tac-toe-state/
 *      https://www.lintcode.com/problem/valid-tic-tac-toe-state/
 */

#include "../helper/vector_helper.h"

using namespace std;

class Solution {
public:
    /**
     * @param board: the given board
     * @return: True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game
     */
    bool validTicTacToe(vector<string> &board) {
        // Write your code
        if (board.size() != 3) {
            return false;
        }
        for (int i = 0; i < 3; ++i) {
            if (board[i].size() != 3) {
                return false;
            }
        }
        int cntx = 0;
        int cnto = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++cntx;
                }
                else if (board[i][j] == 'O') {
                    ++cnto;
                }
            }
        }
        if (!(cntx - cnto == 1 || cntx - cnto == 0)) {
            return false;
        }
        int winx_cnt = 0;
        int wino_cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X') {
                    ++winx_cnt;
                }
                else if (board[i][0] == 'O') {
                    ++wino_cnt;
                }
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X') {
                    ++winx_cnt;
                }
                else if (board[0][i] == 'O') {
                    ++wino_cnt;
                }
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') {
                ++winx_cnt;
            }
            else if (board[0][0] == 'O') {
                ++wino_cnt;
            }
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') {
                ++winx_cnt;
            }
            else if (board[0][2] == 'O') {
                ++wino_cnt;
            }
        }
        if (winx_cnt > 0 && cntx == cnto) {
            return false;
        }
        if (wino_cnt > 0 && cntx > cnto) {
            return false;
        }
        return true;
    }
};

int main() {
    string input;
    getline(cin, input);
    vector<string> board = getVector<string>(input);
    outputVector(board);
    cout << Solution().validTicTacToe(board)<< endl;
    /*
     * input:
     * [      "OXX",   "XOX",    "OXO"   ]
     * output:
     * OXX XOX OXO
     * 0
     */
    return 0;
}