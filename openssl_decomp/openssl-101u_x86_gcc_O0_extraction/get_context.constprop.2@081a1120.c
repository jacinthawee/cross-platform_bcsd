
bool get_context_constprop_2(void)

{
  int in_GS_OFFSET;
  undefined *local_418;
  undefined4 local_414;
  undefined local_410 [1024];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_418 = local_410;
  local_414 = 0x400;
  hwcrhk_context = (*p_hwcrhk_Init)(hwcrhk_globals,0x54,&local_418,password_context);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return hwcrhk_context != 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

