/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
/* | WorkOn: | Emacs23.3         | */
/* |---------+-------------------| */

#ifndef _EVENT_H_
#define _EVENT_H_
/* tableSetEvent() and tableGetEvent() are in pair,Just Process the Event For xTaskID,
 * but not the tableEvent that xTaskID waiting for */
#define tableSetEvent(xTaskID, xMask)           \
    do{                                         \
        OSSetEventTable[(xTaskID)] |= (xMask);  \
    }while(0)
#define tableClearEvent(xTaskID,xMask)          \
    do{                                         \
        OSSetEventTable[(xTaskID)] &=~(xMask);  \
    }while(0)
#define tableGetEvent(xTaskID) (OSSetEventTable[(xTaskID)])

#define tableSetWaitEvent(xTaskID, xMask)       \
    do{                                         \
        OSWaitEventTable[(xTaskID)] |= (xMask); \
    }while(0)

#define tableGetWaitEvent(xTaskID) (OSWaitEventTable[(xTaskID)])
#define tableResetWaitEvent(xTaskID)            \
    do{                                         \
        OSWaitEventTable[(xTaskID)] =NO_EVENT;  \
    }while(0)
#endif /* _EVENT_H_ */

