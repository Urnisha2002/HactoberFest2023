#include <stdio.h>
#include <string.h>

char s[30];
int top = -1;

void push(char item) {
    s[++top] = item;
}

char pop() {
    return s[top--];
}

int pri(char ch) {
    if (ch == '^' || ch == '$')
        return 2;
    else if (ch == '*' || ch == '/')
        return 1;
    else if (ch == '+' || ch == '-')
        return 0;
}

int main() {
    char a[100], b[100], ch;
    int i = 0, j = 0, f;
    printf("Enter infix Expression: ");
    gets(a);

    while (a[i] != '\0') {
        if (a[i] == ' ') {
            i++;
        } else if ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
            b[j++] = a[i++];
        } else if (a[i] == '(') {
            push(a[i]);
            i++;
        } else if (a[i] == ')') {
            while ((ch = pop()) != '(')
                b[j++] = ch;
            i++;
        } else {
            f = 0;
            while (f != 1) {
                if (top == -1 || s[top] == '(' || pri(a[i]) > pri(s[top])) {
                    push(a[i++]);
                    f = 1;
                } else {
                    b[j++] = pop();
                }
            }
        }
    }

    while (top != -1) {
        b[j++] = pop();
    }

    b[j] = '\0';

    printf("Postfix Expression: %s\n", b);

    return 0;
}
