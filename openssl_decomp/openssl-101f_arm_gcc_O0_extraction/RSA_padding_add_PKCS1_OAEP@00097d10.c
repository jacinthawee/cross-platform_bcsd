
int RSA_padding_add_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,uchar *p,int pl)

{
  byte *pbVar1;
  EVP_MD *pEVar2;
  int iVar3;
  uchar *mask;
  uint *puVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  uint *md;
  uint uVar8;
  int iVar9;
  uint num;
  uchar *buf;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  
  iVar9 = tlen + -1;
  local_2c = __TMC_END__;
  if (fl < tlen + -0x29) {
    if (iVar9 < 0x29) {
      ERR_put_error(4,0x79,0x78,"rsa_oaep.c",0x33);
      mask = (uchar *)0x0;
    }
    else {
      uVar8 = 0;
      md = (uint *)(to + 0x15);
      *to = '\0';
      local_44 = p;
      pEVar2 = EVP_sha1();
      iVar3 = EVP_Digest(local_44,pl,(uchar *)md,(uint *)0x0,pEVar2,(ENGINE *)0x0);
      if (iVar3 != 0) {
        local_44 = (uchar *)(iVar9 - fl);
        memset(to + 0x29,0,(size_t)(local_44 + -0x29));
        buf = to + 1;
        (local_44 + (int)md)[-0x15] = '\x01';
        memcpy((byte *)((-0x14 - fl) + iVar9 + (int)md),f,fl);
        iVar9 = RAND_bytes(buf,0x14);
        if (0 < iVar9) {
          num = tlen - 0x15;
          mask = (uchar *)CRYPTO_malloc(num,"rsa_oaep.c",0x49);
          if (mask == (uchar *)0x0) {
            ERR_put_error(4,0x79,0x41,"rsa_oaep.c",0x4c);
            goto LAB_00097d6a;
          }
          pEVar2 = EVP_sha1();
          iVar9 = PKCS1_MGF1(mask,num,buf,0x14,pEVar2);
          if (-1 < iVar9) {
            if (0 < (int)num) {
              if ((((uint)md | (uint)mask) & 3) == 0 &&
                  (6 < num && (to + 0x19 <= mask || mask + 4 <= md))) {
                puVar4 = (uint *)(mask + -4);
                uVar7 = num & 0xfffffffc;
                puVar6 = md;
                do {
                  uVar8 = uVar8 + 1;
                  puVar4 = puVar4 + 1;
                  *puVar6 = *puVar4 ^ *puVar6;
                  puVar6 = puVar6 + 1;
                } while (uVar8 < num >> 2);
                if (num != uVar7) {
                  iVar9 = uVar7 + 1;
                  *(byte *)((int)md + (num & 0xfffffffc)) =
                       *(byte *)((int)md + (num & 0xfffffffc)) ^ mask[num & 0xfffffffc];
                  if (iVar9 < (int)num) {
                    iVar3 = uVar7 + 2;
                    *(byte *)((int)md + iVar9) = *(byte *)((int)md + iVar9) ^ mask[iVar9];
                    if (iVar3 < (int)num) {
                      *(byte *)((int)md + iVar3) = *(byte *)((int)md + iVar3) ^ mask[iVar3];
                    }
                  }
                }
              }
              else {
                pbVar5 = mask + -1;
                puVar4 = md;
                do {
                  pbVar5 = pbVar5 + 1;
                  puVar6 = (uint *)((int)puVar4 + 1);
                  *(byte *)puVar4 = *pbVar5 ^ *(byte *)puVar4;
                  puVar4 = puVar6;
                } while (puVar6 != (uint *)(to + tlen));
              }
            }
            pEVar2 = EVP_sha1();
            iVar9 = PKCS1_MGF1((uchar *)&local_40,0x14,(uchar *)md,num,pEVar2);
            if (-1 < iVar9) {
              if (((uint)buf & 3) == 0) {
                *(uint *)(to + 5) = *(uint *)(to + 5) ^ local_3c;
                *(uint *)(to + 1) = *(uint *)(to + 1) ^ local_40;
                *(uint *)(to + 9) = local_38 ^ *(uint *)(to + 9);
                *(uint *)(to + 0xd) = local_34 ^ *(uint *)(to + 0xd);
                *(uint *)(to + 0x11) = local_30 ^ *(uint *)(to + 0x11);
              }
              else {
                pbVar5 = (byte *)((int)&local_44 + 3);
                do {
                  pbVar5 = pbVar5 + 1;
                  pbVar1 = to + 1;
                  to = to + 1;
                  *to = *pbVar5 ^ *pbVar1;
                } while (pbVar5 != (byte *)((int)&local_30 + 3));
              }
              CRYPTO_free(mask);
              mask = (uchar *)0x1;
              goto LAB_00097d6a;
            }
          }
        }
      }
      mask = (uchar *)0x0;
    }
  }
  else {
    ERR_put_error(4,0x79,0x6e,"rsa_oaep.c",0x2d);
    mask = (uchar *)0x0;
  }
LAB_00097d6a:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)mask;
}

