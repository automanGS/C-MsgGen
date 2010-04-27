/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#if !defined MSG_GEN_DECODE_PRIMITIVES_H_
#define MSG_GEN_DECODE_PRIMITIVES_H_

#include <stdint.h> /* fixed-width types */
#include "ByteOrder.h" /* portable deserialization */

inline static void
MsgGenDecode_char(const uint8_t* src, char* dst)
{ *dst = (char) *src; };

inline static void
MsgGenDecode_int8_t(const uint8_t* src, int8_t* dst)
{ *dst = (int8_t) *src; };

inline static void
MsgGenDecode_uint8_t(const uint8_t* src, uint8_t* dst)
{ *dst = *src; };

inline static void
MsgGenDecode_int16_t(const uint8_t* src, int16_t* dst)
{ *dst = (int16_t)le16dec(src); };

inline static void
MsgGenDecode_uint16_t(const uint8_t* src, uint16_t* dst)
{ *dst = (uint16_t)le16dec(src); };

inline static void
MsgGenDecode_int32_t(const uint8_t* src, int32_t* dst)
{ *dst = (int32_t)le32dec(src); };

inline static void
MsgGenDecode_uint32_t(const uint8_t* src, uint32_t* dst)
{ *dst = (uint32_t)le32dec(src); };

#endif // MSG_GEN_DECODE_PRIMITIVES_H_

