
void dtls1_send_finished(int param_1,int param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5)

{
  undefined uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  size_t __n;
  undefined *data;
  void *__dest;
  pitem *item;
  short sVar6;
  int iVar7;
  int iVar8;
  int in_GS_OFFSET;
  undefined4 local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(param_1 + 0x34) != param_2) goto LAB_080ba174;
  iVar7 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  __n = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x14))
                  (param_1,param_4,param_5,*(int *)(param_1 + 0x58) + 0x234);
  iVar8 = *(int *)(param_1 + 0x58);
  *(size_t *)(iVar8 + 0x2b4) = __n;
  memcpy((void *)(iVar7 + 0xc),(void *)(iVar8 + 0x234),__n);
  if (*(int *)(param_1 + 4) == 0x1000) {
    if (0x40 < (int)__n) {
      OpenSSLDie("d1_both.c",0x416,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),(void *)(*(int *)(param_1 + 0x58) + 0x234),__n
          );
    *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)__n;
  }
  else {
    if (0x40 < (int)__n) {
      OpenSSLDie("d1_both.c",0x41a,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),(void *)(*(int *)(param_1 + 0x58) + 0x234),__n
          );
    *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)__n;
  }
  iVar7 = *(int *)(param_1 + 0x5c);
  sVar2 = *(short *)(iVar7 + 0x226);
  sVar6 = *(short *)(iVar7 + 0x224);
  if (*(int *)(iVar7 + 0x254) == 0) {
    *(short *)(iVar7 + 0x224) = sVar2;
    *(short *)(iVar7 + 0x226) = sVar2 + 1;
    sVar6 = sVar2;
  }
  *(size_t *)(iVar7 + 0x264) = __n;
  *(size_t *)(iVar7 + 0x270) = __n;
  iVar8 = __n + 0xc;
  *(undefined *)(iVar7 + 0x260) = 0x14;
  *(short *)(iVar7 + 0x268) = sVar6;
  *(undefined4 *)(iVar7 + 0x26c) = 0;
  *(int *)(param_1 + 0x44) = iVar8;
  *(undefined4 *)(param_1 + 0x48) = 0;
  data = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
  if (data != (undefined *)0x0) {
    __dest = (void *)0x0;
    if (iVar8 == 0) {
LAB_080ba2a7:
      iVar7 = *(int *)(param_1 + 0x3c);
      *(void **)(data + 0x2c) = __dest;
      *(undefined4 *)(data + 0x30) = 0;
      memcpy(__dest,*(void **)(iVar7 + 4),*(size_t *)(param_1 + 0x44));
      iVar7 = *(int *)(param_1 + 0x5c);
      iVar8 = *(int *)(iVar7 + 0x264);
      if (iVar8 + 0xc != *(int *)(param_1 + 0x44)) {
        OpenSSLDie("d1_both.c",0x510,
                   "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num")
        ;
        iVar7 = *(int *)(param_1 + 0x5c);
        iVar8 = *(int *)(iVar7 + 0x264);
      }
      *(int *)(data + 4) = iVar8;
      uVar3 = *(ushort *)(iVar7 + 0x268);
      *(ushort *)(data + 8) = uVar3;
      uVar1 = *(undefined *)(iVar7 + 0x260);
      iVar7 = (uint)uVar3 * 2;
      *(undefined4 *)(data + 0xc) = 0;
      *data = uVar1;
      local_18 = 0;
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x264);
      uVar4 = *(undefined2 *)(*(int *)(param_1 + 0x5c) + 0x20a);
      *(undefined4 *)(data + 0x14) = 0;
      *(undefined4 *)(data + 0x10) = uVar5;
      *(undefined4 *)(data + 0x18) = *(undefined4 *)(param_1 + 0x8c);
      *(undefined4 *)(data + 0x1c) = *(undefined4 *)(param_1 + 0x90);
      *(undefined4 *)(data + 0x20) = *(undefined4 *)(param_1 + 0x94);
      uVar5 = *(undefined4 *)(param_1 + 0xc0);
      *(undefined2 *)(data + 0x28) = uVar4;
      *(undefined4 *)(data + 0x24) = uVar5;
      local_14 = (uint)CONCAT11((char)iVar7,(char)((uint)iVar7 >> 8)) << 0x10;
      item = pitem_new((uchar *)&local_18,data);
      if (item != (pitem *)0x0) {
        pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248),item);
        goto LAB_080ba3a7;
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
    else {
      __dest = CRYPTO_malloc(iVar8,"d1_both.c",0xba);
      if (__dest != (void *)0x0) goto LAB_080ba2a7;
    }
    CRYPTO_free(data);
  }
LAB_080ba3a7:
  *(undefined4 *)(param_1 + 0x34) = param_3;
LAB_080ba174:
  dtls1_do_write(param_1,0x16);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

