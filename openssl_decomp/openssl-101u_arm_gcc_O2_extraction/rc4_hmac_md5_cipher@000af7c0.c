
void rc4_hmac_md5_cipher(int param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  int iVar1;
  RC4_KEY *key;
  size_t len;
  uchar *md;
  int iVar2;
  MD5_CTX *pMVar3;
  size_t len_00;
  uchar auStack_34 [16];
  int local_24;
  
  key = *(RC4_KEY **)(param_1 + 0x60);
  len = key->data[0x84];
  local_24 = __stack_chk_guard;
  if (len == 0xffffffff) {
    if (*(int *)(param_1 + 8) == 0) {
      RC4(key,param_4,param_3,param_2);
      MD5_Update((MD5_CTX *)(key->data + 0x6d),param_2,param_4);
    }
    else {
      MD5_Update((MD5_CTX *)(key->data + 0x6d),param_3,param_4);
      RC4(key,param_4,param_3,param_2);
    }
  }
  else {
    len_00 = len + 0x10;
    if (len_00 != param_4) {
      iVar2 = 0;
      goto LAB_000af7f4;
    }
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == 0) {
      pMVar3 = (MD5_CTX *)(key->data + 0x6d);
      RC4(key,len_00,param_3,param_2);
      MD5_Update(pMVar3,param_2,len);
      MD5_Final(auStack_34,pMVar3);
      memcpy(pMVar3,key->data + 0x56,0x5c);
      MD5_Update(pMVar3,auStack_34,0x10);
      MD5_Final(auStack_34,pMVar3);
      iVar1 = CRYPTO_memcmp(param_2 + len,auStack_34,0x10);
      if (iVar1 != 0) goto LAB_000af7f4;
    }
    else {
      pMVar3 = (MD5_CTX *)(key->data + 0x6d);
      MD5_Update(pMVar3,param_3,len);
      if (param_3 != param_2) {
        memcpy(param_2,param_3,len);
      }
      md = param_2 + len;
      MD5_Final(md,pMVar3);
      memcpy(pMVar3,key->data + 0x56,0x5c);
      MD5_Update(pMVar3,md,0x10);
      MD5_Final(md,pMVar3);
      RC4(key,len_00,param_2,param_2);
    }
  }
  iVar2 = 1;
  key->data[0x84] = 0xffffffff;
LAB_000af7f4:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}

