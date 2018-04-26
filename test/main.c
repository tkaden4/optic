#include<optic/optic.h>
#include<stdio.h>

int main()
{
    const char *argv[] = { "--test", "test", "--test", "-f" };
    int argc = 4;
    struct optic_parser parser = optic_parser_init(argc, argv);
    struct optic_arg_result *res = NULL;
    while((res = optic_parse(&parser, NULL)) && res != (void *)-1){
        printf("%s=%s\n", res->opt, res->val ?: "(none)");
    }
    return 0;
}
