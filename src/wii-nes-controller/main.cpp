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

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
