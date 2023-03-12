
undefined4 *
srp_create_user(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char **ppcVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined auStack_42c [1024];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar7 = (undefined4 *)0x1;
  pcVar6 = (char *)0x400;
  local_438 = 0;
  local_434 = param_6;
  local_430 = param_1;
  iVar2 = password_callback(auStack_42c,0x400,1,&local_434);
  if (iVar2 < 1) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    if (param_8 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (param_7,"Creating\n user=\"%s\"\n g=\"%s\"\n N=\"%s\"\n",param_1,param_4,param_5);
    }
    puVar7 = &local_438;
    puVar3 = (undefined4 *)
             (*(code *)PTR_SRP_create_verifier_006a9018)
                       (param_1,auStack_42c,puVar7,param_2,param_5,param_4);
    if (puVar3 == (undefined4 *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_7,"Internal error creating SRP verifier\n");
    }
    else {
      *param_3 = local_438;
    }
    pcVar6 = "s\n";
    if (1 < param_8) {
      pcVar6 = "gNid=%s salt =\"%s\"\n verifier =\"%s\"\n";
      puVar7 = puVar3;
      (*(code *)PTR_BIO_printf_006a7f38)
                (param_7,"gNid=%s salt =\"%s\"\n verifier =\"%s\"\n",puVar3,local_438,*param_2);
    }
  }
  if (local_2c != *(int *)puVar1) {
    iVar2 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (pcVar6 == (char *)0x0) {
      return (undefined4 *)0xffffffff;
    }
    puVar3 = (undefined4 *)0x0;
    if (puVar7 == (undefined4 *)0x49) {
      while (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar2 + 4) + 4)),
            (int)puVar3 < iVar4) {
        ppcVar5 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                     (*(undefined4 *)(*(int *)(iVar2 + 4) + 4),puVar3);
        if (**ppcVar5 == 'I') {
          iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar6,ppcVar5[3]);
          if (iVar4 == 0) {
            return puVar3;
          }
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
        else {
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
      }
    }
    else {
      for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar2 + 4) + 4)),
          (int)puVar3 < iVar4; puVar3 = (undefined4 *)((int)puVar3 + 1)) {
        ppcVar5 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                     (*(undefined4 *)(*(int *)(iVar2 + 4) + 4),puVar3);
        if ((**ppcVar5 != 'I') &&
           (iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar6,ppcVar5[3]), iVar4 == 0)) {
          return puVar3;
        }
      }
    }
    return (undefined4 *)0xffffffff;
  }
  return puVar3;
}

