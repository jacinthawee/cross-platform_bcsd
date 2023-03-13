
int CRYPTO_mem_ctrl(int mode)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  CRYPTO_THREADID CStack_6c;
  int iStack_64;
  undefined *puStack_5c;
  char *pcStack_58;
  undefined *puStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  undefined *local_38;
  CRYPTO_THREADID CStack_2c;
  int local_24;
  
  uVar2 = mh_mode;
  puStack_54 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
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
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
  }
  else if ((mode == 3) && ((mh_mode & 1) != 0)) {
    mode = (int)&_gp_1;
    CRYPTO_THREADID_current(&CStack_2c);
    if ((num_disable == 0) ||
       (iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_2c), iVar3 != 0))
    {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0xf4);
      CRYPTO_lock(9,0x1b,"mem_dbg.c",0xfb);
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xfc);
      mh_mode = mh_mode & 0xfffffffd;
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&disabling_threadid,&CStack_2c);
    }
    num_disable = num_disable + 1;
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  if (local_24 != *(int *)puStack_54) {
    pcStack_4c = CRYPTO_is_mem_check_on;
    (**(code **)(local_38 + -0x5330))();
    puVar1 = PTR___stack_chk_guard_006a9ae8;
    pcStack_58 = "TBEX";
    puStack_50 = &_gp_1;
    iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
    uVar2 = 0;
    puStack_5c = (undefined *)mode;
    if ((mh_mode & 1) != 0) {
      CRYPTO_THREADID_current(&CStack_6c);
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
      if ((mh_mode & 2) == 0) {
        iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_6c);
        uVar2 = (uint)(iVar3 != 0);
      }
      else {
        uVar2 = 1;
      }
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    if (iStack_64 != *(int *)puVar1) {
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      options = iStack_64;
      return (int)&_gp_1;
    }
    return uVar2;
  }
  return uVar2;
}

