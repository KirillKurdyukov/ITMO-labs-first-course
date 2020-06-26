#include <stdio.h>
#include <stdlib.h>

int modul(int a) {
    int abs = (a >> 31);
    int t = a ^ abs;
    return t - abs;
}
int maxValue(int a, int b) {
    return (a + b + modul(a - b)) / 2;
}
int minValue(int a, int b) {
    return (a + b - modul(a - b)) / 2;
}

int main() {
    int a, b, c;
    scanf("%i%i%i", &a, &b, &c);

    printf("%i", modul(b));
    return 0;
}
