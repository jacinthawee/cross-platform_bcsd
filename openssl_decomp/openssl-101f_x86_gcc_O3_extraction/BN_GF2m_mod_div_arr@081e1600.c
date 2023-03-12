
uint BN_GF2m_mod_div_arr(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                        BN_CTX *param_5)

{
  ulong *puVar1;
  BIGNUM *a;
  int iVar2;
  BIGNUM *pBVar3;
  void *ptr;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  if (a == (BIGNUM *)0x0) {
LAB_081e1664:
    uVar7 = 0;
    goto LAB_081e1666;
  }
  BN_set_word(a,0);
  iVar2 = *param_4;
  while (iVar2 != -1) {
    param_4 = param_4 + 1;
    iVar2 = BN_set_bit(a,iVar2);
    if (iVar2 == 0) goto LAB_081e1664;
    iVar2 = *param_4;
  }
  BN_CTX_start(param_5);
  pBVar3 = BN_CTX_get(param_5);
  if ((pBVar3 == (BIGNUM *)0x0) || (iVar2 = BN_GF2m_mod_inv(pBVar3,param_3,a,param_5), iVar2 == 0))
  {
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
    iVar2 = BN_num_bits(a);
    iVar2 = iVar2 + 1;
    ptr = CRYPTO_malloc(iVar2 * 4,"bn_gf2m.c",0x1bf);
    if (ptr != (void *)0x0) {
      uVar7 = a->top;
      if (uVar7 == 0) {
LAB_081e17df:
        ERR_put_error(3,0x85,0x6a,"bn_gf2m.c",0x1c3);
      }
      else {
        iVar8 = uVar7 - 1;
        if (iVar8 < 0) {
          uVar7 = 0;
          if (0 < iVar2) {
            bVar10 = false;
            iVar6 = 1;
            iVar8 = 0;
            goto LAB_081e1784;
          }
          goto LAB_081e17df;
        }
        puVar1 = a->d;
        iVar6 = 0;
        iVar9 = iVar8 * 0x20 + -1;
        do {
          uVar5 = puVar1[iVar8];
          if (uVar5 != 0) {
            iVar4 = iVar9 + 0x20;
            uVar7 = 0x80000000;
            while( true ) {
              if ((uVar7 & uVar5) != 0) {
                if (iVar6 < iVar2) {
                  *(int *)((int)ptr + iVar6 * 4) = iVar4;
                }
                iVar6 = iVar6 + 1;
              }
              iVar4 = iVar4 + -1;
              uVar7 = uVar7 >> 1;
              if (iVar4 == iVar9) break;
              uVar5 = puVar1[iVar8];
            }
          }
          iVar8 = iVar8 + -1;
          iVar9 = iVar9 + -0x20;
        } while (iVar8 != -1);
        bVar10 = iVar6 == 0;
        if (iVar6 < iVar2) {
          iVar8 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          bVar10 = iVar6 == 0;
LAB_081e1784:
          *(undefined4 *)((int)ptr + iVar8) = 0xffffffff;
        }
        if ((iVar2 < iVar6) || (bVar10)) {
          uVar7 = (uint)(iVar6 != 0);
          goto LAB_081e17df;
        }
        iVar2 = BN_GF2m_mod_mul_arr(param_1,param_2,pBVar3,ptr,param_5);
        uVar7 = (uint)(iVar2 != 0);
      }
      CRYPTO_free(ptr);
    }
  }
  BN_CTX_end(param_5);
LAB_081e1666:
  BN_CTX_end(param_5);
  return uVar7;
}

