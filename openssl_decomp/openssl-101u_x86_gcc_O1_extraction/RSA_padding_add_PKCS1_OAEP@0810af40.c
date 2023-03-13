
int RSA_padding_add_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,uchar *p,int pl)

{
  uchar *md;
  uchar *buf;
  uint num;
  EVP_MD *pEVar1;
  int iVar2;
  int iVar3;
  uchar *mask;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int in_GS_OFFSET;
  uint local_34 [4];
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = tlen + -1;
  if (fl < tlen + -0x29) {
    if (iVar3 < 0x29) {
      iVar2 = 0x31;
      iVar3 = 0x78;
      goto LAB_0810afcc;
    }
    *to = '\0';
    md = to + 0x15;
    pEVar1 = EVP_sha1();
    iVar2 = EVP_Digest(p,pl,md,(uint *)0x0,pEVar1,(ENGINE *)0x0);
    if (iVar2 != 0) {
      buf = to + 1;
      memset(to + 0x29,0,(iVar3 - fl) - 0x29);
      to[iVar3 - fl] = '\x01';
      memcpy(to + (iVar3 - fl) + 1,f,fl);
      iVar3 = RAND_bytes(buf,0x14);
      if (0 < iVar3) {
        num = tlen - 0x15;
        mask = (uchar *)CRYPTO_malloc(num,"rsa_oaep.c",0x47);
        if (mask == (uchar *)0x0) {
          iVar2 = 0x49;
          iVar3 = 0x41;
          goto LAB_0810afcc;
        }
        pEVar1 = EVP_sha1();
        iVar3 = PKCS1_MGF1(mask,num,buf,0x14,pEVar1);
        if (-1 < iVar3) {
          if (0 < (int)num) {
            if ((num < 7 || mask < to + 0x19 && md < mask + 4) ||
               ((((uint)md | (uint)mask) & 3) != 0)) {
              uVar6 = 0;
              do {
                to[uVar6 + 0x15] = to[uVar6 + 0x15] ^ mask[uVar6];
                uVar6 = uVar6 + 1;
              } while (num != uVar6);
            }
            else {
              uVar5 = 0;
              uVar4 = (tlen - 0x19U >> 2) + 1;
              uVar6 = uVar4 * 4;
              do {
                *(uint *)(to + uVar5 * 4 + 0x15) =
                     *(uint *)(to + uVar5 * 4 + 0x15) ^ *(uint *)(mask + uVar5 * 4);
                uVar5 = uVar5 + 1;
              } while (uVar5 < uVar4);
              if (num != uVar6) {
                md[uVar6] = md[uVar6] ^ mask[uVar4 * 4];
                if ((int)(uVar6 + 1) < (int)num) {
                  md[uVar6 + 1] = md[uVar6 + 1] ^ mask[uVar6 + 1];
                  if ((int)(uVar6 + 2) < (int)num) {
                    md[uVar6 + 2] = md[uVar6 + 2] ^ mask[uVar6 + 2];
                  }
                }
              }
            }
          }
          pEVar1 = EVP_sha1();
          iVar3 = PKCS1_MGF1((uchar *)local_34,0x14,md,num,pEVar1);
          if (-1 < iVar3) {
            if (((uint)buf & 3) == 0) {
              *(uint *)(to + 1) = *(uint *)(to + 1) ^ local_34[0];
              *(uint *)(to + 5) = *(uint *)(to + 5) ^ local_34[1];
              *(uint *)(to + 9) = *(uint *)(to + 9) ^ local_34[2];
              *(uint *)(to + 0xd) = *(uint *)(to + 0xd) ^ local_34[3];
              *(uint *)(to + 0x11) = *(uint *)(to + 0x11) ^ local_24;
            }
            else {
              iVar3 = 0;
              do {
                to[iVar3 + 1] = to[iVar3 + 1] ^ *(byte *)((int)local_34 + iVar3);
                iVar3 = iVar3 + 1;
              } while (iVar3 != 0x14);
            }
            CRYPTO_free(mask);
            iVar3 = 1;
            goto LAB_0810afa3;
          }
        }
      }
    }
  }
  else {
    iVar2 = 0x2c;
    iVar3 = 0x6e;
LAB_0810afcc:
    ERR_put_error(4,0x79,iVar3,"rsa_oaep.c",iVar2);
  }
  iVar3 = 0;
LAB_0810afa3:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

