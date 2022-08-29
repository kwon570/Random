int Red = 12; // LED Ramp
int Yellow = 11; // LED Ramp
int Green = 10; // LED Ramp
int bt = 4; // 버튼
int Congratulations = random (2, 11); // 몇번째 당첨
long randNumber;
int count = 0;
int state = 0;
const int music = 6;
int ddo = 262; int re = 294; int mi = 330; int pa = 350; int sol = 392; int ra = 440; int si = 494; int Do = 523; int sharp = 554;
int RE = 587; int MI = 659; int sim = 0;
int melody[] = {sol, ra, si, Do, sol, sim, Do, si, Do, RE, ra, sim, ra, si, Do, MI, RE, RE, Do, Do, si, ra, si, sol, sim, sim, sol,
                ra, si, Do, sol, sim, MI, RE, Do, RE, ra, sim, ra, si, Do, MI, RE, RE, Do, Do, si, ra, si, Do
               };
double beat[] = {1, 1, 1, 2, 2, 1, 1, 1, 1, 2.0, 2, 1, 1, 1, 1.5, 1.5, 1, 2, 1, 1, 1, 1, 1, 2.5, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1.5, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.5, 1, 1, 3};
int melodyNum = 50;
void setup() {
  // put your setup code here, to run once:
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(bt, INPUT);
  randomSeed(analogRead(0));
  pinMode(music, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  const int btState = digitalRead(bt);
  //int Random = random(0, 3);//LED 랜덤값
  randNumber = random(3);
  if (btState == HIGH)//눌렀을때 
  {
    Serial.print("Congratulations = ");
    Serial.println(Congratulations);
    if (state == 0)
    {
      delay(100);
      state = 1;
    }
    Serial.println(randNumber);
    //=====================================================
    if (randNumber == 0)
    {
      digitalWrite(Red, HIGH);
      delay(5000);
      digitalWrite(Red, LOW);
    }
    else if (randNumber == 1)
    {
      digitalWrite(Yellow, HIGH);
      delay(5000);
      digitalWrite(Yellow, LOW);
    }
    else if (randNumber == 2)
    {
      digitalWrite(Green, HIGH);
      delay(5000);
      digitalWrite(Green, LOW);
    }
  }
  //=================================================== (랜덤 LED 불빛 코드)
  if (btState == LOW)//땟을때 

  {
    if (state == 1)
    {
      delay(10);
      count += 1;
      state = 0;
      Serial.print("count = ");
      Serial.println(count);
      
    }         
    if (count == Congratulations)
      {
         resetFunc();
      }  
  }
  
}
void resetFunc() //당첨 코드
{
 // for (int i = 0; i < melodyNum; i++)
 // {
   // tone(music, melody[i]);
    //delay(300 * beat[i]);
    //noTone(music);
  //}
  analogWrite(music,700);
  delay(500);
  analogWrite(music,0);
  delay(500);
  Congratulations = random (2, 11);
  count=0;
  Serial.print("set Random =");
  Serial.println(Congratulations);
}
