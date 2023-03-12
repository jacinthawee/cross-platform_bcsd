
int BN_GF2m_mod_sqr_arr(undefined4 param_1,int *param_2,undefined4 param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  uint *puVar6;
  uint uVar7;
  bool bVar8;
  BN_CTX *pBVar9;
  
  pBVar9 = param_4;
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if (a == (BIGNUM *)0x0) {
    return 0;
  }
  iVar4 = a->dmax;
  iVar2 = param_2[1] * 2;
  bVar8 = iVar2 - iVar4 != 0;
  iVar3 = iVar2;
  if (!bVar8 || iVar2 < iVar4) {
    iVar3 = param_2[1];
  }
  if (bVar8 && iVar4 <= iVar2) {
    pBVar1 = bn_expand2(a,iVar3);
    if (pBVar1 == (BIGNUM *)0x0) {
      BN_CTX_end(param_4);
      return 0;
    }
    iVar3 = param_2[1];
  }
  iVar2 = iVar3 + -1;
  if (-1 < iVar2) {
    puVar5 = a->d + iVar3 * 2;
    puVar6 = (uint *)(*param_2 + iVar3 * 4);
    do {
      uVar7 = puVar6[-1];
      iVar2 = iVar2 + -1;
      puVar5[-1] = *(uint *)(&SQR_tb + ((uVar7 << 0xc) >> 0x1c) * 4) |
                   *(int *)(&SQR_tb + (uVar7 >> 0x1c) * 4) << 0x18 |
                   *(int *)(&SQR_tb + ((uVar7 << 4) >> 0x1c) * 4) << 0x10 |
                   *(int *)(&SQR_tb + ((uVar7 << 8) >> 0x1c) * 4) << 8;
      puVar6 = puVar6 + -1;
      uVar7 = *puVar6;
      puVar5 = puVar5 + -2;
      *puVar5 = *(uint *)(&SQR_tb + (uVar7 & 0xf) * 4) |
                *(int *)(&SQR_tb + ((uVar7 << 0x14) >> 0x1c) * 4) << 0x10 |
                *(int *)(&SQR_tb + ((uVar7 << 0x10) >> 0x1c) * 4) << 0x18 |
                *(int *)(&SQR_tb + ((uVar7 << 0x18) >> 0x1c) * 4) << 8;
    } while (iVar2 != -1);
    iVar3 = param_2[1];
  }
  iVar3 = iVar3 * 2;
  a->top = iVar3;
  if (0 < iVar3) {
    puVar5 = a->d + iVar3 + 0x3fffffff;
    do {
      if (*puVar5 != 0) break;
      iVar3 = iVar3 + -1;
      puVar5 = puVar5 + -1;
    } while (iVar3 != 0);
    a->top = iVar3;
  }
  iVar3 = BN_GF2m_mod_arr(param_1,a,param_3,iVar3,pBVar9);
  if (iVar3 != 0) {
    iVar3 = 1;
  }
  BN_CTX_end(param_4);
  return iVar3;
}

