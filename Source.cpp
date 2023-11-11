#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Member
{
	char name[20];
	char phone[20];
	char role[20];
	Member* next;
};
typedef struct Member Member;
typedef struct Member* Memberptr;

struct Job
{
	char name[20];
	char explain[100];
	char importance[20];
	char person[20];
	char time[20];
	char schedule[20];
	char mark[20];
	char type[20];
	Job* next;
};
typedef struct Job Job;
typedef struct Job* Jobptr;

void NewPerson(Memberptr* head)
{
	Memberptr current = *head;

	Memberptr newnode = (Memberptr)malloc(sizeof(Member));

	printf("\n�п�J�m�W: ");
	scanf("%s", newnode->name);
	while (current != NULL)
	{
		if (strcmp(current->name, newnode->name) == 0)
		{
			printf("\n���Ʃm�W�A���s��J: ");
			scanf("%s", newnode->name);
			current = *head;
		}
		else
		{
			current = current->next;
		}
	}

	current = *head;

	printf("\n�п�J�q��: ");
	scanf("%s", newnode->phone);

	while (strlen(newnode->phone) != 10 || newnode->phone[0] != '0' || newnode->phone[1] != '9')
	{
		printf("\n�q�ܮ榡���~�A���s��J: ");
		scanf("%s", newnode->phone);
	}

	while (current != NULL)
	{
		if (strcmp(current->phone, newnode->phone) == 0)
		{
			printf("\n���ƹq�ܡA���s��J: ");
			scanf("%s", newnode->phone);
			current = *head;
		}
		else
		{
			current = current->next;
		}
	}
	current = *head;

	int choice = 0;

	printf("\n�п�ܨ���: 1)�����H�� 2)��ݤH�� 3)���ʤH��: ");
	scanf("%d", &choice);
	while (choice < 1 || choice>3)
	{
		printf("\n��J���~�A�п�ܨ���: 1)�����H�� 2)��ݤH�� 3)���ʤH��: ");
		scanf("%d", &choice);
	}
	if (choice == 1)
	{
		strcpy(newnode->role, "�����H��");
	}
	else if (choice == 2)
	{
		strcpy(newnode->role, "��ݤH��");
	}
	else
	{
		strcpy(newnode->role, "���ʤH��");
	}
	newnode->next = (*head);
	*head = newnode;
}

void Delete(Memberptr* head)
{
	int a = 0;
	char del[20] = { 0 };
	Memberptr current = *head;
	Memberptr pre = NULL;

	printf("\n�п�J�n�R�����H��: ");
	scanf("%s", del);

	while (current != NULL)
	{
		if (strcmp(del, current->name) == 0)
		{
			a = 1;
			if (pre != NULL)
			{
				Memberptr drop = current;
				current = current->next;
				pre->next = current;
				free(drop);
				break;
			}
			else
			{
				if (current->next != NULL)
				{
					(*head) = current->next;
					free(current);
					break;
				}
				else
				{
					free(current);
					*head = NULL;
					break;
				}

			}
		}
		else
		{
			pre = current;
			current = current->next;
		}
	}
	if (a == 1)
	{
		printf("\n�w�R���H��\n");
	}
	else
	{
		printf("\n����즹�H\n");
	}
}

void Updatemem(Memberptr* head)
{
	Memberptr current = *head;
	int a = 0;
	char name[20] = { 0 };
	printf("\n�п�J�n�ק��T���H��: ");
	scanf("%s", name);
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0)
		{
			a = 1;
			int what = 0;
			printf("\n1)���m�W 2)���q�� 3)��﨤��: ");
			scanf("%d", &what);
			while (what < 1 || what>3)
			{
				printf("\n���s��J: 1)���m�W 2)���q�� 3)��﨤��: ");
				scanf("%d", &what);
			}
			if (what == 1)
			{
				char name2[20] = { 0 };
				printf("\n�п�J�n��諸�m�W: ");
				scanf("%s", name2);
				Memberptr check = *head;

				while (check != NULL)
				{
					if (strcmp(check->name, name2) == 0)
					{
						printf("\n���Ʃm�W�A���s��J");
						scanf("%s", name2);
						check = *head;
					}
					else
					{
						check = check->next;
					}
				}
				strcpy(current->name, name2);
				break;
			}
			else if (what == 2)
			{
				printf("\n�п�J�n��諸�q��: ");
				scanf("%s", current->phone);
				break;
			}
			else
			{
				int choice = 0;
				printf("\n�п�ܭn��諸����:1)�����H�� 2)��ݤH�� 3)���ʤH��: ");
				scanf("%d", &choice);
				while (choice < 1 || choice>3)
				{
					printf("\n��J���~: 1)�����H�� 2)��ݤH�� 3)���ʤH��: ");
					scanf("%d", &choice);
				}
				if (choice == 1)
				{
					strcpy(current->role, "�����H��");
				}
				else if (choice == 2)
				{
					strcpy(current->role, "��ݤH��");
				}
				else
				{
					strcpy(current->role, "���ʤH��");
				}
				break;
			}
		}
		else
		{
			current = current->next;
		}
	}
	if (a == 1)
	{
		printf("\n�w�ק粒��\n");
	}
	else
	{
		printf("\n����즹�H��\n");
	}
}

