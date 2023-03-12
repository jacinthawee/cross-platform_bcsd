
int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  size_t sVar1;
  uint *mask;
  EVP_MD *pEVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint seedlen;
  size_t __n;
  uchar *seed;
  size_t __n_00;
  uchar *__s;
  int iVar8;
  bool bVar9;
  uint local_54 [4];
  uint local_44;
  uchar auStack_40 [20];
  int local_2c;
  
  local_2c = __TMC_END__;
  sVar1 = rsa_len - 1;
  if ((int)sVar1 < 0x29) {
    ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xb5);
    sVar1 = 0xffffffff;
    goto LAB_0009815a;
  }
  __n_00 = sVar1 - fl;
  bVar9 = (int)__n_00 < 0;
  __n = sVar1;
  if (!bVar9) {
    __n = fl;
  }
  seedlen = rsa_len - 0x15;
  if (bVar9) {
    __n_00 = 0;
  }
  mask = (uint *)CRYPTO_malloc(sVar1 + seedlen,"rsa_oaep.c",0x7c);
  if (mask == (uint *)0x0) {
    ERR_put_error(4,0x7a,0x41,"rsa_oaep.c",0x7f);
    sVar1 = 0xffffffff;
    goto LAB_0009815a;
  }
  __s = (uchar *)((int)mask + seedlen);
  seed = __s + 0x14;
  memset(__s,0,__n_00);
  memcpy(__s + __n_00,f,__n);
  pEVar2 = EVP_sha1();
  iVar3 = PKCS1_MGF1((uchar *)local_54,0x14,seed,seedlen,pEVar2);
  if (iVar3 == 0) {
    puVar4 = (uint *)((int)mask + rsa_len + -0x15);
    uVar6 = (uint)(local_54 + 1 <= puVar4 || (uint *)((int)mask + rsa_len + -0x11) <= local_54);
    if (((uint)puVar4 & 3) != 0) {
      uVar6 = 0;
    }
    if (uVar6 == 0) {
      do {
        *(byte *)((int)local_54 + uVar6) = *(byte *)((int)local_54 + uVar6) ^ __s[uVar6];
        uVar6 = uVar6 + 1;
      } while (uVar6 != 0x14);
    }
    else {
      local_54[0] = local_54[0] ^ *(uint *)((int)mask + rsa_len + -0x15);
      local_54[1] = local_54[1] ^ *(uint *)((int)mask + rsa_len + -0x11);
      local_54[2] = local_54[2] ^ *(uint *)((int)mask + rsa_len + -0xd);
      local_54[3] = local_54[3] ^ *(uint *)((int)mask + rsa_len + -9);
      local_44 = local_44 ^ *(uint *)((int)mask + rsa_len + -5);
    }
    pEVar2 = EVP_sha1();
    uVar6 = PKCS1_MGF1((uchar *)mask,seedlen,(uchar *)local_54,0x14,pEVar2);
    if (uVar6 == 0) {
      if (0 < (int)seedlen) {
        puVar4 = (uint *)((int)mask + rsa_len + -1);
        uVar7 = (uint)(mask + 1 <= puVar4 || (uint *)((int)mask + rsa_len + 3) <= mask);
        if (seedlen < 7) {
          uVar7 = 0;
        }
        if ((((uint)puVar4 | (uint)mask) & 3) != 0) {
          uVar7 = 0;
        }
        if (uVar7 == 0) {
          do {
            *(byte *)((int)mask + uVar7) = *(byte *)((int)mask + uVar7) ^ __s[uVar7 + 0x14];
            uVar7 = uVar7 + 1;
          } while (uVar7 != seedlen);
        }
        else {
          puVar4 = (uint *)((int)mask + rsa_len + -5);
          uVar7 = seedlen & 0xfffffffc;
          puVar5 = mask;
          do {
            uVar6 = uVar6 + 1;
            puVar4 = puVar4 + 1;
            *puVar5 = *puVar4 ^ *puVar5;
            puVar5 = puVar5 + 1;
          } while (uVar6 < seedlen >> 2);
          if (seedlen != uVar7) {
            iVar3 = uVar7 + 1;
            *(byte *)((int)mask + (seedlen & 0xfffffffc)) =
                 seed[seedlen & 0xfffffffc] ^ *(byte *)((int)mask + (seedlen & 0xfffffffc));
            if (iVar3 < (int)seedlen) {
              iVar8 = uVar7 + 2;
              *(byte *)((int)mask + iVar3) = *(byte *)((int)mask + iVar3) ^ seed[iVar3];
              if (iVar8 < (int)seedlen) {
                *(byte *)((int)mask + iVar8) = *(byte *)((int)mask + iVar8) ^ seed[iVar8];
              }
            }
          }
        }
      }
      pEVar2 = EVP_sha1();
      iVar3 = EVP_Digest(p,pl,auStack_40,(uint *)0x0,pEVar2,(ENGINE *)0x0);
      if (iVar3 != 0) {
        iVar3 = CRYPTO_memcmp(mask,auStack_40,0x14);
        if ((iVar3 == 0) && (!bVar9)) {
          if ((int)seedlen < 0x15) {
            uVar6 = 0x14;
LAB_000981ae:
            if (uVar6 == seedlen) goto LAB_0009813a;
          }
          else {
            if (*(uchar *)(mask + 5) == '\0') {
              uVar6 = 0x14;
              do {
                uVar6 = uVar6 + 1;
                if (uVar6 == seedlen) break;
              } while (*(uchar *)((int)mask + uVar6) == '\0');
              goto LAB_000981ae;
            }
            uVar6 = 0x14;
          }
          if (*(uchar *)((int)mask + uVar6) == '\x01') {
            sVar1 = seedlen - (uVar6 + 1);
            if (tlen < (int)sVar1) {
              sVar1 = 0xffffffff;
              ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xa8);
            }
            else {
              memcpy(to,(uchar *)(uVar6 + 1 + (int)mask),sVar1);
            }
            CRYPTO_free(mask);
            goto LAB_0009815a;
          }
        }
LAB_0009813a:
        ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xb5);
        CRYPTO_free(mask);
      }
    }
  }
  sVar1 = 0xffffffff;
LAB_0009815a:
  if (local_2c == __TMC_END__) {
    return sVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

