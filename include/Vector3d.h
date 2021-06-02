#pragma once

#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>

#define gc(a, x) *(double _Complex *)((*a).x)
#define gd(a, x) *(double *)((*a).x)

typedef struct Vertex
{
    void *x;
    void *y;
    void *z;
    struct Vertex *(*sum)(struct Vertex *,struct Vertex *);
    struct Vertex *(*cross)(struct Vertex *,struct Vertex *);
    struct Vertex *(*scan)();
} Vertex;

Vertex *create_Complex();
Vertex *create_double();
Vertex *sum_Complex(Vertex *a, Vertex *b);
Vertex *sum_double(Vertex *a, Vertex *b);
double complex scalar_Complex(Vertex *a, Vertex *b);
double scalar_double(Vertex *a, Vertex *b);
Vertex *cross_Complex(Vertex *a, Vertex *b);
Vertex *cross_double(Vertex * a, Vertex * b);
void print_Complex(Vertex *a);
void print_double(Vertex *a);
Vertex *scan_Complex();
Vertex *scan_double();
void deleteVertex(Vertex*);
void test();