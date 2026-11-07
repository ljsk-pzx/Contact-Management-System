#include <iostream>
#include <string>

#define max 1000

struct Person {//通讯信息
	std::string m_name;
	int m_age;
	std::string m_sex;
	std::string m_phone;
	std::string m_address;
};

struct Addbook {//通讯簿
	struct Person personArray[max];
	int m_size;
};

void showmenu() {
	std::cout << "********************" << std::endl;
	std::cout << "*** 1.添加通讯录 ***" << std::endl;
	std::cout << "*** 2.显示通讯录 ***" << std::endl;
	std::cout << "*** 3.删除通讯录 ***" << std::endl;
	std::cout << "*** 4.查找通讯录 ***" << std::endl;
	std::cout << "*** 5.修改通讯录 ***" << std::endl;
	std::cout << "*** 6.清空通讯录 ***" << std::endl;
	std::cout << "*** 0.退出通讯录 ***" << std::endl;
	std::cout << "********************" << std::endl;
}

void Addperson(Addbook* abs) {
	if (abs->m_size == max) {
		std::cout << "通讯录已满，无法加入！" << std::endl;
		return;//这里需要返回，否则通讯录已满后，会死循环
	}
	else {
		std::string name;
		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		int age;
		std::cout << "请输入年龄：" << std::endl;
		std::cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		int sex;
		std::cout << "请输入性别：1.男  2.女" << std::endl;
		std::cin >> sex;
		if (sex == 1) {
			abs->personArray[abs->m_size].m_sex = "男";
		}else if (sex == 2) {
			abs->personArray[abs->m_size].m_sex = "女";
		}else {
			std::cout << "输入有误，请重新输入！" << std::endl;
			return;
		}

		std::string m_phone;
		std::cout << "请输入电话：" << std::endl;
		std::cin >> m_phone;
		abs->personArray[abs->m_size].m_phone = m_phone;

		std::string m_address;
		std::cout<< "请输入地址：" << std::endl;
		std::cin >> m_address;
		abs->personArray[abs->m_size].m_address = m_address;

		abs->m_size++;
		std::cout<< " 添加成功！" << std::endl;
	}
};

void Showperson(Addbook* abs) {
	if (abs->m_size == 0) {
		std::cout << "通讯录为空！" << std::endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			std::cout << i + 1<<". ";
			std::cout << "姓名：" << abs->personArray[i].m_name << "\t";
			std::cout << "年龄：" << abs->personArray[i].m_age << "\t";
			std::cout << "性别：" << abs->personArray[i].m_sex << "\t";
			std::cout << "电话：" << abs->personArray[i].m_phone << "\t";
			std::cout << "地址：" << abs->personArray[i].m_address << std::endl;
		}
	}
};

void Deleteperson(Addbook * ads) {
	std ::string name;
	std::cout << "请输入要删除的联系人姓名：" << std::endl;
	std::cin >> name;
	for (int i = 0; i < ads->m_size; i++) {
		if (ads->personArray[i].m_name == name) {
			for (int j = i; j < ads->m_size - 1; j++) {
				ads->personArray[j] = ads->personArray[j + 1];
			}
			ads->m_size--;
			std::cout << "删除成功！" << std::endl;
			return;
		}
	}
	std::cout << "未找到联系人！" << std::endl;
}

void Findperson(Addbook* abs) {
	std::string name;
	std::cout << "请输入要查找的联系人姓名：" << std::endl;
	std::cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			std::cout << i + 1 << ". ";
			std::cout << "姓名：" << abs->personArray[i].m_name << "\t";
			std::cout << "年龄：" << abs->personArray[i].m_age << "\t";
			std::cout << "性别：" << abs->personArray[i].m_sex << "\t";
			std::cout << "电话：" << abs->personArray[i].m_phone << "\t";
			std::cout << "地址：" << abs->personArray[i].m_address << std::endl;
			return;
		}
		else {
			std::cout << "未找到联系人！" << std::endl;
		}
	}
	
}

void Updateperson(Addbook* abs) {
	std::string name;
	std::cout << "请输入要修改的联系人姓名：" << std::endl;
	std::cin >> name;
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			std::string e_name;
			std::cout << "请重新输入姓名：" << std::endl;
			std::cin >> e_name;
			abs->personArray[abs->m_size].m_name = e_name;

			int age;
			std::cout << "请重新输入年龄：" << std::endl;
			std::cin >> age;
			abs->personArray[abs->m_size].m_age = age;

			int sex;
			std::cout << "请重新输入性别：1.男  2.女" << std::endl;
			std::cin >> sex;
			if (sex == 1) {
				abs->personArray[abs->m_size].m_sex = "男";
			}
			else if (sex == 2) {
				abs->personArray[abs->m_size].m_sex = "女";
			}
			else {
				std::cout << "输入有误，请重新输入！" << std::endl;
				return;
			}

			std::string m_phone;
			std::cout << "请重新输入电话：" << std::endl;
			std::cin >> m_phone;
			abs->personArray[abs->m_size].m_phone = m_phone;

			std::string m_address;
			std::cout << "请重新输入地址：" << std::endl;
			std::cin >> m_address;
			abs->personArray[abs->m_size].m_address = m_address;

			std::cout << "修改成功！" << std::endl;
			return;
		}
		else {
			std::cout << "未找到联系人！" << std::endl;
		}
	}
}

void Zeroperson(Addbook* abs) {
	abs->m_size = 0;
	std::cout << "清空成功！" << std::endl;
}

int main() {
	int select;//用户可输入的变量
	Addbook abs;
	abs.m_size = 0;
	while (true) {
		system("cls"); // 【关键点】：清空屏幕
		showmenu();//显示菜单放这里是因为每次循环都要显示菜单
		std::cin >> select;
		switch (select) {
		case 1://1.添加通讯录
			Addperson(&abs);
			system("pause"); // 加上这个，让程序暂停，提示“请按任意键继续...”，用户按键后才清屏进入下一次循环
			break;
		case 2://2.显示通讯录
			Showperson(&abs);
			system("pause"); 
			break;
		case 3://3.删除通讯录
			Deleteperson(&abs);
			system("pause");
			break;
		case 4://4.查找通讯录
			Findperson(&abs);
			system("pause");
			break;
		case 5://5.修改通讯录
			Updateperson(&abs);
			system("pause");
			break;
		case 6://6.清空通讯录
			system("pause");
			Zeroperson(&abs);
			break;
		case 0://0.退出通讯录
			std::cout << "欢迎下次使用" << std::endl;
			system("pause");
			return 0;//这里必须返回0，直接结束，否则会一直输出欢迎下次使用
			break;
		default://其他情况直接结束
			break;
		}
	}

	return 0;
}