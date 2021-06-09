#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int getlen(int a)
{
	int n=a/3;
	if(a%3>0)
		n++;
	return n;
}

int getcombi(long long int n,int count)
{
	long long int jj=1;
	int three;
	for(int i=0;i<((count-1)*3);i++)
		jj=jj*10;
	three=n/jj;
	return three;
}

string getst(int a)
{
	string k=to_string(a),str;
	int x,y,z;
	x=a/100;
	y=a%100/10;
	z=a%100%10;
	switch(x)
	{
		case 1:str.append("ONE HUNDRED ");
		       break;
		case 2:str.append("TWO HUNDRED ");
		       break;
		case 3:str.append("THREE HUNDRED ");
		       break;
		case 4:str.append("FOUR HUNDRED ");
		       break;
		case 5:str.append("FIVE HUNDRED ");
		       break;
		case 6:str.append("SIX HUNDRED ");
		       break;
		case 7:str.append("SEVEN HUNDRED ");
		       break;
		case 8:str.append("EIGHT HUNDRED ");
		       break;
		case 9:str.append("NINE HUNDRED ");
		       break;
	}
	switch(y)
	{
		case 1:switch(z)
		       {
			       case 0:str.append("TEN ");
				      break;
			       case 1:str.append("ELEVEN ");
				      break;
			       case 2:str.append("TWELVE ");
				      break;
			       case 3:str.append("THIRTEEN ");
				      break;
			       case 4:str.append("FOURTEEN ");
				      break;
			       case 5:str.append("FIFTEEN ");
				      break;
			       case 6:str.append("SIXTEEN ");
				      break;
			       case 7:str.append("SEVENTEEN ");
				      break;
			       case 8:str.append("EIGHTEEN ");
				      break;
			       case 9:str.append("NINETEEN ");
				      break;
		       }
		       break;
		case 2:str.append("TWENTY ");
		       break;
		case 3:str.append("THIRTY ");
		       break;
		case 4:str.append("FORTY ");
		       break;
		case 5:str.append("FIFTY ");
		       break;
		case 6:str.append("SIXTY ");
		       break;
		case 7:str.append("SEVENTY ");
		       break;
		case 8:str.append("EIGHTY ");
		       break;
		case 9:str.append("NINETY ");
		       break;
	}

	switch(z)
	{
case 1:if(y!=1){str.append("ONE ");}
	break;
case 2:if(y!=1){str.append("TWO ");}
        break;
case 3:if(y!=1){str.append("THREE ");}
        break;
case 4:if(y!=1){str.append("FOUR ");}
        break;
case 5:if(y!=1){str.append("FIVE ");}
        break;
case 6:if(y!=1){str.append("SIX ");}
        break;
case 7:if(y!=1){str.append("SEVEN ");}
        break;
case 8:if(y!=1){str.append("EIGHT ");}
        break;
case 9:if(y!=1){str.append("NINE ");}
        break;
	}
//	cout<<"\nString"<<str;
	return str;
}
string suff(int cnt)
{
	switch(cnt)
	{
		case 1:return ".";
		       break;
case 2:return "THOUSAND ";
      break;
case 3:return "MILLION ";
      break;
case 4:return "BILLION ";
      break;
case 5:return "TRILLION ";
      break;
case 6:return "QUADRILLIAN ";
       break;
case 7:return "QUINTILLION ";
       break;
case 8:return "SEXTILLION ";
       break;
case 9:return "SEPTILLION ";
       break;
case 10:return "OCTILLION ";
       break;
case 11:return "NONIILLION ";
       break;

	}
	return "Value out of bound.";
}
long long int remove(long long int n,int three,int count)
{
	long long int jj=1;
        for(int i=0;i<((count-1)*3);i++)
        jj=jj*10;
        three=n/jj;
	jj=three*jj;
	n=n-jj;
        return n;
}
void getword(long long int n,int length,int count)
{
	long long int temp=n;
	int three;
	string str,tmpstr;
			while(temp>0)
	{
		{
			three=getcombi(temp,count);
			tmpstr=getst(three);
			str.append(tmpstr);
			str.append(suff(count));
			temp=remove(temp,three,count);
			count--;
		}
	}
			cout<<"\nEntered Value= "<<n<<endl<<"\t"<<str;
}
int main()
{
long long int n,temp;	
	int length,count;
	cout<<"\nEnter number you want:";
	cin>>n;
	temp=n;
	cout<<"\nEntered number is "<<n<<endl;
	for(length=1;temp/10!=0;++length)
		temp/=10;
	count=getlen(length);
	getword(n,length,count);
	return 0;
}

/*Output:
Entered number is 12435546232323

Entered Value= 12435546232323
        TWELVE TRILLION FOUR HUNDRED THIRTY FIVE BILLION FIVE HUNDRED FORTY SIX MILLION TWO HUNDRED THIRTY TWO THOUSAND THREE HUNDRED TWENTY THREE .
*/