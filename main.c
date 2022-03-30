#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define INFO_VERSION() printf("VERSION 1.2 %s %s", __DATE__, __TIME__);
#define SPACE() printf("\n\n\n\n\n\n\n\n\n\n");
#define CLEAN() system("cls");
#define SHUTDOWN() printf("\n\tFermeture du programme dans 3 secondes\n\n");\
					printf("\t3");\
					DOTDOTDOT(333)\
					printf("\n\t2");\
					DOTDOTDOT(333)\
					printf("\n\t1");\
					DOTDOTDOT(333)\
					printf("\n");\
					return 0;
#define DOTDOTDOT(time) sleep(time);\
					printf(".");\
					sleep(time);\
					printf(".");\
					sleep(time);\
					printf(".");

void sleep(clock_t duree)
{
	clock_t time_out = clock();
	while ((time_out + duree) > clock());
}
void empty_stdin(void)
{
	int c = getchar();

	while (c != '\n' && c != EOF)
		c = getchar();
}


int main(int argc, char* argv[]) {
	int answer1 = 0;
	while (answer1 < 1 || answer1 > 3) {
		CLEAN();
		INFO_VERSION();
		SPACE();
		printf("\t\t\t\t\tBienvenue dans Shutdown Scheduler !\n\n");
		printf("\n\tQue voulez vous faire ?\n");
		sleep(300);
		printf("\n\t1. Programmer un arr%ct/reboot\n", 136);
		sleep(300);
		printf("\t2. Annuler un arr%ct/reboot\n", 136);
		sleep(300);
		printf("\t3. EXIT\n\n\n\n");
		sleep(300);
		printf("\t\t");
		scanf_s("%d", &answer1);
		if (answer1 == 1) {
			int answer2 = 0;
			while (answer2 < 1 || answer2 > 3) {
				CLEAN();
				INFO_VERSION();
				SPACE();
				printf("\t1. Arr%ct\n", 136);
				sleep(300);
				printf("\t2. Reboot\n\n");
				sleep(300);
				printf("\t3. Retour\n\n");
				sleep(300);
				printf("\t\t");
				scanf_s("%d", &answer2);
				if (answer2 == 1) {
					int time_check = 0;
					int hour = -1;
					int minute = -1;
					while (time_check == 0) {
						CLEAN();
						INFO_VERSION();
						SPACE();
						int hour_check = 0;
						while (hour_check == 0) {
							printf("\tChoisissez maintenant dans combien d'heure(s) puis minute(s) votre PC s'%cteindra.\n\n", 130);
							printf("\tEntrez un chiffre entre 0 et 999 pour les heures:\n");
							printf("\t\t");
							scanf_s(" %d", &hour);
							if (hour <= 0 || hour <= 999) {
								hour_check = 1;
							}
							else {
								printf("\t\nErreur, entr%ce attendu 0-999\n\n", 130);
								empty_stdin();
								printf("\t");
								system("pause");
								printf("\n\n");
							}
						}
						int minute_check = 0;
						while (minute_check == 0) {
							printf("\n\tEntrez un chiffre entre 0 et 59 pour les minutes\n");
							printf("\t\t");
							scanf_s("%d", &minute);
							if (minute <= 0 || minute <= 59) {
								minute_check = 1;
							}
							else {
								printf("\n\tErreur, entr%ce attendu 0-59\n\n", 130);
								empty_stdin();
								printf("\t");
								system("pause");
								printf("\n\n");
							}
						}
						if (hour_check == 1 && minute_check == 1) {
							time_check = 1;
						}
						if (hour != -1 && minute != -1) {
							CLEAN();
							INFO_VERSION();
							SPACE();

							int second = (hour * 3600) + (minute * 60);
							char cmd[50];
							sprintf_s(cmd, 50, "shutdown /s /t %d", second);
							if (second < 60) {
								printf("\t!!!ATTENTION!!! Votre ordinateur s'%cteindra imm%cdiatement apr%cs avoir valid%c !!!ATTENTION!!!\n\n\n", 130, 130, 138, 130);
								printf("\t!!!ATTENTION!!! Votre ordinateur s'%cteindra imm%cdiatement apr%cs avoir valid%c !!!ATTENTION!!!\n\n\n", 130, 130, 138, 130);
								printf("\t!!!ATTENTION!!! Votre ordinateur s'%cteindra imm%cdiatement apr%cs avoir valid%c !!!ATTENTION!!!\n\n\n", 130, 130, 138, 130);
							}
							else {
								printf("\tVotre ordinateur s'%cteindra dans %d heure(s) et %d minute(s)\n", 130, hour, minute);
							}
							char yesno[100] = { 0 }, * y_check = NULL, * y_maj_check = NULL, * n_check = NULL, * n_maj_check = NULL;
							int sure;
							int size_yesno;
							sure = 0;
							while (sure == 0) {
								printf("\tVoulez vous valid%c cette op%cration ? (y/n)\n", 130, 130);
								printf("\t\t");
								scanf(" %s", &yesno);
								size_yesno = strlen(yesno);
								y_check = strchr(yesno, 'y');
								y_maj_check = strchr(yesno, 'Y');
								n_check = strchr(yesno, 'n');
								n_maj_check = strchr(yesno, 'N');
								if (size_yesno > 1 || y_check == NULL && y_maj_check == NULL && n_check == NULL && n_maj_check == NULL) {
									printf("\n\tErreur, entrer 'y' pour valider, 'n' pour annuler\n\n\n\n");
								}
								else if (y_check != NULL || y_maj_check != NULL) {
									sure = 1;
									printf("\n\n\tOp%cration valid%ce\n", 130, 130);
									system(cmd);
									SHUTDOWN();
								}
								else if (n_check != NULL || n_maj_check != NULL) {
									sure = 1;
									printf("\n\tOp%cration annul%ce, retour au menu principal\n\n", 130, 130);
									DOTDOTDOT(100);
									DOTDOTDOT(100);
									DOTDOTDOT(100);
									DOTDOTDOT(100);
									CLEAN();
									answer1 = 0;
								}
							}
						}
						else {
							CLEAN();
							INFO_VERSION();
							SPACE();
							time_check = 0;
							empty_stdin();
							printf("\n\tErreur lors de la saisi\n\n");
							printf("\t");
							system("pause");

						}
					}
				}
				else if (answer2 == 2) {
					int time_check = 0;
					int hour = -1;
					int minute = -1;
					while (time_check == 0) {
						CLEAN();
						INFO_VERSION();
						SPACE();
						int hour_check = 0;
						while (hour_check == 0) {
							printf("\tChoisissez maintenant dans combien d'heure(s) puis minute(s) votre PC red%cmarrera.\n\n", 130);
							printf("\tEntrez un chiffre entre 0 et 999 pour les heures:\n");
							printf("\t\t");
							scanf_s(" %d", &hour);
							if (hour <= 0 || hour <= 999) {
								hour_check = 1;
							}
							else {
								printf("\n\tErreur, entr%ce attendu 0-999\n\n", 130);
								empty_stdin();
								printf("\t");
								system("pause");
								printf("\n\n");
							}
						}
						int minute_check = 0;
						while (minute_check == 0) {
							printf("\n\tEntrez un chiffre entre 0 et 59 pour les minutes\n");
							printf("\t\t");
							scanf_s("%d", &minute);
							if (minute <= 0 || minute <= 59) {
								minute_check = 1;
							}
							else {
								printf("\n\tErreur, entr%ce attendu 0-59\n\n", 130);
								empty_stdin();
								printf("\t");
								system("pause");
								printf("\n\n");
							}
						}
						if (hour_check == 1 && minute_check == 1) {
							time_check = 1;
						}
						if (hour != -1 && minute != -1) {
							CLEAN();
							INFO_VERSION();
							SPACE();

							int second = (hour * 3600) + (minute * 60);
							char cmd[50];
							sprintf_s(cmd, 50, "shutdown /r /t %d", second);
							if (second < 60) {
								printf("\t!!!ATTENTION!!! Votre ordinateur red%cmarrera imm%cdiatement apr%cs avoir valid%c !!!ATTENTION!!!\n\n\n", 130, 130, 138, 130);
								printf("\t!!!ATTENTION!!! Votre ordinateur red%cmarrera imm%cdiatement apr%cs avoir valid%c !!!ATTENTION!!!\n\n\n", 130, 130, 138, 130);
								printf("\t!!!ATTENTION!!! Votre ordinateur red%cmarrera imm%cdiatement apr%cs avoir valid%c !!!ATTENTION!!!\n\n\n", 130, 130, 138, 130);
							}
							else {
								printf("\tVotre ordinateur red%cmarrera dans %d heure(s) et %d minute(s)\n", 130, hour, minute);
							}
							char yesno[100] = { 0 }, * y_check = NULL, * y_maj_check = NULL, * n_check = NULL, * n_maj_check = NULL;
							int sure;
							int size_yesno;
							sure = 0;
							while (sure == 0) {
								printf("\tVoulez vous valid%c cette op%cration ? (y/n)\n", 130, 130);
								printf("\t\t");
								scanf(" %s", &yesno);
								size_yesno = strlen(yesno);
								y_check = strchr(yesno, 'y');
								y_maj_check = strchr(yesno, 'Y');
								n_check = strchr(yesno, 'n');
								n_maj_check = strchr(yesno, 'N');
								if (size_yesno > 1 || y_check == NULL && y_maj_check == NULL && n_check == NULL && n_maj_check == NULL) {
									printf("\n\tErreur, entrer 'y' pour valider, 'n' pour annuler\n\n\n\n");
								}
								else if (y_check != NULL || y_maj_check != NULL) {
									sure = 1;
									printf("\n\n\tOp%cration valid%ce\n", 130, 130);
									system(cmd);
									SHUTDOWN();
								}
								else if (n_check != NULL || n_maj_check != NULL) {
									sure = 1;
									printf("\n\tOp%cration annul%ce, retour au menu principal\n\n", 130, 130);
									DOTDOTDOT(100);
									DOTDOTDOT(100);
									DOTDOTDOT(100);
									DOTDOTDOT(100);
									CLEAN();
									answer1 = 0;
								}
							}
						}
						else {
							CLEAN();
							INFO_VERSION();
							SPACE();
							time_check = 0;
							empty_stdin();
							printf("\n\tErreur lors de la saisi\n\n");
							printf("\t");
							system("pause");

						}
					}
				}
				else if (answer2 == 3) {
					answer1 = 0;
				}
				else {
					printf("\n\tErreur, entr%ce attendu 1-3\n\n", 130);
					printf("\t");
					system("pause");
					empty_stdin();
				}
			}
		}
		else if (answer1 == 2) {
			CLEAN();
			INFO_VERSION();
			SPACE();
			system("shutdown /a");
			printf("\n\nTous les arr%ct ou reboot planifi%c ont %ct%c interrompu.\n", 136, 130, 130, 130);
			SHUTDOWN();
		}
		else if (answer1 == 3) {
			CLEAN();
			INFO_VERSION();
			SPACE();
			SHUTDOWN();
		}
		else {
			printf("\n\tErreur, entr%ce attendu 1-3\n\n", 130);
			printf("\t");
			system("pause");
			empty_stdin();
		}
	}
		return 0;
}