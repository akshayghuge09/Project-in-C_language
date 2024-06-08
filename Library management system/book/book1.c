// create a structure of book 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
typedef struct book
{
	char name[20], a[20], type[10], pub[30];
	int id, prz, yr;
}book;
book storevalue(book*, int);
void display(book*, int);
void search(book*, int);
void sort(book*, int);
book update(book*, int);
book delete_id(book*, int*);
book insert(book*, int*);
void main()
{
	book* bk;
	int n, x, ch;
	printf("----------Book Management Library-----------\n\n\n");
	printf("---->Enter the no. of book to store : ");
	scanf("%d", &n);
	bk = (book*)malloc(n * sizeof(book));
	printf("----> Enter the info about books\n\n");
	storevalue(bk, n);

	do
	{
		printf("*******Menu*******\n\t1.Display\n\t2.Search\n\t3.Sort\n\t4.Update\n\t5.Delete\n\t6.Insert\n----->Enter the choice : ");
		scanf("%d", &ch);


		switch (ch)
		{
		case 1:
			display(bk, n);
			break;
		case 2:
			search(bk, n);
			break;
		case 3:
			sort(bk, n);
			break;
		case 4:
			update(bk, n);
			display(bk, n);
			break;
		case 5:
			x = n;
			delete_id(bk, &x);
			display(bk, x);
			break;
		case 6:
			x = n;
			insert(bk, &x);
			display(bk, x);
			break;
		default:
			printf("Invalid choice\n\n");
		}
	} while (ch != 0);
	printf("------Thank you-------\n");
}
book insert(book* bk, int* n)
{
	int a;
	printf("----> Enter the no. of books to be added");
	scanf("%d", &a);
	*n = *n + a;
	for (i = *n - a; i < *n; i++)
	{
		printf("----> Enter the info of %d book\n", i + 1);
		printf("\tBook id :\t");
		scanf("%d", &bk[i].id);
		printf("\tBook type\n(Fiction,short story,historical,biography,novel....) :\t");
		scanf("%s", &bk[i].type);
		printf("\tBook name :\t");
		scanf("%s", &bk[i].name);
		printf("\tBook author :\t");
		scanf("%s", &bk[i].a);
		printf("\tBook publication :\t");
		scanf("%s", &bk[i].pub);
		printf("\tBook year :\t");
		scanf("%d", &bk[i].yr);
		printf("\tBook price :\t");
		scanf("%d", &bk[i].prz);
	}
	/*	printf("\nbooks\tbook id\tbook type\tname\tauthor\tpublication\tyear\tprice\n");
		for (i = 0; i < n; i++)
		{
			printf("b%d\t%d\t%s\t %s\t %s\t %s\t %d\t %d\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
		}*/
}

book delete_id(book* bk, int* n)
{
	int d, l, flag = 0;
	printf("----> Enter the id no. to be deleted");
	scanf("%d", &d);
	for (i = 0; i < *n; i++)
	{
		if (d == bk[i].id)
		{
			for (l = i + 1; l <= *n; l++)
			{
				bk[l - 1] = bk[l];
			}
			*n = *n - 1;
		}
	}


	/*printf("\nbooks\tbook id\tbook type\tname\tauthor\tpublication\tyear\tprice\n");
	for (i = 0; i < n; i++)
	{
		printf("b%d\t%d\t%s\t %s\t %s\t %s\t %d\t %d\n",i+1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
	}
*/
}

