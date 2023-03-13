
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_get_ex_data_X509_STORE_CTX_idx(void)

{
  int in_EAX;
  int mode;
  
  CRYPTO_lock(in_EAX,5,&DAT_0000000c,(int)"ssl_cert.c");
  if (-1 < ssl_x509_store_ctx_idx_16831) {
    CRYPTO_lock(ssl_x509_store_ctx_idx_16831,6,&DAT_0000000c,(int)"ssl_cert.c");
    return ssl_x509_store_ctx_idx_16831;
  }
  mode = ssl_x509_store_ctx_idx_16831;
  CRYPTO_lock(ssl_x509_store_ctx_idx_16831,6,&DAT_0000000c,(int)"ssl_cert.c");
  CRYPTO_lock(mode,9,&DAT_0000000c,(int)"ssl_cert.c");
  if (ssl_x509_store_ctx_idx_16831 < 0) {
    ssl_x509_store_ctx_idx_16831 =
         X509_STORE_CTX_get_ex_new_index
                   (0,"SSL for verify callback",(undefined1 *)0x0,(undefined1 *)0x0,
                    (undefined1 *)0x0);
  }
  CRYPTO_lock(ssl_x509_store_ctx_idx_16831,10,&DAT_0000000c,(int)"ssl_cert.c");
  return ssl_x509_store_ctx_idx_16831;
}

