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

#[test]
fn julday_test(){
    let (mm,id,iyyy,actual_julday) = (5,23,1968,2440000);
    let calculated_julday = dates::dates::julday(mm,id,iyyy);
    print!("julday test: ");
    if calculated_julday == actual_julday {
        println!("Passed");
    }
    else{
        println!("Failed. Calculated julday ={}, 
                Actual julday ={}",calculated_julday,actual_julday);
    }
    
}

#[test]
fn caldat_test(){
    let (mm,id,iyyy) = (5,23,1968);
    let calculated_julday = dates::dates::julday(mm,id,iyyy);
    let (mut mm2,mut id2,mut iyyy2) = (0,0,0);
    dates::dates::caldat(calculated_julday, &mut mm2, &mut id2, &mut iyyy2);

    print!("caldat test: ");
    if mm == mm2 && id == id2 && iyyy == iyyy2 {
      println!("Passed");
    }
    else{
      println!("Failed. Expected {}/{}/{} but got {}/{}/{}",mm,id,iyyy,mm2,id2,iyyy2);
    }
}
