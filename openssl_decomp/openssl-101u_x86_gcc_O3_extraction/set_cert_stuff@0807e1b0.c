
undefined4 set_cert_stuff(SSL_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  char *format;
  
  if (param_2 == (char *)0x0) {
    return 1;
  }
  iVar1 = SSL_CTX_use_certificate_file(param_1,param_2,1);
  if (iVar1 < 1) {
    format = "unable to get certificate from \'%s\'\n";
    param_3 = param_2;
  }
  else {
    if (param_3 == (char *)0x0) {
      param_3 = param_2;
    }
    iVar1 = SSL_CTX_use_PrivateKey_file(param_1,param_3,1);
    if (0 < iVar1) {
      iVar1 = SSL_CTX_check_private_key(param_1);
      if (iVar1 != 0) {
        return 1;
      }
      BIO_printf(bio_err,"Private key does not match the certificate public key\n");
      return 0;
    }
    format = "unable to get private key from \'%s\'\n";
  }
  BIO_printf(bio_err,format,param_3);
  ERR_print_errors(bio_err);
  return 0;
}

