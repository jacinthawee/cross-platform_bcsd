
int CMAC_Final(CMAC_CTX *ctx,uchar *out,size_t *poutlen)

{
  uint inl;
  uint uVar1;
  byte *pbVar2;
  CMAC_CTX *pCVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  CMAC_CTX *pCVar7;
  
  if (*(int *)(ctx + 0x10c) == -1) {
    iVar6 = 0;
  }
  else {
    inl = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
    *poutlen = inl;
    if (out != (uchar *)0x0) {
      uVar4 = *(uint *)(ctx + 0x10c);
      if (uVar4 == inl) {
        if (0 < (int)uVar4) {
          if ((ctx + 0xec < (CMAC_CTX *)(out + 4) && out < ctx + 0xf0 ||
              (uVar4 < 6 || ((uint)out & 3) != 0)) ||
              ctx + 0x8c < (CMAC_CTX *)(out + 4) && out < ctx + 0x90) {
            pbVar2 = out + -1;
            pCVar3 = ctx + 0xeb;
            do {
              pCVar7 = pCVar3 + 1;
              pbVar2 = pbVar2 + 1;
              *pbVar2 = (byte)*pCVar7 ^ (byte)pCVar3[-0x5f];
              pCVar3 = pCVar7;
            } while (pCVar7 != ctx + inl + 0xeb);
          }
          else {
            uVar1 = uVar4 >> 2;
            uVar5 = uVar4 & 0xfffffffc;
            *(uint *)out = *(uint *)(ctx + 0x8c) ^ *(uint *)(ctx + 0xec);
            if ((((1 < uVar1) &&
                 (*(uint *)(out + 4) = *(uint *)(ctx + 0x90) ^ *(uint *)(ctx + 0xf0), 2 < uVar1)) &&
                (*(uint *)(out + 8) = *(uint *)(ctx + 0x94) ^ *(uint *)(ctx + 0xf4), 3 < uVar1)) &&
               (((*(uint *)(out + 0xc) = *(uint *)(ctx + 0x98) ^ *(uint *)(ctx + 0xf8), 4 < uVar1 &&
                 (*(uint *)(out + 0x10) = *(uint *)(ctx + 0x9c) ^ *(uint *)(ctx + 0xfc), 5 < uVar1))
                && ((*(uint *)(out + 0x14) = *(uint *)(ctx + 0xa0) ^ *(uint *)(ctx + 0x100),
                    6 < uVar1 &&
                    (*(uint *)(out + 0x18) = *(uint *)(ctx + 0xa4) ^ *(uint *)(ctx + 0x104),
                    7 < uVar1)))))) {
              *(uint *)(out + 0x1c) = *(uint *)(ctx + 0xa8) ^ *(uint *)(ctx + 0x108);
            }
            if (uVar4 != uVar5) {
              out[uVar4 & 0xfffffffc] = (byte)ctx[uVar5 + 0xec] ^ (byte)ctx[uVar5 + 0x8c];
              if ((int)(uVar5 + 1) < (int)uVar4) {
                out[uVar5 + 1] = (byte)ctx[uVar5 + 0xed] ^ (byte)ctx[uVar5 + 0x8d];
                if ((int)(uVar5 + 2) < (int)uVar4) {
                  out[uVar5 + 2] = (byte)ctx[uVar5 + 0xee] ^ (byte)ctx[uVar5 + 0x8e];
                }
              }
            }
          }
        }
      }
      else {
        ctx[uVar4 + 0xec] = (CMAC_CTX)0x80;
        if (1 < (int)(inl - uVar4)) {
          memset(ctx + uVar4 + 0xed,0,(inl - uVar4) - 1);
        }
        if (0 < (int)inl) {
          if (inl < 6 ||
              (((uint)out & 3) != 0 ||
              (ctx + 0xac < (CMAC_CTX *)(out + 4) && out < ctx + 0xb0 ||
              ctx + 0xec < (CMAC_CTX *)(out + 4) && out < ctx + 0xf0))) {
            pbVar2 = out + -1;
            pCVar3 = ctx + 0xeb;
            do {
              pCVar7 = pCVar3 + 1;
              pbVar2 = pbVar2 + 1;
              *pbVar2 = (byte)pCVar3[-0x3f] ^ (byte)*pCVar7;
              pCVar3 = pCVar7;
            } while (pCVar7 != ctx + 0xeb + inl);
          }
          else {
            uVar5 = inl >> 2;
            uVar4 = inl & 0xfffffffc;
            *(uint *)out = *(uint *)(ctx + 0xac) ^ *(uint *)(ctx + 0xec);
            if ((((1 < uVar5) &&
                 (*(uint *)(out + 4) = *(uint *)(ctx + 0xb0) ^ *(uint *)(ctx + 0xf0), 2 < uVar5)) &&
                ((*(uint *)(out + 8) = *(uint *)(ctx + 0xb4) ^ *(uint *)(ctx + 0xf4), 3 < uVar5 &&
                 (((*(uint *)(out + 0xc) = *(uint *)(ctx + 0xb8) ^ *(uint *)(ctx + 0xf8), 4 < uVar5
                   && (*(uint *)(out + 0x10) = *(uint *)(ctx + 0xbc) ^ *(uint *)(ctx + 0xfc),
                      5 < uVar5)) &&
                  (*(uint *)(out + 0x14) = *(uint *)(ctx + 0xc0) ^ *(uint *)(ctx + 0x100), 6 < uVar5
                  )))))) &&
               (*(uint *)(out + 0x18) = *(uint *)(ctx + 0xc4) ^ *(uint *)(ctx + 0x104), 7 < uVar5))
            {
              *(uint *)(out + 0x1c) = *(uint *)(ctx + 200) ^ *(uint *)(ctx + 0x108);
            }
            if (inl != uVar4) {
              out[inl & 0xfffffffc] = (byte)ctx[uVar4 + 0xec] ^ (byte)ctx[uVar4 + 0xac];
              if ((int)(uVar4 + 1) < (int)inl) {
                out[uVar4 + 1] = (byte)ctx[uVar4 + 0xed] ^ (byte)ctx[uVar4 + 0xad];
                if ((int)(uVar4 + 2) < (int)inl) {
                  out[uVar4 + 2] = (byte)ctx[uVar4 + 0xee] ^ (byte)ctx[uVar4 + 0xae];
                }
              }
            }
          }
        }
      }
      iVar6 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,out,out,inl);
      if (iVar6 == 0) {
        OPENSSL_cleanse(out,inl);
        return 0;
      }
    }
    iVar6 = 1;
  }
  return iVar6;
}

