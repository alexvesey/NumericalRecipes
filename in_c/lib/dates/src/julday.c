#include <julday.h>
#include "nrutil.h"

long julday(int mm, int id, int iyyy)
{
  void nerror(char error_text[]);

  long jul;
  int ja,jy=iyyy,jm;

  if(jy == 0) nerror("julday: There is no year 0");
  if(jy < 0) ++jy;
  if(mm > 2)
  {
    jm=mm+1;
  }
  else
  {
    --jy;
    jm=mm+13;
  }
  jul = (long) (floor(365.25*jy)+floor(30.6001*jm)+id+1720995);
  if(id+31L*(mm+12L*iyyy) >= IGREG)
  {
    ja=(int)(0.01*jy);
    jul += 2-ja+(int) (0.25*ja);
  }
  return jul;
}
