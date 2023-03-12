
void dtls1_buffer_message(int *param_1,int param_2)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined *ptr;
  undefined *__dest;
  int iVar4;
  pitem *item;
  int iVar5;
  int iVar6;
  undefined *num;
  undefined4 uVar7;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  local_2c = __TMC_END__;
  if (param_1[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x493,"s->init_off == 0");
  }
  num = (undefined *)param_1[0x11];
  ptr = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
  __dest = puRam0000002c;
  if (ptr != (undefined *)0x0) {
    if ((num == (undefined *)0x0) ||
       (num = (undefined *)CRYPTO_malloc((int)num,"d1_both.c",0xb9), num != (undefined *)0x0)) {
      *(undefined **)(ptr + 0x2c) = num;
      *(undefined4 *)(ptr + 0x30) = 0;
      __dest = num;
    }
    else {
      CRYPTO_free(ptr);
      __dest = puRam0000002c;
      ptr = num;
    }
  }
  memcpy(__dest,*(void **)(param_1[0xf] + 4),param_1[0x11]);
  iVar6 = param_1[0x17];
  if (param_2 == 0) {
    iVar5 = *(int *)(iVar6 + 0x260);
    if (iVar5 + 0xc != param_1[0x11]) {
      OpenSSLDie("d1_both.c",0x4a1,
                 "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num");
      iVar6 = param_1[0x17];
      iVar5 = *(int *)(iVar6 + 0x260);
    }
  }
  else {
    iVar5 = *(int *)(iVar6 + 0x260);
    if (*param_1 == 0xfeff) {
      iVar4 = 1;
    }
    else {
      iVar4 = 3;
    }
    if (iVar4 + iVar5 != param_1[0x11]) {
      OpenSSLDie("d1_both.c",0x49c,
                 "s->d1->w_msg_hdr.msg_len + ((s->version==DTLS1_VERSION)?DTLS1_CCS_HEADER_LENGTH:3) == (unsigned int)s->init_num"
                );
      iVar6 = param_1[0x17];
      iVar5 = *(int *)(iVar6 + 0x260);
    }
  }
  uVar1 = *(undefined *)(iVar6 + 0x25c);
  uVar2 = *(ushort *)(iVar6 + 0x264);
  *(int *)(ptr + 4) = iVar5;
  *ptr = uVar1;
  iVar4 = (uint)uVar2 * 2 - param_2;
  iVar6 = param_1[0x17];
  local_34 = 0;
  *(int *)(ptr + 0x18) = param_1[0x23];
  uVar3 = *(undefined2 *)(iVar6 + 0x20a);
  *(int *)(ptr + 0x1c) = param_1[0x24];
  uVar7 = *(undefined4 *)(iVar6 + 0x260);
  *(ushort *)(ptr + 8) = uVar2;
  iVar6 = param_1[0x25];
  *(undefined4 *)(ptr + 0x10) = uVar7;
  iVar5 = param_1[0x30];
  *(undefined4 *)(ptr + 0xc) = 0;
  *(int *)(ptr + 0x14) = param_2;
  *(int *)(ptr + 0x20) = iVar6;
  *(undefined2 *)(ptr + 0x28) = uVar3;
  *(int *)(ptr + 0x24) = iVar5;
  local_30 = (uint)CONCAT11((char)iVar4,(char)((uint)iVar4 >> 8)) << 0x10;
  item = pitem_new((uchar *)&local_34,ptr);
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
    uVar7 = 0;
  }
  else {
    pqueue_insert(*(pqueue *)(param_1[0x17] + 0x248),item);
    uVar7 = 1;
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar7);
}

