#include <Windows.h>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

struct User
{
	char login[30];
	char password[30];
	int role;
};
struct Hokkey
{
	char fio[30];
	int shayba;
	int peredacha;
	int shtraf;
};

void Autorization(string, string);
void Admin(string, string);

void Work_With_Files();
void Create_Files();
void Show_Files();
void Delete_Files();

void Work_With_Clients(string);
User *Massiv_User(int);				  //�-��� ������������ ��������� �� ������ �������� User 
int Number_User_In_File();			  //�-��� ������������ ���������� ������� � ����� Users  
void Add_User(string);
void Show_User(string);		  
void Updating_User(string);				  
void Delete_User(string);					 

void Work_With_Hokkey(string);
void Client_Hokkey(string);
Hokkey *Massiv_Hokkey(int);				  //�-��� ������������ ��������� �� ������ �������� Hokkey 
int Number_Hokkey_In_File();			  //�-��� ������������ ���������� ������� � ����� Hokkey  
int Enter_Int(char*, int);                 //�-��� ������������ ���������� ���� ����� 
void Add_Hokkey(string);				  
void Show_Hokkey(Hokkey*, int, string);		  
void Updating_Hokkey(string);				   
void Delete_Hokkey(string);					  
void Show_Better_Hokkey(Hokkey*, int, string);
void Sort_Hokkey(Hokkey*, int, string);
void Find_Hokkey(Hokkey*, int, string);

void main()
{
	SetConsoleCP(1251);                    
	SetConsoleOutputCP(1251);
	char a, stroka1[53], stroka2[81];
	for(int i=0;i<52;i++)
		stroka1[i]='-';
	stroka1[52]='\0';
	for(int i=0;i<80;i++)
		stroka2[i]='-';
	stroka2[80]='\0';
	while(true)
	{
		_flushall();        
		system("cls");     
		cout << "\t������� ����\n\n 1 - ����� � ������� ��� �������������\n 2 - ����������� ������\n ����� - �����\n\n ������� ����� ��������: ";
		cin >> a;                
		switch (a)
		{
		case '1': Autorization(stroka1, stroka2);             break;				  
		case '2': Client_Hokkey(stroka2);  break;
		default: return;
		}
	} 
}

void Autorization(string stroka1, string stroka2)
{
	_flushall();      
	system("cls");	 
	char login[20];
	char password[20];
	cout << "\t���� � �������\n\n������� ��������� �����: ";
	cin.getline(login, 20);
	_flushall();
	cout << "������� ��������� ������: ";
	cin.getline(password, 20);
	if (strcmp(login, "nastya") == 0 && strcmp(password, "514301") == 0) //��������� ��������� ������ � ������ � �����������
		Admin(stroka1, stroka2);   
	else
		cout << "\n������������ ���� ������ ��� ������!" << endl;
	_getch();  
}

void Admin(string stroka1, string stroka2)
{
	char a;
	while(true)
	{
		_flushall();        
		system("cls");     
		cout << "\t���� ��������������\n\n\ 1 - ������ � �������\n 2 - ������ � ��������������\n 3 - ������ � �������\n ����� - ����� � ������� ����\n\n ������� ����� ��������: ";
		cin >> a;                
		switch (a)
		{
		case '1': Work_With_Files();              break;				  
		case '2': Work_With_Clients(stroka1);  break;
		case '3': Work_With_Hokkey(stroka2);             break;
		default: return;
		}
	} 
}

