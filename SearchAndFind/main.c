/*
 * SearchAndFind.c
 *
 * Created: 2017-05-05 15:54:54
 * Author : hyggan
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <string.h>
#define up 8
#define down 2
#define left 4 
#define right 6
#define wall 1 

typedef struct Robot {
	int xpos;
	int ypos;
	int Array[29][29];
	int direction; 
 
}Robot;

Robot robot; 

int Maparray[29][29]  ={
	
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}
};




//changing robot direction to given direction
void robot_set_direction(int direction){
	//int direction = robot.direction;
	if(direction ==  up ){
		robot.direction = up;
	}
	if(direction == right ){
		robot.direction = right;
	}
	if(direction == down ){
		robot.direction = down;
	}
	if(direction == left ){
		robot.direction = left;
	}
}

//always turning right in relation to where it's heading
void robot_turn_right(){
	int direction= robot.direction;
	if(direction ==  up ){		 
		robot_set_direction(right);
	}
	if(direction == right ){		
		robot_set_direction(down);
	}	
	if(direction == down ){		
		robot_set_direction(left);
	}
	if(direction == left ){		
		robot_set_direction(up);
	}	
}

//always turning right in relation to where it's heading
void robot_turn_left(){
	int direction= robot.direction;
	if(direction ==  up ){
		robot_set_direction(left);
	}
	if(direction == right ){
		robot_set_direction(down);
	}
	if(direction == down ){
		robot_set_direction(right);
	}
	if(direction == left ){
		robot_set_direction(down);
	} 
}

//calculates next pos (general) 
int next_xpos(int direction){
	int next_xpos;
	if(direction == up){
		next_xpos = robot.ypos;
	}
	if(direction == down){
		next_xpos = robot.ypos;
	}
	if(direction == left){
		next_xpos = robot.ypos - 1;
	}
	if(direction == right){
		next_xpos = robot.ypos + 1;
	}
	next_xpos= 100;
	return next_xpos;
}

int next_ypos(int direction){
	int next_ypos;
	if(direction == up){
		next_ypos = robot.ypos -1 ;
	}
	if(direction == down){
		next_ypos = robot.ypos +1;
	}
	if(direction == left){
		next_ypos = robot.ypos;
	}
	if(direction == right){
		next_ypos = robot.ypos ;
	}
	else{
		next_ypos= 100;
	}
	return next_ypos;
}

//calcúlates robots next pos
int robot_next_ypos_forward(){
	int rob_next_pos= next_ypos(robot.direction);
	return rob_next_pos;
}

int robot_next_xpos_forward(){
	int rob_next_pos= next_xpos(robot.direction);
	return rob_next_pos;
}

int robot_next_xpos_right(){
	int right_pos;
	if(robot.direction == up){
		right_pos = next_xpos(right);
	}
	if(robot.direction == down){
		right_pos = next_xpos(left);
	}
	if(robot.direction == right){
		right_pos = next_xpos(down);
	}
	if(robot.direction == left){
		right_pos = next_xpos(up);
	}
	else{
		right_pos= 100;
	}
	return right_pos;
}

///*
//detecting walls 
bool detect_wall(int next_xposition, int next_yposition){
	if(Maparray[next_xposition][ next_yposition]>0){
		return true;	
	}
		
	return false;
}

void robot_move(){
	robot.xpos = robot_next_xpos_forward();
	robot.ypos= robot_next_ypos_forward();
}

void robot_move_distance(int number_of_steps){
	for(int i=0; i<number_of_steps;i++){
		robot_move();
	}
}
//As long as we don't find a wall ahead or a clear at the right hand side, the robot keep moving forward 
//BUT! if we first off, find a clear way to travel to the right, we turn right and if we find a wall we 
//clearly have to turn left
void robot_keep_right(){
	//robot_next_yposition= next_ypos(robot.direction);
	//robot_next_xposition= next_xpos(robot.direction)
	while(detect_wall(robot_next_xpos_right(), robot_next_ypos_forward())){
		while(!(detect_wall(robot_next_xpos_forward(),robot_next_ypos_forward()))){
			robot_move();
		}
		robot_turn_left();
	}
	robot_turn_right();
}



int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

