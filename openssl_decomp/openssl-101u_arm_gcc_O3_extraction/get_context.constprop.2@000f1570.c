
void get_context_constprop_2(void)

{
  int iVar1;
  undefined *local_424;
  undefined4 local_420;
  undefined auStack_41c [1024];
  int local_1c;
  
  local_424 = auStack_41c;
  local_420 = 0x400;
  local_1c = __stack_chk_guard;
  hwcrhk_context = (*p_hwcrhk_Init)(PTR_hwcrhk_globals_000f15c0,0x54,&local_424,password_context);
  iVar1 = hwcrhk_context;
  if (hwcrhk_context != 0) {
    iVar1 = 1;
  }
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}

