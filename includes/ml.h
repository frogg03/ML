#ifndef ML_H_
#define ML_H_

#include <stddef.h>

typedef float MyFloat;

typedef struct _Model Model;

Model *generate_model(size_t len, size_t layers[len]);

#endif // ML_H_
