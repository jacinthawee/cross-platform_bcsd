
undefined4 BN_GF2m_mod(BIGNUM *param_1,BIGNUM *param_2,int *param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  BIGNUM *pBVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int in_GS_OFFSET;
  int local_38 [6];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3[1] == 0) {
LAB_081dfc82:
    ERR_put_error(3,0x83,0x6a,"bn_gf2m.c",0x176);
    uVar6 = 0;
    goto LAB_081dfc68;
  }
  iVar11 = param_3[1] + -1;
  if (iVar11 < 0) {
    piVar4 = local_38;
LAB_081dfc09:
    *piVar4 = -1;
  }
  else {
    iVar5 = *param_3;
    iVar10 = 0;
    iVar12 = iVar11 * 0x20 + -1;
    do {
      uVar8 = *(uint *)(iVar5 + iVar11 * 4);
      if (uVar8 != 0) {
        iVar3 = iVar12 + 0x20;
        uVar9 = 0x80000000;
        while( true ) {
          if ((uVar9 & uVar8) != 0) {
            if (iVar10 < 6) {
              local_38[iVar10] = iVar3;
            }
            iVar10 = iVar10 + 1;
          }
          iVar3 = iVar3 + -1;
          uVar9 = uVar9 >> 1;
          if (iVar3 == iVar12) break;
          uVar8 = *(uint *)(iVar5 + iVar11 * 4);
        }
      }
      iVar11 = iVar11 + -1;
      iVar12 = iVar12 + -0x20;
    } while (iVar11 != -1);
    piVar4 = local_38 + iVar10;
    if (iVar10 < 6) goto LAB_081dfc09;
    if (6 < iVar10) goto LAB_081dfc82;
  }
  if (local_38[0] == 0) {
    BN_set_word(param_1,0);
    uVar6 = 1;
  }
  else {
    if (param_1 != param_2) {
      iVar11 = param_2->top;
      if (param_1->dmax < iVar11) {
        pBVar7 = bn_expand2(param_1,iVar11);
        if (pBVar7 == (BIGNUM *)0x0) {
          uVar6 = 0;
          goto LAB_081dfc68;
        }
        iVar11 = param_2->top;
      }
      if (0 < iVar11) {
        puVar1 = param_2->d;
        puVar2 = param_1->d;
        iVar5 = 0;
        do {
          puVar2[iVar5] = puVar1[iVar5];
          iVar11 = param_2->top;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar11);
      }
      param_1->top = iVar11;
    }
    uVar6 = BN_GF2m_mod_arr_part_0();
  }
LAB_081dfc68:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

