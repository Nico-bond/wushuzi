#include<stdio.h>
int V[200][200];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ
int max(int a,int b)
{
   if(a>=b)
       return a;
   else return b;
}
 
int zhuanhuan(int n,int w[],int p[],int x[],int C)
{
    int i,j;
	//���,���е�һ�к͵�һ��ȫΪ0
    for(i=0;i<=n;i++)
        V[i][0]=0;
    for(j=0;j<=C;j++)
        V[0][j]=0;
    for(i=1;i<=n;i++)
	{
		printf("%d  %d  %d  ",i,w[i-1],p[i-1]);
        for(j=1;j<=C;j++)
		{
            if(j<w[i-1])
			{
				V[i][j]=V[i-1][j];
				printf("[%d][%d]=%2d  ",i,j,V[i][j]);
			}
			
            else
			{
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i-1]]+p[i-1]);
				printf("[%d][%d]=%2d  ",i,j,V[i][j]);
			}
		}
		printf("\n");
	}
	//�ж���Щ��Ʒ��ѡ��
            j=C;
            for(i=n;i>=1;i--)
            {
            if(V[i][j]>V[i-1][j])
                {
					x[i]=1;
					j=j-w[i-1];
                }
            else
                x[i]=0;
            }
            printf("ѡ�е���Ʒ��:\n");
            for(i=1;i<=n;i++)
                printf("%d ",x[i]);
            printf("\n");
        return V[n][C];
        
}
 
void main()
{
    int sum;//��õ�����ֵ
    int w[15];//��Ʒ������
    int p[15];//��Ʒ�ļ�ֵ
    int x[15];//��Ʒ��ѡȡ״̬
    int n,i;
    int C;//�����������
    n=5;
    printf("�����뱳�����������:\n");
    scanf("%d",&C);
    
    printf("������Ʒ��:\n");
    scanf("%d",&n);
    printf("��ֱ�������Ʒ������:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
 
    printf("��ֱ�������Ʒ�ļ�ֵ:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
 
    sum=zhuanhuan(n,w,p,x,C);//hanshudiaoyong��zhuanhuan��
 
    printf("�����Ʒ��ֵΪ:\n");
    printf("%d\n",sum);
   
    
}
