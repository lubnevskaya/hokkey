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
User *Massiv_User(int);				  //Ф-ция возвращающая указатель на массив сруктуры User 
int Number_User_In_File();			  //Ф-ция возвращающая количество записей в файле Users  
void Add_User(string);
void Show_User(string);		  
void Updating_User(string);				  
void Delete_User(string);					 

void Work_With_Hokkey(string);
void Client_Hokkey(string);
Hokkey *Massiv_Hokkey(int);				  //Ф-ция возвращающая указатель на массив сруктуры Hokkey 
int Number_Hokkey_In_File();			  //Ф-ция возвращающая количество записей в файле Hokkey  
int Enter_Int(char*, int);                 //Ф-ция возвращающая правильный ввод числа 
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
		cout << "\tГлавное меню\n\n 1 - Войти в систему как администратор\n 2 - Просмотреть данные\n Иначе - Выход\n\n Введите номер операции: ";
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
	cout << "\tВход в систему\n\nВведите системный логин: ";
	cin.getline(login, 20);
	_flushall();
	cout << "Введите системный пароль: ";
	cin.getline(password, 20);
	if (strcmp(login, "nastya") == 0 && strcmp(password, "514301") == 0) //сравнение введнного логина и пароля с записанными
		Admin(stroka1, stroka2);   
	else
		cout << "\nНеправильный ввод логина или пароля!" << endl;
	_getch();  
}

