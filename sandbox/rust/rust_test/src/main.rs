#![allow(dead_code)]
#![allow(unused_variables)]

mod number;
use number::{Unit};

struct Translation {
    pos: [i64;3],
    vel: [i32;3],
    time: u32,
}
impl Translation {

}



struct Rotation {
    ori: [i32;4],
    rot: [i32;3],
    vel: u32,
    time: u32,
}
impl Rotation {

}


fn main() {
    let a = Unit::new(0b01111111_11111111_11111111_11111110);
    let b = Unit::new(0b01111111_11111111_11111111_11111110);
    let c = &a*&b;

    
    println!("{:b}", a);
    println!("{:b}", b);
    println!("{:b}", c);
}
