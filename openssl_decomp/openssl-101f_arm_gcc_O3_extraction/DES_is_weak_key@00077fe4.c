
int DES_is_weak_key(const_DES_cblock *key)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = memcmp(PTR_weak_keys_000780c0,key,8);
  if (((((iVar1 != 0) && (iVar1 = memcmp(DAT_000780c4,key,8), iVar1 != 0)) &&
       (iVar1 = memcmp(DAT_000780c8,key,8), iVar1 != 0)) &&
      (((iVar1 = memcmp(DAT_000780cc,key,8), iVar1 != 0 &&
        (iVar1 = memcmp(DAT_000780d0,key,8), iVar1 != 0)) &&
       ((iVar1 = memcmp(DAT_000780d4,key,8), iVar1 != 0 &&
        ((iVar1 = memcmp(DAT_000780d8,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_000780dc,key,8), iVar1 != 0)))))))) &&
     ((iVar1 = memcmp(DAT_000780e0,key,8), iVar1 != 0 &&
      (((((iVar1 = memcmp(DAT_000780e4,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_000780e8,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_000780ec,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_000780f0,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_000780f4,key,8), iVar1 != 0)))) &&
       (iVar1 = memcmp(DAT_000780f8,key,8), iVar1 != 0)))))) {
    iVar1 = memcmp(DAT_000780fc,key,8);
    uVar2 = count_leading_zeroes(iVar1);
    return uVar2 >> 5;
  }
  return 1;
}

