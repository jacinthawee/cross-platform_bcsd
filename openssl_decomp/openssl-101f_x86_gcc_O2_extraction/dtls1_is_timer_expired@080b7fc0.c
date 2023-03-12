
bool dtls1_is_timer_expired(int param_1)

{
  int iVar1;
  bool bVar2;
  int in_GS_OFFSET;
  timeval local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c0) == 0) &&
     (*(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) == 0)) {
LAB_080b8072:
    bVar2 = false;
    goto LAB_080b8047;
  }
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  iVar1 = *(int *)(param_1 + 0x5c);
  if ((*(int *)(iVar1 + 0x2c0) < local_18.tv_sec) ||
     ((*(int *)(iVar1 + 0x2c0) == local_18.tv_sec &&
      (*(int *)(iVar1 + 0x2c4) == local_18.tv_usec || *(int *)(iVar1 + 0x2c4) < local_18.tv_usec))))
  {
LAB_080b8068:
    local_18.tv_usec = 0;
  }
  else {
    local_18.tv_sec = *(int *)(iVar1 + 0x2c0) - local_18.tv_sec;
    local_18.tv_usec = *(int *)(iVar1 + 0x2c4) - local_18.tv_usec;
    if (local_18.tv_usec < 0) {
      local_18.tv_sec = local_18.tv_sec + -1;
      local_18.tv_usec = local_18.tv_usec + 1000000;
    }
    if (local_18.tv_sec == 0) {
      if (local_18.tv_usec < 15000) goto LAB_080b8068;
    }
    else if (0 < local_18.tv_sec) goto LAB_080b8072;
  }
  bVar2 = local_18.tv_usec < 1;
LAB_080b8047:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar2;
}

