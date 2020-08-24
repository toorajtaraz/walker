#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void walk_dirs(char *dir_name, int indent) {
    DIR *directory;
    struct dirent *entry;

    if(!(directory = opendir(dir_name)))
        return;

    while ((entry = readdir(directory)) != NULL) {
        switch (entry->d_type) {
            case DT_DIR:{
                char path[1024];
                if(!strcmp(entry->d_name,".") || !strcmp(entry->d_name, "..")) 
                    continue;
                snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
                printf("%*s[%s]\n", indent, "", entry->d_name);
                walk_dirs(path, indent + 2);
                break;
            }
            case DT_BLK:{
                        printf("%*s-|%s| %s\n", indent, "", "BLOCK DEVICE", entry->d_name);
                        break;
                }
            case DT_CHR:{
                        printf("%*s-|%s| %s\n", indent, "", "CHAR DEVICE", entry->d_name);
                        break;
                }
            case DT_FIFO:{
                        printf("%*s-|%s| %s\n", indent, "", "FIFO", entry->d_name); 
                        break;
                }
            case DT_LNK:{
                        printf("%*s-|%s| %s\n", indent, "", "SYMBOLIC LINK", entry->d_name);
                        break;
                }
            case DT_REG:{
                        printf("%*s-|%s| %s\n", indent, "", "FILE", entry->d_name);
                        break;
                }
            case DT_SOCK:{
                        printf("%*s-|%s| %s\n", indent, "", "UNIX DOMAIN SOCKET", entry->d_name); 
                        break;
                }
            case DT_UNKNOWN:{
                        printf("%*s-|%s| %s\n", indent, "", "UNKNOWN", entry->d_name); 
                        break;
                }
        }
    }
    closedir(directory);
}


int main(void) {
    walk_dirs(".", 0);
    return 0;
}
