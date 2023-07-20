#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define INT_MAX 2147483647

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
char f_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
int f_eputchar(char c);
void f_eputs(char *str);
int f_writefd(char c, int fd);
int f_putsfd(char *str, int fd);
int show_help(shell_data_t *shell_data);
int change_directory(shell_data_t *shell_data);
int exit_shell(shell_data_t *shell_data);
char *_strchr(const char *s, char c);
char *_strncat(char *dest, const char *src, int n);
char *_strncpy(char *dest, const char *src, int n);
int custom_atoi(const char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
