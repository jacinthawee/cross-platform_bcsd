
size_t pkey_rsa_verifyrecover(int param_1,uchar *param_2,size_t *param_3,uchar *param_4,int param_5)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uchar *to;
  size_t sVar6;
  size_t sVar7;
  int in_GS_OFFSET;
  size_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(EVP_MD **)(iVar3 + 0x14) == (EVP_MD *)0x0) {
    local_24 = RSA_public_decrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x14),
                                  *(int *)(iVar3 + 0x10));
LAB_081c16c6:
    sVar7 = local_24;
    if ((int)local_24 < 0) goto LAB_081c16d1;
  }
  else {
    if (*(int *)(iVar3 + 0x10) != 5) {
      if (*(int *)(iVar3 + 0x10) != 1) {
LAB_081c17c8:
        sVar7 = 0xffffffff;
        goto LAB_081c16d1;
      }
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x14);
      iVar3 = EVP_MD_type(*(EVP_MD **)(iVar3 + 0x14));
      iVar3 = int_rsa_verify(iVar3,0,0,param_2,&local_24,param_4,param_5,uVar2);
      if (iVar3 < 1) {
        sVar7 = 0;
        goto LAB_081c16d1;
      }
      goto LAB_081c16c6;
    }
    to = *(uchar **)(iVar3 + 0x20);
    if (to == (uchar *)0x0) {
      iVar4 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      to = (uchar *)CRYPTO_malloc(iVar4,"rsa_pmeth.c",0x8c);
      *(uchar **)(iVar3 + 0x20) = to;
      if (to == (uchar *)0x0) goto LAB_081c17c8;
    }
    sVar7 = 0;
    iVar4 = RSA_public_decrypt(param_5,param_4,to,*(RSA **)(*(int *)(param_1 + 8) + 0x14),5);
    if (iVar4 < 1) goto LAB_081c16d1;
    local_24 = iVar4 - 1;
    bVar1 = *(byte *)(*(int *)(iVar3 + 0x20) + -1 + iVar4);
    iVar4 = EVP_MD_type(*(EVP_MD **)(iVar3 + 0x14));
    uVar5 = RSA_X931_hash_id(iVar4);
    if (bVar1 != uVar5) {
      ERR_put_error(4,0x8d,100,"rsa_pmeth.c",0x122);
      goto LAB_081c16d1;
    }
    sVar6 = EVP_MD_size(*(EVP_MD **)(iVar3 + 0x14));
    if (local_24 != sVar6) {
      ERR_put_error(4,0x8d,0x8f,"rsa_pmeth.c",0x127);
      goto LAB_081c16d1;
    }
    if (param_2 != (uchar *)0x0) {
      memcpy(param_2,*(void **)(iVar3 + 0x20),local_24);
    }
  }
  *param_3 = local_24;
  sVar7 = 1;
LAB_081c16d1:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar7;
}

