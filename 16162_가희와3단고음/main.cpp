#include <iostream>
#include <vector>

using namespace std;

/*
    [문제 설명]
    1옥타브 도: 1
    음 A 부터 D 음씩 올린다. -> 첫항 A, 공차 D인 등차수열, 항의 개수 X
    X단 고음 중 가장 큰 X를 구한다.

    [알고리즘]
    
    [풀이]
    1. 입력 받음
    2. 등차수열의 첫항과 음계가 일치하는 지점 찾음
    3. 해당 지점부터 공차만큼 올라가면서 주어진 악보와 몇번 일치하는지 반환
*/

int num;
int A, D;

vector<int> vec;

int cnt=0;
int stt=-1;
int cur;

int main() {
    // Input
    // cout << "Input" << endl;
    cin >> num >> A >> D;
    vec.resize(num);
    for(int i = 0; i < num; ++i) {
        cin >> vec[i];
    }

    // cout << "Find first note" << endl;
    for(int i = 0; i < num; ++i) {
        if(vec[i]==A) {
            ++cnt;
            stt=i;
            break;
        }
    }

    // cout << "solve" << endl;
    cur = A+D;
    for(int i = stt+1; i < num; ++i) {
        if(stt==-1) break; // 예외 처리해주니 풀린다.
        if(cur==vec[i]) {
            cur += D;
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}