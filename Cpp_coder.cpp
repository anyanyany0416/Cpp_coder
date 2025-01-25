#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iomanip>
using namespace std;
int seedall, i, j=-1, k;
int lib_y_or_n[6];//标准库是否存在
/*
6个标准库从0到5分别是
cstdlib,cstring,cmath,ctime,algorithm,iomanip;
*/
int main()
{
	memset(lib_y_or_n,0,sizeof(lib_y_or_n));
	cout << "seed:";
	cin >> seedall;				// 输入最初种子
	srand(seedall);
	cout << "\n#include<iostream>\n#include<cstdio>\n";
	for(i=0;i<6;i++)//调用函数库
	{
	    k=rand()%7;
	    if(k!=j)
	    {
	    	if(k==0)
	    	{
	    		cout<<"#include<cstdlib>\n";
	    		lib_y_or_n[0]=1;
	    	}
	    	else if(k==1)
	    	{
	    		cout<<"#include<cstring>\n";
	    		lib_y_or_n[1]=1;
	    	}
	    	else if(k==2)
	    	{
	    		cout<<"#include<cmath>\n";
	    		lib_y_or_n[2]=1;
	    	}
	    	else if(k==3)
	    	{
	    		cout<<"#include<ctime>\n";
	    		lib_y_or_n[3]=1;
	    	}
	    	else if(k==4)
	    	{
	    		cout<<"#include<algorithm>\n";
	    		lib_y_or_n[4]=1;
	    	}
	    	else if(k==5)
	    	{
	    		cout<<"#include<iomanip>\n";
	    		lib_y_or_n[5]=1;
	    	}
	    }
	    
	    j=k;
	    seedall=abs(seedall+666-j);//更新种子
	    srand(seedall);
	}
	cout<<"using namespace std;\n";
	seedall=seedall%64;//更新种子，防止溢出
	srand(seedall);
	
	return 0;
}