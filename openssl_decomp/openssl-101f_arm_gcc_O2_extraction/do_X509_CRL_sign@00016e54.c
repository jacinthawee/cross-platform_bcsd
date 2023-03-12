
bool do_X509_CRL_sign(BIO *param_1,X509_CRL *param_2,EVP_PKEY *param_3,EVP_MD *param_4,
                     _STACK *param_5)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  EVP_PKEY_CTX *local_3c;
  EVP_MD_CTX EStack_38;
  
  EVP_MD_CTX_init(&EStack_38);
  local_3c = (EVP_PKEY_CTX *)0x0;
  EVP_MD_CTX_init(&EStack_38);
  iVar1 = EVP_DigestSignInit(&EStack_38,&local_3c,param_4,(ENGINE *)0x0,param_3);
  iVar3 = 0;
  if (iVar1 != 0) {
    do {
      iVar1 = sk_num(param_5);
      if (iVar1 <= iVar3) {
        iVar3 = X509_CRL_sign_ctx(param_2,&EStack_38);
        bVar4 = 0 < iVar3;
        goto LAB_00016ee0;
      }
      pvVar2 = sk_value(param_5,iVar3);
      iVar1 = pkey_ctrl_string(local_3c,pvVar2);
      iVar3 = iVar3 + 1;
    } while (0 < iVar1);
    BIO_printf(param_1,"parameter error \"%s\"\n",pvVar2);
    ERR_print_errors(bio_err);
  }
  bVar4 = false;
LAB_00016ee0:
  EVP_MD_CTX_cleanup(&EStack_38);
  return bVar4;
}

