
bool BN_GF2m_mod_div_arr(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                        undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  bool bVar13;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
  piVar1 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
  if (piVar1 == (int *)0x0) {
LAB_006265c8:
    bVar13 = false;
    goto LAB_006265cc;
  }
  (*(code *)PTR_BN_set_word_006a8820)(piVar1,0);
  if (*param_4 != -1) {
    piVar12 = param_4 + 1;
    do {
      iVar2 = (*(code *)PTR_BN_set_bit_006a9710)(piVar1);
      if (iVar2 == 0) goto LAB_006265c8;
      iVar2 = *piVar12;
      piVar12 = piVar12 + 1;
    } while (iVar2 != -1);
  }
  (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
  iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
  if ((iVar2 == 0) || (iVar3 = BN_GF2m_mod_inv(iVar2,param_3,piVar1,param_5), iVar3 == 0)) {
LAB_0062664c:
    bVar13 = false;
  }
  else {
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar1);
    iVar3 = iVar3 + 1;
    iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 * 4,"bn_gf2m.c",0x1bf);
    if (iVar4 == 0) goto LAB_0062664c;
    iVar5 = piVar1[1];
    if (iVar5 == 0) {
LAB_00626710:
      bVar13 = false;
LAB_00626714:
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x85,0x6a,"bn_gf2m.c",0x1c3);
    }
    else {
      if (iVar5 + -1 < 0) {
        iVar9 = 1;
        if (0 < iVar3) {
          iVar5 = 0;
          goto LAB_00626768;
        }
        goto LAB_00626710;
      }
      iVar11 = *piVar1;
      iVar9 = 0;
      iVar10 = iVar11 + iVar5 * 4;
      iVar5 = (iVar5 + -1) * 0x20 + -1;
      do {
        uVar6 = *(uint *)(iVar10 + -4);
        iVar7 = iVar5 + 0x20;
        if (uVar6 != 0) {
          uVar8 = 0x80000000;
          while( true ) {
            if ((uVar8 & uVar6) != 0) {
              if (iVar9 < iVar3) {
                *(int *)(iVar4 + iVar9 * 4) = iVar7;
              }
              iVar9 = iVar9 + 1;
            }
            iVar7 = iVar7 + -1;
            uVar8 = uVar8 >> 1;
            if (iVar7 == iVar5) break;
            uVar6 = *(uint *)(iVar10 + -4);
          }
        }
        iVar10 = iVar10 + -4;
        iVar5 = iVar5 + -0x20;
      } while (iVar11 != iVar10);
      iVar5 = iVar9 << 2;
      if (iVar9 < iVar3) {
        iVar9 = iVar9 + 1;
LAB_00626768:
        *(undefined4 *)(iVar4 + iVar5) = 0xffffffff;
      }
      else if (iVar9 == 0) goto LAB_00626710;
      if (iVar3 < iVar9) {
        bVar13 = iVar9 != 0;
        goto LAB_00626714;
      }
      iVar2 = BN_GF2m_mod_mul_arr(param_1,param_2,iVar2,iVar4,param_5);
      bVar13 = iVar2 != 0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar4);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
LAB_006265cc:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  return bVar13;
}

