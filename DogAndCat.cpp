////
//// Created by chenr5-INS on 11/12/2021.
////
//
//#include <cstdio>
//#include <string>
//#include <cstring>
//
//const int MAXN = 10005;
//int T, N, C, D, M, sum[MAXN];
//char s[MAXN];
//
////int main() {
////    scanf("%d", &T);
////    int x = 0;
////    bool flag = false;
////    while (T--) {
////        ++x;
////        flag = false;
////        std::memset(s, 0, sizeof(s));
////        std::memset(sum, 0, sizeof(sum));
////        scanf("%d%d%d%d", &N, &D, &C, &M);
////        scanf("%s", s);
////        for (int i = N - 1; i >= 0; --i) sum[i] = sum[i + 1] + (s[i] == 'D');
//////        for (int i = 0; i < N; ++i) printf("DEBUG:%d ", sum[i]);
//////        puts("");
////        for (int i = 0; i < N; ++i) {
////            if (!sum[i]) break;
////            if (s[i] == 'C') {
////                if (C) --C;
////                else {
////                    printf("Case #%d: NO\n", x);
////                    flag = true;
////                    break;
////                }
////            } else {
////                if (D) {
////                    --D;
////                    C += M;
////                } else {
////                    printf("Case #%d: NO\n", x);
////                    flag = true;
////                    break;
////                }
////            }
////        }
////        if (!flag) printf("Case #%d: YES\n", x);
////    }
////}
