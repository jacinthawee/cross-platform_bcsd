
void SSL_CTX_free(SSL_CTX *param_1)

{
  int iVar1;
  
  if (param_1 != (SSL_CTX *)0x0) {
    iVar1 = CRYPTO_add_lock(&param_1->references,-1,0xc,"ssl_lib.c",0x795);
    if (iVar1 < 1) {
      SSL_CTX_free_part_6();
      return;
    }
  }
  return;
}

