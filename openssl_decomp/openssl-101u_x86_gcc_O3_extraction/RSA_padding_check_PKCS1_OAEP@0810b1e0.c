
int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  int num;
  byte *seed;
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  byte *mask;
  byte *__s;
  EVP_MD *pEVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t __n;
  int in_GS_OFFSET;
  uint local_bc;
  uint local_b4;
  uint local_a0 [4];
  uint local_90;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((tlen < 1) || (fl < 1)) {
    __n = 0xffffffff;
    goto LAB_0810b534;
  }
  if ((rsa_len < fl) || (rsa_len < 0x2a)) {
    __s = (byte *)0x0;
    mask = (byte *)0x0;
    goto LAB_0810b4f4;
  }
  num = rsa_len + -0x15;
  mask = (byte *)CRYPTO_malloc(num,"rsa_oaep.c",0x78);
  __s = (byte *)CRYPTO_malloc(rsa_len,"rsa_oaep.c",0x79);
  if ((mask == (byte *)0x0) || (__s == (byte *)0x0)) {
    ERR_put_error(4,0x7a,0x41,"rsa_oaep.c",0x7b);
LAB_0810b50f:
    __n = 0xffffffff;
    if (mask != (byte *)0x0) goto LAB_0810b518;
  }
  else {
    memset(__s,0,rsa_len);
    memcpy(__s + (rsa_len - fl),f,fl);
    bVar3 = *__s;
    seed = __s + 0x15;
    pEVar4 = EVP_sha1();
    iVar5 = PKCS1_MGF1((uchar *)local_a0,0x14,seed,num,pEVar4);
    if (iVar5 == 0) {
      if ((local_a0 < __s + 5 && __s + 1 < local_a0 + 1) || (((uint)(__s + 1) & 3) != 0)) {
        iVar5 = 0;
        do {
          pbVar1 = (byte *)((int)local_a0 + iVar5);
          *pbVar1 = *pbVar1 ^ __s[iVar5 + 1];
          iVar5 = iVar5 + 1;
        } while (iVar5 != 0x14);
      }
      else {
        local_a0[0] = local_a0[0] ^ *(uint *)(__s + 1);
        local_a0[1] = local_a0[1] ^ *(uint *)(__s + 5);
        local_a0[2] = local_a0[2] ^ *(uint *)(__s + 9);
        local_a0[3] = local_a0[3] ^ *(uint *)(__s + 0xd);
        local_90 = local_90 ^ *(uint *)(__s + 0x11);
      }
      pEVar4 = EVP_sha1();
      iVar5 = PKCS1_MGF1(mask,num,(uchar *)local_a0,0x14,pEVar4);
      if (iVar5 == 0) {
        if (((((uint)seed | (uint)mask) & 3) == 0) && (mask + 4 <= seed || __s + 0x19 <= mask)) {
          iVar5 = 1;
          if (0x15 < rsa_len) {
            iVar5 = num;
          }
          uVar6 = 0;
          uVar8 = (iVar5 - 4U >> 2) + 1;
          iVar2 = uVar8 * 4;
          do {
            *(uint *)(mask + uVar6 * 4) =
                 *(uint *)(mask + uVar6 * 4) ^ *(uint *)(__s + uVar6 * 4 + 0x15);
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar8);
          if (iVar2 - iVar5 != 0) {
            mask[iVar2] = mask[iVar2] ^ seed[uVar8 * 4];
            if (iVar2 + 1 < num) {
              mask[iVar2 + 1] = mask[iVar2 + 1] ^ __s[iVar2 + 0x16];
              if (iVar2 + 2 < num) {
                mask[iVar2 + 2] = mask[iVar2 + 2] ^ __s[iVar2 + 0x17];
              }
            }
          }
        }
        else {
          iVar5 = 0;
          do {
            mask[iVar5] = mask[iVar5] ^ __s[iVar5 + 0x15];
            iVar5 = iVar5 + 1;
          } while (iVar5 < num);
        }
        pEVar4 = EVP_sha1();
        iVar5 = EVP_Digest(p,pl,local_60,(uint *)0x0,pEVar4,(ENGINE *)0x0);
        if (iVar5 != 0) {
          uVar6 = CRYPTO_memcmp(mask,local_60,0x14);
          uVar8 = 0;
          local_b4 = (int)(bVar3 - 1 & ~(uint)bVar3 & uVar6 - 1 & ~uVar6) >> 0x1f;
          uVar6 = 0x14;
          local_bc = 0;
          do {
            uVar7 = (uint)mask[uVar6];
            uVar10 = local_bc ^ uVar6;
            uVar11 = ~uVar8;
            uVar9 = (int)((uVar7 ^ 1) - 1 & ~(uVar7 ^ 1)) >> 0x1f;
            uVar8 = uVar8 | uVar9;
            uVar6 = uVar6 + 1;
            local_bc = local_bc ^ uVar10 & uVar11 & uVar9;
            local_b4 = local_b4 & ((int)(uVar7 - 1 & ~uVar7) >> 0x1f | uVar8);
          } while ((int)uVar6 < num);
          if ((local_b4 & uVar8) == 0) {
LAB_0810b4f4:
            ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xcb);
            goto LAB_0810b50f;
          }
          __n = num - (local_bc + 1);
          if (tlen < (int)__n) {
            ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xbf);
            goto LAB_0810b4f4;
          }
          memcpy(to,mask + local_bc + 1,__n);
          goto LAB_0810b518;
        }
      }
    }
    __n = 0xffffffff;
LAB_0810b518:
    CRYPTO_free(mask);
  }
  if (__s != (byte *)0x0) {
    CRYPTO_free(__s);
  }
LAB_0810b534:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __n;
}

