#include <iostream>
#include <string>

using namespace std;

int solve(int A, int B) {
    int cnt = 0;
    for(int i = A; i <= B; ++i) {
        string str = to_string(i);
        bool flag = true;
        for(int j = 0; j < str.length(); ++j) {
            if(str[j] != '4' && str[j] != '7') {
                flag = false;
                break;
            }
        }
        if(flag == true) ++cnt;
    }

    return cnt;
}

int main() {
    int A, B;

    cin >> A >> B;

    cout << solve(A, B) << endl;

    return 0;
}