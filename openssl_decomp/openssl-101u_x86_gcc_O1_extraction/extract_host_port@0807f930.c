
long extract_host_port(char *param_1,char **param_2,undefined *param_3,ushort *param_4)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  long lVar4;
  servent *psVar5;
  int in_GS_OFFSET;
  undefined local_40;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar2 = strchr(param_1,0x3a);
  if (pcVar2 == (char *)0x0) {
    lVar4 = 0;
    BIO_printf(bio_err,"no port defined\n");
    goto LAB_0807fa14;
  }
  *pcVar2 = '\0';
  if (param_3 != (undefined *)0x0) {
    iVar3 = __isoc99_sscanf(param_1,&DAT_081f9314,&local_30,&local_2c,&local_28,&local_24);
    if (iVar3 == 4) {
      if ((((0xff < local_30) || (0xff < local_2c)) || (0xff < local_28)) || (0xff < local_24)) {
        lVar4 = 0;
        BIO_printf(bio_err,"invalid IP address\n");
        goto LAB_0807fa14;
      }
      *param_3 = (char)local_30;
      local_40 = (undefined)local_28;
      param_3[1] = (char)local_2c;
      param_3[3] = (char)local_24;
      param_3[2] = local_40;
    }
    else {
      iVar3 = GetHostByName();
      if (iVar3 == 0) {
        lVar4 = 0;
        BIO_printf(bio_err,"gethostbyname failure\n");
        goto LAB_0807fa14;
      }
      if (*(short *)(iVar3 + 8) != 2) {
        lVar4 = 0;
        BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
        goto LAB_0807fa14;
      }
      *param_3 = *(undefined *)**(undefined4 **)(iVar3 + 0x10);
      param_3[1] = *(undefined *)(**(int **)(iVar3 + 0x10) + 1);
      param_3[2] = *(undefined *)(**(int **)(iVar3 + 0x10) + 2);
      param_3[3] = *(undefined *)(**(int **)(iVar3 + 0x10) + 3);
    }
  }
  if (param_2 != (char **)0x0) {
    *param_2 = param_1;
  }
  pcVar2 = pcVar2 + 1;
  lVar4 = strtol(pcVar2,(char **)0x0,10);
  if (lVar4 == 0) {
    psVar5 = getservbyname(pcVar2,"tcp");
    if (psVar5 == (servent *)0x0) {
      BIO_printf(bio_err,"getservbyname failure for %s\n",pcVar2);
      goto LAB_0807fa14;
    }
    uVar1 = (ushort)psVar5->s_port;
    *param_4 = uVar1 >> 8 | uVar1 << 8;
  }
  else {
    *param_4 = (ushort)lVar4;
  }
  lVar4 = 1;
LAB_0807fa14:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

