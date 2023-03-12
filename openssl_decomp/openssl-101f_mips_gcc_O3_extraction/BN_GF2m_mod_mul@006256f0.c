
int BN_GF2m_mod_mul(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                   undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(param_4);
  iVar1 = iVar1 + 1;
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1 * 4,"bn_gf2m.c",0x1bf);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = param_4[1];
  if (iVar3 == 0) {
LAB_006257d4:
    iVar4 = 0;
  }
  else {
    if (iVar3 + -1 < 0) {
      iVar4 = 1;
      if (0 < iVar1) {
        iVar3 = 0;
        goto LAB_00625850;
      }
      goto LAB_006257d4;
    }
    iVar8 = *param_4;
    iVar4 = 0;
    iVar9 = iVar8 + iVar3 * 4;
    iVar3 = (iVar3 + -1) * 0x20 + -1;
    do {
      uVar5 = *(uint *)(iVar9 + -4);
      iVar6 = iVar3 + 0x20;
      if (uVar5 != 0) {
        uVar7 = 0x80000000;
        while( true ) {
          if ((uVar7 & uVar5) != 0) {
            if (iVar4 < iVar1) {
              *(int *)(iVar2 + iVar4 * 4) = iVar6;
            }
            iVar4 = iVar4 + 1;
          }
          iVar6 = iVar6 + -1;
          uVar7 = uVar7 >> 1;
          if (iVar6 == iVar3) break;
          uVar5 = *(uint *)(iVar9 + -4);
        }
      }
      iVar9 = iVar9 + -4;
      iVar3 = iVar3 + -0x20;
    } while (iVar8 != iVar9);
    iVar3 = iVar4 << 2;
    if (iVar4 < iVar1) {
      iVar4 = iVar4 + 1;
LAB_00625850:
      *(undefined4 *)(iVar2 + iVar3) = 0xffffffff;
    }
    else if (iVar4 == 0) goto LAB_006257d4;
    if (iVar4 <= iVar1) {
      iVar4 = BN_GF2m_mod_mul_arr(param_1,param_2,param_3,iVar2,param_5);
      goto LAB_006257fc;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(3,0x85,0x6a,"bn_gf2m.c",0x1c3);
LAB_006257fc:
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
  return iVar4;
}

