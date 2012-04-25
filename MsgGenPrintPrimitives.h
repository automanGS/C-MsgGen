/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#if !defined MSG_GEN_PRINT_PRIMITIVES_H_
#define MSG_GEN_PRINT_PRIMITIVES_H_

/* Users should provide their own definitions for c99 stdint types.
 * We don't include them here.
 *
 * #include <stdint.h>
 */

#include <stdio.h> /* printf */

/* 
 * Print indentation
 */
static inline void
MsgGenPrint_depth(unsigned int depth)
{ while (depth--) { printf("\t"); } };

static inline void
MsgGenPrint_char(const char* src, unsigned int depth)
{ printf("%c", *src); };

static inline void
MsgGenPrint_int8_t(const int8_t* src, unsigned int depth)
{ printf("%d", *src); };

static inline void
MsgGenPrint_uint8_t(const uint8_t* src, unsigned int depth)
{ printf("%u", *src); };

static inline void
MsgGenPrint_int16_t(const int16_t* src, unsigned int depth)
{ printf("%d", *src); };

static inline void
MsgGenPrint_uint16_t(const uint16_t* src, unsigned int depth)
{ printf("%u", *src); };

static inline void
MsgGenPrint_int32_t(const int32_t* src, unsigned int depth)
{ printf("%d", *src); };

static inline void
MsgGenPrint_uint32_t(const uint32_t* src, unsigned int depth)
{ printf("%u", *src); };

static inline void
MsgGenPrint_float(const float* src, unsigned int depth)
{ printf("%f", *src); };

#endif // MSG_GEN_PRINT_PRIMITIVES_H_

