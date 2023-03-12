
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pvVar5 = param_1->ptr;
  local_44 = 0x1c;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_2 == 0) {
    iVar3 = 0;
    goto LAB_00529b98;
  }
  piVar2 = (int *)(*(code *)PTR___errno_location_006a99e8)();
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
    iVar3 = (*(code *)PTR_getsockopt_006a9a90)
                      (param_1->num,0xffff,0x1006,(int)pvVar5 + 0x30,&local_58);
    if (iVar3 < 0) {
      (*(code *)PTR_perror_006a9a80)("getsockopt");
    }
    (*(code *)PTR_gettimeofday_006a9acc)(&local_54,0);
    local_4c = *(int *)((int)pvVar5 + 0x28);
    if (*(int *)((int)pvVar5 + 0x2c) < local_50) {
      local_4c = local_4c + -1;
      local_50 = 1000000 - local_50;
      if (local_54 <= local_4c) goto LAB_00529c08;
LAB_00529aa0:
      local_48 = 1;
      local_4c = 0;
      iVar3 = *(int *)((int)pvVar5 + 0x30);
      if (iVar3 == 0) goto LAB_00529abc;
LAB_00529c18:
      if (iVar3 <= local_4c) goto LAB_00529c24;
LAB_00529ad0:
      iVar3 = (*(code *)PTR_setsockopt_006a9b2c)(param_1->num,0xffff,0x1006,&local_4c,8);
      if (iVar3 < 0) {
        (*(code *)PTR_perror_006a9a80)("setsockopt");
      }
    }
    else {
      local_50 = -local_50;
      if (local_4c < local_54) goto LAB_00529aa0;
LAB_00529c08:
      local_48 = *(int *)((int)pvVar5 + 0x2c) + local_50;
      local_4c = local_4c - local_54;
      iVar3 = *(int *)((int)pvVar5 + 0x30);
      if (iVar3 != 0) goto LAB_00529c18;
LAB_00529abc:
      if (*(int *)((int)pvVar5 + 0x34) == 0) goto LAB_00529ad0;
LAB_00529c24:
      if ((iVar3 == local_4c) && (local_48 <= *(int *)((int)pvVar5 + 0x34))) goto LAB_00529ad0;
    }
    iVar3 = param_1->num;
  }
  iVar3 = (*(code *)PTR_recvfrom_006a9ab8)(iVar3,param_2,param_3,0,&local_40,&local_44);
  if (*(int *)((int)pvVar5 + 0x1c) == 0) {
    if (iVar3 < 0) {
      BIO_clear_flags(param_1,0xf);
      if (iVar3 + 1U < 2) {
        iVar4 = *piVar2;
        goto LAB_00529c70;
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
LAB_00529c70:
      if (iVar4 == 0x47) {
LAB_00529c9c:
        BIO_set_flags(param_1,9);
        *(int *)((int)pvVar5 + 0x20) = *piVar2;
      }
      else if (iVar4 < 0x48) {
        if ((iVar4 == 4) || (iVar4 == 0xb)) goto LAB_00529c9c;
      }
      else if (iVar4 - 0x95U < 2) goto LAB_00529c9c;
    }
  }
  pvVar5 = param_1->ptr;
  if (((0 < *(int *)((int)pvVar5 + 0x28)) || (0 < *(int *)((int)pvVar5 + 0x2c))) &&
     (iVar4 = (*(code *)PTR_setsockopt_006a9b2c)(param_1->num,0xffff,0x1006,(int)pvVar5 + 0x30,8),
     iVar4 < 0)) {
    (*(code *)PTR_perror_006a9a80)("setsockopt");
  }
LAB_00529b98:
  if (local_24 == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x10) == 0) {
      iVar3 = *(int *)(iVar3 + 0x20);
    }
    else {
      if (*(int *)(iVar3 + 0xc) == 0) {
        *(undefined4 *)(iVar3 + 0xc) = 0;
        *(undefined4 *)(iVar3 + 0x14) = 0;
      }
      else {
        (*(code *)PTR_shutdown_006a995c)(*(undefined4 *)(iVar3 + 0x1c),2);
        (*(code *)PTR_close_006a994c)(*(undefined4 *)(iVar3 + 0x1c));
        *(undefined4 *)(iVar3 + 0xc) = 0;
        *(undefined4 *)(iVar3 + 0x14) = 0;
      }
      iVar3 = *(int *)(iVar3 + 0x20);
    }
    if (iVar3 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      return 1;
    }
    return 1;
  }
  return 0;
}

