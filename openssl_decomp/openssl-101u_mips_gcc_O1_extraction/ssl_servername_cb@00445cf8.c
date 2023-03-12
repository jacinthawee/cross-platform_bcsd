
int ssl_servername_cb(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_SSL_get_servername_006a7884)(param_1,0);
  if (iVar1 == 0) {
    if (*param_3 == 0) {
      return 3;
    }
  }
  else {
    if (param_3[1] != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_3[1],"Hostname in TLS extension: \"%s\"\n",iVar1);
    }
    if (*param_3 == 0) {
      return 3;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(iVar1);
    if (iVar1 != 0) {
      return param_3[2];
    }
    if (ctx2 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_3[1],"Switching server context.\n");
      (*(code *)PTR_SSL_set_SSL_CTX_006a7888)(param_1,ctx2);
      return 0;
    }
  }
  return 0;
}

