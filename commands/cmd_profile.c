#include "../main_header.h"
#include <stdlib.h>
#include <errno.h>
int cmd_profile_list(int, const char **);
int cmd_profile_show(int, const char **);
int cmd_profile_add(int, const char **);
int cmd_profile_delete(int, const char **);

int cmd_profile(int argc, const char * argv[]){
	if (argc < 2 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")){
		printf("Usage: nyanp-server profile <list|show|add|delete>\n");
		printf("	nyanp-server profile list 	Show list of all profiles\n");
		printf("	nyanp-server profile show [id]	Show info about selected profile\n");
		return 0;
	}

	const char *cmd = argv[1];
	argc--;
	argv++;

	if (!strcmp(cmd, "list"))
		return cmd_profile_list(argc, argv);
	else if (!strcmp(cmd, "show"))
		return cmd_profile_show(argc, argv);
	else if (!strcmp(cmd, "add"))
		return cmd_profile_add(argc, argv);
	else if (!strcmp(cmd, "delete"))
		return cmd_profile_delete(argc, argv);
	fprintf(stderr, "Unknown command");
	return 1;
}

int cmd_profile_list(int argc, const char * argv[]){
	return 0;
}

int cmd_profile_show(int argc, const char * argv[]){
        return 0;
}

int cmd_profile_add(int argc, const char * argv[]){
        const char *name = NULL;
	uint8_t max_connections = 0;

	struct argparse_option options[] = {
		OPT_HELP(),
		OPT_STRING('n', "name", &name, "Profile name", NULL, 0, 0),
		OPT_INTEGER('c', "mcon", &max_connections, "Max parallel connections", NULL, 0, 0),
		OPT_END(),
	};

	struct argparse argparsed;
	argparse_init(&argparsed, options, NULL, 0);
	argc = argparse_parse(&argparsed, argc, argv);
	printf("	(*≧ω≦*)		\n");
	printf("Creating new profile . . .\n");
	if (!name){
		printf("Enter profile name, pleaze:  ");
		char *line = NULL;
		size_t len = 0;
		ssize_t read = getline(&line, &len, stdin);
		if (read < 0){
			perror("getline");
			free(line);
			return 1;
		}
		printf("%s", line);
		name = line;
		free(line);
	}
	if (!max_connections){
		char *line = NULL;
		size_t len = 0;
		ssize_t read = 0;
		while (!read) {
			printf("Enter max connetions (ENTER for 10 default):	");
			read = getline(&line, &len, stdin);
			if (read <= 0){
				perror("getline");
				free(line);
				return 1;
			}
			else if (read == 1) {
				printf("\n");
				max_connections = 10;
				break;

			}
			else {
				if (line[read - 1] == '\n')
					line[read - 1] = '\0';
				char *endptr = NULL;
				errno = 0;
				long temp = strtol(line, &endptr, 10);
				if (errno != 0){
					perror("strol");
					free(line);
					return 1;
				}
				if (*endptr != '\0') {
					fprintf(stderr, "Error: Letters in the input ( ` ω ´ )\n");
					read = 0;
					len = 0;
					char *line = NULL;
				}
				else {
					max_connections = (uint8_t)temp;
					printf("\n");
					break;
				}
			}
		}
		free(line);
	}
	printf("Your settings: \n");
	printf("	Profile name:		%s\n", name);
	printf("	Max connections:	%d\n", max_connections);
	printf("\nNyaID is profile secret key. Everyone who knows it, can use this VPN profile. If you are not sure that you are alone (not in your life, this is already obious), it is better not to display NyaID.\n");
	printf("Display NyaID? [y/n]:  ");
	
	return 0;
}

int cmd_profile_delete(int argc, const char * argv[]){
        return 0;
}


