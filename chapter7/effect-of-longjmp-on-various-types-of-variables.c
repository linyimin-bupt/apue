#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmp_buffer;
static int global_var;

int main(int argc, char *argv[]) {
    int auto_avar;
    register int register_var;
    volatile int volatile_var;
    static int static_var;

    global_var = 1;
    auto_avar = 2;
    register_var = 3;
    volatile_var = 4;
    static_var = 5;

    if (setjmp(jmp_buffer) != 0) {
        printf("After longjmp: \n");

        printf("global = %d, automatic = %d, register = %d, volatile = %d, static = %d\n", global_var, auto_avar,
               register_var, volatile_var, static_var);

        exit(0);
    } else {
        /*
         * Change variables after setjmp, but before longjmp
         */
        global_var = 91;
        auto_avar = 92;
        register_var = 93;
        volatile_var = 94;
        static_var = 95;

        f1(auto_avar, register_var, volatile_var, static_var);
        exit(0);
    }
}

static void f1(int i, int j, int k, int l) {
    printf("in f1(): \n");
    printf("global = %d, automatic = %d, register = %d, volatile = %d, static = %d\n", global_var, i,
           j, k, l);
    f2();
}

static void f2(void) {
    longjmp(jmp_buffer, 1);
}