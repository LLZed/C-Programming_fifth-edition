//8.写一个函数insert,用来向一个动态链表插入结点，要求按照学号顺序插入

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)		    //定义LEN的值为结构体的长度

struct Student							    //定义一个结构体类型，有三个成员
{
    long num;							    //学号（长整型）
	float score;						    //成绩（浮点型）
	struct Student * next;				    //指向结构体类型数据的指针变量成员next（指针类型的成员，它指向结构体类型数据，就是它所在的结构体类型）
};  
int n;									    //全局变量n

//main函数调用这些函数
int main()
{
    //函数声明
    struct Student *creat(void);
    struct Student *insert(struct Student *head,struct Student *stud);

	struct Student *pt,*head;					                    //定义结构体指针变量；
    struct Student *stud;					                //定义一个结构体指针变量；
    
    long number;
	head=pt=creat();								                //调用函数，函数返回所创建的链表的第1个结点的地址
	printf("\nNow these records are:\n");
    while(pt!=NULL)							                //依次输出各结点的数据
	{
		printf("num:%ld\nscore:%5.1f\n",pt->num,pt->score);
		pt=pt->next;                                        //使结点指向下一个结点
	}
    printf("\n");
    pt=head;                                                //使pt重新指向头结点，因为在上面输出结点时pt指向已经改变
    printf("who is student you want to insert:\n");
    stud=(struct Student * )malloc(LEN);	                //开辟一个结构体类型的新单元
    scanf("%ld,%f",&stud->num,&stud->score);		        // 输入要插入的学生的学号和成绩
    pt = insert(pt,stud);
	printf("\nNow these records are:\n");
    while(pt != NULL)							            //依次输出各结点的数据
	{
		printf("num:%ld\nscore:%5.1f\n",pt->num,pt->score);
		pt=pt->next;
	}

    system("pause");
	return 0;
}

//creat函数创建动态链表
struct Student *creat(void)				    //定义函数，此函数返回一个指向链表头的指针
{
	struct Student * head;				    //指向结构体类型数据的指针变量head，它可以指向结构体变量也可以指向结构体数组中的元素
	struct Student * p1,*p2;			    //指向结构体类型数据的指针变量p1和p2
	n=0;
	p1=p2=(struct Student * )malloc(LEN);	//开辟一个结构体类型的新单元,并使p1和p2指向新单元
	printf("请输入学生学号和成绩（逗号隔开）：\n(若输入0,0表示结束)\n");
	scanf("%ld,%f",&p1->num,&p1->score);	//输入第1个学生的学号和成绩
	head=NULL;								//此时head的值为空，不指向任何；
	while(p1->num!=0)						//当输入的学号不为零时,则输入的是第1个结点的数据
	{
		n=n+1;								//n为结点1的标记
		if(n==1)							//当n为1时表示此时是结点1，要把结点的地址给到head，使head指向结点1
			head=p1;						//把p1的值赋给head，即使head指向新开辟的结点，p1所指向的新开辟的结点就成为链表中第1个结点
		else 
            p2->next=p1;					//将p1的值赋给p2->next
		p2=p1;								//在连接好两个结点后，使p2也指向新结点，为下次连接做准备
		p1=(struct Student *)malloc(LEN);	//开辟动态存储区，把起始地址赋给p1
		scanf("%ld,%f",&p1->num,&p1->score);	// 输入其他学生的学号和成绩
	}
	p2->next=NULL;							//开辟完后使p2不指向任何结点
	return head;							//返回链表头地址；
}


//insert函数插入新结点,可以按学号顺序插入
struct Student *insert(struct Student *head,struct Student *stud)
{
    struct Student *p0,*p1,*p2;			     //指向结构体类型数据的指针变量p0,p1和p2
    p1=head;                                    //使p1指向第1个结点
    p0=stud;                                 //指向要插入的结点
    //原来的表是空表
    if(head==NULL)                             
    {
        head=p0;                               //将插入的结点作为第一个结点
        p0->next=NULL;
    }
    else
    {
        while ((p0->num > p1->num)&&(p1->next!=NULL))//当p0的num成员大于p1的num而且p不是空表
        {
            p2=p1;                          //使p2指向刚才p1指向的结点
            p1=p1->next;					//p1后移一个结点，指向下一个结点
        }
        if(p0->num <= p1->num)					
        {
            if(p1==head)						    //如果p1此时指向的是首结点										
                head=p0;    					    //插到首结点之前
            else 
                p2->next=p0;					//否则插到p2指向的结点之后
            p0->next=p1;                        //插好后再链接到p1
        }
        else
        {
            p1->next=p0;                       //插到最后一个结点之后
            p0->next=NULL;
        }
    }
    n=n+1;                                     //结点数+1
    return head;			
}
