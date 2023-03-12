
char * ERR_func_error_string(ulong e)

{
  undefined *puVar1;
  _LHASH *lh;
  int iVar2;
  char *pcVar3;
  undefined *data;
  undefined auStack_3f4 [400];
  char *pcStack_264;
  undefined *puStack_25c;
  undefined *puStack_258;
  undefined *puStack_254;
  uint *puStack_250;
  code *pcStack_24c;
  undefined *puStack_238;
  undefined auStack_22c [400];
  char *pcStack_9c;
  uint uStack_94;
  undefined *puStack_90;
  undefined *puStack_8c;
  uint *puStack_88;
  code *pcStack_84;
  undefined *puStack_70;
  uint auStack_64 [2];
  int iStack_5c;
  uint uStack_54;
  undefined *puStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  code *pcStack_44;
  undefined *local_30;
  uint local_24 [2];
  uint local_1c;
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  local_30 = &_gp;
  local_1c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(local_30 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  uStack_54 = ((e << 8) >> 0x14) << 0xc | e & 0xff000000;
  local_24[0] = uStack_54;
  iVar2 = (**(code **)((int)err_fns + 8))(local_24);
  if (iVar2 == 0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *(char **)(iVar2 + 4);
  }
  if (local_1c == *(uint *)puStack_50) {
    return pcVar3;
  }
  pcStack_44 = ERR_reason_error_string;
  auStack_64[0] = local_1c;
  (**(code **)(local_30 + -0x5330))();
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  puStack_4c = &_gp_1;
  uStack_48 = 0x660000;
  puStack_70 = &_gp;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(puStack_70 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  uStack_94 = auStack_64[0] & 0xfff;
  puStack_250 = auStack_64;
  auStack_64[0] = auStack_64[0] & 0xff000fff;
  iVar2 = (**(code **)((int)err_fns + 8))(puStack_250);
  if ((iVar2 == 0) &&
     (auStack_64[0] = uStack_94, iVar2 = (**(code **)((int)err_fns + 8))(puStack_250), iVar2 == 0))
  {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *(char **)(iVar2 + 4);
  }
  if (iStack_5c == *(int *)puStack_90) {
    return pcVar3;
  }
  pcStack_84 = ERR_remove_thread_state;
  iVar2 = iStack_5c;
  (**(code **)(puStack_70 + -0x5330))();
  puStack_25c = PTR___stack_chk_guard_006a9ae8;
  puStack_8c = &_gp_1;
  puStack_238 = &_gp;
  pcStack_9c = *(char **)PTR___stack_chk_guard_006a9ae8;
  puStack_88 = puStack_250;
  if (iVar2 == 0) {
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_22c);
  }
  else {
    (*(code *)PTR_CRYPTO_THREADID_cpy_006a8488)(auStack_22c,iVar2);
  }
  if ((code **)err_fns == (code **)0x0) {
    puStack_250 = (uint *)(CAST_S_table3 + 0x110);
    (**(code **)(puStack_238 + -0x6c9c))(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(puStack_238 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  puStack_258 = auStack_22c;
  (**(code **)((int)err_fns + 0x24))(puStack_258);
  pcVar3 = *(char **)puStack_25c;
  if (pcStack_9c == pcVar3) {
    return pcVar3;
  }
  pcStack_24c = ERR_remove_state;
  (**(code **)(puStack_238 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_254 = &_gp_1;
  data = auStack_3f4;
  pcStack_264 = *(char **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(data);
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  (**(code **)((int)err_fns + 0x24))();
  if (pcStack_264 != *(char **)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if ((code **)err_fns == (code **)0x0) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
      if ((code **)err_fns == (code **)0x0) {
        err_fns = err_defaults;
      }
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
    }
    lh = (_LHASH *)(**(code **)err_fns)(0);
    if (lh == (_LHASH *)0x0) {
      pcVar3 = (char *)0x0;
    }
    else {
      (*(code *)PTR_CRYPTO_lock_006a8144)(5,1,"err.c",0x189);
      pcVar3 = (char *)lh_retrieve(lh,data);
      (*(code *)PTR_CRYPTO_lock_006a8144)(6,1,"err.c",0x18b);
    }
    return pcVar3;
  }
  return *(char **)puVar1;
}

