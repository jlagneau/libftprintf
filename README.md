# libftprintf

:package: Static library for ft_printf family functions

[![Build Status][1]][2]

---

## Installation

There's no automatic install. Copy the file manually if you need to.

to compile, use the command:

	make

## Tests

To build and run the tests, use the command:

	make test && ./test

## Documentation

Please read the [Makefile][3] to know what you can do with it. The project
**must** respect [42Born2Code's norme][4]. You can read the [project's
instructions][5]. The purpose of this library is to make my own printf
function that doesn't work with buffered IO streams (because of the
constraints of the authorized functions in the scope of the project).

## License

[MIT][6]

[1]:https://travis-ci.org/jlagneau/libftprintf.svg?branch=master
[2]:https://travis-ci.org/jlagneau/libftprintf
[3]:https://github.com/jlagneau/libftprintf/blob/master/Makefile
[4]:https://github.com/jlagneau/libftprintf/blob/master/doc/norme.en.pdf
[5]:https://github.com/jlagneau/libftprintf/blob/master/doc/ft_printf.en.pdf
[6]:https://github.com/jlagneau/libftprintf/blob/master/LICENSE
