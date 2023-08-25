#include <string.h>
#include <unistd.h>

extern void *sos_calloc(unsigned nelem, unsigned size);
extern void sos_free(void *p);
extern int sos_printf(const char *fmt, ...);

#define dbg sos_printf
//#define pico_zalloc(x) sos_malloc(x)
#define pico_free(x) sos_free(x)

static inline void *pico_zalloc(size_t bytes)
{
    void *ptr = sos_calloc(1, bytes);

    return ptr;
}

extern volatile uint32_t pico_stick;

static inline unsigned long PICO_TIME(void)
{
    register uint32_t tick = pico_stick;
    return tick / 1000;
}

static inline unsigned long PICO_TIME_MS(void)
{
    return pico_stick;
}

static inline void PICO_IDLE(void)
{
    unsigned long tick_now = pico_stick;
    while(tick_now == pico_stick) ;
}

