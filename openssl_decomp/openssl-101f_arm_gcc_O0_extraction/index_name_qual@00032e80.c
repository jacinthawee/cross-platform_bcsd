
uint index_name_qual(byte **param_1)

{
  uint uVar1;
  
  uVar1 = count_leading_zeroes(**param_1 - 0x56);
  return uVar1 >> 5;
}

