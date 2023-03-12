
size_t pkey_rsa_verifyrecover(int param_1,uchar *param_2,size_t *param_3,uchar *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int nid;
  uint uVar3;
  uchar *to;
  int iVar4;
  size_t asStack_24 [2];
  
  iVar4 = *(int *)(param_1 + 0x14);
  if (*(EVP_MD **)(iVar4 + 0x14) == (EVP_MD *)0x0) {
    asStack_24[0] =
         RSA_public_decrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x14),
                            *(int *)(iVar4 + 0x10));
  }
  else {
    if (*(int *)(iVar4 + 0x10) == 5) {
      to = *(uchar **)(iVar4 + 0x20);
      if (to == (uchar *)0x0) {
        iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        to = (uchar *)CRYPTO_malloc(iVar2,"rsa_pmeth.c",0x8d);
        *(uchar **)(iVar4 + 0x20) = to;
        if (to == (uchar *)0x0) {
          return 0xffffffff;
        }
      }
      iVar2 = RSA_public_decrypt(param_5,param_4,to,*(RSA **)(*(int *)(param_1 + 8) + 0x14),5);
      if (iVar2 < 1) {
        return 0;
      }
      bVar1 = *(byte *)(*(int *)(iVar4 + 0x20) + (iVar2 - 1U));
      nid = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x14));
      uVar3 = RSA_X931_hash_id(nid);
      if (bVar1 != uVar3) {
        ERR_put_error(4,0x8d,100,"rsa_pmeth.c",0x131);
        return 0;
      }
      asStack_24[0] = EVP_MD_size(*(EVP_MD **)(iVar4 + 0x14));
      if (asStack_24[0] != iVar2 - 1U) {
        ERR_put_error(4,0x8d,0x8f,"rsa_pmeth.c",0x137);
        return 0;
      }
      if (param_2 != (uchar *)0x0) {
        memcpy(param_2,*(void **)(iVar4 + 0x20),asStack_24[0]);
      }
      goto LAB_00108942;
    }
    if (*(int *)(iVar4 + 0x10) != 1) {
      return 0xffffffff;
    }
    iVar4 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x14));
    iVar4 = int_rsa_verify(iVar4,0,0,param_2,asStack_24,param_4,param_5,
                           *(undefined4 *)(*(int *)(param_1 + 8) + 0x14));
    if (iVar4 < 1) {
      return 0;
    }
  }
  if ((int)asStack_24[0] < 0) {
    return asStack_24[0];
  }
LAB_00108942:
  *param_3 = asStack_24[0];
  return 1;
}

