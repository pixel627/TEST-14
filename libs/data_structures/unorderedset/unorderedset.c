# include "unorderedset.h"
# include <stdlib.h>

unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set set;
    set.data = (int *)malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;
    return set;
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set;
    set.data = (int *)malloc(size * sizeof(int));
    set.size = size;
    set.capacity = size;
    memcpy(set.data, a, size * sizeof(int));
    return set;
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    for (size_t i = 0; i < set.size; i++) {
        if (set.data[i] == value) {
            return i;
        }
    }
    return set.size;
}

size_t unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        if (unordered_array_set_in(set, subset.data[i]) == set.size) {
            return subset.size;
        }
    }
    return set.size;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            return false;
        }
    }
    return true;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    set->data[set->size++] = value;
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t index = unordered_array_set_in(*set, value);
    if (index < set->size) {
        for (size_t i = index; i < set->size - 1; i++) {
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    size_t newSize = set1.size + set2.size;
    unordered_array_set resultSet = unordered_array_set_create(newSize);

    for (size_t i = 0; i < set1.size; i++) {
        unordered_array_set_insert(&resultSet, set1.data[i]);
    }

    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&resultSet, set2.data[i]);
    }

    return resultSet;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set resultSet = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) < set2.size) {
            unordered_array_set_insert(&resultSet, set1.data[i]);
        }
    }
    return resultSet;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set resultSet = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            unordered_array_set_insert(&resultSet, set1.data[i]);
        }
    }
    return resultSet;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set resultSet = unordered_array_set_create(universumSet.size);

    for (size_t i = 0; i < universumSet.size; i++) {
        if (unordered_array_set_in(set, universumSet.data[i]) == set.size) {
            unordered_array_set_insert(&resultSet, universumSet.data[i]);
        }
    }

    return resultSet;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set resultSet1 = unordered_array_set_difference(set1, set2);
    unordered_array_set resultSet2 = unordered_array_set_difference(set2, set1);
    return unordered_array_set_union(resultSet1, resultSet2);
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; i++) {
        printf("%d ", set.data[i]);
    }
    printf("}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}