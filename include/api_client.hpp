#pragma once

/** Positive values are watts charged into the battery, negative values are watts discharged from the battery. */
extern int batteryChargePower;

/** Positive values are watts feeded into the grid, negative values are watts consumed from the grid. */
extern int gridInfeedPower;

/** Battery State of Charge in Percent. */
extern int soc;

void api_client_setup();

void api_client_loop();