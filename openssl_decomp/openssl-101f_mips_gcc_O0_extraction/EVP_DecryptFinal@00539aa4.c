
int EVP_DecryptFinal(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  byte bVar1;
  uchar uVar2;
  ulong uVar3;
  EVP_CIPHER *pEVar4;
  uchar *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int reason;
  undefined4 uVar10;
  uint uVar11;
  
  pEVar4 = ctx->cipher;
  uVar3 = pEVar4->flags;
  *outl = 0;
  if ((int)(uVar3 << 0xb) < 0) {
    iVar6 = (*pEVar4->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (-1 < iVar6) {
      *outl = iVar6;
      return 1;
    }
  }
  else {
    if ((ctx->flags & 0x100) == 0) {
      uVar11 = pEVar4->block_size;
      if (uVar11 < 2) {
        return 1;
      }
      if ((ctx->buf_len == 0) && (ctx->final_used != 0)) {
        if (0x20 < uVar11) {
          (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x217,"b <= sizeof ctx->final");
        }
        uVar9 = (uint)ctx->final[uVar11 - 1];
        if ((uVar9 == 0) || ((int)uVar11 < (int)uVar9)) {
          iVar6 = 0x21b;
        }
        else {
          puVar5 = ctx->final + (uVar11 - 2);
          do {
            if (puVar5 == (byte *)((int)ctx + ((uVar11 + 0x6b) - uVar9))) {
              uVar9 = ctx->cipher->block_size - uVar9;
              if (0 < (int)uVar9) {
                puVar5 = ctx->final;
                if ((puVar5 < outm + 4 && outm < ctx->final + 4) ||
                   (((uint)outm & 3) != 0 || uVar9 < 9)) {
                  do {
                    uVar2 = *puVar5;
                    puVar5 = puVar5 + 1;
                    *outm = uVar2;
                    outm = outm + 1;
                  } while (puVar5 != (undefined *)((int)ctx + uVar9 + 0x6c));
                  *outl = uVar9;
                  return 1;
                }
                uVar8 = 0;
                uVar11 = uVar9 - 4 & 0xfffffffc;
                puVar7 = (undefined4 *)outm;
                do {
                  uVar10 = *(undefined4 *)puVar5;
                  uVar8 = uVar8 + 1;
                  puVar5 = puVar5 + 4;
                  *puVar7 = uVar10;
                  puVar7 = puVar7 + 1;
                } while (uVar8 < (uVar9 - 4 >> 2) + 1);
                if (uVar9 != uVar11 + 4) {
                  outm[uVar11 + 4] = ctx->final[uVar11 + 4];
                  if ((int)(uVar11 + 5) < (int)uVar9) {
                    outm[uVar11 + 5] = ctx->final[uVar11 + 5];
                    if ((int)(uVar11 + 6) < (int)uVar9) {
                      outm[uVar11 + 6] = ctx->final[uVar11 + 6];
                    }
                  }
                }
              }
              *outl = uVar9;
              return 1;
            }
            bVar1 = *puVar5;
            puVar5 = puVar5 + -1;
          } while (uVar9 == bVar1);
          iVar6 = 0x222;
        }
        ERR_put_error(6,0x65,100,"evp_enc.c",iVar6);
        return 0;
      }
      reason = 0x6d;
      iVar6 = 0x214;
    }
    else {
      if (ctx->buf_len == 0) {
        return 1;
      }
      reason = 0x8a;
      iVar6 = 0x20a;
    }
    ERR_put_error(6,0x65,reason,"evp_enc.c",iVar6);
  }
  return 0;
}

