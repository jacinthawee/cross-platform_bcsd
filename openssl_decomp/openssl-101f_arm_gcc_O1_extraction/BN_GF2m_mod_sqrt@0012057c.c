
int BN_GF2m_mod_sqrt(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  int *ptr;
  BIGNUM *a;
  ulong *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = BN_num_bits(param_3);
  iVar1 = iVar1 + 1;
  ptr = (int *)CRYPTO_malloc(iVar1 * 4,"bn_gf2m.c",0x39a);
  if (ptr == (int *)0x0) {
    return 0;
  }
  iVar3 = param_3->top;
  if (iVar3 != 0) {
    iVar8 = iVar3 + -1;
    if (iVar8 < 0) {
      iVar6 = 0;
    }
    else {
      iVar7 = iVar8 * 0x20 + -1;
      iVar6 = 0;
      puVar2 = param_3->d + iVar3;
      do {
        puVar2 = puVar2 + -1;
        uVar5 = *puVar2;
        if (uVar5 != 0) {
          iVar3 = iVar7 + 0x20;
          uVar4 = 0x80000000;
          while( true ) {
            uVar5 = uVar5 & uVar4;
            uVar4 = uVar4 >> 1;
            if (uVar5 != 0) {
              if (iVar6 < iVar1) {
                ptr[iVar6] = iVar3;
              }
              iVar6 = iVar6 + 1;
            }
            iVar3 = iVar3 + -1;
            if (iVar7 == iVar3) break;
            uVar5 = *puVar2;
          }
        }
        iVar8 = iVar8 + -1;
        iVar7 = iVar7 + -0x20;
      } while (iVar8 != -1);
    }
    iVar3 = iVar6;
    if (iVar6 < iVar1) {
      ptr[iVar6] = -1;
      iVar3 = iVar6 + 1;
    }
    uVar5 = count_leading_zeroes(iVar3);
    uVar5 = uVar5 >> 5;
    if (iVar1 < iVar3) {
      uVar5 = uVar5 | 1;
    }
    if (uVar5 == 0) {
      if (*ptr != 0) {
        BN_CTX_start(param_4);
        a = BN_CTX_get(param_4);
        if ((a == (BIGNUM *)0x0) || (iVar1 = BN_set_bit(a,*ptr + -1), iVar1 == 0)) {
          iVar1 = 0;
        }
        else {
          iVar1 = BN_GF2m_mod_exp_arr(param_1,param_2,a,ptr,param_4);
        }
        BN_CTX_end(param_4);
        CRYPTO_free(ptr);
        return iVar1;
      }
      iVar3 = 1;
      BN_set_word(param_1,0);
      goto LAB_00120672;
    }
  }
  ERR_put_error(3,0x89,0x6a,"bn_gf2m.c",0x39e);
LAB_00120672:
  CRYPTO_free(ptr);
  return iVar3;
}

