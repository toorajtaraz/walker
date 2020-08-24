#include <stdio.h>
#include "./ansi_code.h"
void generic_print(int indent, char *type, char *name){

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
