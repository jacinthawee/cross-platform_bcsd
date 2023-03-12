
int __regparm3 X509_load_cert_crl_file_part_0(int param_1,char *param_2)

{
  BIO *bp;
  _STACK *st;
  X509 **ppXVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bp = BIO_new_file(param_2,"r");
  if (bp == (BIO *)0x0) {
    iVar4 = 0x112;
    iVar3 = 2;
  }
  else {
    st = (_STACK *)
         PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
    BIO_free(bp);
    if (st != (_STACK *)0x0) {
      iVar4 = 0;
      iVar3 = 0;
      while( true ) {
        iVar2 = sk_num(st);
        if (iVar2 <= iVar3) break;
        ppXVar1 = (X509 **)sk_value(st,iVar3);
        if (*ppXVar1 != (X509 *)0x0) {
          iVar4 = iVar4 + 1;
          X509_STORE_add_cert(*(X509_STORE **)(param_1 + 0x10),*ppXVar1);
        }
        if (ppXVar1[1] != (X509 *)0x0) {
          iVar4 = iVar4 + 1;
          X509_STORE_add_crl(*(X509_STORE **)(param_1 + 0x10),(X509_CRL *)ppXVar1[1]);
        }
        iVar3 = iVar3 + 1;
      }
      sk_pop_free(st,X509_INFO_free);
      return iVar4;
    }
    iVar4 = 0x118;
    iVar3 = 9;
  }
  ERR_put_error(0xb,0x84,iVar3,"by_file.c",iVar4);
  return 0;
}

