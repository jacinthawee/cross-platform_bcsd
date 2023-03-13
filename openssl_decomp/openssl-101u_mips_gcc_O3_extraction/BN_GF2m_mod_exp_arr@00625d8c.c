
uint BN_GF2m_mod_exp_arr(undefined4 param_1,int *param_2,int **param_3,int *param_4,
                        undefined4 param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (param_3[1] == (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00625f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar6 = (*(code *)PTR_BN_set_word_006a7730)(param_1,1);
    return uVar6;
  }
  if ((param_3[1] == (int *)0x1) && (**param_3 == 1)) {
    iVar5 = (*(code *)PTR_BN_copy_006a8450)();
    return (uint)(iVar5 != 0);
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
  piVar1 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  if (piVar1 == (int *)0x0) {
LAB_00625e80:
    uVar6 = 0;
  }
  else {
    if (*param_4 == 0) {
      (*(code *)PTR_BN_set_word_006a7730)(piVar1,0);
    }
    else {
      if (param_2 != piVar1) {
        iVar5 = param_2[1];
        if (piVar1[2] < iVar5) {
          iVar5 = (*(code *)PTR_bn_expand2_006a8524)(piVar1);
          if (iVar5 == 0) goto LAB_00625e80;
          if (0 < param_2[1]) goto LAB_00625e3c;
          piVar1[1] = param_2[1];
        }
        else {
          if (0 < iVar5) {
LAB_00625e3c:
            puVar4 = (undefined4 *)*param_2;
            iVar3 = 0;
            puVar2 = (undefined4 *)*piVar1;
            do {
              iVar3 = iVar3 + 1;
              *puVar2 = *puVar4;
              iVar5 = param_2[1];
              puVar4 = puVar4 + 1;
              puVar2 = puVar2 + 1;
            } while (iVar3 < iVar5);
          }
          piVar1[1] = iVar5;
        }
      }
      iVar5 = BN_GF2m_mod_arr_part_0(piVar1,param_4);
      if (iVar5 == 0) goto LAB_00625e80;
    }
    iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3);
    iVar5 = iVar5 + -2;
    if (-1 < iVar5) {
      do {
        while( true ) {
          iVar3 = BN_GF2m_mod_sqr_arr(piVar1,piVar1,param_4,param_5);
          iVar7 = iVar5 + -1;
          if (iVar3 == 0) goto LAB_00625e80;
          iVar3 = (*(code *)PTR_BN_is_bit_set_006a8538)(param_3,iVar5);
          iVar5 = iVar7;
          if (iVar3 != 0) break;
          if (iVar7 == -1) goto LAB_00625f90;
        }
        iVar3 = BN_GF2m_mod_mul_arr(piVar1,piVar1,param_2,param_4,param_5);
        if (iVar3 == 0) goto LAB_00625e80;
      } while (iVar7 != -1);
    }
LAB_00625f90:
    iVar5 = (*(code *)PTR_BN_copy_006a8450)(param_1,piVar1);
    uVar6 = (uint)(iVar5 != 0);
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  return uVar6;
}

