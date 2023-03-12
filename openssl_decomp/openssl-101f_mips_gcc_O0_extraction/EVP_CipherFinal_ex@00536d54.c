
int EVP_CipherFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  byte bVar1;
  uchar uVar2;
  uchar *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  EVP_CIPHER *pEVar8;
  int reason;
  undefined4 uVar9;
  uint uVar10;
  _func_1090 *p_Var11;
  
  if (ctx->encrypt == 0) {
    pEVar8 = ctx->cipher;
    *outl = 0;
    if (-1 < (int)(pEVar8->flags << 0xb)) {
      if ((ctx->flags & 0x100) == 0) {
        uVar10 = pEVar8->block_size;
        if (uVar10 < 2) {
          return 1;
        }
        if ((ctx->buf_len == 0) && (ctx->final_used != 0)) {
          if (0x20 < uVar10) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x217,"b <= sizeof ctx->final");
          }
          uVar6 = (uint)ctx->final[uVar10 - 1];
          if ((uVar6 == 0) || ((int)uVar10 < (int)uVar6)) {
            iVar4 = 0x21b;
          }
          else {
            puVar3 = ctx->final + (uVar10 - 2);
            do {
              if (puVar3 == (byte *)((int)ctx + ((uVar10 + 0x6b) - uVar6))) {
                uVar6 = ctx->cipher->block_size - uVar6;
                if (0 < (int)uVar6) {
                  puVar3 = ctx->final;
                  if ((outm < ctx->final + 4 && puVar3 < outm + 4) ||
                     (((uint)outm & 3) != 0 || uVar6 < 9)) {
                    do {
                      uVar2 = *puVar3;
                      puVar3 = puVar3 + 1;
                      *outm = uVar2;
                      outm = outm + 1;
                    } while (puVar3 != (undefined *)((int)ctx + uVar6 + 0x6c));
                    *outl = uVar6;
                    return 1;
                  }
                  uVar7 = 0;
                  uVar10 = uVar6 - 4 & 0xfffffffc;
                  puVar5 = (undefined4 *)outm;
                  do {
                    uVar9 = *(undefined4 *)puVar3;
                    uVar7 = uVar7 + 1;
                    puVar3 = puVar3 + 4;
                    *puVar5 = uVar9;
                    puVar5 = puVar5 + 1;
                  } while (uVar7 < (uVar6 - 4 >> 2) + 1);
                  if (uVar6 != uVar10 + 4) {
                    outm[uVar10 + 4] = ctx->final[uVar10 + 4];
                    if ((int)(uVar10 + 5) < (int)uVar6) {
                      outm[uVar10 + 5] = ctx->final[uVar10 + 5];
                      if ((int)(uVar10 + 6) < (int)uVar6) {
                        outm[uVar10 + 6] = ctx->final[uVar10 + 6];
                      }
                    }
                  }
                }
                *outl = uVar6;
                return 1;
              }
              bVar1 = *puVar3;
              puVar3 = puVar3 + -1;
            } while (uVar6 == bVar1);
            iVar4 = 0x222;
          }
          ERR_put_error(6,0x65,100,"evp_enc.c",iVar4);
          return 0;
        }
        reason = 0x6d;
        iVar4 = 0x214;
      }
      else {
        if (ctx->buf_len == 0) {
          return 1;
        }
        reason = 0x8a;
        iVar4 = 0x20a;
      }
      ERR_put_error(6,0x65,reason,"evp_enc.c",iVar4);
      return 0;
    }
    p_Var11 = pEVar8->do_cipher;
LAB_00536ed0:
    iVar4 = (*p_Var11)(ctx,outm,(uchar *)0x0,0);
    if (iVar4 < 0) {
      return 0;
    }
    *outl = iVar4;
    return 1;
  }
  pEVar8 = ctx->cipher;
  if ((int)(pEVar8->flags << 0xb) < 0) {
    p_Var11 = pEVar8->do_cipher;
    goto LAB_00536ed0;
  }
  uVar10 = pEVar8->block_size;
  if (uVar10 < 0x21) {
    if (uVar10 == 1) goto LAB_00536e28;
  }
  else {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_enc.c",0x193,"b <= sizeof ctx->buf");
  }
  uVar6 = ctx->buf_len;
  if ((ctx->flags & 0x100) == 0) {
    if (uVar6 < uVar10) {
      (*(code *)PTR_memset_006aab00)(ctx->buf + uVar6,uVar10 - uVar6 & 0xff);
    }
    iVar4 = (*ctx->cipher->do_cipher)(ctx,outm,ctx->buf,uVar10);
    if (iVar4 == 0) {
      return 0;
    }
    *outl = uVar10;
    return iVar4;
  }
  if (uVar6 != 0) {
    ERR_put_error(6,0x7f,0x8a,"evp_enc.c",0x19e);
    return 0;
  }
LAB_00536e28:
  *outl = 0;
  return 1;
}

