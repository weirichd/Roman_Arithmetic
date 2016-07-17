#ifndef VALIDATION_H
#define VALIDATION_H

#include "numeral_map.h"

static int is_a_valid_roman_numeral(const char *const numeral) {
    int numeral_offset = 0;

    while(numeral[numeral_offset] != '\0') {
        const RomanMapEntry *current_entry = find_map_element(numeral + numeral_offset);

        if(current_entry == NULL)
            return 0;

        numeral_offset += strlen(current_entry->roman_symbol);
    }

    return 1;
}

#endif /* VALIDATION_H */
