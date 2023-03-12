
uint pkey_rsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,uint param_5)

{
  uint m_length;
  int iVar1;
  void *__dest;
  uchar *EM;
  int iVar2;
  int iVar3;
  RSA *rsa;
  uint local_24;
  
  iVar3 = *(int *)(param_1 + 0x14);
  rsa = *(RSA **)(*(int *)(param_1 + 8) + 0x14);
  if (*(EVP_MD **)(iVar3 + 0x14) == (EVP_MD *)0x0) {
    local_24 = RSA_private_encrypt(param_5,param_4,param_2,rsa,*(int *)(iVar3 + 0x10));
    goto LAB_00108a84;
  }
  m_length = EVP_MD_size(*(EVP_MD **)(iVar3 + 0x14));
  if (m_length != param_5) {
    ERR_put_error(4,0x8e,0x8f,"rsa_pmeth.c",0xce);
    return -1;
  }
  iVar1 = EVP_MD_type(*(EVP_MD **)(iVar3 + 0x14));
  iVar2 = *(int *)(iVar3 + 0x10);
  if (iVar1 == 0x5f) {
    if (iVar2 != 1) {
      return -1;
    }
    iVar3 = RSA_sign_ASN1_OCTET_STRING(0x5f,param_4,m_length,param_2,&local_24,rsa);
  }
  else {
    if (iVar2 == 5) {
      __dest = *(void **)(iVar3 + 0x20);
      if (__dest == (void *)0x0) {
        iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        __dest = CRYPTO_malloc(iVar1,"rsa_pmeth.c",0x8d);
        *(void **)(iVar3 + 0x20) = __dest;
        if (__dest == (void *)0x0) {
          return -1;
        }
      }
      memcpy(__dest,param_4,m_length);
      iVar2 = *(int *)(iVar3 + 0x20);
      iVar1 = EVP_MD_type(*(EVP_MD **)(iVar3 + 0x14));
      iVar1 = RSA_X931_hash_id(iVar1);
      *(char *)(iVar2 + m_length) = (char)iVar1;
      local_24 = RSA_private_encrypt(m_length + 1,*(uchar **)(iVar3 + 0x20),param_2,rsa,5);
      goto LAB_00108a84;
    }
    if (iVar2 != 1) {
      if (iVar2 != 6) {
        return -1;
      }
      EM = *(uchar **)(iVar3 + 0x20);
      if (EM == (uchar *)0x0) {
        iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        EM = (uchar *)CRYPTO_malloc(iVar1,"rsa_pmeth.c",0x8d);
        *(uchar **)(iVar3 + 0x20) = EM;
        if (EM == (uchar *)0x0) {
          return -1;
        }
      }
      iVar1 = RSA_padding_add_PKCS1_PSS_mgf1
                        (rsa,EM,param_4,*(EVP_MD **)(iVar3 + 0x14),*(EVP_MD **)(iVar3 + 0x18),
                         *(int *)(iVar3 + 0x1c));
      if (iVar1 == 0) {
        return -1;
      }
      iVar1 = RSA_size(rsa);
      local_24 = RSA_private_encrypt(iVar1,*(uchar **)(iVar3 + 0x20),param_2,rsa,3);
      goto LAB_00108a84;
    }
    iVar3 = EVP_MD_type(*(EVP_MD **)(iVar3 + 0x14));
    iVar3 = RSA_sign(iVar3,param_4,m_length,param_2,&local_24,rsa);
  }
  if (iVar3 < 1) {
    return iVar3;
  }
LAB_00108a84:
  if (-1 < (int)local_24) {
    *param_3 = local_24;
    local_24 = 1;
  }
  return local_24;
}

