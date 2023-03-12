
int dgram_read(BIO *param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pvVar5 = param_1->ptr;
  local_44 = 0x1c;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_2 == 0) {
    iVar3 = 0;
    goto LAB_0052d568;
  }
  piVar2 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  *piVar2 = 0;
  local_40 = 0;
  local_58 = 0;
  local_3c = 0;
  local_38 = 0;
  if ((*(int *)((int)pvVar5 + 0x28) < 1) && (*(int *)((int)pvVar5 + 0x2c) < 1)) {
    iVar3 = param_1->num;
  }
  else {
    local_58 = 8;
    iVar3 = (*(code *)PTR_getsockopt_006aab98)
                      (param_1->num,0xffff,0x1006,(int)pvVar5 + 0x30,&local_58);
    if (iVar3 < 0) {
      (*(code *)PTR_perror_006aab88)("getsockopt");
    }
    (*(code *)PTR_gettimeofday_006aabd4)(&local_54,0);
    local_4c = *(int *)((int)pvVar5 + 0x28) - local_54;
    local_48 = *(int *)((int)pvVar5 + 0x2c) - local_50;
    if (local_48 < 0) {
      local_4c = local_4c + -1;
      local_48 = local_48 + 1000000;
    }
    if (local_4c < 0) {
      local_4c = 0;
      local_48 = 1;
    }
    iVar3 = *(int *)((int)pvVar5 + 0x30);
    if (iVar3 == 0) {
      if (*(int *)((int)pvVar5 + 0x34) != 0) goto LAB_0052d5c0;
LAB_0052d4a0:
      iVar3 = (*(code *)PTR_setsockopt_006aac34)(param_1->num,0xffff,0x1006,&local_4c,8);
      if (iVar3 < 0) {
        (*(code *)PTR_perror_006aab88)("setsockopt");
      }
    }
    else {
      if (local_4c < iVar3) goto LAB_0052d4a0;
LAB_0052d5c0:
      if ((local_4c == iVar3) && (local_48 <= *(int *)((int)pvVar5 + 0x34))) goto LAB_0052d4a0;
    }
    iVar3 = param_1->num;
  }
  iVar3 = (*(code *)PTR_recvfrom_006aabc0)(iVar3,param_2,param_3,0,&local_40,&local_44);
  if (*(int *)((int)pvVar5 + 0x1c) == 0) {
    if (iVar3 < 0) {
      BIO_clear_flags(param_1,0xf);
      if (iVar3 + 1U < 2) {
        iVar4 = *piVar2;
        goto LAB_0052d60c;
      }
    }
    else {
      BIO_ctrl(param_1,0x2c,0,&local_40);
      BIO_clear_flags(param_1,0xf);
    }
  }
  else {
    BIO_clear_flags(param_1,0xf);
    if ((iVar3 < 0) && (iVar3 + 1U < 2)) {
      iVar4 = *piVar2;
LAB_0052d60c:
      if (iVar4 == 0x47) {
LAB_0052d638:
        BIO_set_flags(param_1,9);
        *(int *)((int)pvVar5 + 0x20) = *piVar2;
      }
      else if (iVar4 < 0x48) {
        if ((iVar4 == 4) || (iVar4 == 0xb)) goto LAB_0052d638;
      }
      else if (iVar4 - 0x95U < 2) goto LAB_0052d638;
    }
  }
  pvVar5 = param_1->ptr;
  if (((0 < *(int *)((int)pvVar5 + 0x28)) || (0 < *(int *)((int)pvVar5 + 0x2c))) &&
     (iVar4 = (*(code *)PTR_setsockopt_006aac34)(param_1->num,0xffff,0x1006,(int)pvVar5 + 0x30,8),
     iVar4 < 0)) {
    (*(code *)PTR_perror_006aab88)("setsockopt");
  }
LAB_0052d568:
  if (local_24 == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar3 == 0) {
    return 0;
  }
  if (*(int *)(iVar3 + 0x10) == 0) {
    iVar3 = *(int *)(iVar3 + 0x20);
  }
  else {
    if (*(int *)(iVar3 + 0xc) == 0) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x14) = 0;
    }
    else {
      (*(code *)PTR_shutdown_006aaa6c)(*(undefined4 *)(iVar3 + 0x1c),2);
      (*(code *)PTR_close_006aaa5c)(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x14) = 0;
    }
    iVar3 = *(int *)(iVar3 + 0x20);
  }
  if (iVar3 == 0) {
    return 1;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)();
  return 1;
}

