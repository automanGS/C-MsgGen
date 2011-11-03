/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_PRINT_H_ */

/* Generate declarations for message printing code */

/*
 * Print the given msg type
 *
 * TYPE: the type to print, must be a single token
 * NAME: variable name of the message to print
 */
#define MsgGenPrint(TYPE, NAME) \
    MsgGenPrint_##TYPE(NAME, 0)


/* Extern declarations by default */
#if !defined LINKAGE
    #define LINKAGE extern
#endif

/* Generate message printing declaration */

#define MESSAGE(TYPE, NAME, MEMBERS) \
LINKAGE void \
MsgGenPrint_##TYPE(const TYPE * src, \
                   int depth); \


#define TYPE(BASE_TYPE, TYPE_NAME) \
LINKAGE void \
MsgGenPrint_##TYPE_NAME(const TYPE_NAME * src, \
                        int depth); \

/* No include guard for MSG_GEN_PRINT_H_ */

