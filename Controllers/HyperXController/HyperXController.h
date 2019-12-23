/*-----------------------------------------*\
|  HyperXController.h                       |
|                                           |
|  Definitions and types for HyperX Predator|
|  RGB RAM lighting controller              |
|                                           |
|  Adam Honse (CalcProgrammer1) 6/29/2019   |
\*-----------------------------------------*/

#include <string>
#include "i2c_smbus.h"

#pragma once

typedef unsigned char	hyperx_dev_id;
typedef unsigned short	hyperx_register;

enum
{
    HYPERX_REG_SLOT0_LED0_RED           = 0x11,     /* R color register for LED 0, Slot 0   */
    HYPERX_REG_SLOT0_LED0_GREEN         = 0x12,     /* G color register for LED 0, Slot 0   */
    HYPERX_REG_SLOT0_LED0_BLUE          = 0x13,     /* B color register for LED 0, Slot 0   */
    HYPERX_REG_SLOT0_LED1_RED           = 0x14,     /* R color register for LED 1, Slot 0   */
    HYPERX_REG_SLOT0_LED1_GREEN         = 0x15,     /* G color register for LED 1, Slot 0   */
    HYPERX_REG_SLOT0_LED1_BLUE          = 0x16,     /* B color register for LED 1, Slot 0   */
    HYPERX_REG_SLOT0_LED2_RED           = 0x17,     /* R color register for LED 2, Slot 0   */
    HYPERX_REG_SLOT0_LED2_GREEN         = 0x18,     /* G color register for LED 2, Slot 0   */
    HYPERX_REG_SLOT0_LED2_BLUE          = 0x19,     /* B color register for LED 2, Slot 0   */
    HYPERX_REG_SLOT0_LED3_RED           = 0x1A,     /* R color register for LED 3, Slot 0   */
    HYPERX_REG_SLOT0_LED3_GREEN         = 0x1B,     /* G color register for LED 3, Slot 0   */
    HYPERX_REG_SLOT0_LED3_BLUE          = 0x1C,     /* B color register for LED 3, Slot 0   */
    HYPERX_REG_SLOT0_LED4_RED           = 0x1D,     /* R color register for LED 4, Slot 0   */
    HYPERX_REG_SLOT0_LED4_GREEN         = 0x1E,     /* G color register for LED 4, Slot 0   */
    HYPERX_REG_SLOT0_LED4_BLUE          = 0x1F,     /* B color register for LED 4, Slot 0   */
    HYPERX_REG_SLOT0_LED0_BRIGHTNESS    = 0x21,     /* Brightness for LED 0, Slot 0 (0-100) */
    HYPERX_REG_SLOT0_LED1_BRIGHTNESS    = 0x24,     /* Brightness for LED 1, Slot 0 (0-100) */
    HYPERX_REG_SLOT0_LED2_BRIGHTNESS    = 0x27,     /* Brightness for LED 2, Slot 0 (0-100) */
    HYPERX_REG_SLOT0_LED3_BRIGHTNESS    = 0x2A,     /* Brightness for LED 3, Slot 0 (0-100) */
    HYPERX_REG_SLOT0_LED4_BRIGHTNESS    = 0x2D,     /* Brightness for LED 4, Slot 0 (0-100) */

