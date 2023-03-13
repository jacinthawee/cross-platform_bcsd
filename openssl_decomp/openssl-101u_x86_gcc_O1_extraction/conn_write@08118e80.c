
int conn_write(BIO *param_1,void *param_2,size_t param_3)

{
  int i;
  int *piVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if ((*param_1->ptr == 6) || (i = conn_state(), 0 < i)) {
    piVar1 = __errno_location();
    *piVar1 = 0;
    i = write(param_1->num,param_2,param_3);
    BIO_clear_flags(param_1,0xf);
    if ((i < 1) && (iVar2 = BIO_sock_should_retry(i), iVar2 != 0)) {
      BIO_set_flags(param_1,10);
    }
  }
  return i;
}

