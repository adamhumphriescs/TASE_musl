#Grab a subset of LibC functions for TASE to execute.
#When we've got better support for floats, we'll just grab the whole library.

set -e


touch src/string/*.c
touch src/stdlib/*.c
touch src/network/*.c
touch src/ctype/*.c
touch src/math/*.c
touch src/fenv/*.c

make -j 8
