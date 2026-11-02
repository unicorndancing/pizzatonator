#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_list
{
void *data;
struct s_list *next;
} t_list;

int     ft_strlen(char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
char    *ft_strdup(const char *s);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
char *    ft_atoi_base(char *str, char *base);


static void test_strlen(void)
{
    printf("\n========== STRLEN ==========\n");

    printf("empty:\n");
    printf("  strlen    = %lu\n", strlen(""));
    printf("  ft_strlen = %d\n\n", ft_strlen(""));

    printf("single char:\n");
    printf("  strlen    = %lu\n", strlen("a"));
    printf("  ft_strlen = %d\n\n", ft_strlen("a"));

    printf("normal string:\n");
    printf("  strlen    = %lu\n", strlen("bonjour"));
    printf("  ft_strlen = %d\n\n", ft_strlen("bonjour"));

    char big[10001];

    memset(big, 'A', 10000);
    big[10000] = '\0';

    printf("long string:\n");
    printf("  strlen    = %lu\n", strlen(big));
    printf("  ft_strlen = %d\n", ft_strlen(big));
}

static void test_strcpy(void)
{
    printf("\n========== STRCPY ==========\n");

    char d1[100];
    char d2[100];

    strcpy(d1, "");
    ft_strcpy(d2, "");

    printf("empty string:\n");
    printf("  strcpy    = \"%s\"\n", d1);
    printf("  ft_strcpy = \"%s\"\n\n", d2);

    strcpy(d1, "abc");
    ft_strcpy(d2, "abc");

    printf("normal string:\n");
    printf("  strcpy    = \"%s\"\n", d1);
    printf("  ft_strcpy = \"%s\"\n\n", d2);

    strcpy(d1, "abcdefghijklmnopqrstuvwxyz");
    ft_strcpy(d2, "abcdefghijklmnopqrstuvwxyz");

    printf("alphabet:\n");
    printf("  strcpy    = \"%s\"\n", d1);
    printf("  ft_strcpy = \"%s\"\n", d2);
}

static void cmp_case(const char *s1, const char *s2)
{
    printf("\"%s\" vs \"%s\"\n", s1, s2);
    printf("  strcmp    = %d\n", strcmp(s1, s2));
    printf("  ft_strcmp = %d\n\n", ft_strcmp(s1, s2));
}

static void test_strcmp(void)
{
    printf("\n========== STRCMP ==========\n");

    cmp_case("", "");
    cmp_case("", "a");
    cmp_case("a", "");
    cmp_case("a", "a");
    cmp_case("a", "b");
    cmp_case("b", "a");

    cmp_case("abc", "abc");
    cmp_case("abc", "abd");
    cmp_case("abd", "abc");

    cmp_case("abcde", "abc");
    cmp_case("abc", "abcde");

    cmp_case("42", "42");
    cmp_case("42Paris", "42");
    cmp_case("42", "42Paris");

    cmp_case("\200", "\0");
    cmp_case("\377", "\0");
}

static void test_read_valid(void)
{
    printf("\n========== READ VALID ==========\n");

    int fd1 = open("main.c", O_RDONLY);
    int fd2 = open("main.c", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
    {
        printf("Cannot open file\n");
        return;
    }

    char b1[256];
    char b2[256];

    memset(b1, 0, sizeof(b1));
    memset(b2, 0, sizeof(b2));

    ssize_t r1 = read(fd1, b1, 255);
    ssize_t r2 = ft_read(fd2, b2, 255);

    printf("read return    = %zd\n", r1);
    printf("ft_read return = %zd\n", r2);

    printf("buffers equal  = %s\n",
        strcmp(b1, b2) == 0 ? "YES" : "NO");

    close(fd1);
    close(fd2);
}

static void test_read_error(void)
{
    printf("\n========== READ ERROR ==========\n");

    char buf[10];

    errno = 0;
    ssize_t r1 = read(-1, buf, 10);
    int e1 = errno;

    errno = 0;
    ssize_t r2 = ft_read(-1, buf, 10);
    int e2 = errno;

    printf("read    = %zd errno=%d\n", r1, e1);
    printf("ft_read = %zd errno=%d\n", r2, e2);
}

static void test_read_zero(void)
{
    printf("\n========== READ COUNT = 0 ==========\n");

    int fd1 = open("main.c", O_RDONLY);
    int fd2 = open("main.c", O_RDONLY);

    char b1[10];
    char b2[10];

    ssize_t r1 = read(fd1, b1, 0);
    ssize_t r2 = ft_read(fd2, b2, 0);

    printf("read    = %zd\n", r1);
    printf("ft_read = %zd\n", r2);

    close(fd1);
    close(fd2);
}

static void test_write_valid(void)
{
    printf("\n========== WRITE VALID ==========\n");

    ssize_t w1 = write(1, "REAL WRITE\n", 11);
    ssize_t w2 = ft_write(1, "FT WRITE11\n", 11);

    printf("write return    = %zd\n", w1);
    printf("ft_write return = %zd\n", w2);
}

static void test_write_error(void)
{
    printf("\n========== WRITE ERROR ==========\n");

    errno = 0;
    ssize_t w1 = write(-1, "abc", 3);
    int e1 = errno;

    errno = 0;
    ssize_t w2 = ft_write(-1, "abc", 3);
    int e2 = errno;

    printf("write    = %zd errno=%d\n", w1, e1);
    printf("ft_write = %zd errno=%d\n", w2, e2);
}

static void test_strdup(void)
{
    printf("\n========== STRDUP ==========\n");

    char *s1;
    char *s2;

    s1 = strdup("");
    s2 = ft_strdup("");

    printf("empty string:\n");
    printf("  strdup    = \"%s\"\n", s1);
    printf("  ft_strdup = \"%s\"\n\n", s2);

    free(s1);
    free(s2);

    s1 = strdup("bonjour");
    s2 = ft_strdup("bonjour");

    printf("normal string:\n");
    printf("  strdup    = \"%s\"\n", s1);
    printf("  ft_strdup = \"%s\"\n\n", s2);

    free(s1);
    free(s2);

    char big[10001];

    memset(big, 'X', 10000);
    big[10000] = '\0';

    s1 = strdup(big);
    s2 = ft_strdup(big);

    printf("long string:\n");
    printf("  strlen(strdup)    = %lu\n", strlen(s1));
    printf("  strlen(ft_strdup) = %lu\n", strlen(s2));

    free(s1);
    free(s2);
}


static void test_list_push()
{
     printf("\n========== list push ==========\n");

    t_list *lst = NULL;
    char *data1 = "Hello";
    char *data2 = "World";
    char *data3 = "42";

    printf("\npush hello\n");

    ft_list_push_front(&lst, data1);
     printf("\npush world\n");
    ft_list_push_front(&lst, data2);
     printf("\npush 42\n");
    ft_list_push_front(&lst, data3);

    t_list *current = lst;
    printf("\nstart write\n");
    while (current)
    {
        printf("address %p,  contenu %s\n",current, (char *)current->data);
        write(1, "\n", 1);
        current = current->next;
    }
}

void test_atoi_base()
{
    
    printf("%s\n", ft_atoi_base("1233333", "123"));
    printf("\n========== atoibase ==========\n");
    printf("%s\n", ft_atoi_base("123", "0123456789"));
    
    printf("%s\n", ft_atoi_base("99999999", "0123456789"));

    printf("%s\n", ft_atoi_base("-0111101", "01"));

    printf("%s\n", ft_atoi_base("123", "123456789"));

    printf("%s\n", ft_atoi_base("ff", "0123456789abcdef"));

    printf("%s\n", ft_atoi_base("unicorn", "unicorn"));

    printf("%s\n", ft_atoi_base("0", "056789"));
}

int main(void)
{
    test_strlen();

    test_strcpy();

    test_strcmp();

    test_read_valid();
    test_read_error();
    test_read_zero();

    test_write_valid();
    test_write_error();

    test_strdup();

    test_list_push();

    test_atoi_base();

    return (0);
}