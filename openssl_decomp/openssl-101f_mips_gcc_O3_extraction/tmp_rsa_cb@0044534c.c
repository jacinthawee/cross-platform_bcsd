
int tmp_rsa_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  if (rsa_tmp_19390 != 0) {
    return rsa_tmp_19390;
  }
  iVar2 = (*(code *)PTR_BN_new_006a82b4)();
  puVar1 = PTR_bio_err_006a7f3c;
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"Allocation error in generating RSA key\n");
    return rsa_tmp_19390;
  }
  if (rsa_tmp_19390 != 0) {
    return rsa_tmp_19390;
  }
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"Generating temp (%d bit) RSA key...",param_3);
    (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  iVar3 = (*(code *)PTR_BN_set_word_006a8820)(iVar2,0x10001);
  if (iVar3 == 0) {
LAB_004453f0:
    if (rsa_tmp_19390 != 0) {
      (*(code *)PTR_RSA_free_006a86f0)();
    }
  }
  else {
    rsa_tmp_19390 = (*(code *)PTR_RSA_new_006a8964)();
    if (rsa_tmp_19390 != 0) {
      iVar3 = (*(code *)PTR_RSA_generate_key_ex_006a8824)(rsa_tmp_19390,param_3,iVar2,0);
      if (iVar3 != 0) goto LAB_00445410;
      goto LAB_004453f0;
    }
  }
  rsa_tmp_19390 = 0;
LAB_00445410:
  puVar1 = PTR_bio_err_006a7f3c;
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"\n");
    (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  (*(code *)PTR_BN_free_006a811c)(iVar2);
  return rsa_tmp_19390;
}

