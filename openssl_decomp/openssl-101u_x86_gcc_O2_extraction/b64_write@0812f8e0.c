
int b64_write(BIO *param_1,uchar *param_2,uint param_3)

{
  int *out;
  int *outl;
  int iVar1;
  uint uVar2;
  int *data;
  int iVar3;
  int iVar4;
  uint __n;
  int local_24;
  
  outl = (int *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  if (outl[4] != 1) {
    outl[4] = 1;
    *outl = 0;
    outl[1] = 0;
    outl[2] = 0;
    EVP_EncodeInit((EVP_ENCODE_CTX *)(outl + 7));
  }
  if (0x5dd < outl[1]) {
    OpenSSLDie("bio_b64.c",0x17a,"ctx->buf_off < (int)sizeof(ctx->buf)");
  }
  iVar4 = *outl;
  if (0x5de < iVar4) {
    OpenSSLDie("bio_b64.c",0x17b,"ctx->buf_len <= (int)sizeof(ctx->buf)");
    iVar4 = *outl;
  }
  iVar3 = outl[1];
  if (iVar4 < iVar3) {
    OpenSSLDie("bio_b64.c",0x17c,"ctx->buf_len >= ctx->buf_off");
    iVar4 = *outl;
    iVar3 = outl[1];
  }
  iVar4 = iVar4 - iVar3;
  if (iVar4 < 1) {
LAB_0812fa12:
    outl[1] = 0;
    *outl = 0;
    if ((param_2 == (uchar *)0x0) || ((int)param_3 < 1)) {
      local_24 = 0;
    }
    else {
      out = outl + 0x1f;
      local_24 = 0;
      do {
        __n = 0x400;
        if ((int)param_3 < 0x401) {
          __n = param_3;
        }
        uVar2 = BIO_test_flags(param_1,-1);
        if ((uVar2 & 0x100) == 0) {
          EVP_EncodeUpdate((EVP_ENCODE_CTX *)(outl + 7),(uchar *)out,outl,param_2,__n);
          iVar4 = *outl;
          if (0x5de < iVar4) {
            OpenSSLDie("bio_b64.c",0x1bf,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar4 = *outl;
          }
          if (outl[1] != iVar4 && iVar4 <= outl[1]) {
            OpenSSLDie("bio_b64.c",0x1c0,"ctx->buf_len >= ctx->buf_off");
            iVar4 = *outl;
          }
          local_24 = local_24 + __n;
        }
        else {
          iVar4 = outl[2];
          if (iVar4 < 1) {
            if ((int)__n < 3) {
              if (__n != 0) {
                uVar2 = 0;
                do {
                  *(uchar *)((int)outl + uVar2 + 0x65a) = param_2[uVar2];
                  uVar2 = uVar2 + 1;
                } while (uVar2 < __n);
              }
              outl[2] = __n;
              return local_24 + __n;
            }
            __n = ((int)__n / 3) * 3;
            iVar4 = EVP_EncodeBlock((uchar *)out,param_2,__n);
            *outl = iVar4;
            if (0x5de < iVar4) {
              OpenSSLDie("bio_b64.c",0x1b7,"ctx->buf_len <= (int)sizeof(ctx->buf)");
              iVar4 = *outl;
            }
            if (outl[1] != iVar4 && iVar4 <= outl[1]) {
              OpenSSLDie("bio_b64.c",0x1b8,"ctx->buf_len >= ctx->buf_off");
              iVar4 = *outl;
            }
            local_24 = local_24 + __n;
          }
          else {
            if (3 < iVar4) {
              OpenSSLDie("bio_b64.c",0x196,"ctx->tmp_len <= 3");
              iVar4 = outl[2];
            }
            __n = 3U - iVar4;
            if ((int)param_3 < (int)(3U - iVar4)) {
              __n = param_3;
            }
            memcpy((void *)((int)outl + iVar4 + 0x65a),param_2,__n);
            local_24 = local_24 + __n;
            iVar4 = outl[2] + __n;
            outl[2] = iVar4;
            if (iVar4 < 3) {
              return local_24;
            }
            iVar4 = EVP_EncodeBlock((uchar *)out,(uchar *)((int)outl + 0x65a),iVar4);
            *outl = iVar4;
            if (0x5de < iVar4) {
              OpenSSLDie("bio_b64.c",0x1a5,"ctx->buf_len <= (int)sizeof(ctx->buf)");
              iVar4 = *outl;
            }
            if (outl[1] != iVar4 && iVar4 <= outl[1]) {
              OpenSSLDie("bio_b64.c",0x1a6,"ctx->buf_len >= ctx->buf_off");
              iVar4 = *outl;
            }
            outl[2] = 0;
          }
        }
        param_2 = param_2 + __n;
        outl[1] = 0;
        data = out;
        if (0 < iVar4) {
          do {
            iVar3 = BIO_write(param_1->next_bio,data,iVar4);
            if (iVar3 < 1) {
              BIO_copy_next_retry(param_1);
              if (local_24 != 0) {
                iVar3 = local_24;
              }
              return iVar3;
            }
            if (iVar4 < iVar3) {
              OpenSSLDie("bio_b64.c",0x1ce,"i <= n");
              iVar4 = iVar4 - iVar3;
              iVar3 = iVar3 + outl[1];
              outl[1] = iVar3;
              if (iVar3 < 0x5df) goto LAB_0812fb2f;
LAB_0812fb8e:
              OpenSSLDie("bio_b64.c",0x1d1,"ctx->buf_off <= (int)sizeof(ctx->buf)");
              if (*outl < outl[1]) goto LAB_0812fbb0;
            }
            else {
              iVar4 = iVar4 - iVar3;
              iVar3 = iVar3 + outl[1];
              outl[1] = iVar3;
              if (0x5de < iVar3) goto LAB_0812fb8e;
LAB_0812fb2f:
              if (*outl < iVar3) {
LAB_0812fbb0:
                OpenSSLDie("bio_b64.c",0x1d2,"ctx->buf_len >= ctx->buf_off");
              }
            }
            if (iVar4 < 1) break;
            data = (int *)((int)outl + outl[1] + 0x7c);
          } while( true );
        }
        param_3 = param_3 - __n;
        *outl = 0;
        outl[1] = 0;
      } while (0 < (int)param_3);
    }
    return local_24;
  }
  do {
    iVar3 = BIO_write(param_1->next_bio,(void *)((int)outl + iVar3 + 0x7c),iVar4);
    if (iVar3 < 1) {
      BIO_copy_next_retry(param_1);
      return iVar3;
    }
    if (iVar4 < iVar3) {
      OpenSSLDie("bio_b64.c",0x184,"i <= n");
      iVar1 = outl[1] + iVar3;
      outl[1] = iVar1;
      if (iVar1 < 0x5df) goto LAB_0812f96f;
LAB_0812f9cc:
      OpenSSLDie("bio_b64.c",0x186,"ctx->buf_off <= (int)sizeof(ctx->buf)");
      if (*outl < outl[1]) goto LAB_0812f9ee;
    }
    else {
      iVar1 = outl[1] + iVar3;
      outl[1] = iVar1;
      if (0x5de < iVar1) goto LAB_0812f9cc;
LAB_0812f96f:
      if (*outl < iVar1) {
LAB_0812f9ee:
        OpenSSLDie("bio_b64.c",0x187,"ctx->buf_len >= ctx->buf_off");
      }
    }
    iVar4 = iVar4 - iVar3;
    if (iVar4 < 1) goto LAB_0812fa12;
    iVar3 = outl[1];
  } while( true );
}
