
_STACK * TS_CONF_load_certs(char *param_1)

{
  BIO *bp;
  _STACK *st;
  _STACK *st_00;
  void **ppvVar1;
  int iVar2;
  int iVar3;
  
  bp = BIO_new_file(param_1,"r");
  if (bp != (BIO *)0x0) {
    st = sk_new_null();
    if (st != (_STACK *)0x0) {
      iVar3 = 0;
      st_00 = (_STACK *)
              PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
      while( true ) {
        iVar2 = sk_num(st_00);
        if (iVar2 <= iVar3) break;
        ppvVar1 = (void **)sk_value(st_00,iVar3);
        if (*ppvVar1 != (void *)0x0) {
          sk_push(st,*ppvVar1);
          *ppvVar1 = (void *)0x0;
        }
        iVar3 = iVar3 + 1;
      }
      goto LAB_08198b5c;
    }
  }
  st_00 = (_STACK *)0x0;
  st = (_STACK *)0x0;
  __fprintf_chk(stderr,1,"unable to load certificates: %s\n",param_1);
LAB_08198b5c:
  sk_pop_free(st_00,X509_INFO_free);
  BIO_free(bp);
  return st;
}

