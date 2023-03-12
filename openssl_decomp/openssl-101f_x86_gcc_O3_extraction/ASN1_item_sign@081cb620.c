
int ASN1_item_sign(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
                  void *data,EVP_PKEY *pkey,EVP_MD *type)

{
  int iVar1;
  int in_GS_OFFSET;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_38);
  iVar1 = EVP_DigestSignInit(&local_38,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
  if (iVar1 == 0) {
    EVP_MD_CTX_cleanup(&local_38);
  }
  else {
    iVar1 = ASN1_item_sign_ctx(it,algor1,algor2,signature,data,&local_38);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

