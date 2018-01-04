#include <fstream>
#include<iostream>
#include <math.h>

using namespace std;

int obOdle(int X,int Y,int metaX,int metaY)
{
	int wynik;
	wynik=sqrt((metaX-X)*(metaX-X))+sqrt((metaY-Y)*(metaY-Y));
	return wynik;
}

int main()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ZMIENNNE
	int startX=2;
	int startY=1;
	int metaX=5;
	int metaY=6;
	int w=1;
	int propX,X;
	int propY,Y;
	int min;
	int propOdle;
	int l;
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//#######################TWORZENIE PAY I WYPISANIE JEJ
	int mapa[10][10] ={ { 0,0,0,0,0,0,0,0,0,0 },
							  { 0,0,0,5,0,0,0,0,0,0 },
							  { 0,0,0,5,0,0,0,0,0,0 },
							  { 0,0,0,5,5,0,0,0,0,0 },
							  { 0,0,0,0,5,0,0,0,0,0 },
							  { 0,0,0,0,5,0,0,0,0,0 },
							  { 0,0,5,5,5,0,0,0,0,0 },
							  { 0,0,0,0,0,0,0,0,0,0 },
							  { 0,0,0,0,0,0,0,0,0,0 },
							  { 0,0,0,0,0,0,0,0,0,0 },
							
							
							
							 };	
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << mapa[i][j] << " ";
		}

		cout << endl;
	}
	//#####################################
	

	cout << endl;
	cout << endl;
	cout << endl;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while(w!=0)
	{
		propX=X;
		propY=Y;
		min=999;
		l=0;
		
		///////////////////////////////////////////////////////////////////////////////prawo
		if(X+1<0 || X+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y]==5 || mapa[X+1][Y]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X+1,Y,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X+1;
			l=l+1;	
		}
		/////////////////////////////////////////////////////////////////////////////////dó³
		
		if(Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X][Y+1]==5 || mapa[X][Y+1]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X,Y+1,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X;
			propY=Y+1;
			l=l+1;		
		}
		///////////////////////////////////////////////////////////////////////////////////////////////prawo dó³
		
		
		if(X+1<0 || X+1>9 || Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y+1]==5 || mapa[X+1][Y+1]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X+1,Y+1,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X+1;
			propY=Y+1;
			l=l+1;	
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////lewo dó³
		
		if(X-1<0 || X-1>9 || Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y+1]==5 || mapa[X-1][Y+1]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X-1,Y+1,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X-1;
			propY=Y+1;
			l=l+1;		
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////lewo
		
		if(X-1<0 || X-1>9 || Y<0 || Y>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y]==5 || mapa[X-1][Y]==3 )
		{
			propOdle=9999999;
			
		}
		else
		{
			propOdle=obOdle(X-1,Y,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X-1;
			propY=Y;
			l=l+1;		
		}
		
	
	//////////////////////////////////////////////////////////////lewo góra
	
		if(X-1<0 || X-1>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y-1]==5 || mapa[X-1][Y-1]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X-1,Y-1,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X-1;
			propY=Y-1;	
			l=l+1;	
		}
//////////////////////////////////////////////////////////////////////////////góra
		if(X<0 || X>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X][Y-1]==5 || mapa[X][Y-1]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X,Y-1,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X;
			propY=Y-1;
			l=l+1;		
		}
		/////////////////////////////////////////////////////////////////////////////////////////////GÓRA PRAWO
		if(X+1<0 || X+1>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y-1]==5 || mapa[X+1][Y-1]==3 )
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X+1,Y-1,metaX,metaY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X+1;
			propY=Y-1;
			l=l+1;	
		}
		
		//////////////////////////////////////////////////////////////////////////////////PROP RUCHY WYKONANE
		//*************************************************************************************************************************************************
		/////////////////////////////////////////////////////////////////////////////////GDY NIC NIEZMNIEJSZA ODLEGLOSCI
		
		if(l==0)
		{
					///////////////////////////////////////////////////////////////////////////////prawo
		if(X+1<0 || X+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y]!=5 && mapa[X+1][Y]==3 )
		{
			propX=X+1;
			l=l+1;	
		}
		/////////////////////////////////////////////////////////////////////////////////dó³
		
		if(Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X][Y+1]!=5 && mapa[X][Y+1]!=3 )
		{
			propX=X;
			propY=Y+1;
			l=l+1;		
		}
		///////////////////////////////////////////////////////////////////////////////////////////////prawo dó³
		
		
		if(X+1<0 || X+1>9 || Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y+1]!=5 && mapa[X+1][Y+1]!=3 )
		{
			propX=X+1;
			propY=Y+1;
			l=l+1;	
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////lewo dó³
		
		if(X-1<0 || X-1>9 || Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y+1]!=5 && mapa[X-1][Y+1]!=3 )
		{
			propX=X-1;
			propY=Y+1;
			l=l+1;		
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////lewo
		
		if(X-1<0 || X-1>9 || Y<0 || Y>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y]!=5 && mapa[X-1][Y]!=3 )
		{
			propX=X-1;
			propY=Y;
			l=l+1;		
		}
		
	
	//////////////////////////////////////////////////////////////lewo góra
	
		if(X-1<0 || X-1>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y-1]!=5 && mapa[X-1][Y-1]!=3 )
		{
			propX=X-1;
			propY=Y-1;	
			l=l+1;	
		}
