
int dtls1_dispatch_alert(undefined4 *param_1)

{
  EVP_MD *pEVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  undefined *puVar8;
  uchar *buf;
  int num;
  undefined2 local_24 [2];
  
  iVar7 = param_1[0x16];
  local_24[0] = *(undefined2 *)(iVar7 + 400);
  *(undefined4 *)(iVar7 + 0x18c) = 0;
  if (*(int *)(iVar7 + 0x108) == 0) {
    if (((param_1[0x30] != 0) && (param_1[0x23] != 0)) &&
       (pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]), pEVar1 != (EVP_MD *)0x0)) {
      pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
      iVar2 = EVP_MD_size(pEVar1);
      if (-1 < iVar2) goto LAB_0005da04;
LAB_0005dc36:
      iVar7 = -1;
      goto LAB_0005db7e;
    }
    iVar2 = 0;
LAB_0005da04:
    puVar8 = *(undefined **)(iVar7 + 0xfc);
    buf = puVar8 + 0xd;
    *puVar8 = 0x15;
    uVar4 = *param_1;
    *(undefined4 *)(iVar7 + 0x130) = 0x15;
    puVar8[1] = (char)((uint)uVar4 >> 8);
    puVar8[2] = (char)*param_1;
    if (((EVP_CIPHER **)param_1[0x23] == (EVP_CIPHER **)0x0) ||
       (uVar3 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x23]), -1 < (int)(uVar3 << 0x1e))) {
      num = 0;
    }
    else {
      num = EVP_CIPHER_block_size(*(EVP_CIPHER **)param_1[0x23]);
    }
    iVar5 = param_1[0x25];
    *(undefined2 **)(iVar7 + 0x140) = local_24;
    *(uchar **)(iVar7 + 0x13c) = buf + num;
    *(undefined4 *)(iVar7 + 0x134) = 2;
    if (iVar5 == 0) {
      *(undefined2 *)(buf + num) = local_24[0];
      *(undefined4 *)(iVar7 + 0x140) = *(undefined4 *)(iVar7 + 0x13c);
    }
    else {
      iVar5 = ssl3_do_compress(param_1);
      if (iVar5 == 0) {
        iVar7 = -1;
        ERR_put_error(0x14,0xf5,0x8d,"d1_pkt.c",0x632);
        goto LAB_0005db7e;
      }
    }
    if (iVar2 == 0) {
      *(uchar **)(iVar7 + 0x140) = buf;
      *(uchar **)(iVar7 + 0x13c) = buf;
    }
    else {
      iVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                        (param_1,buf + num + *(int *)(iVar7 + 0x134),1);
      if (iVar5 < 0) goto LAB_0005dc36;
      *(uchar **)(iVar7 + 0x140) = buf;
      *(uchar **)(iVar7 + 0x13c) = buf;
      *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + iVar2;
    }
    if (num != 0) {
      RAND_pseudo_bytes(buf,num);
      *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + num;
    }
    (***(code ***)(param_1[2] + 100))(param_1,1);
    puVar8[3] = (char)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
    puVar8[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
    iVar2 = param_1[0x16];
    *(undefined4 *)(puVar8 + 5) = *(undefined4 *)(iVar2 + 0x56);
    *(undefined2 *)(puVar8 + 9) = *(undefined2 *)(iVar2 + 0x5a);
    puVar8[0xb] = (char)((uint)*(undefined4 *)(iVar7 + 0x134) >> 8);
    puVar8[0xc] = (char)*(undefined4 *)(iVar7 + 0x134);
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar7 + 0x130) = 0x15;
    *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + 0xd;
    ssl3_record_sequence_update(iVar2 + 0x54);
    iVar2 = param_1[0x16];
    *(undefined4 *)(iVar7 + 0x108) = *(undefined4 *)(iVar7 + 0x134);
    *(undefined4 *)(iVar7 + 0x104) = 0;
    *(undefined4 *)(iVar2 + 0x16c) = 0x15;
    *(undefined2 **)(iVar2 + 0x174) = local_24;
    *(undefined4 *)(iVar2 + 0x168) = 2;
    *(undefined4 *)(iVar2 + 0x170) = 2;
    iVar7 = ssl3_write_pending(param_1,0x15,local_24,2);
  }
  else {
    OpenSSLDie("d1_pkt.c",0x5cc,"0");
    iVar7 = ssl3_write_pending(param_1,0x15,local_24,2);
  }
  if (0 < iVar7) {
    if (*(char *)(param_1[0x16] + 400) == '\x02') {
      BIO_ctrl((BIO *)param_1[4],0xb,0,(void *)0x0);
    }
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
    }
    pcVar6 = (code *)param_1[0x34];
    if ((pcVar6 != (code *)0x0) ||
       (pcVar6 = *(code **)(param_1[0x39] + 0x9c), pcVar6 != (code *)0x0)) {
      (*pcVar6)(param_1,0x4008,
                CONCAT11(*(undefined *)(param_1[0x16] + 400),*(undefined *)(param_1[0x16] + 0x191)))
      ;
    }
    return iVar7;
  }
LAB_0005db7e:
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
  return iVar7;
}

