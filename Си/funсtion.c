#include <stdio.h> 
int main (int argc, char **argv)
{
    int i;
    printf("%\n", argc);
    for(i=0; i < argc; i++) puts(argv[i]);
}