#include <stdio.h>
#include <stdlib.h>
#include "error.h"


void invalid_args(void)
{
    puts("Invalid Argument, Exiting Program...");

    exit(-EINVARG);

}
