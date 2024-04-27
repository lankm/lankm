# Landon Moon

**Hello everyone!!** Most of my repositories are group projects from my education at UTA. I also have a couple personal projects as well.

I love implementing and optimizing algorithms along with backend systems, but a good UI never hurt anyone.

## Recent work

- Discovered a fast inverse square root algorithm for unit vectors

  Due to errors in floating point numbers, multiplying unit vectors does not result in a unit vector all the time. Errors build up and the unit vector is no longer of unit length. To fix this, after (a couple) multiplications, renormalization can be done to remove the growing errors. Because the dot product is very close to one, we can take this as an assumption and utilize the derivitive of sqrt(x) at x=1. To find the quick inverse square root you can: get the dot product, subtract 1, half it, negate it, and add 1.

  I implemented quaternions with both floating and fixed point numbers. floating point numbers provide more precision at the cost of memory and a bit of performance (40% slower)(tests were not extensive). This is a double vs int32 comparison. int64 is more complex to implement due to systems being 64 bit and multiplcation doubling the memory size required for numbers.

- Discovered quick collision prediction between moving spheres

  Two objects moving through space have an initial position and a velocity. this information can be used to parameterized the paths and calculate the distance over time between the points. By solving for when the distance between objects is equal to the sum of their radii, a quadratic solution appears. The sign of the discriminant determines whether the objects will collide. If a collision will occur, the quadratic formula can be used. The square root in the formula is computationally expensive and can not be avoided.
