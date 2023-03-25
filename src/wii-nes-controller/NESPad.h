/*
* Wii Arcade Controller - Nintendo Wiimote/NES Classic/SNES Classic adapter for arcades!
* Copyright (c) 2011 Bruno Freitas - bruno@brunofreitas.com (original work Wii Retropad)
* Modifications (c) 2021 Akerasoft (including name change)
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
NES Controller pinouts:
----------------------

           +---+
GND      - | O  \
CLOCK    - | O O + - +5V
LATCH    - | O O | - NC
DATA OUT - | O O | - NC
           +-----+


NES Pad read data format:
--------------------
      +-------+------+------+----+-------+--------+---+---+
Bit:  |   7   |   6  |   5  |  4 |   3   |    2   | 1 | 0 |
      +-------+------+------+----+-------+--------+---+---+
Data: | RIGHT | LEFT | DOWN | UP | START | SELECT | B | A |
      +-------+------+------+----+-------+--------+---+---+


SNES Clock pulse and corresponding button

1   B
    Y
    Select
    Start
    North
    South
    West
    East
    A
    X
    L
    R
    [no button, always high]
    [no button, always high]
    [no button, always high]
16  [no button, always high]
*/

#ifndef NESPAD_H_
#define NESPAD_H_

#include <WProgram.h>

#define FIRST_PIN 0

// should be A - NES
#define DB_PIN 7

// should be B - NES
#define DY_PIN 6

#define DSELECT_PIN 5
#define DSTART_PIN 4
#define DUP_PIN 3
#define DDOWN_PIN 2
#define DLEFT_PIN 1
#define DRIGHT_PIN 0
//#define DA_PIN 9
//#define DX_PIN 10
//#define DL_PIN 11
//#define DR_PIN 12
#define LAST_PIN 7
#define PIN_COUNT 8 // non home pin

#define HOME_PIN 12

class NESPad {

public:
	static void init();
	static int read(int bits);
	static int readhome();

};

#endif /* NESPAD_H_ */
