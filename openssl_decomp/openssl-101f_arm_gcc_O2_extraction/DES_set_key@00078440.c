
int DES_set_key(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if (_shadow_DES_check_key == 0) {
    DES_set_key_unchecked(key,schedule);
    return 0;
  }
  if (((((uint)(byte)(&odd_parity)[(*key)[0]] == (uint)(*key)[0]) &&
       ((uint)(byte)(&odd_parity)[(*key)[1]] == (uint)(*key)[1])) &&
      ((uint)(byte)(&odd_parity)[(*key)[2]] == (uint)(*key)[2])) &&
     ((((uint)(byte)(&odd_parity)[(*key)[3]] == (uint)(*key)[3] &&
       ((uint)(byte)(&odd_parity)[(*key)[4]] == (uint)(*key)[4])) &&
      (((uint)(byte)(&odd_parity)[(*key)[5]] == (uint)(*key)[5] &&
       (((uint)(byte)(&odd_parity)[(*key)[6]] == (uint)(*key)[6] &&
        ((uint)(byte)(&odd_parity)[(*key)[7]] == (uint)(*key)[7])))))))) {
    iVar1 = memcmp(weak_keys,key,8);
    if ((((((((iVar1 != 0) && (iVar1 = memcmp(DAT_00078594,key,8), iVar1 != 0)) &&
            (iVar1 = memcmp(DAT_00078598,key,8), iVar1 != 0)) &&
           ((iVar1 = memcmp(DAT_0007859c,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_000785a0,key,8), iVar1 != 0)))) &&
          ((iVar1 = memcmp(DAT_000785a4,key,8), iVar1 != 0 &&
           ((iVar1 = memcmp(DAT_000785a8,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_000785ac,key,8), iVar1 != 0)))))) &&
         (iVar1 = memcmp(DAT_000785b0,key,8), iVar1 != 0)) &&
        (((iVar1 = memcmp(DAT_000785b4,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_000785b8,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_000785bc,key,8), iVar1 != 0)))) &&
       (((iVar1 = memcmp(DAT_000785c0,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_000785c4,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_000785c8,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_000785cc,key,8), iVar1 != 0)))))) {
      DES_set_key_unchecked(key,schedule);
      return 0;
    }
    return -2;
  }
  return -1;
}

