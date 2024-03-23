#include "bitset.h"
#include <stdbool.h>
#include <stddef.h>

BitSet createBitSet() {
    BitSet bitSet;
    for (size_t i = 0; i < MAX_CITIES; ++i) {
        bitSet.visited[i] = false;
    }
    return bitSet;
}

void markVisitedCities(BitSet* bitSet, int n) {
    int city, location;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &city);
        for (int j = 0; j < city; ++j) {
            scanf("%d", &location);
            bitSet->visited[location] = true;
        }
    }
}

bool canReachDestination(BitSet bitSet, int destination) {
    return bitSet.visited[destination];
}
