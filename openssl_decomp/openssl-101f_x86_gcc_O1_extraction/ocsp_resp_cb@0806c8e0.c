
undefined4 ocsp_resp_cb(SSL *param_1,BIO *param_2)

{
  long len;
  OCSP_RESPONSE *o;
  undefined4 uVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  len = SSL_ctrl(param_1,0x46,0,&local_14);
  BIO_puts(param_2,"OCSP response: ");
  if (local_14 == (uchar *)0x0) {
    BIO_puts(param_2,"no response sent\n");
    uVar1 = 1;
  }
  else {
    o = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,&local_14,len);
    if (o == (OCSP_RESPONSE *)0x0) {
      BIO_puts(param_2,"response parse error\n");
      BIO_dump_indent(param_2,(char *)local_14,len,4);
      uVar1 = 0;
    }
    else {
      BIO_puts(param_2,"\n======================================\n");
      OCSP_RESPONSE_print(param_2,o,0);
      BIO_puts(param_2,"======================================\n");
      OCSP_RESPONSE_free(o);
      uVar1 = 1;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

