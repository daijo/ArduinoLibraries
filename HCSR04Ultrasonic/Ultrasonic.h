/*
 * Ultrasonic.h - Library for HC-SR04 Ultrasonic Sensing Module.
 *
 * With ideas from:
 *   Created by ITead studio. Alex, Apr 20, 2010.
 *   iteadstudio.com
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 12:47:57 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 31 $
 * ----------------------------------
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stddef.h>
#include <WProgram.h>

// Undefine COMPILE_STD_DEV if you don't want Standard Deviation.
#define COMPILE_STD_DEV


typedef struct bufferCtl
    {
    float *pBegin;
    float *pIndex;
    size_t length;
    bool filled;
    } BufCtl;

class Ultrasonic
    {
    public:
    Ultrasonic(int tp, int ep);
    long timing();
    float convert(long microsec, int metric);
    void setDivisor(float value, int metric);
    static const int IN = 0;
    static const int CM = 1;

#ifdef COMPILE_STD_DEV
    bool sampleCreate(size_t size, ...);
    void sampleClear();
    float unbiasedStdDev(float value, size_t bufNum);
#endif // COMPILE_STD_DEV

    private:
    int _trigPin;
    int _echoPin;
    float _cmDivisor;
    float _inDivisor;

#ifdef COMPILE_STD_DEV
    size_t _numBufs;
    BufCtl *_pBuffers;
    void _sampleUpdate(BufCtl *buf, float msec);
    void _freeBuffers();
#endif // COMPILE_STD_DEV
    };

#endif // ULTRASONIC_H
