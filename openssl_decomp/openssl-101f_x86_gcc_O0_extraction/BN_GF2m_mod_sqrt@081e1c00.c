
int BN_GF2m_mod_sqrt(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  ulong *puVar1;
  int iVar2;
  int *ptr;
  int iVar3;
  BIGNUM *a;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar6 = 0;
  iVar2 = BN_num_bits(param_3);
  iVar2 = iVar2 + 1;
  ptr = (int *)CRYPTO_malloc(iVar2 * 4,"bn_gf2m.c",0x39a);
  if (ptr == (int *)0x0) {
    return 0;
  }
  if (param_3->top != 0) {
    iVar7 = param_3->top + -1;
    if (iVar7 < 0) {
      iVar8 = 0;
      iVar7 = 1;
      if (0 < iVar2) goto LAB_081e1cb8;
    }
    else {
      puVar1 = param_3->d;
      iVar8 = iVar7 * 0x20 + -1;
      do {
        uVar4 = puVar1[iVar7];
        if (uVar4 != 0) {
          iVar3 = iVar8 + 0x20;
          uVar5 = 0x80000000;
          while( true ) {
            if ((uVar5 & uVar4) != 0) {
              if (iVar6 < iVar2) {
                ptr[iVar6] = iVar3;
              }
              iVar6 = iVar6 + 1;
            }
            iVar3 = iVar3 + -1;
            uVar5 = uVar5 >> 1;
            if (iVar8 == iVar3) break;
            uVar4 = puVar1[iVar7];
          }
        }
        iVar7 = iVar7 + -1;
        iVar8 = iVar8 + -0x20;
      } while (iVar7 != -1);
      iVar8 = iVar6 * 4;
      iVar7 = iVar6 + 1;
      if (iVar6 < iVar2) {
LAB_081e1cb8:
        *(undefined4 *)((int)ptr + iVar8) = 0xffffffff;
        bVar9 = false;
        iVar6 = iVar7;
      }
      else {
        bVar9 = iVar6 == 0;
      }
      if ((iVar6 <= iVar2) && (!bVar9)) {
        if (*ptr != 0) {
          BN_CTX_start(param_4);
          a = BN_CTX_get(param_4);
          if ((a == (BIGNUM *)0x0) || (iVar6 = BN_set_bit(a,*ptr + -1), iVar6 == 0)) {
            iVar6 = 0;
          }
          else {
            iVar6 = BN_GF2m_mod_exp_arr(param_1,param_2,a,ptr,param_4);
          }
          BN_CTX_end(param_4);
          CRYPTO_free(ptr);
          return iVar6;
        }
        iVar6 = 1;
        BN_set_word(param_1,0);
        goto LAB_081e1d83;
      }
    }
  }
  ERR_put_error(3,0x89,0x6a,"bn_gf2m.c",0x39e);
LAB_081e1d83:
  CRYPTO_free(ptr);
  return iVar6;
}

