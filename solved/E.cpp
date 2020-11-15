#include <iostream>

using namespace std;

int A[1000000];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    bool flag = false, answer = true;

    for (int i = 0; i < N - 1; i++) {
        if (flag) {
            if (A[i] == 0) {
                flag = true;
            } else if (A[i] == 1) {
                flag = false;
            } else if (A[i] == 2) {
                flag = true;
            } else {
                answer = false;
                break;
            }
        } else {
            if (A[i] == 0) {
                flag = false;
            } else if (A[i] == 1) {
                flag = true;
            } else {
                answer = false;
                break;
            }
        }
    }

    if (flag) {
        if (A[N - 1] != 1) answer = false; 
    } else {
        if (A[N - 1] != 0) answer = false;
    }

    if (answer) cout << "YES" << '\n';
    else cout << "NO" << '\n';

}


