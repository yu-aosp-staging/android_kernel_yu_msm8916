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

#ifndef _LINUX_GOODIX_CONFIG_H
#define	_LINUX_GOODIX_CONFIG_H

// Define panel model
#ifdef CONFIG_MACH_TOMATO
const char * TW_IC_PREFIX_NAME = "GT970";
#else
const char * TW_IC_PREFIX_NAME = "GT9158";
#endif

// Firmware auto update
#define GTP_AUTO_UPDATE 1

// Multitouch limited to 
#define GTP_HAVE_TOUCH_KEY 1
#define GTP_MAX_TOUCH 5

// ESD
#define GTP_ESD_CHECK_CIRCLE  2

// Firmware
#ifdef CONFIG_MACH_TOMATO
#define GTP_COB		      1
#else
#define GTP_COB		      0
#endif 
#if GTP_HAVE_TOUCH_KEY
    #define GTP_KEY_TAB	 {KEY_MENU, KEY_HOME, KEY_BACK}
#endif

struct touch_panel_info
{
        unsigned char  tp_id;        	/*touch panel factory id*/
	unsigned char *tp_name;    	/*touch panel factory name */
	unsigned char *firmware;   	/*firmware for this factory's touch panel*/
	unsigned int   firmware_size; 
};


// Touchscreen firmwares
#ifdef CONFIG_MACH_TOMATO
static unsigned char CTP_CFG_GROUP1[]=  
{
    #include "coolpad_8675_00_V46_20141111_finger.cfg"
};
#ifdef CONFIG_TOUCHSCREEN_GT9XX_YL_COVER_WINDOW_CFG
static unsigned char CTP_CFG_GROUP1_window[]=  
{
    #include "coolpad_8675_00_V46_20141111_window.cfg"
};
#endif
static unsigned char CTP_CFG_GROUP2[]=  
{
    #include "coolpad_8675_02_V46_20141111_finger.cfg"
};
#ifdef CONFIG_TOUCHSCREEN_GT9XX_YL_COVER_WINDOW_CFG
static unsigned char CTP_CFG_GROUP2_window[]=  
{
    #include "coolpad_8675_02_V46_20141111_window.cfg"
};
#endif
static unsigned char CTP_CFG_GROUP3[]=  
{
    #include "coolpad_8675_01_V46_20141111_finger.cfg"
};
#ifdef CONFIG_TOUCHSCREEN_GT9XX_YL_COVER_WINDOW_CFG
static unsigned char CTP_CFG_GROUP3_window[]=  
{
    #include "coolpad_8675_01_V46_20141111_window.cfg"
};
#endif
//[YULONG END]

struct touch_panel_info yl_cfg[] = {
  {0x00, "Boen", CTP_CFG_GROUP1, sizeof(CTP_CFG_GROUP1)},
  {0x02, "Ofilm", CTP_CFG_GROUP2, sizeof(CTP_CFG_GROUP2)},
  {0x01, "Each", CTP_CFG_GROUP3, sizeof(CTP_CFG_GROUP3)},
};

#ifdef CONFIG_TOUCHSCREEN_GT9XX_YL_COVER_WINDOW_CFG
struct touch_panel_info yl_cfg_window[] = {
  {0x00, "Boen", CTP_CFG_GROUP1_window, sizeof(CTP_CFG_GROUP1_window)},
  {0x02, "Ofilm", CTP_CFG_GROUP2_window, sizeof(CTP_CFG_GROUP2_window)},
  {0x01, "Each", CTP_CFG_GROUP3_window, sizeof(CTP_CFG_GROUP3_window)},
};
#endif

#else
static unsigned char CTP_CFG_GROUP1[]=  
{
	#include "coolapd_7625_00_V47_20140730_finger.cfg"
};
static unsigned char CTP_CFG_GROUP2[]=
{
   #include "coolapd_7625_01_V47_20140730_finger.cfg"
};
static unsigned char CTP_CFG_GROUP3[]=
{
    #include "coolapd_7625_02_V47_20140730_finger.cfg"
};
struct touch_panel_info yl_cfg[] = {
  {0x00, "boen", CTP_CFG_GROUP1, sizeof(CTP_CFG_GROUP1)},
  {0x01, "junda", CTP_CFG_GROUP2, sizeof(CTP_CFG_GROUP2)},
  {0x02, "ofilm", CTP_CFG_GROUP3, sizeof(CTP_CFG_GROUP3)},
};
#endif

#endif
