
undefined4 ssl_srp_server_param_cb(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = param_3[2];
  if (*param_3 == 0) {
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_SSL_get_srp_username_006a8960)();
      *param_3 = iVar1;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"SRP username = \"%s\"\n",iVar1);
      return 0xffffffff;
    }
  }
  else if (iVar1 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"User %s doesn\'t exist\n");
    return 2;
  }
  iVar1 = (*(code *)PTR_SSL_set_srp_server_param_006a895c)
                    (param_1,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0xc),
                     *(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),
                     *(undefined4 *)(iVar1 + 0x14));
  if (iVar1 < 0) {
    *param_2 = 0x50;
    return 2;
  }
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,
             "SRP parameters set: username = \"%s\" info=\"%s\" \n",*param_3,
             *(undefined4 *)(param_3[2] + 0x14));
  param_3[2] = 0;
  *param_3 = 0;
  return 0;
}

