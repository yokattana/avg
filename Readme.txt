AVG                                  LOCAL                                 AVG

NAME
     avg -- calculate mean and standard deviation

SYNOPSIS
     avg num num [num ...]

DESCRIPTION
     The avg utility calculates the mean and standard deviation of the numbers
     supplied in its argument list.

     The mean is defined as the sum of the given values divided by their
     count:

           (val[0] + val[1] + ...) / count(vals)

     The standard deviation is defined as the square root of the sum of the
     squared difference between each of the values and the mean:

           sqrt((val[0]-mean)^2 + (val[1]-mean)^2 + ...)

EXAMPLES
     Basic usage:

           avg 1 2 3 4 5

     To use values from a file or other program, try using xargs(1) like so:

           cat numbers.txt | xargs avg

AUTHORS
     iku@yokattana.com

Yokattana                        June 29, 2017                       Yokattana
