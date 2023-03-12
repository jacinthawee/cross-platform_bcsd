
uint pkey_rsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,uint param_5)

{
  RSA *rsa;
  uint m_length;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *__dest;
  uchar *puVar5;
  int in_GS_OFFSET;
  uint local_24;
  int local_20;
  
  iVar2 = *(int *)(param_1 + 0x14);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  rsa = *(RSA **)(*(int *)(param_1 + 8) + 0x14);
  if (*(EVP_MD **)(iVar2 + 0x14) == (EVP_MD *)0x0) {
    local_24 = RSA_private_encrypt(param_5,param_4,param_2,rsa,*(int *)(iVar2 + 0x10));
  }
  else {
    m_length = EVP_MD_size(*(EVP_MD **)(iVar2 + 0x14));
    if (m_length != param_5) {
      ERR_put_error(4,0x8e,0x8f,"rsa_pmeth.c",0xce);
      uVar3 = 0xffffffff;
      goto LAB_081c2ace;
    }
    iVar1 = EVP_MD_type(*(EVP_MD **)(iVar2 + 0x14));
    if (iVar1 == 0x5f) {
      uVar3 = 0xffffffff;
      if (*(int *)(iVar2 + 0x10) != 1) goto LAB_081c2ace;
      uVar3 = RSA_sign_ASN1_OCTET_STRING(0x5f,param_4,m_length,param_2,&local_24,rsa);
    }
    else {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (iVar1 == 5) {
        __dest = *(void **)(iVar2 + 0x20);
        if (__dest == (void *)0x0) {
          iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
          __dest = CRYPTO_malloc(iVar1,"rsa_pmeth.c",0x8d);
          *(void **)(iVar2 + 0x20) = __dest;
          if (__dest == (void *)0x0) goto LAB_081c2c00;
        }
        memcpy(__dest,param_4,m_length);
        iVar1 = *(int *)(iVar2 + 0x20);
        iVar4 = EVP_MD_type(*(EVP_MD **)(iVar2 + 0x14));
        iVar4 = RSA_X931_hash_id(iVar4);
        *(char *)(iVar1 + m_length) = (char)iVar4;
        local_24 = RSA_private_encrypt(m_length + 1,*(uchar **)(iVar2 + 0x20),param_2,rsa,5);
        goto LAB_081c2abf;
      }
      if (iVar1 != 1) {
        if (iVar1 == 6) {
          puVar5 = *(uchar **)(iVar2 + 0x20);
          if (puVar5 == (uchar *)0x0) {
            iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
            puVar5 = (uchar *)CRYPTO_malloc(iVar1,"rsa_pmeth.c",0x8d);
            *(uchar **)(iVar2 + 0x20) = puVar5;
            if (puVar5 == (uchar *)0x0) goto LAB_081c2c00;
          }
          iVar1 = RSA_padding_add_PKCS1_PSS_mgf1
                            (rsa,puVar5,param_4,*(EVP_MD **)(iVar2 + 0x14),
                             *(EVP_MD **)(iVar2 + 0x18),*(int *)(iVar2 + 0x1c));
          if (iVar1 != 0) {
            puVar5 = *(uchar **)(iVar2 + 0x20);
            iVar2 = RSA_size(rsa);
            local_24 = RSA_private_encrypt(iVar2,puVar5,param_2,rsa,3);
            goto LAB_081c2abf;
          }
        }
LAB_081c2c00:
        uVar3 = 0xffffffff;
        goto LAB_081c2ace;
      }
      iVar2 = EVP_MD_type(*(EVP_MD **)(iVar2 + 0x14));
      uVar3 = RSA_sign(iVar2,param_4,m_length,param_2,&local_24,rsa);
    }
    if ((int)uVar3 < 1) goto LAB_081c2ace;
  }
LAB_081c2abf:
  uVar3 = local_24;
  if (-1 < (int)local_24) {
    *param_3 = local_24;
    uVar3 = 1;
  }
LAB_081c2ace:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

