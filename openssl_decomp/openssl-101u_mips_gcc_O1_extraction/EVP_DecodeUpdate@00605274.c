
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  byte *pbVar2;
  uchar *puVar3;
  int iVar4;
  uint n;
  uint uVar5;
  uchar *f;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  n = ctx->num;
  f = ctx->enc_data;
  if (((int)n < 1) || (f[n - 1] != '=')) {
    iVar8 = 0;
LAB_006052d4:
    iVar9 = 0;
    if (inl == 0) goto LAB_00605488;
  }
  else {
    if (n == 1) {
      iVar8 = 1;
      goto LAB_006052d4;
    }
    iVar8 = 2;
    if (f[n - 2] != '=') {
      iVar8 = 1;
    }
    if (inl == 0) {
      iVar9 = 0;
      goto LAB_00605488;
    }
  }
  iVar9 = 0;
  if (0 < inl) {
    uVar5 = (uint)*in;
    if (-1 < (char)*in) {
      bVar1 = data_ascii2bin[uVar5];
      pbVar6 = in + 1;
      if (bVar1 != 0xff) {
        iVar9 = 0;
        while( true ) {
          if (uVar5 == 0x3d) {
            iVar8 = iVar8 + 1;
            if (iVar8 == 3) goto LAB_0060539c;
          }
          else if ((iVar8 != 0) && ((bVar1 | 0x13) != 0xf3)) goto LAB_0060539c;
          if (bVar1 == 0xf2) break;
          if ((bVar1 | 0x13) != 0xf3) {
            puVar3 = f + n;
            if (0x3f < (int)n) goto LAB_0060539c;
            n = n + 1;
            *puVar3 = (uchar)uVar5;
          }
          pbVar2 = pbVar6;
          if (n == 0x40) {
            iVar7 = EVP_DecodeBlock(out,f,0x40);
            if ((iVar7 < 0) || (iVar7 < iVar8)) goto LAB_00605568;
            n = 0;
            iVar9 = iVar9 + (iVar7 - iVar8);
            out = out + (iVar7 - iVar8);
            pbVar2 = pbVar6;
          }
          if (in + inl == pbVar2) goto LAB_00605418;
          pbVar6 = pbVar2 + 1;
          uVar5 = (uint)*pbVar2;
          if (((char)*pbVar2 < '\0') || (bVar1 = data_ascii2bin[uVar5], bVar1 == 0xff))
          goto LAB_0060539c;
        }
        if ((int)n < 1) goto LAB_00605488;
        iVar7 = 1;
        if ((n & 3) == 0) goto LAB_006054e4;
LAB_0060539c:
        *outl = iVar9;
        ctx->num = n;
        return -1;
      }
    }
    *outl = 0;
    ctx->num = n;
    return -1;
  }
LAB_00605418:
  if ((int)n < 1) {
    if (n != 0) goto LAB_0060542c;
  }
  else {
    if ((n & 3) != 0) goto LAB_0060542c;
    iVar7 = 0;
LAB_006054e4:
    iVar4 = EVP_DecodeBlock(out,f,n);
    if ((iVar4 < 0) || (iVar4 < iVar8)) {
LAB_00605568:
      n = 0;
      goto LAB_0060539c;
    }
    iVar9 = iVar9 + (iVar4 - iVar8);
    if (iVar7 != 0) {
      n = 0;
      goto LAB_00605488;
    }
  }
  n = 0;
  if (iVar8 != 0) {
LAB_00605488:
    *outl = iVar9;
    ctx->num = n;
    return 0;
  }
LAB_0060542c:
  *outl = iVar9;
  ctx->num = n;
  return 1;
}

