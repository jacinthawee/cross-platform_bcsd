
uint ec_GFp_simple_add(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  code *pcVar2;
  uint **ppuVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  code *pcVar13;
  
  if (param_3 == param_4) {
                    /* WARNING: Could not recover jumptable at 0x0062f3a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)PTR_EC_POINT_dbl_006a8614)();
    return uVar12;
  }
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_3);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0062f334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(param_2,param_4);
    return uVar12;
  }
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_4);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0062f370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(param_2,param_3);
    return uVar12;
  }
  pcVar13 = *(code **)(*param_1 + 0x84);
  pcVar2 = *(code **)(*param_1 + 0x88);
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a794c)();
    iVar1 = param_5;
    if (param_5 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = 0;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
  ppuVar3 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  uVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  uVar6 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  uVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  iVar9 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  if (iVar9 == 0) {
LAB_0062f2e8:
    uVar12 = 0;
  }
  else {
    if (*(int *)(param_4 + 0x40) == 0) {
      iVar10 = (*pcVar2)(param_1,ppuVar3,param_4 + 0x2c,param_5);
      if ((((iVar10 != 0) &&
           (iVar10 = (*pcVar13)(param_1,uVar4,param_3 + 4,ppuVar3,param_5), iVar10 != 0)) &&
          (iVar10 = (*pcVar13)(param_1,ppuVar3,ppuVar3,param_4 + 0x2c,param_5), iVar10 != 0)) &&
         (iVar10 = (*pcVar13)(param_1,uVar5,param_3 + 0x18,ppuVar3,param_5), iVar10 != 0)) {
        iVar10 = *(int *)(param_3 + 0x40);
        goto LAB_0062f18c;
      }
      goto LAB_0062f2e8;
    }
    iVar10 = (*(code *)PTR_BN_copy_006a8450)(uVar4,param_3 + 4);
    if ((iVar10 == 0) ||
       (iVar10 = (*(code *)PTR_BN_copy_006a8450)(uVar5,param_3 + 0x18), iVar10 == 0))
    goto LAB_0062f2e8;
    iVar10 = *(int *)(param_3 + 0x40);
LAB_0062f18c:
    if (iVar10 == 0) {
      iVar10 = (*pcVar2)(param_1,ppuVar3,param_3 + 0x2c,param_5);
      if (((iVar10 != 0) &&
          (iVar10 = (*pcVar13)(param_1,uVar6,param_4 + 4,ppuVar3,param_5), iVar10 != 0)) &&
         ((iVar10 = (*pcVar13)(param_1,ppuVar3,ppuVar3,param_3 + 0x2c,param_5), iVar10 != 0 &&
          (iVar10 = (*pcVar13)(param_1,uVar7,param_4 + 0x18,ppuVar3,param_5), iVar10 != 0))))
      goto LAB_0062f1c8;
      goto LAB_0062f2e8;
    }
    iVar10 = (*(code *)PTR_BN_copy_006a8450)(uVar6,param_4 + 4);
    if ((iVar10 == 0) ||
       (iVar10 = (*(code *)PTR_BN_copy_006a8450)(uVar7,param_4 + 0x18), iVar10 == 0))
    goto LAB_0062f2e8;
LAB_0062f1c8:
    piVar11 = param_1 + 0x12;
    iVar10 = (*(code *)PTR_BN_mod_sub_quick_006a96f8)(iVar8,uVar4,uVar6,piVar11);
    if ((iVar10 == 0) ||
       (iVar10 = (*(code *)PTR_BN_mod_sub_quick_006a96f8)(iVar9,uVar5,uVar7,piVar11), iVar10 == 0))
    goto LAB_0062f2e8;
    if (*(int *)(iVar8 + 4) != 0) {
      iVar10 = (*(code *)PTR_BN_mod_add_quick_006a96f0)(uVar4,uVar4,uVar6,piVar11);
      if ((iVar10 != 0) &&
         (iVar10 = (*(code *)PTR_BN_mod_add_quick_006a96f0)(uVar5,uVar5,uVar7,piVar11), iVar10 != 0)
         ) {
        if (*(int *)(param_3 + 0x40) == 0) {
          if (*(int *)(param_4 + 0x40) == 0) {
            iVar10 = (*pcVar13)(param_1,ppuVar3,param_3 + 0x2c,param_4 + 0x2c,param_5);
            if (iVar10 == 0) goto LAB_0062f2e8;
          }
          else {
            iVar10 = (*(code *)PTR_BN_copy_006a8450)(ppuVar3,param_3 + 0x2c);
            if (iVar10 == 0) {
              uVar12 = 0;
              goto LAB_0062f2ec;
            }
          }
LAB_0062f548:
          iVar10 = (*pcVar13)(param_1,param_2 + 0x2c,ppuVar3,iVar8,param_5);
          if (iVar10 != 0) {
LAB_0062f568:
            *(undefined4 *)(param_2 + 0x40) = 0;
            iVar10 = (*pcVar2)(param_1,ppuVar3,iVar9,param_5);
            if (((iVar10 != 0) && (iVar10 = (*pcVar2)(param_1,uVar7,iVar8,param_5), iVar10 != 0)) &&
               (iVar10 = (*pcVar13)(param_1,uVar6,uVar4,uVar7,param_5), iVar10 != 0)) {
              iVar10 = (*(code *)PTR_BN_mod_sub_quick_006a96f8)(param_2 + 4,ppuVar3,uVar6,piVar11);
              if (((((iVar10 != 0) &&
                    (iVar10 = (*(code *)PTR_BN_mod_lshift1_quick_006a96ec)
                                        (ppuVar3,param_2 + 4,piVar11), iVar10 != 0)) &&
                   ((iVar10 = (*(code *)PTR_BN_mod_sub_quick_006a96f8)
                                        (ppuVar3,uVar6,ppuVar3,piVar11), iVar10 != 0 &&
                    ((iVar9 = (*pcVar13)(param_1,ppuVar3,ppuVar3,iVar9,param_5), iVar9 != 0 &&
                     (iVar9 = (*pcVar13)(param_1,iVar8,uVar7,iVar8,param_5), iVar9 != 0)))))) &&
                  (iVar8 = (*pcVar13)(param_1,uVar4,uVar5,iVar8,param_5), iVar8 != 0)) &&
                 ((iVar8 = (*(code *)PTR_BN_mod_sub_quick_006a96f8)(ppuVar3,ppuVar3,uVar4,piVar11),
                  iVar8 != 0 &&
                  ((((int)ppuVar3[1] < 1 || ((**ppuVar3 & 1) == 0)) ||
                   (iVar8 = (*(code *)PTR_BN_add_006a85a4)(ppuVar3,ppuVar3,piVar11), iVar8 != 0)))))
                 ) {
                iVar8 = (*(code *)PTR_BN_rshift1_006a7958)(param_2 + 0x18,ppuVar3);
                uVar12 = (uint)(iVar8 != 0);
                goto LAB_0062f2ec;
              }
            }
          }
        }
        else {
          if (*(int *)(param_4 + 0x40) != 0) {
            iVar10 = (*(code *)PTR_BN_copy_006a8450)(param_2 + 0x2c,iVar8);
            if (iVar10 == 0) {
              uVar12 = 0;
              goto LAB_0062f2ec;
            }
            goto LAB_0062f568;
          }
          iVar10 = (*(code *)PTR_BN_copy_006a8450)(ppuVar3,param_4 + 0x2c);
          if (iVar10 != 0) goto LAB_0062f548;
        }
      }
      goto LAB_0062f2e8;
    }
    if (*(int *)(iVar9 + 4) == 0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      uVar12 = (*(code *)PTR_EC_POINT_dbl_006a8614)(param_1,param_2,param_3,param_5);
      goto LAB_0062f258;
    }
    uVar12 = 1;
    (*(code *)PTR_BN_set_word_006a7730)(param_2 + 0x2c,0);
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
LAB_0062f2ec:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
LAB_0062f258:
  if (iVar1 != 0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
  }
  return uVar12;
}
