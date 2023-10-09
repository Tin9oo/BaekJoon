#include <iostream>

using namespace std;

#define debug_input true
#define debug_fn true

int test_case = 0;
vector<int> board_length;
vector<pair<int, int>> cur;
vector<pair<int, int>> nxt;

vector<vector<int>> board;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void get_input() {
    cout << "get_input()" << endl;

    int bl;
    int x, y;

    cin >> test_case;

    for(int i = 0; i < test_case; ++i) {
        cin >> bl;
        board_length.push_back(bl);

        cin >> x >> y;
        cur.push_back(make_pair(x, y));
        cin >> x >> y;
        nxt.push_back(make_pair(x, y));
    }

    if(debug_input) {
        cout << endl << "Test Case: " << test_case << endl;
        for(int i = 0; i < test_case; ++i) {
            cout << "Board length: " << board_length[i] << endl;
            cout << "Current pos: " << cur[i].first << " " << cur[i].second << endl;
            cout << "Next pos: " << nxt[i].first << " " << nxt[i].second << endl;
            cout << "==================================================" << endl;
        }
    }
}

void init() {
    board.
}

int main() {
    cout << "main()" << endl;
    
    get_input();

    return 0;
}