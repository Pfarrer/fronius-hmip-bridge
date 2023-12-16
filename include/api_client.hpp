#pragma once

/** Positive values are watts delivered to the grid, negative values are watts received from the grid.*/
extern int powerToGrid;

void api_client_setup();

void api_client_loop();