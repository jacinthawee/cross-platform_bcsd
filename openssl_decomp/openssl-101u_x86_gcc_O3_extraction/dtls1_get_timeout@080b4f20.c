
int * dtls1_get_timeout(int param_1,int *param_2)

{
  int iVar1;
  int in_GS_OFFSET;
  timeval local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) == 0) &&
     (*(int *)(*(int *)(param_1 + 0x5c) + 0x2c8) == 0)) {
    param_2 = (int *)0x0;
  }
  else {
    gettimeofday(&local_18,(__timezone_ptr_t)0x0);
    iVar1 = *(int *)(param_1 + 0x5c);
    if ((local_18.tv_sec <= *(int *)(iVar1 + 0x2c4)) &&
       ((*(int *)(iVar1 + 0x2c4) != local_18.tv_sec ||
        (*(int *)(iVar1 + 0x2c8) != local_18.tv_usec && local_18.tv_usec <= *(int *)(iVar1 + 0x2c8))
        ))) {
      local_18.tv_sec = *(int *)(iVar1 + 0x2c4) - local_18.tv_sec;
      local_18.tv_usec = *(int *)(iVar1 + 0x2c8) - local_18.tv_usec;
      *param_2 = local_18.tv_sec;
      param_2[1] = local_18.tv_usec;
      if (local_18.tv_usec < 0) {
        local_18.tv_sec = local_18.tv_sec + -1;
        local_18.tv_usec = local_18.tv_usec + 1000000;
        *param_2 = local_18.tv_sec;
        param_2[1] = local_18.tv_usec;
      }
      if ((local_18.tv_sec != 0) || (14999 < local_18.tv_usec)) goto LAB_080b4fa7;
    }
    *param_2 = 0;
    param_2[1] = 0;
  }
LAB_080b4fa7:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}

