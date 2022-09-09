#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/touch.h>

#include <iostream>

int sceTouchSetSamplingState(SceUInt32 port, SceTouchSamplingState state)
{
    return 0;
}

int sceTouchEnableTouchForce(SceUInt32 port)
{
    return 0;
}

int sceCtrlSetSamplingMode(SceCtrlPadInputMode mode)
{
    return 0;
}

int sceCtrlPeekBufferPositive(int port, SceCtrlData *pad_data, int count)
{
    return 0;
}
int sceTouchPeek(SceUInt32 port, SceTouchData *pData, SceUInt32 nBufs)
{
    return 0;
}
int sceTouchDisableTouchForce(SceUInt32 port)
{
    return 0;
}

