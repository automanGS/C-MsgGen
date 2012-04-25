/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#if !defined MSG_GEN_DECODE_PRIMITIVES_H_
#define MSG_GEN_DECODE_PRIMITIVES_H_

/* Users should provide their own definitions for c99 stdint types.
 * We don't include them here.
 *
 * #include <stdint.h>
 */

#include "ByteOrder.h" /* portable deserialization */

static inline void
MsgGenDecode_char(const uint8_t* src, char* dst)
{ *dst = (char) *src; };

static inline void
MsgGenDecode_int8_t(const uint8_t* src, int8_t* dst)
{ *dst = (int8_t) *src; };

static inline void
MsgGenDecode_uint8_t(const uint8_t* src, uint8_t* dst)
{ *dst = *src; };

static inline void
MsgGenDecode_int16_t(const uint8_t* src, int16_t* dst)
{ *dst = (int16_t)le16dec(src); };

static inline void
MsgGenDecode_uint16_t(const uint8_t* src, uint16_t* dst)
{ *dst = (uint16_t)le16dec(src); };

static inline void
MsgGenDecode_int32_t(const uint8_t* src, int32_t* dst)
{ *dst = (int32_t)le32dec(src); };

static inline void
MsgGenDecode_uint32_t(const uint8_t* src, uint32_t* dst)
{ *dst = (uint32_t)le32dec(src); };

static inline void
MsgGenDecode_float(const uint8_t* src, float* dst)
{
    uint32_t tmp32 = le32dec(src);
    *dst = *((float*) &tmp32);
};

#endif // MSG_GEN_DECODE_PRIMITIVES_H_

