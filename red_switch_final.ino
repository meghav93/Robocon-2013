#define encoder0PinA 20              // right wheel encoder    
#define encoder0PinB 21  


#define encoder0PinC 50              // rotary arm encoder
#define encoder0PinD 51 



#define encoder0PinX 49              // left wheel encoder   
#define encoder0PinY 48 


const int t1=A10;
const int t2=A11;
const int t3=41;
const int t4=43;


int r=0;
int yash=0;
int rd=0;

int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;
int g=0;
int x=0;
int p=0;
int z=0;
int w=0;
int a_max=635;
int a_min=165;
int b_max=652;
int b_min=157;
int c_max=645;
int c_min=170;
int d_max=646;
int d_min=162;


int g_max=655;
int g_min=166;
int x_min=167;
int x_max=656;
int p_max=656;
int p_min=165;
int z_min=168;
int z_max=653;
int w_min=167;
int w_max=650;



static int center;
static int left0,left1,left2,left3,left_g1,left_g2,left_g0;
static int right0,right1,right2,right3,right_g1,right_g2,right_g0;
static int arm_left_sharp,arm_right_sharp;
int flag_l=1,flag_r=1,flag_c=1,flag_u=1;
static int sflag,spulses;
static int prev_error=0;
static int sum=0;
static int pulses_right=0;
static int pulses_left=0;
static int arm_pulse=0;
int temp_b=1;
float one_pulse =0.044942228;        // distance covered per unit pulse = circumference / resoolution
float one_degree= 9.82082524;

const float arm_degree=0.59*6;                                                                  
static int path=6;

float cm;
int temp=0;
int y=0;
int lflag=0;
//--------------motor--------------------------
const int left_mot_fwd=9;
const int left_mot_rev=10;

const int right_mot_fwd=8;
const int right_mot_rev=7;

const int arm_motor_frw=6;
const int arm_motor_rev=5;

const int grip_motor_frw=4;
const int grip_motor_rev=3;

const int arm=36;
const int grip=38  ;

//--------------------functions----------------
void forward(int dist);
void forward_check(int velocity);

void left(int angle);
void line_follow_blue(void);
void line_follow_green(void);
void reverse(int dist);

void right(int angle);


void acc_dcc_frw(int total_pulses);
void acc_dcc_rev(int total_pulses);

void arm_left(int angle);
void arm_right(int angle);
void stopper();
//--------------------------------------------------
void setup()
{
  pinMode(encoder0PinA, INPUT); 
  pinMode(encoder0PinB, INPUT); 

  pinMode(encoder0PinC, INPUT); 
  pinMode(encoder0PinD, INPUT); 

  pinMode(encoder0PinX, INPUT); 
  pinMode(encoder0PinY, INPUT);  

  attachInterrupt(encoder0PinA, doEncoderA, CHANGE);
  attachInterrupt(encoder0PinB, doEncoderB, CHANGE);  

  attachInterrupt(encoder0PinX, doEncoderX, CHANGE);
  attachInterrupt(encoder0PinY, doEncoderY, CHANGE);  

  attachInterrupt(encoder0PinC, doEncoderC, CHANGE);
  attachInterrupt(encoder0PinD, doEncoderD, CHANGE);  

  pinMode(left_mot_fwd,OUTPUT);
  pinMode(left_mot_rev,OUTPUT); 

  pinMode(right_mot_fwd,OUTPUT);
  pinMode(right_mot_rev,OUTPUT);

  pinMode(arm_motor_frw,OUTPUT);
  pinMode(arm_motor_rev,OUTPUT); 

  pinMode(grip_motor_frw,OUTPUT);
  pinMode(grip_motor_rev,OUTPUT);

  pinMode(13,OUTPUT);  
  pinMode(grip,OUTPUT);  
  pinMode(arm,OUTPUT);  

  digitalWrite(arm,0);
  digitalWrite(grip,0);

  digitalWrite(left_mot_fwd,0);
  digitalWrite(left_mot_rev,0);

  digitalWrite(right_mot_fwd,0);
  digitalWrite(right_mot_rev,0);

  digitalWrite(grip_motor_frw,0);
  digitalWrite(grip_motor_rev,0);

  digitalWrite(arm_motor_frw,0);
  digitalWrite(arm_motor_rev,0);

  digitalWrite(grip_motor_frw,0);
  digitalWrite(grip_motor_rev,0);

  pinMode(t1,INPUT);
  pinMode(t2,INPUT);
  pinMode(t3,INPUT);
  pinMode(t4,INPUT);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A7,INPUT);
  pinMode(A6,INPUT);
  pinMode(A8,INPUT);
  pinMode(A9,INPUT);
  pinMode(A10,INPUT);
  pinMode(A11,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,1);
  Serial.begin(9600);
  digitalWrite(t1,1);
  digitalWrite(t2,1);
  digitalWrite(t3,1);
  digitalWrite(t4,1);
}



void loop()
{
  int t=0;

  while(digitalRead(t3)==0)
  {
    analogWrite(grip_motor_frw,0);
    analogWrite(grip_motor_rev,100);
  }
  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,0);
  while(digitalRead(t4)==0)
  {
    analogWrite(grip_motor_frw,100);
    analogWrite(grip_motor_rev,0);
  }
  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,0);
  
  
  while(millis()<5000)
  {
    if(digitalRead(t1)==0)
    {
      Serial.println("1");
      t=1;
    }
    else if(digitalRead(t2)==0)
    {
      Serial.println("2");
      t=2;
    }
  }

  switch (t)
  {
  case 1: 
    task1();
    break;

  case 2: 
    task2();
    break;

  default: 
    stopper();
    break; 
  }
}



























