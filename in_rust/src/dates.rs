pub mod dates {

  pub fn flmoon(n: f32, nph: f32, jd: &mut f32, frac: &mut f32){
    const RAD: f32 = 3.14159265/180.0;
    let i = 0.0;
    let (am, as_, c, t, t2, mut xtra):(f32, f32, f32, f32, f32, f32) ;
    c = n+nph/4.0;
    t=c/1236.85;
    t2=t*t;
    as_=359.2242+29.105356*c;
    am=306.0253+385.816918*c+0.010730*t2;
    *jd=2415020.0+28.0*n+7.0*nph;
    xtra=0.75933+1.53058868*c+((1.178e-4)-(1.55e-7)*t)*t2;
    if nph == 0.0 || nph == 2.0 {
      xtra +=(0.1734-3.93e-4*t)*((RAD*as_).sin())-0.4068*(RAD*am).sin();
    }
    else if nph == 1.0 || nph == 3.0 {
      xtra +=(0.1721-4.0e-4*t)*(as_*RAD).sin()-0.6280*(am*RAD).sin();
    }
    else{
      eprintln!("nph is unknown in flmoon");
    }
    if xtra > 0.0 {
      xtra = xtra.floor();
    }
    else{
      xtra = xtra-1.0;
      xtra = xtra.ceil();
    }
    *jd = *jd + i;
    *frac=xtra-i;
  }
}
