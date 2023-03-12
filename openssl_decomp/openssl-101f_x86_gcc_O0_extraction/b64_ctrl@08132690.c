
long b64_ctrl(BIO *param_1,int param_2,long param_3,char *param_4)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  int *outl;
  bio_st *pbVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  outl = (int *)param_1->ptr;
  if (param_2 == 0xb) {
    iVar4 = *outl;
    iVar6 = outl[1];
    while( true ) {
      while( true ) {
        if (iVar4 != iVar6) {
          do {
            iVar4 = b64_write(param_1,0,0);
            if (iVar4 < 0) {
              return iVar4;
            }
          } while (*outl != outl[1]);
        }
        uVar5 = BIO_test_flags(param_1,-1);
        if ((uVar5 & 0x100) != 0) break;
        if ((outl[4] == 0) || (outl[7] == 0)) goto LAB_081328d0;
        outl[1] = 0;
        EVP_EncodeFinal((EVP_ENCODE_CTX *)(outl + 7),(uchar *)(outl + 0x1f),outl);
        iVar4 = *outl;
        iVar6 = outl[1];
      }
      if (outl[2] == 0) break;
      iVar4 = EVP_EncodeBlock((uchar *)(outl + 0x1f),(uchar *)((int)outl + 0x65a),outl[2]);
      outl[1] = 0;
      *outl = iVar4;
      outl[2] = 0;
      iVar6 = 0;
    }
LAB_081328d0:
    param_2 = 0xb;
  }
  else if (param_2 < 0xc) {
    if (param_2 == 2) {
      if (outl[6] < 1) {
        return 1;
      }
      param_2 = 2;
    }
    else if (param_2 == 10) {
      iVar4 = *outl;
      iVar6 = outl[1];
      if (iVar4 < iVar6) {
        OpenSSLDie("bio_b64.c",0x20b,"ctx->buf_len >= ctx->buf_off");
        iVar4 = *outl;
        iVar6 = outl[1];
      }
      if (0 < iVar4 - iVar6) {
        return iVar4 - iVar6;
      }
      param_2 = 10;
    }
    else if (param_2 == 1) {
      outl[6] = 1;
      outl[5] = 1;
      outl[4] = 0;
      param_2 = 1;
    }
  }
  else if (param_2 == 0xd) {
    iVar4 = *outl;
    iVar6 = outl[1];
    if (iVar4 < iVar6) {
      OpenSSLDie("bio_b64.c",0x202,"ctx->buf_len >= ctx->buf_off");
      iVar4 = *outl;
      iVar6 = outl[1];
    }
    iVar4 = iVar4 - iVar6;
    if (iVar4 == 0) {
      if ((outl[4] != 0) && (outl[7] != 0)) {
        return 1;
      }
    }
    else if (0 < iVar4) {
      return iVar4;
    }
    param_2 = 0xd;
  }
  else {
    if (param_2 < 0xd) {
      return 1;
    }
    if (param_2 == 0x65) {
      BIO_clear_flags(param_1,0xf);
      lVar3 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar3;
    }
  }
  pbVar2 = param_1->next_bio;
  if (pbVar2 == (bio_st *)0x0) {
    return 0;
  }
  if ((pbVar2->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = pbVar2->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    lVar3 = -2;
  }
  else {
    p_Var1 = pbVar2->callback;
    if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08117b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar3 = (*UNRECOVERED_JUMPTABLE)(pbVar2,param_2,param_3,param_4);
      return lVar3;
    }
    lVar3 = (*p_Var1)(pbVar2,6,param_4,param_2,param_3,1);
    if (0 < lVar3) {
      lVar3 = (*pbVar2->method->ctrl)(pbVar2,param_2,param_3,param_4);
      lVar3 = (*p_Var1)(pbVar2,0x86,param_4,param_2,param_3,lVar3);
    }
  }
  return lVar3;
}

