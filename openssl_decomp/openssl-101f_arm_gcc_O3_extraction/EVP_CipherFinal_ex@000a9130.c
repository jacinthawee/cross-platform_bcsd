
int EVP_CipherFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  int *piVar1;
  uint uVar2;
  uchar *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  EVP_CIPHER *pEVar7;
  uint uVar8;
  
  pEVar7 = ctx->cipher;
  if (ctx->encrypt == 0) {
    *outl = 0;
    if (-1 < (int)(pEVar7->flags << 0xb)) {
      uVar8 = pEVar7->block_size;
      if ((int)(ctx->flags << 0x17) < 0) {
        if (ctx->buf_len != 0) {
          ERR_put_error(6,0x65,0x8a,"evp_enc.c",0x20a);
          return 0;
        }
        return 1;
      }
      if (uVar8 < 2) {
        return 1;
      }
      if ((ctx->buf_len == 0) && (ctx->final_used != 0)) {
        if (0x20 < uVar8) {
          OpenSSLDie("evp_enc.c",0x217,"b <= sizeof ctx->final");
        }
        uVar5 = (uint)ctx->final[uVar8 - 1];
        uVar2 = count_leading_zeroes(uVar5);
        uVar2 = uVar2 >> 5;
        if ((int)uVar8 < (int)uVar5) {
          uVar2 = uVar2 | 1;
        }
        if (uVar2 == 0) {
          puVar3 = ctx->final + (uVar8 - 1);
          do {
            uVar2 = uVar2 + 1;
            if ((int)uVar5 <= (int)uVar2) {
              uVar5 = ctx->cipher->block_size - uVar5;
              if (0 < (int)uVar5) {
                uVar8 = (uint)(((uint)outm & 3) == 0);
                if (uVar5 < 9) {
                  uVar8 = 0;
                }
                uVar8 = (outm + 4 <= ctx->final || ctx->final + 4 <= outm) & uVar8;
                if (uVar8 == 0) {
                  do {
                    outm[uVar8] = ctx->final[uVar8];
                    uVar8 = uVar8 + 1;
                  } while (uVar8 != uVar5);
                }
                else {
                  piVar1 = &ctx->block_mask;
                  uVar8 = 0;
                  uVar2 = uVar5 & 0xfffffffc;
                  piVar4 = (int *)outm;
                  do {
                    piVar1 = piVar1 + 1;
                    uVar8 = uVar8 + 1;
                    *piVar4 = *piVar1;
                    piVar4 = piVar4 + 1;
                  } while (uVar8 < uVar5 >> 2);
                  if (uVar5 != uVar2) {
                    outm[uVar5 & 0xfffffffc] = ctx->final[uVar2];
                    if ((int)(uVar2 + 1) < (int)uVar5) {
                      outm[uVar2 + 1] = ctx->final[uVar2 + 1];
                      if ((int)(uVar2 + 2) < (int)uVar5) {
                        outm[uVar2 + 2] = ctx->final[uVar2 + 2];
                      }
                    }
                  }
                }
              }
              *outl = uVar5;
              return 1;
            }
            puVar3 = puVar3 + -1;
          } while (uVar5 == *puVar3);
          iVar6 = 0x222;
        }
        else {
          iVar6 = 0x21b;
        }
        ERR_put_error(6,0x65,100,"evp_enc.c",iVar6);
        return 0;
      }
      ERR_put_error(6,0x65,0x6d,"evp_enc.c",0x214);
      return 0;
    }
    iVar6 = (*pEVar7->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (iVar6 < 0) {
      return 0;
    }
LAB_000a927c:
    *outl = iVar6;
    return 1;
  }
  if ((int)(pEVar7->flags << 0xb) < 0) {
    iVar6 = (*pEVar7->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (iVar6 < 0) {
      return 0;
    }
    goto LAB_000a927c;
  }
  uVar8 = pEVar7->block_size;
  if (uVar8 < 0x21) {
    if (uVar8 == 1) goto LAB_000a9186;
  }
  else {
    OpenSSLDie("evp_enc.c",0x193,"b <= sizeof ctx->buf");
  }
  uVar2 = ctx->buf_len;
  if (-1 < (int)(ctx->flags << 0x17)) {
    if (uVar2 < uVar8) {
      memset(ctx->buf + uVar2,uVar8 - uVar2 & 0xff,uVar8 - uVar2);
    }
    iVar6 = (*ctx->cipher->do_cipher)(ctx,outm,ctx->buf,uVar8);
    if (iVar6 != 0) {
      *outl = uVar8;
    }
    return iVar6;
  }
  if (uVar2 != 0) {
    ERR_put_error(6,0x7f,0x8a,"evp_enc.c",0x19e);
    return 0;
  }
LAB_000a9186:
  *outl = 0;
  return 1;
}