void Printfmem(Memberptr* head)
{
	Memberptr current = *head;
	if (current == NULL)
	{
		printf("\n�|�L��T\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("\n�H���m�W: %s", current->name);
			printf("\n�H���q��: %s", current->phone);
			printf("\n�H������: %s\n", current->role);
			current = current->next;
		}
	}


}

int Typefunc(char*** type)
{
	if (*type == NULL)
	{
		int n = 0;
		printf("\n�п�J���O�ƶq: ");
		scanf("%d", &n);
		while (n < 0 || n>20)
		{
			printf("\n��J���~�A���s��J: ");
			scanf("%d", &n);
		}

		*type = (char**)malloc(sizeof(char*) * n);

		for (int i = 0; i < n; i++)
		{
			char str[50] = { NULL };
			printf("\n�п�J��%d�����O�W��", i + 1);
			scanf("%s", str);
			for (int k = 0; k < i; k++)
			{
				if (strcmp((*type)[k], str) == 0)
				{
					printf("\n�W�٭��ơA���s��J: ");
					scanf("%s", str);
					k = -1;
				}
			}
			int m = strlen(str) + 1;
			(*type)[i] = (char*)malloc(sizeof(char) * m);
			strcpy((*type)[i], str);
		}

		for (int i = 0; i < n; i++)
		{
			printf("\n%s", (*type)[i]);
		}

		printf("\n�w�q���\!!\n");
		return n;
	}
	else
	{
		printf("\n�w�w�q�L���O,�L�k�A���w�q\n");
		return 0;
	}
}

void Newjob(Jobptr* head, Memberptr* memhead, char*** type, int n)
{
	if (*memhead == NULL || *type == NULL)
	{
		if (*memhead == NULL)
			printf("\n�ثe�|�L�H���A�зs�W�H����A�ϥΦ��\��\n");
		else
			printf("\n�ثe�|�L���O�A�зs�W�H����A�ϥΦ��\��\n");
	}
	else
	{
		Jobptr current = *head;
		Jobptr newnode = (Jobptr)malloc(sizeof(Job));
		newnode->next = NULL;
		printf("\n�п�J���ȦW��: ");
		scanf("%s", newnode->name);
		while (current != NULL)
		{
			if (strcmp(newnode->name, current->name) == 0)
			{
				printf("��J���ơA���s��J: ");
				scanf("%s", newnode->name);
				current = *head;
			}
			else
			{
				current = current->next;
			}
		}
		current = *head;
		printf("\n�п�J���Ȼ���(50�r��): ");
		scanf("%s", newnode->explain);
		printf("\n�п�J���ȭ��n��: ");
		scanf("%s", newnode->importance);


		Memberptr memcur = *memhead;
		printf("\n�ثe�H����: ");
		while (memcur != NULL)
		{
			printf("\n%s", memcur->name);
			memcur = memcur->next;
		}

		printf("\n�п�J�t�d�H��: ");
		scanf("%s", newnode->person);

		memcur = *memhead;

		while (memcur != NULL)
		{
			if (strcmp(memcur->name, newnode->person) == 0)
			{
				break;
			}
			else
			{
				memcur = memcur->next;
				if (memcur == NULL)
				{
					printf("\n�L���H���A�Э��s��J: ");
					scanf("%s", newnode->person);
					memcur = *memhead;
				}
			}
		}
		printf("\n�п�J�ɵ{: ");
		scanf("%s", newnode->time);
		printf("\n�п�J�i��: ");
		scanf("%s", newnode->schedule);
		printf("\n�п�J���O: ");
		scanf("%s", newnode->mark);


		char** typearr = *type;

		printf("\n�ثe�������O��: ");
		for (int i = 0; i < n; i++)
		{
			printf("\n%s", typearr[i]);
		}

		printf("\n�п�J�������O: ");
		scanf("%s", newnode->type);

		for (int i = 0; i < n; i++)
		{
			if (strcmp(typearr[i], newnode->type) == 0)
			{
				break;
			}
			if (i == n - 1)
			{
				printf("\n�L�����O�A�Э��s��J: ");
				scanf("%s", newnode->type);
				i = -1;
			}
		}
		newnode->next = *head;
		*head = newnode;
	}
}
void jobprintf(Jobptr* head)
{
	Jobptr current = *head;
	if (current == NULL)
	{
		printf("\n�L����T\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("\n���ȦW��: %s", (current)->name);
			printf("\n�������O: %s\n", (current)->type);
			printf("���Ȼ���: %s\n", (current)->explain);
			printf("���n��: %s\n", (current)->importance);
			printf("�t�d�H��: %s\n", (current)->person);
			printf("�ɵ{: %s\n", (current)->time);
			printf("�ثe�i��: %s\n", (current)->schedule);
			printf("���O: %s\n", (current)->mark);
			current = (current)->next;
		}
	}

}

