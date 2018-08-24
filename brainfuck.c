#include <stdio.h>

void main()
{
	long long m[1024]={0};
	int p=0;
	char s[]=",>,<[->+<]>.\0";
	//char s[]=",,+.";
	int i=0;

	while (s[i]!='\0')
	{
		if(s[i]=='>')
		{
			p+=1;
			i+=1;
		}
		else if(s[i]=='<')
		{
			p-=1;
			i+=1;
		}
		else if(s[i]=='+')
		{
			*(m+p)+=1;
			i+=1;
		}
		else if(s[i]=='-')
		{
			*(m+p)-=1;
			i+=1;
		}
		else if(s[i]==',')
		{
			scanf("%lld",m+p);
			i+=1;
		}
		else if(s[i]=='.')
		{
			printf("%c",(char)*(m+p));
			i+=1;
		}
		else if(s[i]=='[')
		{
			if (*(m+p)==0)
			{
				int cnt=1;
				int j=1;
				while (1)
				{
					if (s[i+j]=='[')
					{
						cnt+=1;
					}
					if (s[i+j]==']')
					{
						cnt-=1;
					}
					if (cnt==0)
					{
						i=i+j+1;
						break;
					}
					j+=1;
				}
			}
			else
			{
				i+=1;
			}
		}
		else if(s[i]==']')
		{
			int cnt=1;
			int j=1;
			while (1)
			{
				if (s[i-j]=='[')
				{
					cnt-=1;
				}
				if (s[i-j]==']')
				{
					cnt+=1;
				}
				if (cnt==0)
				{
					i=i-j;
					break;
				}
				j+=1;

			}


		}
		else
		{
			i+=1;
		}

	}

}