//////////////////////////////////////////////////////////////////////////////góra
		if(X<0 || X>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X][Y-1]!=5 && mapa[X][Y-1]!=3 )
		{

			propX=X;
			propY=Y-1;
			l=l+1;		
		}
		/////////////////////////////////////////////////////////////////////////////////////////////GÓRA PRAWO
		if(X+1<0 || X+1>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y-1]!=5 && mapa[X+1][Y-1]!=3 )
		{

			propX=X+1;
			propY=Y-1;
			l=l+1;	
		}
			
			
		}
		
		
		
		X=propX;
		Y=propY;
		mapa[X][Y]=3;
		w=min;
		
		if(w==0)
		{
			mapa[X][Y]=8;	
		}
		
	}
	
	w=10;
	min=999;
	propOdle=obOdle(X,Y,startX,startY);
	X=metaX;
	Y=metaY;
	
	///////////////////////////////////////////////////////////////////////////////////POWRÓT PO POPRZENIEJ TRASIE ALE ZOPTYMALIZOWANY

	while(w>1)
	{
		propX=X;
		propY=Y;
		min=999;
		
		///////////////////////////////////////////////////////////////////////////////prawo
		if(X+1<0 || X+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X+1,Y,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X+1;	
		}
		/////////////////////////////////////////////////////////////////////////////////dó³
		
		if(Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X][Y+1]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X,Y+1,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X;
			propY=Y+1;	
		}
		///////////////////////////////////////////////////////////////////////////////////////////////prawo dó³
		
		
		if(X+1<0 || X+1>9 || Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y+1]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X+1,Y+1,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X+1;
			propY=Y+1;	
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////lewo dó³
		
		if(X-1<0 || X-1>9 || Y+1<0 || Y+1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y+1]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X-1,Y+1,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X-1;
			propY=Y+1;	
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////lewo
		
		if(X-1<0 || X-1>9 || Y<0 || Y>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y]!=3)
		{
			propOdle=9999999;
			
		}
		else
		{
			propOdle=obOdle(X-1,Y,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X-1;
			propY=Y;	
		}
		
	
	//////////////////////////////////////////////////////////////lewo góra
	
		if(X-1<0 || X-1>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X-1][Y-1]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X-1,Y-1,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X-1;
			propY=Y-1;	
		}
//////////////////////////////////////////////////////////////////////////////góra
		if(X<0 || X>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X][Y-1]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X,Y-1,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X;
			propY=Y-1;	
		}
		/////////////////////////////////////////////////////////////////////////////////////////////GÓRA PRAWO
		if(X+1<0 || X+1>9 || Y-1<0 || Y-1>9)
		{
			propOdle=9999999;
		}
		else if(mapa[X+1][Y-1]!=3)
		{
			propOdle=9999999;
			
		}
		else{
			propOdle=obOdle(X+1,Y-1,startX,startY);
		}
		if(propOdle<min)
		{
			min=propOdle;
			propX=X+1;
			propY=Y-1;	
		}
		
		//////////////////////////////////////////////////////////////////////////////////PROP RUCHY WYKONANE
		
		
		X=propX;
		Y=propY;
		mapa[X][Y]=8;
		w=min;
		
	}	
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << mapa[i][j] << " ";
		}

		cout << endl;
	}
	
	return 0;
	
}
