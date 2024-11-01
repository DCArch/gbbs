#ifndef __DCSIMHOOKS_H__
#define __DCSIMHOOKS_H__

#include <stdio.h>

// Per thread ROI start and end
static inline void DCSimStartROI()
{
    // printf("DCSimHooks: Starting Region of Interest\n");
    // Create a multi byte NOP with a special operand: FEED C0DE
    __asm__ __volatile__
    (
        ".byte 0x0F, 0x1F, 0x80, 0xDE, 0xC0, 0xED, 0xFE ;\n\t"
        :
        :
        : "memory"
    );
}

static inline void DCSimEndROI()
{
    // printf("DCSimHooks: Ending Region of Interest\n");
    // Create a multi byte NOP with a special operand: C0001 0FF
    __asm__ __volatile__
    (
        ".byte 0x0F, 0x1F, 0x80, 0xDE, 0xC0, 0xAD, 0xDE ;\n\t"
        :
        :
        : "memory"
    );
}

#endif //__DCSIMHOOKS_H__
