#ifndef JULDAY_H
#define JULDAY_H

#include <math.h>
#define IGREG (15+31L*(10+12L*1582))
#define CALIGREG 2299161

long julday(int mm, int id, int iyyy);

void caldat(long julian, int *mm, int *id, int *iyyy);

#endif
