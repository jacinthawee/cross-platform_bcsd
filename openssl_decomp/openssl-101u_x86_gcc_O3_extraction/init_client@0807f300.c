
undefined4 init_client(int *param_1,undefined4 param_2,ushort param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  int local_28;
  sockaddr local_24;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = 0;
  iVar1 = __isoc99_sscanf(param_2,&DAT_081f9314,&local_24,local_24.sa_data + 2,local_24.sa_data + 6,
                          local_24.sa_data + 10);
  if (iVar1 == 4) {
    if ((((0xff < local_24._0_4_) || (0xff < local_24.sa_data._2_4_)) ||
        (0xff < local_24.sa_data._6_4_)) || (0xff < local_24.sa_data._10_4_)) {
      BIO_printf(bio_err,"invalid IP address\n");
      uVar3 = 0;
      goto LAB_0807f401;
    }
    local_14 = CONCAT13((char)local_24.sa_data._10_4_,
                        CONCAT12((char)local_24.sa_data._6_4_,
                                 CONCAT11((char)local_24.sa_data._2_4_,(char)local_24._0_4_)));
  }
  else {
    iVar1 = GetHostByName();
    if (iVar1 == 0) {
      BIO_printf(bio_err,"gethostbyname failure\n");
      uVar3 = 0;
      goto LAB_0807f401;
    }
    if (*(short *)(iVar1 + 8) != 2) {
      BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
      uVar3 = 0;
      goto LAB_0807f401;
    }
    local_14 = ***(uint ***)(iVar1 + 0x10);
  }
  local_24.sa_data._6_4_ = 0;
  local_24.sa_data._10_4_ = 0;
  local_24._0_4_ = CONCAT22(param_3 >> 8 | param_3 << 8,2);
  local_24.sa_data._2_4_ = local_14;
  if (param_4 == 1) {
    iVar1 = socket(2,1,6);
    if (iVar1 == -1) goto LAB_0807f540;
    local_28 = 0;
    local_28 = setsockopt(iVar1,1,9,&local_28,4);
    if (local_28 < 0) {
      close(iVar1);
      perror("keepalive");
      uVar3 = 0;
      goto LAB_0807f401;
    }
  }
  else {
    iVar1 = socket(2,2,0x11);
    if (iVar1 == -1) {
LAB_0807f540:
      perror("socket");
      uVar3 = 0;
      goto LAB_0807f401;
    }
  }
  iVar2 = connect(iVar1,&local_24,0x10);
  if (iVar2 == -1) {
    close(iVar1);
    perror("connect");
    uVar3 = 0;
  }
  else {
    *param_1 = iVar1;
    uVar3 = 1;
  }
LAB_0807f401:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

