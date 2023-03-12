
int EVP_CipherFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  byte bVar1;
  EVP_CIPHER *pEVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int line;
  uchar *local_20;
  
  if (ctx->encrypt == 0) {
    pEVar2 = ctx->cipher;
    *outl = 0;
    if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
      iVar7 = (*pEVar2->do_cipher)(ctx,outm,(uchar *)0x0,0);
      goto joined_r0x08128d39;
    }
    if ((*(byte *)((int)&ctx->flags + 1) & 1) != 0) {
      if (ctx->buf_len == 0) {
        return 1;
      }
      line = 0x20a;
      iVar7 = 0x8a;
LAB_08128d86:
      ERR_put_error(6,0x65,iVar7,"evp_enc.c",line);
      return 0;
    }
    uVar4 = pEVar2->block_size;
    if (uVar4 < 2) {
      return 1;
    }
    if ((ctx->buf_len != 0) || (ctx->final_used == 0)) {
      line = 0x214;
      iVar7 = 0x6d;
      goto LAB_08128d86;
    }
    if (0x20 < uVar4) {
      OpenSSLDie("evp_enc.c",0x217,"b <= sizeof ctx->final");
    }
    uVar5 = (uint)ctx->final[uVar4 - 1];
    if (uVar5 != 0) {
      local_20 = ctx->final + (uVar4 - 2);
      iVar7 = 0;
      if ((int)uVar5 <= (int)uVar4) {
        do {
          iVar7 = iVar7 + 1;
          if ((int)uVar5 <= iVar7) {
            uVar5 = ctx->cipher->block_size - uVar5;
            if (0 < (int)uVar5) {
              if ((ctx->final < outm + 4 && outm < ctx->final + 4) ||
                 (((uint)outm & 3) != 0 || uVar5 < 9)) {
                uVar4 = 0;
                do {
                  outm[uVar4] = ctx->final[uVar4];
                  uVar4 = uVar4 + 1;
                } while (uVar4 != uVar5);
              }
              else {
                uVar6 = (uVar5 - 4 >> 2) + 1;
                uVar4 = uVar5 - 4 & 0xfffffffc;
                uVar3 = 0;
                do {
                  *(undefined4 *)(outm + uVar3 * 4) = *(undefined4 *)(ctx->final + uVar3 * 4);
                  uVar3 = uVar3 + 1;
                } while (uVar3 < uVar6);
                if (((uVar5 != uVar4 + 4) &&
                    (outm[uVar6 * 4] = ctx->final[uVar4 + 4], (int)(uVar4 + 5) < (int)uVar5)) &&
                   (outm[uVar4 + 5] = ctx->final[uVar4 + 5], (int)(uVar4 + 6) < (int)uVar5)) {
                  outm[uVar4 + 6] = ctx->final[uVar4 + 6];
                }
              }
            }
            *outl = uVar5;
            return 1;
          }
          bVar1 = *local_20;
          local_20 = local_20 + -1;
        } while (uVar5 == bVar1);
        iVar7 = 0x222;
        goto LAB_08128da8;
      }
    }
    iVar7 = 0x21b;
LAB_08128da8:
    ERR_put_error(6,0x65,100,"evp_enc.c",iVar7);
    return 0;
  }
  pEVar2 = ctx->cipher;
  if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) != 0) {
    iVar7 = (*pEVar2->do_cipher)(ctx,outm,(uchar *)0x0,0);
joined_r0x08128d39:
    if (iVar7 < 0) {
      return 0;
    }
    *outl = iVar7;
    return 1;
  }
  uVar4 = pEVar2->block_size;
  if (uVar4 < 0x21) {
    if (uVar4 == 1) goto LAB_08128be2;
  }
  else {
    OpenSSLDie("evp_enc.c",0x193,"b <= sizeof ctx->buf");
  }
  uVar5 = ctx->buf_len;
  if ((*(byte *)((int)&ctx->flags + 1) & 1) == 0) {
    if (uVar5 < uVar4) {
      memset(ctx->buf + uVar5,uVar4 - uVar5 & 0xff,uVar4 - uVar5);
    }
    iVar7 = (*ctx->cipher->do_cipher)(ctx,outm,ctx->buf,uVar4);
    if (iVar7 == 0) {
      return 0;
    }
    *outl = uVar4;
    return iVar7;
  }
  if (uVar5 != 0) {
    ERR_put_error(6,0x7f,0x8a,"evp_enc.c",0x19e);
    return 0;
  }
LAB_08128be2:
  *outl = 0;
  return 1;
}

