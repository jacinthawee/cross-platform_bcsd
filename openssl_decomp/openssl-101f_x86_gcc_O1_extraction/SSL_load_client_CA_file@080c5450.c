
stack_st_X509_NAME * SSL_load_client_CA_file(char *file)

{
  _STACK *st;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509 *pXVar2;
  X509_NAME *pXVar3;
  int iVar4;
  _STACK *st_00;
  _STACK *p_Var5;
  int in_GS_OFFSET;
  X509 *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (X509 *)0x0;
  st = sk_new(xname_cmp);
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((st == (_STACK *)0x0) || (bp == (BIO *)0x0)) {
    iVar4 = 0x2ad;
LAB_080c5538:
    ERR_put_error(0x14,0xb9,0x41,"ssl_cert.c",iVar4);
LAB_080c54b3:
    p_Var5 = (_STACK *)0x0;
    if (st == (_STACK *)0x0) goto LAB_080c54b9;
  }
  else {
    lVar1 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar1 == 0) goto LAB_080c54b3;
    p_Var5 = (_STACK *)0x0;
    while( true ) {
      pXVar2 = PEM_read_bio_X509(bp,&local_24,(undefined1 *)0x0,(void *)0x0);
      if (pXVar2 == (X509 *)0x0) break;
      st_00 = p_Var5;
      if (p_Var5 == (_STACK *)0x0) {
        st_00 = sk_new_null();
        if (st_00 == (_STACK *)0x0) {
          iVar4 = 0x2bd;
          goto LAB_080c5538;
        }
      }
      pXVar3 = X509_get_subject_name(local_24);
      if (pXVar3 == (X509_NAME *)0x0) {
LAB_080c5508:
        p_Var5 = (_STACK *)0x0;
        sk_pop_free(st_00,X509_NAME_free);
        break;
      }
      pXVar3 = X509_NAME_dup(pXVar3);
      if (pXVar3 == (X509_NAME *)0x0) goto LAB_080c5508;
      iVar4 = sk_find(st,pXVar3);
      p_Var5 = st_00;
      if (iVar4 < 0) {
        sk_push(st,pXVar3);
        sk_push(st_00,pXVar3);
      }
      else {
        X509_NAME_free(pXVar3);
      }
    }
  }
  sk_free(st);
LAB_080c54b9:
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  if (local_24 != (X509 *)0x0) {
    X509_free(local_24);
  }
  if (p_Var5 != (_STACK *)0x0) {
    ERR_clear_error();
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (stack_st_X509_NAME *)p_Var5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

