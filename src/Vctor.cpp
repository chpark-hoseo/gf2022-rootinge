#include "Vector.h"

Vector Vector::AddVector(Vector a, Vector b)
{

    Vector c;

    c.m_x = a.m_x + b.m_x;
    c.m_y = a.m_y + b.m_y;

    return c;

}

Vector Vector::SubVecotr(Vector a, Vector b)
{

    Vector c;

    c.m_x = a.m_x - b.m_x;
    c.m_y = a.m_y - b.m_y;

    return c;

}

void Vector::VectorNormalize(Vector* a)
{

    float Length = sqrt((a->m_x * a->m_x) + (a->m_y * a->m_y));

    a->m_x /= (Length * 20.0);
    a->m_y /= (Length * 20.0);

}