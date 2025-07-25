#include "main_header.h"


static const char *const usages[] = {
	"nyapn-server <command> [options]",
	"nyapn-server profile <command>		VPN profiles",
	"nyapn-server run			Start server",
	"nyapn-server stop			Stop server",
	"nyapn-server settings <command> 	Server settings (VPN setting are in profiles)",
	NULL,
};

int main(int argc, const char *argv[]) {
	if (argc < 2 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")){
		printf("Usage:\n");
		for (const char *const *u = usages; *u; u++){
			printf("	%s\n", *u);
		}
		return 0;
	}

	const char *cmd = argv[1];
	argv++;
	argc--;

	if (!strcmp(cmd, "profile"))
		return cmd_profile(argc, argv);
	else if (!strcmp(cmd, "run"))
		return cmd_run(argc, argv);
	else if (!strcmp(cmd, "stop"))
		return cmd_stop(argc, argv);
	else if (!strcmp(cmd, "settings"))
		return cmd_settings(argc, argv);
	fprintf(stderr, "Unknown command");
	return 1;
}

int cmd_run(int argc, const char * argv[]){
        return 0;
}

int cmd_stop(int argc, const char * argv[]){
        return 0;
}
int cmd_settings(int argc, const char * argv[]){
        return 0;
}
