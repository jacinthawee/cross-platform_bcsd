
undefined4 pkey_gost_mac_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  byte bVar5;
  
  bVar5 = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x28,"gost_pmeth.c",0x1a8);
  uVar2 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[9] = 0;
    puVar3 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    for (uVar4 = (uint)((int)puVar1 + (0x28 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc)))
                 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
    }
    EVP_PKEY_CTX_set_data(param_1,puVar1);
    puVar1 = (undefined4 *)EVP_PKEY_CTX_get_data(param_2);
    puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
    *puVar3 = *puVar1;
    puVar3[1] = puVar1[1];
    puVar3[2] = puVar1[2];
    puVar3[3] = puVar1[3];
    puVar3[4] = puVar1[4];
    puVar3[5] = puVar1[5];
    puVar3[6] = puVar1[6];
    puVar3[7] = puVar1[7];
    puVar3[8] = puVar1[8];
    puVar3[9] = puVar1[9];
    uVar2 = 1;
  }
  return uVar2;
}

