
undefined4 rc4_hmac_md5_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  RC4_KEY *key;
  int iVar1;
  MD5_CTX *pMVar2;
  MD5_CTX *c;
  uint *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  key = (RC4_KEY *)param_1->cipher_data;
  iVar1 = EVP_CIPHER_CTX_key_length(param_1);
  c = (MD5_CTX *)(key->data + 0x3f);
  RC4_set_key(key,iVar1,param_2);
  MD5_Init(c);
  pMVar2 = c;
  puVar3 = key->data + 0x56;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = pMVar2->A;
    pMVar2 = (MD5_CTX *)((int)pMVar2 + (uint)bVar4 * -8 + 4);
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  puVar3 = key->data + 0x6d;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = c->A;
    c = (MD5_CTX *)((int)c + (uint)bVar4 * -8 + 4);
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  key->data[0x84] = 0xffffffff;
  return 1;
}

