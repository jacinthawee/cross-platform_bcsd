
undefined4
certify(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
       undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
       undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
       undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
       undefined4 param_17,undefined4 param_18,undefined4 param_19,int param_20,undefined4 param_21,
       undefined4 param_22,undefined4 param_23,undefined4 param_24,int param_25)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
  iVar5 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6c,3,param_2);
  if (iVar5 < 1) {
    (*(code *)PTR_perror_006a9a80)(param_2);
  }
  else {
    iVar5 = (*(code *)PTR_PEM_read_bio_X509_REQ_006a6ee4)(iVar4,0,0,0);
    if (iVar5 != 0) {
      if (param_20 != 0) {
        (*(code *)PTR_X509_REQ_print_006a717c)(*(undefined4 *)PTR_bio_err_006a6e3c,iVar5);
      }
      puVar1 = PTR_bio_err_006a6e3c;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,
                 "Check that the request matches the signature\n");
      if ((param_25 == 0) ||
         (iVar6 = (*(code *)PTR_X509_REQ_check_private_key_006a7180)(iVar5,param_3), iVar6 != 0)) {
        iVar6 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(iVar5);
        puVar2 = PTR_bio_err_006a6e3c;
        if (iVar6 == 0) {
          uVar3 = 0xffffffff;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"error unpacking public key\n");
        }
        else {
          iVar7 = (*(code *)PTR_X509_REQ_verify_006a6ef0)(iVar5,iVar6);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
          uVar3 = *(undefined4 *)puVar2;
          if (iVar7 < 0) {
            pcVar8 = "Signature verification problems....\n";
          }
          else {
            if (iVar7 != 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(uVar3,"Signature ok\n");
              uVar3 = do_body(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                              param_10,param_11,param_12,param_13,param_14,param_15,param_16,
                              param_17,param_20,iVar5,param_18,param_19,param_21,param_22,param_23,
                              param_24,param_25);
              goto LAB_004208b8;
            }
            pcVar8 = "Signature did not match the certificate request\n";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(uVar3,pcVar8);
          uVar3 = 0;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
        }
      }
      else {
        uVar3 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar1,"Certificate request and CA private key do not match\n");
      }
LAB_004208b8:
      (*(code *)PTR_X509_REQ_free_006a6e8c)(iVar5);
      goto LAB_004208c8;
    }
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Error reading certificate request in %s\n",
               param_2);
  }
  uVar3 = 0xffffffff;
LAB_004208c8:
  if (iVar4 != 0) {
    (*(code *)PTR_BIO_free_006a6e70)(iVar4);
  }
  return uVar3;
}

