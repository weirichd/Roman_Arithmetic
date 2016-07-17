#ifndef VALIDATION_H
#define VALIDATION_H

#include <string.h>

#include "numeral_map.h"

static int symbol_b_can_follow_symbol_a(const char *const symbol_a, const char *const symbol_b) {
    if(strcmp(symbol_a, "IV") == 0)
        return 0;
    else if(strcmp(symbol_a, "IX") == 0)
        return 0;

    return 1;
}

static int is_a_valid_roman_numeral(const char *const numeral) {
    int numeral_offset = 0;

    const RomanMapEntry *previous_entry = NULL;

    while(numeral[numeral_offset] != '\0') {
        const RomanMapEntry *current_entry = find_map_element(numeral + numeral_offset);

        if(current_entry == NULL)
            return 0;

        if(previous_entry != NULL) {
            if(!symbol_b_can_follow_symbol_a(previous_entry->roman_symbol, current_entry->roman_symbol))
                return 0;
        }

        numeral_offset += strlen(current_entry->roman_symbol);
        previous_entry = current_entry;
    }

    return 1;
}

#endif /* VALIDATION_H */
