
int CRYPTO_mem_ctrl(int mode)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  CRYPTO_THREADID CStack_6c;
  int iStack_64;
  undefined1 *puStack_5c;
  char *pcStack_58;
  undefined *puStack_54;
  undefined1 *puStack_50;
  code *pcStack_4c;
  undefined *local_38;
  CRYPTO_THREADID CStack_2c;
  int local_24;
  
  uVar2 = mh_mode;
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
  if (mode == 1) {
    mh_mode = 3;
    num_disable = 0;
  }
  else if (mode < 2) {
    if (mode == 0) {
      mh_mode = 0;
      num_disable = 0;
    }
  }
  else if (mode == 2) {
    if ((((mh_mode & 1) != 0) && (iVar3 = num_disable + -1, num_disable != 0)) &&
       (num_disable = iVar3, iVar3 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
  }
  else if ((mode == 3) && ((mh_mode & 1) != 0)) {
    mode = (int)&_ITM_registerTMCloneTable;
    CRYPTO_THREADID_current(&CStack_2c);
    if ((num_disable == 0) ||
       (iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_2c), iVar3 != 0))
    {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0xfa);
      CRYPTO_lock(9,0x1b,"mem_dbg.c",0x100);
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x101);
      mh_mode = mh_mode & 0xfffffffd;
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&disabling_threadid,&CStack_2c);
    }
    num_disable = num_disable + 1;
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  if (local_24 != *(int *)puStack_54) {
    pcStack_4c = CRYPTO_is_mem_check_on;
    (**(code **)(local_38 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    pcStack_58 = "Number";
    puStack_50 = &_ITM_registerTMCloneTable;
    iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
    uVar2 = 0;
    puStack_5c = (undefined1 *)mode;
    if ((mh_mode & 1) != 0) {
      CRYPTO_THREADID_current(&CStack_6c);
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
      if ((mh_mode & 2) == 0) {
        iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_6c);
        uVar2 = (uint)(iVar3 != 0);
      }
      else {
        uVar2 = 1;
      }
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    if (iStack_64 != *(int *)puVar1) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      options = iStack_64;
      return (int)&_ITM_registerTMCloneTable;
    }
    return uVar2;
  }
  return uVar2;
}

