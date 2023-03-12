
undefined4 * bn_expand_internal(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  
  if (0xffffff < param_2) {
    uVar7 = 0x72;
    uVar6 = 0x128;
LAB_004f2bb4:
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x78,uVar7,"bn_lib.c",uVar6);
    return (undefined4 *)0x0;
  }
  if ((param_1[4] & 2) != 0) {
    uVar7 = 0x69;
    uVar6 = 300;
    goto LAB_004f2bb4;
  }
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(param_2 << 2,"bn_lib.c",0x12f);
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x78,0x41,"bn_lib.c",0x131);
    return (undefined4 *)0x0;
  }
  puVar10 = (undefined4 *)*param_1;
  if (puVar10 == (undefined4 *)0x0) {
    return puVar1;
  }
  uVar2 = param_1[1];
  iVar9 = (int)uVar2 >> 2;
  puVar3 = puVar1;
  puVar4 = puVar10;
  iVar5 = iVar9;
  if (0 < iVar9) {
    do {
      uVar8 = puVar4[1];
      uVar7 = puVar4[2];
      iVar5 = iVar5 + -1;
      uVar6 = puVar4[3];
      *puVar3 = *puVar4;
      puVar3[1] = uVar8;
      puVar3[2] = uVar7;
      puVar3[3] = uVar6;
      puVar3 = puVar3 + 4;
      puVar4 = puVar4 + 4;
    } while (iVar5 != 0);
    uVar2 = param_1[1];
    puVar10 = puVar10 + iVar9 * 4;
    puVar3 = puVar1 + iVar9 * 4;
  }
  uVar2 = uVar2 & 3;
  if (uVar2 != 2) {
    if (uVar2 != 3) {
      if (uVar2 != 1) {
        return puVar1;
      }
      goto LAB_004f2b84;
    }
    puVar3[2] = puVar10[2];
  }
  puVar3[1] = puVar10[1];
LAB_004f2b84:
  *puVar3 = *puVar10;
  return puVar1;
}