void Work_With_Files()
{ 
	char number;
	while(true)
	{
		_flushall();               //������ ������ 
		system("cls");            //����� ��������� �-��� ������ ������
		cout<<"\t���� ������ � �������:\n\n 1 - ������� ����\n 2 - ����������� ��� �����\n 3 - ������� ����\n ����� - ������� � ���� ��������������\n\n\ ������� ����� ��������: ";
		cin >> number;
		cout << endl;
		switch(number)
		{ 
		case '1':Create_Files(); break; 
		case '2':Show_Files(); break;
		case '3':Delete_Files(); break;
		default: return;
		}
	}
}
void Create_Files()
{
	system("cls");  
	string file;
	char kod;
	cout << "������� ��� �����, ������� �� ������ �������:\n(���������� .txt ����� ��������� �������������)\n";
	cin >> file;
	file+=".txt";
	ifstream check(file);
	if(check.is_open()) 
	{
		cout << "���� � ����� ������ ��� ����������!\n���� ������ ������� ��� ������������ ���� � ������� ����� � ����� �� ������, ������� 1\n";
		cin >> kod;
		cout << endl;
		if (kod != '1')
		{
			cout << "������ ����� ��������!\n";
			check.close();
			_getch();
			return;
		}
	}
	ofstream f(file);
	if (!f.is_open()) cout << "������ �������� �����!\n";
	else cout << "���� ������!\n";
	f.close();
	_getch();
}
void Show_Files()
{
	system("cls");  
	cout << "\t�����\n\n";
	system("dir/b *.TXT");
	cout << endl;
	_getch();
}
void Delete_Files()
{
	system("cls");  
	string file;
	char kod;
	Show_Files();
	cout << "������� ��� �����, ������� �� ������ �������:\n(���������� .txt ����� ��������� �������������)\n";
	cin >> file;
	file+=".txt";
	ifstream check(file);
	if(!check.is_open()) 
	{
		cout << "����� � ����� ������ �� ����������!\n";
		_getch();
		return;
	}
	check.close();
	cout << "�� �������, ��� ������ ������� ���� ����?\n(���� ��, �� ������� 1)\n";
	cin >> kod;
	cout << endl;
	if (kod != '1')
	{
		cout << "�������� ����� ��������!\n";
		_getch();
		return;
	}
	if(!remove(file.c_str())) 
	{
		cout << "���� ������!\n"; 
		_getch();
	}
	else cout << "������ ��� �������� �����!\n";
	Show_Files();
}

