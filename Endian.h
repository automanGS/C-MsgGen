/*
 * Implementation of portable byte-swap macros.
 *
 * Author: mark AT cognomen DOT co DOT uk
 * Dedicated to the public domain. Use it as you wish.
 */
#if !defined ENDIAN_H_
#define ENDIAN_H_

#include <stdint.h>

#define bswap16(x) \
    ((((x) >> 8) & 0x00ffu) | \
     (((x) << 8) & 0xff00u))

#define bswap32(x) \
    ((((x) >> 24) & 0x000000ffuL) |  \
     (((x) >>  8) & 0x0000ff00uL) |  \
     (((x) <<  8) & 0x00ff0000uL) |  \
     (((x) << 24) & 0xff000000uL ))        

         
#define htobe16(x) ((uint16_t)bswap16(x))
#define htobe32(x) ((uint32_t)bswap32(x))

#define be16toh(x) ((uint16_t)bswap16(x))
#define be32toh(x) ((uint32_t)bswap32(x))

#define htole16(x) ((uint16_t)(x))
#define htole32(x) ((uint32_t)(x))

#define le16toh(x) ((uint16_t)(x))
#define le32toh(x) ((uint32_t)(x))

#endif // ENDIAN_H_

