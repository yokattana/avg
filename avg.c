#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	size_t nvals;
	double *vals, mean, sqerr, stddev;
	int i;

	nvals = argc - 1;
	if (nvals < 1) {
		fprintf(stderr, "usage: avg <num> <num> ...\n");
		return 1;
	}

	vals = malloc(nvals * sizeof(*vals));
	if (!vals) {
		perror("avg");
		return 1;
	}

	mean = 0;
	for (i = 0; i < nvals; i++) {
		vals[i] = strtod(argv[i+1], NULL);
		mean += vals[i] / nvals;
	}
	
	sqerr = 0;
	for (i = 0; i < nvals; i++)
		sqerr += (vals[i] - mean) * (vals[i] - mean);
	
	stddev = sqrt(sqerr);
	printf("%f +/- %f\n", mean, stddev);

	return 0;
}