void Work_With_Clients(string stroka)
{
	char kod;
	while(true)
	{
		_flushall();                
		system("cls");             
		cout << "\t���� ������ � ��������������\n\n 1 - �������� ������������\n 2 - ������� �������������\n 3 - �������� ������������\n 4 - ������� ������������\n 5 - ������� ����\n ����� - ����� � ���� ��������������\n\n\ ������� ����� ��������: ";
		cin >> kod;
		switch (kod)
		{
		case '1': Add_User(stroka);       break;
		case '2': Show_User(stroka);       break;
		case '3': Updating_User(stroka);       break;									 
		case '4': Delete_User(stroka);          break;
		case '5': remove("Users.txt");     break;        
		default: return;
		} 
	}
}
User *Massiv_User(int size)
{
	User *user = new User[size];
	//�������� �����
	ifstream file("Users.txt", ios::in | ios::binary);
	//����������� ������ ������ �� ����� � ������ ��������� User
	for (int i = 0; i < size; i++)
		file.read((char*)(&user[i]), sizeof(User));
	file.close(); //�������� �����
	return user;
}
int Number_User_In_File()
{
	int size;
	//�������� �����
	ifstream file("Users.txt", ios::binary);
	file.seekg(0, ios::end); //�������� ��������� � ����� �����
	//����������� ���������� ������� ����� ������� ������� ����� �� ������ ��������� User
	size = (int)(file.tellg() / sizeof(User));
	file.close(); //�������� �����
	return size; 
}   
void Add_User(string stroka)
{
	char c;
	ofstream file("Users.txt", ios::out| ios::app | ios::binary);
	do
	{
		User user;  
		_flushall();       
		system("cls");	  
		cout << "������� ����� ������������: ";
		cin.getline(user.login, 30);
		_flushall();
		cout << "������� ������: ";
		cin.getline(user.password, 30);
		_flushall();
		cout << "������� ����� ������� (1 - �������������, 0 - ������������): ";
		cin >> user.role; 
		if (user.role==0 || user.role==1)  
		{
			cin.ignore(10, '\n');
		}
		else
		{
			cin.clear();  //������ ������ �� ������� ������
			cout << "������������ ����!";
			cin.ignore(10, '\n'); 
			_getch(); 
			break;
		}
		file.write((char*)(&user), sizeof(User)); //������ ������� � ����
		_flushall();
		system("cls");
		cout << "������� 1, ����� ������� ��� ������ ������������: ";
		cin >> c;
	} while (c == '1');
	file.close();  
} 
void Show_User(string stroka)
{
	int size = Number_User_In_File();
	if (size > 0) 
	{
		User *user = Massiv_User(size);
		system("cls");             //����� ��������� �-��� ������ ������
		cout << "\t������������\n\n";
		cout << "| � |        �����         |     ������     | ���� |" << endl << stroka;
		for (int i = 0; i < size; i++)
		{
			cout << endl << "|" << setw(3) << i+1 << "|" << setw(22) << user[i].login << "|" << setw(16) << user[i].password << "|" << setw(6) << user[i].role << "|" << endl << stroka;
		}
		delete[]user;  
		_getch();   
	}
	else
	{
		cout << "������ ������������� ����!" << endl;
		_getch();
	}
}
void Updating_User(string stroka)
{                                         
	int size = Number_User_In_File();  
	if (size > 0)
	{
		char c;
		bool t = false;
		User *user = Massiv_User(size);     
		do
		{
			int number;
			system("cls");                 //����� ��������� �-��� ������ ������
			Show_User(stroka);    
			_flushall();       //������ ������
			cout << endl << "������� ����� ������������, �������� ������ ��������: ";
			cin >> number;
			if (number > size)
			{
				cout << "������ ������������ ���!" << endl;
				_getch();
				return;
			}
			number--;
			while(true)
			{
				system("cls");
				_flushall();
				cout << "| � |        �����         |     ������     | ���� |" << endl << stroka;
				cout << endl << "|" << setw(3) << number+1 << "|" << setw(22) << user[number].login << "|" << setw(16) << user[number].password << "|" << setw(6) << user[number].role << "|" << endl << stroka;
				cout << "\n 1 - �������� ����� ������������\n 2 - �������� ������ ������������\n 3 - �������� ���� ������������\n ����� - ��������� � ����\n\n ������� ����� ��������: ";
				cin >> c;
				_flushall();
				switch (c)
				{
				case '1':
					system("cls");
					cout << "������� ����� ����� ������������: ";
					cin.getline(user[number].login, 30);
					t = true;
					break;
				case '2':
					system("cls");
					cout << "������� ����� ������: ";
					cin.getline(user[number].password, 30);
					t = true;
					break;
				case '3':
					cout << "������� ����� �������: ";
					cin >> user[number].role; 
					if (user[number].role==0 || user[number].role==1)  
					{
						t = true;
						cin.ignore(10, '\n');
						break;
					}
					cin.clear();  //������ ������ �� ������� ������
					cout << "������������ ����!";
					cin.ignore(10, '\n'); 
					_getch();  
				default: return;
				}
			} 
			if (t == true)
			{ 
				ofstream file("Users.txt", ios::binary | ios::in | ios::out);  //�������� �����
				file.seekp(number*sizeof(User));  //�������� ��������� �� �������
				file.write((char*)(&user[number]), sizeof(User)); //������ ������ �� ��������� �������
				file.close(); 
			}
			system("cls");
			_flushall();
			cout << "����� ���������� ��������� �������������, ������� 1: ";
			cin >> c;
		} while (c == '1');
		delete[]user; 
	}
	else
	{
		cout << "������ ������������� ����!" << endl;
		_getch();      
	}
}
void Delete_User(string stroka)
{
	int size = Number_User_In_File();  
	if (size > 0)
	{
		char c;
		User *user = Massiv_User(size);     
		int number;
		system("cls");                     
		Show_User(stroka);     
		_flushall();
		cout << "\n������� ����� ������������, �������� ������ �������: ";
		cin >> number;
		if (number > size)
		{
			cout << "������ ������������ ���!" << endl;
			_getch();
			return;
		}
		number--;
		system("cls");
		_flushall();                
		cout << "| � |        �����         |     ������     | ���� |" << endl << stroka;
		cout << endl << "|" << setw(3) << number+1 << "|" << setw(22) << user[number].login << "|" << setw(16) << user[number].password << "|" << setw(6) << user[number].role << "|" << endl << stroka;
	    cout << "\n\n�� �������, ��� ������ ������� ����� ������������? (���� ��, �� ������� 1) ";
		cin >> c;
		if (c == '1')
		{
			ofstream file("Users.txt", ios::binary | ios::trunc | ios::out);
			for (int i = 0; i < size; i++)
			{
				if (i != number)
					file.write((char*)(&user[i]), sizeof(User));
			}
			file.close();    
			cout << "������������ ������!" << endl;
			_getch();
		}
		delete[]user;    
	}
	else
	{
		cout << "������ ������������� ����!" << endl;
		_getch();  
	}
}

