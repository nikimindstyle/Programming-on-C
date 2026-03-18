#include <stdio.h>

int main() {
    char c;
    int i;
    for (i = 0; i < 80; i++) {
        c = getchar();
        if (c == 'a') c = 'A';
        else if (c == 'b') c = 'B';
        
        putchar(c);
    }
    return 0;
}
