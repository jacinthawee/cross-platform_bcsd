
char * ERR_reason_error_string(ulong e)

{
  undefined *puVar1;
  _LHASH *lh;
  int iVar2;
  char *pcVar3;
  undefined *data;
  undefined auStack_3b4 [400];
  char *pcStack_224;
  undefined *puStack_21c;
  undefined *puStack_218;
  undefined1 *puStack_214;
  uint *puStack_210;
  code *pcStack_20c;
  undefined *puStack_1f8;
  undefined auStack_1ec [400];
  char *pcStack_5c;
  uint uStack_54;
  undefined *puStack_50;
  undefined1 *puStack_4c;
  uint *puStack_48;
  code *pcStack_44;
  undefined *local_30;
  uint local_24 [2];
  int local_1c;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(local_30 + -0x6c74))(10,1,"err.c",0x12a);
  }
  uStack_54 = e & 0xfff;
  puStack_210 = local_24;
  local_24[0] = e & 0xff000fff;
  iVar2 = (**(code **)((int)err_fns + 8))(puStack_210);
  if ((iVar2 == 0) &&
     (local_24[0] = uStack_54, iVar2 = (**(code **)((int)err_fns + 8))(puStack_210), iVar2 == 0)) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *(char **)(iVar2 + 4);
  }
  if (local_1c == *(int *)puStack_50) {
    return pcVar3;
  }
  pcStack_44 = ERR_remove_thread_state;
  iVar2 = local_1c;
  (**(code **)(local_30 + -0x5328))();
  puStack_21c = PTR___stack_chk_guard_006aabf0;
  puStack_4c = &_ITM_registerTMCloneTable;
  puStack_1f8 = &_gp;
  pcStack_5c = *(char **)PTR___stack_chk_guard_006aabf0;
  puStack_48 = puStack_210;
  if (iVar2 == 0) {
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(auStack_1ec);
  }
  else {
    (*(code *)PTR_CRYPTO_THREADID_cpy_006a95a8)(auStack_1ec,iVar2);
  }
  if ((code **)err_fns == (code **)0x0) {
    puStack_210 = (uint *)0x670000;
    (**(code **)(puStack_1f8 + -0x6c74))(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(puStack_1f8 + -0x6c74))(10,1,"err.c",0x12a);
  }
  puStack_218 = auStack_1ec;
  (**(code **)((int)err_fns + 0x24))(puStack_218);
  pcVar3 = *(char **)puStack_21c;
  if (pcStack_5c != pcVar3) {
    pcStack_20c = ERR_remove_state;
    (**(code **)(puStack_1f8 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    puStack_214 = &_ITM_registerTMCloneTable;
    data = auStack_3b4;
    pcStack_224 = *(char **)PTR___stack_chk_guard_006aabf0;
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(data);
    if ((code **)err_fns == (code **)0x0) {
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
      if ((code **)err_fns == (code **)0x0) {
        err_fns = err_defaults;
      }
      (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
    }
    (**(code **)((int)err_fns + 0x24))();
    if (pcStack_224 != *(char **)puVar1) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      if ((code **)err_fns == (code **)0x0) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
        if ((code **)err_fns == (code **)0x0) {
          err_fns = err_defaults;
        }
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
      }
      lh = (_LHASH *)(**(code **)err_fns)(0);
      if (lh == (_LHASH *)0x0) {
        pcVar3 = (char *)0x0;
      }
      else {
        (*(code *)PTR_CRYPTO_lock_006a926c)(5,1,"err.c",0x185);
        pcVar3 = (char *)lh_retrieve(lh,data);
        (*(code *)PTR_CRYPTO_lock_006a926c)(6,1,"err.c",0x187);
      }
      return pcVar3;
    }
    return *(char **)puVar1;
  }
  return pcVar3;
}

