# fronius-hmip-bridge

Integration for Fronius inverter API into an Homeatic IP smart home.

An ESP8266 acts as the API client to regulary retrieve the latest Battery SOC and charging/discharging power.
Based on this information, the ESP indicates to the HMIP-MOD-OC8 component. This is integrated as a sensor into the
Homeatic IP system and can be used as any other sensor.
