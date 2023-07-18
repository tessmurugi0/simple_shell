#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

typedef struct info
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int line_count_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf;
    int cmd_buf_type;
    int readfd;
    int histcount;
} info_t;

int mode(info_t *info);
int isdelimeter(char c, char *delimeter);
int isalpha(int c);
int _atoi(char *s);
int f_strlen(char *s);
int f_strcmp(char *s, char *t);
char *f_starts_with(const char *haystack, const char *needle);
char *f_strcat(char *destination, char *source);
char *f_strcpy(char *dst, char *src);

#endif