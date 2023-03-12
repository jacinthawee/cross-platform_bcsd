
int BN_GF2m_mod_mul(undefined4 param_1,undefined4 param_2,undefined4 param_3,BIGNUM *param_4,
                   undefined4 param_5)

{
  int iVar1;
  void *ptr;
  int iVar2;
  ulong *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = BN_num_bits(param_4);
  iVar1 = iVar1 + 1;
  ptr = CRYPTO_malloc(iVar1 * 4,"bn_gf2m.c",0x22a);
  if (ptr == (void *)0x0) {
    return 0;
  }
  iVar4 = param_4->top;
  if (iVar4 != 0) {
    iVar2 = iVar4 + -1;
    if (iVar2 < 0) {
      iVar7 = 0;
    }
    else {
      iVar8 = iVar2 * 0x20 + -1;
      iVar7 = 0;
      puVar3 = param_4->d + iVar4;
      do {
        puVar3 = puVar3 + -1;
        uVar6 = *puVar3;
        if (uVar6 != 0) {
          iVar4 = iVar8 + 0x20;
          uVar5 = 0x80000000;
          while( true ) {
            uVar6 = uVar6 & uVar5;
            uVar5 = uVar5 >> 1;
            if (uVar6 != 0) {
              if (iVar7 < iVar1) {
                *(int *)((int)ptr + iVar7 * 4) = iVar4;
              }
              iVar7 = iVar7 + 1;
            }
            iVar4 = iVar4 + -1;
            if (iVar8 == iVar4) break;
            uVar6 = *puVar3;
          }
        }
        iVar2 = iVar2 + -1;
        iVar8 = iVar8 + -0x20;
      } while (iVar2 != -1);
    }
    iVar4 = iVar7;
    if (iVar7 < iVar1) {
      *(undefined4 *)((int)ptr + iVar7 * 4) = 0xffffffff;
      iVar4 = iVar7 + 1;
    }
    uVar6 = count_leading_zeroes(iVar4);
    uVar6 = uVar6 >> 5;
    if (iVar1 < iVar4) {
      uVar6 = uVar6 | 1;
    }
    if (uVar6 == 0) {
      iVar4 = BN_GF2m_mod_mul_arr(param_1,param_2,param_3,ptr,param_5);
      goto LAB_0011e990;
    }
  }
  ERR_put_error(3,0x85,0x6a,"bn_gf2m.c",0x22e);
LAB_0011e990:
  CRYPTO_free(ptr);
  return iVar4;
}

