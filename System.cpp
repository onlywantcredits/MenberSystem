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

	printf("\n請輸入姓名: ");
	scanf("%s", newnode->name);
	while (current != NULL)
	{
		if (strcmp(current->name, newnode->name) == 0)
		{
			printf("\n重複姓名，重新輸入: ");
			scanf("%s", newnode->name);
			current = *head;
		}
		else
		{
			current = current->next;
		}
	}

	current = *head;

	printf("\n請輸入電話: ");
	scanf("%s", newnode->phone);

	while (strlen(newnode->phone) != 10 || newnode->phone[0] != '0' || newnode->phone[1] != '9')
	{
		printf("\n電話格式錯誤，重新輸入: ");
		scanf("%s", newnode->phone);
	}

	while (current != NULL)
	{
		if (strcmp(current->phone, newnode->phone) == 0)
		{
			printf("\n重複電話，重新輸入: ");
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

	printf("\n請選擇角色: 1)網頁人員 2)後端人員 3)機動人員: ");
	scanf("%d", &choice);
	while (choice < 1 || choice>3)
	{
		printf("\n輸入錯誤，請選擇角色: 1)網頁人員 2)後端人員 3)機動人員: ");
		scanf("%d", &choice);
	}
	if (choice == 1)
	{
		strcpy(newnode->role, "網頁人員");
	}
	else if (choice == 2)
	{
		strcpy(newnode->role, "後端人員");
	}
	else
	{
		strcpy(newnode->role, "機動人員");
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

	printf("\n請輸入要刪除的人員: ");
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
		printf("\n已刪除人員\n");
	}
	else
	{
		printf("\n未找到此人\n");
	}
}

void Updatemem(Memberptr* head)
{
	Memberptr current = *head;
	int a = 0;
	char name[20] = { 0 };
	printf("\n請輸入要修改資訊的人員: ");
	scanf("%s", name);
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0)
		{
			a = 1;
			int what = 0;
			printf("\n1)更改姓名 2)更改電話 3)更改角色: ");
			scanf("%d", &what);
			while (what < 1 || what>3)
			{
				printf("\n重新輸入: 1)更改姓名 2)更改電話 3)更改角色: ");
				scanf("%d", &what);
			}
			if (what == 1)
			{
				char name2[20] = { 0 };
				printf("\n請輸入要更改的姓名: ");
				scanf("%s", name2);
				Memberptr check = *head;

				while (check != NULL)
				{
					if (strcmp(check->name, name2) == 0)
					{
						printf("\n重複姓名，重新輸入");
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
				printf("\n請輸入要更改的電話: ");
				scanf("%s", current->phone);
				break;
			}
			else
			{
				int choice = 0;
				printf("\n請選擇要更改的角色:1)網頁人員 2)後端人員 3)機動人員: ");
				scanf("%d", &choice);
				while (choice < 1 || choice>3)
				{
					printf("\n輸入錯誤: 1)網頁人員 2)後端人員 3)機動人員: ");
					scanf("%d", &choice);
				}
				if (choice == 1)
				{
					strcpy(current->role, "網頁人員");
				}
				else if (choice == 2)
				{
					strcpy(current->role, "後端人員");
				}
				else
				{
					strcpy(current->role, "機動人員");
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
		printf("\n已修改完成\n");
	}
	else
	{
		printf("\n未找到此人員\n");
	}
}

void Printfmem(Memberptr* head)
{
	Memberptr current = *head;
	if (current == NULL)
	{
		printf("\n尚無資訊\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("\n人員姓名: %s", current->name);
			printf("\n人員電話: %s", current->phone);
			printf("\n人員角色: %s\n", current->role);
			current = current->next;
		}
	}


}

int Typefunc(char*** type)
{
	if (*type == NULL)
	{
		int n = 0;
		printf("\n請輸入類別數量: ");
		scanf("%d", &n);
		while (n < 0 || n>20)
		{
			printf("\n輸入錯誤，重新輸入: ");
			scanf("%d", &n);
		}

		*type = (char**)malloc(sizeof(char*) * n);

		for (int i = 0; i < n; i++)
		{
			char str[50] = { NULL };
			printf("\n請輸入第%d個類別名稱", i + 1);
			scanf("%s", str);
			for (int k = 0; k < i; k++)
			{
				if (strcmp((*type)[k], str) == 0)
				{
					printf("\n名稱重複，重新輸入: ");
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

		printf("\n定義成功!!\n");
		return n;
	}
	else
	{
		printf("\n已定義過類別,無法再次定義\n");
		return 0;
	}
}

void Newjob(Jobptr* head, Memberptr* memhead, char*** type, int n)
{
	if (*memhead == NULL || *type == NULL)
	{
		if (*memhead == NULL)
			printf("\n目前尚無人員，請新增人員後再使用此功能\n");
		else
			printf("\n目前尚無類別，請新增人員後再使用此功能\n");
	}
	else
	{
		Jobptr current = *head;
		Jobptr newnode = (Jobptr)malloc(sizeof(Job));
		newnode->next = NULL;
		printf("\n請輸入任務名稱: ");
		scanf("%s", newnode->name);
		while (current != NULL)
		{
			if (strcmp(newnode->name, current->name) == 0)
			{
				printf("輸入重複，重新輸入: ");
				scanf("%s", newnode->name);
				current = *head;
			}
			else
			{
				current = current->next;
			}
		}
		current = *head;
		printf("\n請輸入任務說明(50字內): ");
		scanf("%s", newnode->explain);
		printf("\n請輸入任務重要性: ");
		scanf("%s", newnode->importance);


		Memberptr memcur = *memhead;
		printf("\n目前人員有: ");
		while (memcur != NULL)
		{
			printf("\n%s", memcur->name);
			memcur = memcur->next;
		}

		printf("\n請輸入負責人員: ");
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
					printf("\n無此人員，請重新輸入: ");
					scanf("%s", newnode->person);
					memcur = *memhead;
				}
			}
		}
		printf("\n請輸入時程: ");
		scanf("%s", newnode->time);
		printf("\n請輸入進度: ");
		scanf("%s", newnode->schedule);
		printf("\n請輸入註記: ");
		scanf("%s", newnode->mark);


		char** typearr = *type;

		printf("\n目前任務類別有: ");
		for (int i = 0; i < n; i++)
		{
			printf("\n%s", typearr[i]);
		}

		printf("\n請輸入任務類別: ");
		scanf("%s", newnode->type);

		for (int i = 0; i < n; i++)
		{
			if (strcmp(typearr[i], newnode->type) == 0)
			{
				break;
			}
			if (i == n - 1)
			{
				printf("\n無此類別，請重新輸入: ");
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
		printf("\n無此資訊\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("\n任務名稱: %s", (current)->name);
			printf("\n任務類別: %s\n", (current)->type);
			printf("任務說明: %s\n", (current)->explain);
			printf("重要性: %s\n", (current)->importance);
			printf("負責人員: %s\n", (current)->person);
			printf("時程: %s\n", (current)->time);
			printf("目前進度: %s\n", (current)->schedule);
			printf("註記: %s\n", (current)->mark);
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
		printf("\n尚無資訊\n");
	}
	else
	{
		printf("\n請輸入要更改類別的任務名稱");
		scanf("%s", update);
		while (current != NULL)
		{
			if (strcmp(update, current->name) == 0)
			{

				printf("\n目前類別有: ");
				for (int i = 0; i < n; i++)
				{
					printf("\n%s ", typearr[i]);
				}
				printf("\n請輸入類別: ");
				scanf("%s", current->type);

				for (int i = 0; i < n; i++)
				{
					if (strcmp(typearr[i], current->type) == 0)
					{
						printf("更改成功\n");
						break;
					}
					if (i == n - 1)
					{
						printf("\n無此類別，請重新輸入: ");
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
					printf("\n未找到此任務\n");
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
		printf("\n尚無資訊\n");
	}
	else
	{

		char name[20] = { 0 };
		printf("\n請輸入任務名稱: ");
		scanf("%s", name);
		while (current != NULL)
		{
			if (strcmp(current->name, name) == 0)
			{
				int choice = 1;

				while (choice >= 1 && choice <= 8)
				{
					printf("\n1)修改任務名稱 2)修改任務說明 3)修改重要性 4)修改負責人員 5)修改時程 6)修改目前進度 7)修改註記 8)結束: ");
					scanf("%d", &choice);
					while (choice < 1 || choice>8)
					{
						printf("\n重新輸入， 1)修改任務名稱 2)修改任務說明 3)修改重要性 4)修改負責人員 5)修改時程 6)修改目前進度 7)修改註記 8)結束: ");
						scanf("%d", &choice);
					}
					if (choice == 1)
					{
						char newname[20] = { 0 };
						printf("\n輸入新的任務名稱: ");
						scanf("%s", newname);
						Jobptr check = *head;
						while (check != NULL)
						{
							if (strcmp(check->name, newname) == 0)
							{
								printf("\n重複名稱，重新輸入: ");
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
						printf("\n輸入新的任務說明: ");
						scanf("%s", current->explain);
					}
					else if (choice == 3)
					{
						printf("\n輸入新的任務重要性: ");
						scanf("%s", current->importance);
					}
					else if (choice == 4)
					{
						Memberptr mcur = *mhead;
						char person[20] = { 0 };

						printf("\n現在人員有: ");
						while (mcur != NULL)
						{
							printf("\n%s", mcur->name);
							mcur = mcur->next;
						}
						mcur = *mhead;

						printf("\n輸入新的任務負責人員: ");
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
									printf("\n未找到此人員,請重新輸入: ");
									scanf("%s", person);
									mcur = *mhead;
								}
							}
						}

					}
					else if (choice == 5)
					{
						printf("\n輸入新的任務時程: ");
						scanf("%s", current->time);
					}
					else if (choice == 6)
					{
						printf("\n輸入新的任務目前進度: ");
						scanf("%s", current->schedule);
					}
					else if (choice == 7)
					{
						printf("\n輸入新的任務註記: ");
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
					printf("\n無此任務\n");
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
		printf("1)人員功能 2)定義類別 3)工作功能 4)結束: ");
		scanf_s("%d", &choice);
		while (choice < 1 || choice>4)
		{
			printf("\n輸入錯誤， 1)人員功能 2)定義類別 3)工作功能 4)結束: ");
			scanf_s("%d", &choice);
		}

		if (choice == 1)
		{
			int Pchoice = 0;
			printf("\n1)新增成員 2)刪除成員 3)修改成員 4)印出所有成員: ");
			scanf("%d", &Pchoice);
			while (Pchoice < 1 || Pchoice>4)
			{
				printf("\n輸入錯誤，1)新增成員 2)刪除成員 3)修改成員 4)印出所有成員: ");
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
			printf("\n1)新增任務 2)更改任務類別 3)修改任務資訊 4)印出所有任務: ");
			scanf("%d", &choice2);
			while (choice2 < 1 || choice2>4)
			{
				printf("\n輸入錯誤，1)新增任務 2)更改任務類別 3)修改任務資訊 4)印出所有任務: ");
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
