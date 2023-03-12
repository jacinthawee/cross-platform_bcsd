
int DES_is_weak_key(const_DES_cblock *key)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = memcmp(PTR_weak_keys_00075dfc,key,8);
  if (((((iVar1 != 0) && (iVar1 = memcmp(DAT_00075e00,key,8), iVar1 != 0)) &&
       (iVar1 = memcmp(DAT_00075e04,key,8), iVar1 != 0)) &&
      (((iVar1 = memcmp(DAT_00075e08,key,8), iVar1 != 0 &&
        (iVar1 = memcmp(DAT_00075e0c,key,8), iVar1 != 0)) &&
       ((iVar1 = memcmp(DAT_00075e10,key,8), iVar1 != 0 &&
        ((iVar1 = memcmp(DAT_00075e14,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00075e18,key,8), iVar1 != 0)))))))) &&
     ((iVar1 = memcmp(DAT_00075e1c,key,8), iVar1 != 0 &&
      (((((iVar1 = memcmp(DAT_00075e20,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_00075e24,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_00075e28,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_00075e2c,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00075e30,key,8), iVar1 != 0)))) &&
       (iVar1 = memcmp(DAT_00075e34,key,8), iVar1 != 0)))))) {
    iVar1 = memcmp(DAT_00075e38,key,8);
    uVar2 = count_leading_zeroes(iVar1);
    return uVar2 >> 5;
  }
  return 1;
}

