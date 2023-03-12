
undefined4 ec_GFp_simple_points_make_affine(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int local_34;
  
  if (param_2 == 0) {
    return 1;
  }
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_4 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    if (((iVar1 == 0) || (local_34 == 0)) ||
       (piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(param_2 << 2,"ecp_smpl.c",0x4f9),
       iVar11 = param_4, piVar2 == (int *)0x0)) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      (*(code *)PTR_BN_CTX_free_006a7954)(param_4);
      return 0;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    if (((iVar1 == 0) || (local_34 == 0)) ||
       (piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(param_2 << 2,"ecp_smpl.c",0x4f9),
       piVar2 == (int *)0x0)) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      return 0;
    }
    iVar11 = 0;
  }
  iVar9 = 0;
  piVar5 = piVar2;
  do {
    iVar9 = iVar9 + 1;
    iVar3 = (*(code *)PTR_BN_new_006a71b4)();
    *piVar5 = iVar3;
    if (iVar3 == 0) goto LAB_00630000;
    piVar5 = piVar5 + 1;
  } while (param_2 != iVar9);
  if (*(int *)(*param_3 + 0x30) == 0) {
    if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
      iVar9 = (*(code *)PTR_BN_set_word_006a7730)(*piVar2,1,param_4);
    }
    else {
      iVar9 = (**(code **)(*param_1 + 0x98))(param_1,*piVar2);
    }
    if (iVar9 != 0) goto LAB_00630110;
  }
  else {
    iVar9 = (*(code *)PTR_BN_copy_006a8450)(*piVar2,*param_3 + 0x2c);
    if (iVar9 == 0) {
      uVar6 = 0;
      goto LAB_00630004;
    }
LAB_00630110:
    if (param_2 != 1) {
      iVar9 = 1;
      piVar5 = piVar2;
      piVar7 = param_3;
      do {
        piVar7 = piVar7 + 1;
        piVar10 = piVar5 + 1;
        iVar9 = iVar9 + 1;
        if (*(int *)(*piVar7 + 0x30) == 0) {
          iVar3 = (*(code *)PTR_BN_copy_006a8450)(*piVar10,*piVar5);
          if (iVar3 == 0) {
            uVar6 = 0;
            goto LAB_00630004;
          }
        }
        else {
          iVar3 = (**(code **)(*param_1 + 0x84))(param_1,*piVar10,*piVar5,*piVar7 + 0x2c,param_4);
          if (iVar3 == 0) goto LAB_00630000;
        }
        piVar5 = piVar10;
      } while (param_2 != iVar9);
    }
    piVar5 = piVar2 + param_2;
    iVar9 = (*(code *)PTR_BN_mod_inverse_006a85f0)(iVar1,piVar5[-1],param_1 + 0x12,param_4);
    if (iVar9 == 0) {
      uVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x89,3,"ecp_smpl.c",0x525);
      goto LAB_00630004;
    }
    if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
       ((iVar9 = (**(code **)(*param_1 + 0x90))(param_1,iVar1,iVar1,param_4), iVar9 != 0 &&
        (iVar9 = (**(code **)(*param_1 + 0x90))(param_1,iVar1,iVar1,param_4), iVar9 != 0)))) {
      iVar9 = param_2 + -1;
      if (iVar9 != 0) {
        piVar7 = param_3 + param_2;
        do {
          iVar9 = iVar9 + -1;
          if (*(int *)(piVar7[-1] + 0x30) != 0) {
            iVar3 = (**(code **)(*param_1 + 0x84))(param_1,local_34,piVar5[-2],iVar1,param_4);
            if ((iVar3 == 0) ||
               (iVar3 = (**(code **)(*param_1 + 0x84))
                                  (param_1,iVar1,iVar1,piVar7[-1] + 0x2c,param_4), iVar3 == 0))
            goto LAB_00630000;
            iVar3 = (*(code *)PTR_BN_copy_006a8450)(piVar7[-1] + 0x2c,local_34);
            if (iVar3 == 0) {
              uVar6 = 0;
              goto LAB_00630004;
            }
          }
          piVar7 = piVar7 + -1;
          piVar5 = piVar5 + -1;
        } while (iVar9 != 0);
      }
      if ((*(int *)(*param_3 + 0x30) == 0) ||
         (iVar9 = (*(code *)PTR_BN_copy_006a8450)(*param_3 + 0x2c,iVar1), iVar9 != 0)) {
        iVar9 = 0;
        do {
          iVar8 = *param_3;
          iVar3 = iVar8 + 0x2c;
          if (*(int *)(iVar8 + 0x30) != 0) {
            iVar4 = (**(code **)(*param_1 + 0x88))(param_1,iVar1,iVar3,param_4);
            if ((iVar4 == 0) ||
               (iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar8 + 4,iVar8 + 4,iVar1,param_4),
               iVar4 == 0)) goto LAB_00630000;
            iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar1,iVar1,iVar3,param_4);
            if ((iVar4 == 0) ||
               (iVar4 = (**(code **)(*param_1 + 0x84))
                                  (param_1,iVar8 + 0x18,iVar8 + 0x18,iVar1,param_4), iVar4 == 0))
            goto LAB_00630000;
            if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
              iVar3 = (*(code *)PTR_BN_set_word_006a7730)(iVar3,1,param_4);
              if (iVar3 == 0) goto LAB_00630000;
              *(undefined4 *)(iVar8 + 0x40) = 1;
            }
            else {
              iVar3 = (**(code **)(*param_1 + 0x98))(param_1);
              if (iVar3 == 0) goto LAB_00630000;
              *(undefined4 *)(iVar8 + 0x40) = 1;
            }
          }
          iVar9 = iVar9 + 1;
          param_3 = param_3 + 1;
        } while (param_2 != iVar9);
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
      goto LAB_00630004;
    }
  }
LAB_00630000:
  uVar6 = 0;
LAB_00630004:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  if (iVar11 != 0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar11);
  }
  if (*piVar2 != 0) {
    iVar1 = 0;
    piVar5 = piVar2;
    do {
      piVar5 = piVar5 + 1;
      iVar1 = iVar1 + 1;
      (*(code *)PTR_BN_clear_free_006a7fa8)();
      if (param_2 == iVar1) break;
    } while (*piVar5 != 0);
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
  return uVar6;
}

