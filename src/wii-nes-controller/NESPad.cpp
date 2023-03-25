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

#include <WProgram.h>
#include "NESPad.h"
#include "digitalWriteFast.h"

void NESPad::init() {
	int i;
	for (i = FIRST_PIN; i <= LAST_PIN; i++) {
		pinModeFast(i, INPUT);
		// Turns data pin pull-out resistor ON
		digitalWriteFast(i, HIGH);
	}
	
	pinModeFast(HOME_PIN, INPUT);
	// Turns data pin pull-out resistor ON
	digitalWriteFast(HOME_PIN, HIGH);
}

int NESPad::read(int bits) {
	int state, i;

	state = digitalReadFast(FIRST_PIN); // pin 1 = B Button

	// start for loop at 1.  So i+1 in the first iteration is pin2 = Y Button
	// pin count is 12 so i in the last iteration is 11.  So i+1 is 12 = R button
	for (i = 1; i < PIN_COUNT; i++) {
		delayMicroseconds(1);
		state = state | (digitalReadFast(i+FIRST_PIN) << i);
	}
	delayMicroseconds(1);

	return ~state;
}

int NESPad::readhome() {
	int state;
	
	state = digitalReadFast(HOME_PIN) & 0x01;

	return (~state & 0x01);
}
