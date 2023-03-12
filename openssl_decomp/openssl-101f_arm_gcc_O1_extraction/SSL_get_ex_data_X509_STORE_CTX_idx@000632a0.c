
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_get_ex_data_X509_STORE_CTX_idx(void)

{
  CRYPTO_lock(5,0xc,"ssl_cert.c",0x8c);
  if (-1 < ssl_x509_store_ctx_idx_19452) {
    CRYPTO_lock(6,0xc,"ssl_cert.c",0x9e);
    return ssl_x509_store_ctx_idx_19452;
  }
  CRYPTO_lock(6,0xc,"ssl_cert.c",0x90);
  CRYPTO_lock(9,0xc,"ssl_cert.c",0x91);
  if (ssl_x509_store_ctx_idx_19452 < 0) {
    ssl_x509_store_ctx_idx_19452 =
         X509_STORE_CTX_get_ex_new_index
                   (0,"SSL for verify callback",(undefined1 *)0x0,(undefined1 *)0x0,
                    (undefined1 *)0x0);
  }
  CRYPTO_lock(10,0xc,"ssl_cert.c",0x9c);
  return ssl_x509_store_ctx_idx_19452;
}

