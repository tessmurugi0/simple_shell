#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define INT_MAX 2147483647

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;



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

/**
 * struct liststr - singly linked list
 * @num: number field
 * @str: string
 * @next: next node
 */
typedef struct liststring
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;



int mode(info_t *info);
int isdelimeter(char c, char *delimeter);
int isalpha(int c);
void create_envi(char **envi);
void free_env(char **env);
int _atoi(char *s);
int f_strlen(char *s);
int f_strcmp(char *s, char *t);
char *f_starts_with(const char *haystack, const char *needle);
char *f_strcat(char *destination, char *source);
char *f_strcpy(char *dst, char *src);
char* f_strdup(const char *str);
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
int _myenv(info_t *info);
char *f_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);
int memfree(void** ptr);
int is_command(info_t* info, char* path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);
void release_list(list_t **start_ptr);
int delete_node_at_index(list_t **start_ptr, unsigned int position);
size_t print_list_strings(const list_t *head);
list_t *add_last_node(list_t **start_ptr, const char *text, int number);
list_t *add_new_node(list_t **start, const char *text, int number);
char *_custom_memset(char *dest, char ch, unsigned int n);
void custom_free_strings(char **str_arr);
void *_custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t count_list_nodes(const list_t *head);
char **convert_list_to_strings(list_t *start);
size_t print_custom_list(const list_t *head);
list_t *find_node_starts_with(list_t *start, char *search_prefix, char target_char);
ssize_t find_node_index(list_t *start, list_t *target_node);

#endif
