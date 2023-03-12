
undefined4 rotate_index(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined auStack_52c [256];
  undefined auStack_42c [256];
  undefined auStack_32c [256];
  undefined auStack_22c [256];
  undefined auStack_12c [256];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_strlen_006aab30)();
  iVar3 = (*(code *)PTR_strlen_006aab30)(param_3);
  iVar4 = (*(code *)PTR_strlen_006aab30)(param_2);
  iVar5 = iVar2 + iVar4;
  if (iVar2 + iVar4 <= iVar2 + iVar3) {
    iVar5 = iVar2 + iVar3;
  }
  if (0xf9 < iVar5) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"file name too long\n");
    uVar6 = 0;
    goto LAB_0045c9cc;
  }
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_12c,0x100,"%s.attr",param_1);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_32c,0x100,"%s.attr.%s",param_1,param_2);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_52c,0x100,"%s.%s",param_1,param_2);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_42c,0x100,"%s.%s",param_1,param_3);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_22c,0x100,"%s.attr.%s",param_1,param_3);
  iVar5 = (*(code *)PTR_rename_006aab3c)(param_1,auStack_42c);
  if (iVar5 < 0) {
    piVar7 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
    if ((*piVar7 != 2) && (*piVar7 != 0x14)) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",param_1,
                 auStack_42c);
      (*(code *)PTR_perror_006aab88)("reason");
      uVar6 = 0;
      goto LAB_0045c9cc;
    }
  }
  iVar5 = (*(code *)PTR_rename_006aab3c)(auStack_52c,param_1);
  if (iVar5 < 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_52c,param_1
              );
    (*(code *)PTR_perror_006aab88)("reason");
  }
  else {
    iVar5 = (*(code *)PTR_rename_006aab3c)(auStack_12c,auStack_22c);
    if (iVar5 < 0) {
      piVar7 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if ((*piVar7 == 2) || (*piVar7 == 0x14)) goto LAB_0045c9b4;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_12c,
                 auStack_22c);
      (*(code *)PTR_perror_006aab88)("reason");
    }
    else {
LAB_0045c9b4:
      iVar5 = (*(code *)PTR_rename_006aab3c)(auStack_32c,auStack_12c);
      if (-1 < iVar5) {
        uVar6 = 1;
        goto LAB_0045c9cc;
      }
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_32c,
                 auStack_12c);
      (*(code *)PTR_perror_006aab88)("reason");
      (*(code *)PTR_rename_006aab3c)(auStack_22c,auStack_12c);
    }
    (*(code *)PTR_rename_006aab3c)(param_1,auStack_52c);
  }
  (*(code *)PTR_rename_006aab3c)(auStack_42c,param_1);
  uVar6 = 0;
LAB_0045c9cc:
  if (local_2c == *(int *)puVar1) {
    return uVar6;
  }
  iVar5 = local_2c;
  uVar6 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar5 == 0) {
    return uVar6;
  }
  if (*(int *)(iVar5 + 4) != 0) {
    (*(code *)PTR_TXT_DB_free_006a8ce0)();
  }
                    /* WARNING: Could not recover jumptable at 0x0045cc04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
  return uVar6;
}

