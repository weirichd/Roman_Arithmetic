#ifndef NUMERAL_MAP_H
#define NUMERAL_MAP_H

typedef struct RomanMapEntry {
    char roman_symbol[3];
    int arabic_value;
} RomanMapEntry;

static const RomanMapEntry ROMAN_MAP[] = {
    { .roman_symbol = "M",  .arabic_value = 1000},
    { .roman_symbol = "CM", .arabic_value = 900},
    { .roman_symbol = "D",  .arabic_value = 500},
    { .roman_symbol = "CD", .arabic_value = 400},
    { .roman_symbol = "C",  .arabic_value = 100},
    { .roman_symbol = "XC", .arabic_value = 90},
    { .roman_symbol = "L",  .arabic_value = 50},
    { .roman_symbol = "XL", .arabic_value = 40},
    { .roman_symbol = "X",  .arabic_value = 10},
    { .roman_symbol = "IX", .arabic_value = 9},
    { .roman_symbol = "V",  .arabic_value = 5},
    { .roman_symbol = "IV", .arabic_value = 4},
    { .roman_symbol = "I",  .arabic_value = 1},
};

static const size_t ROMAN_MAP_SIZE = sizeof(ROMAN_MAP)/sizeof(RomanMapEntry);

inline static const RomanMapEntry *find_map_element(const char *roman_symbol) {
    for(int i = 0; i < ROMAN_MAP_SIZE; i++) {
        int symbol_len = strlen(ROMAN_MAP[i].roman_symbol);

        if(strncmp(roman_symbol, ROMAN_MAP[i].roman_symbol, symbol_len) == 0)
            return &ROMAN_MAP[i];
    }

    return NULL; 
}

#endif /* NUMERAL_MAP_H */
