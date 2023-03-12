
undefined4 TS_RESP_CTX_set_signer_cert(X509 **param_1,X509 *param_2)

{
  int iVar1;
  
  iVar1 = X509_check_purpose(param_2,9,0);
  if (iVar1 == 1) {
    if (*param_1 != (X509 *)0x0) {
      X509_free(*param_1);
    }
    *param_1 = param_2;
    CRYPTO_add_lock(&param_2->references,1,3,"ts_rsp_sign.c",0xd5);
    return 1;
  }
  ERR_put_error(0x2f,0x83,0x75,"ts_rsp_sign.c",0xcf);
  return 0;
}

