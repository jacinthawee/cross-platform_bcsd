
bool BN_GF2m_mod_sqr_arr(uint **param_1,int *param_2,int *param_3,undefined4 param_4)

{
  uint **ppuVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  bool bVar8;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
  ppuVar1 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
  if (ppuVar1 == (uint **)0x0) {
    return false;
  }
  iVar2 = param_2[1];
  if ((int)ppuVar1[2] < iVar2 << 1) {
    iVar2 = (*(code *)PTR_bn_expand2_006a9680)(ppuVar1);
    if (iVar2 != 0) {
      iVar2 = param_2[1];
      goto LAB_00624918;
    }
LAB_00624ac8:
    bVar8 = false;
  }
  else {
LAB_00624918:
    if (0 < iVar2) {
      puVar7 = *ppuVar1;
      puVar6 = (uint *)(*param_2 + iVar2 * 4);
      puVar5 = puVar7 + iVar2 * 2;
      do {
        uVar3 = puVar6[-1];
        puVar4 = puVar5 + -2;
        puVar6 = puVar6 + -1;
        puVar5[-1] = *(int *)(&SQR_tb + (uVar3 >> 0x1c) * 4) << 0x18 |
                     *(uint *)(&SQR_tb + ((uVar3 << 0xc) >> 0x1c) * 4) |
                     *(int *)(&SQR_tb + ((uVar3 << 4) >> 0x1c) * 4) << 0x10 |
                     *(int *)(&SQR_tb + ((uVar3 << 8) >> 0x1c) * 4) << 8;
        uVar3 = *puVar6;
        *puVar4 = *(int *)(&SQR_tb + ((uVar3 << 0x10) >> 0x1c) * 4) << 0x18 |
                  *(int *)(&SQR_tb + ((uVar3 << 0x14) >> 0x1c) * 4) << 0x10 |
                  *(uint *)(&SQR_tb + (uVar3 & 0xf) * 4) |
                  *(int *)(&SQR_tb + ((uVar3 << 0x18) >> 0x1c) * 4) << 8;
        puVar5 = puVar4;
      } while (puVar7 != puVar4);
      iVar2 = param_2[1];
    }
    puVar5 = (uint *)(iVar2 << 1);
    ppuVar1[1] = puVar5;
    if (0 < (int)puVar5) {
      puVar6 = *ppuVar1 + iVar2 * 2 + -2;
      do {
        if (puVar6[1] != 0) break;
        puVar5 = (uint *)((int)puVar5 + -1);
        puVar6 = puVar6 + -1;
      } while (puVar5 != (uint *)0x0);
      ppuVar1[1] = puVar5;
    }
    if (*param_3 == 0) {
      bVar8 = true;
      (*(code *)PTR_BN_set_word_006a8820)(param_1,0);
      goto LAB_00624acc;
    }
    if (ppuVar1 != param_1) {
      if ((int)param_1[2] < (int)puVar5) {
        iVar2 = (*(code *)PTR_bn_expand2_006a9680)(param_1);
        if (iVar2 == 0) goto LAB_00624ac8;
        puVar5 = ppuVar1[1];
      }
      iVar2 = 0;
      if (0 < (int)puVar5) {
        puVar7 = *ppuVar1;
        puVar6 = *param_1;
        do {
          iVar2 = iVar2 + 1;
          *puVar6 = *puVar7;
          puVar5 = ppuVar1[1];
          puVar7 = puVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar2 < (int)puVar5);
      }
      param_1[1] = puVar5;
    }
    iVar2 = BN_GF2m_mod_arr_part_0(param_1,param_3);
    bVar8 = iVar2 != 0;
  }
LAB_00624acc:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  return bVar8;
}

