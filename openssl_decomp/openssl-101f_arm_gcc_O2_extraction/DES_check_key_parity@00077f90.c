
int DES_check_key_parity(const_DES_cblock *key)

{
  uint uVar1;
  
  if (((((uint)(byte)(&odd_parity)[(*key)[0]] == (uint)(*key)[0]) &&
       ((uint)(byte)(&odd_parity)[(*key)[1]] == (uint)(*key)[1])) &&
      ((uint)(byte)(&odd_parity)[(*key)[2]] == (uint)(*key)[2])) &&
     ((((uint)(byte)(&odd_parity)[(*key)[3]] == (uint)(*key)[3] &&
       ((uint)(byte)(&odd_parity)[(*key)[4]] == (uint)(*key)[4])) &&
      (((uint)(byte)(&odd_parity)[(*key)[5]] == (uint)(*key)[5] &&
       ((uint)(byte)(&odd_parity)[(*key)[6]] == (uint)(*key)[6])))))) {
    uVar1 = count_leading_zeroes((uint)(byte)(&odd_parity)[(*key)[7]] - (uint)(*key)[7]);
    return uVar1 >> 5;
  }
  return 0;
}

