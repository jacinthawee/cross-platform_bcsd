
ssize_t dgram_read(BIO *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  ssize_t sVar5;
  int in_GS_OFFSET;
  socklen_t local_54;
  timeval local_50;
  int local_48;
  int local_44;
  socklen_t local_40;
  sockaddr local_3c;
  int local_20;
  
  sVar5 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_40 = 0x1c;
  pvVar1 = param_1->ptr;
  if (param_2 == (void *)0x0) goto LAB_0811e700;
  piVar2 = __errno_location();
  *piVar2 = 0;
  uVar3 = 0;
  do {
    *(undefined4 *)(local_3c.sa_data + (uVar3 - 2)) = 0;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x1c);
  local_54 = 0;
  if ((0 < *(int *)((int)pvVar1 + 0x28)) || (0 < *(int *)((int)pvVar1 + 0x2c))) {
    local_54 = 8;
    iVar4 = getsockopt(param_1->num,1,0x14,(void *)((int)pvVar1 + 0x30),&local_54);
    if (iVar4 < 0) {
      perror("getsockopt");
    }
    gettimeofday(&local_50,(__timezone_ptr_t)0x0);
    iVar4 = *(int *)((int)pvVar1 + 0x28);
    local_44 = *(int *)((int)pvVar1 + 0x2c);
    if (local_44 < local_50.tv_usec) {
      local_44 = (local_44 - local_50.tv_usec) + 1000000;
      iVar4 = iVar4 + -1;
    }
    else {
      local_44 = local_44 - local_50.tv_usec;
    }
    local_48 = iVar4 - local_50.tv_sec;
    if (iVar4 < local_50.tv_sec) {
      local_44 = 1;
      local_48 = 0;
    }
    iVar4 = *(int *)((int)pvVar1 + 0x30);
    if (iVar4 == 0) {
      if (*(int *)((int)pvVar1 + 0x34) != 0) {
LAB_0811e65e:
        if ((iVar4 != local_48) || (*(int *)((int)pvVar1 + 0x34) < local_44)) goto LAB_0811e666;
      }
    }
    else if (iVar4 <= local_48) goto LAB_0811e65e;
    iVar4 = setsockopt(param_1->num,1,0x14,&local_48,8);
    if (iVar4 < 0) {
      perror("setsockopt");
    }
  }
LAB_0811e666:
  sVar5 = recvfrom(param_1->num,param_2,param_3,0,&local_3c,&local_40);
  if (*(int *)((int)pvVar1 + 0x1c) == 0) {
    if (sVar5 < 0) {
      BIO_clear_flags(param_1,0xf);
LAB_0811e780:
      if (sVar5 + 1U < 2) {
        iVar4 = *piVar2;
        if (iVar4 == 0x47) {
LAB_0811e7ab:
          BIO_set_flags(param_1,9);
          *(int *)((int)pvVar1 + 0x20) = *piVar2;
        }
        else if (iVar4 < 0x48) {
          if ((iVar4 == 4) || (iVar4 == 0xb)) goto LAB_0811e7ab;
        }
        else if (iVar4 - 0x72U < 2) goto LAB_0811e7ab;
      }
    }
    else {
      BIO_ctrl(param_1,0x2c,0,&local_3c);
      BIO_clear_flags(param_1,0xf);
    }
  }
  else {
    BIO_clear_flags(param_1,0xf);
    if (sVar5 < 0) goto LAB_0811e780;
  }
  pvVar1 = param_1->ptr;
  if (((0 < *(int *)((int)pvVar1 + 0x28)) || (0 < *(int *)((int)pvVar1 + 0x2c))) &&
     (iVar4 = setsockopt(param_1->num,1,0x14,(void *)((int)pvVar1 + 0x30),8), iVar4 < 0)) {
    perror("setsockopt");
  }
LAB_0811e700:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar5;
}

