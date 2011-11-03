/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_ENCODE_H_ */

#include <stddef.h> /* size_t */
#include <assert.h> /* assert */

#include "MsgGenEncodePrimitives.h"

/* Generates declarations for simple packed encoding */

/*
 * Encode the given msg type to a packed byte array
 *
 * TYPE: the type to encode, must be a single token
 * NAME: variable name of the message to encode
 */
#define MsgGenEncode(TYPE, src, dst) \
    MsgGenEncode_##TYPE(src, dst)

/* Generate message encoding code */
#define MESSAGE(TYPE, NAME, MEMBERS) \
static uint8_t * \
MsgGenEncode_##TYPE(const TYPE * src, \
                    uint8_t* dst) \
{ \
    assert(src); \
    assert(dst); \
    \
    MEMBERS \
    \
    return dst; \
} \

#define MEMBER(TYPE, NAME) \
    MsgGenEncode_##TYPE(&src->NAME, dst); \
    dst += sizeof(TYPE); \

#define MEMBER_ARRAY(TYPE, NAME, LENGTH) \
    { \
        size_t sz; \
        for (sz = 0; sz < (sizeof(src->NAME)/sizeof(src->NAME[0])) ; sz++) \
        { \
            MEMBER(TYPE, NAME[sz]) \
        } \
    } \

#define MEMBER_FLEXARRAY(TYPE, NAME) \
    { \
        (void) (&src->NAME) ; \
    } \

#define TYPE(BASE_TYPE, TYPE_NAME) \
static inline void \
MsgGenEncode_##TYPE_NAME(const TYPE_NAME * src, \
                         uint8_t* dst) \
{ \
    MsgGenEncode_##BASE_TYPE((const BASE_TYPE *) src, dst); \
} \

/* No include guard for MSG_GEN_ENCODE_H_ */

