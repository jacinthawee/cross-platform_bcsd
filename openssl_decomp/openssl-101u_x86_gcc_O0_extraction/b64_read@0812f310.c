
size_t b64_read(BIO *param_1,void *param_2,size_t param_3)

{
  EVP_ENCODE_CTX *ctx;
  size_t *outl;
  size_t sVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  size_t sVar5;
  uchar *in;
  uchar *puVar6;
  uchar *puVar7;
  int in_GS_OFFSET;
  size_t *local_4c;
  void *local_3c;
  size_t local_38;
  size_t local_30;
  int local_24;
  int local_20;
  uchar *puVar8;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = param_2;
  if (param_2 == (void *)0x0) {
LAB_0812f893:
    local_30 = 0;
    goto LAB_0812f566;
  }
  outl = (size_t *)param_1->ptr;
  local_30 = 0;
  if ((outl == (size_t *)0x0) || (param_1->next_bio == (bio_st *)0x0)) goto LAB_0812f566;
  BIO_clear_flags(param_1,0xf);
  if (outl[4] != 2) {
    outl[4] = 2;
    *outl = 0;
    outl[1] = 0;
    outl[2] = 0;
    EVP_DecodeInit((EVP_ENCODE_CTX *)(outl + 7));
  }
  sVar1 = *outl;
  if ((int)sVar1 < 1) {
    if (((int)param_3 < 1) || ((int)outl[6] < 1)) {
      BIO_copy_next_retry(param_1);
      goto LAB_0812f893;
    }
    local_38 = 0;
LAB_0812f415:
    ctx = (EVP_ENCODE_CTX *)(outl + 7);
    local_30 = 0;
LAB_0812f428:
    do {
      sVar1 = BIO_read(param_1->next_bio,(void *)((int)outl + outl[2] + 0x65a),0x400 - outl[2]);
      if ((int)sVar1 < 1) {
        iVar4 = BIO_test_flags(param_1->next_bio,8);
        local_30 = sVar1;
        if (iVar4 != 0) break;
        sVar3 = outl[2];
        outl[6] = sVar1;
        if (sVar3 == 0) break;
        sVar1 = 0;
      }
      else {
        sVar3 = outl[2];
      }
      sVar1 = sVar1 + sVar3;
      outl[2] = sVar1;
      if (outl[5] == 0) {
LAB_0812f46b:
        if (((int)sVar1 < 0x400) && (0 < (int)outl[6])) goto LAB_0812f428;
LAB_0812f48c:
        local_4c = outl + 0x1f;
        puVar6 = (uchar *)((int)outl + 0x65a);
        uVar2 = BIO_test_flags(param_1,-1);
        if ((uVar2 & 0x100) == 0) {
          sVar3 = EVP_DecodeUpdate(ctx,(uchar *)local_4c,(int *)outl,puVar6,sVar1);
          outl[2] = 0;
          outl[1] = 0;
joined_r0x0812f5a8:
          if ((int)sVar3 < 0) {
            *outl = 0;
            local_30 = 0;
            break;
          }
          sVar3 = *outl;
        }
        else {
          uVar2 = sVar1 & 0xfffffffc;
          sVar3 = EVP_DecodeBlock((uchar *)local_4c,puVar6,uVar2);
          if ((2 < (int)uVar2) && (*(char *)((int)outl + uVar2 + 0x659) == '=')) {
            sVar3 = sVar3 - 2;
            if (*(char *)((int)outl + uVar2 + 0x658) != '=') {
              sVar3 = sVar3 - 1;
            }
          }
          if (sVar1 != uVar2) {
            memmove(puVar6,(void *)((int)outl + uVar2 + 0x65a),sVar1 - uVar2);
            outl[2] = sVar1 - uVar2;
          }
          if ((int)sVar3 < 1) {
            *outl = 0;
            outl[1] = 0;
            goto joined_r0x0812f5a8;
          }
          *outl = sVar3;
        }
        if ((int)param_3 <= (int)sVar3) {
          sVar3 = param_3;
        }
        memcpy(local_3c,local_4c,sVar3);
        local_38 = local_38 + sVar3;
        outl[1] = sVar3;
        if (*outl == sVar3) {
          *outl = 0;
          outl[1] = 0;
        }
        param_3 = param_3 - sVar3;
        local_3c = (void *)((int)local_3c + sVar3);
        if ((int)param_3 < 1) break;
      }
      else {
        uVar2 = BIO_test_flags(param_1,-1);
        if ((uVar2 & 0x100) != 0) {
          outl[2] = 0;
          goto LAB_0812f48c;
        }
        if (outl[5] == 0) goto LAB_0812f46b;
        puVar6 = (uchar *)((int)outl + 0x65a);
        local_24 = 0;
        if (0 < (int)sVar1) {
          sVar3 = 0;
          puVar8 = puVar6;
          in = puVar6;
LAB_0812f63f:
          puVar7 = puVar8 + 1;
          if (*puVar8 != '\n') goto joined_r0x0812f63d;
          if (outl[3] != 0) {
            outl[3] = 0;
            in = puVar7;
            goto joined_r0x0812f63d;
          }
          iVar4 = EVP_DecodeUpdate(ctx,(uchar *)(outl + 0x1f),&local_24,in,(int)puVar7 - (int)in);
          if (((iVar4 < 1) && (local_24 == 0)) && (outl[5] != 0)) {
            EVP_DecodeInit(ctx);
            in = puVar7;
            goto joined_r0x0812f63d;
          }
          if ((puVar6 != in) && (sVar1 = sVar1 - ((int)in - (int)puVar6), 0 < (int)sVar1)) {
            sVar5 = 0;
            do {
              *(uchar *)((int)outl + sVar5 + 0x65a) = in[sVar5];
              sVar5 = sVar5 + 1;
            } while (sVar1 != sVar5);
          }
          EVP_DecodeInit(ctx);
          outl[5] = 0;
          if (sVar1 != sVar3) {
            outl[2] = 0;
            goto LAB_0812f48c;
          }
LAB_0812f663:
          if (local_24 != 0) goto LAB_0812f721;
          if (puVar6 == in) {
            if (sVar1 == 0x400) {
              outl[3] = 1;
              outl[2] = 0;
            }
          }
          else if (puVar7 != in) {
            sVar1 = (int)puVar7 - (int)in;
            if (0 < (int)sVar1) {
              sVar3 = 0;
              do {
                *(uchar *)((int)outl + sVar3 + 0x65a) = in[sVar3];
                sVar3 = sVar3 + 1;
              } while (sVar1 != sVar3);
            }
            outl[2] = sVar1;
          }
          goto LAB_0812f53f;
        }
        if (sVar1 != 0) {
LAB_0812f721:
          outl[2] = 0;
          goto LAB_0812f48c;
        }
      }
LAB_0812f53f:
    } while (0 < (int)outl[6]);
  }
  else {
    sVar3 = outl[1];
    if ((int)sVar1 < (int)sVar3) {
      OpenSSLDie("bio_b64.c",0xad,"ctx->buf_len >= ctx->buf_off");
      sVar1 = *outl;
      sVar3 = outl[1];
    }
    local_38 = sVar1 - sVar3;
    if ((int)param_3 <= (int)(sVar1 - sVar3)) {
      local_38 = param_3;
    }
    if (0x5dd < (int)(local_38 + sVar3)) {
      OpenSSLDie("bio_b64.c",0xb1,"ctx->buf_off + i < (int)sizeof(ctx->buf)");
      sVar3 = outl[1];
    }
    memcpy(param_2,(void *)((int)outl + sVar3 + 0x7c),local_38);
    sVar1 = outl[1];
    local_3c = (void *)((int)param_2 + local_38);
    param_3 = param_3 - local_38;
    outl[1] = local_38 + sVar1;
    if (local_38 + sVar1 == *outl) {
      *outl = 0;
      outl[1] = 0;
    }
    if ((0 < (int)param_3) && (0 < (int)outl[6])) goto LAB_0812f415;
    local_30 = 0;
  }
  BIO_copy_next_retry(param_1);
  if (local_38 != 0) {
    local_30 = local_38;
  }
LAB_0812f566:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_30;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
joined_r0x0812f63d:
  sVar3 = sVar3 + 1;
  puVar8 = puVar7;
  if (sVar1 == sVar3) goto LAB_0812f663;
  goto LAB_0812f63f;
}

