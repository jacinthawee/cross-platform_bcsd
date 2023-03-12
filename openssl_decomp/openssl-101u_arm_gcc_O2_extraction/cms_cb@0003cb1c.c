
int cms_cb(int param_1,X509_STORE_CTX *param_2,undefined4 param_3,undefined4 param_4)

{
  verify_err = X509_STORE_CTX_get_error(param_2);
  if ((verify_err == 0x2b) || (param_1 == 2 && verify_err == 0)) {
    policies_print(0,param_2,param_3,&verify_err,param_4);
  }
  return param_1;
}

