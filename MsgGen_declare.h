/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_DECLARE_H_ */

/*
 * Generates message structure declarations
 */
#define MESSAGE(TYPE, NAME, MEMBERS) \
typedef struct NAME TYPE; \
struct NAME { \
    MEMBERS \
}; \

#define MEMBER(TYPE, NAME) \
        TYPE NAME ; \

#define MEMBER_ARRAY(TYPE, NAME, LENGTH) \
        TYPE NAME[LENGTH] ; \

#define MEMBER_FLEXARRAY(TYPE, NAME) \
        MEMBER_ARRAY(TYPE, NAME, ) \

#define TYPE(BASE_TYPE, TYPE_NAME) \
typedef BASE_TYPE TYPE_NAME; \

/* No include guard for MSG_GEN_DECLARE_H_ */

