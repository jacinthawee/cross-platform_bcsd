
int BN_GF2m_mod_mul(undefined4 param_1,undefined4 param_2,undefined4 param_3,BIGNUM *param_4,
                   undefined4 param_5)

{
  ulong *puVar1;
  int iVar2;
  void *ptr;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar6 = 0;
  iVar2 = BN_num_bits(param_4);
  iVar2 = iVar2 + 1;
  ptr = CRYPTO_malloc(iVar2 * 4,"bn_gf2m.c",0x22a);
  if (ptr == (void *)0x0) {
    return 0;
  }
  if (param_4->top != 0) {
    iVar7 = param_4->top + -1;
    if (iVar7 < 0) {
      iVar8 = 0;
      iVar7 = 1;
      if (0 < iVar2) goto LAB_081e0e78;
    }
    else {
      puVar1 = param_4->d;
      iVar8 = iVar7 * 0x20 + -1;
      do {
        uVar4 = puVar1[iVar7];
        if (uVar4 != 0) {
          iVar3 = iVar8 + 0x20;
          uVar5 = 0x80000000;
          while( true ) {
            if ((uVar5 & uVar4) != 0) {
              if (iVar6 < iVar2) {
                *(int *)((int)ptr + iVar6 * 4) = iVar3;
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
LAB_081e0e78:
        *(undefined4 *)((int)ptr + iVar8) = 0xffffffff;
        bVar9 = false;
        iVar6 = iVar7;
      }
      else {
        bVar9 = iVar6 == 0;
      }
      if ((iVar6 <= iVar2) && (!bVar9)) {
        iVar6 = BN_GF2m_mod_mul_arr(param_1,param_2,param_3,ptr,param_5);
        goto LAB_081e0eb2;
      }
    }
  }
  ERR_put_error(3,0x85,0x6a,"bn_gf2m.c",0x22e);
LAB_081e0eb2:
  CRYPTO_free(ptr);
  return iVar6;
}

