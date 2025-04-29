#include "TimeTick.h"

uint32_t timeTick = 0;

void incTick()
{
	timeTick++;
}

void clearTick()
{
	timeTick = 0;
}

uint32_t getTick()
{
	return timeTick;
}