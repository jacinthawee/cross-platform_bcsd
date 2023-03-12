
undefined4 BN_GF2m_add(uint **param_1,uint **param_2,uint **param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint **ppuVar6;
  
  puVar2 = param_2[1];
  puVar5 = param_3[1];
  puVar4 = puVar2;
  ppuVar6 = param_3;
  if ((int)puVar5 <= (int)puVar2) {
    puVar4 = puVar5;
    puVar5 = puVar2;
    ppuVar6 = param_2;
    param_2 = param_3;
  }
  if ((int)param_1[2] < (int)puVar5) {
    iVar1 = (*(code *)PTR_bn_expand2_006a9680)(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    puVar4 = param_2[1];
  }
  iVar1 = 0;
  if (0 < (int)puVar4) {
    puVar2 = *ppuVar6;
    puVar5 = *param_2;
    puVar4 = *param_1;
    do {
      uVar3 = *puVar2;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
      *puVar4 = uVar3 ^ *puVar5;
      puVar5 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar1 < (int)param_2[1]);
  }
  puVar4 = ppuVar6[1];
  if (iVar1 < (int)puVar4) {
    puVar2 = *ppuVar6 + iVar1;
    puVar5 = *param_1 + iVar1;
    do {
      iVar1 = iVar1 + 1;
      *puVar5 = *puVar2;
      puVar4 = ppuVar6[1];
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar1 < (int)puVar4);
  }
  param_1[1] = puVar4;
  if ((int)puVar4 < 1) {
    return 1;
  }
  puVar5 = *param_1 + (int)puVar4 + -2;
  do {
    if (puVar5[1] != 0) break;
    puVar4 = (uint *)((int)puVar4 + -1);
    puVar5 = puVar5 + -1;
  } while (puVar4 != (uint *)0x0);
  param_1[1] = puVar4;
  return 1;
}

