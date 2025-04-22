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

 #ifndef FSTRING_H
 #define FSTRING_H
 
 #ifdef	__cplusplus
 extern "C" {
 #endif

#ifndef _PIC14E
#error Device not supported
#endif
 
 #include <stddef.h>
 
 void *fmemcpy (void *__restrict, const void *__restrict, size_t);
 void *fmemmove (void *, const void *, size_t);
 void *fmemset (void *, int, size_t);
 int fmemcmp (const void *, const void *, size_t);
 void *fmemchr (const void *, int, size_t);
 
 char *fstrcpy (char *__restrict, const char *__restrict);
 char *fstrncpy (char *__restrict, const char *__restrict, size_t);
 
 char *fstrcat (char *__restrict, const char *__restrict);
 char *fstrncat (char *__restrict, const char *__restrict, size_t);
 
 int fstrcmp (const char *, const char *);
 int fstrncmp (const char *, const char *, size_t);
 
 int fstrcoll (const char *, const char *);
 size_t fstrxfrm (char *__restrict, const char *__restrict, size_t);
 
 char *fstrchr (const char *, int);
 char *fstrrchr (const char *, int);
 
 size_t fstrcspn (const char *, const char *);
 size_t fstrspn (const char *, const char *);
 char *fstrpbrk (const char *, const char *);
 char *fstrstr (const char *, const char *);
 char *fstrtok (char *__restrict, const char *__restrict);
 
 size_t fstrlen (const char *);
 
 char *fstrerror (int);
 
 #ifdef	__cplusplus
 }
 #endif
 
 #endif	/* FSTRING_H */
