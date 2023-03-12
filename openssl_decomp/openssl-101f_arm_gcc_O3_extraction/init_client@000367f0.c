
void init_client(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  sockaddr local_34;
  int local_24;
  
  local_24 = __TMC_END__;
  local_38 = 0;
  iVar1 = __isoc99_sscanf(param_2,"%u.%u.%u.%u",&local_48,&local_44,&local_40,&local_3c);
  if (iVar1 != 4) {
    iVar1 = GetHostByName(param_2);
    if (iVar1 == 0) {
      BIO_printf(bio_err,"gethostbyname failure\n");
    }
    else {
      if (*(short *)(iVar1 + 8) == 2) {
        puVar4 = (undefined4 *)**(undefined4 **)(iVar1 + 0x10);
        local_44 = (uint)*(byte *)((int)puVar4 + 1);
        bVar3 = *(byte *)puVar4;
        local_3c = (uint)*(byte *)((int)puVar4 + 3);
        local_38 = *puVar4;
        local_40 = (uint)*(byte *)((int)puVar4 + 2);
        goto LAB_00036864;
      }
      BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
    }
    uVar5 = 0;
    goto LAB_000368bc;
  }
  if ((((0xff < local_48) || (0xff < local_44)) || (0xff < local_40)) || (0xff < local_3c)) {
    BIO_printf(bio_err,"invalid IP address\n");
    uVar5 = 0;
    goto LAB_000368bc;
  }
  bVar3 = (byte)local_48;
  local_44 = local_44 & 0xff;
  local_40 = local_40 & 0xff;
  local_3c = local_3c & 0xff;
  local_38 = CONCAT13((char)local_3c,CONCAT12((char)local_40,CONCAT11((char)local_44,bVar3)));
LAB_00036864:
  uVar5 = 0;
  local_34.sa_data._0_2_ = (ushort)(byte)((uint)param_3 >> 8) | (ushort)(param_3 << 8);
  local_34.sa_data._2_4_ = local_3c << 0x18 | local_40 << 0x10 | local_44 << 8 | (uint)bVar3;
  local_34.sa_data._6_4_ = 0;
  local_34.sa_data._10_4_ = 0;
  local_34.sa_family = 2;
  if (param_4 == 1) {
    iVar1 = socket(2,1,6);
    if (iVar1 == -1) goto LAB_0003697c;
    local_48 = 0;
    local_48 = setsockopt(iVar1,1,9,&local_48,4);
    if ((int)local_48 < 0) {
      perror("keepalive");
      goto LAB_000368bc;
    }
  }
  else {
    iVar1 = socket(2,2,0x11);
    if (iVar1 == -1) {
LAB_0003697c:
      perror("socket");
      uVar5 = 0;
      goto LAB_000368bc;
    }
  }
  iVar2 = connect(iVar1,&local_34,0x10);
  if (iVar2 == -1) {
    close(iVar1);
    perror("connect");
    uVar5 = 0;
  }
  else {
    *param_1 = iVar1;
    uVar5 = 1;
  }
LAB_000368bc:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}

