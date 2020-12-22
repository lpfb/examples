#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>    /* for getopt_long; POSIX standard getopt is in unistd.h */
int main (int argc, char **argv) {
	int c;
	int digit_optind = 0;
	int aopt = 0, bopt = 0;
	char *copt = 0, *dopt = 0;
	static struct option long_options[] = {
		/*   NAME       ARGUMENT           FLAG  SHORTNAME */
		{"add",     required_argument, NULL, 'a'},
		{"append",  no_argument,       NULL, 'p'},
		{"delete",  required_argument, NULL, 'd'},
		{"verbose", no_argument,       NULL, 'v'},
		{NULL,      0,                 NULL, 0}
	};
	int option_index = 0;
	while ((c = getopt_long(argc, argv, "a:pd:v", long_options, &option_index)) != -1) {
		int this_option_optind = optind ? optind : 1;
		switch (c) {
			case 'a':
				printf ("option [%s], with arg [%s]\n", long_options[option_index].name, optarg);
				break;
			case 'p':
				printf ("option append [%s]\n", long_options[option_index].name);
				break;
			case 'd':
				printf ("option delete [%s], with arg [%s]\n", long_options[option_index].name, optarg);
				break;
			case 'v':
				printf ("option verbose [%s]\n", long_options[option_index].name);
				break;
			default:
				printf ("?? getopt returned character code 0%o ??\n", c);
		}
	}
	if (optind < argc) {
		printf ("non-option ARGV-elements: ");
		while (optind < argc)
			printf ("%s ", argv[optind++]);
		printf ("\n");
	}
	exit (0);
}
