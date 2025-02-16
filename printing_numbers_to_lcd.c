#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


long long id = 220102002033;
int a, b, c, x0, x1;
float step;
int i;

void setup()
{
  lcd.begin(16, 2);

}

int takenumber(long long id, int flag, int initial, int number)
{
  int digit;

  if (flag == 0)
  {
    digit = id / 10000000000;
  }
  
  else
  {
    if (initial == 2)
    {
      digit = id % 100;
    }

    else 
    {
      digit = (id / 100) % 100;
    }
  }

  return digit;
}


int minnumber(long long id)
 {
  int temp, min=9;

  while (id > 0) 
  {
    temp = id % 10; 
    if (temp < min) 
    {
      min = temp; 
    }
    id /= 10; 
  }
  return min;
}

int maxnumber(long long id)
 {
  int temp, max=0;

  while (id > 0) 
  {
    temp = id % 10; 
    if (temp > max) 
    {
      max = temp; 
    }
    id /= 10; 
  }
  return max;
}


float area(int a, int b, int c, int x0, int x1, float step)
{
  float area = 0;
  float x;

  for (x=x0; x<=x1; x+=step)
  {
    area += (a * x * x + b * x + c) * step;
  }
  return area;
}


float average(long long id)
{
  int sum = 0;
  while (id > 0) 
  {
    sum += id % 10; 
    id /= 10; 
  }
  return (float) sum/12;
}


char dec2hexa(int number, int flag)
{
  int remainder = number % 16; 
    
  if (flag == 1) 
  {
    if (remainder >= 0 && remainder <= 9) 
    {
      return (char)(remainder + '0'); 
    }
    else
    {
      return (char)((remainder - 10) + 'A'); 
    }
  }
  else
  {
    int upper = (number / 16) % 16; 
   
    if (upper >= 0 && upper <= 9)
    {
      return (char)(upper + '0');
    }
    else
    {
      return (char)((upper - 10) + 'A');
    }
  }
}


void loop()
{
  a = takenumber(id, 0, 1, 2);
  b = takenumber(id, 1, 4, 2);
  c = takenumber(id, 1, 2, 2);
 
  x0 = minnumber(id);
  x1 = maxnumber(id);
  step = average(id);
 
  float result_area = area(a, b, c, x0, x1, step);

  char firsthexa[3] = {dec2hexa(takenumber(id, 0, 1, 2), 0), dec2hexa(takenumber(id, 0, 1, 2), 1), '\0'};
  char secondhexa[3] = {dec2hexa(takenumber(id, 1, 2, 2), 0), dec2hexa(takenumber(id, 1, 2, 2), 1), '\0'};
	
  String firsthexa_str = String(firsthexa);   
  String secondhexa_str = String(secondhexa);
 
  lcd.setCursor(0, 0);
  lcd.print("First Hex: ");
  lcd.setCursor(0, 1);
  lcd.print(firsthexa_str);
  delay(3000);
  lcd.clear();
  delay(300);
  lcd.setCursor(0, 0);
  lcd.print("Last Hex: ");
  lcd.setCursor(0, 1);
  lcd.print(secondhexa_str);
  delay(3000);
  lcd.clear();
}










