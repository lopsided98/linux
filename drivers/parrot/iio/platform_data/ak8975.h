#ifndef _AK8975_H_
#define _AK8975_H_

#include "mykonos3.h"

/**
 * @file ak8975h
 *  Parrot IIO driver for Magnetometer AK8975/AK8963
 *
 * Copyright (C) 2015 Parrot S.A.
 *
 * @author     didier.leymarie.ext@parrot.com
 * @date       2015-02-05
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * Magnetometer AK8975/AK8963 Device Platform Data
 *
 * struct ak8975_platform_data - Platform data for the mpu driver
 * @orientation:	Orientation matrix of the chip
 *
 * Contains platform specific information on how to configure the AKM8975 to
 * work on this platform.  The orientation matricies are 3x3 rotation matricies
 * that are applied to the data to rotate from the mounting orientation to the
 * platform orientation.  The values must be one of 0, 1, or -1 and each row and
 * column should have exactly 1 non-zero value.
 */
struct ak8975_platform_data {
	s8 orientation[3][3];	/* Orientation matrix of the chip */
	int drdy_gpio;		/* GPIO connected to DRDY pin exclusive with I2C irq */
	int trg_gpio;		/* GPIO connected to TRG pin (AK8963)  */
};

/* Compatible Asahi Kasei Compass parts */
enum asahi_compass_chipset {
	AK8975,
	AK8963,
};

#define IIO_MAGNETOMETER_AK8975 "ak8975"
#define IIO_MAGNETOMETER_AK8963 "ak8963"

#endif /* _AK8975_H_ */
