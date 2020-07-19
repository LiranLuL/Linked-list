#define u unsigned 
#define ll long long
#include <iostream> 
#include <malloc.h> 
#include <algorithm> 
#include <conio.h> 
#include <math.h> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
using namespace std;

struct mylist
{
	u int age;
	mylist* next;
	mylist* prev;
};

struct mylist* initialization()
{
	struct mylist* head;
	head = (struct mylist*)malloc(sizeof(struct mylist));
	head->next = head;
	head->prev = head;
	cout << "������� ������� ��� 1 ��������:";
	cin >> head->age;
	return(head);
};

void delete_all(mylist* head)
{
	mylist* temp = (struct mylist*)malloc(sizeof(struct mylist));
	if (head != nullptr)
	{
		if (head->next == head)
		{
			free(head);
		}
		else
		{
			do {
				temp = head->next;
				free(head);
				head = nullptr;
				head = temp;
			} while (head != temp);
		}
	}

}

struct mylist* addelem_head(mylist* head)
{
	struct mylist* p = (struct mylist*)malloc(sizeof(struct mylist));
	struct mylist* temp = (struct mylist*)malloc(sizeof(struct mylist));
	p = head->prev;
	temp->next = head;
	temp->prev = head->prev;
	p->next = temp;
	head->prev = temp;
	cout << "������� ������� ��� ������ ��������(������): ";
	cin >> temp->age;

	return temp;
}

void addelem_tail(mylist* head)
{
	struct mylist* temp = (struct mylist*)malloc(sizeof(mylist));
	temp->next = head;
	temp->prev = head->prev;
	head->prev = temp;
	temp->prev->next = temp;
	cout << "������� ������� ��� ������ ��������(�����): ";
	cin >> temp->age;
}

mylist* delete_head(mylist* head)
{
	if (head != nullptr)
	{
		struct mylist* temp = (struct mylist*)malloc(sizeof(mylist));
		if (head != head->next)
		{
			cout << "���� ������ �� ������" << endl;
			head->next->prev = head->prev;
			head->prev->next = head->next;
			return head->next;
			free(head);
		}
		else
		{
			cout << "C����� ����" << endl;
			free(head);
			head = nullptr;
		}
	}
	else
		return head;
}

mylist* delete_tail(mylist* head)
{
	if (head != nullptr)
	{
		if (head != head->next)
		{
			cout << "���� ������ �� ������" << endl;
			struct mylist* temp = (struct mylist*)malloc(sizeof(mylist));
			temp = head->prev;
			temp->prev->next = head;
			head->prev = temp->prev;
			free(temp);
			return head;
		}
		else
		{
			cout << "C����� ����" << endl;
			head = nullptr;
			return head;
		}
	}
	else
		return head;
}

void listprint(struct mylist* head)
{
	if (head != nullptr)
	{
		struct mylist* p = (struct mylist*)malloc(sizeof(mylist));
		int K = 1;
		p = head;
		do
		{
			cout << "������� � ������:" << K << " = " << p->age << endl;
			p = p->next;
			K++;
		} while (p != head && p != nullptr);

	}
}

mylist* delete_this(mylist* head)
{
	u int a;
	struct mylist* temp = (struct mylist*)malloc(sizeof(mylist));
	temp = head;
	cout << "����� ���� �������?" << endl;
	cin >> a;
	int k = 0;
	do {
		temp = temp->next;
		k++;
	} while (head != temp);
	if (a == 1 && head == head->next)
	{
		cout << "������ ����" << endl;
		free(head);
		return nullptr;
	}
	else if (a <= k)
	{
		for (int i = 1; i < a; i++)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		if (a == 1)
		{
			cout << "������ " << a << " ������" << endl;
			return head->next;
		}
		else
		{
			cout << "������ " << a << " ������" << endl;
			return head;
		}
		free(head);
	}
	else
	{
		cout << "������������ ������" << endl;
		return head;
	}

}

mylist* add_before(mylist* head)
{
	bool flag = 0;
	u int our_numb;
	struct mylist* temp1 = (struct mylist*)malloc(sizeof(struct mylist));
	struct mylist* temp2 = (struct mylist*)malloc(sizeof(struct mylist));
	if (head != nullptr)
	{
		temp1 = head;
		cout << "������� ������� ��� ������: ";
		cin >> our_numb;
		cout << endl;
		if (head == head->next && our_numb == head->age)
		{
			cout << "������� ������� ��� ������ � ����� �������: ";
			cin >> temp2->age;
			temp2->next = head;
			temp2->prev = head;
			head->next = temp2;
			head->prev = temp2;
			return temp2;
			flag = 1;
		}
		else
		{
			do
			{
				if (temp1->age == our_numb)
				{
					cout << "������� ������� ��� ������ � ����� �������: ";
					cin >> temp2->age;
					temp2->next = temp1;
					temp2->prev = temp1->prev;
					temp1->prev->next = temp2;
					temp1->prev = temp2;
					flag = 1;
					return head;
					break;
				}
				temp1 = temp1->next;
			} while (temp1 != head);
		}
		if (flag == 0)
		{
			cout << "������ �������� ���" << endl;
			return head;
		}
	}

}


int main()
{
	string command;
	setlocale(LC_ALL, "ru");
	u int a;
	mylist* first_element = nullptr;
	bool flag = 0, endl = 0;
	while (command != "end")
	{
		cin >> command;
		if (command == "addbefore")
		{
			first_element = add_before(first_element);
			flag = 1;
		}
		if (command == "initialization")
		{
			first_element = initialization();
			flag = 1;
		}
		if (command == "addtail")
		{
			addelem_tail(first_element);
			flag = 1;
		}
		if (command == "addhead")
		{
			first_element = addelem_head(first_element);
			flag = 1;
		}
		if (command == "deleteall")
		{
			delete_all(first_element);
			flag = 1;
			endl = 1;

		}
		if (command == "deletehead")
		{
			first_element = delete_head(first_element);
			flag = 1;
		}
		if (command == "deletetail")
		{
			first_element = delete_tail(first_element);
			flag = 1;
		}
		if (command == "deletethis")
		{
			first_element = delete_this(first_element);
			flag = 1;
		}
		if (flag == 0)
		{
			cout << "������������ �������" << endl;
		}
		if (flag == 1 && endl == 0)
		{
			listprint(first_element);
		}
		if (endl == 1)
		{
			endl = 0;
		}
		flag = 0;
	}
}
