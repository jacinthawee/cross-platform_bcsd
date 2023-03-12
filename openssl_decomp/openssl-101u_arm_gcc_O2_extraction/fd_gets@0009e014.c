
void fd_gets(BIO *param_1,char *param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  ssize_t sVar3;
  int iVar4;
  char *__buf;
  char *pcVar5;
  
  __buf = param_2;
  if ((param_2 < param_2 + param_3 + -1) && (param_2 != (char *)0x0)) {
    piVar2 = __errno_location();
    while( true ) {
      *piVar2 = 0;
      pcVar5 = __buf + 1;
      sVar3 = read(param_1->num,__buf,1);
      BIO_clear_flags(param_1,0xf);
      if (sVar3 < 1) break;
      if (((*__buf == '\n') || (__buf = pcVar5, pcVar5 == param_2 + param_3 + -1)) ||
         (pcVar5 == (char *)0x0)) goto LAB_0009e06c;
    }
    if (sVar3 + 1U < 2) {
      iVar4 = *piVar2;
      if (iVar4 == 0x47) {
LAB_0009e096:
        BIO_set_flags(param_1,9);
LAB_0009e09e:
        *__buf = '\0';
        cVar1 = *param_2;
        goto joined_r0x0009e0a8;
      }
      if (iVar4 < 0x48) {
        if (iVar4 == 4) goto LAB_0009e096;
        if (iVar4 == 0xb) {
          BIO_set_flags(param_1,9);
          goto LAB_0009e09e;
        }
      }
      else if ((iVar4 == 0x6b) || ((0x6a < iVar4 && (iVar4 - 0x72U < 2)))) goto LAB_0009e096;
    }
  }
LAB_0009e06c:
  *__buf = '\0';
  cVar1 = *param_2;
joined_r0x0009e0a8:
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)PTR_strlen_00189130)(param_2);
  return;
}

