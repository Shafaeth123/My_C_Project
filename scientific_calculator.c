#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FILE_NAME "results.txt"

void saveResult(double result) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%.2lf\n", result);
    fclose(file);
}

void viewResults() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No results to display.\n");
        return;
    }
    char line[50];
    printf("\n--- Previous Results ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void decimalConversion() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Binary: %b\nHexadecimal: %x\nOctal: %o\n", num, num, num);
    saveResult((double)num);
}

void trigonometricFunction() {
    double angle;
    printf("Enter angle in radians: ");
    scanf("%lf", &angle);
    printf("sin: %.2lf, cos: %.2lf, tan: %.2lf\n", sin(angle), cos(angle), tan(angle));
    saveResult(sin(angle));
    saveResult(cos(angle));
    saveResult(tan(angle));
}

void factorial() {
    int num;
    unsigned long long fact = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; ++i) {
        fact *= i;
    }
    printf("Factorial of %d = %llu\n", num, fact);
    saveResult((double)fact);
}

void permutation() {
    int n, r;
    printf("Enter n and r for P(n, r): ");
    scanf("%d%d", &n, &r);
    double perm = tgamma(n + 1) / tgamma(n - r + 1);
    printf("P(%d, %d) = %.2lf\n", n, r, perm);
    saveResult(perm);
}

void polynomialAddition() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    double poly1[degree + 1], poly2[degree + 1], sum[degree + 1];
    printf("Enter coefficients for polynomial 1: ");
    for (int i = 0; i <= degree; i++) {
        scanf("%lf", &poly1[i]);
    }
    printf("Enter coefficients for polynomial 2: ");
    for (int i = 0; i <= degree; i++) {
        scanf("%lf", &poly2[i]);
    }
    for (int i = 0; i <= degree; i++) {
        sum[i] = poly1[i] + poly2[i];
    }
    printf("Result: ");
    for (int i = 0; i <= degree; i++) {
        printf("%.2lf ", sum[i]);
        saveResult(sum[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char continueCalc;
    do {
        printf("\nScientific Calculator Options:\n");
        printf("1. Decimal Conversion\n");
        printf("2. Trigonometric Function\n");
        printf("3. Factorial\n");
        printf("4. Permutation\n");
        printf("5. Polynomial Addition\n");
        printf("6. View Results\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: decimalConversion(); break;
            case 2: trigonometricFunction(); break;
            case 3: factorial(); break;
            case 4: permutation(); break;
            case 5: polynomialAddition(); break;
            case 6: viewResults(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueCalc);
    } while (continueCalc == 'y' || continueCalc == 'Y');

    printf("Exiting calculator.\n");
    return 0;
}
