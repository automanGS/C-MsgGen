/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#if !defined MSG_GEN_PRINT_PRIMITIVES_H_
#define MSG_GEN_PRINT_PRIMITIVES_H_

#include <stdint.h> /* fixed-width types */
#include <stdio.h> /* printf */

/* 
 * Print indentation
 */
inline static void
MsgGenPrint_depth(unsigned int depth)
{ while (depth--) { printf("\t"); } };

inline static void
MsgGenPrint_char(const char* src, unsigned int depth)
{ printf("%c", *src); };

inline static void
MsgGenPrint_int8_t(const int8_t* src, unsigned int depth)
{ printf("%d", *src); };

inline static void
MsgGenPrint_uint8_t(const uint8_t* src, unsigned int depth)
{ printf("%u", *src); };

inline static void
MsgGenPrint_int16_t(const int16_t* src, unsigned int depth)
{ printf("%d", *src); };

inline static void
MsgGenPrint_uint16_t(const uint16_t* src, unsigned int depth)
{ printf("%u", *src); };

inline static void
MsgGenPrint_int32_t(const int32_t* src, unsigned int depth)
{ printf("%d", *src); };

inline static void
MsgGenPrint_uint32_t(const uint32_t* src, unsigned int depth)
{ printf("%u", *src); };

#endif // MSG_GEN_PRINT_PRIMITIVES_H_

