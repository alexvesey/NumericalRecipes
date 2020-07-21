#ifndef JULDAY_H
#define JULDAY_H

#include <math.h>
#define IGREG (15+31L*(10+12L*1582))

long julday(int mm, int id, int iyyy);

#endif
