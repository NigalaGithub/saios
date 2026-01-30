#include "common.h"
#include "shell.h"

#define MAXCMDLEN 128

void shell(void)
{
	unsigned short com[MAXCMDLEN];
	
	unsigned short version_now[] = L"pre1";
	unsigned short ostype_now[] = L"SAIOSPRE";

	puts(L"Use PS/2 not USB!\r\n");
	puts(L"For programmer: using \\r\\n not \\n!\r\n");
	puts(L"Type \"helps\" for guide about commands.\r\n");
	puts(L"Type \"versn\" for more information about SAIOS.\r\n");
	puts(L"CHINA RELEASE\r\n");
	
	while (TRUE) {
		puts(L"SAIOS <");
		if (gets(com, MAXCMDLEN) <= 0) {
			continue;
		}
		else if (!strcmp(L"hello",com)) {
			puts(L"Hello, world by SAIOS!\r\n");
		}
		else if (!strcmp(L"\n",com)) {
			puts(L"\r\n\0");
		}
		else if (!strcmp(L"clear",com)) {
			clrscreen();
		}
		else if (!strcmp(L"helps",com)) {
			puts(L"SAIOS COMMANDS LIST:\r\n");
			puts(L"hello Say hello\r\n");
			puts(L"clear Clear screen\r\n");
			puts(L"helps Help for commands\r\n");
		}
		else if (!strcmp(L"versn",com)) {
			puts(L"SAIOS VERSION:\r\n");
			puts(ostype_now);
			puts(L" ");
			puts(version_now);
			puts(L"\r\n");
		}
		else {
			puts(L"Command not found.\r\n");
		}
	}
}
