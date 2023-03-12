
int EVP_DecryptFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  byte bVar1;
  EVP_CIPHER *pEVar2;
  uint uVar3;
  uchar *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  pEVar2 = ctx->cipher;
  *outl = 0;
  if ((*(byte *)((int)&pEVar2->flags + 2) & 0x10) == 0) {
    if ((*(byte *)((int)&ctx->flags + 1) & 1) == 0) {
      uVar6 = pEVar2->block_size;
      if (uVar6 < 2) {
        iVar9 = 1;
      }
      else {
        iVar9 = ctx->buf_len;
        if ((iVar9 != 0) || (ctx->final_used == 0)) {
          iVar7 = 0x214;
          iVar9 = 0x6d;
          goto LAB_0812b44f;
        }
        if (0x20 < uVar6) {
          OpenSSLDie("evp_enc.c",0x217,"b <= sizeof ctx->final");
        }
        uVar8 = (uint)ctx->final[uVar6 - 1];
        if ((uVar8 == 0) || (puVar4 = ctx->final + (uVar6 - 2), (int)uVar6 < (int)uVar8)) {
          iVar7 = 0x21b;
        }
        else {
          iVar7 = 0;
          do {
            iVar7 = iVar7 + 1;
            if ((int)uVar8 <= iVar7) {
              uVar8 = ctx->cipher->block_size - uVar8;
              if (0 < (int)uVar8) {
                if ((outm < ctx->final + 4 && ctx->final < outm + 4 || ((uint)outm & 3) != 0) ||
                   (uVar8 < 9)) {
                  uVar6 = 0;
                  do {
                    outm[uVar6] = ctx->final[uVar6];
                    uVar6 = uVar6 + 1;
                  } while (uVar8 != uVar6);
                }
                else {
                  uVar3 = 0;
                  uVar5 = (uVar8 - 4 >> 2) + 1;
                  uVar6 = uVar8 - 4 & 0xfffffffc;
                  do {
                    *(undefined4 *)(outm + uVar3 * 4) = *(undefined4 *)(ctx->final + uVar3 * 4);
                    uVar3 = uVar3 + 1;
                  } while (uVar3 < uVar5);
                  if ((uVar8 != uVar6 + 4) &&
                     (outm[uVar5 * 4] = ctx->final[uVar6 + 4], (int)(uVar6 + 5) < (int)uVar8)) {
                    outm[uVar6 + 5] = ctx->final[uVar6 + 5];
                    if ((int)(uVar6 + 6) < (int)uVar8) {
                      outm[uVar6 + 6] = ctx->final[uVar6 + 6];
                    }
                  }
                }
              }
              goto LAB_0812b42f;
            }
            bVar1 = *puVar4;
            puVar4 = puVar4 + -1;
          } while (uVar8 == bVar1);
          iVar7 = 0x222;
        }
        ERR_put_error(6,0x65,100,"evp_enc.c",iVar7);
      }
    }
    else {
      iVar9 = 1;
      if (ctx->buf_len != 0) {
        iVar7 = 0x20a;
        iVar9 = 0x8a;
LAB_0812b44f:
        ERR_put_error(6,0x65,iVar9,"evp_enc.c",iVar7);
        return 0;
      }
    }
  }
  else {
    uVar8 = (*pEVar2->do_cipher)(ctx,outm,(uchar *)0x0,0);
    iVar9 = 0;
    if (-1 < (int)uVar8) {
LAB_0812b42f:
      *outl = uVar8;
      return 1;
    }
  }
  return iVar9;
}

