
undefined4
certify(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
       undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
       undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
       undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
       undefined4 param_17,undefined4 param_18,undefined4 param_19,int param_20,undefined4 param_21,
       undefined4 param_22,undefined4 param_23,undefined4 param_24,int param_25)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6c,3,param_2);
  if (iVar4 < 1) {
    (*(code *)PTR_perror_006aab88)(param_2);
  }
  else {
    iVar4 = (*(code *)PTR_PEM_read_bio_X509_REQ_006a7fe4)(iVar3,0,0,0);
    if (iVar4 != 0) {
      if (param_20 != 0) {
        (*(code *)PTR_X509_REQ_print_006a827c)(*(undefined4 *)PTR_bio_err_006a7f3c,iVar4);
      }
      puVar1 = PTR_bio_err_006a7f3c;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,
                 "Check that the request matches the signature\n");
      if ((param_25 == 0) ||
         (iVar5 = (*(code *)PTR_X509_REQ_check_private_key_006a8280)(iVar4,param_3), iVar5 != 0)) {
        iVar5 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(iVar4);
        if (iVar5 == 0) {
          uVar7 = 0xffffffff;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar1,"error unpacking public key\n");
        }
        else {
          iVar6 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(iVar4,iVar5);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar5);
          uVar2 = *(undefined4 *)PTR_bio_err_006a7f3c;
          if (iVar6 < 0) {
            uVar7 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)(uVar2,"Signature verification problems....\n");
          }
          else if (iVar6 == 0) {
            uVar7 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (uVar2,"Signature did not match the certificate request\n");
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)(uVar2,"Signature ok\n");
            uVar7 = do_body(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10
                            ,param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_20
                            ,iVar4,param_18,param_19,param_21,param_22,param_23,param_24,param_25);
          }
        }
      }
      else {
        uVar7 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar1,"Certificate request and CA private key do not match\n");
      }
      (*(code *)PTR_X509_REQ_free_006a7f8c)(iVar4);
      goto LAB_004208ec;
    }
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"Error reading certificate request in %s\n",
               param_2);
  }
  uVar7 = 0xffffffff;
LAB_004208ec:
  if (iVar3 != 0) {
    (*(code *)PTR_BIO_free_006a7f70)(iVar3);
  }
  return uVar7;
}

