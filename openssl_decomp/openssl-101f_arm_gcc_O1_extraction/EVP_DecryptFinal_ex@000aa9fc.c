
int EVP_DecryptFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  uchar *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  EVP_CIPHER *pEVar8;
  uint uVar9;
  
  iVar7 = 0;
  pEVar8 = ctx->cipher;
  *outl = 0;
  if ((pEVar8->flags & 0x100000) == 0) {
    uVar9 = pEVar8->block_size;
    if ((int)(ctx->flags << 0x17) < 0) {
      if (ctx->buf_len != 0) {
        ERR_put_error(6,0x65,0x8a,"evp_enc.c",0x20a);
        return 0;
      }
    }
    else if (1 < uVar9) {
      if ((ctx->buf_len == 0) && (ctx->final_used != 0)) {
        if (0x20 < uVar9) {
          OpenSSLDie("evp_enc.c",0x217,"b <= sizeof ctx->final");
        }
        puVar1 = ctx->final + (uVar9 - 1);
        uVar5 = (uint)ctx->final[uVar9 - 1];
        uVar6 = count_leading_zeroes(uVar5);
        uVar6 = uVar6 >> 5;
        if ((int)uVar9 < (int)uVar5) {
          uVar6 = uVar6 | 1;
        }
        if (uVar6 == 0) {
          do {
            uVar6 = uVar6 + 1;
            if ((int)uVar5 <= (int)uVar6) {
              uVar5 = ctx->cipher->block_size - uVar5;
              if (0 < (int)uVar5) {
                uVar9 = (uint)(outm + 4 <= ctx->final || ctx->final + 4 <= outm);
                if (uVar5 < 9) {
                  uVar9 = 0;
                }
                if (((uint)outm & 3) != 0) {
                  uVar9 = 0;
                }
                if (uVar9 == 0) {
                  do {
                    outm[uVar9] = ctx->final[uVar9];
                    uVar9 = uVar9 + 1;
                  } while (uVar9 != uVar5);
                }
                else {
                  piVar2 = &ctx->block_mask;
                  uVar9 = 0;
                  uVar6 = uVar5 & 0xfffffffc;
                  piVar4 = (int *)outm;
                  do {
                    piVar2 = piVar2 + 1;
                    uVar9 = uVar9 + 1;
                    *piVar4 = *piVar2;
                    piVar4 = piVar4 + 1;
                  } while (uVar9 < uVar5 >> 2);
                  if (uVar5 != uVar6) {
                    outm[uVar5 & 0xfffffffc] = ctx->final[uVar6];
                    if ((int)(uVar6 + 1) < (int)uVar5) {
                      outm[uVar6 + 1] = ctx->final[uVar6 + 1];
                      if ((int)(uVar6 + 2) < (int)uVar5) {
                        outm[uVar6 + 2] = ctx->final[uVar6 + 2];
                      }
                    }
                  }
                }
              }
              *outl = uVar5;
              return 1;
            }
            puVar1 = puVar1 + -1;
          } while (*puVar1 == uVar5);
          iVar7 = 0x222;
        }
        else {
          iVar7 = 0x21b;
        }
        ERR_put_error(6,0x65,100,"evp_enc.c",iVar7);
        return 0;
      }
      ERR_put_error(6,0x65,0x6d,"evp_enc.c",0x214);
      return 0;
    }
    iVar7 = 1;
  }
  else {
    iVar3 = (*pEVar8->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (-1 < iVar3) {
      *outl = iVar3;
      return 1;
    }
  }
  return iVar7;
}

