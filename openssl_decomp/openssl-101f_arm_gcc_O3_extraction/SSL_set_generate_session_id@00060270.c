
int SSL_set_generate_session_id(SSL *param_1,GEN_SESSION_CB param_2)

{
  CRYPTO_lock(9,0x10,"ssl_lib.c",0x1b3);
  param_1->generate_session_id = param_2;
  CRYPTO_lock(10,0x10,"ssl_lib.c",0x1b5);
  return 1;
}

