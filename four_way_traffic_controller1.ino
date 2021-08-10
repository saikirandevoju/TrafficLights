//declaring and intializing variables
int red1=2,yellow1=3,green1=4;
int red2=5,yellow2=6,green2=7;
int red3=8,yellow3=9,green3=10;
int red4=11,yellow4=12,green4=13;
int greenOnTime=3000,yellowOnTime=1000;
int time_slot;

void setup()
{
  Serial.begin(9600);
  
  pinMode(red1,OUTPUT);     //signal 1 red LED
  pinMode(yellow1,OUTPUT);  //signal 1 yellow LED
  pinMode(green1,OUTPUT);   //signal 1 green LED
  
  pinMode(red2,OUTPUT);     //signal 2 red LED
  pinMode(yellow2,OUTPUT);  //signal 2 yellow LED
  pinMode(green2,OUTPUT);   //signal 2 green LED
  
  pinMode(red3,OUTPUT);     //signal 3 red LED
  pinMode(yellow3,OUTPUT);  //signal 3 yellow LED
  pinMode(green3,OUTPUT);   //signal 3 green LED
  
  pinMode(red4,OUTPUT);     //signal 4 red LED
  pinMode(yellow4,OUTPUT);  //signal 4 yellow LED
  pinMode(green4,OUTPUT);   //signal 4 green LED
  
  Serial.println("Time slots:");
  Serial.println("1.3am to 6am");
  Serial.println("2.6am to 9am");
  Serial.println("3.9am to 9pm");
  Serial.println("4.9pm to 3am");
  Serial.println(" ");
  
  Serial.println("Enter the time slot:");
  while(Serial.available()==0){}
  time_slot=Serial.parseInt();
  
}

void loop()
{ 
  if(time_slot==1)
  {
    digitalWrite(yellow1,HIGH);
    digitalWrite(yellow2,HIGH);
    digitalWrite(yellow3,HIGH);
    digitalWrite(yellow4,HIGH);
  }
  
  else if(time_slot==2 || time_slot==4)
  {
    digitalWrite(green1,HIGH);
    digitalWrite(red2,HIGH);
    digitalWrite(red3,HIGH);
    digitalWrite(red4,HIGH);
    delay(greenOnTime);
    
    digitalWrite(green1,LOW);
    digitalWrite(yellow1,HIGH);
    delay(yellowOnTime);
    
    digitalWrite(yellow1,LOW);
    digitalWrite(red1,HIGH);
    digitalWrite(red2,LOW);
    digitalWrite(green2,HIGH);
    delay(greenOnTime);
    
    digitalWrite(green2,LOW);
    digitalWrite(yellow2,HIGH);
    delay(yellowOnTime);
    
    digitalWrite(yellow2,LOW);
    digitalWrite(red2,HIGH);
    digitalWrite(red3,LOW);
    digitalWrite(green3,HIGH);
    delay(greenOnTime);
    
    digitalWrite(green3,LOW);
    digitalWrite(yellow3,HIGH);
    delay(yellowOnTime);
    
    digitalWrite(yellow3,LOW);
    digitalWrite(red3,HIGH);
    digitalWrite(red4,LOW);
    digitalWrite(green4,HIGH);
    delay(greenOnTime);
    
    digitalWrite(green4,LOW);
    digitalWrite(yellow4,HIGH);
    delay(yellowOnTime);
    
    digitalWrite(yellow4,LOW);
    digitalWrite(red4,HIGH);
    digitalWrite(red1,LOW);
  }
  
  else if(time_slot==3)
  {
    digitalWrite(green2,HIGH);
    digitalWrite(green4,HIGH);
    digitalWrite(red1,HIGH);
    digitalWrite(red3,HIGH);
    delay(greenOnTime);
    
    digitalWrite(green2,LOW);
    digitalWrite(green4,LOW);
    digitalWrite(yellow2,HIGH);
    digitalWrite(yellow4,HIGH);
    delay(yellowOnTime);
    
    digitalWrite(yellow2,LOW);
    digitalWrite(yellow4,LOW);
    digitalWrite(red2,HIGH);
    digitalWrite(red4,HIGH);
    digitalWrite(red1,LOW);
    digitalWrite(red3,LOW);
    digitalWrite(green1,HIGH);
    digitalWrite(green3,HIGH);
    delay(greenOnTime);
    
    digitalWrite(green1,LOW);
    digitalWrite(green3,LOW);
    digitalWrite(yellow1,HIGH);
    digitalWrite(yellow3,HIGH);
    delay(yellowOnTime);
    
    digitalWrite(yellow1,LOW);
    digitalWrite(yellow3,LOW);
    digitalWrite(red2,LOW);
    digitalWrite(red4,LOW);
  }
  
  else
  {
    Serial.println("Invalid time slot!");
  }
}