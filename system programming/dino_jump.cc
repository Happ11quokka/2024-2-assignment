#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define DINO_HEIGHT	13
#define CACTUS_HEIGHT	5

#define SPACE		32
#define ENTER		10

void DrawDinosaur(int);
void DrawCactus(int, int);
int _kbhit(void);
int GetKeyDown();

int _kbhit(void)
{
	struct timeval tv =  { 0L, 0L };
	fd_set fds;

	FD_ZERO(&fds);
	FD_SET(0, &fds);

	return select(1, &fds, NULL, NULL, &tv);
}

int GetKeyDown()
{
	if(_kbhit()){
		return getch();
	}

	return 0;
}

void DrawDinosaur(int dinosaurHead)
{
	move(dinosaurHead, 0);
	static bool legDraw = true;

	printw("        &&&&&&& ");
	move(dinosaurHead + 1, 0);
	printw("       && &&&&&&");
	move(dinosaurHead + 2, 0);
	printw("       &&&&&&&&&");
	move(dinosaurHead + 3, 0);
	printw("&      &&&      ");
	move(dinosaurHead + 4, 0);
	printw("&&     &&&&&&&  ");
	move(dinosaurHead + 5, 0);
	printw("&&&   &&&&&     ");
	move(dinosaurHead + 6, 0);
	printw(" &&  &&&&&&&&&&&");
	move(dinosaurHead + 7, 0);
	printw(" &&&&&&&&&&&    ");
	move(dinosaurHead + 8, 0);
	printw("  &&&&&&&&&&    ");
	move(dinosaurHead + 9, 0);
	printw("    &&&&&&&&    ");
	move(dinosaurHead + 10, 0);
	printw("     &&&&&&     ");

	if (legDraw) {
		move(dinosaurHead + 11, 0);
		printw("     &    &&&     ");
		move(dinosaurHead + 12, 0);
		printw("     &&           ");
		legDraw = false;
	}
	else {
		move(dinosaurHead + 11, 0);
		printw("     &&&  &       ");
		move(dinosaurHead + 12, 0);
		printw("          &&      ");
		legDraw = true;
	}
}

void DrawCactus(int cactusHead, int cactusPos)
{
	move(cactusHead, cactusPos);
	printw("$$$$");
	move(cactusHead + 1, cactusPos);
	printw(" $$ ");
	move(cactusHead + 2, cactusPos);
	printw(" $$ ");
	move(cactusHead + 3, cactusPos);
	printw(" $$ ");
	move(cactusHead + 4, cactusPos);
	printw(" $$ ");
}

void printCount(int count)
{
	move(0,0); 
	printw("Count: %d\n", count); 
}


int main(int argc, char* argv[])
{
	initscr();

	int winWidth = 0, winHeight = 0;
	int dinosaurHead = 0;
	int cactusHead = 0, cactusPos = 0;
	int getKey = 0;
	bool isJumping = false;
	bool isBottom = true;

	int count = 0 ;

	int speed = 100000 ; 



	getmaxyx(stdscr, winHeight, winWidth);

	dinosaurHead = winHeight - DINO_HEIGHT;
	cactusHead = winHeight - CACTUS_HEIGHT;

	cactusPos = winWidth - 20;

	while(true){
		getKey = GetKeyDown();

		if(SPACE == getKey && isBottom){
			isJumping = true;
			isBottom = false;
		}else if(ENTER == getKey){
			break;
		}

		if(isJumping){
			dinosaurHead -= 3;
		}else{
			dinosaurHead += 3;
		}

		if(winHeight <= (dinosaurHead + DINO_HEIGHT)){
			dinosaurHead = winHeight - DINO_HEIGHT;
			isBottom = true;
		}

		if(dinosaurHead <= 0){
			isJumping = false;
		}


		int dinosaurFoot = dinosaurHead + DINO_HEIGHT ; 

		int cactusFoot = winHeight - CACTUS_HEIGHT ; 
		cactusPos -= 3;
		
		if(cactusPos <= 0){
			cactusPos = winWidth - 20;
			count++; 

			if (count % 5 == 0 )
			{
				speed -= 5000; 
				if (speed < 5000 )
				{
					speed = 100 ; 
				}
			}
		}

		if (cactusPos <= 16 && cactusPos >= 0)
		{
			if (dinosaurFoot > cactusFoot)
			{	
				move(winHeight /2, winWidth /2); 
				printw("game over!!!!!!!") ; 
				move((winHeight /2) + 1, winWidth /2); 
				printw("your count is : %d",count); 
				refresh();

				getch();
				break;
			}
		}

		clear();
		DrawCactus(cactusHead, cactusPos);
		DrawDinosaur(dinosaurHead);
		printCount(count); 
		usleep(speed);
		refresh();
	}
	
	endwin();

	return 0;
}
