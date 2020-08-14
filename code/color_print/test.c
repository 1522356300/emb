#include <stdio.h>
#include "color_print.h"


int main(void)
{
    COLOR_PRINT(RED,"hello,world, %d\n", 123);
    printf(COLOR_CTL(GREEN,"hello,world, %d\n"), 123);
    printf(COLOR_CTL_ex(YELLOW_bg, CYAN, "wish you %d "), 888);
    printf("hello,world\n");
    return 0;
}