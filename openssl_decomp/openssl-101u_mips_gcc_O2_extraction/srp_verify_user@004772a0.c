
undefined4 *
srp_verify_user(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char **ppcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uStack_898;
  undefined4 uStack_894;
  int iStack_890;
  undefined auStack_88c [1024];
  int iStack_48c;
  undefined4 *puStack_488;
  undefined4 uStack_484;
  undefined *puStack_480;
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 *puStack_470;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  int iStack_444;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined auStack_424 [1024];
  int local_24;
  
  puStack_480 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar7 = &DAT_00000400;
  puVar5 = &local_42c;
  puVar9 = (undefined4 *)0x0;
  local_430 = 0;
  local_42c = param_6;
  local_434 = param_3;
  local_428 = param_1;
  iVar3 = password_callback(auStack_424);
  if (iVar3 < 1) {
    puStack_488 = (undefined4 *)0x0;
  }
  else {
    if (param_8 != 0) {
      local_448 = param_5;
      (*(code *)PTR_BIO_printf_006a6e38)
                (param_7,
                 "Validating\n   user=\"%s\"\n srp_verifier=\"%s\"\n srp_usersalt=\"%s\"\n g=\"%s\"\n N=\"%s\"\n"
                 ,param_1,param_2);
    }
    (*(code *)PTR_BIO_printf_006a6e38)(param_7,"Pass %s\n",auStack_424);
    puVar5 = &local_430;
    puVar9 = &local_434;
    local_450 = param_5;
    puStack_488 = (undefined4 *)(*(code *)PTR_SRP_create_verifier_006a7f28)(param_1,auStack_424);
    uVar2 = local_430;
    local_44c = param_4;
    if (puStack_488 == (undefined4 *)0x0) {
      pcVar7 = "Internal error validating SRP verifier\n";
      (*(code *)PTR_BIO_printf_006a6e38)(param_7);
    }
    else {
      pcVar7 = (char *)param_2;
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(local_430);
      if (iVar3 != 0) {
        puStack_488 = (undefined4 *)0x0;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(uVar2);
      param_1 = uVar2;
    }
  }
  if (local_24 == *(int *)puStack_480) {
    return puStack_488;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uStack_47c = param_7;
  iStack_48c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_478 = param_5;
  puVar10 = (undefined4 *)0x1;
  pcVar8 = (char *)0x400;
  uStack_898 = 0;
  uStack_894 = local_44c;
  iStack_890 = iVar3;
  uStack_484 = param_1;
  uStack_474 = param_4;
  puStack_470 = param_2;
  iVar4 = password_callback(auStack_88c,0x400,1,&uStack_894);
  if (iVar4 < 1) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    if (iStack_444 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (local_448,"Creating\n user=\"%s\"\n g=\"%s\"\n N=\"%s\"\n",iVar3,puVar5,local_450);
    }
    puVar10 = &uStack_898;
    puVar5 = (undefined4 *)
             (*(code *)PTR_SRP_create_verifier_006a7f28)
                       (iVar3,auStack_88c,puVar10,pcVar7,local_450,puVar5);
    if (puVar5 == (undefined4 *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(local_448,"Internal error creating SRP verifier\n");
    }
    else {
      *puVar9 = uStack_898;
    }
    pcVar8 = "-check_ss_sig";
    if (1 < iStack_444) {
      pcVar8 = "gNid=%s salt =\"%s\"\n verifier =\"%s\"\n";
      puVar10 = puVar5;
      (*(code *)PTR_BIO_printf_006a6e38)
                (local_448,"gNid=%s salt =\"%s\"\n verifier =\"%s\"\n",puVar5,uStack_898,
                 *(undefined4 *)pcVar7);
    }
  }
  if (iStack_48c != *(int *)puVar1) {
    iVar3 = iStack_48c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (pcVar8 == (char *)0x0) {
      return (undefined4 *)0xffffffff;
    }
    puVar9 = (undefined4 *)0x0;
    if (puVar10 == (undefined4 *)0x49) {
      while (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(iVar3 + 4) + 4)),
            (int)puVar9 < iVar4) {
        ppcVar6 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                     (*(undefined4 *)(*(int *)(iVar3 + 4) + 4),puVar9);
        if (**ppcVar6 == 'I') {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,ppcVar6[3]);
          if (iVar4 == 0) {
            return puVar9;
          }
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        else {
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
      }
    }
    else {
      for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(iVar3 + 4) + 4)),
          (int)puVar9 < iVar4; puVar9 = (undefined4 *)((int)puVar9 + 1)) {
        ppcVar6 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                     (*(undefined4 *)(*(int *)(iVar3 + 4) + 4),puVar9);
        if ((**ppcVar6 != 'I') &&
           (iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,ppcVar6[3]), iVar4 == 0)) {
          return puVar9;
        }
      }
    }
    return (undefined4 *)0xffffffff;
  }
  return puVar5;
}

