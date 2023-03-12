
void dtls1_buffer_message(int *param_1,int param_2)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined *ptr;
  pitem *item;
  int iVar4;
  void *__src;
  size_t __n;
  int iVar5;
  undefined4 uVar6;
  void *__dest;
  int iVar7;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (param_1[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x501,"s->init_off == 0");
  }
  __dest = (void *)param_1[0x11];
  ptr = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
  if (ptr != (undefined *)0x0) {
    if ((__dest == (void *)0x0) ||
       (__dest = CRYPTO_malloc((int)__dest,"d1_both.c",0xba), __dest != (void *)0x0)) {
      iVar4 = param_1[0xf];
      *(void **)(ptr + 0x2c) = __dest;
      __n = param_1[0x11];
      __src = *(void **)(iVar4 + 4);
      *(undefined4 *)(ptr + 0x30) = 0;
      memcpy(__dest,__src,__n);
      iVar4 = param_1[0x17];
      if (param_2 == 0) {
        iVar5 = *(int *)(iVar4 + 0x264);
        if (iVar5 + 0xc != param_1[0x11]) {
          OpenSSLDie("d1_both.c",0x510,
                     "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num"
                    );
          iVar4 = param_1[0x17];
          iVar5 = *(int *)(iVar4 + 0x264);
        }
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x264);
        if (*param_1 == 0xfeff) {
          iVar7 = 1;
        }
        else {
          iVar7 = 3;
        }
        if (iVar7 + iVar5 != param_1[0x11]) {
          OpenSSLDie("d1_both.c",0x50d,
                     "s->d1->w_msg_hdr.msg_len + ((s->version == DTLS1_VERSION) ? DTLS1_CCS_HEADER_LENGTH : 3) == (unsigned int)s->init_num"
                    );
          iVar4 = param_1[0x17];
          iVar5 = *(int *)(iVar4 + 0x264);
        }
      }
      uVar1 = *(undefined *)(iVar4 + 0x260);
      uVar2 = *(ushort *)(iVar4 + 0x268);
      *(int *)(ptr + 4) = iVar5;
      *ptr = uVar1;
      iVar7 = (uint)uVar2 * 2 - param_2;
      iVar4 = param_1[0x17];
      local_2c = 0;
      *(int *)(ptr + 0x18) = param_1[0x23];
      uVar3 = *(undefined2 *)(iVar4 + 0x20a);
      *(int *)(ptr + 0x1c) = param_1[0x24];
      uVar6 = *(undefined4 *)(iVar4 + 0x264);
      iVar4 = param_1[0x30];
      *(ushort *)(ptr + 8) = uVar2;
      *(undefined4 *)(ptr + 0x10) = uVar6;
      iVar5 = param_1[0x25];
      *(undefined4 *)(ptr + 0xc) = 0;
      *(int *)(ptr + 0x14) = param_2;
      *(int *)(ptr + 0x20) = iVar5;
      *(undefined2 *)(ptr + 0x28) = uVar3;
      *(int *)(ptr + 0x24) = iVar4;
      local_28 = (uint)CONCAT11((char)iVar7,(char)((uint)iVar7 >> 8)) << 0x10;
      item = pitem_new((uchar *)&local_2c,ptr);
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
        uVar6 = 0;
      }
      else {
        pqueue_insert(*(pqueue *)(param_1[0x17] + 0x248),item);
        uVar6 = 1;
      }
      goto LAB_0005cec6;
    }
    CRYPTO_free(ptr);
  }
  uVar6 = 0;
LAB_0005cec6:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}

