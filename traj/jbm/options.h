/*
 Copyright (C) 2000 James B. Millard, jbm@cybermesa.com

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
 02111-1307, USA.
 */

#ifndef _OPTIONS_H_
#define _OPTIONS_H_

typedef struct
{
		long bits;
} Options, *lpOptions;

#define OPTIONS_SIZE   (sizeof(Options))

/* Function prototypes */
lpOptions options_create(void);
void options_destroy(lpOptions);
int options_getoption(lpOptions, long);
void options_setoption(lpOptions, long, int);

#endif /* _OPTIONS_H_ */
