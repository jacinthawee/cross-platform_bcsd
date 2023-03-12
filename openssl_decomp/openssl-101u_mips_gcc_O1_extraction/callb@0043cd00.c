
undefined4 callb(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(param_2);
  puVar1 = PTR_bio_err_006a6e3c;
  if (iVar2 == 0x12) {
    return 1;
  }
  if (param_1 == 0) {
    uVar3 = (*(code *)PTR_X509_STORE_CTX_get_current_cert_006a744c)(param_2);
    uVar5 = *(undefined4 *)puVar1;
    uVar3 = (*(code *)PTR_X509_get_subject_name_006a6f00)(uVar3);
    print_name(uVar5,0,uVar3,0);
    uVar4 = *(undefined4 *)puVar1;
    uVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_depth_006a7458)(param_2);
    uVar5 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(iVar2);
    (*(code *)PTR_BIO_printf_006a6e38)
              (uVar4,"error with certificate - error %d at depth %d\n%s\n",iVar2,uVar3,uVar5);
    return 1;
  }
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,
             "error with certificate to be certified - should be self signed\n");
  return 0;
}

