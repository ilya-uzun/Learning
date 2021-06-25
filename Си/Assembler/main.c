
#include <unistd.h>

int main(int argc, char* arg[])
{
    char str[] = "Hello\n";
    write(1, str, sizeof(str) - 1);
    _exit(0);
}
