#include <cmath>
#include <cstdio>

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = sqrt(b * b - 4 * a * c);
    double x1 = (-b - d) / (2 * a);
    double x2 = -2 * c / (b + d);

    printf("%.8e %.8e\n", x1, x2);

    return 0;
}
