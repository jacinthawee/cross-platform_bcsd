
uint ec_GF2m_simple_is_at_infinity(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = count_leading_zeroes(*(undefined4 *)(param_2 + 0x30));
  return uVar1 >> 5;
}

