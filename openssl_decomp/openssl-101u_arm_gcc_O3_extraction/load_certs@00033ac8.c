
_STACK * load_certs(BIO *param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                   undefined4 param_6)

{
  bool bVar1;
  BIO *bp;
  _STACK *st;
  _STACK *st_00;
  int iVar2;
  void **ppvVar3;
  int iVar4;
  int iVar5;
  undefined4 local_28;
  char *pcStack_24;
  
  local_28 = param_4;
  pcStack_24 = param_2;
  if (param_3 != 3) {
    BIO_printf(param_1,"bad input format specified for %s\n",param_6);
    return (_STACK *)0x0;
  }
  if (param_2 == (char *)0x0) {
    bp = BIO_new_fp(stdin,0);
    if (bp == (BIO *)0x0) {
      param_2 = "stdin";
      goto LAB_00033bbe;
    }
  }
  else {
    bp = BIO_new_file(param_2,"r");
    if (bp == (BIO *)0x0) {
LAB_00033bbe:
      BIO_printf(param_1,"Error opening %s %s\n",param_6,param_2);
      ERR_print_errors(param_1);
      return (_STACK *)0x0;
    }
  }
  st = (_STACK *)
       PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,password_callback + 1,&local_28);
  BIO_free(bp);
  st_00 = sk_new_null();
  if (st_00 == (_STACK *)0x0) {
LAB_00033b5e:
    bVar1 = false;
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar2 = sk_num(st);
      iVar5 = iVar4 + 1;
      if (iVar2 <= iVar4) break;
      ppvVar3 = (void **)sk_value(st,iVar4);
      iVar4 = iVar5;
      if (*ppvVar3 != (void *)0x0) {
        iVar2 = sk_push(st_00,*ppvVar3);
        if (iVar2 == 0) goto LAB_00033b5e;
        *ppvVar3 = (void *)0x0;
      }
    }
    iVar4 = sk_num(st_00);
    bVar1 = 0 < iVar4;
  }
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,X509_INFO_free + 1);
  }
  if (!bVar1) {
    sk_pop_free(st_00,X509_free + 1);
    BIO_printf(param_1,"unable to load %s\n","certificates");
    ERR_print_errors(param_1);
    return (_STACK *)0x0;
  }
  return st_00;
}

