/**
 * cf04_driver.cpp — CWClockfaceDriver adapter for cw-cf-0x04 (Castlevania)
 * v3 bridge: wraps the v2 CF04::Clockface class in the function-pointer API.
 */

#include "Clockface04.h"        // v2 class, namespace CF04
#include <widgets/clockface/CWClockfaceDriver.h>     // v3 driver API

static CF04::Clockface* s_face = nullptr;

static void cf04_setup(Adafruit_GFX* display, CWDateTime* dateTime) {
    if (!s_face) s_face = new CF04::Clockface(display);
    s_face->setup(dateTime);
}

static void cf04_update() {
    if (s_face) s_face->update();
}

static void cf04_teardown() {
    // Instance kept alive for fast re-activation.
}

CWClockfaceDriver cf_castlevania = {
    .name     = "Castlevania",
    .index    = 3,
    .setup    = cf04_setup,
    .update   = cf04_update,
    .teardown = cf04_teardown,
};
