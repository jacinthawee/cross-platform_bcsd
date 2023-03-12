
size_t fd_gets(BIO *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  ssize_t sVar4;
  size_t sVar5;
  char *__buf;
  
  __buf = param_2;
  if (param_2 < param_2 + param_3 + -1) {
    if (param_2 != (char *)0x0) {
      piVar3 = __errno_location();
      do {
        *piVar3 = 0;
        sVar4 = read(param_1->num,__buf,1);
        BIO_clear_flags(param_1,0xf);
        if (sVar4 < 1) {
          if (1 < sVar4 + 1U) goto LAB_081190b2;
          iVar2 = *piVar3;
          if (iVar2 != 0x47) {
            if (iVar2 < 0x48) {
              if (iVar2 != 4) {
                if (iVar2 == 0xb) {
                  BIO_set_flags(param_1,9);
                }
                goto LAB_081190b2;
              }
            }
            else if ((iVar2 != 0x6b) && ((iVar2 < 0x6b || (1 < iVar2 - 0x72U)))) goto LAB_081190b2;
          }
          BIO_set_flags(param_1,9);
          goto LAB_081190b2;
        }
        if ((*__buf == '\n') || (__buf = __buf + 1, param_2 + param_3 + -1 == __buf))
        goto LAB_081190b2;
      } while (__buf != (char *)0x0);
    }
    DAT_00000000 = 0;
    cVar1 = *param_2;
  }
  else {
LAB_081190b2:
    *__buf = '\0';
    cVar1 = *param_2;
  }
  if (cVar1 == '\0') {
    return 0;
  }
  sVar5 = strlen(param_2);
  return sVar5;
}

