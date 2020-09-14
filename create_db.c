#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "db.h"


void create_data(char* type, char* path, char* name, char* data) {
    int len;
    int i = 1;
    int j = 0;
    data[0] = '[';
    len = strlen(type);
    for (; j < len;) {
        data[i++] = type[j++];
    }
    data[i++] = ']';
    j = 1;
    len = strlen(path);
    for (; j < len;) {
        data[i++] = path[j++];
    }
    j = 0;
    if (data[i-1] != '/') {
        data[i++] = '/';
    }
    len = strlen(name);
    for (; j < len;) {
        data[i++] = name[j++];
    }
    data[i] = '\0';
}

int creat_db(char *path) {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    fd = open("/tmp/walker.db", O_WRONLY | O_APPEND, mode);
    if (fd < 0) {
        printf("\n\nsomething went wrong...\n\n");
        close(fd);
        exit(fd);
    }
    write(fd, path, sizeof(char) * 255);
    write(fd, "\n", sizeof(char));
    close(fd);
    return fd;
}

void walk_query(char *dir_name, char *data){
    DIR *directory;
    struct dirent *entry;
    int dir_in_count = 0;
    int dir_in_dir = 0;
    if(!(directory = opendir(dir_name))) {
        return;
    }
    while ((entry = readdir(directory)) != NULL) {
        switch (entry->d_type) {
            case DT_DIR:{
                char path[1024];
                if(!strcmp(entry->d_name,".") || !strcmp(entry->d_name, ".."))
                    continue;
                snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
                create_data("directory\0", path, "\0", data);
                creat_db(data);
                walk_query(path, data);
                break;
            }
            case DT_BLK:{
                        create_data("BLOCK DEVICE\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
            case DT_CHR:{
                        create_data("CHAR DEVICE\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
            case DT_FIFO:{
                        create_data("FIFO\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
            case DT_LNK:{
                        create_data("SYMBOLIC LINK\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
            case DT_REG:{
                        create_data("FILE\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
            case DT_SOCK:{
                        create_data("UNIX DOMAIN SOCKET\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
            case DT_UNKNOWN:{
                        create_data("UNKNOWN\0", dir_name, entry->d_name, data);
                        creat_db(data);
                        break;
                }
        }
    }
    closedir(directory);
}
void run () {
    char *data = malloc(sizeof(char) * 2000);
    if (!data) {
        printf("\n\nsomething went wrong!\n\n");
        exit(-1);
    }
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    fd = open("/tmp/walker.db", O_WRONLY | O_CREAT | O_TRUNC, mode);
    close(fd);
    walk_query("/", data);
}

int read_line(int fd, char *line) {
    char c = ' ';
    int i = 0;
    while (c != '\n') {
        if (read(fd, &c, sizeof(char)) == 0) {
            return -1;
        }
        line[i++] = c;
    }
    line[i] = '\0';
    return 0;
}


void _search (char *search_str_ws) {
    char search_str[1024];
    int j = 0;
    for (int i = 0; i < strlen(search_str_ws);) {
        if (search_str_ws[i] != ' ' || search_str_ws[i-1] == 92) {
           if (search_str_ws[i] != 92)
                search_str[j++] = search_str_ws[i];
        }
        i++;
    }
    search_str[j] = '\0';
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    fd = open("/tmp/walker.db", O_RDONLY, mode);
    char *line = malloc(sizeof(char)*2000);
    if (!line) {
        printf("\n\nsomething went wrong...\n\n");
        exit(-1);
    }
    
    while (read(fd, line, sizeof(char)*256)) {
        if (strstr(line, search_str) != NULL) {
            puts(line);
        }
    }
    close(fd);
}
