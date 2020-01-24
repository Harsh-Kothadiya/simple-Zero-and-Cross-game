//zero and cross game (tic toc game)
#include<iostream>
using namespace std;
class game
{
   private : 
     int row,column,matrix[3][3],i,j,x_col,x_row,x_dia1,x_dia2,y_col,y_row,y_dia1,y_dia2;
   public  :
   	char choice;
   void p1();
   void p2(); 
   void intial_disp();
   void disp();
   int win_p1_col();
   int win_p1_row();
   int win_p1_dia1();
   int win_p1_dia2();
   
   int win_p2_col();
   int win_p2_row();
   int win_p2_dia1();
   int win_p2_dia2();
   
};
int main()
{   
    game obj;
    cout<<"\n\t\t WELCOME ZERO AND CROSS GAME";
    cout<<"\n----------------------------------------------------------\n";
	cout<<"\n\n\t 3*3 Matrix Index";
	cout<<"\n\n\t 00 \t 01 \t 02";
	cout<<"\n\n\t 10 \t 11 \t 12";
	cout<<"\n\n\t 20 \t 21 \t 22";
	cout<<"\n\n\t PLAYER-1 : 1 MEANS IN GAME PLAYER-1 POSITION";
	cout<<"\n\n\t PLAYER-2 : 0 MEANS IN GAME PLAYER-2 POSITION";
	cout<<"\n\n----------------------------------------------------------\n";
	obj.intial_disp();
	cout<<"\n\n 500 MEANS EMPTY PLACE";
	cout<<"\n---------------------------------------------------------------\n";
	cout<<"\n\n\t ENTER CAPTIAL Z  : FOR PLAYER-1 STARTINGING GAME,Z:Zero"; //Z :zero
	cout<<"\n\n\t ENTER CAPTIAL C  : FOR PLAYER-2 STARTINGING GAME,C:cross";//C : cross
	cout<<"\n\n\t ENTER YOUR CHOICE  Z OR C : ";
	
	cin>>obj.choice;
	switch(obj.choice)
	{
		case 'Z' :
			obj.p1();
			break;
		case 'C' :
			obj.p2();
			break;
		default :
			cout<<"\n\n\t  ENTER CAPTIAL Z OR CAPTIAL C";
			break;
	}
	return 0;
}
void game :: intial_disp()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			matrix[i][j]=500;
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void game :: disp()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int game :: win_p1_col()
{ 
    //start check condition for column
	if( (matrix[0][0]==1)&&(matrix[1][0]==1)&&(matrix[2][0]==1) )
	   return 100;
	else if( (matrix[0][1]==1)&&(matrix[1][1]==1)&&(matrix[2][1]==1) ) 
	 return 100;
	else if( (matrix[0][2]==1)&&(matrix[1][2]==1)&&(matrix[2][2]==1) )
	  return 100; 
	//end column condition
	else
	  return 200;

}
int game :: win_p1_row()
{
 	//start check condition for row
	 if( (matrix[0][0]==1)&&(matrix[0][1]==1)&&(matrix[0][2]==1) )
	  return 100;
	 else if( (matrix[1][0]==1)&&(matrix[1][1]==1)&&(matrix[1][2]==1) )
	  return 100;
	else if( (matrix[2][0]==1)&&(matrix[2][1]==1)&&(matrix[2][2]==1) )
	  return 100; 
	
	//end row condition
	else
	  return 200; 
}
int game :: win_p1_dia1()
{
	//start check condition for diagonal-1
	 if( (matrix[0][0]==1)&&(matrix[1][1]==1)&&(matrix[2][2]==1) )
	  return 100;
	  //end diagonal-1 condition
	 else
	  return 200; 
}
int game :: win_p1_dia2()
{
    //start check condition for diagonal-2
	 if( (matrix[2][0]==1)&&(matrix[1][1]==1)&&(matrix[0][2]==1) )
	  return 100;
	//end diagonal-2 condition
	
	else
	  return 200;
}

