#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

const double pi = std::acos(-1);
typedef std::complex<double> base;

void fft(std::vector<base>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * pi / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}

void multiply(const std::vector<long long>& a, const std::vector<long long>& b, std::vector<long long>& res) {
    std::vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < std::max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];

    fft(fa, true);
    res.resize(n);
    for (int i = 0; i < n; ++i)
        res[i] = (long long)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
    int n1, n2, n3;
    std::vector<long long> v1(60001, 0), v2(60001, 0), v3(60001, 0);
    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i) {
        int x;
        scanf("%d", &x);
        ++v1[x + 30000];
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; ++i) {
        int x;
        scanf("%d", &x);
        ++v2[x + 30000];
    }
    scanf("%d", &n3);
    for (int i = 0; i < n3; ++i) {
        int x;
        scanf("%d", &x);
        ++v3[x + 30000];
    }

    std::vector<long long> mult;
    multiply(v1, v3, mult);

    long long answer = 0;
    for (int i = 0; i < (int)mult.size(); i += 2)
    {
        if (mult[i] && i/2 < (int)v2.size() && v2[i/2] > 0)
        {
            answer += mult[i];
        }
    }

    printf("%lld", answer);
}