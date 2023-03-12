
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
    if ((((((((iVar1 != 0) && (iVar1 = memcmp(DAT_00076460,key,8), iVar1 != 0)) &&
            (iVar1 = memcmp(DAT_00076464,key,8), iVar1 != 0)) &&
           ((iVar1 = memcmp(DAT_00076468,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_0007646c,key,8), iVar1 != 0)))) &&
          ((iVar1 = memcmp(DAT_00076470,key,8), iVar1 != 0 &&
           ((iVar1 = memcmp(DAT_00076474,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_00076478,key,8), iVar1 != 0)))))) &&
         (iVar1 = memcmp(DAT_0007647c,key,8), iVar1 != 0)) &&
        (((iVar1 = memcmp(DAT_00076480,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_00076484,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_00076488,key,8), iVar1 != 0)))) &&
       (((iVar1 = memcmp(DAT_0007648c,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00076490,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_00076494,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00076498,key,8), iVar1 != 0)))))) {
      DES_set_key_unchecked(key,schedule);
      return 0;
    }
    return -2;
  }
  return -1;
}

