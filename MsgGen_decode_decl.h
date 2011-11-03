/*
 * MsgGen - portable serialization library
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */

/* No include guard for MSG_GEN_DECLARE_DECODERS_H_ */

/* Generates declarations for simple packed decoding */

/*
 * Decode the given msg type from a packed byte array
 *
 * TYPE: the type to decode, must be a single token
 * src: packed byte array to decode
 * dst: destination decoded message
 */
#define MsgGenDecode(TYPE, src, dst) \
    MsgGenDecode_##TYPE(src, dst)

/* Extern declarations by default */
#if !defined LINKAGE
    #define LINKAGE extern
#endif

/* Generate message decoding declaration */
#define MESSAGE(TYPE, NAME, MEMBERS) \
LINKAGE TYPE * \
MsgGenDecode_##TYPE(const uint8_t* src, \
                    TYPE * dst); \


#define TYPE(BASE_TYPE, TYPE_NAME) \
LINKAGE void \
MsgGenDecode_##TYPE_NAME(const uint8_t* src, \
                         TYPE_NAME * dst); \

/* No include guard for MSG_GEN_DECLARE_DECODERS_H_ */

