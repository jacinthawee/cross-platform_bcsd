
int cms_cb(int param_1,X509_STORE_CTX *param_2)

{
  verify_err = X509_STORE_CTX_get_error(param_2);
  if ((verify_err == 0x2b) || ((verify_err == 0 && (param_1 == 2)))) {
    policies_print(0,param_2);
  }
  return param_1;
}

