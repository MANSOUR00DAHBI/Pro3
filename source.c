#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <unistd.h>
#define Width  100
#define Hieght 30

struct Circle {
	int x, y, r, xx, yy;
};
void clear_screen() {
	//printf("\e[2J");
	//printf("\e[H");
	system("clear");
}

void Draw_Circle(struct Circle circle) {
	for (int y = 0; y <= Hieght; ++y) {
		for (int x = 0; x <= Width; ++x) {

			float distance = sqrt(pow(x - circle.x, 2) + pow(y - circle.y, 2));
			if(distance  < circle.r){
				 printf("*");
			}
			else {
				printf(".");
			}

		}
		printf("\n");
	}
}
void setup(struct Circle* circle) {
	circle->x += circle->xx;
	circle->y += circle->yy;
	if (circle->x - circle->r < 0) {
		circle->xx = -circle->xx;
	}
	if (circle->x + circle->r > Width) {
		circle->xx = -circle->xx;
	}
	if (circle->y - circle->r < 0) {
		circle->yy = -circle->yy;
	}
	if (circle->y + circle->r > Hieght) {
		circle->yy = -circle->yy;
	}

}

int main(){
	int statu = 0;
	struct Circle circle = { 10,10,5,1,1 };
	while (1) {
		 clear_screen();
	      Draw_Circle(circle);
		 setup(&circle);

		  usleep(500000);
	}
	printf("\n");
	
	
	return statu;
}






















