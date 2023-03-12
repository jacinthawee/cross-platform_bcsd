
int DES_key_sched(const_DES_cblock *key,DES_key_schedule *schedule)

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
    if ((((((((iVar1 != 0) && (iVar1 = memcmp(DAT_00078724,key,8), iVar1 != 0)) &&
            (iVar1 = memcmp(DAT_00078728,key,8), iVar1 != 0)) &&
           ((iVar1 = memcmp(DAT_0007872c,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_00078730,key,8), iVar1 != 0)))) &&
          ((iVar1 = memcmp(DAT_00078734,key,8), iVar1 != 0 &&
           ((iVar1 = memcmp(DAT_00078738,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_0007873c,key,8), iVar1 != 0)))))) &&
         (iVar1 = memcmp(DAT_00078740,key,8), iVar1 != 0)) &&
        (((iVar1 = memcmp(DAT_00078744,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_00078748,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_0007874c,key,8), iVar1 != 0)))) &&
       (((iVar1 = memcmp(DAT_00078750,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00078754,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_00078758,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_0007875c,key,8), iVar1 != 0)))))) {
      DES_set_key_unchecked(key,schedule);
      return 0;
    }
    return -2;
  }
  return -1;
}

