
bool app_passwd(BIO *param_1,byte *param_2,byte *param_3,char **param_4,char **param_5)

{
  int iVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  if ((param_3 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    bVar6 = param_2 == (byte *)0x0;
    if (!bVar6) {
      bVar7 = false;
      goto LAB_0807aaf8;
    }
    if (param_4 != (char **)0x0) {
      *param_4 = (char *)0x0;
    }
    if (param_3 == (byte *)0x0) goto LAB_0807ac50;
LAB_0807abe2:
    iVar1 = 5;
    bVar6 = false;
    bVar7 = true;
    pbVar3 = param_3;
    pbVar4 = (byte *)"pass:";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pbVar3 < *pbVar4;
      bVar7 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (uint)bVar8 * -2 + 1;
      pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (bVar7) {
LAB_0807abf8:
      pcVar2 = BUF_strdup((char *)(param_3 + 5));
      goto LAB_0807aba5;
    }
  }
  else {
    iVar1 = strcmp((char *)param_2,(char *)param_3);
    bVar6 = iVar1 == 0;
    bVar7 = bVar6;
LAB_0807aaf8:
    bVar5 = false;
    iVar1 = 5;
    pbVar3 = param_2;
    pbVar4 = (byte *)"pass:";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (uint)bVar8 * -2 + 1;
      pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      pcVar2 = BUF_strdup((char *)(param_2 + 5));
    }
    else {
      iVar1 = 4;
      pbVar3 = param_2;
      pbVar4 = &DAT_081f7ac9;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pbVar3 < *pbVar4;
        bVar6 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + (uint)bVar8 * -2 + 1;
        pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
      } while (bVar6);
      if ((!bVar5 && !bVar6) == bVar5) {
        pcVar2 = getenv((char *)(param_2 + 4));
        if (pcVar2 == (char *)0x0) {
          BIO_printf(param_1,"Can\'t read environment variable %s\n",param_2 + 4);
          *param_4 = (char *)0x0;
          return false;
        }
        pcVar2 = BUF_strdup(pcVar2);
      }
      else {
        pcVar2 = (char *)app_get_pass_part_0();
      }
    }
    *param_4 = pcVar2;
    if (pcVar2 == (char *)0x0) {
      return false;
    }
    if (param_3 == (byte *)0x0) {
LAB_0807ac50:
      if (param_5 == (char **)0x0) {
        return true;
      }
      *param_5 = (char *)0x0;
      return true;
    }
    bVar6 = false;
    bVar7 = !bVar7;
    if (bVar7) goto LAB_0807abe2;
    iVar1 = 5;
    pbVar3 = param_3;
    pbVar4 = (byte *)"pass:";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pbVar3 < *pbVar4;
      bVar7 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (uint)bVar8 * -2 + 1;
      pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (bVar7) goto LAB_0807abf8;
  }
  iVar1 = 4;
  pbVar3 = param_3;
  pbVar4 = &DAT_081f7ac9;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pbVar3 < *pbVar4;
    bVar7 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (uint)bVar8 * -2 + 1;
    pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
  } while (bVar7);
  if ((!bVar6 && !bVar7) == bVar6) {
    pcVar2 = getenv((char *)(param_3 + 4));
    if (pcVar2 == (char *)0x0) {
      BIO_printf(param_1,"Can\'t read environment variable %s\n",param_3 + 4);
      *param_5 = (char *)0x0;
      return false;
    }
    pcVar2 = BUF_strdup(pcVar2);
  }
  else {
    pcVar2 = (char *)app_get_pass_part_0();
  }
LAB_0807aba5:
  *param_5 = pcVar2;
  return pcVar2 != (char *)0x0;
}

