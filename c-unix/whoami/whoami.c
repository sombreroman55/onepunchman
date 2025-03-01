#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
    int uid = getuid();
    struct passwd* pu = getpwuid(uid);
    printf("%s\n", pu->pw_name);
    return 0;
}
