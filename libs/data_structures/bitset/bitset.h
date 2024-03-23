#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>

#define MAX_CITIES 101

typedef struct {
    bool visited[MAX_CITIES];
} BitSet;

BitSet createBitSet();
void markVisitedCities(BitSet* bitSet, int n);
bool canReachDestination(BitSet bitSet, int destination);

#endif // BITSET_H