
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
    if ((((((((iVar1 != 0) && (iVar1 = memcmp(DAT_000762d0,key,8), iVar1 != 0)) &&
            (iVar1 = memcmp(DAT_000762d4,key,8), iVar1 != 0)) &&
           ((iVar1 = memcmp(DAT_000762d8,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_000762dc,key,8), iVar1 != 0)))) &&
          ((iVar1 = memcmp(DAT_000762e0,key,8), iVar1 != 0 &&
           ((iVar1 = memcmp(DAT_000762e4,key,8), iVar1 != 0 &&
            (iVar1 = memcmp(DAT_000762e8,key,8), iVar1 != 0)))))) &&
         (iVar1 = memcmp(DAT_000762ec,key,8), iVar1 != 0)) &&
        (((iVar1 = memcmp(DAT_000762f0,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_000762f4,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_000762f8,key,8), iVar1 != 0)))) &&
       (((iVar1 = memcmp(DAT_000762fc,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00076300,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_00076304,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00076308,key,8), iVar1 != 0)))))) {
      DES_set_key_unchecked(key,schedule);
      return 0;
    }
    return -2;
  }
  return -1;
}

