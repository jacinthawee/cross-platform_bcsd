
size_t ssl3_output_cert_chain(int param_1,X509 *param_2)

{
  size_t sVar1;
  BUF_MEM *str;
  int iVar2;
  int iVar3;
  X509 *pXVar4;
  int iVar5;
  size_t len;
  char *pcVar6;
  int in_GS_OFFSET;
  bool bVar7;
  uchar *local_ac;
  X509_STORE_CTX local_a8;
  int local_20;
  
  bVar7 = true;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)(param_1 + 0x104) & 8) == 0) {
    bVar7 = *(int *)(*(int *)(param_1 + 0xe4) + 0x94) != 0;
  }
  str = *(BUF_MEM **)(param_1 + 0x3c);
  iVar2 = BUF_MEM_grow_clean(str,10);
  if (iVar2 == 0) {
    ERR_put_error(0x14,0x93,7,"s3_both.c",0x16b);
    len = 0;
    goto LAB_080a6316;
  }
  if (param_2 == (X509 *)0x0) {
    len = 7;
  }
  else if (bVar7) {
    iVar2 = i2d_X509(param_2,(uchar **)0x0);
    len = iVar2 + 10;
    iVar3 = BUF_MEM_grow_clean(str,len);
    if (iVar3 == 0) {
LAB_080a6480:
      ERR_put_error(0x14,0x128,7,"s3_both.c",0x150);
      len = 0;
      goto LAB_080a6316;
    }
    pcVar6 = str->data;
    pcVar6[7] = (char)((uint)iVar2 >> 0x10);
    pcVar6[9] = (char)iVar2;
    local_a8.ctx = (X509_STORE *)(pcVar6 + 10);
    pcVar6[8] = (char)((uint)iVar2 >> 8);
    i2d_X509(param_2,(uchar **)&local_a8);
  }
  else {
    iVar2 = X509_STORE_CTX_init(&local_a8,*(X509_STORE **)(*(int *)(param_1 + 0xe4) + 0xc),param_2,
                                (stack_st_X509 *)0x0);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x93,0xb,"s3_both.c",0x176);
      len = 0;
      goto LAB_080a6316;
    }
    iVar2 = 0;
    X509_verify_cert(&local_a8);
    ERR_clear_error();
    len = 7;
    while( true ) {
      iVar3 = sk_num(&(local_a8.chain)->stack);
      if (iVar3 <= iVar2) break;
      pXVar4 = (X509 *)sk_value(&(local_a8.chain)->stack,iVar2);
      iVar3 = i2d_X509(pXVar4,(uchar **)0x0);
      sVar1 = len + 3 + iVar3;
      iVar5 = BUF_MEM_grow_clean(str,sVar1);
      if (iVar5 == 0) {
        ERR_put_error(0x14,0x128,7,"s3_both.c",0x150);
        X509_STORE_CTX_cleanup(&local_a8);
        len = 0;
        goto LAB_080a6316;
      }
      iVar2 = iVar2 + 1;
      pcVar6 = str->data + len;
      *pcVar6 = (char)((uint)iVar3 >> 0x10);
      pcVar6[1] = (char)((uint)iVar3 >> 8);
      pcVar6[2] = (char)iVar3;
      local_ac = (uchar *)(pcVar6 + 3);
      i2d_X509(pXVar4,&local_ac);
      len = sVar1;
    }
    X509_STORE_CTX_cleanup(&local_a8);
  }
  iVar2 = 0;
  while( true ) {
    iVar3 = sk_num(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94));
    if (iVar3 <= iVar2) break;
    pXVar4 = (X509 *)sk_value(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94),iVar2);
    iVar3 = i2d_X509(pXVar4,(uchar **)0x0);
    sVar1 = len + 3 + iVar3;
    iVar5 = BUF_MEM_grow_clean(str,sVar1);
    if (iVar5 == 0) goto LAB_080a6480;
    iVar2 = iVar2 + 1;
    pcVar6 = str->data + len;
    *pcVar6 = (char)((uint)iVar3 >> 0x10);
    pcVar6[1] = (char)((uint)iVar3 >> 8);
    pcVar6[2] = (char)iVar3;
    local_a8.ctx = (X509_STORE *)(pcVar6 + 3);
    i2d_X509(pXVar4,(uchar **)&local_a8);
    len = sVar1;
  }
  iVar2 = len - 7;
  pcVar6 = str->data;
  pcVar6[4] = (char)((uint)iVar2 >> 0x10);
  pcVar6[6] = (char)iVar2;
  iVar3 = len - 4;
  pcVar6[5] = (char)((uint)iVar2 >> 8);
  pcVar6 = str->data;
  pcVar6[1] = (char)((uint)iVar3 >> 0x10);
  *pcVar6 = '\v';
  pcVar6[3] = (char)iVar3;
  pcVar6[2] = (char)((uint)iVar3 >> 8);
LAB_080a6316:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