void jobtypeup(Jobptr* jhead, char*** thead, int n)
{
	char** typearr = *thead;
	Jobptr current = *jhead;
	char update[20] = { NULL };
	if (current == NULL)
	{
		printf("\n�|�L��T\n");
	}
	else
	{
		printf("\n�п�J�n������O�����ȦW��");
		scanf("%s", update);
		while (current != NULL)
		{
			if (strcmp(update, current->name) == 0)
			{

				printf("\n�ثe���O��: ");
				for (int i = 0; i < n; i++)
				{
					printf("\n%s ", typearr[i]);
				}
				printf("\n�п�J���O: ");
				scanf("%s", current->type);

				for (int i = 0; i < n; i++)
				{
					if (strcmp(typearr[i], current->type) == 0)
					{
						printf("��令�\\n");
						break;
					}
					if (i == n - 1)
					{
						printf("\n�L�����O�A�Э��s��J: ");
						scanf("%s", current->type);
						i = -1;
					}
				}

				break;
			}
			else
			{
				current = current->next;
				if (current == NULL)
				{
					printf("\n����즹����\n");
					break;
				}
			}
		}
	}
}

void updatejob(Jobptr* head, Memberptr* mhead)
{
	Jobptr current = *head;
	if (current == NULL)
	{
		printf("\n�|�L��T\n");
	}
	else
	{

		char name[20] = { 0 };
		printf("\n�п�J���ȦW��: ");
		scanf("%s", name);
		while (current != NULL)
		{
			if (strcmp(current->name, name) == 0)
			{
				int choice = 1;

				while (choice >= 1 && choice <= 8)
				{
					printf("\n1)�ק���ȦW�� 2)�ק���Ȼ��� 3)�קﭫ�n�� 4)�ק�t�d�H�� 5)�ק�ɵ{ 6)�ק�ثe�i�� 7)�ק���O 8)����: ");
					scanf("%d", &choice);
					while (choice < 1 || choice>8)
					{
						printf("\n���s��J�A 1)�ק���ȦW�� 2)�ק���Ȼ��� 3)�קﭫ�n�� 4)�ק�t�d�H�� 5)�ק�ɵ{ 6)�ק�ثe�i�� 7)�ק���O 8)����: ");
						scanf("%d", &choice);
					}
					if (choice == 1)
					{
						char newname[20] = { 0 };
						printf("\n��J�s�����ȦW��: ");
						scanf("%s", newname);
						Jobptr check = *head;
						while (check != NULL)
						{
							if (strcmp(check->name, newname) == 0)
							{
								printf("\n���ƦW�١A���s��J: ");
								scanf("%s", newname);
								check = *head;
							}
							else
							{
								check = check->next;
							}
						}
						strcpy(current->name, newname);
					}
					else if (choice == 2)
					{
						printf("\n��J�s�����Ȼ���: ");
						scanf("%s", current->explain);
					}
					else if (choice == 3)
					{
						printf("\n��J�s�����ȭ��n��: ");
						scanf("%s", current->importance);
					}
					else if (choice == 4)
					{
						Memberptr mcur = *mhead;
						char person[20] = { 0 };

						printf("\n�{�b�H����: ");
						while (mcur != NULL)
						{
							printf("\n%s", mcur->name);
							mcur = mcur->next;
						}
						mcur = *mhead;

						printf("\n��J�s�����ȭt�d�H��: ");
						scanf("%s", person);

						while (mcur != NULL)
						{
							if (strcmp(mcur->name, person) == 0)
							{
								strcpy(current->name, person);
								break;
							}
							else
							{
								mcur = mcur->next;
								if (mcur == NULL)
								{
									printf("\n����즹�H��,�Э��s��J: ");
									scanf("%s", person);
									mcur = *mhead;
								}
							}
						}

					}
					else if (choice == 5)
					{
						printf("\n��J�s�����Ȯɵ{: ");
						scanf("%s", current->time);
					}
					else if (choice == 6)
					{
						printf("\n��J�s�����ȥثe�i��: ");
						scanf("%s", current->schedule);
					}
					else if (choice == 7)
					{
						printf("\n��J�s�����ȵ��O: ");
						scanf("%s", current->mark);
					}
					else if (choice == 8)
					{
						break;
					}
				}
				if (choice == 8)
				{
					break;
				}
			}
			else
			{
				current = current->next;
				if (current == NULL)
				{
					printf("\n�L������\n");
					break;
				}
			}
		}
	}
}

