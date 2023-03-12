
uint CRYPTO_mem_ctrl_constprop_5(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  void *ptr;
  void *ptr_00;
  CRYPTO_THREADID CStack_2c;
  void *local_24;
  
  uVar3 = mh_mode;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(void **)PTR___stack_chk_guard_006a9ae8;
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
  if ((mh_mode & 1) != 0) {
    CRYPTO_THREADID_current(&CStack_2c);
    if ((num_disable == 0) ||
       (iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_2c), iVar2 != 0))
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
  if (local_24 != *(void **)puVar1) {
    ptr = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar3 = *(int *)((int)ptr + 0x18) - 1;
    *(uint *)((int)ptr + 0x18) = uVar3;
    if ((int)uVar3 < 1) {
      ptr_00 = *(void **)((int)ptr + 0x14);
      if (ptr_00 != (void *)0x0) {
        uVar3 = *(int *)((int)ptr_00 + 0x18) - 1;
        *(uint *)((int)ptr_00 + 0x18) = uVar3;
        if ((int)uVar3 < 1) {
          if (*(int *)((int)ptr_00 + 0x14) != 0) {
            uVar3 = app_info_free();
          }
          CRYPTO_free(ptr_00);
        }
      }
      CRYPTO_free(ptr);
      return uVar3;
    }
    return uVar3;
  }
  return uVar3;
}

