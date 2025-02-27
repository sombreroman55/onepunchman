#ifndef bitwise_h
#define bitwise_h

#define BIT_SET(r, b) ((r) |= (1 << (b)))
#define BIT_RESET(r, b) ((r) &= ~(1 << (b)))
#define BIT_TOGGLE(r, b) ((r) ^= (1 << (b)))
#define BIT_READ(r, b) ((r) >> (b) & 1)

#endif
