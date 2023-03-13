
uint CRYPTO_ccm128_tag(byte *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = (*param_1 >> 3 & 7) * 2;
  uVar1 = iVar2 + 2;
  if (uVar1 <= param_3) {
    if (uVar1 < 4) {
      if ((uVar1 != 0) && (*(byte *)param_2 = param_1[0x10], (uVar1 & 2) != 0)) {
        *(undefined2 *)((int)param_2 + iVar2) = *(undefined2 *)(param_1 + iVar2 + 0x10);
      }
    }
    else {
      *param_2 = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)((int)param_2 + iVar2 + -2) = *(undefined4 *)(param_1 + iVar2 + 0xe);
      iVar2 = (int)param_2 - ((uint)(param_2 + 1) & 0xfffffffc);
      uVar3 = iVar2 + uVar1 & 0xfffffffc;
      if (3 < uVar3) {
        uVar4 = 0;
        do {
          *(undefined4 *)(((uint)(param_2 + 1) & 0xfffffffc) + uVar4) =
               *(undefined4 *)(param_1 + uVar4 + (0x10 - iVar2));
          uVar4 = uVar4 + 4;
        } while (uVar4 < uVar3);
      }
    }
    return uVar1;
  }
  return 0;
}

