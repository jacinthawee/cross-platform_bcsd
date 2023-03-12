
void dtls1_send_finished(int param_1,int param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  size_t sVar4;
  undefined *data;
  pitem *item;
  void *__src;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  void *__dest;
  undefined4 uVar9;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(int *)(param_1 + 0x34) != param_2) goto LAB_0005c772;
  iVar8 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  sVar4 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x14))
                    (param_1,param_4,param_5,*(int *)(param_1 + 0x58) + 0x234);
  iVar7 = *(int *)(param_1 + 0x58);
  *(size_t *)(iVar7 + 0x2b4) = sVar4;
  memcpy((void *)(iVar8 + 0xc),(void *)(iVar7 + 0x234),sVar4);
  if (*(int *)(param_1 + 4) == 0x1000) {
    if (0x40 < (int)sVar4) {
      OpenSSLDie("d1_both.c",0x416,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),(void *)(*(int *)(param_1 + 0x58) + 0x234),
           sVar4);
    *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)sVar4;
  }
  else {
    if (0x40 < (int)sVar4) {
      OpenSSLDie("d1_both.c",0x41a,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),(void *)(*(int *)(param_1 + 0x58) + 0x234),
           sVar4);
    *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)sVar4;
  }
  iVar7 = *(int *)(param_1 + 0x5c);
  if (*(int *)(iVar7 + 0x254) == 0) {
    sVar5 = *(short *)(iVar7 + 0x226);
    *(short *)(iVar7 + 0x226) = sVar5 + 1;
    *(short *)(iVar7 + 0x224) = sVar5;
  }
  else {
    sVar5 = *(short *)(iVar7 + 0x224);
  }
  *(size_t *)(iVar7 + 0x264) = sVar4;
  *(short *)(iVar7 + 0x268) = sVar5;
  __dest = (void *)(sVar4 + 0xc);
  *(size_t *)(iVar7 + 0x270) = sVar4;
  *(undefined4 *)(iVar7 + 0x26c) = 0;
  *(undefined *)(iVar7 + 0x260) = 0x14;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(void **)(param_1 + 0x44) = __dest;
  data = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
  if (data != (undefined *)0x0) {
    if ((__dest == (void *)0x0) ||
       (__dest = CRYPTO_malloc((int)__dest,"d1_both.c",0xba), __dest != (void *)0x0)) {
      iVar7 = *(int *)(param_1 + 0x3c);
      sVar4 = *(size_t *)(param_1 + 0x44);
      *(void **)(data + 0x2c) = __dest;
      __src = *(void **)(iVar7 + 4);
      *(undefined4 *)(data + 0x30) = 0;
      memcpy(__dest,__src,sVar4);
      iVar8 = *(int *)(param_1 + 0x5c);
      iVar7 = *(int *)(iVar8 + 0x264);
      if (iVar7 + 0xc != *(int *)(param_1 + 0x44)) {
        OpenSSLDie("d1_both.c",0x510,
                   "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num")
        ;
        iVar8 = *(int *)(param_1 + 0x5c);
        iVar7 = *(int *)(iVar8 + 0x264);
      }
      uVar1 = *(undefined *)(iVar8 + 0x260);
      uVar2 = *(ushort *)(iVar8 + 0x268);
      *(int *)(data + 4) = iVar7;
      *data = uVar1;
      iVar7 = (uint)uVar2 << 1;
      iVar8 = *(int *)(param_1 + 0x5c);
      local_2c = 0;
      *(undefined4 *)(data + 0x18) = *(undefined4 *)(param_1 + 0x8c);
      uVar3 = *(undefined2 *)(iVar8 + 0x20a);
      *(undefined4 *)(data + 0x1c) = *(undefined4 *)(param_1 + 0x90);
      uVar6 = *(undefined4 *)(iVar8 + 0x264);
      *(ushort *)(data + 8) = uVar2;
      uVar9 = *(undefined4 *)(param_1 + 0x94);
      *(undefined4 *)(data + 0x10) = uVar6;
      uVar6 = *(undefined4 *)(param_1 + 0xc0);
      *(undefined4 *)(data + 0xc) = 0;
      *(undefined4 *)(data + 0x20) = uVar9;
      *(undefined4 *)(data + 0x24) = uVar6;
      *(undefined2 *)(data + 0x28) = uVar3;
      *(undefined4 *)(data + 0x14) = 0;
      local_28 = (uint)CONCAT11((char)iVar7,(char)((uint)iVar7 >> 8)) << 0x10;
      item = pitem_new((uchar *)&local_2c,data);
      if (item != (pitem *)0x0) {
        pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248),item);
        goto LAB_0005c8d4;
      }
      if (*(int *)(data + 0x14) != 0) {
        EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(data + 0x18));
        EVP_MD_CTX_destroy(*(EVP_MD_CTX **)(data + 0x1c));
      }
      if (*(void **)(data + 0x2c) != (void *)0x0) {
        CRYPTO_free(*(void **)(data + 0x2c));
      }
      if (*(void **)(data + 0x30) != (void *)0x0) {
        CRYPTO_free(*(void **)(data + 0x30));
      }
    }
    CRYPTO_free(data);
  }
LAB_0005c8d4:
  *(undefined4 *)(param_1 + 0x34) = param_3;
LAB_0005c772:
  dtls1_do_write(param_1,0x16);
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

