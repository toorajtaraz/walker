#include <stdio.h>
#include "./ansi_code.h"
#include <string.h>
#include "./print_color.h"

void generic_print(int indent, char *type, char *name){
   if(type[0] == 'D'){
       for(int i = 0 ; i < indent ; i++)
           printf("-");
        printf("[%s]\n", name);
       for(int i = 0 ; i < indent + strlen(name) + 1; i++)
           printf(" ");
       printf("|\n");
   }
  else {
       for(int i = 0 ; i < indent ; i++)
           printf("-");
        printf("|%s| %s\n", type, name);
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

void bold_red_print(int indent, char *type, char *name){
    printf(BRED);
    generic_print(indent, type, name);
    printf(reset);
}
void light_blue_print(int indent, char *type, char *name){
    printf(CYN);
    generic_print(indent, type, name);
    printf(reset);
}
