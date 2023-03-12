
undefined4 save_index(int *param_1,char *param_2,int *param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  undefined *unaff_s0;
  int unaff_s2;
  undefined *unaff_s6;
  int *unaff_s7;
  undefined auStack_87c [256];
  undefined auStack_77c [256];
  undefined auStack_67c [256];
  undefined auStack_57c [256];
  undefined auStack_47c [256];
  int iStack_37c;
  undefined *puStack_378;
  int *piStack_374;
  int iStack_370;
  char *pcStack_36c;
  undefined *puStack_368;
  int *piStack_364;
  undefined *puStack_360;
  int *piStack_35c;
  undefined auStack_32c [256];
  undefined auStack_22c [256];
  int aiStack_12c [64];
  int local_2c;
  
  puStack_368 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar8 = param_2;
  piVar9 = param_3;
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
    uVar2 = 0;
  }
  else {
    unaff_s0 = (undefined *)(*(code *)PTR_strlen_006aab30)(param_1);
    iVar4 = (*(code *)PTR_strlen_006aab30)(param_2);
    unaff_s2 = iVar3;
    if ((int)(unaff_s0 + iVar4) < 0xfa) {
      unaff_s7 = aiStack_12c;
      (*(code *)PTR_BIO_snprintf_006a8060)(unaff_s7,0x100,"%s.attr",param_1);
      unaff_s6 = auStack_22c;
      unaff_s0 = auStack_32c;
      (*(code *)PTR_BIO_snprintf_006a8060)(unaff_s6,0x100,"%s.attr.%s",param_1);
      (*(code *)PTR_BIO_snprintf_006a8060)(unaff_s0,0x100,"%s.%s",param_1);
      piVar9 = (int *)&DAT_00000005;
      iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6c,5,unaff_s0);
      if (iVar4 < 1) {
        (*(code *)PTR_perror_006aab88)(param_1);
        piVar9 = param_1;
LAB_0045c7a4:
        pcVar8 = "unable to open \'%s\'\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        uVar2 = 0;
      }
      else {
        pcVar8 = (char *)param_3[1];
        iVar4 = (*(code *)PTR_TXT_DB_write_006a818c)(iVar3);
        if (iVar4 < 1) {
          uVar2 = 0;
        }
        else {
          (*(code *)PTR_BIO_free_006a7f70)(iVar3);
          uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
          unaff_s0 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar2);
          iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s0,0x6c,5,unaff_s6);
          if (iVar3 < 1) {
            (*(code *)PTR_perror_006aab88)(unaff_s7);
            piVar9 = unaff_s7;
            goto LAB_0045c7a4;
          }
          if (*param_3 == 0) {
            piVar9 = (int *)&DAT_0064033c;
          }
          else {
            piVar9 = (int *)&DAT_00640338;
          }
          pcVar8 = "unique_subject = %s\n";
          (*(code *)PTR_BIO_printf_006a7f38)(unaff_s0);
          (*(code *)PTR_BIO_free_006a7f70)(unaff_s0);
          uVar2 = 1;
        }
      }
    }
    else {
      pcVar8 = "file name too long\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      uVar2 = 0;
    }
  }
  if (local_2c == *(int *)puStack_368) {
    return uVar2;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_37c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_378 = unaff_s0;
  piStack_374 = param_1;
  iStack_370 = unaff_s2;
  pcStack_36c = param_2;
  piStack_364 = param_3;
  puStack_360 = unaff_s6;
  piStack_35c = unaff_s7;
  iVar5 = (*(code *)PTR_strlen_006aab30)();
  iVar6 = (*(code *)PTR_strlen_006aab30)(piVar9);
  iVar7 = (*(code *)PTR_strlen_006aab30)(pcVar8);
  iVar3 = iVar5 + iVar7;
  if (iVar5 + iVar7 <= iVar5 + iVar6) {
    iVar3 = iVar5 + iVar6;
  }
  if (0xf9 < iVar3) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"file name too long\n");
    uVar2 = 0;
    goto LAB_0045c9cc;
  }
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_47c,0x100,"%s.attr",iVar4);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_67c,0x100,"%s.attr.%s",iVar4,pcVar8);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_87c,0x100,"%s.%s",iVar4,pcVar8);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_77c,0x100,"%s.%s",iVar4,piVar9);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_57c,0x100,"%s.attr.%s",iVar4,piVar9);
  iVar3 = (*(code *)PTR_rename_006aab3c)(iVar4,auStack_77c);
  if (iVar3 < 0) {
    piVar9 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
    if ((*piVar9 != 2) && (*piVar9 != 0x14)) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",iVar4,auStack_77c
                );
      (*(code *)PTR_perror_006aab88)("reason");
      uVar2 = 0;
      goto LAB_0045c9cc;
    }
  }
  iVar3 = (*(code *)PTR_rename_006aab3c)(auStack_87c,iVar4);
  if (iVar3 < 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_87c,iVar4);
    (*(code *)PTR_perror_006aab88)("reason");
  }
  else {
    iVar3 = (*(code *)PTR_rename_006aab3c)(auStack_47c,auStack_57c);
    if (iVar3 < 0) {
      piVar9 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if ((*piVar9 == 2) || (*piVar9 == 0x14)) goto LAB_0045c9b4;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_47c,
                 auStack_57c);
      (*(code *)PTR_perror_006aab88)("reason");
    }
    else {
LAB_0045c9b4:
      iVar3 = (*(code *)PTR_rename_006aab3c)(auStack_67c,auStack_47c);
      if (-1 < iVar3) {
        uVar2 = 1;
        goto LAB_0045c9cc;
      }
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_67c,
                 auStack_47c);
      (*(code *)PTR_perror_006aab88)("reason");
      (*(code *)PTR_rename_006aab3c)(auStack_57c,auStack_47c);
    }
    (*(code *)PTR_rename_006aab3c)(iVar4,auStack_87c);
  }
  (*(code *)PTR_rename_006aab3c)(auStack_77c,iVar4);
  uVar2 = 0;
LAB_0045c9cc:
  if (iStack_37c == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = iStack_37c;
  uVar2 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar3 == 0) {
    return uVar2;
  }
  if (*(int *)(iVar3 + 4) != 0) {
    (*(code *)PTR_TXT_DB_free_006a8ce0)();
  }
                    /* WARNING: Could not recover jumptable at 0x0045cc04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
  return uVar2;
}

