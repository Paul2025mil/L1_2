#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII-only frame symbols
const char *frame[] = {
    "+", // top-left
    "-", // horizontal
    "+", // top-right
    "|", // vertical
    "+", // bottom-left
    "+"  // bottom-right
};

// Lines and labels
const char *line[] = {
    "------------------------------",
    "Result:"
};

// Header function
void printHeader(const char *title) {
    int width = 50;
    int pad = (width - strlen(title)) / 2;

    // Top frame
    printf("%s", frame[0]);
    for (int i = 0; i < width; i++) printf("%s", frame[1]);
    printf("%s\n", frame[2]);

    // Centered title
    printf("%s", frame[3]);
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", title);
    for (int i = 0; i < width - pad - strlen(title); i++) printf(" ");
    printf("%s\n", frame[3]);

    // Bottom frame
    printf("%s", frame[4]);
    for (int i = 0; i < width; i++) printf("%s", frame[1]);
    printf("%s\n", frame[5]);
}

// Result output function
void printResult(double x, double y) {
    printf("\n%s\n", line[1]);
    printf("%s\n", line[0]);
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);
    printf("%s\n", line[0]);
}

int main() {
    double x, y;
    char input[100];

    printHeader("Function calculation: y = x^2 + 2x + 1");

    printf("Enter value for x: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error: failed to read input.\n");
        return 1;
    }

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Try to parse the number
    if (sscanf(input, "%lf", &x) != 1) {
        printf("Error: invalid input. Please enter a number.\n");
        return 1;
    }

    y = x * x + 2 * x + 1;

    printResult(x, y);

    return 0;
}
