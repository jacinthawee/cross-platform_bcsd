
uint ec_GFp_simple_cmp(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  code *pcVar9;
  int local_30;
  int local_2c;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_3);
    return (uint)(iVar1 == 0);
  }
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if (iVar1 != 0) {
    return 1;
  }
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_3 + 0x40) != 0)) {
    iVar1 = (*(code *)PTR_BN_cmp_006a7960)(param_2 + 4,param_3 + 4);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = (*(code *)PTR_BN_cmp_006a7960)(param_2 + 0x18,param_3 + 0x18);
    return (uint)(iVar1 != 0);
  }
  pcVar6 = *(code **)(*param_1 + 0x84);
  pcVar9 = *(code **)(*param_1 + 0x88);
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_4 == 0) {
      return 0xffffffff;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    iVar1 = param_4;
    if (iVar3 == 0) {
      uVar7 = 0xffffffff;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      goto LAB_0062eddc;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    if (iVar3 == 0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      return 0xffffffff;
    }
    iVar1 = 0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar8 = (*pcVar9)(param_1,iVar3,param_3 + 0x2c,param_4);
    if ((iVar8 != 0) && (iVar8 = (*pcVar6)(param_1,local_30,param_2 + 4,iVar3,param_4), iVar8 != 0))
    {
      iVar4 = *(int *)(param_2 + 0x40);
      iVar8 = local_30;
      goto LAB_0062ecbc;
    }
LAB_0062edc4:
    uVar7 = 0xffffffff;
  }
  else {
    iVar4 = *(int *)(param_2 + 0x40);
    iVar8 = param_2 + 4;
LAB_0062ecbc:
    if (iVar4 == 0) {
      iVar4 = (*pcVar9)(param_1,uVar2,param_2 + 0x2c,param_4);
      if ((iVar4 == 0) ||
         (iVar5 = (*pcVar6)(param_1,local_2c,param_3 + 4,uVar2,param_4), iVar4 = local_2c,
         iVar5 == 0)) goto LAB_0062edc4;
    }
    else {
      iVar4 = param_3 + 4;
    }
    iVar5 = (*(code *)PTR_BN_cmp_006a7960)(iVar8,iVar4);
    if (iVar5 == 0) {
      if (*(int *)(param_3 + 0x40) == 0) {
        iVar5 = (*pcVar6)(param_1,iVar3,iVar3,param_3 + 0x2c,param_4);
        if ((iVar5 == 0) ||
           (iVar3 = (*pcVar6)(param_1,local_30,param_2 + 0x18,iVar3,param_4), iVar3 == 0))
        goto LAB_0062edc4;
        iVar3 = *(int *)(param_2 + 0x40);
      }
      else {
        iVar8 = param_2 + 0x18;
        iVar3 = *(int *)(param_2 + 0x40);
      }
      if (iVar3 == 0) {
        iVar3 = (*pcVar6)(param_1,uVar2,uVar2,param_2 + 0x2c,param_4);
        if ((iVar3 == 0) ||
           (iVar3 = (*pcVar6)(param_1,local_2c,param_3 + 0x18,uVar2,param_4), iVar3 == 0))
        goto LAB_0062edc4;
      }
      else {
        iVar4 = param_3 + 0x18;
      }
      iVar3 = (*(code *)PTR_BN_cmp_006a7960)(iVar8,iVar4);
      uVar7 = (uint)(iVar3 != 0);
    }
    else {
      uVar7 = 1;
    }
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  param_4 = iVar1;
  if (iVar1 == 0) {
    return uVar7;
  }
LAB_0062eddc:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_4);
  return uVar7;
}

