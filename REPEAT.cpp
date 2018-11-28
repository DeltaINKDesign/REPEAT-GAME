#include <iostream>  //standardowa biblioteka wejscia wyjscia
#include <ctime>
#include <conio.h>
#include <fstream>
#include <windows.h> //beep i sleep 
#include <cstdlib>
#include <stdlib.h>
#include <vector>
using namespace std;

int score;
string nick;

vector <int> losowania;
   //tablica ktora bedzie przechowywac losowania
void wyswietlaniewynikow()
{
	string linia;  //linia to tekst, ktory znajdzie. Razem z endl
	fstream wyniki; //wyniki
	wyniki.open("Wyniki.txt", ios::in); //otwieranie z prawami odczytu jesli nie ma
	if(wyniki.good()==true) //jesli wyniki sa to 
	{
		while(!wyniki.eof()) //robi tak dlugo dopoki nie znajdzie pustki
		{
		
		getline(wyniki,linia); //wrzuca do linii 
		cout<<linia<<endl;
	}
	}
	wyniki.close(); //zamyka plik
}

void wynik()  //tworzy wynik
{
	fstream wyniki;  //tworzy wyniki
	cout<<"ZAPISYWANIE, PROSZE CZEKAC ..."<<endl;
	Sleep(400);
	if(wyniki.good()==true)
	{
		wyniki.open("Wyniki.txt", ios::app);  //dopisywanie do Wynikow
		wyniki<<endl<<nick<<" zdobyl "<<score;
		wyniki.close();
	}else
	{
		wyniki.open("Wyniki.txt", ios::out);  //stworzenie nowego lub podmiana
		wyniki<<endl<<nick<<" zdobyl "<<score;
		wyniki.close();
	}
	
}
void kolorowane()
{
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"=========================================================\t\t"<<endl;	
	cout<<"\n\n\n\n\n\n";
	Sleep(200);
}
void odczytywanie()  //funkcja na odczyt losowan
{
	for(int i=0;i<=losowania.size()-1;i++)
	{
	HANDLE hOut;                                            //KOLORY CZCIONEK
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	system("cls");
	int kolor;
	int pierwszaa=3;
	int pierwsza1=3;
	int pierwsza2=4;
	int warunek=0;
	kolor=losowania[i];
	

	do{
		if(warunek==1) pierwsza2=0;
	if(pierwszaa==0) 
	{
	SetConsoleTextAttribute( hOut, 07);
	kolorowane();
	}
	
	
	if(kolor==0)	{
	SetConsoleTextAttribute( hOut, 04);
	kolorowane();
	pierwsza1=0;
	pierwsza2=0;
	}
	if(pierwsza1==0)
		{
	SetConsoleTextAttribute( hOut, 07);
	kolorowane();
	}
				if(kolor==1)	{
	
	if(warunek==1) {
		
	SetConsoleTextAttribute( hOut, 02);
	kolorowane();
	}
	pierwszaa=0;
	
 	warunek++;
	}									
	
	if(pierwsza2==0) 
		{
	SetConsoleTextAttribute( hOut, 07);
	kolorowane();
	}
	if(kolor==2)
	{
		if(warunek==1) 
		{
		
			SetConsoleTextAttribute( hOut, 01);
	kolorowane();
	}
	pierwszaa=0;
	warunek++;
	}
	
	}while(warunek==1);
}
}
void pustekwadraty()
{
	HANDLE hOut;                                            //KOLORY CZCIONEK
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	for(int d=0; d<=2; d++)
	{
		SetConsoleTextAttribute( hOut, 07);
		kolorowane();
	}
	cout<<"SCORE: "<<score;
}

