// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <EffectDevices/Definitions.h>

#define PPUC_NUM_LEDS_1 60
#define PPUC_LED_TYPE_1 WS2812_GRB
//#define PPUC_LED_TYPE_1 SK6812_GBRW
#define PPUC_NUM_LEDS_7 60
#define PPUC_LED_TYPE_7 WS2812_GRB

#include <EffectsController.h>

EffectsController effectsController("0.1.0", PLATFORM_WPC);

void setup() {
    // Debug
    Serial.begin(9600); // USB is always 12 Mbit/sec
    effectsController.eventDispatcher()->addListener(new CrossLinkDebugger());

    // Setup
    effectsController.eventDispatcher()->setCrossLinkSerial(Serial8);

    effectsController.createCombinedGiAndLightMatrixWs2812FXDevice(7);

    effectsController.setBrightness(1, 64);
    effectsController.setBrightness(7, 255);
    //effectsController.attachBrightnessControl(7, 1);

    effectsController.giAndLightMatrix(7)->setHeatUp(40);
    effectsController.giAndLightMatrix(7)->setAfterGlow(280);

    effectsController.giAndLightMatrix(7)->assignLedToGiString(1, 55);
    effectsController.giAndLightMatrix(7)->assignLedToGiString(2, 56);
    effectsController.giAndLightMatrix(7)->assignLedToGiString(3, 57);
    effectsController.giAndLightMatrix(7)->assignLedToGiString(4, 58);
    effectsController.giAndLightMatrix(7)->assignLedToGiString(5, 59);

    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(11, 1, ORANGE); // Camera (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(12, 2, ORANGE); // Hitch-Hiker (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(13, 3, ORANGE); // Clock Chaos (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(14, 4, ORANGE); // Super Skill (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(15, 5, ORANGE); // Fast Lock (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(16, 6, ORANGE); // Lite Gumball (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(17, 7, ORANGE); // Town Square Madness (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(18, 8, ORANGE); // Lite Extra Ball (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(21, 9, RED); // Door Panel 'Lock 2'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(22, 10, ORANGE); // Greed (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(23, 11, ORANGE); // 10 Million (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(24, 12, ORANGE); // Bat11e the Power (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(25, 13, ORANGE); // The Spiral (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(26, 14, ORANGE); // Clock Million (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(27, 15, ORANGE); // Super Slot (Door)
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(28, 16, RED); // Door Panel 'Ball'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(31, 17, RED); // Left Extra Ball
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(32, 18, RED); // Door Panel 'Lock 1'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(33, 19, WHITE); // Left lnlane 1
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(34, 20, WHITE); // Door Handle
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(35, 21, WHITE); // Left lnlane 2
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(36, 22, RED); // Door Panel 'Gum'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(37, 23, YELLOW); // Lower Left 5 Million
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(38, 24, WHITE); // Dead End
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(41, 25, YELLOW); // Spiral '2 Million'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(42, 26, YELLOW); // Spiral Left Battle Power
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(43, 27, YELLOW); // Spiral '4 Million'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(44, 28, YELLOW); // Spiral Right Battle Power
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(45, 29, YELLOW); // Spiral '10 Million'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(46, 30, RED); // Spiral 'Extra Ball'
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(47, 31, RED); // Shoot Again
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(48, 32, WHITE); // Right lnlane
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(51, 33, WHITE); // Left Ramp Bonus X
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(52, 34, WHITE); // Left Ramp Multiball
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(53, 35, ORANGE); // Left Ramp Super Skill
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(54, 36, WHITE); // Left Powerball
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(55, 37, WHITE); // The Camera
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(56, 38, ORANGE); // Right Ramp The Power
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(57, 39, ORANGE); // Lock Extra Ball
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(58, 40, RED); // Lock Arrow
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(61, 41, RED); // Left Jet Bumper
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(62, 42, YELLOW); // Lower Jet Bumper
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(63, 43, RED); // Right Jet Bumper
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(64, 44, YELLOW); // Middle Left 5 Million
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(65, 45, YELLOW); // Upper Left 5 Million
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(66, 46, RED); // Right Special
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(67, 47, WHITE); // Right Powerball
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(68, 48, ORANGE); // Right Lane Spiral
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(71, 49, YELLOW); // Lower Right 5 Million
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(72, 50, YELLOW); // Middle Right 5 Million 2
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(73, 51, YELLOW); // Middle Right 5 Million 1
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(74, 52, WHITE); // Power Payoff
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(75, 53, YELLOW); // Upper Right 5 Million
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(76, 54, YELLOW); // *Mini-playfield 500,000
    effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(77, 55, RED); // *Mini-playfield 1,000,000
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(78, 56, RED); // *Mini-playfield 750,000
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(81, 57, YELLOW); // *Left Spiral
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(82, 58, WHITE); // Clock Millions
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(83, 59, YELLOW); // *Piano Yellow
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(84, 60, RED); // *Piano Red
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(85, 61, YELLOW); // *Slot Machine
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(86, 62, RED); // *Right Lane Gumball
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(87, 63, GREEN); // Buy-In Button
    //effectsController.giAndLightMatrix(7)->assignLedToLightMatrixWPC(88, 64, GREEN); // Credit Button

    // There's one WS2812FXDevice ready to use for each LED port. Using createWS2812FXDevice() you can define additional
    // "virtual" WS2812FXDevice on a LED port to run independent effects on segments of the LED chain attached to that
    // port.
    effectsController.createWS2812FXDevice(
            1, // LED port
            0, // number of WS2812FX device, in total max 10 devices are allowed per LED port (counting starts with 0)
            1, // number of WS2812FX "segments" to assign to this device, in total max 10 segments are allowed per LED port
            0, // number of first LED in chain (counting starts with 0)
            4  // number of last LED in chain (counting starts with 0)
    );

    effectsController.createWS2812FXDevice(
            1, // LED port
            1, // number of WS2812FX device, in total max 10 devices are allowed per LED port (counting starts with 0)
            1, // number of WS2812FX "segments" to assign to this device, in total max 10 segments are allowed per LED port
            5, // number of first LED in chain (counting starts with 0)
            29  // number of last LED in chain (counting starts with 0)
    );

    effectsController.createWS2812FXDevice(
            1, // LED port
            2, // number of WS2812FX device, in total max 10 devices are allowed per LED port (counting starts with 0)
            1, // number of WS2812FX "segments" to assign to this device, in total max 10 segments are allowed per LED port
            30, // number of first LED in chain (counting starts with 0)
            32  // number of last LED in chain (counting starts with 0)
    );

    effectsController.createWS2812FXDevice(
            1, // LED port
            3, // number of WS2812FX device, in total max 10 devices are allowed per LED port (counting starts with 0)
            1, // number of WS2812FX "segments" to assign to this device, in total max 10 segments are allowed per LED port
            33, // number of first LED in chain (counting starts with 0)
            35  // number of last LED in chain (counting starts with 0)
    );

    effectsController.createWS2812FXDevice(
            1, // LED port
            4, // number of WS2812FX device, in total max 10 devices are allowed per LED port (counting starts with 0)
            1, // number of WS2812FX "segments" to assign to this device, in total max 10 segments are allowed per LED port
            36, // number of first LED in chain (counting starts with 0)
            38  // number of last LED in chain (counting starts with 0)
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_TWINKLEFOX, BLUE, 100, NO_OPTIONS),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_SWITCH, 27), // Ball Shooter pressed
            1, // priority
            -1, // run endless
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_CHASE_COLOR, WHITE, /* speed */ 500, NO_OPTIONS, /* duration */ 500),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_SWITCH, 27, 0), // Ball Shooter released
            2, // priority
            -1,
            //0, // run once
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_FIREWORKS, RED, 100, NO_OPTIONS, 2000),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_DMD, 32),
            1, // priority
            -1, // run endless
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_FIREWORKS, ORANGE, 100, NO_OPTIONS, 2000),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_DMD, 31),
            1, // priority
            -1, // run endless
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_FIREWORKS, YELLOW, 100, NO_OPTIONS, 2000),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_DMD, 30),
            1, // priority
            -1, // run endless
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_SPARKLE, RED, 100, NO_OPTIONS, 2000),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_DMD, 17),
            1, // priority
            -1, // run endless
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_RAINBOW_CYCLE, RED, 100, NO_OPTIONS, 2000),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 1),
            new Event(EVENT_SOURCE_DMD, 5),
            1, // priority
            -1, // run endless
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_STATIC, RED, /* speed */ 0, NO_OPTIONS, /* duration */ 200),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 2),
            new Event(EVENT_SOURCE_SWITCH, 61, 0), // Lower Skill
            1, // priority
            -1,
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_STATIC, ORANGE, /* speed */ 0, NO_OPTIONS, /* duration */ 200),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 3),
            new Event(EVENT_SOURCE_SWITCH, 62, 0), // Middle Skill
            1, // priority
            -1,
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_STATIC, YELLOW, /* speed */ 0, NO_OPTIONS, /* duration */ 400),
            effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 4),
            new Event(EVENT_SOURCE_SWITCH, 63, 0), // Upper Skill
            1, // priority
            -1,
            0  // mode
    );

    effectsController.addEffect(
            new WS2812FXEffect(FX_MODE_RAINBOW, PURPLE, 500, NO_OPTIONS),
            effectsController.ws2812FXDevice(1, 0),
            new Event(EVENT_SOURCE_EFFECT, 1, 255), // controller start event
            1, // priority
            -1, // run endless
            0  // mode
    );

    // Shaker
    // @todo read poti to adjust max shaking power

    // Shaker: Bumpers
    effectsController.addEffect(
            // 4Hz, intensity 128 of 255
            new ImpulsePWMEffect(2, 96),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SWITCH, 31),
            1, // priority
            0, // repeat
            0  // mode
    );
    effectsController.addEffect(
            // 4Hz, intensity 128 of 255
            new ImpulsePWMEffect(2, 96),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SWITCH, 32),
            1, // priority
            0, // repeat
            0  // mode
    );
    effectsController.addEffect(
            // 4Hz, intensity 128 of 255
            new ImpulsePWMEffect(2, 96),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SWITCH, 33),
            1, // priority
            0, // repeat
            0  // mode
    );

    // DOF: S21 m600 I32/S23 m600 I32/S24 I28/S25 300 I32/S26 300 I32

    // Shaker: Playfield Magnets
    effectsController.addEffect(
            new SinePWMEffect(10, 600, 196, 128),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SOLENOID, 21),
            1, // priority
            0, // repeat
            0  // mode
    );
    effectsController.addEffect(
            new SinePWMEffect(10, 600, 196, 128),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SOLENOID, 23),
            1, // priority
            0, // repeat
            0  // mode
    );

    // Shaker: Gumball Motor
    effectsController.addEffect(
            new SinePWMEffect(20, 3000, 96),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SOLENOID, 24),
            1, // priority
            0, // repeat
            0  // mode
    );
    effectsController.addEffect(
            // 4Hz, intensity 128 of 255
            new RampDownStopPWMEffect(10),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SOLENOID, 24, 0),
            2, // priority
            0, // repeat
            0  // mode
    );

    // Shaker: Mini Playfield Magnets
    effectsController.addEffect(
            new SinePWMEffect(2, 1000, 196, 96),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SOLENOID, 25),
            1, // priority
            0, // repeat
            0  // mode
    );
    effectsController.addEffect(
            new SinePWMEffect(2, 1000, 196, 96),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SOLENOID, 26),
            1, // priority
            0, // repeat
            0  // mode
    );

    // Shaker: Rocket Kicker
    effectsController.addEffect(
            new SinePWMEffect(4, 3000, 96, 48),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SWITCH, 28),
            1, // priority
            0, // repeat
            0  // mode
    );
    effectsController.addEffect(
            new SinePWMEffect(4, 1500, 196, 128),
            effectsController.shakerPWMDevice(),
            new Event(EVENT_SOURCE_SWITCH, 28, 0),
            2, // priority
            0, // repeat
            0  // mode
    );

    // Test Buttons
    effectsController.addEffect(
            new LedBlinkEffect(),
            effectsController.ledBuiltInDevice(),
            new Event(EVENT_SOURCE_SWITCH, 201),
            1, // priority
            5, // repeat
            0  // mode
    );

    effectsController.addEffect(
            new NullEffect(),
            effectsController.ledBuiltInDevice(),
            new Event(EVENT_SOURCE_SWITCH, 202),
            2, // priority
            0, // repeat
            0  // mode
    );

    effectsController.addEffect(
            new LedBlinkEffect(),
            effectsController.ledBuiltInDevice(),
            new Event(EVENT_SOURCE_SWITCH, 203),
            1, // priority
            5, // repeat
            0  // mode
    );

    // Controller start
    effectsController.addEffect(
            new NullEffect(),
            effectsController.ledBuiltInDevice(),
            new Event(EVENT_SOURCE_SWITCH, 204),
            2, // priority
            0, // repeat
            0  // mode
    );

    // Start
    effectsController.start();
    effectsController.generalIllumintationWPC()->start();
}

void loop() {
    effectsController.update();
}
