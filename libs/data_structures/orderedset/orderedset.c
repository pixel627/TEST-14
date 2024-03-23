# include "orderedset.h"
# include <stdlib.h>

ordered_array_set ordered_array_set_create(size_t capacity) {
    ordered_array_set newSet;
    newSet.data = (int *)malloc(capacity * sizeof(int));
    newSet.size = 0;
    newSet.capacity = capacity;
    return newSet;
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set newSet;
    newSet.data = (int *)malloc(size * sizeof(int));
    memcpy(newSet.data, a, size * sizeof(int));
    newSet.size = size;
    newSet.capacity = size;
    return newSet;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return i;
        }
    }
    return set->size;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; i++) {
        if (set1.data[i] != set2.data[i]) {
            return false;
        }
    }
    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        if (ordered_array_set_in(&set, subset.data[i]) == set.size) {
            return false;
        }
    }
    return true;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    set->data[set->size] = value;
    set->size++;
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t index = ordered_array_set_in(set, value);
    if (index < set->size) {
        for (size_t i = index; i < set->size - 1; i++) {
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resultSet = ordered_array_set_create(set1.size + set2.size);
    memcpy(resultSet.data, set1.data, set1.size * sizeof(int));
    resultSet.size = set1.size;
    for (size_t i = 0; i < set2.size; i++) {
        if (ordered_array_set_in(&resultSet, set2.data[i]) == resultSet.size) {
            resultSet.data[resultSet.size] = set2.data[i];
            resultSet.size++;
        }
    }
    return resultSet;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resultSet = ordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size) {
            resultSet.data[resultSet.size] = set1.data[i];
            resultSet.size++;
        }
    }
    return resultSet;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resultSet = ordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            resultSet.data[resultSet.size] = set1.data[i];
            resultSet.size++;
        }
    }
    return resultSet;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resultSet1 = ordered_array_set_difference(set1, set2);
    ordered_array_set resultSet2 = ordered_array_set_difference(set2, set1);
    ordered_array_set resultSet = ordered_array_set_union(resultSet1, resultSet2);
    ordered_array_set_delete(resultSet1);
    ordered_array_set_delete(resultSet2);
    return resultSet;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set resultSet = ordered_array_set_difference(universumSet, set);
    return resultSet;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; i++) {
        printf("%d ", set.data[i]);
    }
    printf("}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}