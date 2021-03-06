///
//  globals.h
//
//  Created by Liam Lacey on 28/01/2016.
//
//
//

//==========================================================================
//Socket stuff.
//I needed to create the vintageToySynthProject directory in order for these sockets to be setup

//server socket
#define SOCK_BRAIN_FILENAME "/var/vintageToySynthProject/vintageBrain.serv"

//client sockets
#define SOCK_SOUND_ENGINE_FILENAME "/var/vintageToySynthProject/vintageSoundEngine.cli"

//==========================================================================
#define NUM_OF_VOICES 2

//==========================================================================
#define VOICE_MONO_BUFFER_SIZE 18
#define VOICE_NO_NOTE -1

//this value must not be smaller than NUM_OF_VOICES or VOICE_MONO_BUFFER_SIZE
#define VOICE_ALLOC_NOTE_BUFFER_SIZE 18

//==========================================================================
//MIDI defines

#define MIDI_NOTEOFF 0x80
#define MIDI_NOTEON 0x90
#define MIDI_PAT 0xA0
#define MIDI_CC 0xB0
#define MIDI_PROGRAM_CHANGE 0xC0
#define MIDI_CAT 0xD0
#define MIDI_PITCH_BEND 0xE0

#define MIDI_NOTEOFF_MAX 0x8F
#define MIDI_NOTEON_MAX 0x9F
#define MIDI_PAT_MAX 0xAF
#define MIDI_CC_MAX 0xBF
#define MIDI_PROGRAM_CHANGE_MAX 0xCF
#define MIDI_CAT_MAX 0xDF
#define MIDI_PITCH_BEND_MAX 0xEF

#define MIDI_CLOCK 0xF8
#define MIDI_CLOCK_START 0xFA
#define MIDI_CLOCK_CONTINUE 0xFB
#define MIDI_CLOCK_STOP 0xFC

#define MIDI_SYSEX_START 0xF0
#define MIDI_SYSEX_END 0xF7

#define MIDI_CHANNEL_BITS 0b00001111
#define MIDI_STATUS_BITS 0b11110000

//==========================================================================
//Patch parameter CC numbers

//Osc
#define PARAM_OSC_SINE_LEVEL 14
#define PARAM_OSC_TRI_LEVEL 15
#define PARAM_OSC_SAW_LEVEL 16
#define PARAM_OSC_PULSE_LEVEL 17
#define PARAM_OSC_PULSE_AMOUNT 3
#define PARAM_OSC_SQUARE_LEVEL 18
#define PARAM_OSC_SINE_NOTE 33
#define PARAM_OSC_TRI_NOTE 34
#define PARAM_OSC_SAW_NOTE 35
#define PARAM_OSC_PULSE_NOTE 36
#define PARAM_OSC_SQUARE_NOTE 37
#define PARAM_OSC_PHASE_SPREAD 20

//Filter
#define PARAM_FILTER_FREQ 74
#define PARAM_FILTER_RESO 19
#define PARAM_FILTER_LP_MIX 26
#define PARAM_FILTER_BP_MIX 27
#define PARAM_FILTER_HP_MIX 28
#define PARAM_FILTER_NOTCH_MIX 29

//AEG
#define PARAM_AEG_ATTACK 73
#define PARAM_AEG_DECAY 75
#define PARAM_AEG_SUSTAIN 79
#define PARAM_AEG_RELEASE 72
#define PARAM_AEG_AMOUNT 7

//FEG
#define PARAM_FEG_ATTACK 22
#define PARAM_FEG_DECAY 23
#define PARAM_FEG_SUSTAIN 24
#define PARAM_FEG_RELEASE 25

//LFO
#define PARAM_LFO_SHAPE 50
#define PARAM_LFO_RATE 47
#define PARAM_LFO_DEPTH 48

//Keys
#define PARAM_KEYS_OCTAVE 114
#define PARAM_KEYS_SCALE 102
#define PARAM_KEYS_TRANSPOSE 106

//Voice
#define PARAM_VOICE_MODE 103

//Modulation depths
#define PARAM_MOD_VEL_AMP 63
#define PARAM_MOD_VEL_FREQ 109
#define PARAM_MOD_VEL_RESO 110
#define PARAM_MOD_LFO_AMP 58
#define PARAM_MOD_LFO_FREQ 112
#define PARAM_MOD_LFO_RESO 56
//Not currently used
#define PARAM_MOD_AT_FREQ 90
#define PARAM_MOD_AT_LFO_DEPTH 89

