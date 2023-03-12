
int BN_GF2m_mod_div(undefined4 param_1,undefined4 param_2,undefined4 param_3,BIGNUM *param_4,
                   BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  void *ptr;
  ulong *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  if ((pBVar1 == (BIGNUM *)0x0) ||
     (iVar2 = BN_GF2m_mod_inv(pBVar1,param_3,param_4,param_5), iVar2 == 0)) {
LAB_0011eebe:
    BN_CTX_end(param_5);
    return 0;
  }
  iVar2 = BN_num_bits(param_4);
  iVar2 = iVar2 + 1;
  ptr = CRYPTO_malloc(iVar2 * 4,"bn_gf2m.c",0x22a);
  if (ptr == (void *)0x0) goto LAB_0011eebe;
  iVar6 = param_4->top;
  if (iVar6 != 0) {
    iVar4 = iVar6 + -1;
    if (iVar4 < 0) {
      iVar9 = 0;
    }
    else {
      iVar5 = iVar4 * 0x20 + -1;
      iVar9 = 0;
      puVar3 = param_4->d + iVar6;
      do {
        puVar3 = puVar3 + -1;
        uVar8 = *puVar3;
        if (uVar8 != 0) {
          iVar6 = iVar5 + 0x20;
          uVar7 = 0x80000000;
          while( true ) {
            uVar8 = uVar8 & uVar7;
            uVar7 = uVar7 >> 1;
            if (uVar8 != 0) {
              if (iVar9 < iVar2) {
                *(int *)((int)ptr + iVar9 * 4) = iVar6;
              }
              iVar9 = iVar9 + 1;
            }
            iVar6 = iVar6 + -1;
            if (iVar5 == iVar6) break;
            uVar8 = *puVar3;
          }
        }
        iVar5 = iVar5 + -0x20;
        bVar10 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar10);
    }
    iVar6 = iVar9;
    if (iVar9 < iVar2) {
      *(undefined4 *)((int)ptr + iVar9 * 4) = 0xffffffff;
      iVar6 = iVar9 + 1;
    }
    uVar8 = count_leading_zeroes(iVar6);
    uVar8 = uVar8 >> 5;
    if (iVar2 < iVar6) {
      uVar8 = uVar8 | 1;
    }
    if (uVar8 == 0) {
      iVar6 = BN_GF2m_mod_mul_arr(param_1,param_2,pBVar1,ptr,param_5);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
      goto LAB_0011ef7a;
    }
    if (iVar6 != 0) {
      iVar6 = 1;
    }
  }
  ERR_put_error(3,0x85,0x6a,"bn_gf2m.c",0x22e);
LAB_0011ef7a:
  CRYPTO_free(ptr);
  BN_CTX_end(param_5);
  return iVar6;
}

