#include <iostream>

using namespace std;

int A[6], B[6];

int main() {
    for (int i = 0; i < 6; i++) cin >> A[i];
    for (int i = 0; i < 6; i++) cin >> B[i];

    int ret = 0, low = 36;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (A[i] > B[j]) ret++;
        }
    }
    
    if (ret != 0) {
        for (int i = 2; i < 10; i++) {
            while ((ret % i) == 0 && (low % i) == 0) {
                ret /= i;
                low /= i;
            } 
        }
    }
    cout << ret << '/' << low << '\n';
}


