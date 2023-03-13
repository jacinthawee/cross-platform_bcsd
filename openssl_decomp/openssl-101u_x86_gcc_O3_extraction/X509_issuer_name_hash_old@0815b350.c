
ulong X509_issuer_name_hash_old(X509 *a)

{
  X509_NAME *a_00;
  BUF_MEM *pBVar1;
  EVP_MD *type;
  int iVar2;
  int in_GS_OFFSET;
  EVP_MD_CTX local_38;
  ulong local_20 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  a_00 = a->cert_info->issuer;
  i2d_X509_NAME(a_00,(uchar **)0x0);
  EVP_MD_CTX_init(&local_38);
  EVP_MD_CTX_set_flags(&local_38,8);
  type = EVP_md5();
  iVar2 = EVP_DigestInit_ex(&local_38,type,(ENGINE *)0x0);
  if (((iVar2 == 0) ||
      (pBVar1 = a_00->bytes, iVar2 = EVP_DigestUpdate(&local_38,pBVar1->data,pBVar1->length),
      iVar2 == 0)) ||
     (iVar2 = EVP_DigestFinal_ex(&local_38,(uchar *)local_20,(uint *)0x0), iVar2 == 0)) {
    local_20[0] = 0;
  }
  EVP_MD_CTX_cleanup(&local_38);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_20[0];
}

