
int tmp_rsa_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  if (rsa_tmp_19388 != 0) {
    return rsa_tmp_19388;
  }
  iVar2 = (*(code *)PTR_BN_new_006a71b4)();
  puVar1 = PTR_bio_err_006a6e3c;
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Allocation error in generating RSA key\n");
    return rsa_tmp_19388;
  }
  if (rsa_tmp_19388 != 0) {
    return rsa_tmp_19388;
  }
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Generating temp (%d bit) RSA key...",param_3);
    (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  iVar3 = (*(code *)PTR_BN_set_word_006a7730)(iVar2,0x10001);
  if (iVar3 == 0) {
LAB_00445a48:
    if (rsa_tmp_19388 != 0) {
      (*(code *)PTR_RSA_free_006a7600)();
    }
  }
  else {
    rsa_tmp_19388 = (*(code *)PTR_RSA_new_006a787c)();
    if (rsa_tmp_19388 != 0) {
      iVar3 = (*(code *)PTR_RSA_generate_key_ex_006a7734)(rsa_tmp_19388,param_3,iVar2,0);
      if (iVar3 != 0) goto LAB_00445a68;
      goto LAB_00445a48;
    }
  }
  rsa_tmp_19388 = 0;
LAB_00445a68:
  puVar1 = PTR_bio_err_006a6e3c;
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"\n");
    (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  (*(code *)PTR_BN_free_006a701c)(iVar2);
  return rsa_tmp_19388;
}