void maingra()
{
	HANDLE hOut;                                            //KOLORY CZCIONEK
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	system("cls");
	int kolor ;
	int pierwszaa=3;
	int pierwsza1=3;
	int pierwsza2=4;
	int warunek=0;
	srand( time ( NULL));
	kolor=rand()%3;
	losowania.push_back(kolor);
	//cout<<kolor;

	do{
		if(warunek==1) pierwsza2=0;
	if(pierwszaa==0) 
	{
	SetConsoleTextAttribute( hOut, 07);
	kolorowane();
	Sleep(200);
	}
	
	
	if(kolor==0)	{
	SetConsoleTextAttribute( hOut, 04);
	kolorowane();
	Sleep(200);
	pierwsza1=0;
	pierwsza2=0;
	}
	if(pierwsza1==0)
		{
	SetConsoleTextAttribute( hOut, 07);
	kolorowane();
	}
				if(kolor==1)	{
	
	if(warunek==1) {
		
	SetConsoleTextAttribute( hOut, 02);
	kolorowane();
	}
	pierwszaa=0;
	
 	warunek++;
	}									
	
	if(pierwsza2==0) 
		{
	SetConsoleTextAttribute( hOut, 07);
	kolorowane();
	}
	if(kolor==2)
	{
		if(warunek==1) 
		{
		
			SetConsoleTextAttribute( hOut, 01);
			
	
	kolorowane();
	}
		pierwszaa=0;
		warunek++;
	}
	
	}while(warunek==1);
}

void lepszamaingra()
{
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);	
	CONSOLE_FONT_INFOEX cfi;	
	
	int zycie=1; //uzytkownik ma jedno zycie

	do
	{			
		int glosgracza=0;
		pustekwadraty();
		cfi.dwFontSize.X = 12;			//nowa wartosc
		cfi.dwFontSize.Y = 16;			//nowa wartosc
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); 
		cout<<" LOSOWANIE";
			Sleep(100);
			cout<<".";
			Sleep(100);
			cout<<".";
			Sleep(100);
			cout<<".";
			Sleep(1000);
		system("cls");
		if(losowania.size()>0)
		{
			odczytywanie();
			system("cls");
		}
		maingra();
		system("cls");
		Sleep(400);
		pustekwadraty();
		cfi.dwFontSize.X = 12;			//nowa wartosc
		cfi.dwFontSize.Y = 16;			//nowa wartosc
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); 
		cout<<" ZGADNIJ ";
		Sleep(100);
			cout<<".";
			Sleep(100);
			cout<<".";
			Sleep(100);
			cout<<".";
		for(int w=0;w<=losowania.size()-1;w++)
		{
			char odpowiedz=getch();
			switch(odpowiedz)
			{
				case 'i': //kolor czerwony
					{
					glosgracza=0;  //po nacisniecu i gracz odpowiedzial ze czerwony
					if(glosgracza==losowania[w])
					{
						 score++;	 
						 cout<<"ZDOBYLES PUNKT ! "<<score<<endl; 
						 system("cls");
						 break;
					}
					else
					{
						zycie--;
						break;
						
					}
					break;
					}
				case 'j': //kolor zielony
					{
						glosgracza=1;  //po nacisniecu j gracz odpowiedzial ze zielony
						if(glosgracza==losowania[w])
							{
								 score++;
								 cout<<"ZDOBYLES PUNKT ! "<<score<<endl; 
								 system("cls");
								 break;
							}
						else
						{
							zycie--;  
						}
						break;
					}
				case 'n': //kolor niebieski
					{
						glosgracza=2;  //po nacisniecu n gracz odpowiedzial ze niebieski
						if(glosgracza==losowania[w])   //sprawdzanie odpowiedzi z wylosowanym kolorem 
						{
					 		score++;    //dodawanie kolejnego punktu graczowi
							cout<<"ZDOBYLES PUNKT ! "<<score<<endl; 
							system("cls");
							break;
						}
						else
						{
							zycie--;
						}
						break;
					}
				default :
					{
						zycie--;
						system("cls");
						cout<<"Uzyskane punkty: "<<score<<endl;
						cout<<"POPELNILES BLAD, KONIEC GRY"<<endl;
					}
			}
		}	
		}while(zycie==1);
		system("cls");
	cout<<"POPELNILES BLAD, KONIEC GRY"<<endl;
	cout<<endl;
	cout<<"Uzyskane punkty: "<<score<<endl;	
	cout<<endl;
	cout<<"Nacisnij klawisz, aby wrocic do menu"<<endl;	
	cout<<endl;
	
	
	
}


