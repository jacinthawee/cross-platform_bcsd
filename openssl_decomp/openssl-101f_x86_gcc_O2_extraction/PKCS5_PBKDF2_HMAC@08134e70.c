
int PKCS5_PBKDF2_HMAC(char *pass,int passlen,uchar *salt,int saltlen,int iter,EVP_MD *digest,
                     int keylen,uchar *out)

{
  byte *pbVar1;
  size_t len;
  int iVar2;
  size_t __n;
  int iVar3;
  uint uVar4;
  int in_GS_OFFSET;
  int local_228;
  int local_214;
  HMAC_CTX local_204;
  HMAC_CTX local_134;
  uchar local_64;
  undefined local_63;
  undefined local_62;
  undefined local_61;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  len = EVP_MD_size(digest);
  iVar2 = 0;
  if (-1 < (int)len) {
    HMAC_CTX_init(&local_204);
    if (pass == (char *)0x0) {
      passlen = 0;
    }
    else if (passlen == -1) {
      passlen = strlen(pass);
    }
    iVar2 = HMAC_Init_ex(&local_204,pass,passlen,digest,(ENGINE *)0x0);
    if (iVar2 == 0) {
LAB_0813527b:
      HMAC_CTX_cleanup(&local_204);
      iVar2 = 0;
    }
    else {
      if (keylen != 0) {
        local_214 = 1;
        do {
          __n = len;
          if (keylen < (int)len) {
            __n = keylen;
          }
          local_61 = (undefined)local_214;
          local_64 = (uchar)((uint)local_214 >> 0x18);
          local_63 = (undefined)((uint)local_214 >> 0x10);
          local_62 = (undefined)((uint)local_214 >> 8);
          iVar2 = HMAC_CTX_copy(&local_134,&local_204);
          if (iVar2 == 0) goto LAB_0813527b;
          iVar2 = HMAC_Update(&local_134,salt,saltlen);
          if (((iVar2 == 0) || (iVar2 = HMAC_Update(&local_134,&local_64,4), iVar2 == 0)) ||
             (iVar2 = HMAC_Final(&local_134,(uchar *)&local_60,(uint *)0x0), iVar2 == 0)) {
LAB_081352a8:
            HMAC_CTX_cleanup(&local_204);
            HMAC_CTX_cleanup(&local_134);
            iVar2 = 0;
            goto LAB_0813528d;
          }
          HMAC_CTX_cleanup(&local_134);
          memcpy(out,&local_60,__n);
          if (1 < iter) {
            local_228 = 1;
            iVar2 = (__n - 4 >> 2) + 1;
            do {
              iVar3 = HMAC_CTX_copy(&local_134,&local_204);
              if (iVar3 == 0) goto LAB_0813527b;
              iVar3 = HMAC_Update(&local_134,(uchar *)&local_60,len);
              if ((iVar3 == 0) ||
                 (iVar3 = HMAC_Final(&local_134,(uchar *)&local_60,(uint *)0x0), iVar3 == 0))
              goto LAB_081352a8;
              HMAC_CTX_cleanup(&local_134);
              if (0 < (int)__n) {
                if (((uint)out & 3) == 0 && 5 < __n) {
                  if (__n - 1 < 3) {
                    uVar4 = 0;
                  }
                  else {
                    *(uint *)out = *(uint *)out ^ local_60;
                    if (((((iVar2 != 1) &&
                          (*(uint *)((int)out + 4) = *(uint *)((int)out + 4) ^ local_5c, iVar2 != 2)
                          ) && ((*(uint *)((int)out + 8) = *(uint *)((int)out + 8) ^ local_58,
                                iVar2 != 3 &&
                                (((*(uint *)((int)out + 0xc) = *(uint *)((int)out + 0xc) ^ local_54,
                                  iVar2 != 4 &&
                                  (*(uint *)((int)out + 0x10) =
                                        *(uint *)((int)out + 0x10) ^ local_50, iVar2 != 5)) &&
                                 (*(uint *)((int)out + 0x14) = *(uint *)((int)out + 0x14) ^ local_4c
                                 , iVar2 != 6)))))) &&
                        ((*(uint *)((int)out + 0x18) = *(uint *)((int)out + 0x18) ^ local_48,
                         iVar2 != 7 &&
                         (*(uint *)((int)out + 0x1c) = *(uint *)((int)out + 0x1c) ^ local_44,
                         iVar2 != 8)))) &&
                       ((*(uint *)((int)out + 0x20) = *(uint *)((int)out + 0x20) ^ local_40,
                        iVar2 != 9 &&
                        (((*(uint *)((int)out + 0x24) = *(uint *)((int)out + 0x24) ^ local_3c,
                          iVar2 != 10 &&
                          (*(uint *)((int)out + 0x28) = *(uint *)((int)out + 0x28) ^ local_38,
                          iVar2 != 0xb)) &&
                         ((*(uint *)((int)out + 0x2c) = *(uint *)((int)out + 0x2c) ^ local_34,
                          iVar2 != 0xc &&
                          (((*(uint *)((int)out + 0x30) = *(uint *)((int)out + 0x30) ^ local_30,
                            iVar2 != 0xd &&
                            (*(uint *)((int)out + 0x34) = *(uint *)((int)out + 0x34) ^ local_2c,
                            iVar2 != 0xe)) &&
                           (*(uint *)((int)out + 0x38) = *(uint *)((int)out + 0x38) ^ local_28,
                           iVar2 != 0xf)))))))))) {
                      *(uint *)((int)out + 0x3c) = *(uint *)((int)out + 0x3c) ^ local_24;
                    }
                    uVar4 = iVar2 * 4;
                    if (__n == iVar2 * 4) goto LAB_081351b8;
                  }
                  *(byte *)((int)out + uVar4) =
                       *(byte *)((int)out + uVar4) ^ *(byte *)((int)&local_60 + uVar4);
                  if ((int)(uVar4 + 1) < (int)__n) {
                    pbVar1 = (byte *)((int)out + uVar4 + 1);
                    *pbVar1 = *pbVar1 ^ *(byte *)((int)&local_60 + uVar4 + 1);
                    if ((int)(uVar4 + 2) < (int)__n) {
                      pbVar1 = (byte *)((int)out + uVar4 + 2);
                      *pbVar1 = *pbVar1 ^ *(byte *)((int)&local_60 + uVar4 + 2);
                    }
                  }
                }
                else {
                  uVar4 = 0;
                  do {
                    *(byte *)((int)out + uVar4) =
                         *(byte *)((int)out + uVar4) ^ *(byte *)((int)&local_60 + uVar4);
                    uVar4 = uVar4 + 1;
                  } while (uVar4 != __n);
                }
              }
LAB_081351b8:
              local_228 = local_228 + 1;
            } while (iter != local_228);
          }
          local_214 = local_214 + 1;
          out = (uchar *)((int)out + __n);
          keylen = keylen - __n;
        } while (keylen != 0);
      }
      HMAC_CTX_cleanup(&local_204);
      iVar2 = 1;
    }
  }
LAB_0813528d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

