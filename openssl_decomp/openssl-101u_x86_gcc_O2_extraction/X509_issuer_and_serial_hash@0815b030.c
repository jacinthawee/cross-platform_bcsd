
ulong X509_issuer_and_serial_hash(X509 *a)

{
  ASN1_INTEGER *pAVar1;
  char *__s;
  EVP_MD *type;
  int iVar2;
  size_t cnt;
  int in_GS_OFFSET;
  EVP_MD_CTX local_38;
  ulong local_20 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_38);
  __s = X509_NAME_oneline(a->cert_info->issuer,(char *)0x0,0);
  type = EVP_md5();
  iVar2 = EVP_DigestInit_ex(&local_38,type,(ENGINE *)0x0);
  if (iVar2 != 0) {
    cnt = strlen(__s);
    iVar2 = EVP_DigestUpdate(&local_38,__s,cnt);
    if (iVar2 != 0) {
      CRYPTO_free(__s);
      pAVar1 = a->cert_info->serialNumber;
      iVar2 = EVP_DigestUpdate(&local_38,pAVar1->data,pAVar1->length);
      if ((iVar2 != 0) &&
         (iVar2 = EVP_DigestFinal_ex(&local_38,(uchar *)local_20,(uint *)0x0), iVar2 != 0))
      goto LAB_0815b07d;
    }
  }
  local_20[0] = 0;
LAB_0815b07d:
  EVP_MD_CTX_cleanup(&local_38);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_20[0];
}

