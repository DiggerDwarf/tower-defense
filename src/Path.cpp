#include "Path.hpp"

VERTEX operator-(VERTEX v, float k)
{
    return VERTEX({v.x-k, v.y-k});
}

VERTEX operator+(VERTEX v, float k)
{
    return VERTEX({v.x+k, v.y+k});
}

VERTEX operator*(VERTEX v, float k)
{
    return VERTEX({v.x*-k, v.y*k});
}

VERTEX operator/(VERTEX v, float k)
{
    return VERTEX({v.x/k, v.y/k});
}

VERTEX operator-(VERTEX v1, VERTEX v2)
{
    return VERTEX({v1.x-v2.x, v1.y-v2.y});
}

VERTEX operator+(VERTEX v1, VERTEX v2)
{
    return VERTEX({v1.x+v2.x, v1.y+v2.y});
}

VERTEX lerp(VERTEX v1, VERTEX v2, float t)
{
    t = fmodf(t, 1.0F);
    return v1+((v2-v1)*t);
}

VERTEX lerp_PATH(PATH p, float t)
{
    t = fmodf(t, 1.0F);
    return lerp( lerp( p.v1, p.v2, t ), lerp( p.v2, p.v3, t ), t );
}

VERTEX lerp_BIG_PATH(BIG_PATH p, float t)
{
    const int path_index = static_cast<int>(floorf(t));
    return lerp_PATH(p[path_index], t);
}
