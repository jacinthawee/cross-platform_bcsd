
int conn_read(BIO *param_1,void *param_2,size_t param_3)

{
  ssize_t i;
  int *piVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*param_1->ptr == 6) {
    i = 0;
  }
  else {
    i = conn_state();
    if (i < 1) {
      return i;
    }
  }
  if (param_2 != (void *)0x0) {
    piVar1 = __errno_location();
    *piVar1 = 0;
    i = read(param_1->num,param_2,param_3);
    BIO_clear_flags(param_1,0xf);
    if ((i < 1) && (iVar2 = BIO_sock_should_retry(i), iVar2 != 0)) {
      BIO_set_flags(param_1,9);
    }
  }
  return i;
}

