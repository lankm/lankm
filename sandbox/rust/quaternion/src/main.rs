use std::fmt;

struct Quaternion {
    w: f64,
    x: f64,
    y: f64,
    z: f64,
}
impl Quaternion {
    fn new() -> Self {
        Quaternion {
            w: 1.0,
            x: 0.0,
            y: 0.0,
            z: 0.0,
        }
    }
    fn mul(&self, q: Quaternion) -> Quaternion {
        Quaternion {
            w: self.w * q.w + self.x * q.x + self.y * q.y + self.z * q.z + 
            x: self.w * q.w + self.w * q.w + self.w * q.w + self.w * q.w + 
            y: self.w * q.w + self.w * q.w + self.w * q.w + self.w * q.w + 
            z: self.w * q.w + self.w * q.w + self.w * q.w + self.w * q.w + 
        }
    }
}
impl fmt::Display for Quaternion {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "<{}, {}, {}, {}>", self.w, self.x, self.y, self.z)
    }
}

fn main() {
    let q = Quaternion::new();
    println!("{}", q);
}
