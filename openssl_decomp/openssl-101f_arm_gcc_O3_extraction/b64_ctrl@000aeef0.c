
long b64_ctrl(BIO *param_1,int param_2,long param_3,void *param_4)

{
  long lVar1;
  BIO *pBVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *outl;
  
  outl = (int *)param_1->ptr;
  if (param_2 == 0xb) {
    iVar5 = *outl;
    iVar3 = outl[1];
    while( true ) {
      while( true ) {
        if (iVar5 != iVar3) {
          do {
            iVar3 = b64_write(param_1,0,0);
            if (iVar3 < 0) {
              return iVar3;
            }
          } while (*outl != outl[1]);
        }
        uVar4 = BIO_test_flags(param_1,-1);
        if ((uVar4 & 0x100) == 0) break;
        if (outl[2] == 0) goto LAB_000af036;
        iVar5 = EVP_EncodeBlock((uchar *)(outl + 0x1f),(uchar *)((int)outl + 0x65a),outl[2]);
        outl[1] = 0;
        iVar3 = 0;
        outl[2] = 0;
        *outl = iVar5;
      }
      if ((outl[4] == 0) || (outl[7] == 0)) break;
      outl[1] = 0;
      EVP_EncodeFinal((EVP_ENCODE_CTX *)(outl + 7),(uchar *)(outl + 0x1f),outl);
      iVar5 = *outl;
      iVar3 = outl[1];
    }
LAB_000af036:
    pBVar2 = param_1->next_bio;
    param_2 = 0xb;
    goto LAB_000aef46;
  }
  if (param_2 < 0xc) {
    if (param_2 == 2) {
      if (outl[6] < 1) {
        return 1;
      }
      pBVar2 = param_1->next_bio;
      goto LAB_000aef46;
    }
    if (param_2 == 10) {
      iVar3 = *outl;
      iVar5 = outl[1];
      if (iVar3 < iVar5) {
        OpenSSLDie("bio_b64.c",0x20b,"ctx->buf_len >= ctx->buf_off");
        iVar3 = *outl;
        iVar5 = outl[1];
      }
      if (0 < iVar3 - iVar5) {
        return iVar3 - iVar5;
      }
      pBVar2 = param_1->next_bio;
      param_2 = 10;
      goto LAB_000aef46;
    }
    if (param_2 == 1) {
      pBVar2 = param_1->next_bio;
      outl[6] = 1;
      outl[5] = 1;
      outl[4] = 0;
      lVar1 = BIO_ctrl(pBVar2,1,param_3,param_4);
      return lVar1;
    }
  }
  else {
    if (param_2 == 0xd) {
      iVar3 = *outl;
      iVar5 = outl[1];
      if (iVar3 < iVar5) {
        OpenSSLDie("bio_b64.c",0x202,"ctx->buf_len >= ctx->buf_off");
        iVar3 = *outl;
        iVar5 = outl[1];
      }
      iVar3 = iVar3 - iVar5;
      if (iVar3 == 0) {
        if ((outl[4] != 0) && (outl[7] != 0)) {
          return 1;
        }
      }
      else if (0 < iVar3) {
        return iVar3;
      }
      pBVar2 = param_1->next_bio;
      param_2 = 0xd;
      goto LAB_000aef46;
    }
    if (param_2 < 0xd) {
      return 1;
    }
    if (param_2 == 0x65) {
      BIO_clear_flags(param_1,0xf);
      lVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar1;
    }
  }
  pBVar2 = param_1->next_bio;
LAB_000aef46:
  lVar1 = BIO_ctrl(pBVar2,param_2,param_3,param_4);
  return lVar1;
}

