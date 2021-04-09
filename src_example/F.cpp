#include <cstdio>
using namespace std;

const int MAX_X = 50005000;

class Collatz {
  private:
    /* ↓ここを編集する． */

    /* ↑ここを編集する． */

  public:
    Collatz(int x);
    int step();
    bool shouldProceed();
    void leaveFootprint();
    int getX();
};

/* ↓ここを編集する． */

/* ↑ここを編集する． */

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