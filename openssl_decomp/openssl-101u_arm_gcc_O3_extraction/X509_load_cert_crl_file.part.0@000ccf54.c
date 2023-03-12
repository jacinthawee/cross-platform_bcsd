
_STACK * X509_load_cert_crl_file_part_0(int param_1,char *param_2)

{
  BIO *bp;
  _STACK *st;
  int iVar1;
  X509 **ppXVar2;
  int iVar3;
  int iVar4;
  _STACK *p_Var5;
  
  bp = BIO_new_file(param_2,"r");
  if (bp != (BIO *)0x0) {
    st = (_STACK *)
         PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
    BIO_free(bp);
    if (st == (_STACK *)0x0) {
      ERR_put_error(0xb,0x84,9,"by_file.c",0x103);
    }
    else {
      p_Var5 = (_STACK *)0x0;
      iVar3 = 0;
      while( true ) {
        iVar1 = sk_num(st);
        iVar4 = iVar3 + 1;
        if (iVar1 <= iVar3) break;
        ppXVar2 = (X509 **)sk_value(st,iVar3);
        if (*ppXVar2 != (X509 *)0x0) {
          p_Var5 = (_STACK *)((int)&p_Var5->num + 1);
          X509_STORE_add_cert(*(X509_STORE **)(param_1 + 0x10),*ppXVar2);
        }
        iVar3 = iVar4;
        if (ppXVar2[1] != (X509 *)0x0) {
          p_Var5 = (_STACK *)((int)&p_Var5->num + 1);
          X509_STORE_add_crl(*(X509_STORE **)(param_1 + 0x10),(X509_CRL *)ppXVar2[1]);
        }
      }
      sk_pop_free(st,X509_INFO_free + 1);
      st = p_Var5;
    }
    return st;
  }
  ERR_put_error(0xb,0x84,2,"by_file.c",0xfd);
  return (_STACK *)0x0;
}

