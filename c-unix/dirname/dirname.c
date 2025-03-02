#include <stdio.h>
#include <string.h>

void usage(void)
{
    printf("TODO\n");
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        usage();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int j = strlen(argv[i]) - 1;
        while (j >= 0 && argv[i][j] == '/') {
            --j;
        }
        while (j >= 0 && argv[i][j] != '/') {
            --j;
        }
        while (j >= 0 && argv[i][j] == '/') {
            --j;
        }
        ++j;
        if (j == 0) {
            printf("%c\n", (argv[i][j] == '/' ? '/' : '.'));
        } else {
            argv[i][j] = '\0';
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}
