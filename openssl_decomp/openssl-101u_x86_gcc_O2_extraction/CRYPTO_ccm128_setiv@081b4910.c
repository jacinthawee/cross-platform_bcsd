
undefined4 CRYPTO_ccm128_setiv(byte *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = -(*param_1 & 7);
  if (param_3 < iVar1 + 0xeU) {
    uVar3 = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = *param_1 & 0xbf;
    param_1[0xc] = (byte)((uint)param_4 >> 0x18);
    param_1[0xd] = (byte)((uint)param_4 >> 0x10);
    param_1[0xe] = (byte)((uint)param_4 >> 8);
    param_1[0xf] = (byte)param_4;
    *(undefined4 *)(param_1 + 1) = *param_2;
    *(undefined4 *)(param_1 + iVar1 + 0xb) = *(undefined4 *)((int)param_2 + iVar1 + 10);
    uVar2 = (uint)(param_1 + (1 - ((uint)(param_1 + 5) & 0xfffffffc)) + iVar1 + 0xeU) & 0xfffffffc;
    if (3 < uVar2) {
      uVar4 = 0;
      do {
        *(undefined4 *)(((uint)(param_1 + 5) & 0xfffffffc) + uVar4) =
             *(undefined4 *)
              ((int)param_2 + (uVar4 - (int)(param_1 + (1 - ((uint)(param_1 + 5) & 0xfffffffc)))));
        uVar4 = uVar4 + 4;
      } while (uVar4 < uVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}

