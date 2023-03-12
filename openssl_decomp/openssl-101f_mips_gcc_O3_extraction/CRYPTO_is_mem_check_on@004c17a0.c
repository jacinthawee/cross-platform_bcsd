
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_is_mem_check_on(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  CRYPTO_THREADID CStack_24;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = 0;
  if ((mh_mode & 1) != 0) {
    CRYPTO_THREADID_current(&CStack_24);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_24);
      uVar2 = (uint)(iVar3 != 0);
    }
    else {
      uVar2 = 1;
    }
    CRYPTO_lock(6,0x14,"mem_dbg.c",299);
  }
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  options = local_1c;
  return (int)&_ITM_registerTMCloneTable;
}

