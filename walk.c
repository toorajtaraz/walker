#include "./ansi_code.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./linuxfs_dirs_walk.h"

void help() {
    printf(BRED);
    printf("'||      ||`      /.\\      '||     '||  //' '||''''| '||'''|,\n ");
    printf("||      ||      // \\\\      ||      || //    ||   .   ||   || \n");
    printf(" ||  /\\  ||     //...\\\\     ||      ||<<     ||'''|   ||...|' \n");
    printf("  \\\\//\\\\//     //     \\\\    ||      || \\\\    ||       || \\\\   \n");
    printf("   \\/  \\/    .//       \\\\. .||...| .||  \\\\. .||....| .||  \\\\.\n");
    printf(reset);
    printf("for indentifing path to walk use -D:\n");
    printf("===> -D /home\n");
    printf("for configuring maximum depth use -d:\n");
    printf("===> -d 200\n");
    printf("for help use -h\n");
}
int main(int argc, char *argv[]) {
    char *walk_directory = malloc(sizeof(*walk_directory) * 100);
    strcpy(walk_directory, ".");
    int depth = 10;
    int opt;

    while((opt = getopt(argc, argv, ":D:d:h")) != -1){
        switch(opt){
            case 'D':
                    strcpy(walk_directory, optarg);
                    printf("walking in %s\n", walk_directory);
                    break;
            case 'd':{
                    char digit = optarg[0];
                    for(int i = 0; optarg[i] != ' '; i++){ 
                        digit = optarg[i];
                        if(i > strlen(optarg) || isdigit(digit)) break;
                    }
                    if(isdigit(digit)) {
                        sscanf(optarg, "%d", &depth);
                    }
                    else {
                        printf(BRED);
                        printf("BAD INPUT: %s\n", optarg);
                        printf(reset);
                        return -1;
                    }
                    break;
                }
            case 'h':
                help();
                return 0;
        }
    }

    walk_dirs(walk_directory, 4, 0, depth);
    free(walk_directory);
    return 0;
}
