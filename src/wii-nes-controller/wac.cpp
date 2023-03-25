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

#include "WMExtension.h"
#include "NESPad.h"

// Classic Controller Buttons
int bdl = 0; // D-Pad Left state
int bdr = 0; // D-Pad Right state
int bdu = 0; // D-Pad Up state
int bdd = 0; // D-Pad Down state
int ba = 0; // A button state
int bb = 0; // B button state
int bx = 0; // X button state
int by = 0; // Y button state
int bl = 0; // L button state
int br = 0; // R button state
int bm = 0; // MINUS button state
int bp = 0; // PLUS button state
int bhome = 0; // HOME button state
int bzl = 0; // ZL button state
int bzr = 0; // ZR button state
int lt = 0; // L analog value
int rt = 0; // R analog value

// Analog Buttons
byte lx = WMExtension::get_calibration_byte(2);
byte ly = WMExtension::get_calibration_byte(5);
byte rx = WMExtension::get_calibration_byte(8);
byte ry = WMExtension::get_calibration_byte(11);

// Analog stick neutral radius
#define ANALOG_NEUTRAL_RADIUS 10

// NES pad loop
/*
void nes_loop() {
	int button_data;
	int home_data;

	NESPad::init();

	for (;;) {

		button_data = NESPad::read(8);
		home_data = NESPad::readhome();

		bdl = button_data & 64;
		bdr = button_data & 128;
		bdu = button_data & 16;
		bdd = button_data & 32;
		ba = button_data & 1;
		bb = button_data & 2;
		bm = button_data & 4;
		bp = button_data & 8;
		bhome = home_data & 1;

		WMExtension::set_button_data(bdl, bdr, bdu, bdd, ba, bb, bx, by, bl, br,
				bm, bp, bhome, lx, ly, rx, ry, bzl, bzr, lt, rt);
	}
}
*/

// SNES pad loop
void snes_loop() {
	int button_data;
	int home_data;

	NESPad::init();

	for (;;) {
		button_data = NESPad::read(8);
		home_data = NESPad::readhome();

		bdl = (button_data & 2) ? 1 : 0;
		bdr = (button_data & 1) ? 1 : 0;
		bdu = (button_data & 8) ? 1 : 0;
		bdd = (button_data & 4) ? 1 : 0;
		bb = (button_data & 128) ? 1 : 0;
		//by = button_data & 2;
		bm = (button_data & 32) ? 1 : 0;
		bp = (button_data & 16) ? 1 : 0;
		ba = (button_data & 64) ? 1 : 0;
		//bx = button_data & 512;
		//bl = button_data & 1024;
		//br = button_data & 2048;
		bhome = (home_data & 1) ? 1 : 0;

		WMExtension::set_button_data(bdl, bdr, bdu, bdd, ba, bb, bx, by, bl, br,
				bm, bp, bhome, lx, ly, rx, ry, bzl, bzr, lt, rt);
	}
}

void setup() {
	// Prepare wiimote communications
	WMExtension::init();
}

void loop() {
	snes_loop();
}
