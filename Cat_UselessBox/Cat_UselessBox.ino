#include <Servo.h>                       //Servo 라이브러리
Servo handServo;                         //스위치를 끄는 서보모터 정의
Servo boxServo;                          //상자를 여는 서보모터 정의
int switchStatus=0, action=10;            //스위치 상태와 랜덤한 수의 변수를 정의
const int frontSwitchPin = 2;            //상자 바깥쪽에있는 스위치 핀 정의
const int handServoPin = 5;              //인형의 손을 담당하는 서보모터 핀 정의
const int boxServoPin = 6;               //인형의 머리를 담당하고 상자를 여는 서보모터 핀 정의

void setup()
{
  Serial.begin(9600);

  handServo.attach(handServoPin);              //서보모터 핀을 변수로 정의
  boxServo.attach(boxServoPin);
  handServo.write(180);                        //서보모터 초기화
  boxServo.write(50);
  randomSeed(analogRead(0));                   // 난수 발생기의 시작값 초기화
}


void loop()
{
  switchStatus = digitalRead(frontSwitchPin); //스위치 상태 읽기
  action = random(1,14); //랜덤 변수
  
  if (switchStatus == LOW){                   //사용자가 스위치를 올리면
    
    if (action == 1)
    {
      Serial.println("Action 1");           //첫 번째 패턴은 인형이 나와 사람을 쳐다본뒤 천천히
      for (int i = 50; i <= 110; i+=2)      //인형이 나와 사람을 쳐다본 뒤
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 25; i--)       //손을 천천히 스위치쪽으로 가져다 놓은 뒤
      {
        handServo.write(i);
        delay(20);
      }
      delay(1000);                          //약간의 시간이 있은 후
      handServo.write(0);                   //스위치를 끈다
      delay(200);
      for (int i = 0; i <=180; i++)         //그리고 팔을 원위치 시킨 뒤
      {
        handServo.write(i);
        delay(20);
      }
      for (int i = 110; i >= 50; i--)       //인형도 다시 상자 속으로 들어간다
      {
        boxServo.write(i);
        delay(20);
      }
      action++;
    }
    
    
    else if (action == 2)
    {
      Serial.println("Action 2");         //스위치를 빨리 끄고 들어간 후에 조금 있다 다시 나와서 머리를 내미는 패턴
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(550);
      handServo.write(5);
      delay(550);
      handServo.write(180);
      delay(550);
      boxServo.write(50);
      delay(1500);
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 3)
    {
      Serial.println("Action 3");         //올려다보고 스위치를 빨리 끄는 패턴
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      boxServo.write(50);
      delay(2000);
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(5);
      delay(550);
      handServo.write(180);
      delay(500);
      boxServo.write(50);
      action++;
    }
   
    else if (action == 4)
    {
      Serial.println("Action 4");         //천천히 나와서 스위치를 누른후 빠르게 들어가기
      for (int i = 50; i <= 110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(20);
      }
      delay(2000);
      handServo.write(5);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 5)
    {
      Serial.println("Action 5");       //뚜겅을 열고 나와서 손을 왔다갔다 하며 화를내는 패턴
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      handServo.write(55);
      delay(550);
      handServo.write(30);
      delay(200);
      handServo.write(55);
      delay(200);
      handServo.write(30);
      delay(200);
      handServo.write(55);
      delay(200);
      handServo.write(30);
      delay(200);
      handServo.write(55);
      delay(200);
      handServo.write(30);
      delay(200);
      handServo.write(55);
      delay(200);
      handServo.write(30);
      delay(200);
      handServo.write(55);
      delay(2000);
      handServo.write(5);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 6)             
    {
      Serial.println("Action 6");        //빠른 시간동안 뚜겅을 여닫는걸 반복하면서 화를 내는 패턴
      for (int i = 50; i <110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 0; i < 12; i++)
      {
        for (int j = 50; j <= 110; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      for (int i = 180; i >= 25; i--)
      {
        handServo.write(i);
        delay(30);
      }
      handServo.write(5);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      delay(1500);
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 7) // 손을 내민상태에서 뚜껑을 빨리 여닫는걸 반복하며 화내는 패턴
    {
      Serial.println("Action 7"); 
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(400);
      handServo.write(5);
      delay(1000);
      for (int i = 0; i < 6; i++)
      {
        for (int j = 70; j <= 110; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      delay(500);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 8) // 손을 내밀어 스위치를 끈 후 손을 빠르게 움직여 화내는 패턴
    {
      Serial.println("Action 8");
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(5);
      delay(2000);
      for (int i = 0; i < 7; i++)
      {
        handServo.write(65);
        delay(100);
        handServo.write(30);
        delay(100);
      }
      delay(500);
      handServo.write(180);
      delay(1000);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 9) // 천천히 손을 내밀고 스위치를 끈 후 천천히 들어가고 뚜껑이 닫힌 후 다시나와 놀래키는 패턴
    {
      Serial.println("Action 9");
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      boxServo.write(110);
      for (int i = 180; i >=30; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(500);
      handServo.write(5);
      delay(200);
      for (int i = 5; i <=180; i++)
      {
        handServo.write(i);
        delay(40);
      }
      boxServo.write(50);
      delay(2000);
      boxServo.write(105);
      delay(3000);
      boxServo.write(50);
      action++;
    }
  
    
    else if (action == 10)
    {
      Serial.println("Action 10");      //천천히 뚜껑을 열은 뒤 열었다 닫았다를 반복하며 화를 내다 빠르게 스위치를 끄고 들어가는 패턴
      for (int i = 50; i <= 110; i++)
      {
        boxServo.write(i);
        delay(100);
      }
      delay(1000);
      for (int i = 0; i < 10; i++)
      {
        for (int j = 50; j <= 110; j++){
          boxServo.write(j);
          delay(6);
      }
        delay(100);
      }
      boxServo.write(110);
      delay(100);
      handServo.write(6);
      delay(650);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 11)
    {
      Serial.println("Action 11");      // 빠르게 나와 스위치를 끄고 손을 3번정도 흔들면서 항의한다음에 들어가고 몇초 있다 다시 나와 손으로 스위치 가리는 패턴
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(5);
      delay(2000);
      for (int i = 0; i < 3; i++)
      {
        handServo.write(55);
        delay(200);
        handServo.write(30);
        delay(200);
      }
      delay(1500);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      delay(1500);
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(25);
      delay(3000);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 12)
    {
      Serial.println("Action 12");      //천천히 머리를 내밀고 천천히 스위치쪽으로 가다가 빠르게 스위치를 끄고 들어가는 패턴
      for (int i = 50; i <= 110; i++)
      {
        boxServo.write(i);
        delay(50);
      }
      delay(1000);
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(50);
      }
      delay(2000);
      handServo.write(15);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(50);
      action++;
    }
    
    else if (action == 13)
    {
      Serial.println("Action 13");      //천천히 머리를 내밀고 손을 스위치를 향해 천천히 가다가 끌까말까를 반복하다 끄고 들어가는 패턴
      for (int i = 50; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      for (int i = 180; i >= 50; i--)
      {
        handServo.write(i);
        delay(40);
      }
      for (int i = 0; i < 3; i++)
      {
        handServo.write(50);
        delay(200);
        handServo.write(35);
        delay(800);
      }
      handServo.write(15);
      delay(2000);
      handServo.write(180);
      delay(500);
      boxServo.write(50);
      action++;
    }
    
    
    
  }
  
}