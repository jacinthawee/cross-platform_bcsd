
undefined4 ssl3_new(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x424,"s3_lib.c",0xbb1);
  uVar2 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[0x108] = 0;
    puVar4 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    for (uVar3 = (uint)((int)puVar1 + (0x424 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc))
                       ) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    puVar1[0x4a] = 0;
    puVar1[0x4b] = 0;
    puVar1[0x53] = 0;
    puVar1[0x54] = 0;
    *(undefined4 **)(param_1 + 0x58) = puVar1;
    SSL_SRP_CTX_init(param_1);
    (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
    uVar2 = 1;
  }
  return uVar2;
}

