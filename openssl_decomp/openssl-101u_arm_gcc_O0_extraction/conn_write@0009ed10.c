
ssize_t conn_write(BIO *param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  if ((*param_1->ptr != 6) && (sVar1 = conn_state(), sVar1 < 1)) {
    return sVar1;
  }
  piVar2 = __errno_location();
  *piVar2 = 0;
  sVar1 = write(param_1->num,param_2,param_3);
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

