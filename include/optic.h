#include<string.h>

struct optic_sub;

struct optic_state {
    struct optic_state *next;
    struct optic_sub *subc;
};

enum {
    optic_required,
    optic_optional,
    optic_none
};

struct optic_arg_type {
    enum {
    
    };
    union {
    
    } u;
};

/*  */
struct optic_arg {
    const char *name;
};

/* subcommand */
struct optic_sub {
    const char *name;
    struct optic_state state;
};
