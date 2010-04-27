/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#if !defined MSG_GEN_ENCODE_PRIMITIVES_H_
#define MSG_GEN_ENCODE_PRIMITIVES_H_

#include <stdint.h> /* fixed-width types */
#include "ByteOrder.h" /* portable serialization */

inline static void
MsgGenEncode_char(const char* src, uint8_t* dst)
{ *dst = (uint8_t) *src; };

inline static void
MsgGenEncode_int8_t(const int8_t* src, uint8_t* dst)
{ *dst = (uint8_t) *src; };

inline static void
MsgGenEncode_uint8_t(const uint8_t* src, uint8_t* dst)
{ *dst = *src; };

inline static void
MsgGenEncode_int16_t(const int16_t* src, uint8_t* dst)
{ le16enc(dst, (uint16_t) *src); };

inline static void
MsgGenEncode_uint16_t(const uint16_t* src, uint8_t* dst)
{ le16enc(dst, *src); };

inline static void
MsgGenEncode_int32_t(const int32_t* src, uint8_t* dst)
{ le32enc(dst, (uint32_t) *src); };

inline static void
MsgGenEncode_uint32_t(const uint32_t* src, uint8_t* dst)
{ le32enc(dst, *src); };

#endif // MSG_GEN_ENCODE_PRIMITIVES_H_

