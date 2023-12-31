// Write the simulation program for demand paging and show the page 
//  scheduling and total number of page faults according the FIFO page 
//  replacement algorithm. Assume the memory of n frames. 
//  Reference String : 2, 4, 5, 6, 9, 4, 7, 3, 4, 5, 6, 7, 2, 4, 7, 1 
/////////////////////////////////////////////////////////////////////////
/// 
 
 #include<stdio.h> 
int nor,nof,table[20][20],ref[20],frame[10],pagefault=0; 
void accept() 
{ 
 int i; 
 printf("\nHow many references:"); 
 scanf("%d",&nor); 
 printf("\nEnter reference String:"); 
 for(i=0;i<nor;i++) 
 { 
 scanf("%d",&ref[i]); 
 } 
 printf("\nHow many Frames:"); 
 scanf("%d",&nof); 
} 
int search(int pno) 
{ int i; 
 for(i=0;i<nof;i++) 
 { 
 if(frame[i]==pno) 
 return i; 
 } 
 return -1; 
} 
void fifo() 
{ 
 int i,pos=0,r,found; 
 for(i=0;i<nof;i++) 
 { 
 frame[i]=-1; 
 } 
 for(r=0;r<nor;r++) 
 { 
 found=search(ref[r]); 
 if(found==-1) 
 { 
 pagefault++; 
 frame[pos]=ref[r]; 
 pos=(pos+1)%nof; 
 for(i=0;i<nof;i++) 
 { 
 table[i][r]=frame[i]; 
 } 
 } 
 else 
 { 
 for(i=0;i<nof;i++) 
 { 
 table[i][r]=frame[i]; 
 } 
 } 
 } 
 } 
void display() 
{ 
 int i,j; 
 printf("\nReference String: "); 
 for(i=0;i<nor;i++) 
 { 
 printf("%2d",ref[i]); 
 } 
 printf("\n\n"); 
 for(i=0;i<nof;i++) 
 { 
 for(j=0;j<nor;j++) 
 { 
 printf("%2d",table[i][j]); 
 } 
 printf("\n"); 
 } 
 printf("\n\nPage Fault= %d\n",pagefault); 
} 
int main() 
{ 
 accept(); 
 fifo(); 
 display(); 
} 