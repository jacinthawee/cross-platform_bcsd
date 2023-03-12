
void dtls1_send_finished(int param_1,int param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5)

{
  undefined uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  size_t __n;
  undefined *ptr;
  void *__dest;
  int iVar6;
  pitem *item;
  short sVar7;
  int iVar8;
  int in_GS_OFFSET;
  undefined4 local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(param_1 + 0x34) != param_2) {
LAB_080bca84:
    dtls1_do_write(param_1,0x16);
    if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  __n = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x14))
                  (param_1,param_4,param_5,*(int *)(param_1 + 0x58) + 0x234);
  iVar6 = *(int *)(param_1 + 0x58);
  *(size_t *)(iVar6 + 0x2b4) = __n;
  memcpy((void *)(iVar8 + 0xc),(void *)(iVar6 + 0x234),__n);
  if (*(int *)(param_1 + 4) == 0x1000) {
    if (0x40 < (int)__n) {
      OpenSSLDie("d1_both.c",0x3a0,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),(void *)(*(int *)(param_1 + 0x58) + 0x234),__n
          );
    *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)__n;
  }
  else {
    if (0x40 < (int)__n) {
      OpenSSLDie("d1_both.c",0x3a7,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),(void *)(*(int *)(param_1 + 0x58) + 0x234),__n
          );
    *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)__n;
  }
  iVar8 = *(int *)(param_1 + 0x5c);
  sVar2 = *(short *)(iVar8 + 0x226);
  sVar7 = *(short *)(iVar8 + 0x224);
  if (*(int *)(iVar8 + 0x254) == 0) {
    *(short *)(iVar8 + 0x224) = sVar2;
    *(short *)(iVar8 + 0x226) = sVar2 + 1;
    sVar7 = sVar2;
  }
  iVar6 = __n + 0xc;
  *(size_t *)(iVar8 + 0x260) = __n;
  *(size_t *)(iVar8 + 0x26c) = __n;
  *(undefined *)(iVar8 + 0x25c) = 0x14;
  *(short *)(iVar8 + 0x264) = sVar7;
  *(undefined4 *)(iVar8 + 0x268) = 0;
  *(int *)(param_1 + 0x44) = iVar6;
  *(undefined4 *)(param_1 + 0x48) = 0;
  ptr = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
  if (ptr != (undefined *)0x0) {
    __dest = (void *)0x0;
    if ((iVar6 == 0) || (__dest = CRYPTO_malloc(iVar6,"d1_both.c",0xb9), __dest != (void *)0x0)) {
      iVar8 = *(int *)(param_1 + 0x3c);
      *(void **)(ptr + 0x2c) = __dest;
      *(undefined4 *)(ptr + 0x30) = 0;
      memcpy(__dest,*(void **)(iVar8 + 4),*(size_t *)(param_1 + 0x44));
      iVar8 = *(int *)(param_1 + 0x5c);
      iVar6 = *(int *)(iVar8 + 0x260);
      if (iVar6 + 0xc != *(int *)(param_1 + 0x44)) {
        OpenSSLDie("d1_both.c",0x4a1,
                   "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num")
        ;
        iVar8 = *(int *)(param_1 + 0x5c);
        iVar6 = *(int *)(iVar8 + 0x260);
      }
      *(int *)(ptr + 4) = iVar6;
      uVar3 = *(ushort *)(iVar8 + 0x264);
      *(ushort *)(ptr + 8) = uVar3;
      uVar1 = *(undefined *)(iVar8 + 0x25c);
      iVar8 = (uint)uVar3 * 2;
      *(undefined4 *)(ptr + 0xc) = 0;
      *ptr = uVar1;
      local_18 = 0;
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x260);
      uVar4 = *(undefined2 *)(*(int *)(param_1 + 0x5c) + 0x20a);
      *(undefined4 *)(ptr + 0x14) = 0;
      *(undefined4 *)(ptr + 0x10) = uVar5;
      *(undefined4 *)(ptr + 0x18) = *(undefined4 *)(param_1 + 0x8c);
      *(undefined4 *)(ptr + 0x1c) = *(undefined4 *)(param_1 + 0x90);
      *(undefined4 *)(ptr + 0x20) = *(undefined4 *)(param_1 + 0x94);
      uVar5 = *(undefined4 *)(param_1 + 0xc0);
      *(undefined2 *)(ptr + 0x28) = uVar4;
      *(undefined4 *)(ptr + 0x24) = uVar5;
      local_14 = (uint)CONCAT11((char)iVar8,(char)((uint)iVar8 >> 8)) << 0x10;
      item = pitem_new((uchar *)&local_18,ptr);
      if (item == (pitem *)0x0) {
        if (*(int *)(ptr + 0x14) != 0) {
          EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(ptr + 0x18));
          EVP_MD_CTX_destroy(*(EVP_MD_CTX **)(ptr + 0x1c));
        }
        if (*(void **)(ptr + 0x2c) != (void *)0x0) {
          CRYPTO_free(*(void **)(ptr + 0x2c));
        }
        if (*(void **)(ptr + 0x30) != (void *)0x0) {
          CRYPTO_free(*(void **)(ptr + 0x30));
        }
        CRYPTO_free(ptr);
      }
      else {
        pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248),item);
      }
      *(undefined4 *)(param_1 + 0x34) = param_3;
      goto LAB_080bca84;
    }
    CRYPTO_free(ptr);
  }
  do {
    invalidInstructionException();
  } while( true );
}

