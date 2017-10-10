/*****************************************************************
   PORT Command is used to change the state of pin i.e. On or OFF

   DDR is used to set the pinmode whether as input/output,
   thus DDR register instead of using pinMode().
 *****************************************************************/
void setup()
{
  DDRB = 0b00000011; //B0-B1(Set as output); DDR-Data Direvction Register is used to set the pin as input(0) or output(1)
  DDRD = 0b11111110; //D1-D7(Set as output)
}


void loop()
{
  start();
  for (int i = 0; i < 10; i++)
  {
    for ( int j = 0; j < 10; j++)
    {
      for (int del = 0; del < 10; del++)
      {
        disp(i, j);
      }
    }
  }
}

void start()
{ int i = 2;
  while (i != 0)
  {
    if (i == 2)
    {
      PORTB = 0b00000010; //Turn ON B1-pin and other pins of port B are OFF.
    }
    if (i == 1)
    {
      PORTB = 0b00000001;
    }
    PORTD = 0b00000010;
    delay(100);
    PORTD = 0b00000110;
    delay(100);
    PORTD = 0b00001110;
    delay(100);
    PORTD = 0b00011110;
    delay(100);
    PORTD = 0b00111110;
    delay(100);
    PORTD = 0b01111110;
    delay(100);
    PORTD = 0b11111110;
    delay(200);
    PORTD = 0b01111110;
    delay(100);
    PORTD = 0b00111110;
    delay(100);
    PORTD = 0b00011110;
    delay(100);
    PORTD = 0b00001110;
    delay(100);
    PORTD = 0b00000110;
    delay(100);
    PORTD = 0b00000010;
    delay(100);
    PORTD = 0b00000000;
    delay(200);
    i--;
  }
}

void zero()
{
  PORTD = 0b01111110;
}

void one()
{
  PORTD = 0b00001100;
}

void two()
{
  PORTD = 0b10110110;
}

void three()
{
  PORTD = 0b10011110;
}

void four()
{
  PORTD = 0b11001100;
}

void five()
{
  PORTD = 0b11011010;
}

void six()
{
  PORTD = 0b11111010;
}

void seven()
{
  PORTD = 0b00001110;
}

void eight()
{
  PORTD = 0b11111110;
}

void nine()
{
  PORTD = 0b11001110;
}

void digit1(int x)
{
  PORTB = 0b00000001;
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 10: zero(); break;
    case 0: zero(); break;
  }
}

void digit2(int x)
{
  PORTB = 0b000000010;
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 0: zero(); break;
    case 10: zero(); break;
  }
}

void disp(int i, int j)
{
  digit1(i);
  delay(10);
  digit2(j);
  delay(10);
}
