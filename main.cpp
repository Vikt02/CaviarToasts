#include <iostream>
#include <queue>
#include "main.h"

#define f first
#define s second

using namespace std;

point q[1000000];
int en = 0, st = 0;

void push (const point& x) {
    q[en] = x;
    en++;
}

bool empty () {
    return en == st;
}

point front () {
    return q[st];
}

void pop () {
    st++;
}

bool point_in_triangl(point point, struct point pPoint[3]) {
    int n = 3;
    for (int i = 1; i <= n; i++) {
        vekt v1(point, pPoint[i % n]);
        vekt v2
    }
}

int main() {

    int n;
    double c1, c2;
    cin >> n >> c1 >> c2;

    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        push({a, b});
    }

    int n1 = n - 3;

    while (n1) {
        n1--;
        point a[3];
        a[0] = q[st];
        a[1] = q[st + 1];
        a[2] = q[en - 1];

        for (int i = st + 2; i < en - 2; i++) {
            point_in_triangl(q[i], a);
        }
    }
    return 0;
}
