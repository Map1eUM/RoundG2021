#include <cstdio>
#include <algorithm>

//
// Created by chenr5-INS on 11/12/2021.
//
const int N = 1e5;
const int INF = 1e9;
int Ts, n, ansx, ansy;
struct Seg {
    int x1, x2;
} x[N], y[N], x1arr[N], x2arr[N];

int bef(int cur, Seg arr[]) {
    //find the seg i that x2 < cur and seg i+1 that x2 > cur.
    int l = 1, r = n, ans = 0;
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid].x2 <= cur) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

int nxt(int cur, Seg arr[]) {
    int l = 1, r = n, ans = 0;
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid].x1 >= cur)ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

bool x1sort(Seg x, Seg y) {
    return x.x1 < y.x1;
}

bool x2sort(Seg x, Seg y) {
    return x.x2 < y.x2;
}

int main() {
    //Complexity is O(T(log(1e9)log(n)+nlogn)=O(nlogn)
    scanf("%d", &Ts);
    for (int q = 1; q <= Ts; ++q) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &x[i].x1, &x[i].x2, &y[i].x1, &y[i].x2);

        }
        for (int i = 1; i <= n; ++i) {
            x1arr[i] = x[i];
            x2arr[i] = x[i];
        }
        std::sort(x + 1, x + 1 + n, x1sort);
        for (int i = 1; i <= n; ++i)std::swap(x[i], x1arr[i]);
        std::sort(x + 1, x + n + 1, x2sort);
        for (int i = 1; i <= n; ++i)std::swap(x[i], x2arr[i]);

        int l = -INF, r = INF;
        //get ansx first since they are independent
        while (l < r) {
            int mid = l + r >> 1;
            if (bef(mid, x2arr) < nxt(mid, x1arr))l = mid + 1;
            else ansx = mid, r = mid - 1;
        }
        for (int i = 1; i <= n; ++i) {
            x1arr[i] = y[i];
            x2arr[i] = y[i];
        }
        std::sort(y + 1, y + n + 1, x1sort);
        for (int i = 1; i <= n; ++i)std::swap(y[i], x1arr[i]);
        std::sort(y + 1, y + n + 1, x2sort);
        for (int i = 1; i <= n; ++i)std::swap(y[i], x2arr[i]);

        l = -INF, r = INF;
        while (l < r) {
            int mid = l + r >> 1;
            if (bef(mid, y) < nxt(mid, y))l = mid + 1;
            else ansy = mid, r = mid - 1;
        }
        printf("Case #%d: %d %d", q, ansx, ansy);
    }
}