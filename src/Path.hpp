#ifndef PATH_INCLUDED
#define PATH_INCLUDED

#include <vector>
#include <math.h>

typedef struct _VERTEX {
    float x;
    float y;
} VERTEX, *P_VERTEX;

typedef struct _PATH {
    VERTEX v1;
    VERTEX v2;
    VERTEX v3;
} PATH, *P_PATH;

typedef std::vector<PATH> BIG_PATH;

VERTEX operator-(VERTEX v, float k);
VERTEX operator+(VERTEX v, float k);
VERTEX operator*(VERTEX v, float k);
VERTEX operator/(VERTEX v, float k);
VERTEX operator-(VERTEX v1, VERTEX v2);
VERTEX operator+(VERTEX v1, VERTEX v2);

VERTEX lerp(VERTEX v1, VERTEX v2, float t);

VERTEX lerp_PATH(PATH p, float t);

VERTEX lerp_BIG_PATH(BIG_PATH p, float t);

#endif