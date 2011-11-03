/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_PRINT_H_ */

#include <stddef.h> /* size_t */
#include <stdio.h> /* printf */

#include "MsgGenPrintPrimitives.h"

/* Static functions by default */
#if !defined LINKAGE
    #define LINKAGE static
#endif

/*
 * Print the given msg type
 *
 * TYPE: the type to print, must be a single token
 * NAME: variable name of the message to print
 */
#define MsgGenPrint(TYPE, NAME) \
    MsgGenPrint_##TYPE(NAME, 0)

/* Generate message printing code */

#define MESSAGE(TYPE, NAME, MEMBERS) \
LINKAGE void \
MsgGenPrint_##TYPE(const TYPE * src, \
                                int depth) \
{ \
    MsgGenPrint_depth(depth); \
    printf("%s %s = {\n", #TYPE, #NAME); \
    depth++; \
    \
    MEMBERS \
    \
    depth--; \
    MsgGenPrint_depth(depth); \
    printf("}\n"); \
} \

#define MEMBER(TYPE, NAME) \
        MsgGenPrint_depth(depth); \
        printf(".%s = ", #NAME); \
        MsgGenPrint_##TYPE(&src->NAME, depth); \
        printf("\n"); \

#define MEMBER_ARRAY(TYPE, NAME, LENGTH) \
        { \
            MsgGenPrint_depth(depth); \
            printf(".%s = {\n", #NAME); \
            depth++; \
            MsgGenPrint_depth(depth); \
            size_t sz; \
            for (sz = 0; sz < (sizeof(src->NAME)/sizeof(src->NAME[0])) ; sz++) \
            { \
                MsgGenPrint_##TYPE(&src->NAME[sz], depth); \
                printf(" "); \
            } \
            printf("\n"); \
            depth--; \
            MsgGenPrint_depth(depth); \
            printf("}\n"); \
        } \

#define MEMBER_FLEXARRAY(TYPE, NAME) \
        { \
            MsgGenPrint_depth(depth); \
            printf(".%s = {\n", #NAME); \
            depth++; \
            MsgGenPrint_depth(depth); \
            printf("Flexible Array Data\n"); \
            depth--; \
            MsgGenPrint_depth(depth); \
            printf("}\n"); \
        } \

#define TYPE(BASE_TYPE, TYPE_NAME) \
LINKAGE void \
MsgGenPrint_##TYPE_NAME(const TYPE_NAME * src, \
                        int depth) \
{ \
    printf("(%s) ", #TYPE_NAME); \
    MsgGenPrint_##BASE_TYPE((const BASE_TYPE *) src, depth); \
} \

/* No include guard for MSG_GEN_PRINT_H_ */

