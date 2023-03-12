
int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  byte bVar1;
  uint *mask;
  uint *__s;
  EVP_MD *pEVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint num;
  size_t __n;
  uint *seed;
  uint *puVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint auStack_98 [11];
  uchar auStack_6c [64];
  int local_2c;
  
  bVar15 = fl < 0;
  bVar16 = fl == 0;
  if (0 < fl) {
    bVar15 = tlen < 0;
    bVar16 = tlen == 0;
  }
  __s = (uint *)(uint)(bVar16 || bVar15);
  local_2c = __stack_chk_guard;
  if (bVar16 || bVar15) {
    __n = 0xffffffff;
    goto LAB_00096768;
  }
  bVar16 = SBORROW4(rsa_len,fl);
  iVar3 = rsa_len - fl;
  bVar15 = rsa_len == fl;
  if (fl <= rsa_len) {
    bVar16 = SBORROW4(rsa_len,0x29);
    iVar3 = rsa_len + -0x29;
    bVar15 = rsa_len == 0x29;
  }
  mask = __s;
  if (bVar15 || iVar3 < 0 != bVar16) goto LAB_0009677a;
  num = rsa_len - 0x15;
  mask = (uint *)CRYPTO_malloc(num,"rsa_oaep.c",0x78);
  __s = (uint *)CRYPTO_malloc(rsa_len,"rsa_oaep.c",0x79);
  if (mask != (uint *)0x0 && __s != (uint *)0x0) {
    memset(__s,(uint)(mask == (uint *)0x0 || __s == (uint *)0x0),rsa_len);
    memcpy((byte *)((rsa_len - fl) + (int)__s),f,fl);
    seed = (uint *)((int)__s + 0x15);
    bVar1 = *(byte *)__s;
    pEVar2 = EVP_sha1();
    iVar3 = PKCS1_MGF1((uchar *)&local_ac,0x14,(uchar *)seed,num,pEVar2);
    if (iVar3 == 0) {
      if (((uint)(uint *)((int)__s + 1) & 3) == 0 &&
          (&local_a8 <= (uint *)((int)__s + 1) || (uint *)((int)__s + 5) <= &local_ac)) {
        local_ac = *(uint *)((int)__s + 1) ^ local_ac;
        local_a8 = *(uint *)((int)__s + 5) ^ local_a8;
        local_a4 = *(uint *)((int)__s + 9) ^ local_a4;
        local_a0 = *(uint *)((int)__s + 0xd) ^ local_a0;
        local_9c = local_9c ^ *(uint *)((int)__s + 0x11);
      }
      else {
        puVar13 = __s;
        puVar7 = &local_ac;
        do {
          puVar13 = (uint *)((int)puVar13 + 1);
          puVar11 = (uint *)((int)puVar7 + 1);
          *(byte *)puVar7 = *(byte *)puVar7 ^ *(byte *)puVar13;
          puVar7 = puVar11;
        } while (puVar11 != auStack_98);
      }
      pEVar2 = EVP_sha1();
      uVar4 = PKCS1_MGF1((uchar *)mask,num,(uchar *)&local_ac,0x14,pEVar2);
      if (uVar4 == 0) {
        uVar8 = (uint)(mask + 1 <= seed || (uint *)((int)__s + 0x19) <= mask);
        if ((((uint)seed | (uint)mask) & 3) != 0) {
          uVar8 = 0;
        }
        if (uVar8 == 0) {
          do {
            *(byte *)((int)mask + uVar8) =
                 *(byte *)((int)mask + uVar8) ^ *(byte *)((int)__s + uVar8 + 0x15);
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < (int)num);
        }
        else {
          uVar8 = num;
          if (rsa_len < 0x16) {
            uVar8 = 1;
          }
          if (uVar8 >> 2 == 0) {
            iVar3 = 1;
            *(byte *)mask = *(byte *)((int)__s + 0x15) ^ *(byte *)mask;
LAB_000968b8:
            iVar9 = iVar3 + 1;
            *(byte *)((int)mask + iVar3) =
                 *(byte *)((int)mask + iVar3) ^ *(byte *)((int)seed + iVar3);
            if (iVar9 < (int)num) {
              *(byte *)((int)mask + iVar9) =
                   *(byte *)((int)seed + iVar9) ^ *(byte *)((int)mask + iVar9);
            }
          }
          else {
            puVar13 = (uint *)((int)__s + 0x11);
            puVar7 = mask;
            do {
              uVar4 = uVar4 + 1;
              puVar13 = puVar13 + 1;
              *puVar7 = *puVar7 ^ *puVar13;
              puVar7 = puVar7 + 1;
            } while (uVar4 < uVar8 >> 2);
            if ((uVar8 & 0xfffffffc) != uVar8) {
              iVar3 = (uVar8 & 0xfffffffc) + 1;
              *(byte *)((int)mask + (uVar8 & 0xfffffffc)) =
                   *(byte *)((int)seed + (uVar8 & 0xfffffffc)) ^
                   *(byte *)((int)mask + (uVar8 & 0xfffffffc));
              if (iVar3 < (int)num) goto LAB_000968b8;
            }
          }
        }
        pEVar2 = EVP_sha1();
        iVar3 = EVP_Digest(p,pl,auStack_6c,(uint *)0x0,pEVar2,(ENGINE *)0x0);
        if (iVar3 != 0) {
          uVar4 = CRYPTO_memcmp(mask,auStack_6c,0x14);
          uVar8 = 0;
          uVar14 = 0;
          uVar10 = 0x14;
          uVar4 = (int)(bVar1 - 1 & ~(uint)bVar1 & uVar4 - 1 & ~uVar4) >> 0x1f;
          do {
            uVar6 = (uint)*(byte *)((int)mask + uVar10);
            uVar12 = (int)((uVar6 ^ 1) - 1 & ~(uVar6 ^ 1)) >> 0x1f;
            uVar5 = uVar12 & ~uVar8;
            uVar8 = uVar8 | uVar12;
            uVar12 = uVar5 & uVar10;
            uVar10 = uVar10 + 1;
            uVar14 = uVar14 & ~uVar5 | uVar12;
            uVar4 = uVar4 & (uVar8 | (int)(uVar6 - 1 & ~uVar6) >> 0x1f);
          } while ((int)uVar10 < (int)num);
          if ((uVar8 & uVar4) == 0) {
LAB_0009677a:
            ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xcb);
            goto LAB_00096750;
          }
          __n = num - (uVar14 + 1);
          if (tlen < (int)__n) {
            ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xbf);
            goto LAB_0009677a;
          }
          memcpy(to,(byte *)(uVar14 + 1 + (int)mask),__n);
          goto LAB_00096756;
        }
      }
    }
    __n = 0xffffffff;
LAB_00096756:
    CRYPTO_free(mask);
  }
  else {
    ERR_put_error(4,0x7a,0x41,"rsa_oaep.c",0x7b);
LAB_00096750:
    __n = 0xffffffff;
    if (mask != (uint *)0x0) goto LAB_00096756;
  }
  if (__s != (uint *)0x0) {
    CRYPTO_free(__s);
  }
LAB_00096768:
  if (local_2c == __stack_chk_guard) {
    return __n;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

