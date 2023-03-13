
SSL * __regparm3 doConnection(SSL *param_1)

{
  byte bVar1;
  BIO_METHOD *type;
  BIO *bp;
  int iVar2;
  int iVar3;
  char *pcVar4;
  SSL *s;
  __fd_mask *p_Var5;
  int in_GS_OFFSET;
  fd_set local_a0;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_connect();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,100,0,host);
    if (param_1 == (SSL *)0x0) {
      s = SSL_new(tm_ctx);
    }
    else {
      SSL_set_connect_state(param_1);
      s = param_1;
    }
    SSL_set_bio(s,bp,bp);
    while( true ) {
      iVar2 = SSL_connect(s);
      iVar3 = BIO_sock_should_retry(iVar2);
      if (iVar3 == 0) break;
      BIO_printf(bio_err,"DELAY\n");
      iVar2 = SSL_get_fd(s);
      iVar3 = 0x20;
      p_Var5 = local_a0.fds_bits;
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *p_Var5 = 0;
        p_Var5 = p_Var5 + 1;
      }
      iVar3 = __fdelt_chk(iVar2);
      bVar1 = (byte)(iVar2 >> 0x1f);
      local_a0.fds_bits[iVar3] =
           local_a0.fds_bits[iVar3] |
           1 << (((char)iVar2 + (bVar1 >> 3) & 0x1f) - (bVar1 >> 3) & 0x1f);
      select(iVar2 + 1,&local_a0,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
    }
    if (0 < iVar2) goto LAB_08078e83;
    BIO_printf(bio_err,"ERROR\n");
    if (verify_error == 0) {
      ERR_print_errors(bio_err);
    }
    else {
      pcVar4 = X509_verify_cert_error_string(verify_error);
      BIO_printf(bio_err,"verify error:%s\n",pcVar4);
    }
    if (param_1 == (SSL *)0x0) {
      SSL_free(s);
    }
  }
  s = (SSL *)0x0;
LAB_08078e83:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return s;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

