
uint save_serial(char *param_1,int param_2,char *param_3,uint *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  int unaff_s0;
  int unaff_s5;
  undefined *unaff_s6;
  undefined auStack_66c [256];
  undefined auStack_56c [1024];
  int iStack_16c;
  int iStack_168;
  undefined *puStack_164;
  uint uStack_160;
  uint *puStack_15c;
  char *pcStack_158;
  int iStack_154;
  undefined *puStack_150;
  code *pcStack_14c;
  int local_138;
  undefined *local_130;
  undefined auStack_124 [256];
  char *local_24;
  
  puStack_164 = PTR___stack_chk_guard_006a9ae8;
  local_130 = &_gp;
  local_24 = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcVar11 = param_3;
  if (param_2 == 0) {
    iVar2 = (*(code *)PTR_strlen_006a9a24)();
    if (iVar2 < 0x100) {
      pcVar11 = (char *)0x100;
      pcVar10 = param_1;
      (**(code **)(local_130 + -0x7e7c))(auStack_124);
      goto LAB_0045c6c0;
    }
LAB_0045c7cc:
    uStack_160 = 0;
    pcVar10 = "file name too long\n";
    (**(code **)(local_130 + -0x7fa8))(**(undefined4 **)(local_130 + -0x7fa4));
  }
  else {
    unaff_s0 = (*(code *)PTR_strlen_006a9a24)();
    iVar2 = (**(code **)(local_130 + -0x53bc))(param_2);
    unaff_s5 = param_2;
    if (0xff < unaff_s0 + iVar2 + 1) goto LAB_0045c7cc;
    pcVar11 = "%s.%s";
    pcVar10 = (char *)0x100;
    local_138 = param_2;
    (**(code **)(local_130 + -0x7e80))(auStack_124,0x100,"%s.%s",param_1);
LAB_0045c6c0:
    unaff_s6 = auStack_124;
    uVar3 = (**(code **)(local_130 + -0x7f40))();
    unaff_s0 = (**(code **)(local_130 + -0x7f3c))(uVar3);
    if (unaff_s0 == 0) {
      uStack_160 = 0;
      (**(code **)(local_130 + -0x7fa0))(**(undefined4 **)(local_130 + -0x7fa4));
    }
    else {
      pcVar11 = (char *)0x5;
      pcVar10 = (char *)0x6c;
      iVar2 = (**(code **)(local_130 + -0x7fc8))(unaff_s0,0x6c,5,unaff_s6);
      if (iVar2 < 1) {
        uStack_160 = 0;
        (**(code **)(local_130 + -0x5360))(param_1);
      }
      else {
        uVar4 = (**(code **)(local_130 + -0x7cec))(param_3,0);
        if (uVar4 == 0) {
          pcVar10 = "error converting serial to ASN.1 format\n";
          (**(code **)(local_130 + -0x7fa8))(**(undefined4 **)(local_130 + -0x7fa4));
          uStack_160 = uVar4;
        }
        else {
          (**(code **)(local_130 + -0x77f0))(unaff_s0,uVar4);
          pcVar10 = "\n";
          (**(code **)(local_130 + -0x7e88))(unaff_s0);
          if (param_4 == (uint *)0x0) {
            (**(code **)(local_130 + -0x7f6c))(unaff_s0);
            uStack_160 = 1;
            (**(code **)(local_130 + -0x7f4c))(uVar4);
            goto LAB_0045c76c;
          }
          *param_4 = uVar4;
          uStack_160 = 1;
        }
      }
      (**(code **)(local_130 + -0x7f6c))(unaff_s0);
    }
  }
LAB_0045c76c:
  if (local_24 == *(char **)puStack_164) {
    return uStack_160;
  }
  pcStack_14c = rotate_serial;
  pcVar9 = local_24;
  (**(code **)(local_130 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_16c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_168 = unaff_s0;
  puStack_15c = param_4;
  pcStack_158 = param_3;
  iStack_154 = unaff_s5;
  puStack_150 = unaff_s6;
  iVar5 = (*(code *)PTR_strlen_006a9a24)();
  iVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar11);
  iVar7 = (*(code *)PTR_strlen_006a9a24)(pcVar10);
  iVar2 = iVar5 + iVar7;
  if (iVar5 + iVar7 <= iVar5 + iVar6) {
    iVar2 = iVar5 + iVar6;
  }
  if (iVar2 < 0xff) {
    (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_66c,0x100,"%s.%s",pcVar9,pcVar10);
    (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_56c,0x100,"%s.%s",pcVar9,pcVar11);
    iVar2 = (*(code *)PTR_rename_006a9a30)(pcVar9,auStack_56c);
    if (iVar2 < 0) {
      piVar8 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      if ((*piVar8 != 2) && (*piVar8 != 0x14)) {
        pcVar11 = "unable to rename %s to %s\n";
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"unable to rename %s to %s\n",pcVar9,
                   auStack_56c);
        (*(code *)PTR_perror_006a9a80)("reason");
        uVar4 = 0;
        goto LAB_0045c998;
      }
    }
    pcVar11 = pcVar9;
    iVar2 = (*(code *)PTR_rename_006a9a30)(auStack_66c);
    if (iVar2 < 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"unable to rename %s to %s\n",auStack_66c,
                 pcVar9);
      (*(code *)PTR_perror_006a9a80)("reason");
      (*(code *)PTR_rename_006a9a30)(auStack_56c);
      uVar4 = 0;
      pcVar11 = pcVar9;
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    pcVar11 = "file name too long\n";
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
    uVar4 = 0;
  }
LAB_0045c998:
  if (iStack_16c == *(int *)puVar1) {
    return uVar4;
  }
  iVar2 = iStack_16c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar2 == 0) {
    iVar5 = (*(code *)PTR_BN_new_006a71b4)();
    if (iVar5 == 0) {
      return 0;
    }
    iVar6 = (*(code *)PTR_BN_pseudo_rand_006a7bec)(iVar5,0x40,0,0);
    if (iVar6 == 0) {
      uVar4 = 0;
      goto LAB_0045cb28;
    }
    if (pcVar11 == (char *)0x0) {
      uVar4 = 1;
      goto LAB_0045cb28;
    }
  }
  else {
    iVar5 = (*(code *)PTR_BN_pseudo_rand_006a7bec)();
    if (iVar5 == 0) {
      return 0;
    }
    iVar5 = iVar2;
    if (pcVar11 == (char *)0x0) {
      return 1;
    }
  }
  iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar5,pcVar11);
  uVar4 = (uint)(iVar6 != 0);
  if (iVar2 != 0) {
    return uVar4;
  }
LAB_0045cb28:
  (*(code *)PTR_BN_free_006a701c)(iVar5);
  return uVar4;
}