    HYPERX_REG_SLOT1_LED0_RED           = 0x41,     /* R color register for LED 0, Slot 1   */
    HYPERX_REG_SLOT1_LED0_GREEN         = 0x42,     /* G color register for LED 0, Slot 1   */
    HYPERX_REG_SLOT1_LED0_BLUE          = 0x43,     /* B color register for LED 0, Slot 1   */
    HYPERX_REG_SLOT1_LED1_RED           = 0x44,     /* R color register for LED 1, Slot 1   */
    HYPERX_REG_SLOT1_LED1_GREEN         = 0x45,     /* G color register for LED 1, Slot 1   */
    HYPERX_REG_SLOT1_LED1_BLUE          = 0x46,     /* B color register for LED 1, Slot 1   */
    HYPERX_REG_SLOT1_LED2_RED           = 0x47,     /* R color register for LED 2, Slot 1   */
    HYPERX_REG_SLOT1_LED2_GREEN         = 0x48,     /* G color register for LED 2, Slot 1   */
    HYPERX_REG_SLOT1_LED2_BLUE          = 0x49,     /* B color register for LED 2, Slot 1   */
    HYPERX_REG_SLOT1_LED3_RED           = 0x4A,     /* R color register for LED 3, Slot 1   */
    HYPERX_REG_SLOT1_LED3_GREEN         = 0x4B,     /* G color register for LED 3, Slot 1   */
    HYPERX_REG_SLOT1_LED3_BLUE          = 0x4C,     /* B color register for LED 3, Slot 1   */
    HYPERX_REG_SLOT1_LED4_RED           = 0x4D,     /* R color register for LED 4, Slot 1   */
    HYPERX_REG_SLOT1_LED4_GREEN         = 0x4E,     /* G color register for LED 4, Slot 1   */
    HYPERX_REG_SLOT1_LED4_BLUE          = 0x4F,     /* B color register for LED 4, Slot 1   */
    HYPERX_REG_SLOT1_LED0_BRIGHTNESS    = 0x51,     /* Brightness for LED 0, Slot 1 (0-100) */
    HYPERX_REG_SLOT1_LED1_BRIGHTNESS    = 0x54,     /* Brightness for LED 1, Slot 1 (0-100) */
    HYPERX_REG_SLOT1_LED2_BRIGHTNESS    = 0x57,     /* Brightness for LED 2, Slot 1 (0-100) */
    HYPERX_REG_SLOT1_LED3_BRIGHTNESS    = 0x5A,     /* Brightness for LED 3, Slot 1 (0-100) */
    HYPERX_REG_SLOT1_LED4_BRIGHTNESS    = 0x5D,     /* Brightness for LED 4, Slot 1 (0-100) */

    HYPERX_REG_SLOT2_LED0_RED           = 0x71,     /* R color register for LED 0, Slot 2   */
    HYPERX_REG_SLOT2_LED0_GREEN         = 0x72,     /* G color register for LED 0, Slot 2   */
    HYPERX_REG_SLOT2_LED0_BLUE          = 0x73,     /* B color register for LED 0, Slot 2   */
    HYPERX_REG_SLOT2_LED1_RED           = 0x74,     /* R color register for LED 1, Slot 2   */
    HYPERX_REG_SLOT2_LED1_GREEN         = 0x75,     /* G color register for LED 1, Slot 2   */
    HYPERX_REG_SLOT2_LED1_BLUE          = 0x76,     /* B color register for LED 1, Slot 2   */
    HYPERX_REG_SLOT2_LED2_RED           = 0x77,     /* R color register for LED 2, Slot 2   */
    HYPERX_REG_SLOT2_LED2_GREEN         = 0x78,     /* G color register for LED 2, Slot 2   */
    HYPERX_REG_SLOT2_LED2_BLUE          = 0x79,     /* B color register for LED 2, Slot 2   */
    HYPERX_REG_SLOT2_LED3_RED           = 0x7A,     /* R color register for LED 3, Slot 2   */
    HYPERX_REG_SLOT2_LED3_GREEN         = 0x7B,     /* G color register for LED 3, Slot 2   */
    HYPERX_REG_SLOT2_LED3_BLUE          = 0x7C,     /* B color register for LED 3, Slot 2   */
    HYPERX_REG_SLOT2_LED4_RED           = 0x7D,     /* R color register for LED 4, Slot 2   */
    HYPERX_REG_SLOT2_LED4_GREEN         = 0x7E,     /* G color register for LED 4, Slot 2   */
    HYPERX_REG_SLOT2_LED4_BLUE          = 0x7F,     /* B color register for LED 4, Slot 2   */
    HYPERX_REG_SLOT2_LED0_BRIGHTNESS    = 0x81,     /* Brightness for LED 0, Slot 2 (0-100) */
    HYPERX_REG_SLOT2_LED1_BRIGHTNESS    = 0x84,     /* Brightness for LED 1, Slot 2 (0-100) */
    HYPERX_REG_SLOT2_LED2_BRIGHTNESS    = 0x87,     /* Brightness for LED 2, Slot 2 (0-100) */
    HYPERX_REG_SLOT2_LED3_BRIGHTNESS    = 0x8A,     /* Brightness for LED 3, Slot 2 (0-100) */
    HYPERX_REG_SLOT2_LED4_BRIGHTNESS    = 0x8D,     /* Brightness for LED 4, Slot 2 (0-100) */

