
size_t dtls1_output_cert_chain(int param_1,X509 *param_2)

{
  size_t sVar1;
  short sVar2;
  BUF_MEM *str;
  int iVar3;
  int iVar4;
  X509 *pXVar5;
  int iVar6;
  size_t sVar7;
  short sVar8;
  char *pcVar9;
  int in_GS_OFFSET;
  uchar *local_ac;
  X509_STORE_CTX local_a8;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  str = *(BUF_MEM **)(param_1 + 0x3c);
  iVar3 = BUF_MEM_grow_clean(str,10);
  if (iVar3 == 0) {
    ERR_put_error(0x14,0xff,7,"d1_both.c",0x479);
    sVar7 = 0;
  }
  else {
    if (param_2 == (X509 *)0x0) {
      sVar7 = 0xf;
    }
    else {
      iVar3 = X509_STORE_CTX_init(&local_a8,*(X509_STORE **)(*(int *)(param_1 + 0xe4) + 0xc),param_2
                                  ,(stack_st_X509 *)0x0);
      if (iVar3 == 0) {
        ERR_put_error(0x14,0xff,0xb,"d1_both.c",0x480);
LAB_080ba60e:
        sVar7 = 0;
        goto LAB_080ba610;
      }
      iVar3 = 0;
      X509_verify_cert(&local_a8);
      ERR_clear_error();
      sVar7 = 0xf;
      while( true ) {
        iVar4 = sk_num(&(local_a8.chain)->stack);
        if (iVar4 <= iVar3) break;
        pXVar5 = (X509 *)sk_value(&(local_a8.chain)->stack,iVar3);
        iVar4 = i2d_X509(pXVar5,(uchar **)0x0);
        sVar1 = iVar4 + 3 + sVar7;
        iVar6 = BUF_MEM_grow_clean(str,sVar1);
        if (iVar6 == 0) {
          ERR_put_error(0x14,0x127,7,"d1_both.c",0x464);
          X509_STORE_CTX_cleanup(&local_a8);
          goto LAB_080ba60e;
        }
        iVar3 = iVar3 + 1;
        pcVar9 = str->data + sVar7;
        *pcVar9 = (char)((uint)iVar4 >> 0x10);
        pcVar9[1] = (char)((uint)iVar4 >> 8);
        pcVar9[2] = (char)iVar4;
        local_ac = (uchar *)(pcVar9 + 3);
        i2d_X509(pXVar5,&local_ac);
        sVar7 = sVar1;
      }
      X509_STORE_CTX_cleanup(&local_a8);
    }
    iVar3 = 0;
    while( true ) {
      iVar4 = sk_num(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94));
      if (iVar4 <= iVar3) break;
      pXVar5 = (X509 *)sk_value(*(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94),iVar3);
      iVar4 = i2d_X509(pXVar5,(uchar **)0x0);
      sVar1 = sVar7 + 3 + iVar4;
      iVar6 = BUF_MEM_grow_clean(str,sVar1);
      if (iVar6 == 0) {
        ERR_put_error(0x14,0x127,7,"d1_both.c",0x464);
        goto LAB_080ba60e;
      }
      iVar3 = iVar3 + 1;
      pcVar9 = str->data + sVar7;
      *pcVar9 = (char)((uint)iVar4 >> 0x10);
      pcVar9[1] = (char)((uint)iVar4 >> 8);
      pcVar9[2] = (char)iVar4;
      local_a8.ctx = (X509_STORE *)(pcVar9 + 3);
      i2d_X509(pXVar5,(uchar **)&local_a8);
      sVar7 = sVar1;
    }
    iVar3 = sVar7 - 0xf;
    pcVar9 = str->data;
    pcVar9[0xc] = (char)((uint)iVar3 >> 0x10);
    pcVar9[0xe] = (char)iVar3;
    pcVar9[0xd] = (char)((uint)iVar3 >> 8);
    iVar3 = *(int *)(param_1 + 0x5c);
    sVar2 = *(short *)(iVar3 + 0x226);
    sVar8 = *(short *)(iVar3 + 0x224);
    if (*(int *)(iVar3 + 0x254) == 0) {
      *(short *)(iVar3 + 0x224) = sVar2;
      *(short *)(iVar3 + 0x226) = sVar2 + 1;
      sVar8 = sVar2;
    }
    *(undefined *)(iVar3 + 0x260) = 0xb;
    *(size_t *)(iVar3 + 0x264) = sVar7 - 0xc;
    *(short *)(iVar3 + 0x268) = sVar8;
    *(undefined4 *)(iVar3 + 0x26c) = 0;
    *(size_t *)(iVar3 + 0x270) = sVar7 - 0xc;
  }
LAB_080ba610:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

