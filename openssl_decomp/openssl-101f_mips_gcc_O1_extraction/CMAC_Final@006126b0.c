
int CMAC_Final(CMAC_CTX *ctx,uchar *out,size_t *poutlen)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  CMAC_CTX *pCVar4;
  CMAC_CTX *pCVar5;
  byte *pbVar6;
  
  if (*(int *)(ctx + 0x10c) == -1) {
    return 0;
  }
  uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)();
  *poutlen = uVar1;
  if (out != (uchar *)0x0) {
    uVar2 = *(uint *)(ctx + 0x10c);
    if (uVar1 == uVar2) {
      if (0 < (int)uVar1) {
        if ((((uint)out & 3) == 0 && ((CMAC_CTX *)(out + 4) <= ctx + 0x8c || ctx + 0xf0 <= out)) &&
           (5 < uVar1)) {
          iVar3 = (uVar1 - 4 >> 2) + 1;
          *(uint *)out = *(uint *)(ctx + 0xec) ^ *(uint *)(ctx + 0x8c);
          uVar2 = iVar3 * 4;
          if ((((iVar3 != 1) &&
               (*(uint *)(out + 4) = *(uint *)(ctx + 0xf0) ^ *(uint *)(ctx + 0x90), iVar3 != 2)) &&
              (*(uint *)(out + 8) = *(uint *)(ctx + 0xf4) ^ *(uint *)(ctx + 0x94), iVar3 != 3)) &&
             (((*(uint *)(out + 0xc) = *(uint *)(ctx + 0xf8) ^ *(uint *)(ctx + 0x98), iVar3 != 4 &&
               (*(uint *)(out + 0x10) = *(uint *)(ctx + 0xfc) ^ *(uint *)(ctx + 0x9c), iVar3 != 5))
              && ((*(uint *)(out + 0x14) = *(uint *)(ctx + 0x100) ^ *(uint *)(ctx + 0xa0),
                  iVar3 != 6 &&
                  (*(uint *)(out + 0x18) = *(uint *)(ctx + 0x104) ^ *(uint *)(ctx + 0xa4),
                  iVar3 != 7)))))) {
            *(uint *)(out + 0x1c) = *(uint *)(ctx + 0x108) ^ *(uint *)(ctx + 0xa8);
          }
          if (uVar1 != uVar2) {
            out[uVar2] = (byte)ctx[uVar2 + 0xec] ^ (byte)ctx[uVar2 + 0x8c];
            if ((int)(uVar2 + 1) < (int)uVar1) {
              out[uVar2 + 1] = (byte)ctx[uVar2 + 0xed] ^ (byte)ctx[uVar2 + 0x8d];
              if ((int)(uVar2 + 2) < (int)uVar1) {
                out[uVar2 + 2] = (byte)ctx[uVar2 + 0xee] ^ (byte)ctx[uVar2 + 0x8e];
              }
            }
          }
        }
        else {
          pCVar4 = ctx + 0xec;
          pbVar6 = out;
          do {
            pCVar5 = pCVar4 + 1;
            *pbVar6 = (byte)*pCVar4 ^ (byte)pCVar4[-0x60];
            pCVar4 = pCVar5;
            pbVar6 = pbVar6 + 1;
          } while (ctx + uVar1 + 0xec != pCVar5);
        }
      }
    }
    else {
      ctx[uVar2 + 0xec] = (CMAC_CTX)0x80;
      if (1 < (int)(uVar1 - uVar2)) {
        (*(code *)PTR_memset_006aab00)(ctx + uVar2 + 0xed,0,(uVar1 - uVar2) + -1);
      }
      if (0 < (int)uVar1) {
        if ((((uint)out & 3) == 0 && ((CMAC_CTX *)(out + 4) <= ctx + 0xac || ctx + 0xf0 <= out)) &&
           (5 < uVar1)) {
          iVar3 = (uVar1 - 4 >> 2) + 1;
          *(uint *)out = *(uint *)(ctx + 0xec) ^ *(uint *)(ctx + 0xac);
          uVar2 = iVar3 * 4;
          if (((iVar3 != 1) &&
              ((((*(uint *)(out + 4) = *(uint *)(ctx + 0xf0) ^ *(uint *)(ctx + 0xb0), iVar3 != 2 &&
                 (*(uint *)(out + 8) = *(uint *)(ctx + 0xf4) ^ *(uint *)(ctx + 0xb4), iVar3 != 3))
                && (*(uint *)(out + 0xc) = *(uint *)(ctx + 0xf8) ^ *(uint *)(ctx + 0xb8), iVar3 != 4
                   )) && ((*(uint *)(out + 0x10) = *(uint *)(ctx + 0xfc) ^ *(uint *)(ctx + 0xbc),
                          iVar3 != 5 &&
                          (*(uint *)(out + 0x14) = *(uint *)(ctx + 0x100) ^ *(uint *)(ctx + 0xc0),
                          iVar3 != 6)))))) &&
             (*(uint *)(out + 0x18) = *(uint *)(ctx + 0x104) ^ *(uint *)(ctx + 0xc4), iVar3 != 7)) {
            *(uint *)(out + 0x1c) = *(uint *)(ctx + 0x108) ^ *(uint *)(ctx + 200);
          }
          if (uVar1 != uVar2) {
            out[uVar2] = (byte)ctx[uVar2 + 0xec] ^ (byte)ctx[uVar2 + 0xac];
            if ((int)(uVar2 + 1) < (int)uVar1) {
              out[uVar2 + 1] = (byte)ctx[uVar2 + 0xed] ^ (byte)ctx[uVar2 + 0xad];
              if ((int)(uVar2 + 2) < (int)uVar1) {
                out[uVar2 + 2] = (byte)ctx[uVar2 + 0xee] ^ (byte)ctx[uVar2 + 0xae];
              }
            }
          }
        }
        else {
          pCVar4 = ctx + 0xec;
          pbVar6 = out;
          do {
            pCVar5 = pCVar4 + 1;
            *pbVar6 = (byte)*pCVar4 ^ (byte)pCVar4[-0x40];
            pCVar4 = pCVar5;
            pbVar6 = pbVar6 + 1;
          } while (pCVar5 != ctx + uVar1 + 0xec);
        }
      }
    }
    iVar3 = (*(code *)PTR_EVP_Cipher_006a90b0)(ctx,out,out,uVar1);
    if (iVar3 == 0) {
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(out,uVar1);
      return 0;
    }
  }
  return 1;
}