//Effects
#define PARAM_FX_DISTORTION_AMOUNT 13

//Global
#define PARAM_GLOBAL_VINTAGE_AMOUNT 107
#define PARAM_GLOBAL_VOLUME 9

//CC only used between the brain and voice
#define PARAM_UPDATE_NOTE_PITCH 126

//special CC num used for sending commands rather than settings
#define PARAM_CMD 127

//==========================================================================
#define KEYBOARD_NUM_OF_KEYS 18
#define KEYBOARD_NUM_OF_SCALES 8

const int keyboardScales[KEYBOARD_NUM_OF_SCALES][KEYBOARD_NUM_OF_KEYS] =
{
    //chromatic
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17},
    //major
    {0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19, 21, 23, 24, 26, 28, 29},
    //major pentatonic
    {0, 2, 4, 7, 9, 12, 14, 16, 19, 21, 24, 26, 28, 31, 33, 36, 38, 40},
    //minor
    {0, 2, 3, 5, 7, 8, 10, 12, 14, 15, 17, 19, 20, 22, 24, 26, 27, 29},
    //minor pentatonic
    {0, 3, 5, 7, 10, 12, 15, 17, 19, 22, 24, 27, 29, 31, 34, 36, 39, 41},
    //melodic minor
    {0, 2, 3, 5, 7, 9, 11, 12, 14, 15, 17, 19, 21, 23, 24, 26, 27, 29},
    //harmonic minor
    {0, 2, 3, 5, 7, 8, 11, 12, 14, 15, 17, 19, 20, 23, 24, 26, 27, 29},
    //blues
    {0, 3, 5, 6, 7, 10, 12, 15, 17, 18, 19, 22, 24, 27, 29, 30, 31, 34}
};

//==========================================================================
//command parameter (127) values

#define CMD_KILL_ALL_VOICES 0
#define CMD_REQUEST_PANEL_PARAM_DATA 1
#define CMD_REQUEST_ALL_PATCH_DATA 2
#define CMD_SENT_ALL_PATCH_DATA 3
#define CMD_DISABLE_PANEL 4
#define CMD_ENABLE_PANEL 5

//==========================================================================
//structure that stores info about a patch parameter

typedef struct
{
    uint8_t user_val;
    uint8_t user_min_val;
    uint8_t user_max_val;
    bool sound_param; //sets whether the paramater needs to be sent to the sound engine or not
    bool patch_param; //sets whether this is actually a patch parameter or just a utility CC
    double voice_val;
    double voice_min_val;
    double voice_max_val;
    //Sets the skew factor of scaling between user and voice value.
    //1.0 gives linear scaling, less than 1.0 gives more control in the lower end (exp scaling),
    //and greater than 1.0 give more control in the upper end (log scaling).
    float skew_factor;
    //for easier debugging
    uint8_t param_name[32];

} PatchParameterData;

//array that stores the default data for all patch parameters

