
undefined4 asn1_bio_new(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x40,"bio_asn1.c",0x99);
  if (puVar1 != (undefined4 *)0x0) {
    pvVar2 = CRYPTO_malloc(0x14,"bio_asn1.c",0xa6);
    puVar1[1] = pvVar2;
    if (pvVar2 != (void *)0x0) {
      puVar1[2] = 0x14;
      puVar1[7] = 4;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[0xc] = 0;
      puVar1[0xe] = 0;
      puVar1[0xd] = 0;
      *puVar1 = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 **)(param_1 + 0x20) = puVar1;
      *(undefined4 *)(param_1 + 0xc) = 1;
      return 1;
    }
  }
  return 0;
}

