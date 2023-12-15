#pragma once

void api_client_setup();

/** Positive values are watts received from the grid, negative values are watts delivered to the grid.*/
float api_client_loop();