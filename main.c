#include <stdio.h>
#include <stdlib.h>

#define P(x) x##x
#define KEY 0x3A
#define U unsigned
#define F float
#define forever for(;;)

typedef void (*vfn)();

void ___(char *s) {
    while (*s) putchar(*s++);
}

void decode(char *s, int len) {
    for (int i = 0; i < len; i++)
        s[i] ^= KEY;
}

void entropy() {
    char msg[] = { 'R'^KEY, 'O'^KEY, 'W'^KEY, 'T'^KEY, '!'^KEY, '\0' };
    decode(msg, 5);
    ___(msg);
}

void *(dispatch(const char *tag)) {
    static void *labels[] = { &&one, &&two, &&three };
    int h = (tag[0] + tag[1]) % 3;
    goto *labels[h];
one:
    entropy();
    return NULL;
two: {
    char s[] = { 'h'^KEY, 'e'^KEY, 'l'^KEY, 'l'^KEY, 'o'^KEY, ' '^KEY,
                 'w'^KEY, 'o'^KEY, 'r'^KEY, 'l'^KEY, 'd'^KEY, '\0'^KEY };
    decode(s, sizeof(s)-1);
    ___(s);
    puts("");
    return NULL;
}
three:
    {
        int i = 0;
        while (i < 1) {
            void (*f)() = entropy;
            f();
            i++;
        }
    }
    return NULL;
}

int main() {
    char *codes[] = { "a1", "b2", "c3" };
    for (int i = 0; i < 3; i++)
        dispatch(codes[i]);
    return 0;
}
