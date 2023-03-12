
void X509_CRL_set_default_method(undefined *param_1)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_int_crl_meth_000b8798;
  }
  *(undefined **)(PTR_int_crl_meth_000b8798 + -4) = param_1;
  return;
}