void Admin(string stroka1, string stroka2)
{
	char a;
	while(true)
	{
		_flushall();        
		system("cls");     
		cout << "\tМеню администратора\n\n\ 1 - Работа с файлами\n 2 - Работа с пользователями\n 3 - Работа с данными\n Иначе - Выход в главное меню\n\n Введите номер операции: ";
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
		_flushall();               //очитка потока 
		system("cls");            //вызов системной ф-ции очитки экрана
		cout<<"\tМеню работы с файлами:\n\n 1 - Создать файл\n 2 - Просмотреть все файлы\n 3 - Удалить файл\n Иначе - Возврат в меню администратора\n\n\ Введите номер операции: ";
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
	cout << "Введите имя файла, который Вы хотите создать:\n(расширение .txt будет добавлено автоматически)\n";
	cin >> file;
	file+=".txt";
	ifstream check(file);
	if(check.is_open()) 
	{
		cout << "Файл с таким именем уже существует!\nЕсли хотите удалить уже существующий файл и создать новый с таким же именем, введите 1\n";
		cin >> kod;
		cout << endl;
		if (kod != '1')
		{
			cout << "Замена файла отменена!\n";
			check.close();
			_getch();
			return;
		}
	}
	ofstream f(file);
	if (!f.is_open()) cout << "Ошибка создания файла!\n";
	else cout << "Файл создан!\n";
	f.close();
	_getch();
}
void Show_Files()
{
	system("cls");  
	cout << "\tФайлы\n\n";
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
	cout << "Введите имя файла, который Вы хотите удалить:\n(расширение .txt будет добавлено автоматически)\n";
	cin >> file;
	file+=".txt";
	ifstream check(file);
	if(!check.is_open()) 
	{
		cout << "Файла с таким именем не существует!\n";
		_getch();
		return;
	}
	check.close();
	cout << "Вы уверены, что хотите удалить этот файл?\n(Если да, то введите 1)\n";
	cin >> kod;
	cout << endl;
	if (kod != '1')
	{
		cout << "Удаление файла отменено!\n";
		_getch();
		return;
	}
	if(!remove(file.c_str())) 
	{
		cout << "Файл удален!\n"; 
		_getch();
	}
	else cout << "Ошибка при удалении файла!\n";
	Show_Files();
}

void Work_With_Clients(string stroka)
{
	char kod;
	while(true)
	{
		_flushall();                
		system("cls");             
		cout << "\tМеню работы с пользователями\n\n 1 - Добавить пользователя\n 2 - Просмор пользователей\n 3 - Изменить пользователя\n 4 - Удалить пользователя\n 5 - Удалить файл\n Иначе - Выход в меню администратора\n\n\ Введите номер операции: ";
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
	//открытие файла
	ifstream file("Users.txt", ios::in | ios::binary);
	//циклическая запись данных из файла в массив структуры User
	for (int i = 0; i < size; i++)
		file.read((char*)(&user[i]), sizeof(User));
	file.close(); //закрытие файла
	return user;
}
int Number_User_In_File()
{
	int size;
	//открытие файла
	ifstream file("Users.txt", ios::binary);
	file.seekg(0, ios::end); //смещение указателя в конец файла
	//определение количества записей путем деления размера файла на размер структура User
	size = (int)(file.tellg() / sizeof(User));
	file.close(); //закрытие файла
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
		cout << "Введите логин пользователя: ";
		cin.getline(user.login, 30);
		_flushall();
		cout << "Введите пароль: ";
		cin.getline(user.password, 30);
		_flushall();
		cout << "Введите права доступа (1 - администратор, 0 - пользователь): ";
		cin >> user.role; 
		if (user.role==0 || user.role==1)  
		{
			cin.ignore(10, '\n');
		}
		else
		{
			cin.clear();  //очитка потока от входных данных
			cout << "Неправильный ввод!";
			cin.ignore(10, '\n'); 
			_getch(); 
			break;
		}
		file.write((char*)(&user), sizeof(User)); //запись объекта в файл
		_flushall();
		system("cls");
		cout << "Введите 1, чтобы создать еще одного пользователя: ";
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
		system("cls");             //вызов системной ф-ции очитки экрана
		cout << "\tПользователи\n\n";
		cout << "| № |        Логин         |     Пароль     | Роль |" << endl << stroka;
		for (int i = 0; i < size; i++)
		{
			cout << endl << "|" << setw(3) << i+1 << "|" << setw(22) << user[i].login << "|" << setw(16) << user[i].password << "|" << setw(6) << user[i].role << "|" << endl << stroka;
		}
		delete[]user;  
		_getch();   
	}
	else
	{
		cout << "Список пользователей пуст!" << endl;
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
			system("cls");                 //вызов системной ф-ции очитки экрана
			Show_User(stroka);    
			_flushall();       //очитка потока
			cout << endl << "Введите номер пользователя, которого хотите изменить: ";
			cin >> number;
			if (number > size)
			{
				cout << "Такого пользователя нет!" << endl;
				_getch();
				return;
			}
			number--;
			while(true)
			{
				system("cls");
				_flushall();
				cout << "| № |        Логин         |     Пароль     | Роль |" << endl << stroka;
				cout << endl << "|" << setw(3) << number+1 << "|" << setw(22) << user[number].login << "|" << setw(16) << user[number].password << "|" << setw(6) << user[number].role << "|" << endl << stroka;
				cout << "\n 1 - Изменить логин пользователя\n 2 - Изменить пароль пользователя\n 3 - Изменить роль пользователя\n Иначе - Вернуться в меню\n\n Введите номер операции: ";
				cin >> c;
				_flushall();
				switch (c)
				{
				case '1':
					system("cls");
					cout << "Введите новый логин пользователя: ";
					cin.getline(user[number].login, 30);
					t = true;
					break;
				case '2':
					system("cls");
					cout << "Введите новый пароль: ";
					cin.getline(user[number].password, 30);
					t = true;
					break;
				case '3':
					cout << "Введите права доступа: ";
					cin >> user[number].role; 
					if (user[number].role==0 || user[number].role==1)  
					{
						t = true;
						cin.ignore(10, '\n');
						break;
					}
					cin.clear();  //очитка потока от входных данных
					cout << "Неправильный ввод!";
					cin.ignore(10, '\n'); 
					_getch();  
				default: return;
				}
			} 
			if (t == true)
			{ 
				ofstream file("Users.txt", ios::binary | ios::in | ios::out);  //открытие файла
				file.seekp(number*sizeof(User));  //смещение указателя на позицию
				file.write((char*)(&user[number]), sizeof(User)); //запись данных на смещенную позицию
				file.close(); 
			}
			system("cls");
			_flushall();
			cout << "Чтобы продолжить изменение пользователей, введите 1: ";
			cin >> c;
		} while (c == '1');
		delete[]user; 
	}
	else
	{
		cout << "Список пользователей пуст!" << endl;
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
		cout << "\nВведите номер пользователя, которого хотите удалить: ";
		cin >> number;
		if (number > size)
		{
			cout << "Такого пользователя нет!" << endl;
			_getch();
			return;
		}
		number--;
		system("cls");
		_flushall();                
		cout << "| № |        Логин         |     Пароль     | Роль |" << endl << stroka;
		cout << endl << "|" << setw(3) << number+1 << "|" << setw(22) << user[number].login << "|" << setw(16) << user[number].password << "|" << setw(6) << user[number].role << "|" << endl << stroka;
	    cout << "\n\nВы уверены, что хотите удалить этого пользователя? (Если да, то введите 1) ";
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
			cout << "Пользователь удален!" << endl;
			_getch();
		}
		delete[]user;    
	}
	else
	{
		cout << "Список пользователей пуст!" << endl;
		_getch();  
	}
}

