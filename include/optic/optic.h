#include<string.h>

struct optic_sub;

enum {
    optic_required = 0,
    optic_optional,
    optic_none,
    /* do not use */
    __optic_types_end
};

struct optic_state {
    struct optic_arg *args;
    struct 
};

struct optic_arg {
    const char *name;
    int type;
};

/* subcommand */
struct optic_sub {
};
