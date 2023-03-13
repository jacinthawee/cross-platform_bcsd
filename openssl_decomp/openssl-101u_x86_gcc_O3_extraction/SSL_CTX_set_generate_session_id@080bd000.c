
int __regparm1 SSL_CTX_set_generate_session_id(SSL_CTX *param_1,GEN_SESSION_CB param_2)

{
  undefined4 in_stack_00000008;
  
  CRYPTO_lock((int)param_1,9,&DAT_0000000c,(int)"ssl_lib.c");
  *(undefined4 *)(param_2 + 0xec) = in_stack_00000008;
  CRYPTO_lock((int)param_2,10,&DAT_0000000c,(int)"ssl_lib.c");
  return 1;
}

