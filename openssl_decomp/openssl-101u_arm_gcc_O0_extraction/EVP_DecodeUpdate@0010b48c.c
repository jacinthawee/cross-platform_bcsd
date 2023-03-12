
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  uchar *f;
  
  f = ctx->enc_data;
  uVar4 = ctx->num;
  if (((int)uVar4 < 1) || (f[uVar4 - 1] != '=')) {
    uVar9 = 0;
  }
  else {
    uVar9 = uVar4;
    if (uVar4 != 1) {
      if (f[uVar4 - 2] == '=') {
        uVar9 = 2;
      }
      else {
        uVar9 = 1;
      }
    }
  }
  iVar3 = inl;
  if (inl == 0) goto LAB_0010b536;
  if (inl < 1) {
    iVar3 = 0;
    uVar2 = uVar4;
    iVar8 = iVar3;
LAB_0010b5a4:
    if ((int)uVar2 < 1) {
LAB_0010b5f4:
      if (iVar8 != 0) {
        *outl = iVar3;
        ctx->num = uVar2;
        return 0;
      }
LAB_0010b5b2:
      uVar4 = count_leading_zeroes(uVar9);
      *outl = iVar3;
      ctx->num = uVar2;
      uVar4 = uVar4 >> 5;
      if (uVar2 != 0) {
        uVar4 = uVar4 | 1;
      }
      return uVar4;
    }
    uVar4 = uVar2 & 3;
    if (uVar4 == 0) {
      uVar5 = EVP_DecodeBlock(out,f,uVar2);
      uVar2 = uVar5 >> 0x1f;
      if ((int)uVar5 < (int)uVar9) {
        uVar2 = 1;
      }
      if (uVar2 == 0) {
        iVar3 = iVar3 + (uVar5 - uVar9);
        goto LAB_0010b5f4;
      }
    }
    else {
      uVar4 = uVar2;
      if (iVar8 == 0) goto LAB_0010b5b2;
    }
  }
  else {
    uVar2 = (uint)*in;
    if (((int)(uVar2 << 0x18) < 0) || (bVar1 = data_ascii2bin[uVar2], bVar1 == 0xff)) {
      *outl = 0;
      ctx->num = uVar4;
      return -1;
    }
    pbVar6 = in + 1;
    iVar3 = 0;
    if (uVar2 == 0x3d) goto LAB_0010b52c;
    while ((pbVar7 = pbVar6, uVar9 == 0 || ((bVar1 | 0x13) == 0xf3))) {
      while( true ) {
        if (bVar1 == 0xf2) {
          uVar2 = uVar4;
          iVar8 = 1;
          goto LAB_0010b5a4;
        }
        uVar5 = uVar4;
        if ((bVar1 | 0x13) != 0xf3) {
          if (0x3f < (int)uVar4) goto LAB_0010b532;
          uVar5 = uVar4 + 1;
          f[uVar4] = (uchar)uVar2;
        }
        uVar4 = uVar5;
        if (uVar5 == 0x40) {
          uVar2 = EVP_DecodeBlock(out,f,0x40);
          uVar4 = uVar2 >> 0x1f;
          if ((int)uVar2 < (int)uVar9) {
            uVar4 = 1;
          }
          if (uVar4 != 0) {
            uVar4 = 0;
            inl = -1;
            goto LAB_0010b536;
          }
          iVar3 = iVar3 + (uVar2 - uVar9);
          out = out + (uVar2 - uVar9);
        }
        if (pbVar7 == in + inl) {
          uVar2 = uVar4;
          iVar8 = 0;
          goto LAB_0010b5a4;
        }
        pbVar6 = pbVar7 + 1;
        uVar2 = (uint)*pbVar7;
        if (((int)(uVar2 << 0x18) < 0) || (bVar1 = data_ascii2bin[uVar2], bVar1 == 0xff))
        goto LAB_0010b532;
        if (uVar2 != 0x3d) break;
LAB_0010b52c:
        uVar9 = uVar9 + 1;
        pbVar7 = pbVar6;
        if (uVar9 == 3) goto LAB_0010b532;
      }
    }
  }
LAB_0010b532:
  inl = -1;
LAB_0010b536:
  *outl = iVar3;
  ctx->num = uVar4;
  return inl;
}

