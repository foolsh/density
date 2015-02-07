/*
 * Centaurean Density
 *
 * Copyright (c) 2015, Guillaume Voirin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Centaurean nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * 5/02/15 20:54
 *
 * ------------------
 * Argonaut algorithm
 * ------------------
 *
 * Author(s)
 * Guillaume Voirin (https://github.com/gpnuma)
 *
 * Description
 * Word rank and predictions algorithm
 */

#ifndef DENSITY_ARGONAUT_DICTIONARY_H
#define DENSITY_ARGONAUT_DICTIONARY_H

#include "globals.h"
#include "kernel_argonaut.h"

#include <string.h>

#pragma pack(push)
#pragma pack(1)
typedef struct {
    union {
        uint64_t as_uint64_t;
        uint8_t letters[sizeof(uint64_t)];
    };
} density_argonaut_word;

typedef struct {
    density_argonaut_word next_word;
} density_argonaut_dictionary_prediction_entry;

typedef struct {
    density_argonaut_word word;
    uint8_t rank_4bits;
    uint32_t usage;
} density_argonaut_dictionary_8bits_entry;

typedef struct {
    density_argonaut_word word;
    uint8_t rank_8bits;
    uint32_t usage;
} density_argonaut_dictionary_16bits_entry;

typedef struct {
    uint8_t letter;
    uint32_t usage;
    uint8_t rank;
} density_argonaut_dictionary_letter;

typedef struct {
    density_argonaut_dictionary_letter letters[1 << 8];
    density_argonaut_dictionary_letter letterRanks[1 << 8];
    density_argonaut_dictionary_prediction_entry predictions[1 << 16];
    density_argonaut_word* ranks_4bits[1 << 4];
    density_argonaut_word* ranks_8bits[1 << 8];
    density_argonaut_dictionary_8bits_entry entries_8bits[1 << 8];
    density_argonaut_dictionary_16bits_entry entries_16bits[1 << 16];
} density_argonaut_dictionary;
#pragma pack(pop)

#endif