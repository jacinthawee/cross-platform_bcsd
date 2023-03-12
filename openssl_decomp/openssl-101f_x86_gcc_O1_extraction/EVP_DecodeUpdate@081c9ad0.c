
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint n;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_38;
  uint local_30;
  int local_2c;
  int local_28;
  
  n = ctx->num;
  iVar6 = ctx->line_num;
  local_38 = ctx->expect_nl;
  if ((inl == 0) || ((n == 0 && (data_ascii2bin[*in & 0x7f] == -0xe)))) {
    local_28 = 0;
    iVar5 = 0;
  }
  else if (inl < 1) {
    local_28 = 0;
    iVar5 = 1;
  }
  else {
    if (iVar6 < 0x50) {
      iVar5 = 1;
      local_28 = 0;
      local_2c = 0;
      local_30 = 0xffffffff;
      uVar4 = n;
      do {
        bVar1 = in[iVar5 + -1];
        bVar2 = data_ascii2bin[bVar1 & 0x7f];
        if ((bVar2 | 0x13) == 0xf3) {
          n = uVar4;
          if (bVar2 == 0xff) goto LAB_081c9e10;
          if (bVar1 == 0x3d) goto LAB_081c9c53;
LAB_081c9b67:
          if (bVar2 != 0xf1) goto LAB_081c9b73;
LAB_081c9c72:
          if (local_38 != 0) goto LAB_081c9c7a;
LAB_081c9cd0:
          iVar6 = 0;
          if (iVar5 == inl) {
LAB_081c9cdc:
            iVar3 = local_2c;
            uVar4 = n & 3;
            if ((uVar4 != 0) && (local_2c = 0, iVar3 == 0)) goto LAB_081c9b89;
            local_2c = (uint)(ctx->enc_data[n - 1] == '=') + (uint)(ctx->enc_data[n - 2] == '=');
LAB_081c9d75:
            if (uVar4 == 0) {
              if (0 < (int)n) goto LAB_081c9d81;
              if (0 < ctx->length) {
                local_38 = 0;
                iVar5 = 0;
                goto LAB_081c9dba;
              }
              local_38 = 0;
              iVar3 = 0;
              local_2c = 1;
            }
            else {
              if ((int)n < 0x40) goto LAB_081c9ca0;
LAB_081c9d81:
              local_38 = 0;
LAB_081c9bb2:
              iVar3 = EVP_DecodeBlock(out,ctx->enc_data,n);
              if ((iVar3 < 0) ||
                 ((local_28 = local_28 + (iVar3 - local_2c), iVar3 < ctx->length && (local_2c != 0))
                 )) {
                n = 0;
                iVar5 = 0;
                goto LAB_081c9dba;
              }
              n = 0;
            }
            ctx->length = iVar3;
            if (-1 < (int)local_30) {
              iVar5 = 0;
              goto LAB_081c9dba;
            }
            out = out + iVar3;
          }
          else {
LAB_081c9b95:
            if (0x3f < (int)n) {
              local_38 = 1;
              if (bVar2 == 0xf2) goto LAB_081c9d81;
              goto LAB_081c9bb2;
            }
LAB_081c9ca0:
            local_38 = 0;
          }
          if (inl <= iVar5) {
            iVar5 = 1;
            goto LAB_081c9dba;
          }
          if (iVar6 == 0x50) goto LAB_081c9e10;
        }
        else {
          if (0x4f < (int)uVar4) {
            OpenSSLDie("encode.c",0x106,"n < (int)sizeof(ctx->enc_data)");
          }
          iVar6 = iVar6 + 1;
          n = uVar4 + 1;
          ctx->enc_data[uVar4] = bVar1;
          if (bVar1 != 0x3d) goto LAB_081c9b67;
LAB_081c9c53:
          if (local_30 == 0xffffffff) {
            local_30 = n;
          }
          local_2c = local_2c + 1;
          if (bVar2 == 0xf1) goto LAB_081c9c72;
LAB_081c9b73:
          if (bVar2 != 0xf0) {
            if (inl == iVar5) goto LAB_081c9cdc;
LAB_081c9b89:
            if (bVar2 != 0xf2) goto LAB_081c9b95;
            uVar4 = n & 3;
            goto LAB_081c9d75;
          }
          if (local_38 == 0) goto LAB_081c9cd0;
          local_38 = 0;
LAB_081c9c7a:
          if (inl <= iVar5) {
            iVar6 = 0;
            iVar5 = 1;
            goto LAB_081c9dba;
          }
          iVar6 = 0;
        }
        iVar5 = iVar5 + 1;
        uVar4 = n;
      } while( true );
    }
    local_28 = 0;
    iVar5 = -1;
  }
LAB_081c9dba:
  *outl = local_28;
  ctx->num = n;
  ctx->line_num = iVar6;
  ctx->expect_nl = local_38;
  return iVar5;
LAB_081c9e10:
  iVar5 = -1;
  goto LAB_081c9dba;
}

