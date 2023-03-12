
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uchar *f;
  int iVar5;
  uint uVar6;
  uint n;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_3c;
  uchar *local_38;
  uint local_30;
  
  n = ctx->num;
  iVar7 = ctx->line_num;
  iVar8 = ctx->expect_nl;
  uVar3 = inl;
  local_30 = inl;
  if ((inl != 0) && ((n != 0 || (uVar3 = n, local_30 = n, data_ascii2bin[*in & 0x7f] != -0xe)))) {
    if (inl < 1) {
      uVar3 = 1;
      local_30 = 0;
    }
    else if (iVar7 < 0x50) {
      iVar5 = 0;
      local_30 = 0;
      uVar3 = 0;
      f = ctx->enc_data;
      local_3c = 0xffffffff;
      iVar9 = iVar8;
      local_38 = out;
      do {
        while( true ) {
          bVar1 = *in;
          uVar6 = (uint)bVar1;
          iVar5 = iVar5 + 1;
          bVar4 = data_ascii2bin[uVar6 & 0x7f];
          if ((bVar4 | 0x13) == 0xf3) break;
          if (0x4f < (int)n) {
            OpenSSLDie("encode.c",0x106,"n < (int)sizeof(ctx->enc_data)");
          }
          uVar2 = n + 1;
          iVar7 = iVar7 + 1;
          f[n] = bVar1;
          n = uVar2;
          if (uVar6 == 0x3d) goto LAB_0010d24a;
LAB_0010d21a:
          if (bVar4 != 0xf1) goto LAB_0010d21e;
LAB_0010d25c:
          iVar7 = iVar9;
          if (iVar9 == 0) goto LAB_0010d222;
LAB_0010d262:
          iVar7 = 0;
          in = in + 1;
          if (inl <= iVar5) {
LAB_0010d23a:
            uVar3 = 1;
            iVar8 = iVar9;
            goto LAB_0010d2fc;
          }
        }
        if (bVar4 == 0xff) break;
        if (uVar6 != 0x3d) goto LAB_0010d21a;
LAB_0010d24a:
        uVar3 = uVar3 + 1;
        if (local_3c == 0xffffffff) {
          local_3c = n;
        }
        if (bVar4 == 0xf1) goto LAB_0010d25c;
LAB_0010d21e:
        if ((bVar4 == 0xf0) && (iVar7 = iVar9, iVar9 != 0)) {
          iVar9 = 0;
          goto LAB_0010d262;
        }
LAB_0010d222:
        if ((inl != iVar5) || (((n & 3) != 0 && (uVar3 == 0)))) {
          if (bVar4 == 0xf2) goto LAB_0010d2c6;
LAB_0010d22c:
          if (0x3f < (int)n) {
            if (bVar4 == 0xf2) goto LAB_0010d27e;
            iVar9 = 1;
            goto LAB_0010d19a;
          }
          iVar9 = 0;
          iVar8 = 0;
          if (iVar5 < inl) goto LAB_0010d1e4;
          goto LAB_0010d23a;
        }
        uVar3 = count_leading_zeroes(f[n - 1] - 0x3d);
        uVar3 = uVar3 >> 5;
        if (f[n - 2] == '=') {
          uVar3 = uVar3 + 1;
        }
LAB_0010d2c6:
        if ((n & 3) != 0) {
          bVar4 = 0xf2;
          goto LAB_0010d22c;
        }
LAB_0010d27e:
        if ((int)n < 1) {
          iVar9 = 0;
          iVar8 = 0;
          uVar3 = 0;
          if (0 < ctx->length) goto LAB_0010d2fc;
          uVar3 = 1;
        }
        else {
          iVar9 = 0;
LAB_0010d19a:
          iVar8 = EVP_DecodeBlock(local_38,f,n);
          if (iVar8 < 0) {
LAB_0010d31a:
            n = 0;
            uVar3 = 0;
            iVar8 = iVar9;
            goto LAB_0010d2fc;
          }
          local_30 = local_30 + (iVar8 - uVar3);
          if (iVar8 < ctx->length) {
            n = uVar3;
            if (uVar3 != 0) goto LAB_0010d31a;
          }
          else {
            n = 0;
          }
        }
        ctx->length = iVar8;
        if (-1 < (int)local_3c) {
          uVar3 = 0;
          iVar8 = iVar9;
          goto LAB_0010d2fc;
        }
        local_38 = local_38 + iVar8;
        iVar8 = iVar9;
        if (inl <= iVar5) goto LAB_0010d23a;
LAB_0010d1e4:
        in = in + 1;
        iVar9 = iVar8;
      } while (iVar7 != 0x50);
      uVar3 = 0xffffffff;
      iVar8 = iVar9;
    }
    else {
      uVar3 = 0xffffffff;
      local_30 = 0;
    }
  }
LAB_0010d2fc:
  *outl = local_30;
  ctx->num = n;
  ctx->line_num = iVar7;
  ctx->expect_nl = iVar8;
  return uVar3;
}

