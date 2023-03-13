
void X509_CRL_set_default_method(undefined *param_1)

{
  if (param_1 != (undefined *)0x0) {
    default_crl_method = param_1;
    return;
  }
  default_crl_method = int_crl_meth;
  return;
}

