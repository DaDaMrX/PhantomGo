#define BLACK 0
#define WHITE 1
#define EMPTY 2

typedef struct _Point{ //点结构
	int x,y;
}Point;

typedef struct _Step{ //步结构
	Point point;
	int value;
}Step;

int Board[10][10];//棋盘结构

int PhantomGo()
{
	Step step;//临时步结构
	char message[256];//通信消息缓冲
    int computerSide;//己方执棋颜色
    int start=0;//对局开始标记

	//此处放置初始化代码
    //...
    
    //程序主循环
	while(1)
	{
		fflush(stdout);
        
		//获取平台消息
		scanf("%s", message);
        
        //分析命令
		if (strcmp(message, "accept") == 0)                     //己方提交着法被接受
		{
			fflush(stdin);
            
			//处理己方行棋
            Board[step.point.x][step.point.y]=computerSide;
            //...
		}
		else if (strcmp(message, "refuse") == 0)                //己方提交着法被拒绝
		{
			fflush(stdin);
                
			//生成着法，并保存在step结构中
            //...

            //检查着法
            if (...)//输出着法
                printf("move %c%c\n",step.point.x+'A',step.point.y+'A');   
            else//或Pass
				printf("move pass\n");
		}
		else if (strcmp(message, "move") == 0) //不知道对方是落子了还是pass了！！！
		{
			scanf("%s", message);
			if (strcmp(message, "go") == 0)
			{
				fflush(stdin);
                
go:				//生成着法，并保存在step结构中
                //...
                
                //检查着法
                if (...)//输出着法
                    printf("move %c%c\n",step.point.x+'A',step.point.y+'A');   
				else//或Pass
					printf("move pass\n");
			}
			else if (strcmp(message, "pass") == 0)//对方pass
			{
				fflush(stdin);
                
				//...
				goto go;
			}
		}
		else if (strcmp(message, "take") == 0)//己方提子
		{
			int num;
            
            fflush(stdin);
            
			scanf("%d", &num);//读取提子数目
			scanf("%s", message);//读取提子列表
            
			for (int k = 0; k < num; k++)
			{
				x = message[2 * k] - 'A';
				y = message[2 * k + 1] - 'A';
				Board[x][y] = EMPTY;
                //...
			}
            //...
		}
		else if (strcmp(message, "taked") == 0)//对方提子
		{
            int num;
            
			scanf("%d", &num);//读取提子数目
			scanf("%s", message);//读取提子列表
            
			for (int k = 0; k < num; k++)
			{
				x = message[2 * k] - 'A';
				y = message[2 * k + 1] - 'A';
				Board[x][y] = EMPTY;
                //...
			}
            //...
		}
		else if (strcmp(message,"new") == 0)//新建棋局
		{
            int i,j;
            
			scanf("%s",message);//获取己方执棋颜色
            fflush(stdin);
            
			if(strcmp(message,"black")==0)//执黑
				computerSide=BLACK;
			else//执白
				computerSide=WHITE;
            
            //初始化棋局
            for(i=0;i<10;++i)
                for(j=0;j<10;++j)
                    Board[i][j]=EMPTY;
            //...
            
            start=1;
            
            if(computerSide==BLACK)
            {
                //生成第一手着法，并保存在step结构中
                //...
                
                //处理己方行棋
                Board[step.point.x][step.point.y]=computerSide;
                //...
                
                //输出着法
                printf("move %c%c\n",step.point.x+'A',step.point.y+'A');
            }
		}
        else if (strcmp(message, "error") == 0)//着法超出棋盘范围
        {
            fflush(stdin);
            
            //...
        }
		else if (strcmp(message, "name?") == 0)//询问引擎名
		{
            fflush(stdin);
            
            //输出引擎名
			printf("name xxxx\n");
		}
		else if (strcmp(message, "end") == 0)//对局结束
		{
            fflush(stdin);
            
			start = 0;
            //...
		}
		else if (strcmp(message, "quit") == 0)//退出引擎
		{
            fflush(stdin);
            
            //...
			printf("Quit!\n");
			break;
		}
	}
	return 0;
}
