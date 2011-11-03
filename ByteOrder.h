/*
 * Implementation of portable byte encoding and decoding.
 * 
 * Uses byte-oriented operations to avoid alignment issues.
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#ifndef BYTEORDER_H_
#define BYTEORDER_H_

/* Users should provide their own definitions for c99 stdint types.
 * We don't include them here.
 *
 * #include <stdint.h>
 */

#include "Endian.h"

/* Internal inlines  - use [be|le][16|32][enc|dec] functions instead */
static inline uint16_t Read16LE(uint8_t* src);
static inline uint32_t Read32LE(uint8_t* src);
static inline void Write16LE(uint8_t* dst, uint16_t src);
static inline void Write32LE(uint8_t* dst, uint32_t src);

/* Decode big-endian uint16 from byte array */
static inline uint16_t be16dec(const uint8_t *src)
{
    register uint16_t tmpBE = Read16LE((uint8_t*)src);
    return be16toh(tmpBE);
}

/* Decode big-endian uint32 from byte array */
static inline uint32_t be32dec(const uint8_t *src)
{
    register uint32_t tmpBE = Read32LE((uint8_t*)src);
    return be32toh(tmpBE);
}

/* Decode little-endian uint16 from byte array */
static inline uint16_t le16dec(const uint8_t *src)
{
    register uint16_t tmpLE = Read16LE((uint8_t*)src);
    return le16toh(tmpLE);
}

/* Decode little-endian uint32 from byte array */
static inline uint32_t le32dec(const uint8_t *src)
{
    register uint32_t tmpLE = Read32LE((uint8_t*)src);
    return le32toh(tmpLE);
}

/* Encode big-endian uint16 to byte array */
static inline void be16enc(uint8_t *dst, uint16_t src)
{
    Write16LE((uint8_t*) dst, htobe16(src));
}

/* Encode big-endian uint32 to byte array */
static inline void be32enc(uint8_t *dst, uint32_t src)
{
    Write32LE((uint8_t*) dst, htobe32(src));
}

/* Encode little-endian uint16 to byte array */
static inline void le16enc(uint8_t *dst, uint16_t src)
{
    Write16LE((uint8_t*) dst, htole16(src));
}

/* Encode little-endian uint32 to byte array */
static inline void le32enc(uint8_t *dst, uint32_t src)
{
    Write32LE((uint8_t*) dst, htole32(src));
}


/* Little endian decode two bytes to uint16 */
static inline uint16_t Read16LE(uint8_t* src)
{
    return (uint16_t) (src[0] | ((uint16_t)(src[1] << 8) ));
}

/* Little endian decode four bytes to uint32 */
static inline uint32_t Read32LE(uint8_t* src)
{
    return (uint32_t) (src[0]
                     + ((uint32_t)src[1] << 8)
                     + ((uint32_t)src[2] << 16)
                     + ((uint32_t)src[3] << 24) );
}

/* Little endian encode uint16_t to two bytes
 * Byte-aligned access 
 */
static inline void Write16LE(uint8_t* dst, uint16_t src)
{
    dst[0] = (uint8_t)(src & 0x00ffu);
    dst[1] = (uint8_t)((src & 0xff00u) >> 8);
}

/* Little endian encode uint32_t to four bytes
 * Byte-aligned access
 */
static inline void Write32LE(uint8_t* dst, uint32_t src)
{
    dst[0] = (uint8_t)((src >> 0) & 0x000000ffuL);
    dst[1] = (uint8_t)((src >> 8) & 0x000000ffuL);
    dst[2] = (uint8_t)((src >> 16) & 0x000000ffuL);
    dst[3] = (uint8_t)((src >> 24) & 0x000000ffuL);
}

#endif // BYTEORDER_H_
