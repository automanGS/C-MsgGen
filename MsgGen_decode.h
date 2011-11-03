/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_DECODE_H_ */

#include <stddef.h> /* size_t */
#include <assert.h> /* assert */

#include "MsgGenDecodePrimitives.h"

/* Generates declarations for simple packed decoding */

/*
 * Decode the given msg type from a packed byte array
 *
 * TYPE: the type to decode, must be a single token
 * NAME: variable name of the message to decode
 */
#define MsgGenDecode(TYPE, src, dst) \
    MsgGenDecode_##TYPE(src, dst)

/* Generate message decoding code */
#define MESSAGE(TYPE, NAME, MEMBERS) \
static TYPE * \
MsgGenDecode_##TYPE(const uint8_t* src, \
                    TYPE * dst) \
{ \
    assert(src); \
    assert(dst); \
    \
    MEMBERS \
    \
    return dst; \
} \

#define MEMBER(TYPE, NAME) \
    MsgGenDecode_##TYPE(src, &dst->NAME); \
    src += sizeof(TYPE); \

#define MEMBER_ARRAY(TYPE, NAME, LENGTH) \
    { \
        size_t sz; \
        for (sz = 0; sz < (sizeof(dst->NAME)/sizeof(dst->NAME[0])) ; sz++) \
        { \
            MEMBER(TYPE, NAME[sz]) \
        } \
    } \

#define MEMBER_FLEXARRAY(TYPE, NAME) \
    { \
        (void) (&dst->NAME); \
    } \

#define TYPE(BASE_TYPE, TYPE_NAME) \
static inline void \
MsgGenDecode_##TYPE_NAME(const uint8_t* src, \
                         TYPE_NAME * dst) \
{ \
    MsgGenDecode_##BASE_TYPE(src, (BASE_TYPE *) dst); \
} \

/* No include guard for MSG_GEN_DECODE_H_ */

