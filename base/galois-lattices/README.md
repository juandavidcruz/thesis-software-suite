# Galois lattices extraction algorithm

This is the implementation of the Galois lattice extraction algorithm proposed by [Vicky Choi, 2006](http://arxiv.org/abs/cs/0602069).

One of the problems, or classic bottlenecks, is the concept lookup during the construction of the lattice, i.e., before adding a closed concept to the lattice, it is mandatory to check if that concept already exists. TO improve the search time I use a [trie](http://en.wikipedia.org/wiki/Trie).

## License
The MIT License (MIT)

Copyright (c) 2014 Juan David Cruz Gómez and Telecom - Bretagne
juan.cruzgomez@telecom-bretagne.eu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-------------------------------------------------------
## Compiling and installing the algorithms
###Requisites
* A reasonable good C++ compiler (I use gcc 4.7.2)
* Install CMake

###Compiling the code
* Go to the base folder:
~~~~
juancrug@juandavid-office:~$ cd path-to-repo/software-suite/base/galois-lattices
~~~~
* Create a build folder and go into it:
~~~~
juancrug@juandavid-office:~/path-to-repo/software-suite/base/galois-lattices/$ mkdir build
juancrug@juandavid-office:~/path-to-repo/software-suite/base/galois-lattices/$ cd build
~~~~
* Configure with Cmake:
~~~~
juancrug@juandavid-office:~/path-to-repo/software-suite/base/galois-lattices/build$ cmake -DPREFIX=/home/juancrug ..
~~~~
**Note:** replace the configuration paths with your own, custom paths.

* Build and install:
~~~~
juancrug@juandavid-office:~/path-to-repo/software-suite/base/galois-lattices/build$ make && make install
~~~~

At this stage the libraries should be installed in /PREFIX/lib while the public interfaces (.h files) should be in /PREFIX/
