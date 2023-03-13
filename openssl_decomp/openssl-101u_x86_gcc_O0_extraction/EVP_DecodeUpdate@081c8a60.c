
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  bool bVar1;
  uchar *f;
  int iVar2;
  byte bVar3;
  uint n;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte *local_20;
  int local_14;
  
  iVar6 = 0;
  n = ctx->num;
  f = ctx->enc_data;
  if (((0 < (int)n) && (ctx->enc_data[n - 1] == '=')) && (iVar6 = 1, n != 1)) {
    iVar6 = (ctx->enc_data[n - 2] == '=') + 1;
  }
  if (inl == 0) {
    local_14 = 0;
    uVar5 = 0;
  }
  else if (inl < 1) {
    local_14 = 0;
LAB_081c8bd0:
    if ((0 < (int)n) && ((n & 3) == 0)) {
      bVar1 = false;
LAB_081c8c58:
      iVar2 = EVP_DecodeBlock(out,f,n);
      if ((iVar2 < 0) || (iVar2 < iVar6)) {
LAB_081c8c8d:
        n = 0;
        uVar5 = 0xffffffff;
        goto LAB_081c8b55;
      }
      n = 0;
      local_14 = local_14 + (iVar2 - iVar6);
      if (bVar1) {
        uVar5 = 0;
        goto LAB_081c8b55;
      }
    }
    uVar5 = (uint)(iVar6 == 0 || n != 0);
  }
  else {
    bVar3 = *in;
    if (-1 < (char)bVar3) {
      uVar5 = (uint)bVar3;
      bVar4 = data_ascii2bin[uVar5];
      if (bVar4 != 0xff) {
        local_14 = 0;
        local_20 = in + 1;
        do {
          if (uVar5 == 0x3d) {
            iVar6 = iVar6 + 1;
            if (iVar6 == 3) break;
          }
          else if ((iVar6 != 0) && ((bVar4 | 0x13) != 0xf3)) break;
          if (bVar4 == 0xf2) {
            if ((int)n < 1) {
              uVar5 = 0;
              goto LAB_081c8b55;
            }
            bVar1 = true;
            if ((n & 3) == 0) goto LAB_081c8c58;
            break;
          }
          if ((bVar4 | 0x13) != 0xf3) {
            if (0x3f < (int)n) break;
            f[n] = bVar3;
            n = n + 1;
          }
          if (n == 0x40) {
            iVar2 = EVP_DecodeBlock(out,f,0x40);
            if ((iVar2 < 0) || (iVar2 < iVar6)) goto LAB_081c8c8d;
            n = 0;
            local_14 = local_14 + (iVar2 - iVar6);
            out = out + (iVar2 - iVar6);
          }
          if (in + inl == local_20) goto LAB_081c8bd0;
          bVar3 = *local_20;
          if ((char)bVar3 < '\0') break;
          uVar5 = (uint)bVar3;
          bVar4 = data_ascii2bin[uVar5];
          local_20 = local_20 + 1;
        } while (bVar4 != 0xff);
        uVar5 = 0xffffffff;
        goto LAB_081c8b55;
      }
    }
    local_14 = 0;
    uVar5 = 0xffffffff;
  }
LAB_081c8b55:
  *outl = local_14;
  ctx->num = n;
  return uVar5;
}

