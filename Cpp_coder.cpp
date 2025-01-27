#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iomanip>
using namespace std;
struct f_x_						// 自定义函数信息
{
	int fc;						// 函数类型
	char fname[10];				// 函数名称
	char fre[10];				// 返回值
	char fxname[4][10];			// 形参
	int fxc[4];					// 形参类型
};
f_x_ fx[10];
char rstr[10];
int seedall, h[6], i, j = -1, k, l, m, n, x, y, z;
int lib_y_or_n[6];				// 标准库是否存在
/* 
   6个标准库从0到5分别是
   cstdlib,cstring,cmath,ctime,algorithm,iomanip; */
void box()						// 函数内容
{
	// 这里未完成
}

void randstr()					// 实现随机字符串
{
	int rx, ry, rz, ri;
	seedall = abs(seedall - 114514) % 64 + time(NULL);
	srand(seedall);
	ry = rand() % 2;
	if (ry == 0)
	{
		rz = rand() % 26;
		rstr[0] = 'a' + rz;
	}
	else if (ry == 1)
	{
		rz = rand() % 26;
		rstr[0] = 'A' + rz;
	}
	seedall = seedall % 64 + 6;
	srand(seedall);
	rx = rand() % 8 + 2;
	for (ri = 1; ri < rx; ri++)
	{
		seedall = seedall + time(NULL);
		srand(seedall);
		ry = rand() % 3;
		if (ry == 0)
		{
			rz = rand() % 26;
			rstr[ri] = 'a' + rz;
		}
		else if (ry == 1)
		{
			rz = rand() % 26;
			rstr[ri] = 'A' + rz;
		}
		else if (ry == 2)
		{
			rz = rand() % 10;
			rstr[ri] = '0' + rz;
		}
	}
}

void lib_h()					// 函数库
{
	srand(seedall);
	cout << "\n#include<iostream>\n#include<cstdio>\n";
	for (i = 0; i < 6; i++)		// 调用函数库
	{
		l = 1;
		k = rand() % 7;
		for (j = 0; j < i; j++)
		{
			if (k == h[j])
			{
				l = 0;
			}
		}
		if (l == 1)
		{
			if (k == 0)
			{
				cout << "#include<cstdlib>\n";
				lib_y_or_n[0] = 1;
			}
			else if (k == 1)
			{
				cout << "#include<cstring>\n";
				lib_y_or_n[1] = 1;
			}
			else if (k == 2)
			{
				cout << "#include<cmath>\n";
				lib_y_or_n[2] = 1;
			}
			else if (k == 3)
			{
				cout << "#include<ctime>\n";
				lib_y_or_n[3] = 1;
			}
			else if (k == 4)
			{
				cout << "#include<algorithm>\n";
				lib_y_or_n[4] = 1;
			}
			else if (k == 5)
			{
				cout << "#include<iomanip>\n";
				lib_y_or_n[5] = 1;
			}
		}
		h[i] = k;
		seedall = abs(seedall + 666 - j);	// 更新种子
		srand(seedall);
	}
}

int main()
{
	srand(time(NULL));			// 使运气和种子共同决定结果
	k = rand() % 64;
	memset(lib_y_or_n, 0, sizeof(lib_y_or_n));
	cout << "seed:";
	cin >> seedall;				// 输入最初种子
	seedall = seedall * k;

	lib_h();

	cout << "using namespace std;\n";
	seedall = seedall % 64;		// 更新种子，防止溢出
	srand(seedall);
	k = rand() % 9 + 1;
	for (i = 0; i < k; i++)		// 自定义函数部分
	{
		j = rand() % 5;
		if (j == 0)
		{
			cout << "void ";
		}
		else if (j == 1)
		{
			cout << "int ";
		}
		else if (j == 2)
		{
			cout << "double ";
		}
		else if (j == 3)
		{
			cout << "long long ";
		}
		else if (j == 4)
		{
			cout << "char ";
		}
		fx[i].fc = j;
		randstr();
		strcpy(fx[i].fname, rstr);
		cout << fx[i].fname << "(";
		seedall = seedall + time(NULL);
		srand(seedall);
		n = rand() % 3 + 1;		// 形参
		for (l = 0; l < n; l++)
		{
			x = rand() % 3;
			if (x == 0)
			{
				cout << "int ";
			}
			else if (x == 1)
			{
				cout << "double ";
			}
			else
			{
				cout << "long long ";
			}
			fx[i].fxc[l] = x;
			randstr();
			strcpy(fx[i].fxname[l], rstr);
			cout << fx[i].fxname[l] << "," ;
		}
		cout << "\b)\n{\n";
		randstr();
		strcpy(fx[i].fre, rstr);	// 返回值
		if (j != 0)
		{
			if (j == 1)
			{
				cout << "int ";
			}
			else if (j == 2)
			{
				cout << "double ";
			}
			else if (j == 3)
			{
				cout << "long long ";
			}
			else if (j == 4)
			{
				cout << "char ";
			}
			cout << fx[i].fre << ";\n";
		}
		box();
		if (fx[i].fc != 0)		// 返回返回值
		{
			cout << "return " << fx[i].fre << ";\n";
		}
		cout << "}\n";

	}
	cout << "int main()\n{\n";	// 主函数部分
	box();
	cout << "return 0;\n}";
	return 0;
}
