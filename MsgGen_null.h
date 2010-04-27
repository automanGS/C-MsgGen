/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_NULL_H_ */

/* Defines null-generation x-macros.
 * Generates no code
 */
#define MESSAGE(TYPE, NAME, MEMBERS)
    #define MEMBER(TYPE, NAME)
    #define MEMBER_ARRAY(TYPE, NAME, LENGTH)
    #define MEMBER_FLEXARRAY(TYPE, NAME)
#define TYPE(BASE_TYPE, TYPE_NAME)

/* No include guard for MSG_GEN_NULL_H_ */

