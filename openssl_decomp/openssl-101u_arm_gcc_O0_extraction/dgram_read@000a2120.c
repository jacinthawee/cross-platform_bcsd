
void dgram_read(BIO *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  socklen_t local_58;
  timeval local_54;
  int local_4c;
  int local_48;
  socklen_t local_44;
  sockaddr local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  pvVar5 = param_1->ptr;
  local_44 = 0x1c;
  local_24 = __stack_chk_guard;
  if (param_2 == (void *)0x0) goto LAB_000a2244;
  piVar1 = __errno_location();
  local_40.sa_data._10_4_ = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_40._0_4_ = 0;
  local_40.sa_data._2_4_ = 0;
  local_40.sa_data._6_4_ = 0;
  local_58 = 0;
  *piVar1 = 0;
  pvVar4 = param_1->ptr;
  if ((0 < *(int *)((int)pvVar4 + 0x28)) || (0 < *(int *)((int)pvVar4 + 0x2c))) {
    local_58 = 8;
    iVar2 = getsockopt(param_1->num,1,0x14,(void *)((int)pvVar4 + 0x30),&local_58);
    if (iVar2 < 0) {
      perror("getsockopt");
    }
    gettimeofday(&local_54,(__timezone_ptr_t)0x0);
    iVar2 = *(int *)((int)pvVar4 + 0x28);
    if (*(int *)((int)pvVar4 + 0x2c) < local_54.tv_usec) {
      local_54.tv_usec = 1000000 - local_54.tv_usec;
      iVar2 = iVar2 + -1;
    }
    else {
      local_54.tv_usec = -local_54.tv_usec;
    }
    local_48 = *(int *)((int)pvVar4 + 0x2c) + local_54.tv_usec;
    local_4c = iVar2;
    if (local_54.tv_sec <= iVar2) {
      local_4c = iVar2 - local_54.tv_sec;
    }
    iVar3 = *(int *)((int)pvVar4 + 0x30);
    if (iVar2 < local_54.tv_sec) {
      local_4c = 0;
      local_48 = 1;
    }
    if (((((iVar3 == 0) && (*(int *)((int)pvVar4 + 0x34) == 0)) || (local_4c < iVar3)) ||
        ((iVar3 == local_4c && (local_48 <= *(int *)((int)pvVar4 + 0x34))))) &&
       (iVar2 = setsockopt(param_1->num,1,0x14,&local_4c,8), iVar2 < 0)) {
      perror("setsockopt");
    }
  }
  param_2 = (void *)recvfrom(param_1->num,param_2,param_3,0,&local_40,&local_44);
  if (*(int *)((int)pvVar5 + 0x1c) == 0) {
    if ((int)param_2 < 0) {
      BIO_clear_flags(param_1,0xf);
joined_r0x000a227c:
      if ((int)param_2 + 1U < 2) {
        iVar2 = *piVar1;
        if (iVar2 == 0x47) {
LAB_000a2290:
          BIO_set_flags(param_1,9);
          *(int *)((int)pvVar5 + 0x20) = *piVar1;
        }
        else if (iVar2 < 0x48) {
          if ((iVar2 == 4) || (iVar2 == 0xb)) goto LAB_000a2290;
        }
        else if (iVar2 - 0x72U < 2) goto LAB_000a2290;
      }
    }
    else {
      BIO_ctrl(param_1,0x2c,0,&local_40);
      BIO_clear_flags(param_1,0xf);
    }
  }
  else {
    BIO_clear_flags(param_1,0xf);
    if ((int)param_2 < 0) goto joined_r0x000a227c;
  }
  pvVar5 = param_1->ptr;
  if (((0 < *(int *)((int)pvVar5 + 0x28)) || (0 < *(int *)((int)pvVar5 + 0x2c))) &&
     (iVar2 = setsockopt(param_1->num,1,0x14,(void *)((int)pvVar5 + 0x30),8), iVar2 < 0)) {
    perror("setsockopt");
  }
LAB_000a2244:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2);
  }
  return;
}

