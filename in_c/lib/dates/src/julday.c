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

void caldat(long julian, int *mm, int *id, int *iyyy)
{
  long ja,jalpha,jb,jc,jd,je;
  if(julian >= CALIGREG)
  {
    jalpha=(long) (((float) (julian-1867216)-0.25)/36524.25);
    ja=julian+1+jalpha-(long)(0.25*jalpha);
  }
  else
  {
    ja=julian;
  }
  jb =ja+1524;
  jc =(long)(6680.0+((float) (jb-2439870)-122.1)/365.25);
  jd =(long)(365*jc+(0.25*jc));
  je =(long)((jb-jd)/30.6001);
  *id=jb-jd-(long)(30.6001*je);
  *mm=je-1;
  if(*mm > 12)
  {
    *mm -= 12;
  }
  *iyyy=jc-4715;
  if(*mm > 2)
  {
    --(*iyyy);
  }
  if(*iyyy <= 0)
  {
    --(*iyyy);
  }
  
}
