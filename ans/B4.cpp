#include <cstdio>

int ret[101] = {1,   1,   2,   6,   24,  120, 720, 504, 403, 362, 362, 399, 479, 622, 871,
                130, 209, 355, 640, 121, 243, 510, 112, 258, 620, 155, 403, 108, 304, 884,
                265, 822, 263, 868, 295, 103, 371, 137, 523, 203, 815, 334, 140, 604, 265,
                119, 550, 258, 124, 608, 304, 155, 806, 427, 230, 126, 710, 405, 235, 138,
                832, 507, 314, 198, 126, 824, 544, 364, 248, 171, 119, 850, 612, 447, 330,
                248, 188, 145, 113, 894, 715, 579, 475, 394, 331, 281, 242, 210, 185, 165,
                148, 135, 124, 115, 108, 103, 991, 961, 942, 933, 933};

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", ret[n]);
    return 0;
}