void Work_With_Hokkey(string stroka)
{
	char kod;
	while (true)
	{
		_flushall();               //������ ������ 
		system("cls");            //����� ��������� �-��� ������ ������ 
		cout << "\t���� ������ � �������\n\n 1 - ������� ������ � ����������\n 2 - �������� ������ � ���������\n 3 - �������������� ������ � ���������\n 4 - ������� ������ ���������\n 5 - ������� ����\n ����� - ��������� � ���� ��������������\n\n ������� ����� ��������: ";
		cin >> kod;
		cout << endl;
		switch (kod)
		{
		case '1': Client_Hokkey(stroka);       break;
		case '2': Add_Hokkey(stroka);        break;
		case '3': Updating_Hokkey(stroka);       break;									 
		case '4': Delete_Hokkey(stroka);        break;
		case '5': remove("Hokkey.txt");     break;        
		default: return;
		} 
	} 

}
void Client_Hokkey(string stroka)
{
	int size = Number_Hokkey_In_File();  
	if (size > 0) 
	{
		Hokkey *hokkey = Massiv_Hokkey(size);
		char kod;
		while(true)
		{
			_flushall();               //������ ������ 
			system("cls");            //����� ��������� �-��� ������ ������
			cout << "\t���� ��������� ������\n\n 1 - ������� ���� ������\n 2 - ����������\n 3 - ������� ������ 6 ������ ����������\n 4 - ����� ���������\n ����� - ��������� � ����\n\n ������� ����� ��������: ";
			cin >> kod;
			cout << endl;
			switch (kod)
			{
			case '1': Show_Hokkey(hokkey, size, stroka); break;									  
			case '2': Sort_Hokkey(hokkey, size, stroka); break;										 								   
			case '3': Show_Better_Hokkey(hokkey, size, stroka); break;
			case '4': Find_Hokkey(hokkey, size, stroka); break;
			default: return;
			}
		}
		delete[]hokkey;  
	}
	else
	{
		cout << "������ ���������� ����!" << endl;
		_getch();
	}
}
Hokkey *Massiv_Hokkey(int size)
{
	Hokkey *hokkey = new Hokkey[size];
	ifstream file("Hokkey.txt", ios::in | ios::binary);  //�������� �����
	//����������� ������ ������ �� ����� � ������ ��������� Hokkey
	for (int i = 0; i < size; i++)
		file.read((char*)(&hokkey[i]), sizeof(Hokkey));
	file.close(); //�������� �����
	return hokkey;
}
int Number_Hokkey_In_File()
{
	int size;
	ifstream file("Hokkey.txt", ios::binary);   //�������� �����
	file.seekg(0, ios::end); //�������� ��������� � ����� �����
	size = (int)(file.tellg() / sizeof(Hokkey)); //����������� ���������� ������� ����� ������� ������� ����� �� ������ ��������� Hokkey
	file.close(); //�������� �����
	return size; 
}
int Enter_Int(char* mes, int ch)
{
	cin.unsetf(ios::skipws); 
	while (1)
	{
		system("cls");
		cout << mes;
		cin >> ch;
		if (cin.good())  //�������� ������ �� ������������ �����
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();  //������ ������ �� ������� ������
		cout << "������������ ����!";
		cin.ignore(10, '\n'); 
		_getch();  
	}
	return ch;
}
void Add_Hokkey(string stroka)
{
	char c;
	ofstream file("Hokkey.txt", ios::out| ios::app | ios::binary);
	do
	{
		Hokkey hokkey;  
		_flushall();       //������ ������ 
		system("cls");	  //����� ��������� �-��� ������ ������
		cout << "������� ��� ���������: ";
		cin.getline(hokkey.fio, 30);
		_flushall();
		hokkey.shayba = Enter_Int("������� ����� ����������� ����: ", hokkey.shayba);
		hokkey.peredacha = Enter_Int("������� ��������� ������� �������: ", hokkey.peredacha);
		hokkey.shtraf = Enter_Int("������� ��������� �������� �����: ", hokkey.shtraf);
		file.write((char*)(&hokkey), sizeof(Hokkey)); //������ ������� � ����
		_flushall();
		system("cls");
		cout << "����� �������� ��� ������ ���������, ������� 1: ";
		cin >> c;
	} while (c == '1');
	file.close();  //�������� �����
} 
void Show_Hokkey(Hokkey* hokkey, int size, string stroka)
{
	system("cls");
	cout << "\t���������\n\n";
	cout << "| � |      ���     ���������      | ����� | ������� �������� | �������� ������ |" << stroka;
	for (int i = 0; i < size; i++)
	{
		cout << "|" << setw(3) << i+1 << "|" << setw(29) << hokkey[i].fio << "|" << setw(7) << hokkey[i].shayba << "|" << setw(18) << hokkey[i].peredacha << "|" << setw(17) << hokkey[i].shtraf << "|" << stroka;
	}
	_getch();   
}
void Updating_Hokkey(string stroka)
{                                         
	int size = Number_Hokkey_In_File();  
	if (size > 0)
	{
		char c;
		bool t = false;
		Hokkey *hokkey = Massiv_Hokkey(size);    
		do
		{
			int number;
			system("cls");                
			Show_Hokkey(hokkey, size, stroka);    
			_flushall();     
			cout << endl << "������� ����� ���������, �������� ������ ��������: ";
			cin >> number;
			if (number > size)
			{
				cout << "������ ��������� ���!" << endl;
				_getch();
				return;
			}
			number--;
			do
			{
				system("cls");
				_flushall();
				cout << "| � |      ���     ���������      | ����� | ������� �������� | �������� ������ |" << stroka;
				cout << "|" << setw(3) << number+1 << "|" << setw(29) << hokkey[number].fio << "|" << setw(7) << hokkey[number].shayba << "|" << setw(18) << hokkey[number].peredacha << "|" << setw(17) << hokkey[number].shtraf << "|" << stroka;
				cout <<"\n 1 - �������� ��� ���������\n 2 - �������� ���������� ����������� ����\n 3 - �������� ���������� ������� �������\n 4 - �������� ���������� �������� �����\n ����� - ������� � ���� ������ � �������\n\n ������� ����� ��������: ";
				cin >> c;
				_flushall();
				switch (c)
				{
				case '1':
					system("cls");
					cout << "������� ��� ���������: ";
					cin.getline(hokkey[number].fio, 30);
					t = true;
					break;
				case '2': 
					hokkey[number].shayba = Enter_Int("�������� ����� ����������� ����: ", hokkey[number].shayba);
					t = true;
					break;
				case '3':
					hokkey[number].peredacha = Enter_Int("�������� ��������� ������� �������: ", hokkey[number].peredacha);
					t = true;
					break;
				case '4':
					hokkey[number].shtraf = Enter_Int("�������� ��������� �������� �����: ", hokkey[number].shtraf);
					t = true;
					break;
				default:
					c = '0';
					break;
				}
			} while (c != '0');
			if (t == true)
			{
				ofstream file("Hokkey.txt", ios::binary | ios::in | ios::out);
				file.seekp(number*sizeof(Hokkey));  //�������� ��������� �� �������
				file.write((char*)(&hokkey[number]), sizeof(Hokkey)); //������ ������ �� ��������� �������
				file.close(); 
			}
			system("cls");
			_flushall();
			cout << "����� ���������� �������� ������ � ����������, ������� 1: ";
			cin >> c;
		} while (c == '1');
		delete[]hokkey; 
	}
	else
	{
		cout << "������ ���������� ����!" << endl;
		_getch();     
	}
}
void Delete_Hokkey(string stroka)
{
	int size = Number_Hokkey_In_File();  
	if (size > 0)
	{
		char c;
		Hokkey *hokkey = Massiv_Hokkey(size);     
		int number;
		system("cls");                     
		Show_Hokkey(hokkey, size, stroka);     
		_flushall();
		cout << "\n������� ����� ���������, �������� ������ �������: ";
		cin >> number;
		if (number > size)
		{
			cout << "������ ��������� ���!" << endl;
			_getch();
			return;
		}
		number--;
		system("cls");
		_flushall();                
		cout << "| � |      ���     ���������      | ����� | ������� �������� | �������� ������ |" << stroka;
		cout << "|" << setw(3) << number+1 << "|" << setw(29) << hokkey[number].fio << "|" << setw(7) << hokkey[number].shayba << "|" << setw(18) << hokkey[number].peredacha << "|" << setw(17) << hokkey[number].shtraf << "|" << stroka;
		cout << endl;
		cout << "\n�� ������������� ������ ������� ���������? (���� ��, �� ������� 1) ";
		cin >> c;
		if (c == '1')
		{
			ofstream file("Hokkey.txt", ios::binary | ios::trunc | ios::out);
			for (int i = 0; i < size; i++)
			{
				if (i != number)
					file.write((char*)(&hokkey[i]), sizeof(Hokkey));
			}
			file.close();     
			cout << "�������� ������!" << endl;
			_getch();
		}
		delete[]hokkey;    
	}
	else
	{
		cout << "������ ���������� ����!" << endl;
		_getch();  
	}
}
void Show_Better_Hokkey(Hokkey* hokkey, int size, string stroka)
{
	int i, j;
	system("cls");   
	for(i=0; i<size-1; i++)
			for(j=i+1; j<size; j++)
				if((hokkey[j].shayba+hokkey[j].peredacha) > (hokkey[i].shayba+hokkey[i].peredacha))
					swap(hokkey[i],hokkey[j]);
	cout << "| � |      ���     ���������      | ����� | ������� �������� | �������� ������ |" << stroka;		
	if (size >= 6)
		for (int i = 0; i < 6; i++)
		{
			cout << "|" << setw(3) << i+1 << "|" << setw(29) << hokkey[i].fio << "|" << setw(7) << hokkey[i].shayba << "|" << setw(18) << hokkey[i].peredacha << "|" << setw(17) << hokkey[i].shtraf << "|" << stroka;
		}
	else
		for (int i = 0; i < size; i++)
		{
			cout << "|" << setw(3) << i+1 << "|" << setw(29) << hokkey[i].fio << "|" << setw(7) << hokkey[i].shayba << "|" << setw(18) << hokkey[i].peredacha << "|" << setw(17) << hokkey[i].shtraf << "|" << stroka;
		}
	_getch();   
}			
void Sort_Hokkey(Hokkey* hokkey, int size, string stroka)
{
	int i, j, kod;
	system("cls");   //����� ��������� �-��� ������ ������
	cout << "�������� ��� ����������:\n 1 - �� ���� ����������� ����\n 2 - �� ���������� ������� �������\n 3 - �� ���������� �������� �����\n ����� - �����\n";
	cin >> kod;
	if(kod<1||kod>3) return;
	for(i = 0; i < size-1; i++)
		for(j = i+1; j < size; j++)
		{
			if((kod==1 && hokkey[j].shayba > hokkey[i].shayba) || (kod==2 && hokkey[j].peredacha > hokkey[i].peredacha) || (kod==3 && hokkey[i].shtraf < hokkey[j].shtraf))
					swap(hokkey[i],hokkey[j]);
		}
	cout << "| � |      ���     ���������      | ����� | ������� �������� | �������� ������ |" << stroka;
	for (int i = 0; i < size; i++)
	{
		cout << "|" << setw(3) << i+1 << "|" << setw(29) << hokkey[i].fio << "|" << setw(7) << hokkey[i].shayba << "|" << setw(18) << hokkey[i].peredacha << "|" << setw(17) << hokkey[i].shtraf << "|" << stroka;
	}
	_getch();  
}			

void Find_Hokkey(Hokkey* hokkey, int size, string stroka)
{
	flushall();	           
	system("cls");		  
	char name[30];
	cout << "������� ��� ������������� ��� ���������, �������� ����� �� ��������� ������: \n";
	cin.getline(name, 30);
	int la = 0, flag, k = 0;
	int size_str = strlen(name);   //������� strlen ���������� � ������ ����� ������
	for (int i = 0; i < size; i++)
	{
		flag = 0; 
		for (int j = 0; j < size_str; j++)
		{
			if (name[j] == hokkey[i].fio[j]) 
			{
				flag++;
			}
			else break; 
		}
		if (flag == size_str)   
		{
			k++;
			if (k == 1) cout << "\n| � |      ���     ���������      | ����� | ������� �������� | �������� ������ |" << stroka;
			la++;
			cout << "|" << setw(3) << i + 1 << "|" << setw(29) << hokkey[i].fio << "|" << setw(7) << hokkey[i].shayba << "|" << setw(18) << hokkey[i].peredacha << "|" << setw(17) << hokkey[i].shtraf << "|" << stroka;
		}
	}
	if (la == 0) cout << "����� ���������� ���!" << endl;
	_getch();   
}
