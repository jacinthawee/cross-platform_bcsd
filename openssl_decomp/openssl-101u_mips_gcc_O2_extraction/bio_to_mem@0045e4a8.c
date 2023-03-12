
undefined4 bio_to_mem(undefined4 param_1,undefined *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined auStack_42c [1024];
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar6 = param_2;
  uVar1 = (*(code *)PTR_BIO_s_mem_006a7c18)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    do {
      if (param_2 == (undefined *)0xffffffff) {
        puVar6 = &DAT_00000400;
      }
      else {
        puVar6 = &DAT_00000400;
        if ((int)param_2 < 0x400) {
          puVar6 = param_2;
        }
      }
      iVar3 = (*(code *)PTR_BIO_read_006a74c0)(param_3,auStack_42c,puVar6);
      if (iVar3 < 1) break;
      puVar6 = auStack_42c;
      iVar4 = (*(code *)PTR_BIO_write_006a6e14)(iVar2,auStack_42c,iVar3);
      if (iVar3 != iVar4) {
        (*(code *)PTR_BIO_free_006a6e70)(iVar2);
        uVar1 = 0xffffffff;
        goto LAB_0045e5c0;
      }
      param_2 = param_2 + -iVar3;
    } while (param_2 != (undefined *)0x0);
    uVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,3,0,param_1);
    puVar6 = (undefined *)0x200;
    (*(code *)PTR_BIO_set_flags_006a7570)(iVar2,0x200);
    (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  }
LAB_0045e5c0:
  if (local_2c == *(int *)puVar5) {
    return uVar1;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(puVar6);
  if (iVar3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    puVar5 = (undefined *)(*(code *)PTR_strchr_006a9a28)(iVar3,0x3a);
    if (puVar5 != (undefined *)0x0) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    uVar1 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_str_006a7c1c)(iVar2,iVar3,puVar5);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
  }
  return uVar1;
}

