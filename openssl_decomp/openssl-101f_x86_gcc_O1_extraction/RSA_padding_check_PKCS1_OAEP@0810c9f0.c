
int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  uint *__s;
  uint seedlen;
  uchar *mask;
  EVP_MD *pEVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uchar uVar6;
  uint uVar7;
  uchar *puVar8;
  size_t sVar9;
  int in_GS_OFFSET;
  bool bVar10;
  uint local_54;
  uint local_48 [4];
  uint local_38;
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = rsa_len + -1;
  if (iVar5 < 0x29) {
    iVar2 = 0xb5;
    iVar5 = 0x79;
LAB_0810ccf7:
    ERR_put_error(4,0x7a,iVar5,"rsa_oaep.c",iVar2);
  }
  else {
    sVar9 = iVar5 - fl;
    bVar10 = (int)sVar9 < 0;
    if (bVar10) {
      sVar9 = 0;
      fl = iVar5;
    }
    local_54 = (uint)bVar10;
    seedlen = rsa_len - 0x15;
    mask = (uchar *)CRYPTO_malloc(seedlen + iVar5,"rsa_oaep.c",0x7c);
    if (mask == (uchar *)0x0) {
      iVar2 = 0x7f;
      iVar5 = 0x41;
      goto LAB_0810ccf7;
    }
    __s = (uint *)(mask + seedlen);
    memset(__s,0,sVar9);
    memcpy((void *)(sVar9 + (int)__s),f,fl);
    pEVar1 = EVP_sha1();
    iVar2 = PKCS1_MGF1((uchar *)local_48,0x14,(uchar *)(__s + 5),seedlen,pEVar1);
    if (iVar2 == 0) {
      if ((local_48 < mask + rsa_len + -0x11 && __s < local_48 + 1) || (((uint)__s & 3) != 0)) {
        iVar2 = 0;
        do {
          *(byte *)((int)local_48 + iVar2) =
               *(byte *)((int)local_48 + iVar2) ^ *(byte *)((int)__s + iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x14);
      }
      else {
        local_48[0] = local_48[0] ^ *__s;
        local_48[1] = local_48[1] ^ __s[1];
        local_48[2] = local_48[2] ^ __s[2];
        local_48[3] = local_48[3] ^ __s[3];
        local_38 = local_38 ^ __s[4];
      }
      pEVar1 = EVP_sha1();
      iVar2 = PKCS1_MGF1(mask,seedlen,(uchar *)local_48,0x14,pEVar1);
      if (iVar2 == 0) {
        if (0 < (int)seedlen) {
          puVar8 = mask + iVar5;
          if (((rsa_len + 3 < 1 || mask + 4 <= puVar8) && 6 < seedlen) &&
             ((((uint)puVar8 | (uint)mask) & 3) == 0)) {
            uVar7 = 0;
            uVar3 = rsa_len - 0x19U >> 2;
            uVar4 = uVar3 + 1;
            iVar5 = uVar4 * 4;
            do {
              *(uint *)(mask + uVar7 * 4) =
                   *(uint *)(mask + uVar7 * 4) ^ *(uint *)(puVar8 + uVar7 * 4);
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar4);
            if (iVar5 - seedlen != 0) {
              mask[iVar5] = mask[iVar5] ^ *(byte *)(__s + uVar3 + 6);
              if (iVar5 + 1 < (int)seedlen) {
                mask[iVar5 + 1] = mask[iVar5 + 1] ^ *(byte *)((int)__s + iVar5 + 0x15);
                if (iVar5 + 2 < (int)seedlen) {
                  mask[iVar5 + 2] = mask[iVar5 + 2] ^ *(byte *)((int)__s + iVar5 + 0x16);
                }
              }
            }
          }
          else {
            uVar3 = 0;
            do {
              mask[uVar3] = mask[uVar3] ^ *(byte *)((int)__s + uVar3 + 0x14);
              uVar3 = uVar3 + 1;
            } while (uVar3 != seedlen);
          }
        }
        pEVar1 = EVP_sha1();
        iVar5 = EVP_Digest(p,pl,local_34,(uint *)0x0,pEVar1,(ENGINE *)0x0);
        if (iVar5 != 0) {
          uVar3 = CRYPTO_memcmp(mask,local_34,0x14);
          if ((local_54 | uVar3) == 0) {
            if ((int)seedlen < 0x15) {
              uVar3 = 0x14;
LAB_0810cc87:
              uVar4 = uVar3;
              if (uVar4 == seedlen) goto LAB_0810cc98;
              uVar6 = mask[uVar4];
            }
            else {
              uVar4 = 0x14;
              if (mask[0x14] == '\0') {
                do {
                  uVar4 = uVar4 + 1;
                  uVar3 = seedlen;
                  if (uVar4 == seedlen) goto LAB_0810cc87;
                  uVar6 = mask[uVar4];
                } while (uVar6 == '\0');
              }
              else {
                uVar6 = mask[0x14];
              }
            }
            if (uVar6 == '\x01') {
              sVar9 = seedlen - (uVar4 + 1);
              if (tlen < (int)sVar9) {
                sVar9 = 0xffffffff;
                ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xa8);
              }
              else {
                memcpy(to,mask + uVar4 + 1,sVar9);
              }
              CRYPTO_free(mask);
              goto LAB_0810ccc9;
            }
          }
LAB_0810cc98:
          ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xb5);
          CRYPTO_free(mask);
          sVar9 = 0xffffffff;
          goto LAB_0810ccc9;
        }
      }
    }
  }
  sVar9 = 0xffffffff;
LAB_0810ccc9:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar9;
}

