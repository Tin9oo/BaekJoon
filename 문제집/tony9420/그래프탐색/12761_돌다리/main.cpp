#include <iostream>
#include <climits>
#include <queue>

#define MAX_LENGTH 1e5 + 1

using namespace std;

int a;
int b;
int n;
int m;

vector<int> stone_bridge;
int min_jump = INT_MAX;

void get_input() {
    cin >> a;
    cin >> b;
    cin >> n;
    cin >> m;
}

void init() {
    stone_bridge = vector<int> (MAX_LENGTH, INT_MAX);
    stone_bridge[n] = 0;
}

int jump(int curpos, int method) {
    if(method==0) {
        return curpos+a;
    }
    else if(method==1) {
        return curpos-a;
    }
    else if(method==2) {
        return curpos+b;
    }
    else if(method==3) {
        return curpos-b;
    }
    else if(method==4) {
        return curpos+1;
    }
    else if(method==5) {
        return curpos-1;
    }
    else if(method==6) {
        return curpos*a;
    }
    else if(method==7) {
        return curpos*b;
    }
    return 0;
}

void bfs() {
    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int curpos = q.front();
        q.pop();

        if(n == m) {
            min_jump = 0;
            break;
        }

        for(int i = 0; i < 8; ++i) {
            int nxtpos = jump(curpos, i);
            if(0 <= nxtpos && nxtpos <= MAX_LENGTH) {
                if(stone_bridge[curpos]+1 < stone_bridge[nxtpos]) {
                    stone_bridge[nxtpos] = stone_bridge[curpos]+1;
                    q.push(nxtpos);
                }

                if(nxtpos == m) {
                    min_jump = min(stone_bridge[nxtpos], stone_bridge[m]);
                }
            }
        }
    }
}

int main() {
    get_input();
    init();

    bfs();

    cout << min_jump << endl;

    return 0;
}