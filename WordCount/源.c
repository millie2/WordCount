//模块功能：按照需要选择计算文件内的字符数量或者单词数量

//模块接口：
//*fp：指向文件的指针
//filename[20]：文件名字符串
//parameter[5]：控制参数字符串
//character：字符计数参数
//word：单词计数参数

//局部变量：
//middle：
//用途：缓存取出的字符，用于后期判断是否为决定是否为单词的特殊字符

//开发历史：
//设计者：陈淼伶
//修改日期：2020.5.19

#include<stdio.h>
int main()
{
	FILE *fp;
	char filename[20];
	char parameter[5];
	int character=0;
	int word=0;

	gets(parameter);
	gets(filename);
	//获取输入的两个字符串

	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		return ;
	}
	//判断文件是否正常打开，及时反馈

	if ( parameter[1]=='c')
	{
		while(!feof(fp))   //判断文件是否结束
		{
			fgetc(fp)&&character++; 
		}
		//如获取字符成功则character计数加一

		printf("字符数: %d\n",character);
	}
	else                    //当输入-w时
	{
		while(!feof(fp))   //判断文件是否结束
		{
			char middle=0;
			middle=fgetc(fp);
			//设置中间变量middle用于缓存取出的字符

			if ((middle==' ')||(middle==',')||(middle=='.'))
			{
				word++;
			} 
			//当字符为空格、顿号和句号时word计数器加一
		}

		printf(" 单词数: %d\n",word);
	}
	fclose(fp);
	return ;
}
