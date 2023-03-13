
undefined4 dtls1_buffer_message(int *param_1,int param_2)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined *ptr;
  void *__dest;
  int iVar4;
  pitem *item;
  undefined4 uVar5;
  int in_GS_OFFSET;
  int iVar6;
  char *assertion;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x501,"s->init_off == 0");
  }
  iVar6 = param_1[0x11];
  ptr = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
  if (ptr == (undefined *)0x0) {
LAB_080badb0:
    uVar5 = 0;
    goto LAB_080bad0f;
  }
  __dest = (void *)0x0;
  if (iVar6 != 0) {
    __dest = CRYPTO_malloc(iVar6,"d1_both.c",0xba);
    if (__dest == (void *)0x0) {
      CRYPTO_free(ptr);
      goto LAB_080badb0;
    }
  }
  iVar6 = param_1[0xf];
  *(void **)(ptr + 0x2c) = __dest;
  *(undefined4 *)(ptr + 0x30) = 0;
  memcpy(__dest,*(void **)(iVar6 + 4),param_1[0x11]);
  iVar6 = param_1[0x17];
  iVar4 = *(int *)(iVar6 + 0x264);
  if (param_2 == 0) {
    if (iVar4 + 0xc != param_1[0x11]) {
      assertion = "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num";
      iVar6 = 0x510;
LAB_080bac49:
      OpenSSLDie("d1_both.c",iVar6,assertion);
      iVar6 = param_1[0x17];
      iVar4 = *(int *)(iVar6 + 0x264);
    }
  }
  else if (iVar4 + 1 + (uint)(*param_1 != 0xfeff) * 2 != param_1[0x11]) {
    assertion = 
    "s->d1->w_msg_hdr.msg_len + ((s->version == DTLS1_VERSION) ? DTLS1_CCS_HEADER_LENGTH : 3) == (unsigned int)s->init_num"
    ;
    iVar6 = 0x50d;
    goto LAB_080bac49;
  }
  *(int *)(ptr + 4) = iVar4;
  uVar2 = *(ushort *)(iVar6 + 0x268);
  *(ushort *)(ptr + 8) = uVar2;
  uVar1 = *(undefined *)(iVar6 + 0x260);
  iVar4 = (uint)uVar2 * 2 - param_2;
  *(undefined4 *)(ptr + 0xc) = 0;
  *ptr = uVar1;
  local_28 = 0;
  uVar5 = *(undefined4 *)(param_1[0x17] + 0x264);
  uVar3 = *(undefined2 *)(param_1[0x17] + 0x20a);
  *(int *)(ptr + 0x14) = param_2;
  *(undefined4 *)(ptr + 0x10) = uVar5;
  *(int *)(ptr + 0x18) = param_1[0x23];
  *(int *)(ptr + 0x1c) = param_1[0x24];
  *(int *)(ptr + 0x20) = param_1[0x25];
  iVar6 = param_1[0x30];
  *(undefined2 *)(ptr + 0x28) = uVar3;
  *(int *)(ptr + 0x24) = iVar6;
  local_24 = (uint)CONCAT11((char)iVar4,(char)((uint)iVar4 >> 8)) << 0x10;
  item = pitem_new((uchar *)&local_28,ptr);
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
    uVar5 = 0;
  }
  else {
    pqueue_insert(*(pqueue *)(param_1[0x17] + 0x248),item);
    uVar5 = 1;
  }
LAB_080bad0f:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

