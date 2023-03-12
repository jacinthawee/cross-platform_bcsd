
_STACK * TS_CONF_load_certs(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  BIO *bp;
  _STACK *st;
  _STACK *st_00;
  int iVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  
  bp = BIO_new_file(param_1,"r");
  if ((bp == (BIO *)0x0) || (st = sk_new_null(), st == (_STACK *)0x0)) {
    st_00 = (_STACK *)0x0;
    __fprintf_chk(stderr,1,"unable to load certificates: %s\n",param_1,param_4);
    st = (_STACK *)0x0;
  }
  else {
    st_00 = (_STACK *)
            PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
    iVar3 = 0;
    while( true ) {
      iVar1 = sk_num(st_00);
      iVar4 = iVar3 + 1;
      if (iVar1 <= iVar3) break;
      ppvVar2 = (void **)sk_value(st_00,iVar3);
      iVar3 = iVar4;
      if (*ppvVar2 != (void *)0x0) {
        sk_push(st,*ppvVar2);
        *ppvVar2 = (void *)0x0;
      }
    }
  }
  sk_pop_free(st_00,X509_INFO_free + 1);
  BIO_free(bp);
  return st;
}