void freeall(Memberptr* member, char*** type, Jobptr* job,int n)
{
	while (*member != NULL)
	{
		Memberptr f = *member;
		*member = (*member)->next;
		free(f);
	}

	for (int i = 0; i < n; i++)
	{
		free((*type)[i]);
	}
	free(*type);

	while (*job != NULL)
	{
		Jobptr f = *job;
		*job = (*job)->next;
		free(f);
	}
}

void main()
{
	Memberptr member = NULL;
	Jobptr job = NULL;
	char** type = NULL;
	int n = 0;
	int choice = 1;
	while (choice >= 1 && choice <= 4)
	{
		printf("1)�H���\�� 2)�w�q���O 3)�u�@�\�� 4)����: ");
		scanf_s("%d", &choice);
		while (choice < 1 || choice>4)
		{
			printf("\n��J���~�A 1)�H���\�� 2)�w�q���O 3)�u�@�\�� 4)����: ");
			scanf_s("%d", &choice);
		}

		if (choice == 1)
		{
			int Pchoice = 0;
			printf("\n1)�s�W���� 2)�R������ 3)�ק令�� 4)�L�X�Ҧ�����: ");
			scanf("%d", &Pchoice);
			while (Pchoice < 1 || Pchoice>4)
			{
				printf("\n��J���~�A1)�s�W���� 2)�R������ 3)�ק令�� 4)�L�X�Ҧ�����: ");
				scanf("%d", &Pchoice);
			}
			if (Pchoice == 1)
			{
				NewPerson(&member);
			}
			else if (Pchoice == 2)
			{
				Delete(&member);
			}
			else if (Pchoice == 3)
			{
				Updatemem(&member);
			}
			else
			{
				Printfmem(&member);
			}
		}
		else if (choice == 2)
		{
			int l = Typefunc(&type);
			if (l != 0)
			{
				n = l;
			}
		}
		else if (choice == 3)
		{
			int choice2 = 0;
			printf("\n1)�s�W���� 2)���������O 3)�ק���ȸ�T 4)�L�X�Ҧ�����: ");
			scanf("%d", &choice2);
			while (choice2 < 1 || choice2>4)
			{
				printf("\n��J���~�A1)�s�W���� 2)���������O 3)�ק���ȸ�T 4)�L�X�Ҧ�����: ");
				scanf("%d", &choice2);
			}
			if (choice2 == 1)
			{
				Newjob(&job, &member, &type, n);
			}
			else if (choice2 == 2)
			{
				jobtypeup(&job, &type, n);
			}
			else if (choice2 == 3)
			{
				updatejob(&job, &member);
			}
			else if (choice2 == 4)
			{
				jobprintf(&job);
			}
		}
		else
		{
			freeall(&member,&type,&job,n);
			break;
		}
	}

}