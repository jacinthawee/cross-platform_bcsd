
int dtls1_write_bytes(undefined4 *param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  uchar *buf;
  undefined *puVar1;
  undefined4 uVar2;
  EVP_MD *pEVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int local_28;
  int local_24;
  
  if (0x4000 < (int)param_4) {
    OpenSSLDie("d1_pkt.c",0x5b8,"len <= SSL3_RT_MAX_PLAIN_LENGTH");
  }
  param_1[6] = 1;
  if (*(int *)(param_1[0x16] + 0x108) == 0) {
    if ((*(int *)(param_1[0x16] + 0x18c) != 0) &&
       (iVar6 = (**(code **)(param_1[2] + 0x3c))(param_1), iVar6 < 1)) {
      return iVar6;
    }
    if (param_4 == 0) {
      return 0;
    }
    iVar6 = param_1[0x16];
    if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
       (pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]), pEVar3 == (EVP_MD *)0x0)) {
      local_28 = 0;
    }
    else {
      pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
      local_28 = EVP_MD_size(pEVar3);
      if (local_28 < 0) {
        return -1;
      }
    }
    puVar1 = *(undefined **)(iVar6 + 0xfc);
    *puVar1 = (char)param_2;
    uVar2 = *param_1;
    *(undefined4 *)(iVar6 + 0x130) = param_2;
    puVar1[1] = (char)((uint)uVar2 >> 8);
    puVar1[2] = (char)*param_1;
    buf = puVar1 + 0xd;
    if (((EVP_CIPHER **)param_1[0x23] == (EVP_CIPHER **)0x0) ||
       (uVar4 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x23]), (uVar4 & 2) == 0)) {
      local_24 = 0;
    }
    else {
      local_24 = EVP_CIPHER_block_size(*(EVP_CIPHER **)param_1[0x23]);
    }
    *(size_t *)(iVar6 + 0x134) = param_4;
    *(void **)(iVar6 + 0x140) = param_3;
    iVar5 = param_1[0x25];
    *(uchar **)(iVar6 + 0x13c) = buf + local_24;
    if (iVar5 == 0) {
      memcpy(buf + local_24,param_3,param_4);
      *(undefined4 *)(iVar6 + 0x140) = *(undefined4 *)(iVar6 + 0x13c);
    }
    else {
      iVar5 = ssl3_do_compress(param_1);
      if (iVar5 == 0) {
        ERR_put_error(0x14,0xf5,0x8d,"d1_pkt.c",0x632);
        return -1;
      }
    }
    if (local_28 != 0) {
      iVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                        (param_1,buf + local_24 + *(int *)(iVar6 + 0x134),1);
      if (iVar5 < 0) {
        return -1;
      }
      *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_28;
    }
    *(uchar **)(iVar6 + 0x140) = buf;
    *(uchar **)(iVar6 + 0x13c) = buf;
    if (local_24 != 0) {
      RAND_pseudo_bytes(buf,local_24);
      *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_24;
    }
    (***(code ***)(param_1[2] + 100))(param_1,1);
    puVar1[3] = *(undefined *)(param_1[0x17] + 0x20b);
    puVar1[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
    iVar5 = param_1[0x16];
    *(undefined4 *)(puVar1 + 5) = *(undefined4 *)(iVar5 + 0x56);
    *(undefined2 *)(puVar1 + 9) = *(undefined2 *)(iVar5 + 0x5a);
    puVar1[0xb] = (char)((uint)*(undefined4 *)(iVar6 + 0x134) >> 8);
    puVar1[0xc] = (char)*(undefined4 *)(iVar6 + 0x134);
    iVar5 = param_1[0x16];
    *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + 0xd;
    *(undefined4 *)(iVar6 + 0x130) = param_2;
    ssl3_record_sequence_update(iVar5 + 0x54);
    *(undefined4 *)(iVar6 + 0x104) = 0;
    *(undefined4 *)(iVar6 + 0x108) = *(undefined4 *)(iVar6 + 0x134);
    iVar6 = param_1[0x16];
    *(size_t *)(iVar6 + 0x168) = param_4;
    *(void **)(iVar6 + 0x174) = param_3;
    *(undefined4 *)(iVar6 + 0x16c) = param_2;
    *(size_t *)(iVar6 + 0x170) = param_4;
  }
  else {
    OpenSSLDie("d1_pkt.c",0x5cc,"0");
  }
  iVar6 = ssl3_write_pending();
  return iVar6;
}

