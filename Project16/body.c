#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// check if the expression is valid (evaluates to 24)
int is_valid(double a, double b, double c, double d, char op1, char op2, char op3) {
    double res = 0;
    if (op1 == '+') res = a + b;
    else if (op1 == '-') res = a - b;
    else if (op1 == '*') res = a * b;
    else if (op1 == '/') res = a / b;

    if (op2 == '+') res = res + c;
    else if (op2 == '-') res = res - c;
    else if (op2 == '*') res = res * c;
    else if (op2 == '/') res = res / c;

    if (op3 == '+') res = res + d;
    else if (op3 == '-') res = res - d;
    else if (op3 == '*') res = res * d;
    else if (op3 == '/') res = res / d;

    if (fabs(res - 24) < 0.0001) return 1;
    else return 0;
}

// find all combinations of cards that evaluate to 24
void find_24_point_combinations(double cards[]) {
    char ops[] = { '+', '-', '*', '/' };
    int found = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                for (int l = 0; l < 4; l++) {
                    if (l == i || l == j || l == k) continue;
                    for (int op1 = 0; op1 < 4; op1++) {
                        for (int op2 = 0; op2 < 4; op2++) {
                            for (int op3 = 0; op3 < 4; op3++) {
                                if (is_valid(cards[i], cards[j], cards[k], cards[l], ops[op1], ops[op2], ops[op3])) {
                                    printf("%d %c %d %c %d %c %d\n", (int)cards[i], ops[op1], (int)cards[j], ops[op2], (int)cards[k], ops[op3], (int)cards[l]);
                                    found = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (!found) printf("No combination found\n");
}

int main() {
    double cards[4];
    char input[4][4];
    printf("Enter 4 card values: ");
    int i = 0;
    for (i=0; i < 4; i++) {
        scanf("%s", input[i]);
        if (strcmp(input[i], "A") == 0) cards[i] = 1;
        else if (strcmp(input[i], "J") == 0) cards[i] = 11;
        else if (strcmp(input[i], "Q") == 0) cards[i] = 12;
        else if (strcmp(input[i], "K") == 0) cards[i] = 13;
        else cards[i] = atof(input[i]);
    }
    find_24_point_combinations(cards);
    return 0;
}
//KONGKONG 2023.1.11
//均采用 CC BY - NC - SA 4.0 许可协议