void Work_With_Hokkey(string stroka)
{
	char kod;
	while (true)
	{
		_flushall();               //очитка потока 
		system("cls");            //вызов системной ф-ции очитки экрана 
		cout << "\tМеню работы с данными\n\n 1 - Просмор данных о хоккеистах\n 2 - Добавить данные о хоккеисте\n 3 - Редактирование данных о хоккеисте\n 4 - Удалить данные хоккеиста\n 5 - Удалить файл\n Иначе - Вернуться в меню администратора\n\n Введите номер операции: ";
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
			_flushall();               //очитка потока 
			system("cls");            //вызов системной ф-ции очитки экрана
			cout << "\tМеню просмотра данных\n\n 1 - Вывести весь список\n 2 - Сортировка\n 3 - Вывести список 6 лучших хоккеистов\n 4 - Найти хоккеиста\n Иначе - Вернуться в меню\n\n Введите номер операции: ";
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
		cout << "Список хоккеистов пуст!" << endl;
		_getch();
	}
}
Hokkey *Massiv_Hokkey(int size)
{
	Hokkey *hokkey = new Hokkey[size];
	ifstream file("Hokkey.txt", ios::in | ios::binary);  //открытие файла
	//циклическая запись данных из файла в массив структуры Hokkey
	for (int i = 0; i < size; i++)
		file.read((char*)(&hokkey[i]), sizeof(Hokkey));
	file.close(); //закрытие файла
	return hokkey;
}
int Number_Hokkey_In_File()
{
	int size;
	ifstream file("Hokkey.txt", ios::binary);   //открытие файла
	file.seekg(0, ios::end); //смещение указателя в конец файла
	size = (int)(file.tellg() / sizeof(Hokkey)); //определение количества записей путем деления размера файла на размер структура Hokkey
	file.close(); //закрытие файла
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
		if (cin.good())  //проверка потока на правильность ввода
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();  //очитка потока от входных данных
		cout << "Неправильный ввод!";
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
		_flushall();       //очитка потока 
		system("cls");	  //вызов системной ф-ции очитки экрана
		cout << "Введите ФИО хоккеиста: ";
		cin.getline(hokkey.fio, 30);
		_flushall();
		hokkey.shayba = Enter_Int("Введите число заброшенных шайб: ", hokkey.shayba);
		hokkey.peredacha = Enter_Int("Введите количесво голевых передач: ", hokkey.peredacha);
		hokkey.shtraf = Enter_Int("Введите количесво штрафных минут: ", hokkey.shtraf);
		file.write((char*)(&hokkey), sizeof(Hokkey)); //запись объекта в файл
		_flushall();
		system("cls");
		cout << "Чтобы добавить еще одного хоккеиста, введите 1: ";
		cin >> c;
	} while (c == '1');
	file.close();  //закрытие файла
} 
void Show_Hokkey(Hokkey* hokkey, int size, string stroka)
{
	system("cls");
	cout << "\tХоккеисты\n\n";
	cout << "| № |      ФИО     хоккеиста      | Шайбы | Голевые передачи | Штрафные минуты |" << stroka;
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
			cout << endl << "Введите номер хоккеиста, которого хотите изменить: ";
			cin >> number;
			if (number > size)
			{
				cout << "Такого хоккеиста нет!" << endl;
				_getch();
				return;
			}
			number--;
			do
			{
				system("cls");
				_flushall();
				cout << "| № |      ФИО     хоккеиста      | Шайбы | Голевые передачи | Штрафные минуты |" << stroka;
				cout << "|" << setw(3) << number+1 << "|" << setw(29) << hokkey[number].fio << "|" << setw(7) << hokkey[number].shayba << "|" << setw(18) << hokkey[number].peredacha << "|" << setw(17) << hokkey[number].shtraf << "|" << stroka;
				cout <<"\n 1 - Изменить ФИО хоккеиста\n 2 - Изменить количество заброшенных шайб\n 3 - Изменить количество голевых передач\n 4 - Изменить количество штрафных минут\n Иначе - Возврат в меню работы с данными\n\n Введите номер операции: ";
				cin >> c;
				_flushall();
				switch (c)
				{
				case '1':
					system("cls");
					cout << "Введите ФИО хоккеиста: ";
					cin.getline(hokkey[number].fio, 30);
					t = true;
					break;
				case '2': 
					hokkey[number].shayba = Enter_Int("Измените число заброшенных шайб: ", hokkey[number].shayba);
					t = true;
					break;
				case '3':
					hokkey[number].peredacha = Enter_Int("Измените количесво голевых передач: ", hokkey[number].peredacha);
					t = true;
					break;
				case '4':
					hokkey[number].shtraf = Enter_Int("Измените количесво штрафных минут: ", hokkey[number].shtraf);
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
				file.seekp(number*sizeof(Hokkey));  //смещение указателя на позицию
				file.write((char*)(&hokkey[number]), sizeof(Hokkey)); //запись данных на смещенную позицию
				file.close(); 
			}
			system("cls");
			_flushall();
			cout << "Чтобы продолжить изменять данные о хоккеистах, введите 1: ";
			cin >> c;
		} while (c == '1');
		delete[]hokkey; 
	}
	else
	{
		cout << "Список хоккеистов пуст!" << endl;
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
		cout << "\nВведите номер хоккеиста, которого хотите удалить: ";
		cin >> number;
		if (number > size)
		{
			cout << "Такого хоккеиста нет!" << endl;
			_getch();
			return;
		}
		number--;
		system("cls");
		_flushall();                
		cout << "| № |      ФИО     хоккеиста      | Шайбы | Голевые передачи | Штрафные минуты |" << stroka;
		cout << "|" << setw(3) << number+1 << "|" << setw(29) << hokkey[number].fio << "|" << setw(7) << hokkey[number].shayba << "|" << setw(18) << hokkey[number].peredacha << "|" << setw(17) << hokkey[number].shtraf << "|" << stroka;
		cout << endl;
		cout << "\nВы действительно хотите удалить хоккеиста? (Есди да, то введите 1) ";
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
			cout << "Хоккеист удален!" << endl;
			_getch();
		}
		delete[]hokkey;    
	}
	else
	{
		cout << "Список хоккеистов пуст!" << endl;
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
	cout << "| № |      ФИО     хоккеиста      | Шайбы | Голевые передачи | Штрафные минуты |" << stroka;		
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
	system("cls");   //вызов системной ф-ции очитки экрана
	cout << "Выберите вид сортировки:\n 1 - по чилу заброшенных шайб\n 2 - по количеству голевых передач\n 3 - по количеству штрафных минут\n Иначе - выход\n";
	cin >> kod;
	if(kod<1||kod>3) return;
	for(i = 0; i < size-1; i++)
		for(j = i+1; j < size; j++)
		{
			if((kod==1 && hokkey[j].shayba > hokkey[i].shayba) || (kod==2 && hokkey[j].peredacha > hokkey[i].peredacha) || (kod==3 && hokkey[i].shtraf < hokkey[j].shtraf))
					swap(hokkey[i],hokkey[j]);
		}
	cout << "| № |      ФИО     хоккеиста      | Шайбы | Голевые передачи | Штрафные минуты |" << stroka;
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
	cout << "Введите ФИО интересующего Вас хоккеиста, возможен поиск по начальным буквам: \n";
	cin.getline(name, 30);
	int la = 0, flag, k = 0;
	int size_str = strlen(name);   //Функция strlen возвращает в байтах длину строки
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
			if (k == 1) cout << "\n| № |      ФИО     хоккеиста      | Шайбы | Голевые передачи | Штрафные минуты |" << stroka;
			la++;
			cout << "|" << setw(3) << i + 1 << "|" << setw(29) << hokkey[i].fio << "|" << setw(7) << hokkey[i].shayba << "|" << setw(18) << hokkey[i].peredacha << "|" << setw(17) << hokkey[i].shtraf << "|" << stroka;
		}
	}
	if (la == 0) cout << "Таких хоккеистов нет!" << endl;
	_getch();   
}