    HYPERX_REG_SLOT3_LED0_RED           = 0xA1,     /* R color register for LED 0, Slot 3   */
    HYPERX_REG_SLOT3_LED0_GREEN         = 0xA2,     /* G color register for LED 0, Slot 3   */
    HYPERX_REG_SLOT3_LED0_BLUE          = 0xA3,     /* B color register for LED 0, Slot 3   */
    HYPERX_REG_SLOT3_LED1_RED           = 0xA4,     /* R color register for LED 1, Slot 3   */
    HYPERX_REG_SLOT3_LED1_GREEN         = 0xA5,     /* G color register for LED 1, Slot 3   */
    HYPERX_REG_SLOT3_LED1_BLUE          = 0xA6,     /* B color register for LED 1, Slot 3   */
    HYPERX_REG_SLOT3_LED2_RED           = 0xA7,     /* R color register for LED 2, Slot 3   */
    HYPERX_REG_SLOT3_LED2_GREEN         = 0xA8,     /* G color register for LED 2, Slot 3   */
    HYPERX_REG_SLOT3_LED2_BLUE          = 0xA9,     /* B color register for LED 2, Slot 3   */
    HYPERX_REG_SLOT3_LED3_RED           = 0xAA,     /* R color register for LED 3, Slot 3   */
    HYPERX_REG_SLOT3_LED3_GREEN         = 0xAB,     /* G color register for LED 3, Slot 3   */
    HYPERX_REG_SLOT3_LED3_BLUE          = 0xAC,     /* B color register for LED 3, Slot 3   */
    HYPERX_REG_SLOT3_LED4_RED           = 0xAD,     /* R color register for LED 4, Slot 3   */
    HYPERX_REG_SLOT3_LED4_GREEN         = 0xAE,     /* G color register for LED 4, Slot 3   */
    HYPERX_REG_SLOT3_LED4_BLUE          = 0xAF,     /* B color register for LED 4, Slot 3   */
    HYPERX_REG_SLOT3_LED0_BRIGHTNESS    = 0xB1,     /* Brightness for LED 0, Slot 3 (0-100) */
    HYPERX_REG_SLOT3_LED1_BRIGHTNESS    = 0xB4,     /* Brightness for LED 1, Slot 3 (0-100) */
    HYPERX_REG_SLOT3_LED2_BRIGHTNESS    = 0xB7,     /* Brightness for LED 2, Slot 3 (0-100) */
    HYPERX_REG_SLOT3_LED3_BRIGHTNESS    = 0xBA,     /* Brightness for LED 3, Slot 3 (0-100) */
    HYPERX_REG_SLOT3_LED4_BRIGHTNESS    = 0xBD,     /* Brightness for LED 4, Slot 3 (0-100) */

