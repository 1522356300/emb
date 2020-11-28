#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[])
{
    int ret, num;
    char str[128];
//    scanf("%0d", &num);
//    ret = printf("%d",num);
//    printf("%d\n", ret);

    //scanf("%s\n", str);
    //gets(&str);
//    fgets(str, 128, stdin);
    
    scanf("%[^\n]", str);
    
    printf("strlen: %d, %#x, %s\n", strlen(str), str[strlen(str)-1], str);

    
    return 0;
}