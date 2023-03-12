
char * app_passwd(BIO *param_1,char *param_2,char *param_3,char **param_4,char **param_5)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_2 == (char *)0x0 || param_3 == (char *)0x0) {
    if (param_2 != (char *)0x0) {
      uVar5 = 0;
      goto LAB_0003342a;
    }
    if (param_4 != (char **)0x0) {
      *param_4 = (char *)0x0;
    }
    if (param_3 == (char *)0x0) goto LAB_000334ba;
  }
  else {
    iVar1 = strcmp(param_2,param_3);
    uVar5 = count_leading_zeroes(iVar1);
    uVar5 = uVar5 >> 5;
LAB_0003342a:
    iVar1 = strncmp(param_2,"pass:",5);
    if (iVar1 == 0) {
      pcVar2 = BUF_strdup(param_2 + 5);
    }
    else {
      iVar1 = strncmp(param_2,"env:",4);
      if (iVar1 == 0) {
        pcVar2 = getenv(param_2 + 4);
        if (pcVar2 == (char *)0x0) {
          BIO_printf(param_1,"Can\'t read environment variable %s\n",param_2 + 4);
          *param_4 = (char *)0x0;
          return (char *)0x0;
        }
        pcVar2 = BUF_strdup(pcVar2);
      }
      else {
        pcVar2 = (char *)app_get_pass_part_0(param_1,param_2,uVar5);
      }
    }
    *param_4 = pcVar2;
    if (pcVar2 == (char *)0x0) {
      return (char *)0x0;
    }
    if (param_3 == (char *)0x0) {
LAB_000334ba:
      if (param_5 == (char **)0x0) {
        return (char *)0x1;
      }
      *param_5 = (char *)0x0;
      return (char *)0x1;
    }
    uVar4 = 2;
    if (uVar5 != 0) goto LAB_0003346e;
  }
  uVar4 = 0;
LAB_0003346e:
  iVar1 = strncmp(param_3,"pass:",5);
  if (iVar1 == 0) {
    pcVar2 = BUF_strdup(param_3 + 5);
  }
  else {
    iVar1 = strncmp(param_3,"env:",4);
    if (iVar1 == 0) {
      pcVar2 = getenv(param_3 + 4);
      if (pcVar2 == (char *)0x0) {
        BIO_printf(param_1,"Can\'t read environment variable %s\n",param_3 + 4);
        *param_5 = (char *)0x0;
        return (char *)0x0;
      }
      pcVar2 = BUF_strdup(pcVar2);
    }
    else {
      pcVar2 = (char *)app_get_pass_part_0(param_1,param_3,uVar4);
    }
  }
  pcVar3 = pcVar2;
  if (pcVar2 != (char *)0x0) {
    pcVar3 = (char *)0x1;
  }
  *param_5 = pcVar2;
  return pcVar3;
}

