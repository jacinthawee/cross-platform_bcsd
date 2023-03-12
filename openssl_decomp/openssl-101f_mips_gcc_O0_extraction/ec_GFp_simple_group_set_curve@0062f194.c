
undefined4
ec_GFp_simple_group_set_curve
          (int *param_1,uint **param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(param_2);
  if (((iVar1 < 3) || ((int)param_2[1] < 1)) || ((**param_2 & 1) == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa6,0x67,"ecp_smpl.c",0xb9);
    return 0;
  }
  if (param_5 == 0) {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (iVar1 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar1);
    iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar1);
    if ((iVar2 == 0) ||
       (iVar3 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x12,param_2), param_5 = iVar1, iVar3 == 0
       )) {
      uVar4 = 0;
      (*(code *)PTR_BN_CTX_end_006a9654)(iVar1);
      goto LAB_0062f2a4;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((iVar2 == 0) ||
       (iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x12,param_2), iVar1 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return 0;
    }
    iVar1 = 0;
  }
  (*(code *)PTR_BN_set_negative_006a96e8)(param_1 + 0x12,0);
  iVar3 = (*(code *)PTR_BN_nnmod_006a9664)(iVar2,param_3,param_2,param_5);
  if (iVar3 == 0) {
LAB_0062f28c:
    uVar4 = 0;
  }
  else {
    if (*(code **)(*param_1 + 0x90) != (code *)0x0) {
      iVar3 = (**(code **)(*param_1 + 0x90))(param_1,param_1 + 0x1d,iVar2);
      if (iVar3 != 0) goto LAB_0062f354;
      goto LAB_0062f28c;
    }
    iVar3 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x1d,iVar2);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
LAB_0062f354:
      piVar5 = param_1 + 0x22;
      iVar3 = (*(code *)PTR_BN_nnmod_006a9664)(piVar5,param_4,param_2,param_5);
      if ((iVar3 == 0) ||
         (((*(code **)(*param_1 + 0x90) != (code *)0x0 &&
           (iVar3 = (**(code **)(*param_1 + 0x90))(param_1,piVar5,piVar5,param_5), iVar3 == 0)) ||
          (iVar3 = (*(code *)PTR_BN_add_word_006a81bc)(iVar2,3), iVar3 == 0)))) goto LAB_0062f28c;
      uVar4 = 1;
      iVar2 = (*(code *)PTR_BN_cmp_006a8a4c)(iVar2,param_1 + 0x12);
      param_1[0x27] = (uint)(iVar2 == 0);
    }
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  if (iVar1 == 0) {
    return uVar4;
  }
LAB_0062f2a4:
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
  return uVar4;
}

