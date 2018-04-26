#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>

struct optic_sub;

enum {
    optic_required = 0,
    optic_optional,
    optic_none,
    /* do not use */
    __optic_types_end
};

struct optic_options {
    //TODO
};

struct optic_result {
    //TODO
};

struct optic_arg_result {
    const char *opt;
    const char *val;
};

struct optic_parser {
    /* current result argument */
    struct optic_arg_result current;
    /* arguments */
    int argc;
    const char **argv;
};

#define optic_parser_init(argc, argv) \
    { {}, argc, argv }

static struct optic_arg_result *
__optic_parse_argument(
        struct optic_parser *parser,
        const struct optic_options *opts)
{
    return NULL;
}

static bool
is_option(const char *text)
{
    if(!text){
        return false;
    }
    if(*text != '-'){
        return false;
    }
    while(isalpha(*++text));
    if(*text){
        return false;
    }
    return true;
}

static bool
is_long_option(const char *text)
{
    if(!text){
        return false;
    }
    if(strncmp(text, "--", 2)){
        return false;
    }
    text += 2;
    if(!isalpha(*text)){
        return false;
    }
    while(*++text){
        if(*text == '-'){
            if(!isalpha(*(text + 1))){
                return false;
            }
        }else if(!isalpha(*text)){
            return false;
        }
    }
    return true;
}

static bool
is_any_option(const char *text)
{
    return *text && (is_option(text) || is_long_option(text));
}

/* Extract an option and it's value from
 * an array of strings of length <len>
 * returning the amount of elements of
 * the array used */
static size_t
__optic_parse_string(
        const char **argv,
        size_t len,
        const char **option,
        const char **value)
{
    int
    __get_option(const char **argv, const char **option)
    {
        if(is_option(*argv)){
            *option = *argv + 1;
        }else if(is_long_option(*argv)){
            *option = *argv + 2;
        }else{
            return 1;
        }
        return 0;
    }

    if(len == 1){
        *value = NULL;
        if(__get_option(argv, option)){
            return 0;
        }
        return 1;
    }else if(len > 1){
        if(__get_option(argv, option)){
            return 0;
        }
        ++argv;
        /* TODO fix, this doesnt work */
        if(is_any_option(*argv)){
            return 1;
        }
        *value = *argv;
        return 2;
    }else{
        return 0;
    }
    return 0;
}

/* The most basic parser, allowing the user to handle
 * arguments however they like, similar to the getopt()
 * function. However, the optic_parse function is fully
 * reentrant, has support for argument types, and can
 * parse subcommands. */
struct optic_arg_result *
optic_parse(
        /* parser state */
        struct optic_parser *parser,
        /* options to be parsed */
        const struct optic_options *opts) 
{
    if(parser->argc == 0){
        return NULL;
    }
    /* read one option */
    size_t read = 0;
    const char *opt = NULL;
    const char *val = NULL;
    if((read = __optic_parse_string(parser->argv, parser->argc, &opt, &val)) == 0){
        return (void *)-1;
    }
    parser->argv += read;
    parser->argc -= read;
    parser->current.opt = opt;
    parser->current.val = val;
    /* find the option in our scope */
    return &parser->current;
}
