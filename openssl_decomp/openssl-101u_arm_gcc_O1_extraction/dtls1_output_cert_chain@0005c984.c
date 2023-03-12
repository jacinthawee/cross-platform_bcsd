
size_t dtls1_output_cert_chain(int param_1,X509 *param_2)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  X509 *pXVar4;
  int iVar5;
  short sVar6;
  char *pcVar7;
  BUF_MEM *str;
  size_t sVar8;
  uchar *local_b4;
  X509_STORE_CTX local_b0;
  
  str = *(BUF_MEM **)(param_1 + 0x3c);
  sVar1 = BUF_MEM_grow_clean(str,10);
  if (sVar1 == 0) {
    ERR_put_error(0x14,0xff,7,"d1_both.c",0x479);
  }
  else {
    if (param_2 == (X509 *)0x0) {
      sVar1 = 0xf;
    }
    else {
      iVar2 = X509_STORE_CTX_init(&local_b0,*(X509_STORE **)(*(int *)(param_1 + 0xe4) + 0xc),param_2
                                  ,(stack_st_X509 *)0x0);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xff,0xb,"d1_both.c",0x480);
        return 0;
      }
      X509_verify_cert(&local_b0);
      ERR_clear_error();
      sVar1 = 0xf;
      iVar2 = 0;
      while( true ) {
        iVar3 = sk_num(&(local_b0.chain)->stack);
        if (iVar3 <= iVar2) break;
        pXVar4 = (X509 *)sk_value(&(local_b0.chain)->stack,iVar2);
        iVar3 = i2d_X509(pXVar4,(uchar **)0x0);
        sVar8 = iVar3 + 3 + sVar1;
        iVar5 = BUF_MEM_grow_clean(str,sVar8);
        if (iVar5 == 0) {
          ERR_put_error(0x14,0x127,7,"d1_both.c",0x464);
          X509_STORE_CTX_cleanup(&local_b0);
          return 0;
        }
        pcVar7 = str->data;
        pcVar7[sVar1] = (char)((uint)iVar3 >> 0x10);
        pcVar7[sVar1 + 1] = (char)((uint)iVar3 >> 8);
        pcVar7[sVar1 + 2] = (char)iVar3;
        local_b4 = (uchar *)(pcVar7 + sVar1 + 3);
        i2d_X509(pXVar4,&local_b4);
        sVar1 = sVar8;
        iVar2 = iVar2 + 1;
      }
      X509_STORE_CTX_cleanup(&local_b0);
    }
    iVar2 = 0;
    while( true ) {
      iVar3 = sk_num(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94));
      if (iVar3 <= iVar2) break;
      pXVar4 = (X509 *)sk_value(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94),iVar2);
      iVar3 = i2d_X509(pXVar4,(uchar **)0x0);
      sVar8 = iVar3 + 3 + sVar1;
      iVar5 = BUF_MEM_grow_clean(str,sVar8);
      if (iVar5 == 0) {
        ERR_put_error(0x14,0x127,7,"d1_both.c",0x464);
        return 0;
      }
      pcVar7 = str->data;
      pcVar7[sVar1] = (char)((uint)iVar3 >> 0x10);
      pcVar7[sVar1 + 1] = (char)((uint)iVar3 >> 8);
      pcVar7[sVar1 + 2] = (char)iVar3;
      local_b0.ctx = (X509_STORE *)(pcVar7 + sVar1 + 3);
      i2d_X509(pXVar4,(uchar **)&local_b0);
      sVar1 = sVar8;
      iVar2 = iVar2 + 1;
    }
    pcVar7 = str->data;
    iVar2 = sVar1 - 0xf;
    pcVar7[0xe] = (char)iVar2;
    pcVar7[0xc] = (char)((uint)iVar2 >> 0x10);
    pcVar7[0xd] = (char)((uint)iVar2 >> 8);
    iVar2 = *(int *)(param_1 + 0x5c);
    if (*(int *)(iVar2 + 0x254) == 0) {
      sVar6 = *(short *)(iVar2 + 0x226);
      *(short *)(iVar2 + 0x226) = sVar6 + 1;
      *(short *)(iVar2 + 0x224) = sVar6;
    }
    else {
      sVar6 = *(short *)(iVar2 + 0x224);
    }
    *(short *)(iVar2 + 0x268) = sVar6;
    *(size_t *)(iVar2 + 0x264) = sVar1 - 0xc;
    *(size_t *)(iVar2 + 0x270) = sVar1 - 0xc;
    *(undefined *)(iVar2 + 0x260) = 0xb;
    *(undefined4 *)(iVar2 + 0x26c) = 0;
  }
  return sVar1;
}

