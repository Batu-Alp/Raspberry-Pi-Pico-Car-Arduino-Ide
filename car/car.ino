#define Cizgi1 26
#define Cizgi2 27

const int a1 = 14; // Birinci dc motorun + yönü
const int a2= 15; // Birinci dc motorun - yönü

const int b1 = 16; // İkinci dc motorun + yönü
const int b2 = 17; // İkinci dc motorun - yönü


int a,b;
int x = 0;

bool started = false;

void setup() {
  
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(Cizgi1, INPUT);
  pinMode(Cizgi2, INPUT);
 
  Serial.begin(9600);

}

void loop() {
  
  a = digitalRead(Cizgi1);
  b = digitalRead(Cizgi2);
  
  if(a==1){
    
    if(b == 1){
      
      analogWrite(a1,0);
      analogWrite(a2,160);
      analogWrite(b1,160);
      analogWrite(b2,0);
      started = true;
    }

    if(b == 0){
      
      analogWrite(a1,0);
      analogWrite(a2,0);
      analogWrite(b1,160);
      analogWrite(b2,0);
      x=1;
    }
  }

  if(a == 0){
    
    if(b == 1){
      
      analogWrite(a1,0);
      analogWrite(a2,160);
      analogWrite(b1,0);
      analogWrite(b2,0);
      x = 2;
      
    }
    
    if(b == 0){
      analogWrite(a1,0);
      analogWrite(a2,0);
      analogWrite(b1,0);
      analogWrite(b2,0);

      
      if(x == 1){
        analogWrite(a1,0);
        analogWrite(a2,0);
        analogWrite(b1,160);
        analogWrite(b2,0);
      }

      if(x == 2){
        analogWrite(a1,0);
        analogWrite(a2,160);
        analogWrite(b1,0);
        analogWrite(b2,0);
      }
    }
  }
  
  Serial.print("A : ");
  Serial.print(a);
  Serial.print("  B : ");
  Serial.println(b);

}
