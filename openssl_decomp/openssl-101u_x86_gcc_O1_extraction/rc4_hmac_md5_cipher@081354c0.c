
int rc4_hmac_md5_cipher(int param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  size_t len;
  MD5_CTX *pMVar1;
  RC4_KEY *key;
  size_t len_00;
  int iVar2;
  int iVar3;
  uchar *md;
  uint *puVar4;
  MD5_CTX *pMVar5;
  int in_GS_OFFSET;
  byte bVar6;
  uchar local_30 [16];
  int local_20;
  
  bVar6 = 0;
  key = *(RC4_KEY **)(param_1 + 0x60);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = 0;
  len_00 = key->data[0x84];
  if (len_00 == 0xffffffff) {
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
    len = len_00 + 0x10;
    if (len != param_4) goto LAB_08135505;
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == 0) {
      pMVar1 = (MD5_CTX *)(key->data + 0x6d);
      RC4(key,len,param_3,param_2);
      MD5_Update(pMVar1,param_2,len_00);
      MD5_Final(local_30,pMVar1);
      puVar4 = key->data + 0x56;
      pMVar5 = pMVar1;
      for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
        pMVar5->A = *puVar4;
        puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
        pMVar5 = (MD5_CTX *)((int)pMVar5 + (uint)bVar6 * -8 + 4);
      }
      MD5_Update(pMVar1,local_30,0x10);
      MD5_Final(local_30,pMVar1);
      iVar2 = CRYPTO_memcmp(param_2 + len_00,local_30,0x10);
      if (iVar2 != 0) goto LAB_08135505;
    }
    else {
      pMVar1 = (MD5_CTX *)(key->data + 0x6d);
      MD5_Update(pMVar1,param_3,len_00);
      if (param_3 != param_2) {
        memcpy(param_2,param_3,len_00);
      }
      md = param_2 + len_00;
      MD5_Final(md,pMVar1);
      puVar4 = key->data + 0x56;
      pMVar5 = pMVar1;
      for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
        pMVar5->A = *puVar4;
        puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
        pMVar5 = (MD5_CTX *)((int)pMVar5 + (uint)bVar6 * -8 + 4);
      }
      MD5_Update(pMVar1,md,0x10);
      MD5_Final(md,pMVar1);
      RC4(key,len,param_2,param_2);
    }
  }
  key->data[0x84] = 0xffffffff;
  iVar3 = 1;
LAB_08135505:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