static const PatchParameterData defaultPatchParameterData[128] =
{
    {}, //0
    {}, //1
    {}, //2
    {90, 0, 127, true, true, 0.7, 0., 1., 1.0, "OSC PULSE AMOUNT"}, //3 - PARAM_OSC_PULSE_AMOUNT
    {}, //4
    {}, //5
    {}, //6
    {127, 0, 127, true, true, 0.6, 0., 1., 1.0, "AEG AMOUNT"}, //7 - PARAM_AEG_AMOUNT
    {}, //8
    {80, 0, 100, false, false, 80, 0, 100, 1.0, "GLOBAL VOLUME"}, //9 - PARAM_GLOBAL_VOLUME
    {}, //10
    {}, //11
    {}, //12
    {0, 0, 127, true, true, 0, 0., 1., 0.5, "DISTORTION AMOUNT"}, //13 - PARAM_FX_DISTORTION_AMOUNT
    {127, 0, 127, true, true, 0., 0., 1., 1.0, "OSC SINE LEVEL"}, //14 - PARAM_OSC_SINE_LEVEL
    {127, 0, 127, true, true, 0., 0., 1., 1.0, "OSC TRI LEVEL"}, //15 - PARAM_OSC_TRI_LEVEL
    {127, 0, 127, true, true, 1., 0., 1., 1.0, "OSC SAW LEVEL"}, //16 - PARAM_OSC_SAW_LEVEL
    {127, 0, 127, true, true, 0., 0., 1., 1.0, "OSC PULSE LEVEL"}, //17 - PARAM_OSC_PULSE_LEVEL
    {127, 0, 127, true, true, 0., 0., 1., 1.0, "OSC SQUARE LEVEL"}, //18 - PARAM_OSC_SQUARE_LEVEL
    {5, 0, 127, true, true, 0.1, 0.1, 30., 0.5, "FILTER RESO"}, //19 - PARAM_FILTER_RESO
    {0, 0, 127, true, true, 10, 0, 100, 1.0, "OSC PHASE SPREAD"}, //20 - PARAM_OSC_PHASE_SPREAD
    {}, //21
    {0, 0, 127, true, true, 0, 0, 20000, 0.5, "FEG ATTACK"}, //22 - PARAM_FEG_ATTACK
    {2, 0, 127, true, true, 400, 0, 5000, 0.5, "FEG DECAY"}, //23 - PARAM_FEG_DECAY
    {20, 0, 127, true, true, 0.7, 0., 1., 1.0, "FEG SUSTAIN"}, //24 - PARAM_FEG_SUSTAIN
    {20, 0, 127, true, true, 3000, 0, 10000, 0.5, "FEG RELEASE"}, //25 - PARAM_FEG_RELEASE
    {127, 0, 127, true, true, 1., 0, 1., 1.0, "FILTER LP MIX"}, //26 - PARAM_FILTER_LP_MIX
    {0, 0, 127, true, true, 0., 0, 1., 1.0, "FILTER BP MIX"}, //27 - PARAM_FILTER_BP_MIX
    {0, 0, 127, true, true, 0., 0, 1., 1.0, "FILTER HP MIX"}, //28 - PARAM_FILTER_HP_MIX
    {0, 0, 127, true, true, 0., 0, 1., 1.0, "FILTER NOTCH MIX"}, //29 - PARAM_FILTER_NOTCH_MIX
    {}, //30
    {}, //31
    {}, //32
    {64, 40, 88, true, true, 64, 40, 88, 1.0, "OSC SINE NOTE"}, //33 - PARAM_OSC_SINE_NOTE
    {64, 40, 88, true, true, 64, 40, 88, 1.0, "OSC TRI NOTE"}, //34 - PARAM_OSC_TRI_NOTE
    {64, 40, 88, true, true, 64, 40, 88, 1.0, "OSC SAW NOTE"}, //35 - PARAM_OSC_SAW_NOTE
    {64, 40, 88, true, true, 64, 40, 88, 1.0, "OSC PULSE NOTE"}, //36 - PARAM_OSC_PULSE_NOTE
    {52, 40, 88, true, true, 52, 40, 88, 1.0, "OSC SQUARE NOTE"}, //37 - PARAM_OSC_SQUARE_NOTE
    {}, //38
    {}, //39
    {}, //40
    {}, //41
    {}, //42
    {}, //43
    {}, //44
    {}, //45
    {}, //46
    {1, 0, 127, true, true, 1, 0.01, 30, 0.5, "LFO RATE"}, //47 - PARAM_LFO_RATE
    {64, 1, 127, true, true, 1., -1., 1., 1.0, "LFO DEPTH"}, //48 - PARAM_LFO_DEPTH
    {}, //49
    {0, 0, 3, true, true, 0, 0, 3, 1.0, "LFO SHAPE"}, //50 - PARAM_LFO_SHAPE
    {}, //51
    {}, //52
    {}, //53
    {}, //54
    {}, //55
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "LFO -> RESO"}, //56 - PARAM_MOD_LFO_RESO
    {}, //57
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "LFO -> AMP"}, //58 - PARAM_MOD_LFO_AMP
    {}, //59
    {}, //60
    {}, //61
    {}, //62
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "VEL -> AMP"}, //63 - PARAM_MOD_VEL_AMP
    {}, //64
    {}, //65
    {}, //66
    {}, //67
    {}, //68
    {}, //69
    {}, //70
    {}, //71
    {20, 0, 127, true, true, 2000, 0, 10000, 0.5, "AEG RELEASE"}, //72 - PARAM_AEG_RELEASE
    {0, 0, 127, true, true, 0, 0, 20000, 0.5, "AEG ATTACK"}, //73 - PARAM_AEG_ATTACK
    {20, 0, 127, true, true, 5000, 50, 15000, 1.0, "FILTER CUTOFF"}, //74 - PARAM_FILTER_FREQ
    {2, 0, 127, true, true, 200, 0, 5000, 0.5, "AEG DECAY"}, //75 - PARAM_AEG_DECAY
    {}, //76
    {}, //77
    {}, //78
    {20, 0, 127, true, true, 0.2, 0., 1., 1.0, "AEG SUSTAIN"}, //79 - PARAM_AEG_SUSTAIN
    {}, //80
    {}, //81
    {}, //82
    {}, //83
    {}, //84
    {}, //85
    {}, //86
    {}, //87
    {}, //88
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "AT -> LFO DEPTH"}, //89 - PARAM_MOD_AT_LFO_DEPTH
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "AT -> CUTOFF"}, //90 - PARAM_MOD_AT_FREQ
    {}, //91
    {}, //92
    {}, //93
    {}, //94
    {}, //95
    {}, //96
    {}, //97
    {}, //98
    {}, //99
    {}, //100
    {}, //101
    {1, 0, KEYBOARD_NUM_OF_SCALES-1, false, true, 0, 0, 0, 1.0, "KEYBOARD SCALE"}, //102 - PARAM_KEYS_SCALE
    {127, 0, 127, false, true, 0, 0, 0, 1.0, "VOICE MODE"}, //103 - PARAM_VOICE_MODE
    {}, //104
    {}, //105
    {64, 58, 70, false, true, 0, 0, 0, 1.0, "KEYBOARD TRANSPOSE"}, //106 - PARAM_KEYS_TRANSPOSE
    {0, 0, 127, true, true, 0, 0, 127, 1.0, "VINTAGE AMOUNT"}, //107 - PARAM_GLOBAL_VINTAGE_AMOUNT
    {}, //108
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "VEL -> CUTOFF"}, //109 - PARAM_MOD_VEL_FREQ
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "VEL -> RESO"}, //110 - PARAM_MOD_VEL_RESO
    {}, //111
    {64, 1, 127, true, true, 0., -1., 1., 1.0, "LFO -> CUTOFF"}, //112 - PARAM_MOD_LFO_FREQ
    {}, //113
    {64, 61, 67, false, true, 0, 0, 0, 1.0, "KEYBOARD OCTAVE"}, //114 - PARAM_KEYS_OCTAVE
    {}, //115
    {}, //116
    {}, //117
    {}, //118
    {}, //119
    {}, //120
    {}, //121
    {}, //122
    {}, //123
    {}, //124
    {}, //125
    {0, 0, 127, true, false, 0, 0, 127, 1.0, "UPDATE NOTE PITCH"},  //126 - PARAM_UPDATE_NOTE_PITCH
    {0, 0, 127, false, false, 0, 0, 0, 1.0, "COMMAND CC"}  //127 - PARAM_CMD
};


//===================================================================
//Function that scales a number to a new number based on a new range

static float scaleValue (float value, float minValue, float maxValue, float minRange, float maxRange, float skewFactor)
{
    //minValue is the min range of the value coming in.
    //maxValue is the max range of the value coming in.
    //minRange is the min range of the value going out.
    //maxRange is the max range of the value going out.
    
    //if we want a log or exp scaling...
    if (skewFactor != 1.0 && skewFactor > 0)
    {
        //set proportion based on the skewFactor value...
        
        //scale value into a value between 0 and 1
        float proportion = (1.0 * (value - minValue)) / (maxValue - minValue);
        
        //scale proportion with the skew factor
        proportion = exp (log (proportion) / skewFactor);
        
        //scale proportion into a value between minRange and maxRange
        return ((((maxRange - minRange) * proportion) / 1.0) + minRange);
        
    } //if (skewFactor != 1.0 && skewFactor > 0)
    
    //else we just want a linear scaling
    else
    {
        return ((((maxRange - minRange) * (value - minValue)) / (maxValue - minValue)) + minRange);
    }
}