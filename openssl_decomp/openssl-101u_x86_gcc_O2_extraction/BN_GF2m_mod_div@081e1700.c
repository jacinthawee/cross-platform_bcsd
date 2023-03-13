
uint BN_GF2m_mod_div(undefined4 param_1,undefined4 param_2,undefined4 param_3,BIGNUM *param_4,
                    BN_CTX *param_5)

{
  ulong *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  void *ptr;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  BN_CTX_start(param_5);
  pBVar2 = BN_CTX_get(param_5);
  if ((pBVar2 == (BIGNUM *)0x0) ||
     (iVar3 = BN_GF2m_mod_inv(pBVar2,param_3,param_4,param_5), iVar3 == 0)) {
    uVar7 = 0;
    goto LAB_081e1744;
  }
  uVar7 = 0;
  iVar3 = BN_num_bits(param_4);
  iVar3 = iVar3 + 1;
  ptr = CRYPTO_malloc(iVar3 * 4,"bn_gf2m.c",0x22a);
  if (ptr == (void *)0x0) goto LAB_081e1744;
  uVar7 = param_4->top;
  if (uVar7 == 0) {
LAB_081e186a:
    ERR_put_error(3,0x85,0x6a,"bn_gf2m.c",0x22e);
  }
  else {
    iVar8 = uVar7 - 1;
    if (iVar8 < 0) {
      iVar8 = 0;
      uVar7 = 0;
      iVar9 = 1;
      if (0 < iVar3) goto LAB_081e180c;
      goto LAB_081e186a;
    }
    puVar1 = param_4->d;
    iVar6 = 0;
    iVar9 = iVar8 * 0x20 + -1;
    do {
      uVar7 = puVar1[iVar8];
      if (uVar7 != 0) {
        iVar4 = iVar9 + 0x20;
        uVar5 = 0x80000000;
        while( true ) {
          if ((uVar5 & uVar7) != 0) {
            if (iVar6 < iVar3) {
              *(int *)((int)ptr + iVar6 * 4) = iVar4;
            }
            iVar6 = iVar6 + 1;
          }
          iVar4 = iVar4 + -1;
          uVar5 = uVar5 >> 1;
          if (iVar4 == iVar9) break;
          uVar7 = puVar1[iVar8];
        }
      }
      iVar8 = iVar8 + -1;
      iVar9 = iVar9 + -0x20;
    } while (iVar8 != -1);
    iVar8 = iVar6 * 4;
    iVar9 = iVar6 + 1;
    if (iVar6 < iVar3) {
LAB_081e180c:
      iVar6 = iVar9;
      *(undefined4 *)((int)ptr + iVar8) = 0xffffffff;
      bVar10 = false;
    }
    else {
      bVar10 = iVar6 == 0;
    }
    if ((iVar3 < iVar6) || (bVar10)) {
      uVar7 = (uint)(iVar6 != 0);
      goto LAB_081e186a;
    }
    iVar3 = BN_GF2m_mod_mul_arr(param_1,param_2,pBVar2,ptr,param_5);
    uVar7 = (uint)(iVar3 != 0);
  }
  CRYPTO_free(ptr);
LAB_081e1744:
  BN_CTX_end(param_5);
  return uVar7;
}

