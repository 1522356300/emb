#ifndef __COLOR_PRINT_H__
#define __COLOR_PRINT_H__
/**
 * @file    color_print.h
 * @note    1、两种使用方式：
 *              1）printf(COLOR_CTL(READ, "hello,world. %s\n"), "cool?"); //可采用自定打印接口
 *              2）COLOR_PRINT(READ, "this is %d", 666666); //默认采用printf接口
 *              3) COLOR_CTL_ex 可用于同时控制背景色、字体颜色
 * @author  Pengsj      2020.08.14      create
 */

//define: font color, background color 
#define BLACK       30
#define BLACK_bg    40
#define RED         31  // red font
#define RED_bg      41  // red background 
#define GREEN       32
#define GREEN_bg    42
#define YELLOW      33
#define YELLOW_bg   43
#define BLUE        34
#define BLUE_bg     44
#define PURPLE      35  //蓝色
#define PURPLE_bg   45
#define CYAN        36  //紫色
#define CYAN_bg     46  
#define GRAY        37  //灰白色
#define GRAY_bg     47

//interface to use up color definition
#define COLOR_START(color)                  "\033[1;" #color "m"
#define COLOR_START_ex(color, color_bg)     "\033[1;"#color";"#color_bg"m"
#define COLOR_END                           "\033[0m"

#define COLOR_CTL(color, fmt)               COLOR_START(color) fmt COLOR_END
#define COLOR_CTL_ex(color, color_bg, fmt)  COLOR_START_ex(color, color_bg) fmt COLOR_END

#define COLOR_PRINT_START(color)    {printf(COLOR_START(color));}
#define COLOR_PRINT_END             {printf(COLOR_END);}
#define COLOR_PRINT(color, ...) {\
            COLOR_PRINT_START(color);\
            printf(__VA_ARGS__);\
            COLOR_PRINT_END;\
        }

#endif