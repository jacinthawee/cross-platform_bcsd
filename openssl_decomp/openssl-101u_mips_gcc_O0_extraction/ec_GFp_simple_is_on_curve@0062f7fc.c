
uint ec_GFp_simple_is_on_curve(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  uint uVar9;
  code *pcVar10;
  undefined4 local_30;
  
  iVar2 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if (iVar2 != 0) {
    return 1;
  }
  pcVar7 = *(code **)(*param_1 + 0x84);
  pcVar10 = *(code **)(*param_1 + 0x88);
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_3 == 0) {
      return 0xffffffff;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_3);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    iVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    if ((iVar2 == 0) ||
       (iVar6 = (*pcVar10)(param_1,uVar3,param_2 + 4,param_3), iVar5 = param_3, iVar6 == 0)) {
      uVar9 = 0xffffffff;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
      goto LAB_0062f938;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_3);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    iVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    if ((iVar2 == 0) || (iVar5 = (*pcVar10)(param_1,uVar3,param_2 + 4,param_3), iVar5 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
      return 0xffffffff;
    }
    iVar5 = 0;
  }
  if (*(int *)(param_2 + 0x40) == 0) {
    iVar6 = (*pcVar10)(param_1,piVar4,param_2 + 0x2c,param_3);
    if (((iVar6 != 0) && (iVar6 = (*pcVar10)(param_1,local_30,piVar4,param_3), iVar6 != 0)) &&
       (iVar6 = (*pcVar7)(param_1,iVar2,local_30,piVar4,param_3), iVar6 != 0)) {
      if (param_1[0x27] == 0) {
        iVar6 = (*pcVar7)(param_1,piVar4,local_30,param_1 + 0x1d,param_3);
        pcVar1 = (code *)PTR_BN_mod_add_quick_006a96f0;
      }
      else {
        iVar6 = (*(code *)PTR_BN_mod_lshift1_quick_006a96ec)(piVar4,local_30,param_1 + 0x12);
        if (iVar6 == 0) goto LAB_0062f920;
        iVar6 = (*(code *)PTR_BN_mod_add_quick_006a96f0)(piVar4,piVar4,local_30,param_1 + 0x12);
        pcVar1 = (code *)PTR_BN_mod_sub_quick_006a96f8;
      }
      if (((iVar6 != 0) && (iVar6 = (*pcVar1)(uVar3,uVar3,piVar4,param_1 + 0x12), iVar6 != 0)) &&
         ((iVar6 = (*pcVar7)(param_1,uVar3,uVar3,param_2 + 4,param_3), iVar6 != 0 &&
          (iVar2 = (*pcVar7)(param_1,piVar4,param_1 + 0x22,iVar2,param_3), piVar8 = piVar4,
          iVar2 != 0)))) goto LAB_0062fbd4;
    }
LAB_0062f920:
    uVar9 = 0xffffffff;
  }
  else {
    iVar2 = (*(code *)PTR_BN_mod_add_quick_006a96f0)(uVar3,uVar3,param_1 + 0x1d,param_1 + 0x12);
    if ((iVar2 == 0) || (iVar2 = (*pcVar7)(param_1,uVar3,uVar3,param_2 + 4,param_3), iVar2 == 0))
    goto LAB_0062f920;
    piVar8 = param_1 + 0x22;
LAB_0062fbd4:
    iVar2 = (*(code *)PTR_BN_mod_add_quick_006a96f0)(uVar3,uVar3,piVar8,param_1 + 0x12);
    if ((iVar2 == 0) || (iVar2 = (*pcVar10)(param_1,piVar4,param_2 + 0x18,param_3), iVar2 == 0))
    goto LAB_0062f920;
    iVar2 = (*(code *)PTR_BN_ucmp_006a7fb4)(piVar4,uVar3);
    uVar9 = (uint)(iVar2 == 0);
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
  param_3 = iVar5;
  if (iVar5 == 0) {
    return uVar9;
  }
LAB_0062f938:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_3);
  return uVar9;
}

