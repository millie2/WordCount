//ģ�鹦�ܣ�������Ҫѡ������ļ��ڵ��ַ��������ߵ�������

//ģ��ӿڣ�
//*fp��ָ���ļ���ָ��
//filename[20]���ļ����ַ���
//parameter[5]�����Ʋ����ַ���
//character���ַ���������
//word�����ʼ�������

//�ֲ�������
//middle��
//��;������ȡ�����ַ������ں����ж��Ƿ�Ϊ�����Ƿ�Ϊ���ʵ������ַ�

//������ʷ��
//����ߣ������
//�޸����ڣ�2020.5.19

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
	//��ȡ����������ַ���

	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("�ļ���ʧ��\n");
		return ;
	}
	//�ж��ļ��Ƿ������򿪣���ʱ����

	if ( parameter[1]=='c')
	{
		while(!feof(fp))   //�ж��ļ��Ƿ����
		{
			fgetc(fp)&&character++; 
		}
		//���ȡ�ַ��ɹ���character������һ

		printf("�ַ���: %d\n",character);
	}
	else                    //������-wʱ
	{
		while(!feof(fp))   //�ж��ļ��Ƿ����
		{
			char middle=0;
			middle=fgetc(fp);
			//�����м����middle���ڻ���ȡ�����ַ�

			if ((middle==' ')||(middle==',')||(middle=='.'))
			{
				word++;
			} 
			//���ַ�Ϊ�ո񡢶ٺź;��ʱword��������һ
		}

		printf(" ������: %d\n",word);
	}
	fclose(fp);
	return ;
}
