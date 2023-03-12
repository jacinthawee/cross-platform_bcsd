
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_get_ex_data_X509_STORE_CTX_idx(void)

{
  CRYPTO_lock(5,0xc,"ssl_cert.c",0x8e);
  if (ssl_x509_store_ctx_idx_16851 < 0) {
    CRYPTO_lock(6,0xc,"ssl_cert.c",0x91);
    CRYPTO_lock(9,0xc,"ssl_cert.c",0x92);
    if (ssl_x509_store_ctx_idx_16851 < 0) {
      ssl_x509_store_ctx_idx_16851 =
           (*(code *)PTR_X509_STORE_CTX_get_ex_new_index_006a8370)
                     (0,"SSL for verify callback",0,0,0);
    }
    CRYPTO_lock(10,0xc,"ssl_cert.c",0x9d);
    return ssl_x509_store_ctx_idx_16851;
  }
  CRYPTO_lock(6,0xc,"ssl_cert.c",0x9f);
  return ssl_x509_store_ctx_idx_16851;
}

