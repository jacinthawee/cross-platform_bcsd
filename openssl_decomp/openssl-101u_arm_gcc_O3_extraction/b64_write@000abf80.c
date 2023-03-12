
/* WARNING: Type propagation algorithm not settling */

uchar * b64_write(BIO *param_1,uchar *param_2,uchar *param_3)

{
  bool bVar1;
  int *piVar2;
  uchar *puVar3;
  uchar *puVar4;
  int iVar5;
  uchar *puVar6;
  int *outl;
  int iVar7;
  uchar *unaff_r10;
  bool bVar8;
  bool bVar9;
  uchar *local_30;
  
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
  iVar7 = *outl;
  if (0x5de < iVar7) {
    OpenSSLDie("bio_b64.c",0x17b,"ctx->buf_len <= (int)sizeof(ctx->buf)");
    iVar7 = *outl;
  }
  iVar5 = outl[1];
  if (iVar7 < iVar5) {
    OpenSSLDie("bio_b64.c",0x17c,"ctx->buf_len >= ctx->buf_off");
    iVar7 = *outl;
    iVar5 = outl[1];
  }
  if (iVar7 - iVar5 < 1) {
LAB_000ac06a:
    local_30 = (uchar *)0x0;
    bVar9 = param_2 == (uchar *)0x0;
    puVar3 = param_2;
    if (!bVar9) {
      puVar3 = param_3;
    }
    bVar8 = (int)puVar3 < 0;
    bVar1 = param_3 == (uchar *)0x0;
    outl[1] = 0;
    *outl = 0;
    if ((bVar9 || bVar1) || bVar8) {
      unaff_r10 = (uchar *)0x1;
    }
    if ((!bVar9 && !bVar1) && !bVar8) {
      unaff_r10 = (uchar *)0x0;
    }
    puVar3 = unaff_r10;
    if ((!bVar9 && !bVar1) && !bVar8) {
      do {
        local_30 = puVar3;
        puVar3 = (uchar *)0x400;
        if ((int)param_3 < 0x401) {
          puVar3 = param_3;
        }
        iVar7 = BIO_test_flags(param_1,-1);
        if (iVar7 << 0x17 < 0) {
          iVar7 = outl[2];
          if (iVar7 < 1) {
            if ((int)puVar3 < 3) {
              memcpy((void *)((int)outl + 0x65a),param_2,(size_t)puVar3);
              outl[2] = (int)puVar3;
              return local_30 + (int)puVar3;
            }
            puVar3 = (uchar *)(((int)puVar3 / 3) * 3);
            iVar7 = EVP_EncodeBlock((uchar *)(outl + 0x1f),param_2,(int)puVar3);
            *outl = iVar7;
            if (0x5de < iVar7) {
              OpenSSLDie("bio_b64.c",0x1b7,"ctx->buf_len <= (int)sizeof(ctx->buf)");
              iVar7 = *outl;
            }
            if (iVar7 < outl[1]) {
              OpenSSLDie("bio_b64.c",0x1b8,"ctx->buf_len >= ctx->buf_off");
              iVar7 = *outl;
            }
            local_30 = local_30 + (int)puVar3;
          }
          else {
            if (3 < iVar7) {
              OpenSSLDie("bio_b64.c",0x196,"ctx->tmp_len <= 3");
              iVar7 = outl[2];
            }
            puVar3 = (uchar *)(3U - iVar7);
            if ((int)param_3 <= (int)(uchar *)(3U - iVar7)) {
              puVar3 = param_3;
            }
            local_30 = local_30 + (int)puVar3;
            memcpy((void *)((int)outl + iVar7 + 0x65a),param_2,(size_t)puVar3);
            puVar6 = puVar3 + outl[2];
            outl[2] = (int)puVar6;
            if ((int)puVar6 < 3) {
              return local_30;
            }
            iVar7 = EVP_EncodeBlock((uchar *)(outl + 0x1f),(uchar *)((int)outl + 0x65a),(int)puVar6)
            ;
            *outl = iVar7;
            if (0x5de < iVar7) {
              OpenSSLDie("bio_b64.c",0x1a5,"ctx->buf_len <= (int)sizeof(ctx->buf)");
              iVar7 = *outl;
            }
            if (iVar7 < outl[1]) {
              OpenSSLDie("bio_b64.c",0x1a6,"ctx->buf_len >= ctx->buf_off");
              iVar7 = *outl;
            }
            outl[2] = 0;
          }
        }
        else {
          EVP_EncodeUpdate((EVP_ENCODE_CTX *)(outl + 7),(uchar *)(outl + 0x1f),outl,param_2,
                           (int)puVar3);
          iVar7 = *outl;
          if (0x5de < iVar7) {
            OpenSSLDie("bio_b64.c",0x1bf,"ctx->buf_len <= (int)sizeof(ctx->buf)");
            iVar7 = *outl;
          }
          if (iVar7 < outl[1]) {
            OpenSSLDie("bio_b64.c",0x1c0,"ctx->buf_len >= ctx->buf_off");
            iVar7 = *outl;
          }
          local_30 = local_30 + (int)puVar3;
        }
        param_2 = param_2 + (int)puVar3;
        outl[1] = 0;
        piVar2 = outl;
        if (0 < iVar7) {
          do {
            puVar6 = (uchar *)BIO_write(param_1->next_bio,piVar2 + 0x1f,iVar7);
            if ((int)puVar6 < 1) {
              BIO_copy_next_retry(param_1);
              if (local_30 == (uchar *)0x0) {
                local_30 = puVar6;
              }
              return local_30;
            }
            if (iVar7 < (int)puVar6) {
              OpenSSLDie("bio_b64.c",0x1ce,"i <= n");
              puVar4 = puVar6 + outl[1];
              outl[1] = (int)puVar4;
              if (0x5de < (int)puVar4) goto LAB_000ac172;
LAB_000ac128:
              if (*outl < (int)puVar4) goto LAB_000ac192;
            }
            else {
              puVar4 = puVar6 + outl[1];
              outl[1] = (int)puVar4;
              if ((int)puVar4 < 0x5df) goto LAB_000ac128;
LAB_000ac172:
              OpenSSLDie("bio_b64.c",0x1d1,"ctx->buf_off <= (int)sizeof(ctx->buf)");
              if (*outl < outl[1]) {
LAB_000ac192:
                OpenSSLDie("bio_b64.c",0x1d2,"ctx->buf_len >= ctx->buf_off");
              }
            }
            if (iVar7 - (int)puVar6 < 1) break;
            iVar7 = iVar7 - (int)puVar6;
            piVar2 = (int *)(outl[1] + (int)outl);
          } while( true );
        }
        param_3 = param_3 + -(int)puVar3;
        *outl = 0;
        outl[1] = 0;
        puVar3 = local_30;
      } while (0 < (int)param_3);
    }
    return local_30;
  }
  unaff_r10 = (uchar *)0x5de;
  iVar7 = iVar7 - iVar5;
  do {
    puVar3 = (uchar *)BIO_write(param_1->next_bio,(void *)((int)outl + iVar5 + 0x7c),iVar7);
    if ((int)puVar3 < 1) {
      BIO_copy_next_retry(param_1);
      return puVar3;
    }
    if (iVar7 < (int)puVar3) {
      OpenSSLDie("bio_b64.c",0x184,"i <= n");
      puVar6 = puVar3 + outl[1];
      outl[1] = (int)puVar6;
      if (0x5de < (int)puVar6) goto LAB_000ac02e;
LAB_000abfe6:
      if (*outl < (int)puVar6) goto LAB_000ac04e;
    }
    else {
      puVar6 = puVar3 + outl[1];
      outl[1] = (int)puVar6;
      if ((int)puVar6 < 0x5df) goto LAB_000abfe6;
LAB_000ac02e:
      OpenSSLDie("bio_b64.c",0x186,"ctx->buf_off <= (int)sizeof(ctx->buf)");
      if (*outl < outl[1]) {
LAB_000ac04e:
        OpenSSLDie("bio_b64.c",0x187,"ctx->buf_len >= ctx->buf_off");
      }
    }
    if (iVar7 - (int)puVar3 < 1) goto LAB_000ac06a;
    iVar5 = outl[1];
    iVar7 = iVar7 - (int)puVar3;
  } while( true );
}

