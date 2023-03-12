
bool dtls1_is_timer_expired(int param_1)

{
  int iVar1;
  timeval local_18;
  
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c0) == 0) &&
     (*(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) == 0)) {
    return false;
  }
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  iVar1 = *(int *)(param_1 + 0x5c);
  if ((local_18.tv_sec <= *(int *)(iVar1 + 0x2c0)) &&
     ((*(int *)(iVar1 + 0x2c0) != local_18.tv_sec || (local_18.tv_usec < *(int *)(iVar1 + 0x2c4)))))
  {
    local_18.tv_usec = *(int *)(iVar1 + 0x2c4) - local_18.tv_usec;
    local_18.tv_sec = *(int *)(iVar1 + 0x2c0) - local_18.tv_sec;
    if (local_18.tv_usec < 0) {
      local_18.tv_sec = local_18.tv_sec + -1;
      local_18.tv_usec = local_18.tv_usec + 1000000;
    }
    if (local_18.tv_sec != 0) {
      if (0 < local_18.tv_sec) {
        return false;
      }
      goto LAB_0005bb2c;
    }
    if (14999 < local_18.tv_usec) goto LAB_0005bb2c;
  }
  local_18.tv_usec = 0;
LAB_0005bb2c:
  return local_18.tv_usec < 1;
}

