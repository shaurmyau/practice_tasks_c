#include <stdio.h>

extern int global_var;  // Объявляем глобальную переменную из file1.c

void print_from_file2() {
    printf("file2.c -> global_var = %d\n", global_var);
}