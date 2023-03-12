
int BN_GF2m_mod_sqrt(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3);
  iVar1 = iVar1 + 1;
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1 * 4,"bn_gf2m.c",0x44a);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = param_3[1];
  if (iVar3 == 0) {
LAB_006263dc:
    iVar4 = 0;
  }
  else {
    if (iVar3 + -1 < 0) {
      iVar4 = 1;
      if (0 < iVar1) {
        iVar3 = 0;
        goto LAB_00626458;
      }
      goto LAB_006263dc;
    }
    iVar8 = *param_3;
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
              piVar2[iVar4] = iVar6;
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
LAB_00626458:
      *(undefined4 *)((int)piVar2 + iVar3) = 0xffffffff;
    }
    else if (iVar4 == 0) goto LAB_006263dc;
    if (iVar4 <= iVar1) {
      if (*piVar2 == 0) {
        iVar4 = 1;
        (*(code *)PTR_BN_set_word_006a7730)(param_1,0);
      }
      else {
        (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
        iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
        if ((iVar1 == 0) ||
           (iVar3 = (*(code *)PTR_BN_set_bit_006a85ec)(iVar1,*piVar2 + -1), iVar3 == 0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = BN_GF2m_mod_exp_arr(param_1,param_2,iVar1,piVar2,param_4);
        }
        (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      }
      goto LAB_00626404;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(3,0x89,0x6a,"bn_gf2m.c",0x44e);
LAB_00626404:
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
  return iVar4;
}

