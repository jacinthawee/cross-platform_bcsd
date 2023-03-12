
size_t ssl3_output_cert_chain(int param_1,X509 *param_2)

{
  int iVar1;
  size_t sVar2;
  X509 *pXVar3;
  int iVar4;
  char *pcVar5;
  size_t len;
  int iVar6;
  BUF_MEM *str;
  size_t len_00;
  uchar *local_b4;
  X509_STORE_CTX local_b0;
  
  if (*(int *)(param_1 + 0x104) << 0x1c < 0) {
    iVar6 = 1;
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 0xe4) + 0x94);
    if (iVar6 != 0) {
      iVar6 = 1;
    }
  }
  str = *(BUF_MEM **)(param_1 + 0x3c);
  iVar1 = BUF_MEM_grow_clean(str,10);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0x93,7,"s3_both.c",0x16e);
    return 0;
  }
  if (param_2 == (X509 *)0x0) {
    len = 7;
  }
  else if (iVar6 == 0) {
    iVar1 = X509_STORE_CTX_init(&local_b0,*(X509_STORE **)(*(int *)(param_1 + 0xe4) + 0xc),param_2,
                                (stack_st_X509 *)0x0);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x93,0xb,"s3_both.c",0x17e);
      return 0;
    }
    X509_verify_cert(&local_b0);
    ERR_clear_error();
    len = 7;
    while( true ) {
      iVar1 = sk_num(&(local_b0.chain)->stack);
      if (iVar1 <= iVar6) break;
      pXVar3 = (X509 *)sk_value(&(local_b0.chain)->stack,iVar6);
      iVar1 = i2d_X509(pXVar3,(uchar **)0x0);
      sVar2 = iVar1 + 3 + len;
      iVar4 = BUF_MEM_grow_clean(str,sVar2);
      if (iVar4 == 0) {
        ERR_put_error(0x14,0x128,7,"s3_both.c",0x152);
        X509_STORE_CTX_cleanup(&local_b0);
        return 0;
      }
      pcVar5 = str->data;
      pcVar5[len] = (char)((uint)iVar1 >> 0x10);
      pcVar5[len + 1] = (char)((uint)iVar1 >> 8);
      pcVar5[len + 2] = (char)iVar1;
      local_b4 = (uchar *)(pcVar5 + len + 3);
      i2d_X509(pXVar3,&local_b4);
      len = sVar2;
      iVar6 = iVar6 + 1;
    }
    X509_STORE_CTX_cleanup(&local_b0);
  }
  else {
    iVar6 = i2d_X509(param_2,(uchar **)0x0);
    len = iVar6 + 10;
    sVar2 = BUF_MEM_grow_clean(str,len);
    if (sVar2 == 0) goto LAB_000528c4;
    pcVar5 = str->data;
    local_b0.ctx = (X509_STORE *)(pcVar5 + 10);
    pcVar5[9] = (char)iVar6;
    pcVar5[7] = (char)((uint)iVar6 >> 0x10);
    pcVar5[8] = (char)((uint)iVar6 >> 8);
    i2d_X509(param_2,(uchar **)&local_b0);
  }
  iVar6 = 0;
  while( true ) {
    iVar1 = sk_num(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94));
    if (iVar1 <= iVar6) {
      pcVar5 = str->data;
      iVar6 = len - 7;
      iVar1 = len - 4;
      pcVar5[6] = (char)iVar6;
      pcVar5[4] = (char)((uint)iVar6 >> 0x10);
      pcVar5[5] = (char)((uint)iVar6 >> 8);
      pcVar5 = str->data;
      *pcVar5 = '\v';
      pcVar5[3] = (char)iVar1;
      pcVar5[1] = (char)((uint)iVar1 >> 0x10);
      pcVar5[2] = (char)((uint)iVar1 >> 8);
      return len;
    }
    pXVar3 = (X509 *)sk_value(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94),iVar6);
    iVar1 = i2d_X509(pXVar3,(uchar **)0x0);
    len_00 = iVar1 + 3 + len;
    sVar2 = BUF_MEM_grow_clean(str,len_00);
    if (sVar2 == 0) break;
    pcVar5 = str->data;
    pcVar5[len] = (char)((uint)iVar1 >> 0x10);
    pcVar5[len + 1] = (char)((uint)iVar1 >> 8);
    pcVar5[len + 2] = (char)iVar1;
    local_b0.ctx = (X509_STORE *)(pcVar5 + len + 3);
    i2d_X509(pXVar3,(uchar **)&local_b0);
    len = len_00;
    iVar6 = iVar6 + 1;
  }
LAB_000528c4:
  ERR_put_error(0x14,0x128,7,"s3_both.c",0x152);
  return sVar2;
}

