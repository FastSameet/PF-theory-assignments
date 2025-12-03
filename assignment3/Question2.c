#include <stdio.h>
void calculatefuel(int fuel,int nplanets,int solarbonus,int planet,int consumption,int gravitationalrecharge)
{
  if (planet==nplanets || fuel==0)
  {
    if (fuel==0)
    {
        printf("This amount of fuel is insufficient for this journey!!\n");
    }
    else
    printf("Journey successfull\n");
    
    return;
  }
  fuel-=consumption;
  if (planet%4==0)
  {
    fuel+=solarbonus;
  }
  if (planet%5==0)
  {
    fuel+=gravitationalrecharge;
  }
  printf("Planet=%d  Fuel Remaining=%d\n",planet,fuel);

  return calculatefuel(fuel,nplanets,solarbonus,planet+1,consumption,gravitationalrecharge);
}
int main()
{
 int fuel;
 int solarbonus=30;
 int nplanets;
 int consumption=20;
 int planet=0;
 int gravitationalrecharge=10;
 printf("Enter the amount of fuel:\n");
 scanf("%d",&fuel);
 printf("Enter the number of planets:\n");
 scanf("%d",&nplanets);

printf("current planet = X  remaining Fuel=%d\n",fuel);
calculatefuel(fuel,nplanets,solarbonus,planet+1,consumption,gravitationalrecharge);
    return 0;
}
