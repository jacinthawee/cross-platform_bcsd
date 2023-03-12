
undefined4 * __regparm3 bn_expand_internal(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  if (0xffffff < param_2) {
    iVar7 = 0x135;
    iVar8 = 0x72;
LAB_080f656f:
    ERR_put_error(3,0x78,iVar8,"bn_lib.c",iVar7);
    return (undefined4 *)0x0;
  }
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    iVar7 = 0x13a;
    iVar8 = 0x69;
    goto LAB_080f656f;
  }
  puVar4 = (undefined4 *)CRYPTO_malloc(param_2 << 2,"bn_lib.c",0x13d);
  if (puVar4 == (undefined4 *)0x0) {
    iVar7 = 0x140;
    iVar8 = 0x41;
    goto LAB_080f656f;
  }
  puVar10 = (undefined4 *)*param_1;
  if (puVar10 == (undefined4 *)0x0) {
    return puVar4;
  }
  uVar6 = param_1[1];
  iVar7 = (int)uVar6 >> 2;
  puVar5 = puVar4;
  iVar8 = iVar7;
  puVar9 = puVar10;
  if (0 < iVar7) {
    do {
      uVar1 = puVar9[2];
      uVar2 = puVar9[3];
      uVar3 = *puVar9;
      puVar5[1] = puVar9[1];
      puVar5[2] = uVar1;
      *puVar5 = uVar3;
      puVar5[3] = uVar2;
      iVar8 = iVar8 + -1;
      puVar5 = puVar5 + 4;
      puVar9 = puVar9 + 4;
    } while (iVar8 != 0);
    puVar10 = puVar10 + iVar7 * 4;
    uVar6 = param_1[1];
    puVar5 = puVar4 + iVar7 * 4;
  }
  uVar6 = uVar6 & 3;
  if (uVar6 != 2) {
    if (uVar6 != 3) {
      if (uVar6 != 1) {
        return puVar4;
      }
      goto LAB_080f654c;
    }
    puVar5[2] = puVar10[2];
  }
  puVar5[1] = puVar10[1];
LAB_080f654c:
  *puVar5 = *puVar10;
  return puVar4;
}

