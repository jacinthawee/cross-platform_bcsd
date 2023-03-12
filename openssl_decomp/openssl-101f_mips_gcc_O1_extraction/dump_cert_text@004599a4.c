
undefined4 dump_cert_text(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_X509_get_subject_name_006a8000)(param_2);
  uVar1 = (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar1,0,0);
  (*(code *)PTR_BIO_puts_006a8058)(param_1,"subject=");
  (*(code *)PTR_BIO_puts_006a8058)(param_1,uVar1);
  (*(code *)PTR_CRYPTO_free_006a7f88)(uVar1);
  uVar1 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(param_2);
  uVar1 = (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar1,0,0);
  (*(code *)PTR_BIO_puts_006a8058)(param_1,"\nissuer=");
  (*(code *)PTR_BIO_puts_006a8058)(param_1,uVar1);
  (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
  (*(code *)PTR_CRYPTO_free_006a7f88)(uVar1);
  return 0;
}

