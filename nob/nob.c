#define NOB_STRIP_PREFIX
#define NOB_IMPLEMENTATION
#include "nob.h"

#include <string.h>

#define DOWN_PATH   "../"
#define SOURCE_PATH "./src/"
#define HEADER_PATH "./includes/"

#define COMPILER      "cc"
#define WARNING_FLAGS "-Wall", "-Wextra", "-Wpedantic" 
#define OPTIMIZATIONS "-O0"
#define DEBUG_SYMBOLS "-ggdb"
#define LIBRARIES     "-lm" // , "-lraylib"
#define INCLUDES      "-I./"HEADER_PATH

#define TARGET "main"

int main (int argc, char *argv[])
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!set_current_dir(DOWN_PATH)) 
    {
        nob_log(NOB_ERROR, "set_current_dir(\"%s\") failed", DOWN_PATH);
        return 1;
    }

    Cmd compile_flags = {0};
    Cmd build_flags   = {0};
    Cmd source_files  = {0};
    Cmd linking_flags = {0};
    
    cmd_append(&compile_flags,
        COMPILER,
        INCLUDES,
    );
    
    cmd_append(&build_flags,
        WARNING_FLAGS,
        OPTIMIZATIONS,
        DEBUG_SYMBOLS,
    );

    cmd_append(&source_files,
        SOURCE_PATH"main.c"
    );

    cmd_append(&linking_flags,
        "-o", TARGET,
        LIBRARIES,
    );
    
    {
        Cmd cmd = {0};
        cmd_extend(&cmd, &compile_flags);
        cmd_extend(&cmd, &build_flags  );
        cmd_extend(&cmd, &source_files );
        cmd_extend(&cmd, &linking_flags);

        int r = cmd_run(&cmd); 
        cmd_free(cmd);

        if (!r) goto cleanup;
    }

    if (argc == 1) goto cleanup;

    if (!strcmp("run", argv[1]))
    {
        Cmd run = {0}; 
        cmd_append(&run, TARGET);

        int r = cmd_run(&run); 
        cmd_free(run);

        if (!r) goto cleanup;
    }

cleanup:

    cmd_free(compile_flags);
    cmd_free(build_flags);
    cmd_free(source_files);
    cmd_free(linking_flags);

    return 0;
}