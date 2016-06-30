/* 
 * 2010 - 2012 Goodix Technology.
 * 2016 - Louis Popi <theh2o64@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */

#ifndef LINUX_GT9XX_FIRMWARE_H
#define LINUX_GT9XX_FIRMWARE_H

#ifdef HEADER_UPDATE_DATA
#undef HEADER_UPDATE_DATA
#endif

#define HEADER_UPDATE_DATA goodix_firmware

#ifdef CONFIG_MACH_TOMATO
const unsigned char goodix_firmware[] = {
#ifdef CONFIG_TOUCHSCREEN_GT9XX_YL_COVER_WINDOW_CFG
	#include "GT970_1039_DACA"
#else
	#include "GT970_1030_5A1F"
#endif
};
#else
const unsigned char goodix_firmware[] = {
	#include "GT9158_1034_A9D0"
};	
#endif


#endif
