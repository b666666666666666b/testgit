//�ô����������˳�����ν��� 
#include<stdio.h>
int main()
{
	int a[5],b[5],c[5],st=1,i,j,temp,result,t,zt=0;
	FILE *fpRead=fopen("input.txt","r");
	for(i=0;i<5;i++)
	{
		fscanf(fpRead,"%d %d %d",&a[i],&b[i],&c[i]);
	}//�������� 
	for(i=0;i<5;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];a[j+1]=a[j];a[j]=temp;
				temp=b[j+1];b[j+1]=b[j];b[j]=temp;
				temp=c[j+1];c[j+1]=c[j];c[j]=temp;
			}
		}
	}//������ʱ������ 
	FILE *fpWrite=fopen("output.txt","w");
	t=b[0]-1+a[0];//����ͣ��ʱ�� 
	fprintf(fpWrite,"%dʱ��ͣ����%d\n",t,b[0]);
	t=t+c[0]-b[0]+1;
	fprintf(fpWrite,"%dʱ��ͣ����%d\n",t,c[0]);
	zt=t-a[0];if(c[0]!=b[1])t=t+1;
	for(i=1;i<5;i++)
	{
		if(a[i]<=t)
		{
			t=t+b[i]-c[i-1];
			fprintf(fpWrite,"%dʱ��ͣ����%d\n",t,b[i]);
			t=t+c[i]-b[i];
			fprintf(fpWrite,"%dʱ��ͣ����%d\n",t,c[i]);
			zt=zt+t-a[i];
			if(i!=5&&c[i]!=b[i+1])t=t+1;
		}
		else
		{
			t=a[i]+b[i]-c[i-1];
			fprintf(fpWrite,"%dʱ��ͣ����%d\n",t,b[i]);
			t=t+c[i]-b[i];
			fprintf(fpWrite,"%dʱ��ͣ����%d\n",t,c[i]);
			zt=t-a[i];
			if(i!=5&&c[i]!=b[i+1])t=t+1;
		}
	}//zt���ܵȴ�ʱ�䣬t��ʱ�� 
	fprintf(fpWrite,"�˿͵ȴ�ʱ��Ϊ%d",zt);
	return 0;
}
