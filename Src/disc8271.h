/****************************************************************
BeebEm - BBC Micro and Master 128 Emulator
Copyright (C) 1994  David Alan Gilbert
Copyright (C) 1997  Mike Wyatt

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public 
License along with this program; if not, write to the Free 
Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
Boston, MA  02110-1301, USA.
****************************************************************/

/* 8271 disc emulation - David Alan Gilbert 4/12/94 */

#ifndef DISC8271_HEADER
#define DISC8271_HEADER

extern int Disc8271Trigger; /* Cycle based time Disc8271Trigger */
extern bool Disc8271Enabled;

void LoadSimpleDSDiscImage(const char *FileName, int DriveNum, int Tracks);
void LoadSimpleDiscImage(const char *FileName, int DriveNum, int HeadNum, int Tracks);
bool IsDiscWritable(int DriveNum);
void DiscWriteEnable(int DriveNum, bool WriteEnable);
void FreeDiscImage(int DriveNum);
void Eject8271DiscImage(int DriveNum);
void Get8271DiscInfo(int DriveNum, char *pFileName, int *Heads);

/*--------------------------------------------------------------------------*/
/* Address is in the range 0-7 - with the fe80 etc stripped out */
int Disc8271_read(int Address);

/*--------------------------------------------------------------------------*/
/* Address is in the range 0-7 - with the fe80 etc stripped out */
void Disc8271_write(int Address, unsigned char Value);

/*--------------------------------------------------------------------------*/
void Disc8271_poll_real(void);

#define Disc8271_poll(ncycles) if (Disc8271Trigger<=TotalCycles) Disc8271_poll_real();

/*--------------------------------------------------------------------------*/
void Disc8271_reset(void);

void Save8271UEF(FILE *SUEF);
void Load8271UEF(FILE *SUEF);

/*--------------------------------------------------------------------------*/
void disc8271_dumpstate(void);
#endif
