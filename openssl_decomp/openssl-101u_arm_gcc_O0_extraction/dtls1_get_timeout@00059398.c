
int * dtls1_get_timeout(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  timeval local_18;
  
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) == 0) &&
     (*(int *)(*(int *)(param_1 + 0x5c) + 0x2c8) == 0)) {
    return (int *)0x0;
  }
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  iVar2 = *(int *)(param_1 + 0x5c);
  if ((local_18.tv_sec <= *(int *)(iVar2 + 0x2c4)) &&
     ((*(int *)(iVar2 + 0x2c4) != local_18.tv_sec || (local_18.tv_usec < *(int *)(iVar2 + 0x2c8)))))
  {
    iVar1 = *(int *)(iVar2 + 0x2c4);
    param_2[1] = *(int *)(iVar2 + 0x2c8);
    *param_2 = iVar1;
    local_18.tv_usec = param_2[1] - local_18.tv_usec;
    param_2[1] = local_18.tv_usec;
    local_18.tv_sec = *param_2 - local_18.tv_sec;
    *param_2 = local_18.tv_sec;
    if (local_18.tv_usec < 0) {
      local_18.tv_sec = local_18.tv_sec + -1;
      local_18.tv_usec = local_18.tv_usec + 1000000;
      *param_2 = local_18.tv_sec;
      param_2[1] = local_18.tv_usec;
    }
    if (local_18.tv_sec != 0) {
      return param_2;
    }
    if (14999 < local_18.tv_usec) {
      return param_2;
    }
  }
  *(undefined *)param_2 = 0;
  *(undefined *)((int)param_2 + 1) = 0;
  *(undefined *)((int)param_2 + 2) = 0;
  *(undefined *)((int)param_2 + 3) = 0;
  *(undefined *)(param_2 + 1) = 0;
  *(undefined *)((int)param_2 + 5) = 0;
  *(undefined *)((int)param_2 + 6) = 0;
  *(undefined *)((int)param_2 + 7) = 0;
  return param_2;
}

