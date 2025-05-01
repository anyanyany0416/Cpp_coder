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
	short fc;						// 函数类型
	char fname[10];				// 函数名称
	char fxname[10][10];			// 形参名称
	short fxc[10];			// 形参类型
};
struct constvar//常量信息
{
	char name[10];
	bool fill;//是否已赋值
	short class_;
	bool have;//是否已定义
	int wifi;
};
struct varclass//变量信息
{
	char name[10];
	bool fill;//是否已赋值
	short class_;
	bool have;//是否已定义
	int wifi;
};
constvar cvars[106];
varclass vars[150];
f_x_ fx[10];
char rstr[10],rstr2[200];
int seedall;
int i, j = -1, k, l, m, n, x, y, z;
short vgb,cjb;
bool lib_y_or_n[6];				// 标准库是否存在
short fillvar,fillcvar;
/* 
   6个标准库从0到5分别是
   cstdlib,cstring,cmath,ctime,algorithm,iomanip; */
void rlowstr()//实现随机非法字符串
{
	int ri,rj,it;
	srand(seedall+time(NULL)%24);
	ri=rand()%198+2;
	rj=rand()%26;
	rstr2[0]='a'+rj;
	for(it=1;it<ri;it++)
	{
		srand(seedall);
		seedall++;
		rj=rand()%95;
		rstr2[it]=' '+rj;
		if(rstr2[it]=='\''||(rstr2[it]=='\"'||rstr2[it]=='\\'))
		    rstr2[it-1]='\\';
	}
	rj=rand()%8;
	if(rj==0&&ri>=2)
	{
		rstr2[ri]='n';
		rstr2[ri-1]='\\';
	}
}
void randstr()					// 实现随机标识符
{
	int rx, ry, rz, ri;
	srand(abs(rand()-seedall));
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
	srand(rand()+seedall);
	rx = rand() % 8 + 2;
	for (ri = 1; ri < rx; ri++)
	{
		srand(rand());
		ry = rand() % 3;
		if (ry == 0)
		{
			srand(rand()-1);
			rz = rand() % 26;
			rstr[ri] = 'a' + rz;
		}
		else if (ry == 1)
		{
			srand(rand()+1);
			rz = rand() % 26;
			rstr[ri] = 'A' + rz;
		}
		else if (ry == 2)
		{
			srand(rand());
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
		if (lib_y_or_n[k] = true)
		{
			l = 0;
		}
		
		if (l == 1)
		{
			if (k == 0)
			{
				cout << "#include<cstdlib>\n";
				lib_y_or_n[0] = true;
			}
			else if (k == 1)
			{
				cout << "#include<cstring>\n";
				lib_y_or_n[1] = true;
			}
			else if (k == 2)
			{
				cout << "#include<cmath>\n";
				lib_y_or_n[2] = true;
			}
			else if (k == 3)
			{
				cout << "#include<ctime>\n";
				lib_y_or_n[3] = true;
			}
			else if (k == 4)
			{
				cout << "#include<algorithm>\n";
				lib_y_or_n[4] = true;
			}
			else if (k == 5)
			{
				cout << "#include<iomanip>\n";
				lib_y_or_n[5] = true;
			}
		}
		seedall = abs(seedall + 666 - j);	// 更新种子
		srand(seedall);
	}
}
void bds(int wid,short classes)//表达式生成
{
	int bdsr1,bdsi1;
	short bdsj1[2];
	srand(rand());	
	while(1)
	{
		bdsr1=rand()%3;
		srand(rand());
		if(bdsr1=0)
	    {
	    	cout<<rand()%128;
    	}
	    if(bdsr1=1)
	    {
	    	bdsj1[0]=0;
	    	for(bdsi1=0;bdsi1<vgb;bdsi1++)
	    	{
	    		if(vars[bdsi1].fill==true&&(vars[bdsi1].class_==classes&&(vars[bdsi1].wifi==-2||vars[bdsi1].wifi==wid)))
	    		{
	    			bdsj1[0]++;
	    			if(rand()%24>=11)
	    			{
	    			    cout<<vars[bdsi1].name;
	    			    break;
	    			}
	    		}
	    	}
	    	if(bdsj1[0]==0)
	    	cout<<rand()%128;
	    }
	    if(bdsr1=2)
    	{
    		bdsj1[1]=0;
	    	for(bdsi1=0;bdsi1<vgb;bdsi1++)
	    	{
	    		if(cvars[bdsi1].fill==true&&(cvars[bdsi1].class_==classes&&(cvars[bdsi1].wifi==-2||cvars[bdsi1].wifi==wid)))
	    		{
	    			bdsj1[1]++;
	    			if(rand()%2==1)
	    			{
	    			    cout<<vars[bdsi1].name;
	    			    break;
	    			}
	    		}
	    	}
	    	if(bdsj1[1]==0)
	    	cout<<rand()%128;
	    }
	    bdsr1=rand()%5;
	    if(bdsr1==0)
	        break;
	    else if(bdsr1==1)
	        cout<<"+";
	    else if(bdsr1==2)
	        cout<<"-";
	    else if(bdsr1==3)
	        cout<<"*";
	    else if(bdsr1==4)
	        cout<<"/";
	}
	cout<<"\b";
}

void fill_var(int fid)//赋值
{
	if(rand()%2==0)
	{
		k=rand()%vgb;
		cout<<vars[k].name<<"=";
		bds(fid,vars[k].class_);
		cout<<";\n";
		vars[k].fill==true;
	}
	else if(rand()%2==1)
	{
		k=rand()%cjb;
		if(cvars[k].fill!=true)
		{
		cout<<cvars[k].name<<"=";
		bds(fid,cvars[k].class_);
		cout<<";\n";
		cvars[k].fill=true;
		}
	}
	
}
void in(int iid)//输入
{
	
}
void out(int oid)//输出
{
	
}
void box(int id)						// 函数内容
{
	k=rand()%16+1;
	n=0;
	x=0;
	y=0;
	z=0;
	for(i=vgb-1;i<k+vgb;i++)//定义局部变量
	{
		srand(rand()*time(NULL)%128);
		j=rand()%4;
		
		vars[i].class_=j;
		switch(j)
		{
			case 0:
			     n++;
			     break;
			case 1:
			     x++;
			     break;
			case 2:
			     y++;
			     break;
			default:
			     z++;
		}
		vars[i].wifi=id;
		randstr();
		strcpy(vars[i].name,rstr);
		vars[i].have=true;
	}
	if(n>0)
	{
		cout<<"int ";
		for(i=vgb-1;i<k+vgb;i++)
		{
			if(vars[i].class_==0)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(x>0)
	{
		cout<<"double ";
		for(i=vgb-1;i<k+vgb;i++)
		{
			if(vars[i].class_==1)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(y>0)
	{
		cout<<"long long ";
		for(i=vgb-1;i<k+vgb;i++)
		{
			if(vars[i].class_==2)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(z>0)
	{
		cout<<"char ";
		for(i=vgb-1;i<k+vgb;i++)
		{
			if(vars[i].class_==3)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	vgb=vgb+k;
	k=rand()%10+1;
	n=0;
	x=0;
	y=0;
	z=0;
	for(i=cjb-1;i<k+cjb;i++)//定义局部常量
	{
		srand(rand()*time(NULL)%128);
		j=rand()%4;
		
		cvars[i].class_=j;
		switch(j)
		{
			case 0:
			     n++;
			     break;
			case 1:
			     x++;
			     break;
			case 2:
			     y++;
			     break;
			default:
			     z++;
		}
		cvars[i].wifi=id;
		randstr();
		strcpy(cvars[i].name,rstr);
		cvars[i].have=true;
	}
	cout<<"const ";
	if(n>0)
	{
		cout<<"int ";
		for(i=cjb-1;i<k+cjb;i++)
		{
			if(cvars[i].class_==0)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(x>0)
	{
		cout<<"double ";
		for(i=cjb-1;i<k+cjb;i++)
		{
			if(cvars[i].class_==1)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(y>0)
	{
		cout<<"long long ";
		for(i=cjb-1;i<k+cjb;i++)
		{
			if(cvars[i].class_==2)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(z>0)
	{
		cout<<"char ";
		for(i=cjb-1;i<k+cjb;i++)
		{
			if(cvars[i].class_==3)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	cjb=cjb+k;
	srand(rand()*time(NULL));
	while(1)
	{
		srand(rand());
		n=rand()%22;
		if(n==0)
		    break;
		else if(n>0&&n<8)
		    in(id);
		else if(n>7&&n<15)
		    out(id);
		else if(n>14&&n<22)
		    fill_var(id);
	}
}
int main()
{
	short hit;
	int hib;
	srand((time(NULL)*seedall)%128);			// 使运气和种子共同决定结果
	k = rand() % 64;
	memset(lib_y_or_n, 0, sizeof(lib_y_or_n));
	cout << "seed:";
	cin >> seedall;				// 输入最初种子
	seedall = seedall * k;

	lib_h();

	cout << "using namespace std;\n";
	seedall = seedall % 64;		// 更新种子，防止溢出
	srand(seedall);
	k=rand()%19+1;
	vgb=k;
	n=0;
	x=0;
	y=0;
	z=0;
	for(i=0;i<k;i++)//定义全局变量
	{
		srand(rand()*time(NULL)%128);
		j=rand()%4;
		vars[i].wifi=-2;
		vars[i].class_=j;
		switch(j)
		{
			case 0:
			     n++;
			     break;
			case 1:
			     x++;
			     break;
			case 2:
			     y++;
			     break;
			default:
			     z++;
		}
		randstr();
		strcpy(vars[i].name,rstr);
		vars[i].have=true;
	}
	if(n>0)
	{
		cout<<"int ";
		for(i=0;i<k;i++)
		{
			if(vars[i].class_==0)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(x>0)
	{
		cout<<"double ";
		for(i=0;i<k;i++)
		{
			if(vars[i].class_==1)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(y>0)
	{
		cout<<"long long ";
		for(i=0;i<k;i++)
		{
			if(vars[i].class_==2)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(z>0)
	{
		cout<<"char ";
		for(i=0;i<k;i++)
		{
			if(vars[i].class_==3)
			    cout<<vars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	k=rand()%5+1;
	cjb=k;
	n=0;
	x=0;
	y=0;
	z=0;
	for(i=0;i<k;i++)//定义全局常量
	{
		srand(rand()*time(NULL)%128);
		j=rand()%4;
		cvars[i].wifi=-2;
		cvars[i].class_=j;
		switch(j)
		{
			case 0:
			     n++;
			     break;
			case 1:
			     x++;
			     break;
			case 2:
			     y++;
			     break;
			default:
			     z++;
		}
		randstr();
		strcpy(cvars[i].name,rstr);
		cvars[i].have=true;
	}
	if(n>0)
	{
		cout<<"const int ";
		for(i=0;i<k;i++)
		{
			if(cvars[i].class_==0)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(x>0)
	{
		cout<<"const double ";
		for(i=0;i<k;i++)
		{
			if(cvars[i].class_==1)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(y>0)
	{
		cout<<"const long long ";
		for(i=0;i<k;i++)
		{
			if(cvars[i].class_==2)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	if(z>0)
	{
		cout<<"const char ";
		for(i=0;i<k;i++)
		{
			if(cvars[i].class_==3)
			    cout<<cvars[i].name<<",";
		}
		cout<<"\b;\n";
	}
	hib= rand() % 9 + 1;
	for (i = 0; i < hib; i++)		// 自定义函数部分
	{
		hit= rand() % 5;
		if (hit == 0)
		{
			cout << "void ";
		}
		else if (hit== 1)
		{
			cout << "int ";
		}
		else if (hit== 2)
		{
			cout << "double ";
		}
		else if (hit== 3)
		{
			cout << "long long ";
		}
		else if (hit == 4)
		{
			cout << "char ";
		}
		fx[i].fc = hit;
		randstr();
		strcpy(fx[i].fname, rstr);
		cout << fx[i].fname << "(";
		seedall = seedall + time(NULL);
		srand(seedall);
		n = rand() % 3 + 1;		// 形参
		for (l = 0; l < n; l++)
		{
			x = rand() % 4;
			if (x == 0)
				cout << "int ";
			else if (x == 1)
				cout << "double ";
			else if (x==2)
				cout << "long long ";
			else
			     cout<<"char ";
			fx[i].fxc[l] = x;
			randstr();
			strcpy(fx[i].fxname[l], rstr);
			cout << fx[i].fxname[l] << "," ;
		}
		cout << "\b)\n{\n";
		box(i);
		if (fx[i].fc != 0)		// 返回返回值
		{
			cout << "return " ;
			bds(i,fx[i].fc);
			cout<< ";\n";
		}
		cout << "}\n";

	}
	cout << "int main()\n{\n";	// 主函数部分
	box(-1);
	cout << "return 0;\n}";
	return 0;
}