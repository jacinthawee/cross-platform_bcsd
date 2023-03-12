
int CMAC_Final(CMAC_CTX *ctx,uchar *out,size_t *poutlen)

{
  uint uVar1;
  int iVar2;
  uint inl;
  CMAC_CTX *pCVar3;
  CMAC_CTX *pCVar4;
  byte *pbVar5;
  
  iVar2 = 0;
  if (*(int *)(ctx + 0x10c) != -1) {
    inl = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
    *poutlen = inl;
    if (out != (uchar *)0x0) {
      uVar1 = *(uint *)(ctx + 0x10c);
      if (inl == uVar1) {
        if (0 < (int)inl) {
          if ((out < ctx + 0xf0 && ctx + 0x8c < (CMAC_CTX *)(out + 4) || ((uint)out & 3) != 0) ||
             (inl < 6)) {
            pbVar5 = out;
            pCVar3 = ctx + 0xec;
            do {
              pCVar4 = pCVar3 + 1;
              *pbVar5 = (byte)*pCVar3 ^ (byte)pCVar3[-0x60];
              pbVar5 = pbVar5 + 1;
              pCVar3 = pCVar4;
            } while (ctx + inl + 0xec != pCVar4);
          }
          else {
            iVar2 = (inl - 4 >> 2) + 1;
            uVar1 = iVar2 * 4;
            *(uint *)out = *(uint *)(ctx + 0xec) ^ *(uint *)(ctx + 0x8c);
            if (((((iVar2 != 1) &&
                  (*(uint *)(out + 4) = *(uint *)(ctx + 0xf0) ^ *(uint *)(ctx + 0x90), iVar2 != 2))
                 && (*(uint *)(out + 8) = *(uint *)(ctx + 0xf4) ^ *(uint *)(ctx + 0x94), iVar2 != 3)
                 ) && ((*(uint *)(out + 0xc) = *(uint *)(ctx + 0xf8) ^ *(uint *)(ctx + 0x98),
                       iVar2 != 4 &&
                       (*(uint *)(out + 0x10) = *(uint *)(ctx + 0xfc) ^ *(uint *)(ctx + 0x9c),
                       iVar2 != 5)))) &&
               ((*(uint *)(out + 0x14) = *(uint *)(ctx + 0x100) ^ *(uint *)(ctx + 0xa0), iVar2 != 6
                && (*(uint *)(out + 0x18) = *(uint *)(ctx + 0x104) ^ *(uint *)(ctx + 0xa4),
                   iVar2 != 7)))) {
              *(uint *)(out + 0x1c) = *(uint *)(ctx + 0x108) ^ *(uint *)(ctx + 0xa8);
            }
            if ((inl != uVar1) &&
               (out[iVar2 * 4] = (byte)ctx[uVar1 + 0xec] ^ (byte)ctx[uVar1 + 0x8c],
               (int)(uVar1 + 1) < (int)inl)) {
              out[uVar1 + 1] = (byte)ctx[uVar1 + 0xed] ^ (byte)ctx[uVar1 + 0x8d];
              if ((int)(uVar1 + 2) < (int)inl) {
                out[uVar1 + 2] = (byte)ctx[uVar1 + 0xee] ^ (byte)ctx[uVar1 + 0x8e];
              }
            }
          }
        }
      }
      else {
        ctx[uVar1 + 0xec] = (CMAC_CTX)0x80;
        if (1 < (int)(inl - uVar1)) {
          memset(ctx + uVar1 + 0xed,0,(inl - uVar1) - 1);
        }
        if (0 < (int)inl) {
          if ((out < ctx + 0xf0 && ctx + 0xac < (CMAC_CTX *)(out + 4) || ((uint)out & 3) != 0) ||
             (inl < 6)) {
            pCVar3 = ctx + 0xec;
            pbVar5 = out;
            do {
              pCVar4 = pCVar3 + 1;
              *pbVar5 = (byte)*pCVar3 ^ (byte)pCVar3[-0x40];
              pCVar3 = pCVar4;
              pbVar5 = pbVar5 + 1;
            } while (pCVar4 != ctx + inl + 0xec);
          }
          else {
            iVar2 = (inl - 4 >> 2) + 1;
            uVar1 = iVar2 * 4;
            *(uint *)out = *(uint *)(ctx + 0xec) ^ *(uint *)(ctx + 0xac);
            if ((((iVar2 != 1) &&
                 (*(uint *)(out + 4) = *(uint *)(ctx + 0xf0) ^ *(uint *)(ctx + 0xb0), iVar2 != 2))
                && (*(uint *)(out + 8) = *(uint *)(ctx + 0xf4) ^ *(uint *)(ctx + 0xb4), iVar2 != 3))
               && (((*(uint *)(out + 0xc) = *(uint *)(ctx + 0xf8) ^ *(uint *)(ctx + 0xb8),
                    iVar2 != 4 &&
                    (*(uint *)(out + 0x10) = *(uint *)(ctx + 0xfc) ^ *(uint *)(ctx + 0xbc),
                    iVar2 != 5)) &&
                   ((*(uint *)(out + 0x14) = *(uint *)(ctx + 0x100) ^ *(uint *)(ctx + 0xc0),
                    iVar2 != 6 &&
                    (*(uint *)(out + 0x18) = *(uint *)(ctx + 0x104) ^ *(uint *)(ctx + 0xc4),
                    iVar2 != 7)))))) {
              *(uint *)(out + 0x1c) = *(uint *)(ctx + 0x108) ^ *(uint *)(ctx + 200);
            }
            if ((inl != uVar1) &&
               (out[iVar2 * 4] = (byte)ctx[uVar1 + 0xec] ^ (byte)ctx[uVar1 + 0xac],
               (int)(uVar1 + 1) < (int)inl)) {
              out[uVar1 + 1] = (byte)ctx[uVar1 + 0xed] ^ (byte)ctx[uVar1 + 0xad];
              if ((int)(uVar1 + 2) < (int)inl) {
                out[uVar1 + 2] = (byte)ctx[uVar1 + 0xee] ^ (byte)ctx[uVar1 + 0xae];
              }
            }
          }
        }
      }
      iVar2 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,out,out,inl);
      if (iVar2 == 0) {
        OPENSSL_cleanse(out,inl);
        return 0;
      }
    }
    iVar2 = 1;
  }
  return iVar2;
}

