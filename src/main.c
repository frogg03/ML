#include "../includes/ml.h"

#include <stdio.h>

int main (void)
{
    size_t layers[] = {3, 4, 6, 2};

    Model *m = generate_model(4, layers);

    (void) m;

    return 0;
}
