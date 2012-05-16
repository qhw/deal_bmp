#include "stdafx.h"
int IntPow( int base, int exponent )
{
  int i;
  int output = 1;
  for( i=0 ; i < exponent ; i++ )
  { output *= base; }
  return output;
}