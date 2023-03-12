
undefined4 pkey_gost_mac_init(EVP_PKEY_CTX *param_1)

{
  undefined4 *data;
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  data = (undefined4 *)CRYPTO_malloc(0x28,"gost_pmeth.c",0x1a8);
  uVar1 = 0;
  if (data != (undefined4 *)0x0) {
    *data = 0;
    data[9] = 0;
    puVar3 = (undefined4 *)((uint)(data + 1) & 0xfffffffc);
    for (uVar2 = (uint)((int)data + (0x28 - (int)(undefined4 *)((uint)(data + 1) & 0xfffffffc))) >>
                 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    EVP_PKEY_CTX_set_data(param_1,data);
    uVar1 = 1;
  }
  return uVar1;
}