void game :: p1()
{
	while(1)
	{
		y_col=win_p2_col();
		if(y_col==100)
		  break;
		y_row=win_p2_row();
		if(y_row==100)
		  break;
		y_dia1=win_p2_dia1();
		if(y_dia1==100)
		  break;
		y_dia2=win_p2_dia2();
		if(y_dia2==100)
		  break;
		
		cout<<"\n\n--------PLAYER-1---------------------------------";
		cout<<"\n\n\t ENTER A ROW : ";
     	cin>>row;
    	cout<<"\n\t ENTER A COLUMN : ";
		cin>>column;
		if(matrix[row][column]==500)
		{
			matrix[row][column]=1;
			break;
		}
		else
		{
		   cout<<"\n THIS INDEX(PLACE or POSITION) NOT EMPTY ";
		}
	}
	if(y_col==100 || y_row==100 || y_dia1==100 || y_dia2==100 )
	{
		cout<<"\n\n\n------------------------------------\n";
		cout<<"\n PLAYER-2 WIN THIS GAME....";
	}
    else
	{
		disp();
		p2();
    }
	
}

void game :: p2()
{
	while(1)
	{
		x_col=win_p1_col();
		if(x_col==100)
		  break;
		x_row=win_p1_row();
		if(x_row==100)
		  break;
		x_dia1=win_p1_dia1();
		if(x_dia1==100)
		  break;
		x_dia2=win_p1_dia2();
		if(x_dia2==100)
		  break;
		
		cout<<"\n\n--------PLAYER-2---------------------------------";
		cout<<"\n\n\t ENTER A ROW : ";
     	cin>>row;
    	cout<<"\n\t ENTER A COLUMN : ";
		cin>>column;
		if(matrix[row][column]==500)
		{
			matrix[row][column]=0;
			break;
		}
		else
		{
		   cout<<"\n THIS INDEX(PLACE or POSITION) NOT EMPTY ";
		}
	}
	if(x_col==100 || x_row==100 || x_dia1==100 || x_dia2==100 )
	{
		cout<<"\n\n\n------------------------------------\n";
		cout<<"\n PLAYER-1 WIN THIS GAME....";
	}
    else
	{
		disp();
		p1();
    }
	
}


int game :: win_p2_col()
{ 
    //start check condition for column
	if( (matrix[0][0]==0)&&(matrix[1][0]==0)&&(matrix[2][0]==0) )
	   return 100;
	else if( (matrix[0][1]==0)&&(matrix[1][1]==0)&&(matrix[2][1]==0) ) 
	 return 100;
	else if( (matrix[0][2]==0)&&(matrix[1][2]==0)&&(matrix[2][2]==0) )
	  return 100; 
	//end column condition
	else
	  return 200;

}
int game :: win_p2_row()
{
 	//start check condition for row
	 if( (matrix[0][0]==0)&&(matrix[0][1]==0)&&(matrix[0][2]==0) )
	  return 100;
	 else if( (matrix[1][0]==0)&&(matrix[1][1]==0)&&(matrix[1][2]==0) )
	  return 100;
	else if( (matrix[2][0]==0)&&(matrix[2][1]==0)&&(matrix[2][2]==0) )
	  return 100; 
	
	//end row condition
	else
	  return 200; 
}
int game :: win_p2_dia1()
{
	//start check condition for diagonal-1
	 if( (matrix[0][0]==0)&&(matrix[1][1]==0)&&(matrix[2][2]==0) )
	  return 100;
	  //end diagonal-1 condition
	 else
	  return 200; 
}
int game :: win_p2_dia2()
{
    //start check condition for diagonal-2
	 if( (matrix[2][0]==0)&&(matrix[1][1]==0)&&(matrix[0][2]==0) )
	  return 100;
	//end diagonal-2 condition
	
	else
	  return 200;
}

