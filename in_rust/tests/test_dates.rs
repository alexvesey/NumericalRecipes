#[path = "../src/dates.rs"] mod dates;

//use crate::dates::dates::flmoon;

#[test]

fn flmoon_test(){
    let (n,nph)=(1.0, 0.0);
    let (mut jd,mut frac)=(0.0, 0.0);

    dates::dates::flmoon(n, nph, &mut jd, &mut frac);

    print!("flmoon test: ");
    println!("n={}, nph={}, jd={}, frac={}",n,nph,jd,frac);
}
