#include<stdio.h>
#include<stdlib.h>
int temp1,temp2,temp3,temp4,i,winsize=8,noframes,moreframes;
int receiver(int);
int simulate(int);
void main(){
	temp1 = 0;
	temp2 = 0;
	temp3 = 0;
	temp4 = 0;
	noframes = 10;
	winsize = 8;
	moreframes = noframes;
	printf("No. of frames %d",noframes);
	while(moreframes>0){
		temp1 = simulate(winsize);
		winsize -= temp1;
		temp4 += temp1;
		if(temp4>noframes){
			temp4 = noframes;
		}
		for(i = temp3 + 1;i<=temp4;i++)
			printf("Sending frames %d",i);
		temp2 = receiver(temp1);
		temp3 +=temp2;
		if(temp3>noframes)
			temp3 = noframes;
		printf("\n Ackowledgement for frames upto %d",temp3);
		moreframes -= temp2;
		temp4 = temp3;
		if(winsize<=0)
			winsize=8;
	}
	
		printf("\nend of sliding window protocol");	
}
int receiver(int temp1){
	int i;
	for(i=0;i<100;i++)
		rand();
		 i = rand() % temp1;

	return i;
}
int simulate(int winsize){
	int temp1,i;
	for(i=0;i<50;i++)
		temp1 = rand();
	if(temp1==0)
		temp1 = simulate(winsize);
		i = temp1 % winsize;
		if(i==0)
		return winsize;
		else
		return temp1 % winsize;
}

//OUTPUT
/*
mit@mit-Vostro-3800:~/Desktop/darsh$ ./goBackN 
No. of frames 10Sending frames 1Sending frames 2
 Ackowledgement for frames upto 0Sending frames 1Sending frames 2
 Ackowledgement for frames upto 0Sending frames 1Sending frames 2
 Ackowledgement for frames upto 0Sending frames 1Sending frames 2
 Ackowledgement for frames upto 1Sending frames 2Sending frames 3Sending frames 4
 Ackowledgement for frames upto 1Sending frames 2
 Ackowledgement for frames upto 1Sending frames 2Sending frames 3
 Ackowledgement for frames upto 1Sending frames 2
 Ackowledgement for frames upto 1Sending frames 2
 Ackowledgement for frames upto 1Sending frames 2Sending frames 3Sending frames 4Sending frames 5
 Ackowledgement for frames upto 4Sending frames 5
 Ackowledgement for frames upto 4Sending frames 5
 Ackowledgement for frames upto 4Sending frames 5Sending frames 6
 Ackowledgement for frames upto 4Sending frames 5Sending frames 6Sending frames 7Sending frames 8Sending frames 9Sending frames 10
 Ackowledgement for frames upto 7Sending frames 8Sending frames 9Sending frames 10
 Ackowledgement for frames upto 9Sending frames 10
 Ackowledgement for frames upto 9Sending frames 10
 Ackowledgement for frames upto 10
*/
