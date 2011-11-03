/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_DECLARE_ENCODERS_H_ */

/* Generates declarations for simple packed encoding */

/*
 * Encode the given msg type to a packed byte array
 *
 * TYPE: the type to decode, must be a single token
 * src: message to encode
 * dst: destination packed byte array
 */
#define MsgGenEncode(TYPE, src, dst) \
    MsgGenEncode_##TYPE(src, dst)

/* Extern declarations by default */
#if !defined LINKAGE
    #define LINKAGE extern
#endif

/* Generate message encoding declaration */
#define MESSAGE(TYPE, NAME, MEMBERS) \
LINKAGE uint8_t * \
MsgGenEncode_##TYPE(const TYPE * src, \
                    uint8_t* dst); \


#define TYPE(BASE_TYPE, TYPE_NAME) \
LINKAGE void \
MsgGenEncode_##TYPE_NAME(const TYPE_NAME * src, \
                         uint8_t* dst); \

/* No include guard for MSG_GEN_DECLARE_ENCODERS_H_ */

