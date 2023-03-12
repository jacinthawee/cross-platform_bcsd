
int SSL_CTX_set_generate_session_id(SSL_CTX *param_1,GEN_SESSION_CB param_2)

{
  CRYPTO_lock(9,0xc,"ssl_lib.c",0x1ab);
  param_1->generate_session_id = param_2;
  CRYPTO_lock(10,0xc,"ssl_lib.c",0x1ad);
  return 1;
}

