
bool do_X509_sign(BIO *param_1,X509 *param_2,EVP_PKEY *param_3,EVP_MD *param_4,_STACK *param_5)

{
  int iVar1;
  void *pvVar2;
  bool bVar3;
  int iVar4;
  int in_GS_OFFSET;
  EVP_PKEY_CTX *local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_38);
  local_3c = (EVP_PKEY_CTX *)0x0;
  EVP_MD_CTX_init(&local_38);
  iVar4 = 0;
  iVar1 = EVP_DigestSignInit(&local_38,&local_3c,param_4,(ENGINE *)0x0,param_3);
  if (iVar1 == 0) {
LAB_0804ddd1:
    bVar3 = false;
  }
  else {
    for (; iVar1 = sk_num(param_5), iVar4 < iVar1; iVar4 = iVar4 + 1) {
      pvVar2 = sk_value(param_5,iVar4);
      iVar1 = pkey_ctrl_string(local_3c,pvVar2);
      if (iVar1 < 1) {
        BIO_printf(param_1,"parameter error \"%s\"\n",pvVar2);
        ERR_print_errors(bio_err);
        goto LAB_0804ddd1;
      }
    }
    iVar1 = X509_sign_ctx(param_2,&local_38);
    bVar3 = 0 < iVar1;
  }
  EVP_MD_CTX_cleanup(&local_38);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar3;
}

