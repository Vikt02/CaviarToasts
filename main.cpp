#include <iostream>
#include <queue>
#include "main.h"
#include <iomanip>
#define f first
#define s second

using namespace std;

vector<point> q(1000000);
vector<point> t[1000000];

int en = 0, st = 0;
double c1, c2;


pair <double, vector<point>> rec(vector<point>& t, int deep) {
    if (deep > 0) {
        vector<point> r = maxRectangleInTriangle(t);
        double s = 1 + c1 * vekt(r[1], r[0]).len() * vekt(r[1], r[2]).len();
        double h = 4 * s / vekt(t[2], t[0]).len();
        double s1 = 1 + c2 * h * vekt(t[2], t[0]).len();
        vector<point> r1 = createRectangle(t[0], t[2], t[1], h);
        vector<point> r2;
        /*for (int i = 0; i < t.size(); i++) {
            cout << t[i].x << " " << t[i].y << "\n";
        }
        cout << "\n";
        cout << r1[0].x << " " << r1[0].y << " " << r1[2].x << " " << r1[2].y << "\n";*/
        r2.push_back(r1[0]);
        r2.push_back(r1[2]);
        return {s1, r2};
    }

    vector<point> r = maxRectangleInTriangle(t);
    double s = 1 + c1 * vekt(r[1], r[0]).len() * vekt(r[1], r[2]).len();
    double h = 4 * s / vekt(t[2], t[0]).len();
    double s1 = 1 + c2 * h * vekt(t[2], t[0]).len();
    vector<point> r1 = createRectangle(t[0], t[2], t[1], h);
    vector<point> r2;
    r2.push_back(r1[0]);
    r2.push_back(r1[2]);
    vector<point> t1, t2, t3;

    t1.push_back(t[0]);
    t1.push_back(r[0]);
    t1.push_back(r[3]);

    t2.push_back(t[1]);
    t2.push_back(r[0]);
    t2.push_back(r[1]);

    t3.push_back(t[2]);
    t3.push_back(r[1]);
    t3.push_back(r[2]);

    pair <double, vector<point>> rec1 = rec(t1, deep + 1);
    pair <double, vector<point>> rec2 = rec(t2, deep + 1);
    pair <double, vector<point>> rec3 = rec(t3, deep + 1);

    s += rec1.first + rec2.first + rec3.first;

    if (s > s1) {
        return {s1, r2};
    } else {
        vector<point> p = r;
        for (int i = 0; i < rec1.second.size(); i++)
            p.push_back(rec1.second[i]);
        for (int i = 0; i < rec2.second.size(); i++)
            p.push_back(rec2.second[i]);
        for (int i = 0; i < rec3.second.size(); i++)
            p.push_back(rec3.second[i]);
        return {s, p};
    }
}

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


int main() {

    int n;
    cin >> n >> c1 >> c2;

    cout << fixed << setprecision(9);

    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        push({a, b});
    }
    int n1 = n - 2, sz = n - 2;

    while (n1) {
        vector<point> a(3);
        a[0] = q[st];
        a[1] = q[st + 1];
        a[2] = q[en - 1];
        vekt v1(a[0], a[1]);
        vekt v2(a[0], a[2]);
       // cout << v1.vp(v2) << "\n";
        if (v1.vp(v2) > 0) {
            pop();
            push(a[0]);
        }
        bool ear = true;
        for (int i = st + 2; i < en - 1; i++) {
            if (pointInConvexPolygon(a, q[i])) {
                ear = false;
                break;
            }
        }
        if (ear) {
            pop();
            n1--;
            t[n1].push_back(a[0]);
            t[n1].push_back(a[1]);
            t[n1].push_back(a[2]);
        } else {
            pop();
            push(a[0]);
        }
    }
    vector<point> ans;
    for (int i = 0; i < sz; i++) {
        vector<point> p = rec(t[i], 1).second;
        for (int j = 0; j < p.size(); j++) {
            ans.push_back(p[j]);
        }
    }

    cout << ans.size() / 2 << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].x << " " << ans[i].y << " ";
        if (i % 2) {
            cout << "\n";
        }
    }
    return 0;
}

