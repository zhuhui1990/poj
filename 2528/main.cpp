#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
struct CPost
{
   int L,R;    
};
CPost posters[10100];//用来存放海报的两个端点的结构体数组；
int x[20200];//海报的端点瓷砖编号
int hash[10000010];//hash[i]表示瓷砖i所处的离散化后的区间编号
struct CNode
{
   int L,R;
   bool bCovered;//区间[L,R]是否已经被完全覆盖
   CNode *pLeft,*pRight; 
};
CNode Tree[1000000];//存放海报区间的线段树
int nNodeCount=0;//结构体指针下标 
int Mid(CNode *pRoot)
{
   return (pRoot->L+pRoot->R)/2;
} 
void BuildTree(CNode *pRoot,int L,int R)
{
   pRoot->L=L;
   pRoot->R=R;
   pRoot->bCovered=false;
   if(L==R)
     return;
   nNodeCount++;
   pRoot->pLeft=Tree+nNodeCount;
   nNodeCount++;
   pRoot->pRight=Tree+nNodeCount;
   BuildTree(pRoot->pLeft,L,(L+R)/2);
   BuildTree(pRoot->pRight,(L+R)/2+1,R); 
}
bool Post(CNode *pRoot,int L,int R)
{/*插入一张正好覆盖区间[L,R]的海报，返回ture说明区间[L,R]，是部分
或全部可见的 */
   if(pRoot->bCovered) return false;//如果该部分已经被完全覆盖，返回false 
   /*如果该部分没有被完全覆盖，则完全覆盖此部分 ，并返回ture说明 插入的海报是部分
或全部可见的*/
   if(pRoot->L==L&&pRoot->R==R){
        pRoot->bCovered=true;
        return true;                         
   }
   //没有找到海报区间要继续寻找 
   bool bResult;
   if(R<=Mid(pRoot))
        bResult=Post(pRoot->pLeft,L,R);
   else if(L>=Mid(pRoot)+1)
        bResult=Post(pRoot->pRight,L,R);
   else{
        bool b1=Post(pRoot->pLeft,L,Mid(pRoot));
        bool b2=Post(pRoot->pRight,Mid(pRoot)+1,R);
        bResult=b1||b2; //只要有true的，最终都是true 
   }
   //要更新根节点的覆盖情况
   if(pRoot->pLeft->bCovered&&pRoot->pRight->bCovered) 
         pRoot->bCovered=true;
   return bResult;
   
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    int nCaseNo=0;
    while(t--)
    {
       nCaseNo++;
       scanf("%d",&n);
       int nCount=0;
       for(i=0;i<n;i++)
       {
          scanf("%d%d",&posters[i].L,&posters[i].R);
          x[nCount++]=posters[i].L;
          x[nCount++]=posters[i].R;
       }
       sort(x,x+nCount);
       nCount=unique(x,x+nCount)-x;//去掉重复元素
       //下面离散化
       int nIntervalNo=0;
       for(i=0;i<nCount;i++)
       {
          hash[x[i]]=nIntervalNo;
          if(i<nCount-1)
          {
             if(x[i+1]-x[i]==1)
                nIntervalNo++;
             else
                nIntervalNo+=2;
          }                   
       } 
       
       BuildTree(Tree,0,nIntervalNo);
       int nSum=0;
       for(i=n-1;i>=0;i--)
       {
          if(Post(Tree,hash[posters[i].L],hash[posters[i].R]))
          nSum++;
       } 
       printf("%d\n",nSum);
    }
    return 0;
}