use std::ops::Mul;
use std::fmt;

// Unit =======================================================================
pub struct Unit {
    val: i32,
}
impl Unit {
    pub fn new(num: i32) -> Unit {
        Unit { 
            val: num,
        }
    }
}
impl Mul<&Unit> for &Unit {
    type Output = Unit;

    fn mul(self, other: &Unit) -> Unit {
        let a: i64 = self.val as i64;
        let b: i64 = other.val as i64;
        let round = (a+b)>>1;
        Unit {
            val: ((a*b + round) >> 31) as i32,
        }
    }
}
impl fmt::Display for Unit {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Unit: {}", self.val)
    }
}
impl fmt::Binary for Unit {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Unit: {:0>32b}", self.val)
    }
}

// Angle ======================================================================
pub struct Angle {
    val: u32,
}
impl Angle {
    
}
