/*
 vintageVoice.cpp
 
 Created by Liam Lacey on 29/01/2016.
 Copyright 2016 Liam Lacey. All rights reserved.
 */

#ifndef ____vintageVoice__
#define ____vintageVoice__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <poll.h>
#include <signal.h>
#include <sched.h>
#include <time.h>
#include <netdb.h>
#include <memory.h>
#include <ifaddrs.h>
#include <stdarg.h>
#include <math.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/termios.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <linux/spi/spidev.h>
#include <linux/sockios.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <iostream>

#include "../globals.h"
#include "Maximilian/maximilian.h"

class VintageVoice
{
public:
    VintageVoice (uint8_t voice_num);
    ~VintageVoice();
    
    void processAudio (double *output);
    
    void setOscPitch (uint8_t midi_note_num);
    
private:
    
    //maximilian objects
    maxiOsc oscSquare;
    
    //'patch' parameters
    
    //other parameters
    double oscPitch;
};

#endif /* defined(____vintageVoice__) */
