#include "common.h"
#include "shell.h"

#define MAXCMDLEN 128

void shell(void)
{
	unsigned short com[MAXCMDLEN];
	unsigned short ttclr;
	unsigned short bgclr;	
	unsigned short version_now[] = L"pre1";
	unsigned short ostype_now[] = L"SAIOSPRE";

	setattr(0x0F);

	puts(L"Use PS/2 not USB!\r\n");
	puts(L"Type \"helps\" for guide of commands.");
	puts(L"PRE2\r\n");
	
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
			puts(L"hello   Say hello\r\n");
			puts(L"clear   Clear screen\r\n");
			puts(L"helps   Help for commands\r\n");
			puts(L"versn   More information of SAIOS\r\n");
			puts(L"theme   Change text color and background color\r\n");
		}
		else if (!strcmp(L"theme",com)) {
			puts(L"Theme type: ");
			gets(ttclr,65535);
			if (!strcmp(L"1",ttclr)) {
				setattr(0x0F);
			}
			else if (!strcmp(L"2",ttclr)) {
				setattr(0x1F);
			}
			else if (!strcmp(L"3",ttclr)) {
				setattr(0x2F);
			}
			else {
				setattr(0x0F);
			}
			puts(L"\r\n");
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
