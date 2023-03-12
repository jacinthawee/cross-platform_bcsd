
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
  
  (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
  ppuVar1 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_4);
  if (ppuVar1 == (uint **)0x0) {
LAB_006240cc:
    bVar8 = false;
  }
  else {
    iVar2 = param_2[1];
    puVar4 = (uint *)(iVar2 << 1);
    if ((int)ppuVar1[2] < (int)puVar4) {
      iVar2 = (*(code *)PTR_bn_expand2_006a8524)(ppuVar1);
      if (iVar2 == 0) goto LAB_006240cc;
      iVar2 = param_2[1];
      puVar4 = (uint *)(iVar2 << 1);
    }
    if (0 < iVar2) {
      puVar7 = *ppuVar1;
      puVar6 = (uint *)(*param_2 + iVar2 * 4);
      puVar4 = puVar7 + iVar2 * 2;
      do {
        uVar3 = puVar6[-1];
        puVar5 = puVar4 + -2;
        puVar6 = puVar6 + -1;
        puVar4[-1] = *(int *)(&SQR_tb + (uVar3 >> 0x1c) * 4) << 0x18 |
                     *(uint *)(&SQR_tb + ((uVar3 << 0xc) >> 0x1c) * 4) |
                     *(int *)(&SQR_tb + ((uVar3 << 4) >> 0x1c) * 4) << 0x10 |
                     *(int *)(&SQR_tb + ((uVar3 << 8) >> 0x1c) * 4) << 8;
        uVar3 = *puVar6;
        *puVar5 = *(int *)(&SQR_tb + ((uVar3 << 0x10) >> 0x1c) * 4) << 0x18 |
                  *(int *)(&SQR_tb + ((uVar3 << 0x14) >> 0x1c) * 4) << 0x10 |
                  *(uint *)(&SQR_tb + (uVar3 & 0xf) * 4) |
                  *(int *)(&SQR_tb + ((uVar3 << 0x18) >> 0x1c) * 4) << 8;
        puVar4 = puVar5;
      } while (puVar7 != puVar5);
      puVar4 = (uint *)(param_2[1] << 1);
    }
    ppuVar1[1] = puVar4;
    if (0 < (int)puVar4) {
      puVar6 = *ppuVar1 + (int)puVar4 + -2;
      do {
        if (puVar6[1] != 0) break;
        puVar4 = (uint *)((int)puVar4 + -1);
        puVar6 = puVar6 + -1;
      } while (puVar4 != (uint *)0x0);
      ppuVar1[1] = puVar4;
    }
    if (*param_3 == 0) {
      bVar8 = true;
      (*(code *)PTR_BN_set_word_006a7730)(param_1,0);
      goto LAB_006240d0;
    }
    if (ppuVar1 != param_1) {
      if ((int)param_1[2] < (int)puVar4) {
        iVar2 = (*(code *)PTR_bn_expand2_006a8524)(param_1);
        if (iVar2 == 0) goto LAB_006240cc;
        puVar4 = ppuVar1[1];
      }
      iVar2 = 0;
      if (0 < (int)puVar4) {
        puVar7 = *ppuVar1;
        puVar6 = *param_1;
        do {
          iVar2 = iVar2 + 1;
          *puVar6 = *puVar7;
          puVar4 = ppuVar1[1];
          puVar7 = puVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar2 < (int)puVar4);
      }
      param_1[1] = puVar4;
    }
    iVar2 = BN_GF2m_mod_arr_part_0(param_1,param_3);
    bVar8 = iVar2 != 0;
  }
LAB_006240d0:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  return bVar8;
}

