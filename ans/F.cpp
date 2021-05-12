#include <cstdio>
using namespace std;

const int MAX_X = 50005000;

class Collatz {
  private:
    int x;
    static bool stepped_on[MAX_X];

  public:
    Collatz(int x);
    int step();
    bool shouldProceed();
    void leaveFootprint();
    int getX();
};

Collatz::Collatz(int x) {
    this->x = x;
    stepped_on[1] = true;
}

int Collatz::step() {
    if ((x & 1) == 0) {
        x /= 2;
    } else {
        x *= 3;
        x += 1;
    }
    if (x >= MAX_X) {
        printf("Error: x=%d exceeded a limit\n", x);
        return 1;
    }
    return x;
}

bool Collatz::shouldProceed() {
    return !stepped_on[x];
}

void Collatz::leaveFootprint() {
    stepped_on[x] = true;
}

int Collatz::getX() {
    return x;
}

bool Collatz::stepped_on[MAX_X];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        Collatz collatz(x);
        printf("%d\n", collatz.getX());
        while (collatz.shouldProceed()) {
            collatz.leaveFootprint();
            printf("%d\n", collatz.step());
        }
    }

    return 0;
}