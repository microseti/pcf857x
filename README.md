# PCF857x Arduino library
* By SkyWodd <https://github.com/skywodd> original PCF8574 Arduino library (version 2.0)
* By Microseti <https://github.com/microseti> (version >=2.1)

### Overview
---

The "PCF8574" or "PCF8575" chip is an I2C I/O expander that free some of your Arduino pins by controlling them over I2C.
This chips are directly powered by the 5v rail of your arduino and let you control I/O with only two common wires (I2C bus)!
* The PCF8574 features an 8-bit quasi-bidirectional I/O port (P0–P7) [datasheet](https://www.ti.com/lit/ds/symlink/pcf8574.pdf).
* The PCF8575 features an 16-bit quasi-bidirectional I/O port (P0–P7, P17–P10) [datasheet](https://www.ti.com/lit/ds/symlink/pcf8575.pdf).


## Library API
---

This library has the same API as the standard Arduino GPIO API (digitalRead, digitalWrite, ...).

This library also support interrupts on any of the PCF857x pins.
To do this the library internaly use the "Pin Change Interrupt (PCINT)" capability of AVR microcontrolers.
By this way any pins of your Arduino can be used to wire the "INT" pin of the PCF857x.

Remarks: the interrupt "check and process" routine of the library is public and require the user to provide an "global scope" wrapping fonction to work.
This is do in order to allow multiple PCF857x to use the same interrupt pin ("INT" pin) on the Arduino board with call to multiple PCF857x class instances.