    HYPERX_REG_EFFECT_BRIGHTNESS        = 0xDD,     /* Brightness for effects (0-100)       */
    HYPERX_REG_APPLY                    = 0xE1,     /* Apply changes register               */
    HYPERX_REG_MODE1                    = 0xE3,     /* Mode control register 1              */
    HYPERX_REG_MODE2                    = 0xE4,     /* Mode control register 2              */
    HYPERX_REG_MODE3                    = 0xE5,     /* Mode control register 3              */
    HYPERX_REG_EFFECT_RED               = 0xEC,     /* Red color register for effects       */
    HYPERX_REG_EFFECT_GREEN             = 0xED,     /* Green color register for effects     */
    HYPERX_REG_EFFECT_BLUE              = 0xEE,     /* Blue color register for effects      */
};

enum
{
    HYPERX_MODE1_RAINBOW                = 0x05,     /* Mode 1 rainbow effect                */
    HYPERX_MODE1_CYCLE                  = 0x04,     /* Mode 1 cycle effect                  */
};

enum
{
    HYPERX_MODE2_BOUNCE                 = 0x02,     /* Mode 2 bounce effect                 */
    HYPERX_MODE2_BREATHING              = 0x03,     /* Mode 2 breathing effect              */
    HYPERX_MODE2_BLINK                  = 0x06,     /* Mode 2 blink effect                  */
    HYPERX_MODE2_HEARTBEAT              = 0x07,     /* Mode 2 heartbeat effect              */
    HYPERX_MODE2_COMET                  = 0x08,     /* Mode 2 comet effect                  */
    HYPERX_MODE2_STATIC                 = 0x09,     /* Mode 2 static effect                 */
};

enum
{
    HYPERX_MODE3_DIRECT                 = 0x21,     /* Mode 3 direct control                */
};

enum
{
    HYPERX_MODE_DIRECT                  = 0,        /* Direct control mode                  */
    HYPERX_MODE_STATIC                  = 1,        /* Static color mode                    */
    HYPERX_MODE_RAINBOW                 = 2,        /* Rainbow wave mode                    */
    HYPERX_MODE_COMET                   = 3,        /* Comet (chase) mode                   */
    HYPERX_MODE_HEARTBEAT               = 4,        /* Heartbeat (pulsing) mode             */
    HYPERX_MODE_CYCLE                   = 5,        /* Spectrum cycle mode                  */
    HYPERX_MODE_BREATHING               = 6,        /* Breathing mode                       */
    HYPERX_MODE_BOUNCE                  = 7,        /* Bounce mode                          */
    HYPERX_MODE_BLINK                   = 8,        /* Blinking mode                        */
    HYPERX_NUMBER_MODES                             /* Number of HyperX modes               */
};

static const unsigned char slot_base[4] =
{
    HYPERX_REG_SLOT0_LED0_RED,                      /* SPD 0x50 maps to slot 0              */
    HYPERX_REG_SLOT1_LED0_RED,                      /* SPD 0x51 maps to slot 1              */
    HYPERX_REG_SLOT2_LED0_RED,                      /* SPD 0x52 maps to slot 2              */
    HYPERX_REG_SLOT3_LED0_RED                       /* SPD 0x53 maps to slot 3              */
};

class HyperXController
{
public:
    HyperXController(i2c_smbus_interface* bus, hyperx_dev_id dev, unsigned char slots);
    ~HyperXController();

    std::string     GetDeviceName();
    std::string     GetDeviceLocation();
    unsigned int    GetLEDCount();
    unsigned int    GetSlotCount();
    unsigned int    GetMode();
    void            SetMode(unsigned char new_mode);

    void            SetAllColors(unsigned char red, unsigned char green, unsigned char blue);
    void            SetEffectColor(unsigned char red, unsigned char green, unsigned char blue);
    void            SetLEDColor(unsigned int led, unsigned char red, unsigned char green, unsigned char blue);
    void            SetLEDColor(unsigned int slot, unsigned int led, unsigned char red, unsigned char green, unsigned char blue);

private:
    char                    device_name[32];
    unsigned int            led_count;
    unsigned char           slots_valid;
    i2c_smbus_interface*    bus;
    hyperx_dev_id           dev;
    unsigned int            mode;
};
