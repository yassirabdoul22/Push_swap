#include "../../includes/stack.h"


#define BUFFER_SIZE 32

void ft_fr(char *ptr)
{
    if (ptr)
        free(ptr);
}

char *read_operations(int fd)
{
    char tmp[BUFFER_SIZE + 1];
    int r;
    char *res = NULL;

    while ((r = read(fd, tmp, BUFFER_SIZE)) > 0)
    {
        tmp[r] = '\0';
        res = ft_strjoin(res, tmp);
        if (!res) return NULL;
    }
    if (r < 0)
    {
        ft_fr(res);
        return NULL;
    }
    return res;
}

char *extract_operation(char *buffer)
{
    char *newline = strchr(buffer, '\n');
    if (!newline)
        return NULL;

    int len = newline - buffer;
    if (len <= 0)
        return NULL;

    char *op = calloc(len + 1, 1);
    if (!op)
        return NULL;

    strncpy(op, buffer, len);
    return op;
}

char *update_buffer(char *buffer)
{
    char *newline = strchr(buffer, '\n');
    if (!newline)
        return NULL;

    char *tmp = strdup(newline + 1);
    ft_fr(buffer);
    return tmp;
}

char *get_next_operation_from_buffer(char **buffer)
{
    if (!*buffer || !**buffer)
        return NULL;

    char *op = extract_operation(*buffer);
    if (!op)
    {
        ft_fr(*buffer);
        *buffer = NULL;
        return NULL;
    }

    *buffer = update_buffer(*buffer);
    return op;
}

void execute_operations(stack **a, stack **b)
{
    char *buffer = read_operations(STDIN_FILENO);
    if (!buffer || !*buffer)
            return;
    char *op;
    while ((op = get_next_operation_from_buffer(&buffer)) != NULL)
    {
        if (!apply_operation(a, b, op))
        {
            write(2, "Error\n", 6);
            ft_fr(op);
            break;
        }
        ft_fr(op);
    }
    ft_fr(buffer);
}
