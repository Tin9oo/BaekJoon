#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int min_diff = INT_MAX;

int calc_team_ablity(vector<vector<int>>& S, vector<bool>& team) {
    int score_link = 0;
    int score_start = 0;

    for(int i = 0; i < team.size()-1; ++i) {
        for(int j = i+1; j < team.size(); ++j) {
            if(team[i] && team[j]) {
                score_link += S[i][j] + S[j][i];
            }
            else if(!team[i] && !team[j]) {
                score_start += S[i][j] + S[j][i];
            }
        }
    }
    
    return abs(score_link-score_start);
}

void solve(vector<vector<int>>& S, vector<bool> team, int N, int n, int team_size) {    
    if(n == N) {
        min_diff = min(min_diff, calc_team_ablity(S, team));
        return;
    }

    team[n] = true;
    solve(S, team, N, n+1, team_size+1);
    team[n] = false;
    solve(S, team, N, n+1, team_size);

}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> S(N, vector<int> (N));

    vector<bool> team(N, false);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> S[i][j];
        }
    }

    solve(S, team, N, 0, 0);

    cout << min_diff << endl;

    return 0;
}