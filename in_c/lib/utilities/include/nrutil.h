#ifndef _NR_UTILS_H_
#define _NR_UTILS_H_

#if defined(__STDC__) || defined(ANSI) || defined(NRANSI)
void nerror(char error_text[]);
#else
void nerror();
#endif

#endif
