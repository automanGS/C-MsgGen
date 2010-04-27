/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_WRAP_H_ */

/*
 * Declares encapsulated message structures by prefixing a header
 * structure.
 *
 * Optional Parameters:
 *    MSG_GEN_WRAP_HEADER_TYPE : typename of header
 */

/* Optional header type */
#if defined MSG_GEN_WRAP_HEADER_TYPE
    #define MESSAGE(TYPE, NAME, MEMBERS) \
        typedef struct WRAP_##NAME WRAP_##TYPE; \
        struct WRAP_##NAME { \
            MSG_GEN_WRAP_HEADER_TYPE hdr; \
            struct NAME content ; \
        };
#else
    #define MESSAGE(TYPE, NAME, MEMBERS) \
        typedef struct WRAP_##NAME WRAP_##TYPE; \
        struct WRAP_##NAME { \
            struct NAME content ; \
        };
#endif

#define MEMBER(TYPE, NAME)
#define MEMBER_ARRAY(TYPE, NAME, LENGTH)
#define TYPE(BASE_TYPE, TYPE_NAME)

/* No include guard for MSG_GEN_WRAP_H_ */

