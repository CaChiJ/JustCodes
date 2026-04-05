#include <stdio.h>


int main(void) {
    printf("hihi %d %d", !((0x7FFFFFFF ^ -1) + (0x7FFFFFFF ^ -1)), !234324);
    return 0;

}