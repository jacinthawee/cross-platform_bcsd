
undefined4 set_cert_stuff(undefined4 param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = (*(code *)PTR_SSL_CTX_use_certificate_file_006a8d20)(param_1,param_2,1);
    puVar1 = PTR_bio_err_006a7f3c;
    if (iVar2 < 1) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to get certificate from \'%s\'\n",
                 param_2);
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
      return 0;
    }
    if (param_3 == 0) {
      param_3 = param_2;
    }
    iVar2 = (*(code *)PTR_SSL_CTX_use_PrivateKey_file_006a8d24)(param_1,param_3,1);
    puVar1 = PTR_bio_err_006a7f3c;
    if (iVar2 < 1) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to get private key from \'%s\'\n",
                 param_3);
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
      return 0;
    }
    iVar2 = (*(code *)PTR_SSL_CTX_check_private_key_006a8d28)(param_1);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,
                 "Private key does not match the certificate public key\n");
      return 0;
    }
  }
  return 1;
}

