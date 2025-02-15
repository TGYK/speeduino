#ifndef CRANKMATHS_H
#define CRANKMATHS_H

#include "maths.h"

#define CRANKMATH_METHOD_INTERVAL_DEFAULT  0
#define CRANKMATH_METHOD_INTERVAL_REV      1
#define CRANKMATH_METHOD_INTERVAL_TOOTH    2
#define CRANKMATH_METHOD_ALPHA_BETA        3
#define CRANKMATH_METHOD_2ND_DERIVATIVE    4

#define SECOND_DERIV_ENABLED                0          

//#define fastDegreesToUS(targetDegrees) ((targetDegrees) * (unsigned long)timePerDegree)
#define fastDegreesToUS(targetDegrees) (((targetDegrees) * (unsigned long)timePerDegreex16) >> 4)
/*#define fastTimeToAngle(time) (((unsigned long)time * degreesPeruSx2048) / 2048) */ //Divide by 2048 will be converted at compile time to bitshift
#define fastTimeToAngle(time) (((unsigned long)(time) * degreesPeruSx32768) / 32768) //Divide by 32768 will be converted at compile time to bitshift

#define ignitionLimits(angle) ( (((int16_t)(angle)) >= CRANK_ANGLE_MAX_IGN) ? ((angle) - CRANK_ANGLE_MAX_IGN) : ( ((int16_t)(angle) < 0) ? ((angle) + CRANK_ANGLE_MAX_IGN) : (angle)) )


unsigned long angleToTime(uint16_t angle, byte method);
inline unsigned long angleToTimeIntervalRev(uint16_t angle) {
    return div360(angle * revolutionTime);
}
uint16_t timeToAngle(unsigned long time, byte method);
void doCrankSpeedCalcs(void);

extern volatile uint16_t timePerDegree;
extern volatile uint16_t timePerDegreex16;
extern volatile unsigned long degreesPeruSx32768;

#endif