
undefined4 gost_digest_init(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *puVar1 = 0;
  puVar1[0x1b] = 0;
  puVar3 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
  for (uVar2 = (uint)((int)puVar1 + (0x70 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc)))
               >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  gost_init(puVar1 + 0x1c,GostR3411_94_CryptoProParamSet);
  puVar1[2] = puVar1 + 0x1c;
  return 1;
}

