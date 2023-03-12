
undefined4 set_cert_key_stuff(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == 0) {
    return 1;
  }
  iVar2 = (*(code *)PTR_SSL_CTX_use_certificate_006a8d2c)();
  if (iVar2 < 1) {
    pcVar3 = "error setting certificate\n";
  }
  else {
    iVar2 = (*(code *)PTR_SSL_CTX_use_PrivateKey_006a8d30)(param_1,param_3);
    if (0 < iVar2) {
      iVar2 = (*(code *)PTR_SSL_CTX_check_private_key_006a8d28)(param_1);
      if (iVar2 != 0) {
        return 1;
      }
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,
                 "Private key does not match the certificate public key\n");
      return 0;
    }
    pcVar3 = "error setting private key\n";
  }
  puVar1 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar3);
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
  return 0;
}

