
undefined4 asn1_bio_new(int param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  ptr = (undefined4 *)CRYPTO_malloc(0x40,"bio_asn1.c",0x95);
  if (ptr != (undefined4 *)0x0) {
    pvVar1 = CRYPTO_malloc(0x14,"bio_asn1.c",0xa4);
    ptr[1] = pvVar1;
    if (pvVar1 == (void *)0x0) {
      CRYPTO_free(ptr);
      return 0;
    }
    ptr[2] = 0x14;
    ptr[3] = 0;
    uVar2 = 1;
    ptr[4] = 0;
    ptr[5] = 0;
    ptr[6] = 0;
    ptr[7] = 4;
    ptr[0xc] = 0;
    ptr[0xe] = 0;
    ptr[0xd] = 0;
    *ptr = 0;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 **)(param_1 + 0x20) = ptr;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return uVar2;
}
