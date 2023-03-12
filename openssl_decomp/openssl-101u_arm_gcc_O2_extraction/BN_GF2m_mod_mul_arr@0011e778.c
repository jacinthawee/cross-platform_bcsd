
int BN_GF2m_mod_mul_arr(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,
                       BN_CTX *param_5)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  if (param_2 == param_3) {
    iVar6 = BN_GF2m_mod_sqr_arr(param_1,param_2,param_4,param_5);
    return iVar6;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  if ((a == (BIGNUM *)0x0) ||
     ((iVar6 = param_3[1] + param_2[1] + 4, a->dmax < iVar6 &&
      (pBVar1 = bn_expand2(a,iVar6), pBVar1 == (BIGNUM *)0x0)))) {
    iVar6 = 0;
  }
  else {
    a->top = iVar6;
    if (0 < iVar6) {
      memset(a->d,0,iVar6 * 4);
    }
    iVar6 = param_3[1];
    if (0 < iVar6) {
      iVar4 = param_2[1];
      iVar11 = 0;
      do {
        uVar9 = *(undefined4 *)(*param_3 + iVar11 * 4);
        if (iVar11 + 1 == iVar6) {
          uVar10 = 0;
        }
        else {
          uVar10 = *(undefined4 *)(*param_3 + iVar11 * 4 + 4);
        }
        if (0 < iVar4) {
          iVar8 = 1;
          iVar7 = 0;
          iVar6 = iVar11 * 4;
          do {
            iVar3 = iVar7 * 4;
            if (iVar4 == iVar8) {
              uVar2 = 0;
            }
            else {
              uVar2 = *(undefined4 *)(*param_2 + iVar8 * 4);
            }
            iVar7 = iVar7 + 2;
            iVar8 = iVar8 + 2;
            bn_GF2m_mul_2x2(&local_38,uVar2,*(undefined4 *)(*param_2 + iVar3),uVar10,uVar9);
            puVar5 = a->d;
            iVar3 = iVar6 + 8;
            *(uint *)((int)puVar5 + iVar6) = local_38 ^ *(uint *)((int)puVar5 + iVar6);
            *(uint *)((int)puVar5 + iVar6 + 4) = local_34 ^ *(uint *)((int)puVar5 + iVar6 + 4);
            *(uint *)((int)puVar5 + iVar3) = local_30 ^ *(uint *)((int)puVar5 + iVar3);
            *(uint *)((int)puVar5 + iVar6 + 0xc) = local_2c ^ *(uint *)((int)puVar5 + iVar6 + 0xc);
            iVar4 = param_2[1];
            iVar6 = iVar3;
          } while (iVar7 < iVar4);
          iVar6 = param_3[1];
        }
        iVar11 = iVar11 + 2;
      } while (iVar11 < iVar6);
    }
    iVar6 = a->top;
    if (0 < iVar6) {
      puVar5 = a->d + iVar6 + 0x3fffffff;
      do {
        if (*puVar5 != 0) break;
        iVar6 = iVar6 + -1;
        puVar5 = puVar5 + -1;
      } while (iVar6 != 0);
      a->top = iVar6;
    }
    iVar6 = BN_GF2m_mod_arr(param_1,a,param_4);
    if (iVar6 != 0) {
      iVar6 = 1;
    }
  }
  BN_CTX_end(param_5);
  return iVar6;
}