book update(book* bk, int n)
{
	int u;
	printf("---->Enter the book id to be update\n");
	scanf("%d", &u);
	for (i = 0; i < n; i++)
	{
		if (u == bk[i].id)
		{
			int ch;
			do
			{
				printf("---->Update\n\n1.type\t2.name\t3.author\t4.publication\t5.year\t6.price\nenter the choice\n");
				scanf("%d", &ch);

				switch (ch)
				{
				case 1:
				{
					printf("\tBook type\n(Fiction,short story,historical,biography,novel....) :\t");
					scanf("%s", &bk[i].type);
					break;
				}
				case 2:
				{

					printf("\tBook name :\t");
					scanf("%s", &bk[i].name);
					break;
				}
				case 3:
				{
					printf("\tBook author :\t");
					scanf("%s", &bk[i].a);
					break;
				}
				case 4:
				{
					printf("\tBook publication :\t");
					scanf("%s", &bk[i].pub);
					break;
				}
				case 5: {

					printf("\tBook year :\t");
					scanf("%d", &bk[i].yr);
					break;
				}
				case 6: {
					printf("\tBook price :\t");
					scanf("%d", &bk[i].prz);
					break;
				}
				default:
					printf("invalid choice");
				}
			} while (ch != 0);
		}


	}
}

void sort(book* bk, int n)
{
	int j, x;
	printf("----> Sort by\n\n1.id no\n2.year\n3.price\n");
	printf("---->Enter the choice : ");
	scanf("%d", &x);
	switch (x)
	{
	case 1:
	{
		int p;
		printf("Choice\n\t1.Accending\n\t2.descenfing\n");
		scanf("%d", &p);
		book a;
		if (p == 1)
		{

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (bk[i].id < bk[j].id)
					{
						a = bk[i];
						bk[i] = bk[j];
						bk[j] = a;
					}
				}
			}

			printf("\n--------------------------------------------------------------------------------------");
			printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
			for (i = 0; i < n; i++)
			{
				printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
			}
			printf("\n--------------------------------------------------------------------------------------\n");
		}
		else if (p == 2)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (bk[i].id > bk[j].id)
					{
						a = bk[i];
						bk[i] = bk[j];
						bk[j] = a;
					}
				}
			}
		}
	}printf("\n--------------------------------------------------------------------------------------");
	printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
	for (i = 0; i < n; i++)
	{
		printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
	}
	printf("\n--------------------------------------------------------------------------------------\n");
	break;
	case 2:
	{
		int p;
		printf("Choice\n\t1.Accending\n\t2.descenfing\n");
		scanf("%d", &p);
		book a;
		if (p == 1)
		{

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (bk[i].yr < bk[j].yr)
					{
						a = bk[i];
						bk[i] = bk[j];
						bk[j] = a;
					}
				}
			}
			printf("\n--------------------------------------------------------------------------------------");
			printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
			for (i = 0; i < n; i++)
			{
				printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
			}
			printf("\n--------------------------------------------------------------------------------------\n");
		}
		else if (p == 2)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (bk[i].yr > bk[j].yr)
					{
						a = bk[i];
						bk[i] = bk[j];
						bk[j] = a;
					}
				}
			}
		}
	}printf("\n--------------------------------------------------------------------------------------");
	printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
	for (i = 0; i < n; i++)
	{
		printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
	}
	printf("\n--------------------------------------------------------------------------------------\n");
	break;
	case 3:
	{
		int p;
		printf("\t1.Accending\n\t2.Descenfing\n");
		scanf("%d", &p);
		book a;
		if (p == 1)
		{

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (bk[i].prz < bk[j].prz)
					{
						a = bk[i];
						bk[i] = bk[j];
						bk[j] = a;
					}
				}
			}
			printf("\n--------------------------------------------------------------------------------------");
			printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
			for (i = 0; i < n; i++)
			{
				printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
			}
			printf("\n--------------------------------------------------------------------------------------\n");
		}
		else if (p == 2)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (bk[i].prz > bk[j].prz)
					{
						a = bk[i];
						bk[i] = bk[j];
						bk[j] = a;
					}
				}
			}
		}
	}printf("\n--------------------------------------------------------------------------------------");
	printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
	for (i = 0; i < n; i++)
	{
		printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
	}
	printf("\n--------------------------------------------------------------------------------------\n");
	break;
	default:
		printf("invalid choice");
	}
}
book storevalue(book* bk, int n)
{
	for (i = 0; i < n; i++)
	{
		printf("----> Book no. %d\n", i + 1);
		printf("\tBook id :\t");
		scanf("%d", &bk[i].id);
		printf("\tBook type\n(Fiction,short story,historical,biography,novel....) :\t");
		scanf("%s", &bk[i].type);
		printf("\tBook name :\t");
		scanf("%s", &bk[i].name);
		printf("\tBook author name :\t");
		scanf("%s", &bk[i].a);
		printf("\tBook publication :\t");
		scanf("%s", &bk[i].pub);
		printf("\tBook year :\t");
		scanf("%d", &bk[i].yr);
		printf("\tPrice of book:\t");
		scanf("%d", &bk[i].prz);
	}
}
void display(book* bk, int n)
{
	printf("\n--------------------------------------------------------------------------------------");
	printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
	for (i = 0; i < n; i++)
	{
		printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
	}
	printf("\n--------------------------------------------------------------------------------------\n");
}

