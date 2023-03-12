
undefined4 extract_host_port(char *param_1,char **param_2,undefined *param_3,ushort *param_4)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  servent *psVar4;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  pcVar1 = strchr(param_1,0x3a);
  if (pcVar1 == (char *)0x0) {
    BIO_printf(bio_err,"no port defined\n");
    return 0;
  }
  *pcVar1 = '\0';
  if (param_3 != (undefined *)0x0) {
    iVar2 = __isoc99_sscanf(param_1,"%u.%u.%u.%u",&local_28,&local_24,&local_20,&local_1c);
    if (iVar2 == 4) {
      if (((local_28 < 0x100) && (local_24 < 0x100)) && (local_20 < 0x100)) {
        if (local_1c < 0x100) {
          *param_3 = (char)local_28;
        }
        if (local_1c < 0x100) {
          param_3[1] = (char)local_24;
        }
        if (local_1c < 0x100) {
          param_3[2] = (char)local_20;
        }
        if (local_1c < 0x100) {
          param_3[3] = (char)local_1c;
          goto LAB_00036c4c;
        }
      }
      BIO_printf(bio_err,"invalid IP address\n");
      return 0;
    }
    iVar2 = GetHostByName(param_1);
    if (iVar2 == 0) {
      BIO_printf(bio_err,"gethostbyname failure\n");
      return 0;
    }
    if (*(short *)(iVar2 + 8) != 2) {
      BIO_printf(bio_err,"gethostbyname addr is not AF_INET\n");
      return 0;
    }
    *param_3 = *(undefined *)**(undefined4 **)(iVar2 + 0x10);
    param_3[1] = *(undefined *)(**(int **)(iVar2 + 0x10) + 1);
    param_3[2] = *(undefined *)(**(int **)(iVar2 + 0x10) + 2);
    param_3[3] = *(undefined *)(**(int **)(iVar2 + 0x10) + 3);
  }
LAB_00036c4c:
  if (param_2 != (char **)0x0) {
    *param_2 = param_1;
  }
  pcVar1 = pcVar1 + 1;
  lVar3 = strtol(pcVar1,(char **)0x0,10);
  if (lVar3 == 0) {
    psVar4 = getservbyname(pcVar1,"tcp");
    if (psVar4 == (servent *)0x0) {
      BIO_printf(bio_err,"getservbyname failure for %s\n",pcVar1);
      return 0;
    }
    *param_4 = (ushort)(byte)((uint)psVar4->s_port >> 8) | (ushort)(psVar4->s_port << 8);
  }
  else {
    *param_4 = (ushort)lVar3;
  }
  return 1;
}

