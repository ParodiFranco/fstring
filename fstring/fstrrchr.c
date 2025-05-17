/*****************************************************************************
MIT License

Copyright (c) 2025 Parodi, Franco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/
#include <fstring.h>
#include <xc.h>

char *fstrrchr (const char *string, int c){
	size_t string_len = fstrlen(string); 
	FSR0 = (uintptr_t) (string + string_len);
	while(FSR0 != (uintptr_t) string){
		WREG = (unsigned char) c;
		asm("xorwf	indf0, w");
		asm("addfsr	fsr0, -1");
		if(ZERO){
			asm("addfsr	fsr0, 1");
			return (char *) FSR0;
		}
	}
	WREG = (unsigned char) c;
	asm("xorwf	indf0, w");
	if(ZERO)
		return (char *) FSR0;
	return (char *) 0;
}