
bool ec_GFp_simple_dbl(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  bool bVar9;
  code *pcVar10;
  undefined4 local_3c;
  int local_30;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,param_3);
  if (iVar1 != 0) {
    (*(code *)PTR_BN_set_word_006a8820)(param_2 + 0x2c,0);
    *(undefined4 *)(param_2 + 0x40) = 0;
    return true;
  }
  pcVar10 = *(code **)(*param_1 + 0x88);
  pcVar7 = *(code **)(*param_1 + 0x84);
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_4 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    piVar3 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_3c = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar1 = param_4;
    if (iVar4 == 0) {
      bVar9 = false;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      goto LAB_0062eaf4;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    piVar3 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_3c = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    if (iVar4 == 0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      return false;
    }
    iVar1 = 0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    if (param_1[0x27] == 0) {
      iVar5 = (*pcVar10)(param_1,uVar2,param_3 + 4,param_4);
      if (((((iVar5 != 0) &&
            (iVar5 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(piVar3,uVar2,param_1 + 0x12),
            iVar5 != 0)) &&
           ((iVar5 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(uVar2,uVar2,piVar3,param_1 + 0x12),
            iVar5 != 0 &&
            ((iVar5 = (*pcVar10)(param_1,piVar3,param_3 + 0x2c,param_4), iVar5 != 0 &&
             (iVar5 = (*pcVar10)(param_1,piVar3,piVar3,param_4), iVar5 != 0)))))) &&
          (iVar5 = (*pcVar7)(param_1,piVar3,piVar3,param_1 + 0x1d,param_4), iVar5 != 0)) &&
         (iVar5 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(piVar3,piVar3,uVar2,param_1 + 0x12),
         iVar5 != 0)) {
        iVar5 = *(int *)(param_3 + 0x40);
        goto LAB_0062ec20;
      }
    }
    else {
      iVar5 = (*pcVar10)(param_1,piVar3,param_3 + 0x2c,param_4);
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(uVar2,param_3 + 4,piVar3,param_1 + 0x12);
        if ((((iVar5 != 0) &&
             (iVar5 = (*(code *)PTR_BN_mod_sub_quick_006aa800)
                                (local_3c,param_3 + 4,piVar3,param_1 + 0x12), iVar5 != 0)) &&
            (iVar5 = (*pcVar7)(param_1,piVar3,uVar2,local_3c,param_4), iVar5 != 0)) &&
           (iVar5 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(uVar2,piVar3,param_1 + 0x12),
           piVar8 = piVar3, iVar5 != 0)) goto LAB_0062ef20;
      }
    }
LAB_0062eadc:
    bVar9 = false;
  }
  else {
    iVar5 = (*pcVar10)(param_1,uVar2,param_3 + 4,param_4);
    if (((iVar5 == 0) ||
        (iVar5 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(piVar3,uVar2,param_1 + 0x12),
        iVar5 == 0)) ||
       (iVar5 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(uVar2,uVar2,piVar3,param_1 + 0x12),
       iVar5 == 0)) goto LAB_0062eadc;
    piVar8 = param_1 + 0x1d;
LAB_0062ef20:
    iVar5 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(piVar3,uVar2,piVar8,param_1 + 0x12);
    if (iVar5 == 0) goto LAB_0062eadc;
    iVar5 = *(int *)(param_3 + 0x40);
LAB_0062ec20:
    local_30 = param_3 + 4;
    iVar6 = param_3 + 0x18;
    if (iVar5 == 0) {
      iVar5 = (*pcVar7)(param_1,uVar2,iVar6,param_3 + 0x2c,param_4);
      if (iVar5 != 0) goto LAB_0062ec48;
      goto LAB_0062eadc;
    }
    iVar5 = (*(code *)PTR_BN_copy_006a9570)(uVar2,iVar6);
    if (iVar5 == 0) goto LAB_0062eadc;
LAB_0062ec48:
    iVar5 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(param_2 + 0x2c,uVar2,param_1 + 0x12);
    if (iVar5 == 0) goto LAB_0062eadc;
    *(undefined4 *)(param_2 + 0x40) = 0;
    iVar5 = (*pcVar10)(param_1,iVar4,iVar6,param_4);
    if (((iVar5 == 0) || (iVar5 = (*pcVar7)(param_1,local_3c,local_30,iVar4,param_4), iVar5 == 0))
       || ((iVar5 = (*(code *)PTR_BN_mod_lshift_quick_006aaa28)(local_3c,local_3c,2,param_1 + 0x12),
           iVar5 == 0 ||
           (iVar5 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(uVar2,local_3c,param_1 + 0x12),
           iVar5 == 0)))) goto LAB_0062eadc;
    iVar6 = param_2 + 4;
    iVar5 = (*pcVar10)(param_1,iVar6,piVar3,param_4);
    if ((((iVar5 == 0) ||
         (iVar5 = (*(code *)PTR_BN_mod_sub_quick_006aa800)(iVar6,iVar6,uVar2,param_1 + 0x12),
         iVar5 == 0)) || (iVar5 = (*pcVar10)(param_1,uVar2,iVar4,param_4), iVar5 == 0)) ||
       (((iVar5 = (*(code *)PTR_BN_mod_lshift_quick_006aaa28)(iVar4,uVar2,3,param_1 + 0x12),
         iVar5 == 0 ||
         (iVar5 = (*(code *)PTR_BN_mod_sub_quick_006aa800)(uVar2,local_3c,iVar6,param_1 + 0x12),
         iVar5 == 0)) || (iVar5 = (*pcVar7)(param_1,uVar2,piVar3,uVar2,param_4), iVar5 == 0))))
    goto LAB_0062eadc;
    iVar4 = (*(code *)PTR_BN_mod_sub_quick_006aa800)(param_2 + 0x18,uVar2,iVar4,param_1 + 0x12);
    bVar9 = iVar4 != 0;
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  param_4 = iVar1;
  if (iVar1 == 0) {
    return bVar9;
  }
LAB_0062eaf4:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_4);
  return bVar9;
}

