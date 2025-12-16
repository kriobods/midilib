#ifndef _ENDIAN_H
#define _ENDIAN_H

/* Simple endian header for embedded systems */
#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN    4321

/* Raspberry Pi Pico is little-endian */
#define __BYTE_ORDER __LITTLE_ENDIAN

/* Basic byte swap functions if needed */
#define __bswap_16(x) ((uint16_t)((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))
#define __bswap_32(x) ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >>  8) | \
                       (((x) & 0x0000ff00u) <<  8) | (((x) & 0x000000ffu) << 24))

#endif
