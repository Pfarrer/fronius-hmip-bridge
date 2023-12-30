#pragma once

/** Positive values are watts charged into the battery, negative values are watts discharged from the battery.*/
extern int batteryChargePower;

/** Battery State of Charge in Percent */
extern int soc;

void api_client_setup();

void api_client_loop();