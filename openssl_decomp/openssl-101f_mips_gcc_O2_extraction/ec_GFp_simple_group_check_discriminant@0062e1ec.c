
bool ec_GFp_simple_group_check_discriminant(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  
  if (param_2 == 0) {
    param_2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    iVar7 = param_2;
    if (param_2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa5,0x41,"ecp_smpl.c",299);
      return false;
    }
  }
  else {
    iVar7 = 0;
  }
  (*(code *)PTR_BN_CTX_start_006a9644)(param_2);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_2);
  iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_2);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_2);
  uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_2);
  iVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(param_2);
  if (iVar5 != 0) {
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      iVar5 = (*(code *)PTR_BN_copy_006a9570)(iVar1,param_1 + 0x1d,param_1 + 0x1d);
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_BN_copy_006a9570)(iVar2,param_1 + 0x22);
        if (iVar5 == 0) {
          bVar6 = false;
          goto LAB_0062e2cc;
        }
        goto LAB_0062e33c;
      }
    }
    else {
      iVar5 = (**(code **)(*param_1 + 0x94))(param_1,iVar1,param_1 + 0x1d,param_2);
      if ((iVar5 != 0) &&
         (iVar5 = (**(code **)(*param_1 + 0x94))(param_1,iVar2,param_1 + 0x22,param_2), iVar5 != 0))
      {
LAB_0062e33c:
        if (*(int *)(iVar1 + 4) == 0) {
          bVar6 = *(int *)(iVar2 + 4) != 0;
          goto LAB_0062e2cc;
        }
        if (*(int *)(iVar2 + 4) == 0) {
          bVar6 = true;
          goto LAB_0062e2cc;
        }
        param_1 = param_1 + 0x12;
        iVar5 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(uVar3,iVar1,param_1,param_2);
        if ((((iVar5 != 0) &&
             (iVar5 = (*(code *)PTR_BN_mod_mul_006a9698)(uVar4,uVar3,iVar1,param_1,param_2),
             iVar5 != 0)) && (iVar5 = (*(code *)PTR_BN_lshift_006a95b8)(uVar3,uVar4,2), iVar5 != 0))
           && (((iVar2 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(uVar4,iVar2,param_1,param_2), iVar2 != 0
                && (iVar2 = (*(code *)PTR_BN_mul_word_006a9694)(uVar4,0x1b), iVar2 != 0)) &&
               (iVar2 = (*(code *)PTR_BN_mod_add_006aa61c)(iVar1,uVar3,uVar4,param_1,param_2),
               iVar2 != 0)))) {
          bVar6 = *(int *)(iVar1 + 4) != 0;
          goto LAB_0062e2cc;
        }
      }
    }
  }
  bVar6 = false;
LAB_0062e2cc:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_2);
  if (iVar7 != 0) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar7);
  }
  return bVar6;
}

