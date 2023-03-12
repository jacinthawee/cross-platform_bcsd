
undefined4 set_cert_key_stuff(SSL_CTX *param_1,X509 *param_2,EVP_PKEY *param_3)

{
  int iVar1;
  char *format;
  
  if (param_2 == (X509 *)0x0) {
    return 1;
  }
  iVar1 = SSL_CTX_use_certificate(param_1,param_2);
  if (iVar1 < 1) {
    format = "error setting certificate\n";
  }
  else {
    iVar1 = SSL_CTX_use_PrivateKey(param_1,param_3);
    if (0 < iVar1) {
      iVar1 = SSL_CTX_check_private_key(param_1);
      if (iVar1 != 0) {
        return 1;
      }
      BIO_printf(bio_err,"Private key does not match the certificate public key\n");
      return 0;
    }
    format = "error setting private key\n";
  }
  BIO_printf(bio_err,format);
  ERR_print_errors(bio_err);
  return 0;
}

