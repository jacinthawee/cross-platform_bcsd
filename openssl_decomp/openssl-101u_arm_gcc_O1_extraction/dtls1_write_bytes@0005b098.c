
int dtls1_write_bytes(undefined4 *param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  EVP_MD *pEVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  uchar *buf;
  int local_30;
  int local_2c;
  
  if (0x4000 < (int)param_4) {
    OpenSSLDie("d1_pkt.c",0x5f9,"len <= SSL3_RT_MAX_PLAIN_LENGTH");
  }
  param_1[6] = 1;
  if (*(int *)(param_1[0x16] + 0x108) != 0) {
    OpenSSLDie("d1_pkt.c",0x60f,"0");
    iVar5 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar5;
  }
  if ((*(int *)(param_1[0x16] + 0x18c) != 0) &&
     (iVar5 = (**(code **)(param_1[2] + 0x3c))(param_1), iVar5 < 1)) {
    return iVar5;
  }
  if (param_4 == 0) {
    return 0;
  }
  iVar5 = param_1[0x16];
  if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
     (pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]), pEVar1 == (EVP_MD *)0x0)) {
    local_2c = 0;
  }
  else {
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    local_2c = EVP_MD_size(pEVar1);
    if (local_2c < 0) {
      return -1;
    }
  }
  puVar6 = *(undefined **)(iVar5 + 0xfc);
  buf = puVar6 + 0xd;
  *puVar6 = (char)param_2;
  uVar3 = *param_1;
  *(undefined4 *)(iVar5 + 0x130) = param_2;
  puVar6[1] = (char)((uint)uVar3 >> 8);
  puVar6[2] = (char)*param_1;
  if (((EVP_CIPHER **)param_1[0x23] == (EVP_CIPHER **)0x0) ||
     (uVar2 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x23]), -1 < (int)(uVar2 << 0x1e))) {
    local_30 = 0;
  }
  else {
    local_30 = EVP_CIPHER_block_size(*(EVP_CIPHER **)param_1[0x23]);
  }
  iVar4 = param_1[0x25];
  *(size_t *)(iVar5 + 0x134) = param_4;
  *(void **)(iVar5 + 0x140) = param_3;
  *(uchar **)(iVar5 + 0x13c) = buf + local_30;
  if (iVar4 == 0) {
    memcpy(buf + local_30,param_3,param_4);
    *(undefined4 *)(iVar5 + 0x140) = *(undefined4 *)(iVar5 + 0x13c);
  }
  else {
    iVar4 = ssl3_do_compress(param_1);
    if (iVar4 == 0) {
      ERR_put_error(0x14,0xf5,0x8d,"d1_pkt.c",0x676);
      return -1;
    }
  }
  if (local_2c != 0) {
    iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,buf + local_30 + *(int *)(iVar5 + 0x134),1);
    if (iVar4 < 0) {
      return -1;
    }
    *(int *)(iVar5 + 0x134) = *(int *)(iVar5 + 0x134) + local_2c;
  }
  *(uchar **)(iVar5 + 0x140) = buf;
  *(uchar **)(iVar5 + 0x13c) = buf;
  if (local_30 != 0) {
    iVar4 = RAND_bytes(buf,local_30);
    if (iVar4 < 1) {
      return -1;
    }
    *(int *)(iVar5 + 0x134) = *(int *)(iVar5 + 0x134) + local_30;
  }
  iVar4 = (***(code ***)(param_1[2] + 100))(param_1,1);
  if (iVar4 < 1) {
    return -1;
  }
  puVar6[3] = (char)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
  puVar6[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
  iVar4 = param_1[0x16];
  *(undefined4 *)(puVar6 + 5) = *(undefined4 *)(iVar4 + 0x56);
  *(undefined2 *)(puVar6 + 9) = *(undefined2 *)(iVar4 + 0x5a);
  puVar6[0xb] = (char)((uint)*(undefined4 *)(iVar5 + 0x134) >> 8);
  puVar6[0xc] = (char)*(undefined4 *)(iVar5 + 0x134);
  iVar4 = param_1[0x16];
  *(undefined4 *)(iVar5 + 0x130) = param_2;
  *(int *)(iVar5 + 0x134) = *(int *)(iVar5 + 0x134) + 0xd;
  ssl3_record_sequence_update(iVar4 + 0x54);
  iVar4 = param_1[0x16];
  *(undefined4 *)(iVar5 + 0x104) = 0;
  *(undefined4 *)(iVar5 + 0x108) = *(undefined4 *)(iVar5 + 0x134);
  *(size_t *)(iVar4 + 0x168) = param_4;
  *(void **)(iVar4 + 0x174) = param_3;
  *(undefined4 *)(iVar4 + 0x16c) = param_2;
  *(size_t *)(iVar4 + 0x170) = param_4;
  iVar5 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar5;
}

