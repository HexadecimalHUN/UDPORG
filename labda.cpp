#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdlib.h>

int main (void)
{
		struct winsize w;
			
		int xj=0, xk=0, yj=0, yk=0;
		int mx =80*2, my=24*2;
		
		WINDOW * ablak;
		ablak = initscr();
		noecho ();
		cbreak ();
		nodelay (ablak, true);
	for(;;)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ);
			mx=w.ws_col;
			my=w.ws_row;
		xj=(xj-1) % mx;
		xk=(xj+1) % mx;
		yj=(xj-1) % my;
		yk=(xj+1) % my;
			clear();
	 	mvprintw (0, 0,
				"--------------------------------------------------------------------------------");
		mvprintw (24, 0, 
				"________________________________________________________________________________");

		
			mvprintw (abs ((yj + (my - yk)) / 2),
			 	 abs ((xj + (mx - yk)) / 2), "x");
			refresh();
			usleep (150000);
}
return 0;
}
