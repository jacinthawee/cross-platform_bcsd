
uint pkey_hmac_ctrl_str(int param_1,int *param_2,int *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_3 == (int *)0x0) {
    uVar6 = 0;
  }
  else {
    piVar5 = param_3;
    if ((((*(char *)param_2 == 'k') && (*(char *)((int)param_2 + 1) == 'e')) &&
        (*(char *)((int)param_2 + 2) == 'y')) &&
       (piVar5 = (int *)0xffffffff, *(char *)((int)param_2 + 3) == '\0')) {
      iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(*(int *)(param_1 + 0x14) + 4);
      uVar6 = (uint)(iVar2 != 0);
      param_2 = param_3;
    }
    else {
      pcVar4 = "hexkey";
      uVar6 = (*(code *)PTR_strcmp_006aac20)(param_2,"hexkey",piVar5);
      if (uVar6 == 0) {
        param_2 = &local_20;
        piVar5 = (int *)(*(code *)PTR_string_to_hex_006a848c)(param_3);
        if (piVar5 != (int *)0x0) {
          param_2 = piVar5;
          if (-2 < local_20) {
            iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(*(int *)(param_1 + 0x14) + 4);
            uVar6 = (uint)(iVar2 != 0);
          }
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5);
        }
      }
      else {
        uVar6 = 0xfffffffe;
        param_2 = (int *)pcVar4;
      }
    }
  }
  if (local_1c != *(int *)puVar1) {
    iVar2 = local_1c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xe4,"hm_pmeth.c",0x4e);
    puVar1 = PTR_HMAC_CTX_init_006a8b0c;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      puVar7 = puVar3 + 5;
      puVar3[3] = 0;
      puVar3[1] = 0;
      puVar3[4] = 0;
      puVar3[2] = 4;
      (*(code *)puVar1)(puVar7);
      *(undefined4 **)(iVar2 + 0x14) = puVar3;
      puVar8 = (undefined4 *)param_2[5];
      *(undefined4 *)(iVar2 + 0x24) = 0;
      puVar1 = PTR_HMAC_CTX_init_006a8b0c;
      *puVar3 = *puVar8;
      (*(code *)puVar1)(puVar7);
      iVar2 = (*(code *)PTR_HMAC_CTX_copy_006a9d94)(puVar7,puVar8 + 5);
      if (iVar2 != 0) {
        if (puVar8[3] == 0) {
          return 1;
        }
        iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(puVar3 + 1,puVar8[3],puVar8[1]);
        return (uint)(iVar2 != 0);
      }
    }
    return 0;
  }
  return uVar6;
}

