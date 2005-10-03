/*---------------------------------------------------------------------------------
	$Id: input.h,v 1.4 2005-10-03 21:21:21 wntrmute Exp $

	key input code -- provides slightly higher level input forming

  Copyright (C) 2005
			Michael Noland (joat)
			Jason Rogers (dovoto)
			Christian Auby (DesktopMan)
			Dave Murphy (WinterMute)

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any
  damages arising from the use of this software.

  Permission is granted to anyone to use this software for any
  purpose, including commercial applications, and to alter it and
  redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you
     must not claim that you wrote the original software. If you use
     this software in a product, an acknowledgment in the product
     documentation would be appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and
     must not be misrepresented as being the original software.
  3. This notice may not be removed or altered from any source
     distribution.

	$Log: not supported by cvs2svn $
	Revision 1.3  2005/09/07 18:03:36  wntrmute
	renamed key input registers
	moved key bit definitions to input.h
	
	Revision 1.2  2005/08/23 17:06:10  wntrmute
	converted all endings to unix

	Revision 1.1  2005/08/03 17:37:28  wntrmute
	moved to input.h

	Revision 1.5  2005/08/01 23:18:22  wntrmute
	adjusted headers for logging

	Revision 1.4  2005/07/25 02:31:07  wntrmute
	made local variables static
	added proper header to keys.h

	Revision 1.3  2005/07/25 02:19:01  desktopman
	Added support for KEY_LID in keys.c.
	Moved KEYS_CUR from header to source file.
	Changed from the custom abs() to stdlib.h's abs().

	Revision 1.2  2005/07/14 08:00:57  wntrmute
	resynchronise with ndslib


---------------------------------------------------------------------------------*/
/*! \file input.h

    \brief nds input support.

*/

//---------------------------------------------------------------------------------
#ifndef	_input_h_
#define	_input_h_
//---------------------------------------------------------------------------------

#include <nds/jtypes.h>

// Keyboard

/*! \enum KEYPAD_BITS
	\brief bit values for keypad buttons

*/
enum KEYPAD_BITS {
	KEY_A		=	BIT(0),	/*!< keypad A button */
	KEY_B		=	BIT(1),	/*!< keypad B button */
	KEY_SELECT	=	BIT(2),	/*!< keypad SELECT button*/
	KEY_START	=	BIT(3),	/*!< keypad START button*/
	KEY_RIGHT	=	BIT(4),	/*!< keypad RIGHT button*/
	KEY_LEFT	=	BIT(5),	/*!< keypad LEFT button*/
	KEY_UP		=	BIT(6),	/*!< keypad UP button*/
	KEY_DOWN	=	BIT(7),	/*!< keypad DOWN button*/
	KEY_R		=	BIT(8),	/*!< RIGHT shoulder button*/
	KEY_L		=	BIT(9),	/*!< LEFT shoulder button*/
	
	KEY_X		=	(1<<10),	/*!< keypad X button*/
	KEY_Y		=	(1<<11),	/*!< keypad Y button*/
	KEY_TOUCH	=	(1<<12),	/*!< touchscreen pendown*/
	KEY_LID		=	(1<<13)		/*!< lid state*/
} KEYPAD_BITS;

#ifdef __cplusplus
extern "C" {
#endif
/*! \fn scanKeys()
	\brief obtain the current keypad states.

	Call this function once per main loop in order to use the keypad functions.
*/
void scanKeys();
void keysInit();
/*! \fn KEYPAD_BITS keysHeld()
	\brief obtain the current keypad held state.

*/
enum KEYPAD_BITS keysHeld();
/*! \fn KEYPAD_BITS keysDown()
	\brief obtain the current keypad pressed state.

*/
enum KEYPAD_BITS keysDown();
/*! \fn KEYPAD_BITS keysUp()
	\brief obtain the current keypad released state.

*/
enum KEYPAD_BITS keysUp();


/*! \fn touchPosition touchReadXY()
	\brief obtain the current touchscreen co-ordinates.

*/
touchPosition touchReadXY();

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------------
#endif // _keys_h_
//---------------------------------------------------------------------------------
