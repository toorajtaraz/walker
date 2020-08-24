#include <stdio.h>
#include "./ansi_code.h"
#include "./print_color.h"

void generic_print(int indent, char *type, char *name){
   if(type[0] == 'D'){
        printf("%*s[%s]\n", indent, "", name);
   }
  else {
        printf("%*s-|%s| %s\n", indent, "", type, name);
   } 
}
void white_print(int indent, char *type, char *name){
    printf(WHT);
    generic_print(indent, type, name);
    printf(reset);
}
void red_print(int indent, char *type, char *name){
    printf(RED);
    generic_print(indent, type, name);
    printf(reset);
}
void green_print(int indent, char *type, char *name){
    printf(GRN);
    generic_print(indent, type, name);
    printf(reset);
}
void blue_print(int indent, char *type, char *name){
    printf(BLU);
    generic_print(indent, type, name);
    printf(reset);
}
void bold_print(int indent, char *type, char *name){
    printf(BHWHT);
    generic_print(indent, type, name);
    printf(reset);
}