void search(book* bk, int n)
{
	int x, flag = 0, c;
	do
	{
		printf("----> Search by\n\t1.Book id\n\t2.Book name\n\t3.Book type\n\t4.Book of author\n\t5.Book year\n\t6.publication\n\t7.Price\n");
		printf("----> Enter the choice : ");
		scanf("%d", &x);
		switch (x)
		{

		case 1: {

			int id;
			printf("----> Enter the id to be searched");
			scanf("%d", &id);
			for (i = 0; i < n; i++)
			{
				if (id == bk[i].id)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
				}
			}if (flag == 0)
				printf("book not fount");
		}
			  break;

		case 2:
		{
			char ch[20];

			printf("---->Enter the book name to be searched : ");
			scanf("%s", &ch);
			for (i = 0; i < n; i++)
			{
				c = strcmp(bk[i].name, ch);
				if (c == 0)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("|b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
					break;
				}
			}if (flag == 0)
			{
				printf("book not fount");
			}

		}
		break;
		case 3:
		{
			char ch[20];
			printf("----> Enter the book type to be searched: ");
			scanf("%s", &ch);
			for (i = 0; i < n; i++)
			{
				c = strcmp(ch, bk[i].type);
				if (c == 0)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
				}

			}if (flag == 0)
				printf("book not fount");

		}
		break;
		case 4:
		{
			char ch[20];
			printf("enter the book author to be searched");
			scanf("%s", &ch);
			for (i = 0; i < n; i++)
			{
				c = strcmp(ch, bk[i].a);
				if (c == 0)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
				}
			}if (flag = 1)
				printf("book not fount");

		}
		break;
		case 5:
		{
			int x;
			printf("---->Enter the book year to be searched");
			scanf("%d", &x);
			for (i = 0; i < n; i++)
			{
				if (x == bk[i].yr)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("|b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
				}
			}if (flag == 0)
				printf("book not fount");

		}
		break;
		case 6:
		{
			char ch[20];
			printf("----> Enter the publication to be searched: ");
			scanf("%s", &ch);
			for (i = 0; i < n; i++)
			{
				c = strcmp(ch, bk[i].pub);
				if (c == 0)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
				}

			}if (flag == 0)
				printf("book not fount");

		}
		break;
		case 7: {

			int id;
			printf("----> Enter the id to be searched");
			scanf("%d", &id);
			for (i = 0; i < n; i++)
			{
				if (id == bk[i].prz)
				{
					printf("\n--------------------------------------------------------------------------------------");
					printf("\n|books |book id |book type   |name        |author      |publication    |year  |price |\n");
					printf("b%-6d| %-7d| %-11s| %-11s| %-11s| %--14s| %-5d| %-5d|\n", i + 1, bk[i].id, bk[i].type, bk[i].name, bk[i].a, bk[i].pub, bk[i].yr, bk[i].prz);
					printf("\n--------------------------------------------------------------------------------------\n");
					flag = 1;
				}
			}if (flag == 0)
				printf("book not fount");
		}
			  break;

		default:
			printf("invalid choice");
		}

	} while (x != 0);
}