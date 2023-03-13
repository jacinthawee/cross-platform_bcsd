
bool BN_GF2m_mod_sqr_arr(BIGNUM *param_1,int *param_2,int *param_3,BN_CTX *param_4)

{
  ulong *puVar1;
  uint uVar2;
  ulong *puVar3;
  BIGNUM *a;
  int iVar4;
  BIGNUM *pBVar5;
  int iVar6;
  bool bVar7;
  
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if (a == (BIGNUM *)0x0) {
LAB_081e0139:
    bVar7 = false;
  }
  else {
    iVar4 = param_2[1];
    if (a->dmax < iVar4 * 2) {
      pBVar5 = bn_expand2(a,iVar4 * 2);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_081e0139;
      iVar4 = param_2[1];
    }
    iVar6 = iVar4 + -1;
    if (-1 < iVar6) {
      puVar1 = a->d;
      iVar4 = *param_2;
      do {
        uVar2 = *(uint *)(iVar4 + iVar6 * 4);
        puVar1[iVar6 * 2 + 1] =
             *(int *)(SQR_tb + (uVar2 >> 0x18 & 0xf) * 4) << 0x10 |
             *(int *)(SQR_tb + (uVar2 >> 0x1c) * 4) << 0x18 |
             *(uint *)(SQR_tb + (uVar2 >> 0x10 & 0xf) * 4) |
             *(int *)(SQR_tb + (uVar2 >> 0x14 & 0xf) * 4) << 8;
        uVar2 = *(uint *)(iVar4 + iVar6 * 4);
        puVar1[iVar6 * 2] =
             *(int *)(SQR_tb + (uVar2 >> 8 & 0xf) * 4) << 0x10 |
             *(int *)(SQR_tb + (uVar2 >> 0xc & 0xf) * 4) << 0x18 |
             *(uint *)(SQR_tb + (uVar2 & 0xf) * 4) | *(int *)(SQR_tb + (uVar2 >> 4 & 0xf) * 4) << 8;
        iVar6 = iVar6 + -1;
      } while (iVar6 != -1);
      iVar4 = param_2[1];
    }
    iVar4 = iVar4 * 2;
    a->top = iVar4;
    if (0 < iVar4) {
      do {
        if (a->d[iVar4 + -1] != 0) break;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      a->top = iVar4;
    }
    if (*param_3 == 0) {
      bVar7 = true;
      BN_set_word(param_1,0);
      goto LAB_081e010b;
    }
    if (a != param_1) {
      if (param_1->dmax < iVar4) {
        pBVar5 = bn_expand2(param_1,iVar4);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_081e0139;
        iVar4 = a->top;
      }
      if (0 < iVar4) {
        puVar1 = a->d;
        iVar6 = 0;
        puVar3 = param_1->d;
        do {
          puVar3[iVar6] = puVar1[iVar6];
          iVar4 = a->top;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
      param_1->top = iVar4;
    }
    iVar4 = BN_GF2m_mod_arr_part_0();
    bVar7 = iVar4 != 0;
  }
LAB_081e010b:
  BN_CTX_end(param_4);
  return bVar7;
}

