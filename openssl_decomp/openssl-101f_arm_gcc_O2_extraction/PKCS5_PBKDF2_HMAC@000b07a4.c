
int PKCS5_PBKDF2_HMAC(char *pass,int passlen,uchar *salt,int saltlen,int iter,EVP_MD *digest,
                     int keylen,uchar *out)

{
  size_t len;
  int iVar1;
  uint uVar2;
  int iVar3;
  char *len_00;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  size_t __n;
  int local_21c;
  uchar local_210;
  undefined local_20f;
  undefined local_20e;
  undefined local_20d;
  undefined4 local_20c;
  uint local_208;
  uint local_204;
  uint local_200;
  uint local_1fc;
  uint local_1f8;
  uint local_1f4;
  uint local_1f0;
  uint local_1ec;
  uint local_1e8;
  uint local_1e4;
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  uint local_1d4;
  uint local_1d0;
  HMAC_CTX HStack_1cc;
  HMAC_CTX HStack_fc;
  int local_2c;
  
  local_2c = __TMC_END__;
  len = EVP_MD_size(digest);
  if ((int)len < 0) {
    iVar1 = 0;
  }
  else {
    HMAC_CTX_init(&HStack_1cc);
    len_00 = pass;
    if ((pass != (char *)0x0) && (len_00 = (char *)passlen, passlen == -1)) {
      len_00 = (char *)strlen(pass);
    }
    iVar1 = HMAC_Init_ex(&HStack_1cc,pass,(int)len_00,digest,(ENGINE *)0x0);
    if (iVar1 == 0) {
LAB_000b0af8:
      HMAC_CTX_cleanup(&HStack_1cc);
      iVar1 = 0;
    }
    else {
      if (keylen != 0) {
        local_21c = 1;
        do {
          local_20d = (undefined)local_21c;
          local_210 = (uchar)((uint)local_21c >> 0x18);
          local_20f = (undefined)((uint)local_21c >> 0x10);
          local_20e = (undefined)((uint)local_21c >> 8);
          __n = keylen;
          if ((int)len <= keylen) {
            __n = len;
          }
          iVar1 = HMAC_CTX_copy(&HStack_fc,&HStack_1cc);
          if (iVar1 == 0) goto LAB_000b0af8;
          iVar1 = HMAC_Update(&HStack_fc,salt,saltlen);
          if (((iVar1 == 0) || (iVar1 = HMAC_Update(&HStack_fc,&local_210,4), iVar1 == 0)) ||
             (iVar1 = HMAC_Final(&HStack_fc,(uchar *)&local_20c,(uint *)0x0), iVar1 == 0)) {
LAB_000b0ae8:
            HMAC_CTX_cleanup(&HStack_1cc);
            HMAC_CTX_cleanup(&HStack_fc);
            iVar1 = 0;
            goto LAB_000b0ad6;
          }
          HMAC_CTX_cleanup(&HStack_fc);
          memcpy(out,&local_20c,__n);
          if (1 < iter) {
            uVar6 = __n >> 2;
            iVar1 = 1;
            uVar2 = __n & 0xfffffffc;
            uVar5 = (uint)(((uint)out & 3) == 0);
            if (__n < 6) {
              uVar5 = 0;
            }
            iVar7 = uVar2 + 1;
            iVar8 = uVar2 + 2;
            do {
              while( true ) {
                iVar3 = HMAC_CTX_copy(&HStack_fc,&HStack_1cc);
                if (iVar3 == 0) goto LAB_000b0af8;
                iVar3 = HMAC_Update(&HStack_fc,(uchar *)&local_20c,len);
                if ((iVar3 == 0) ||
                   (iVar3 = HMAC_Final(&HStack_fc,(uchar *)&local_20c,(uint *)0x0), iVar3 == 0))
                goto LAB_000b0ae8;
                HMAC_CTX_cleanup(&HStack_fc);
                if (0 < (int)__n) break;
LAB_000b0a54:
                iVar1 = iVar1 + 1;
                if (iVar1 == iter) goto LAB_000b0ab8;
              }
              uVar4 = uVar5;
              if (uVar5 != 0) {
                if ((__n & 0xfffffffc) != 0) {
                  *(uint *)out = local_20c ^ *(uint *)out;
                  if (((((1 < uVar6) &&
                        (*(uint *)((int)out + 4) = local_208 ^ *(uint *)((int)out + 4), uVar6 != 2))
                       && ((*(uint *)((int)out + 8) = local_204 ^ *(uint *)((int)out + 8),
                           uVar6 != 3 &&
                           ((((*(uint *)((int)out + 0xc) = local_200 ^ *(uint *)((int)out + 0xc),
                              uVar6 != 4 &&
                              (*(uint *)((int)out + 0x10) = local_1fc ^ *(uint *)((int)out + 0x10),
                              uVar6 != 5)) &&
                             (*(uint *)((int)out + 0x14) = local_1f8 ^ *(uint *)((int)out + 0x14),
                             uVar6 != 6)) &&
                            ((*(uint *)((int)out + 0x18) = local_1f4 ^ *(uint *)((int)out + 0x18),
                             uVar6 != 7 &&
                             (*(uint *)((int)out + 0x1c) = local_1f0 ^ *(uint *)((int)out + 0x1c),
                             uVar6 != 8)))))))) &&
                      (*(uint *)((int)out + 0x20) = *(uint *)((int)out + 0x20) ^ local_1ec,
                      uVar6 != 9)) &&
                     (((*(uint *)((int)out + 0x24) = *(uint *)((int)out + 0x24) ^ local_1e8,
                       uVar6 != 10 &&
                       (*(uint *)((int)out + 0x28) = *(uint *)((int)out + 0x28) ^ local_1e4,
                       uVar6 != 0xb)) &&
                      ((*(uint *)((int)out + 0x2c) = *(uint *)((int)out + 0x2c) ^ local_1e0,
                       uVar6 != 0xc &&
                       (((*(uint *)((int)out + 0x30) = *(uint *)((int)out + 0x30) ^ local_1dc,
                         uVar6 != 0xd &&
                         (*(uint *)((int)out + 0x34) = *(uint *)((int)out + 0x34) ^ local_1d8,
                         uVar6 != 0xe)) &&
                        (*(uint *)((int)out + 0x38) = *(uint *)((int)out + 0x38) ^ local_1d4,
                        uVar6 != 0xf)))))))) {
                    *(uint *)((int)out + 0x3c) = *(uint *)((int)out + 0x3c) ^ local_1d0;
                  }
                  if ((__n & 0xfffffffc) == __n) goto LAB_000b0a54;
                }
                *(byte *)(uVar2 + (int)out) =
                     *(byte *)((int)&local_20c + uVar2) ^ *(byte *)(uVar2 + (int)out);
                if ((iVar7 < (int)__n) &&
                   (*(byte *)((int)out + iVar7) =
                         *(byte *)((int)&local_20c + iVar7) ^ *(byte *)((int)out + iVar7),
                   iVar8 < (int)__n)) {
                  *(byte *)((int)out + iVar8) =
                       *(byte *)((int)&local_20c + iVar8) ^ *(byte *)((int)out + iVar8);
                }
                goto LAB_000b0a54;
              }
              do {
                *(byte *)((int)out + uVar4) =
                     *(byte *)((int)out + uVar4) ^ *(byte *)((int)&local_20c + uVar4);
                uVar4 = uVar4 + 1;
              } while (uVar4 != __n);
              iVar1 = iVar1 + 1;
            } while (iVar1 != iter);
          }
LAB_000b0ab8:
          out = (uchar *)((int)out + __n);
          keylen = keylen - __n;
          local_21c = local_21c + 1;
        } while (keylen != 0);
      }
      HMAC_CTX_cleanup(&HStack_1cc);
      iVar1 = 1;
    }
  }
LAB_000b0ad6:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

