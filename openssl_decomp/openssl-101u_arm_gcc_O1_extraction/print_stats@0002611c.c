
void print_stats(BIO *param_1,SSL_CTX *param_2)

{
  long lVar1;
  
  lVar1 = SSL_CTX_ctrl(param_2,0x14,0,(void *)0x0);
  BIO_printf(param_1,"%4ld items in the session cache\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x15,0,(void *)0x0);
  BIO_printf(param_1,"%4ld client connects (SSL_connect())\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x17,0,(void *)0x0);
  BIO_printf(param_1,"%4ld client renegotiates (SSL_connect())\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x16,0,(void *)0x0);
  BIO_printf(param_1,"%4ld client connects that finished\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x18,0,(void *)0x0);
  BIO_printf(param_1,"%4ld server accepts (SSL_accept())\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x1a,0,(void *)0x0);
  BIO_printf(param_1,"%4ld server renegotiates (SSL_accept())\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x19,0,(void *)0x0);
  BIO_printf(param_1,"%4ld server accepts that finished\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x1b,0,(void *)0x0);
  BIO_printf(param_1,"%4ld session cache hits\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x1d,0,(void *)0x0);
  BIO_printf(param_1,"%4ld session cache misses\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x1e,0,(void *)0x0);
  BIO_printf(param_1,"%4ld session cache timeouts\n",lVar1);
  lVar1 = SSL_CTX_ctrl(param_2,0x1c,0,(void *)0x0);
  BIO_printf(param_1,"%4ld callback cache hits\n",lVar1);
  SSL_CTX_ctrl(param_2,0x1f,0,(void *)0x0);
  SSL_CTX_ctrl(param_2,0x2b,0,(void *)0x0);
  BIO_vprintf(param_1,"%4ld cache full overflows (%ld allowed)\n",&stack0xfffffff8);
  return;
}

