#ifndef MAJI_H
#define MAJI_H

#define MAX_CUSTOMER 100
#define MAX_BOOK 100

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

enum Maj_type
{
    S,
    P,
    M,
    ZH,
    FA,
    BA,
    East,
    West,
    South,
    North,
    Error
};

typedef struct
{
    int value;
    Maj_type type;
} Tile;

#endif // MAJI_H