
char * ERR_lib_error_string(ulong e)

{
  undefined *puVar1;
  _LHASH *lh;
  int iVar2;
  char *pcVar3;
  undefined *data;
  uint uVar4;
  undefined auStack_434 [400];
  char *pcStack_2a4;
  undefined *puStack_29c;
  undefined *puStack_298;
  undefined *puStack_294;
  uint *puStack_290;
  code *pcStack_28c;
  undefined *puStack_278;
  undefined auStack_26c [400];
  char *pcStack_dc;
  uint uStack_d4;
  undefined *puStack_d0;
  undefined *puStack_cc;
  uint *puStack_c8;
  code *pcStack_c4;
  undefined *puStack_b0;
  uint auStack_a4 [2];
  int iStack_9c;
  uint uStack_94;
  undefined *puStack_90;
  undefined *puStack_8c;
  undefined4 uStack_88;
  code *pcStack_84;
  undefined *puStack_70;
  uint auStack_64 [2];
  uint uStack_5c;
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
  uStack_54 = e & 0xff000000;
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
  pcStack_44 = ERR_func_error_string;
  uVar4 = local_1c;
  (**(code **)(local_30 + -0x5330))();
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  puStack_4c = &_gp_1;
  uStack_48 = 0x660000;
  puStack_70 = &_gp;
  uStack_5c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(puStack_70 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  uStack_94 = ((uVar4 << 8) >> 0x14) << 0xc | uVar4 & 0xff000000;
  auStack_64[0] = uStack_94;
  iVar2 = (**(code **)((int)err_fns + 8))(auStack_64);
  if (iVar2 == 0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *(char **)(iVar2 + 4);
  }
  if (uStack_5c == *(uint *)puStack_90) {
    return pcVar3;
  }
  pcStack_84 = ERR_reason_error_string;
  auStack_a4[0] = uStack_5c;
  (**(code **)(puStack_70 + -0x5330))();
  puStack_d0 = PTR___stack_chk_guard_006a9ae8;
  puStack_8c = &_gp_1;
  uStack_88 = 0x660000;
  puStack_b0 = &_gp;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(puStack_b0 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  uStack_d4 = auStack_a4[0] & 0xfff;
  puStack_290 = auStack_a4;
  auStack_a4[0] = auStack_a4[0] & 0xff000fff;
  iVar2 = (**(code **)((int)err_fns + 8))(puStack_290);
  if ((iVar2 == 0) &&
     (auStack_a4[0] = uStack_d4, iVar2 = (**(code **)((int)err_fns + 8))(puStack_290), iVar2 == 0))
  {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *(char **)(iVar2 + 4);
  }
  if (iStack_9c == *(int *)puStack_d0) {
    return pcVar3;
  }
  pcStack_c4 = ERR_remove_thread_state;
  iVar2 = iStack_9c;
  (**(code **)(puStack_b0 + -0x5330))();
  puStack_29c = PTR___stack_chk_guard_006a9ae8;
  puStack_cc = &_gp_1;
  puStack_278 = &_gp;
  pcStack_dc = *(char **)PTR___stack_chk_guard_006a9ae8;
  puStack_c8 = puStack_290;
  if (iVar2 == 0) {
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_26c);
  }
  else {
    (*(code *)PTR_CRYPTO_THREADID_cpy_006a8488)(auStack_26c,iVar2);
  }
  if ((code **)err_fns == (code **)0x0) {
    puStack_290 = (uint *)(CAST_S_table3 + 0x110);
    (**(code **)(puStack_278 + -0x6c9c))(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(puStack_278 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  puStack_298 = auStack_26c;
  (**(code **)((int)err_fns + 0x24))(puStack_298);
  pcVar3 = *(char **)puStack_29c;
  if (pcStack_dc == pcVar3) {
    return pcVar3;
  }
  pcStack_28c = ERR_remove_state;
  (**(code **)(puStack_278 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_294 = &_gp_1;
  data = auStack_434;
  pcStack_2a4 = *(char **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(data);
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  (**(code **)((int)err_fns + 0x24))();
  if (pcStack_2a4 != *(char **)puVar1) {
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

