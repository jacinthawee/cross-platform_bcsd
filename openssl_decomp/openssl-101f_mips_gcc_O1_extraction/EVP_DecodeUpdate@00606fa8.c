
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  uchar *f;
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint n;
  uint uVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_44;
  
  n = ctx->num;
  iVar12 = ctx->line_num;
  iVar10 = ctx->expect_nl;
  if ((inl == 0) || ((n == 0 && (data_ascii2bin[*in & 0x7f] == -0xe)))) {
    local_44 = 0;
    iVar7 = 0;
  }
  else if (inl < 1) {
    iVar7 = 1;
    local_44 = 0;
  }
  else {
    if (iVar12 < 0x50) {
      f = ctx->enc_data;
      uVar4 = (uint)*in;
      pbVar2 = in + 1;
      local_44 = 0;
      iVar7 = 1;
      uVar8 = 0;
      bVar6 = data_ascii2bin[uVar4 & 0x7f];
      uVar9 = 0xffffffff;
      uVar5 = n;
      if ((bVar6 | 0x13) == 0xf3) goto LAB_0060716c;
LAB_00607070:
      if (0x4f < (int)uVar5) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)("encode.c",0x106,"n < (int)sizeof(ctx->enc_data)");
      }
      n = uVar5 + 1;
      f[uVar5] = (uchar)uVar4;
      iVar12 = iVar12 + 1;
      if (uVar4 == 0x3d) goto LAB_00607180;
LAB_00607094:
      iVar1 = iVar10;
      iVar11 = iVar10;
      if (bVar6 == 0xf1) goto joined_r0x00607214;
LAB_006070a0:
      if (bVar6 == 0xf0) {
        iVar1 = 0;
        iVar11 = iVar10;
        goto joined_r0x00607214;
      }
      if (inl == iVar7) goto LAB_006071bc;
LAB_006070b4:
      if (bVar6 == 0xf2) {
        if ((n & 3) != 0) goto LAB_006071f4;
        goto LAB_00607264;
      }
LAB_006070c0:
      if ((int)n < 0x40) goto LAB_006071fc;
      iVar10 = 1;
LAB_006070d0:
      iVar1 = EVP_DecodeBlock(out,f,n);
      if (iVar1 < 0) {
        n = 0;
        iVar7 = 0;
      }
      else {
        n = 0;
        local_44 = local_44 + (iVar1 - uVar8);
        if ((ctx->length <= iVar1) || (uVar8 == 0)) {
LAB_00607124:
          ctx->length = iVar1;
          if ((int)uVar9 < 0) {
            out = out + iVar1;
            if (iVar7 < inl) {
              do {
                if (iVar12 == 0x50) {
LAB_006072c4:
                  iVar7 = -1;
                  goto LAB_006072cc;
                }
                while( true ) {
                  iVar7 = iVar7 + 1;
                  pbVar3 = pbVar2 + 1;
                  uVar4 = (uint)*pbVar2;
                  bVar6 = data_ascii2bin[uVar4 & 0x7f];
                  pbVar2 = pbVar3;
                  uVar5 = n;
                  if ((bVar6 | 0x13) != 0xf3) goto LAB_00607070;
LAB_0060716c:
                  if (bVar6 == 0xff) goto LAB_006072c4;
                  if (uVar4 != 0x3d) goto LAB_00607094;
LAB_00607180:
                  if (uVar9 == 0xffffffff) {
                    uVar9 = n;
                  }
                  uVar8 = uVar8 + 1;
                  iVar1 = iVar10;
                  iVar11 = iVar10;
                  if (bVar6 != 0xf1) goto LAB_006070a0;
joined_r0x00607214:
                  iVar10 = iVar1;
                  if (iVar11 == 0) break;
                  if (inl <= iVar7) {
                    iVar12 = 0;
                    iVar7 = 1;
                    goto LAB_006072cc;
                  }
                  iVar12 = 0;
                }
                iVar12 = 0;
                if (iVar7 != inl) goto LAB_006070c0;
LAB_006071bc:
                if (((n & 3) != 0) && (uVar8 == 0)) goto LAB_006070b4;
                uVar8 = (uint)(f[n - 1] == '=');
                if (f[n - 2] == '=') {
                  uVar8 = (f[n - 1] == '=') + 1;
                }
                if ((n & 3) == 0) goto LAB_00607264;
LAB_006071f4:
                if (0x3f < (int)n) goto LAB_0060726c;
LAB_006071fc:
                iVar10 = 0;
                if (inl <= iVar7) break;
              } while( true );
            }
            iVar7 = 1;
            goto LAB_006072cc;
          }
        }
        iVar7 = 0;
      }
      goto LAB_006072cc;
    }
    iVar7 = -1;
    local_44 = 0;
  }
LAB_006072cc:
  *outl = local_44;
  ctx->num = n;
  ctx->line_num = iVar12;
  ctx->expect_nl = iVar10;
  return iVar7;
LAB_00607264:
  if (0 < (int)n) goto LAB_0060726c;
  uVar8 = 1;
  if (0 < ctx->length) {
    iVar10 = 0;
    iVar7 = 0;
    goto LAB_006072cc;
  }
  iVar10 = 0;
  iVar1 = 0;
  goto LAB_00607124;
LAB_0060726c:
  iVar10 = 0;
  goto LAB_006070d0;
}

