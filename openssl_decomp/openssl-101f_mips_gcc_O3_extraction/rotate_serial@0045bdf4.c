
bool rotate_serial(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  bool bVar8;
  undefined auStack_524 [256];
  undefined auStack_424 [1024];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_strlen_006aab30)();
  iVar3 = (*(code *)PTR_strlen_006aab30)(param_3);
  iVar4 = (*(code *)PTR_strlen_006aab30)(param_2);
  iVar5 = iVar2 + iVar4;
  if (iVar2 + iVar4 <= iVar2 + iVar3) {
    iVar5 = iVar2 + iVar3;
  }
  if (iVar5 < 0xff) {
    (*(code *)PTR_BIO_snprintf_006a8060)(auStack_524,0x100,"%s.%s",param_1,param_2);
    (*(code *)PTR_BIO_snprintf_006a8060)(auStack_424,0x100,"%s.%s",param_1,param_3);
    iVar5 = (*(code *)PTR_rename_006aab3c)(param_1,auStack_424);
    if (iVar5 < 0) {
      piVar6 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if ((*piVar6 != 2) && (*piVar6 != 0x14)) {
        pcVar7 = "unable to rename %s to %s\n";
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",param_1,
                   auStack_424);
        (*(code *)PTR_perror_006aab88)("reason");
        bVar8 = false;
        goto LAB_0045bf08;
      }
    }
    pcVar7 = param_1;
    iVar5 = (*(code *)PTR_rename_006aab3c)(auStack_524);
    if (iVar5 < 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_524,
                 param_1);
      (*(code *)PTR_perror_006aab88)("reason");
      (*(code *)PTR_rename_006aab3c)(auStack_424);
      bVar8 = false;
      pcVar7 = param_1;
    }
    else {
      bVar8 = true;
    }
  }
  else {
    pcVar7 = "file name too long\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    bVar8 = false;
  }
LAB_0045bf08:
  if (local_24 == *(int *)puVar1) {
    return bVar8;
  }
  iVar5 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar5 == 0) {
    iVar2 = (*(code *)PTR_BN_new_006a82b4)();
    if (iVar2 == 0) {
      return false;
    }
    iVar3 = (*(code *)PTR_BN_pseudo_rand_006a8cd8)(iVar2,0x40,0,0);
    if (iVar3 == 0) {
      bVar8 = false;
      goto LAB_0045c098;
    }
    if (pcVar7 == (char *)0x0) {
      bVar8 = true;
      goto LAB_0045c098;
    }
  }
  else {
    iVar2 = (*(code *)PTR_BN_pseudo_rand_006a8cd8)();
    if (iVar2 == 0) {
      return false;
    }
    iVar2 = iVar5;
    if (pcVar7 == (char *)0x0) {
      return true;
    }
  }
  iVar3 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(iVar2,pcVar7);
  bVar8 = iVar3 != 0;
  if (iVar5 != 0) {
    return bVar8;
  }
LAB_0045c098:
  (*(code *)PTR_BN_free_006a811c)(iVar2);
  return bVar8;
}

