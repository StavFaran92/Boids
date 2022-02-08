# Boids Simulation

This is a 2D Boids simulation I created using SFML and TGUI, it simulates a flocking mechanism that is based on 3 
basic rules: Cohesion, Seperation and Alignment, using these 3 simple rules we can observe an emergence effect that 
resembles the mechanism we can see in nature in a flock of birds,
the project is written in C++, I used SFML to handle the graphics and TGUI for the user interface to control the simulation.
currently the flock calculations are done in brute force (for every boid we check every other boid o(n^2)) but this can be optimized using a quad-tree
to get a o(nlogn) complexity.

## Installation
Download the source files 
```git
git clone git@github.com:StavFaran92/Boids.git
```
Once downloaded go into the cloned directory, in order to build the example you will need [cmake](https://cmake.org/download/),
simply type 
```git
mkdir build
cd build
cmake ..
```

if everything worked fine a Visual studio solution has been generated, open `build/BoidsExample.sln`
and build the solution.

if you are facing any issues fill free to contact me.

## Further reading
I used the following to get information about the above algorithms:

[Link 1](https://cs.stanford.edu/people/eroberts/courses/soco/projects/2008-09/modeling-natural-systems/boids.html) 

[Link 2](http://www.vergenet.net/~conrad/boids/pseudocode.html)

[Link 3](http://www.red3d.com/cwr/boids/)

[Link 4](https://eater.net/boids)

[Link 5](https://www.youtube.com/watch?v=mhjuuHl6qHM)

## License
[MIT](https://choosealicense.com/licenses/mit/)
