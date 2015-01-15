# RH2O
volatile uint32_t rpmcont; //flancos 
volatile uint32_t rpmcont1; //flancos 
int calc;
int pin_sensor = 2;
int s0,s1,s2,s3,s4,s5;

void rpm () // funcion de contador de flancos
{rpmcont++;}

void rpm1()
{rpmcont1 ++;}

void setup()
{
  Serial.begin(115200);
  rpmcont=0;
  rpmcont1=0;
  delay(100);
  attachInterrupt(1, rpm, RISING);//el 1 es el modulo de interupcion, rising flanco de subida, y rpm fuuncion 
  attachInterrupt(0, rpm1, RISING);
}

void loop ()
{
  //rpmcont=0;
  sei();//habilita interuppciones
  delay(10);
  cli();//deshabilita las interupciones
  //-calc=(rpmcont*60/350);
  //-Serial.print(calc,DEC);
  
  //Serial.print(rpmcont,DEC);
  //Serial.print(" --- ");
  //Serial.print(rpmcont1,DEC);
  //Serial.print("\n");
  
//    attachInterrupt(1, rpm, RISING); 
//    attachInterrupt(0, rpm1, RISING);
  String dataString = "";
  delay(1);
  s0= analogRead(0); s1= analogRead(1); s2= analogRead(2); s3= analogRead(3);s4= analogRead(4);s5= analogRead(5);  
    dataString += String(s0);
    dataString += "\t"; 
    dataString += String(s1);
    dataString += "\t"; 
    dataString += String(s2);
    dataString += "\t"; 
    dataString += String(s3);
    dataString += "\t"; 
    dataString += String(s4);
    dataString += "\t"; 
    dataString += String(s5);
    dataString += "\t"; 
    dataString += String(rpmcont);
    dataString += "\t"; 
    dataString += String(rpmcont1);
    dataString += "\t"; 
    Serial.println(dataString);
}
