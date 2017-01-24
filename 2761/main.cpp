#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <set>  
#include<map>  
#include<ctime>  
using namespace std;  
const int N=100009;  
const int M=50009;  
int n,m,a[N],ans[M];  
int hash[N];  
map<int,int> Map;  
struct point{  
    int a,num,h;  
}p[N];  
struct Inv{  
    int a,b,k,num;  
}inv[M];  
bool cmp(Inv x,Inv y){  
    return x.b<y.b;  
}  
bool cmp2(point x,point y){  
    return x.a<y.a;  
}  
bool cmp3(point x,point y){  
    return x.num<y.num;  
}  
int ar[N]; //��״����     
inline int lowb(int t){
	return t&(-t) ;
}    
void add(int i,int v){ //����״�����ֵ     
	//for(;i<N;ar[i]+=v,i+=lowb(i));      
	while(i<N){
		ar[i] += v;
		i += lowb(i);
	}
}      
int sum(int k){ //������״�����ѯ��k��Ԫ��     
	int  pos=0,cnt=0;      
	for(int i=20;i>=0;i--){  // 20: ��֤�㹻�������ҵ���ȷ��ֵ
	    pos+=1<<i;  
	    if(pos>=N||cnt+ar[pos]>=k){
	    	pos-=1<<i;  //��ͷ�ˣ������ƶ�
	    }else{
	    	cnt+=ar[pos]; //�������������ƶ�
	    }  
	}     
	return pos+1;   
} 

int main(){  
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);  
	memset(ar,0,sizeof(ar));  
	for(int i=1;i<=n;i++)  
	{  
	scanf("%d",&p[i].a);  
	p[i].num=i;  
	}  
	sort(p+1,p+n+1,cmp2);  //sort by p.a
	for(int i=1;i<=n;i++)  
	{  
	    p[i].h=i;  
	    hash[i]=p[i].a;  //��ɢ��
	}  
	sort(p+1,p+n+1,cmp3);  //sort by p.num, "sort back"
	for(int i=0;i<m;i++)  
	{  
	    scanf("%d%d%d",&inv[i].a,&inv[i].b,&inv[i].k);  
	    inv[i].num=i;  
	}  
	sort(inv,inv+m,cmp);  //sort by inv.b
	int s=inv[0].a,e=inv[0].a;  
	for(int i=0;i<m;i++){  
	    while(inv[i].a>s){	      
	        add(p[s].h,-1);  //����p[s].h��ص���״����ֵ
	        s++;  
	    }  
	    while(e<=inv[i].b){    
	        add(p[e].h,1);  //����p[e].h��ص���״����ֵ
	        e++;  
	    }  
	    ans[inv[i].num]=hash[sum(inv[i].k)];  
	}  
	for(int i=0;i<m;i++)  
	printf("%d\n",ans[i]);  
     
}