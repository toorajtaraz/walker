#include "./headers/linuxfs_dirs_walk.h"
#include "./headers/print_color.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void walk_dirs(char *dir_name, int indent, int current_depth, int depth){
    DIR *directory;
    struct dirent *entry;
    int dir_in_count = 0;
    int dir_in_dir = 0;
    if(!(directory = opendir(dir_name))) {
        red_print(indent, "NO FILE OR DIR FOUND\0", "");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        switch (entry->d_type) {
            case DT_DIR:{
                char path[1024];
                if(!strcmp(entry->d_name,".") || !strcmp(entry->d_name, "..")) 
                    continue;
                dir_in_dir++;
                snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
                bold_print(indent, "DIR\0", entry->d_name);
                if(current_depth < depth)
                    walk_dirs(path, indent + 2, current_depth + 1, depth);
                break;
            }
            case DT_BLK:{
                        green_print(indent, "BLOCK DEVICE\0", entry->d_name);
                        dir_in_count++;
                        break;
                }
            case DT_CHR:{
                        green_print(indent, "CHAR DEVICE\0", entry->d_name);
                         dir_in_count++;
                        break;
                }
            case DT_FIFO:{
                        red_print(indent, "FIFO\0", entry->d_name); 
                        dir_in_count++;
                        break;
                }
            case DT_LNK:{
                        light_blue_print(indent, "SYMBOLIC LINK\0", entry->d_name);
                        dir_in_count++;
                        break;
                }
            case DT_REG:{
                        blue_print(indent, "FILE\0", entry->d_name);
                        dir_in_count++;
                        break;
                }
            case DT_SOCK:{
                        red_print(indent, "UNIX DOMAIN SOCKET\0", entry->d_name); 
                        dir_in_count++;
                        break;
                }
            case DT_UNKNOWN:{
                        bold_red_print(indent, "UNKNOWN\0", entry->d_name); 
                        dir_in_count++;
                        break;
                }
        }
    }
    if(dir_in_count == 0 && dir_in_dir == 0)
        red_print(indent, "NO FILE OR DIR FOUND\0", "");
    closedir(directory);
}
