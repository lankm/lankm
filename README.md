# Landon Moon

**Hello everyone!!** Most of my repositories are group projects from my education at UTA. I also have a couple personal projects as well.

I love implementing and optimizing algorithms along with backend systems, but a good UI never hurt anyone.

## Recent work

- Discovered a fast inverse square root algorithm for unit vectors

  Due to errors in floating point numbers, multiplying unit vectors does not result in a unit vector all the time. Errors build up and the unit vector is no longer of unit length. To fix this, after (a couple) multiplications, renormalization can be done to remove the growing errors. Because the dot product is very close two one, we can take this as an assumption and utilize the derivitive of sqrt(x) at x=1. To find the quick inverse square root you can: get the dot product, subtract 1, half it, negate it, and add 1.

  I implemented quaternions with both floating and fixed point numbers. floating point numbers provide more precision at the cost of memory and a bit of performance (40% slower)(tests were not extensive). This is a double vs int32 comparison. int64 is more complex to implement due to systems being 64 bit and multiplcation doubling the memory size required for numbers.
