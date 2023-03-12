
ssize_t conn_puts(BIO *param_1,char *param_2)

{
  size_t __n;
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  
  __n = strlen(param_2);
                    /* WARNING: Load size is inaccurate */
  if ((*param_1->ptr != 6) && (sVar1 = conn_state(param_1), sVar1 < 1)) {
    return sVar1;
  }
  piVar2 = __errno_location();
  *piVar2 = 0;
  sVar1 = write(param_1->num,param_2,__n);
  BIO_clear_flags(param_1,0xf);
  if (0 < sVar1) {
    return sVar1;
  }
  iVar3 = BIO_sock_should_retry(sVar1);
  if (iVar3 == 0) {
    return sVar1;
  }
  BIO_set_flags(param_1,10);
  return sVar1;
}