int main()
{   
	int wyborwmenu;
	int zapis;
	int muzyka=0;
//WSZYSTKO CO DOTYCZY CZCIONKI I OKNA
	
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);	
	CONSOLE_FONT_INFOEX cfi;							//struktura w ktorej zawieraja sie informacje o czcionce, struktura cfi 
    cfi.cbSize = sizeof cfi;											
    cfi.dwFontSize.X;									//rozmiar x czcionki
    cfi.dwFontSize.Y;									//rozmiar y czcionki
    cfi.FontFamily = FF_DONTCARE;						
    cfi.FontWeight;										//kursywa
    GetCurrentConsoleFontEx(outcon, false, &cfi);		//wczytywanie aktualnych informacji o konsoli
	cfi.dwFontSize.X = 6;								//edytujemy rozmiar
	cfi.dwFontSize.Y = 8;							
	cfi.FontWeight = 100;								
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  //zatwierdzenie
    ShowWindow( GetConsoleWindow(), SW_MAXIMIZE);  //maksymalizacja okna
	 //ustawia parametry do tych podanych wyzej
	
	setlocale(LC_ALL,"");
	
	HANDLE hOut;                                            //KOLORY CZCIONEK
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );

	SetConsoleTextAttribute( hOut, 01);
	cout<<endl;
	cout<<endl;
	cout<<"      RRRRRRRRRRRRRRR"<<"            "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPPPPPPPPPPPPPPPP"<<"         "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"    AAAAAAAAAAAAAAAAAAA     "<<"  "<<"TTTTTTTTTTTTTTTTTTTTTTTTTTTT"<<endl;
	cout<<"   RRRRRRRRRRRRRRRRRRRRR"<<"         "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPPPPPPPPPPPPPPPPPP"<<"       "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"  AAAAAAAAAAAAAAAAAAAAAAAA  "<<"  "<<"TTTTTTTTTTTTTTTTTTTTTTTTTTTT"<<endl;
	cout<<" RRRRRRRRRRRRRRRRRRRRRRRRR"<<"       "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPPPPPPPPPPPPPPPPPPPP"<<"     "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"  "<<"TTTTTTTTTTTTTTTTTTTTTTTTTTTT"<<endl;
	cout<<"RRRRRRRRRRRRRRRRRRRRRRRRRRRR"<<"     "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPPPPPPPPPPPPPPPPPPPPPP"<<"   "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"  "<<"TTTTTTTTTTTTTTTTTTTTTTTTTTTT"<<endl;
	cout<<"RRRRRRRR            RRRRRRRR"<<"     "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP            PPPPPPPPP"<<"  "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR            RRRRRRRR"<<"     "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP            PPPPPPPPP"<<"  "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR            RRRRRRRRR"<<"    "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP            PPPPPPPPP"<<"  "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR            RRRRRRRRR"<<"    "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP            PPPPPPPPP"<<"  "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR            RRRRRRRR"<<"     "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP            PPPPPPP"<<"    "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR          RRRRRRRR"<<"       "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"PPPPPPPP            PPPPPP"<<"     "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRRRRRRRRRRRRRRRRRRR"<<"        "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"PPPPPPPPPPPPPPPPPPPPPPPP"<<"       "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRRRRRRRRRRRRRRRRRRRRR"<<"      "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"PPPPPPPPPPPPPPPPPPPPPPP"<<"        "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR           RRRRRRRRRR"<<"    "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"PPPPPPPPPPPPPPPPPPPPPP"<<"         "<<"EEEEEEEEEEEEEEEEEEEEEE"<<"        "<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR             RRRRRRRRR"<<"   "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP"<<"                       "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR              RRRRRRRR"<<"   "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP"<<"                       "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR              RRRRRRRR"<<"   "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP"<<"                       "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR               RRRRRRR"<<"   "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP"<<"                       "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR               RRRRRRR"<<"   "<<"EEEEEEEE"<<"                      "<<"PPPPPPPP"<<"                       "<<"EEEEEEEE"<<"                      "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR               RRRRRRR "<<"  "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPP"<<"                       "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR               RRRRRRRR"<<"  "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPP"<<"                       "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	cout<<"RRRRRRRR               RRRRRRRR"<<"  "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"PPPPPPPP"<<"                       "<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"  "<<"AAAAAAAA            AAAAAAAA"<<"  "<<"          TTTTTT            "<<endl;
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	SetConsoleTextAttribute( hOut, 02);
	cout<<"    III        NNN    NNN     OO     WW     WW     AAAAA         GGGGG    RRRRRRR    AAAA   "<< flush <<endl;
	cout<<"   I II        NNNNN  NNN   OO  OO   WW  W  WW    AA   AA      GGG       RRR   RRR  AA  AA  "<<endl;
	cout<<"     II        NNN NN NNN  OO    OO  WW WWW WW    AAAAAAA      GGG GGGG  RRRRRRRR   AAAAAA  "<<endl;
	cout<<"     II        NNN  NNNNN   OO  OO   WWW   WWW    AA   AA      GGG  GGG  RRR   RRR  AA  AA  "<<endl;
	cout<<"     II o      NNN    NNN     OO     WW     WW    AA   AA       GGGGGG   RRR   RRR  AA  AA  "<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"    III        III  NNN    NNN   SSSSS  TTTTTTTTT   RRRRRR   UUU  UUU  KKK  KKK    CCCCCC        JJJ   AAAA   "<<endl;
	cout<<"  II  II       III  NNNNN  NNN  SSS        TTT     RRR  RRR  UUU  UUU  KKK  KK    CCC   CC       JJJ  AA  AA  "<<endl;
	cout<<"     II        III  NNN NN NNN    SSS      TTT     RRRRRRR   UUU  UUU  KKKKK     CCC             JJJ  AAAAAA  "<<endl;
	cout<<"    II         III  NNN  NNNNN       SSS   TTT     RRR  RRR  UUU  UUU  KKK  KK    CCC   CC   JJ  JJJ  AA  AA  "<<endl;
	cout<<"  IIIIII o     III  NNN    NNN   SSSSSS    TTT     RRR  RRR   UUUUUU   KKK  KKK    CCCCCC    JJJJJJJ  AA  AA  "<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"    III       WW     WW  YY   YY  NNN    NNN   III   KKK  KKK  III                "<<endl;
	cout<<"  II  II      WW  W  WW   YY YY   NNNNN  NNN   III   KKK  KK   III                  "<<endl;
	cout<<"     II       WW WWW WW    YYY    NNN NN NNN   III   KKKKK     III                 "<<endl;
	cout<<"  II  II      WWW    WW    YYY    NNN  NNNNN   III   KKK  KK   III                "<<endl;
	cout<<"    III o     WW     WW    YY     NNN    NNN   III   KKK  KKK  III                "<<endl;
	
	cout<<endl;
	cout<<endl;
	
	cout<<"  III  III     WW     WW   YY   YY     JJJ   SSSSS     CCCCCC    III  EEEEEEE   "<<endl;
	cout<<"  III  III     WW  W  WW    YY YY      JJJ  SSS       CCC   CC   III  EEE       "<<endl;
	cout<<"  IIIIIIII     WW WWW WW     YYY       JJJ    SSS    CCC         III  EEEEE     "<<endl;
	cout<<"       III     WWW   WWW     YYY   JJ  JJJ      SSS   CCC   CC   III  EEE       "<<endl;
	cout<<"       III o   WW     WW     YYY   JJJJJJJ   SSSSS     CCCCCC    III  EEEEEEE   "<<endl;
	
	if(muzyka==23)
	{
		cout<<"MUZYCZKA";
		cout<<endl;
		Beep(261,500);
		Sleep(100);
		Beep(523,500);
		Beep(587,500);
		Beep(659,500);
		Beep(698,500);
		Beep(784,800);
		Beep(784,500);
		Beep(876,400);
		Beep(523,500);
		Beep(587,500);
		Beep(659,500);
		Beep(698,500);
		Beep(784,800);
		Beep(784,500);
		Beep(876,400);
		Beep(523,500);
		Beep(587,500);
		Beep(520,500);
		muzyka++;
		cout<<endl;
		cout<<"WYBIERZ OPCJE: ";
	}do
	{

		
	cin>>wyborwmenu;
	switch(wyborwmenu)
		{
			case 1: 
					{
						//NOWA GRA
					system("cls");			
					ShowWindow( GetConsoleWindow(), SW_MAXIMIZE);	
					cfi.dwFontSize.X = 12;			//nowa wartosc
					cfi.dwFontSize.Y = 16;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
					cout<<"Podaj swoj Nick!";   //podawanie nazwy
					cin>>nick;
					system("cls");
					
					ShowWindow( GetConsoleWindow(), SW_MAXIMIZE);	
					cfi.dwFontSize.X = 6;			//nowa wartosc
					cfi.dwFontSize.Y = 8;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
					lepszamaingra();  
					  //uruchamianie glownej mechaniki gry
					losowania.clear();
					cfi.dwFontSize.X = 12;			//nowa wartosc
					cfi.dwFontSize.Y = 16;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
					wynik();
					score=0;
					cout<<endl;
					cout<<"Co teraz chcesz zrobiæ ?"<<endl;
					cout<<"1. NOWA GRA"<<endl;
					cout<<"2. INSTRUKCJA"<<endl;
					cout<<"3. WYNIKI"<<endl;
					cout<<"4. KONIEC"<<endl;
					
					break;
						
					}
			case 2:
				{   //INSTRUKCJA
					system("cls");
					cfi.dwFontSize.X = 12;			//nowa wartosc
					cfi.dwFontSize.Y = 16;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  //akcept
					SetConsoleTextAttribute( hOut, 02); //ZIELONY KOLOR
					cout<<"-----INSTRUKCJA-----"<<endl;
					cout<<"NA EKRANIE POJAWI¥ SIÊ KOLORY W ODPOWIEDNIEJ KOLEJNOŒCI\n SPRÓBUJ POWTÓRZYÆ SEKWENCJÊ KOLORÓW W ODPOWIEDNIEJ KOLEJNOŒCI, ABY DOSTAC PUNKT"<<endl;
					cout<<"STEROWANIE ODBYWA SIÊ ZA POMOC¥ KLAWISZY: "<<endl;
					cout<<"I - CZERWONY\nJ - ZIELONY\nN - NIEBIESKI"<<endl;
					SetConsoleTextAttribute( hOut, 04);
					cout<<endl;
					cout<<"Co teraz chcesz zrobiæ ?"<<endl;
					cout<<"1. NOWA GRA"<<endl;
					cout<<"2. INSTRUKCJA <-- TUTAJ JESTEŒ"<<endl;
					cout<<"3. WYNIKI"<<endl;
					cout<<"4. KONIEC"<<endl;
					break;
				};
			case 3:
				{   //WYNIKI
					system("cls");
					cfi.dwFontSize.X = 12;			//nowa wartosc
					cfi.dwFontSize.Y = 16;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  //akcept
					SetConsoleTextAttribute( hOut, 02);//ZIELONY KOLOR
				    cout<<"---WYNIKI---"<<endl;
				    wyswietlaniewynikow();  //wyswietla wyniki graczy 
				    cout<<endl;
				    SetConsoleTextAttribute( hOut, 04);//CZERWONY KOLOR
				    cout<<"Co teraz chcesz zrobiæ ?"<<endl;
				    cout<<"1. NOWA GRA"<<endl;
					cout<<"2. INSTRUKCJA"<<endl;
					cout<<"3. WYNIKI <-- TUTAJ JESTEŒ"<<endl;
					cout<<"4. KONIEC"<<endl;
				    break;
				};
			case 4:
				{  //wyniki
					system("cls");
					cfi.dwFontSize.X = 12;			//nowa wartosc
					cfi.dwFontSize.Y = 16;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  //akcept
					SetConsoleTextAttribute( hOut, 02);
					cout<<"Do zobaczenia ..."<<endl;
					break;
				};
			default:
				{   //INNE OPCJE
					system("cls");
					SetConsoleTextAttribute( hOut, 02);
					cfi.dwFontSize.X = 12;			//nowa wartosc
					cfi.dwFontSize.Y = 16;			//nowa wartosc
					SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); //AKCEPTACJA
					cout<<"Nie ma takiej opcji, wybierz ponownie"<<endl;
					cout<<"1. NOWA GRA"<<endl;
					cout<<"2. INSTRUKCJA"<<endl;
					cout<<"3. WYNIKI"<<endl;
					cout<<"4. WYJŒCIE"<<endl;
					break;
				}
			
		}
	}
	while(wyborwmenu!=4);
	return 0;
}		



