#include <cstdio>
#include <algorithm>

//
// Created by chenr5-INS on 11/12/2021.
//
const int N = 1e5+10;
const int INF = 1e9;
int Ts, n, ansx, ansy, sum;
struct Seg {
    int x1, x2;
} x[N], y[N], x1arr[N], x2arr[N];

int bef(int cur, Seg arr[]) {
    //find how many segments that x2 < cur
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (arr[mid].x2 < cur) ans = mid, l = mid + 1;
        else r = mid - 1;
//        printf("DEBUG bef: l:%d r:%d ans:%d mid:%d cur:%d arr[mid].x2:%d\n", l, r, ans, mid, cur, arr[mid].x1);
    }
    return ans;
}

int nxt(int cur, Seg arr[]) {
    //find how many segments that x1 > cur
    //wtf if n == 1???
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (arr[mid].x1 > cur)ans = n - mid + 1, r = mid - 1; // it's n-mid+1 not mid fuck mother fucker!!!!!!!!!!!
        else l = mid + 1;
//        printf("DEBUG NXT: l:%d r:%d ans:%d mid:%d cur:%d arr[mid].x1:%d\n", l, r, ans, mid, cur, arr[mid].x1);
    }
    return ans;
}

bool x1sort(Seg x, Seg y) {
    return x.x1 < y.x1;
}

bool x2sort(Seg x, Seg y) {
    return x.x2 < y.x2;
}

int getsum(int cur, Seg x[]) {
    int now = 0;
    for (int i = 1; i <= n; ++i) {
        if (cur >= x[i].x1 && cur <= x[i].x2) continue;
        now += std::min(abs(cur - x[i].x1), abs(cur - x[i].x2));
    }
    return now;
}

int main() {
    //Complexity is O(T(log(1e9)log(n)+nlogn)=O(nlogn)
    scanf("%d", &Ts);
    for (int q = 1; q <= Ts; ++q) {
        sum = INF;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &x[i].x1, &y[i].x1, &x[i].x2, &y[i].x2);
        }
        for (int i = 1; i <= n; ++i) {
            x1arr[i] = x[i];
            x2arr[i] = x[i];
        }
        std::sort(x + 1, x + 1 + n, x1sort);
        for (int i = 1; i <= n; ++i)std::swap(x[i], x1arr[i]);
        std::sort(x + 1, x + n + 1, x2sort);
        for (int i = 1; i <= n; ++i)std::swap(x[i], x2arr[i]);

//        for (int i = 1; i <= n; ++i)printf("DEBUGSORT:%d %d %d %d\n", x1arr[i].x1, x1arr[i].x2, x2arr[i].x1, x2arr[i].x2);
        int l = -INF, r = INF;
        //get ansx first since they are independent
        while (l <= r) {
            int mid = l + r >> 1;
//            printf("DEBUGX: l:%d mid:%d r:%d ansx:%d bef:%d nxt:%d\n", l, mid, r, ansx,bef(mid, x2arr),nxt(mid, x1arr));
            if (bef(mid, x2arr) < nxt(mid, x1arr)) {
                if (getsum(mid, x) < sum || (getsum(mid, x) == sum && mid < ansx)) sum = getsum(mid, x), ansx = mid;
                l = mid + 1;
            } else {
                if (getsum(mid, x) < sum || (getsum(mid, x) == sum && mid < ansx)) sum = getsum(mid, x), ansx = mid;
                r = mid - 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            x1arr[i] = y[i];
            x2arr[i] = y[i];
        }
        sum = INF;
        std::sort(y + 1, y + n + 1, x1sort);
        for (int i = 1; i <= n; ++i)std::swap(y[i], x1arr[i]);
        std::sort(y + 1, y + n + 1, x2sort);
        for (int i = 1; i <= n; ++i)std::swap(y[i], x2arr[i]);

//        for (int i = 1; i <= n; ++i)printf("DEBUGSORT:x1sorted(%d %d) x2sorted(%d %d)\n", x1arr[i].x1, x1arr[i].x2, x2arr[i].x1, x2arr[i].x2);
        l = -INF, r = INF;
        while (l <= r) {
            int mid = l + r >> 1;
//            printf("DEBUGY: l:%d mid:%d r:%d ansy:%d bef:%d nxt:%d\n", l, mid, r, ansy,bef(mid, x2arr),nxt(mid, x1arr));
            if (bef(mid, x2arr) < nxt(mid, x1arr)) {
                if (getsum(mid, y) < sum || (getsum(mid, y) == sum && mid < ansy)) sum = getsum(mid, y), ansy = mid;
                l = mid + 1;
            } else {
                if (getsum(mid, y) < sum || (getsum(mid, y) == sum && mid < ansy)) sum = getsum(mid, y), ansy = mid;
                r = mid - 1;
            }
        }
        printf("Case #%d: %d %d\n", q, ansx, ansy);
    }
}