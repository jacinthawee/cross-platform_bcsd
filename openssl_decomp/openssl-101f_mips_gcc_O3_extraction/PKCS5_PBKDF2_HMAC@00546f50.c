
int PKCS5_PBKDF2_HMAC(char *pass,int passlen,uchar *salt,int saltlen,int iter,EVP_MD *digest,
                     int keylen,uchar *out)

{
  byte bVar1;
  undefined *puVar2;
  EVP_MD *pEVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  EVP_MD *pEVar7;
  uchar *puVar8;
  uint *puVar9;
  uint *puVar10;
  char *pass_00;
  undefined4 *puVar11;
  EVP_MD *salt_00;
  EVP_MD *pEVar12;
  int iVar13;
  int local_240;
  int iStack_23c;
  int local_224;
  undefined4 auStack_210 [52];
  undefined auStack_140 [208];
  undefined local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_6d;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
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
  char *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  puVar11 = (undefined4 *)passlen;
  salt_00 = (EVP_MD *)salt;
  pEVar12 = (EVP_MD *)saltlen;
  pEVar3 = (EVP_MD *)EVP_MD_size(digest);
  if ((int)pEVar3 < 0) {
    iVar4 = 0;
  }
  else {
    (*(code *)PTR_HMAC_CTX_init_006a8b0c)(auStack_210);
    if (pass == (char *)0x0) {
      salt_00 = (EVP_MD *)0x0;
    }
    else {
      salt_00 = (EVP_MD *)passlen;
      if (passlen == -1) {
        salt_00 = (EVP_MD *)(*(code *)PTR_strlen_006aab30)(pass);
      }
    }
    local_240 = 0;
    iVar4 = (*(code *)PTR_HMAC_Init_ex_006a8ba0)(auStack_210);
    if (iVar4 == 0) {
LAB_005474b4:
      (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_210);
      iVar4 = 0;
      puVar11 = (undefined4 *)pass;
      pEVar12 = digest;
    }
    else {
      if (keylen != 0) {
        local_224 = 1;
        do {
          local_6d = (undefined)local_224;
          pEVar12 = (EVP_MD *)keylen;
          if ((int)pEVar3 <= keylen) {
            pEVar12 = pEVar3;
          }
          local_70 = (undefined)((uint)local_224 >> 0x18);
          local_6f = (undefined)((uint)local_224 >> 0x10);
          local_6e = (undefined)((uint)local_224 >> 8);
          pass = (char *)auStack_210;
          salt_00 = pEVar3;
          digest = pEVar12;
          iVar4 = (*(code *)PTR_HMAC_CTX_copy_006a9d94)(auStack_140);
          if (iVar4 == 0) goto LAB_005474b4;
          pass = (char *)salt;
          salt_00 = (EVP_MD *)saltlen;
          iVar4 = (*(code *)PTR_HMAC_Update_006a8ba4)(auStack_140);
          if (iVar4 == 0) {
LAB_0054748c:
            (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_210);
            (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_140);
            iVar4 = 0;
            puVar11 = (undefined4 *)pass;
            pEVar12 = digest;
            goto LAB_0054744c;
          }
          salt_00 = (EVP_MD *)&SUB_00000004;
          pass = &local_70;
          iVar4 = (*(code *)PTR_HMAC_Update_006a8ba4)(auStack_140);
          if (iVar4 == 0) goto LAB_0054748c;
          salt_00 = (EVP_MD *)0x0;
          pass = (char *)&local_6c;
          iVar4 = (*(code *)PTR_HMAC_Final_006a8ba8)(auStack_140);
          if (iVar4 == 0) goto LAB_0054748c;
          (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_140);
          pass = (char *)&local_6c;
          salt_00 = pEVar12;
          (*(code *)PTR_memcpy_006aabf4)(out);
          if (1 < iter) {
            iVar4 = ((uint)&pEVar12[-1].md_ctrl >> 2) + 1;
            iVar13 = 1;
LAB_0054735c:
            do {
              pass = (char *)auStack_210;
              iVar6 = (*(code *)PTR_HMAC_CTX_copy_006a9d94)(auStack_140);
              if (iVar6 == 0) goto LAB_005474b4;
              pass = (char *)&local_6c;
              salt_00 = pEVar3;
              iVar6 = (*(code *)PTR_HMAC_Update_006a8ba4)(auStack_140);
              if (iVar6 == 0) goto LAB_0054748c;
              salt_00 = (EVP_MD *)0x0;
              pass = (char *)&local_6c;
              iVar6 = (*(code *)PTR_HMAC_Final_006a8ba8)(auStack_140);
              if (iVar6 == 0) goto LAB_0054748c;
              (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_140);
              if (0 < (int)pEVar12) {
                puVar9 = (uint *)out;
                puVar11 = &local_6c;
                if (((uint)out & 3) != 0 || pEVar12 <= (EVP_MD *)&DAT_00000005) {
                  do {
                    puVar10 = (uint *)((int)puVar9 + 1);
                    pass = (char *)((int)puVar11 + 1);
                    *(byte *)puVar9 = *(byte *)puVar9 ^ *(byte *)puVar11;
                    puVar9 = puVar10;
                    puVar11 = (undefined4 *)pass;
                  } while (puVar10 != (uint *)((int)out + (int)pEVar12));
                  iVar13 = iVar13 + 1;
                  if (iter == iVar13) break;
                  goto LAB_0054735c;
                }
                pEVar7 = (EVP_MD *)0x0;
                if (&SUB_00000002 < (undefined *)((int)&pEVar12[-1].md_ctrl + 3)) {
                  *(uint *)out = local_6c ^ *(uint *)out;
                  if (((((iVar4 != 1) &&
                        (*(uint *)((int)out + 4) = local_68 ^ *(uint *)((int)out + 4), iVar4 != 2))
                       && (*(uint *)((int)out + 8) = local_64 ^ *(uint *)((int)out + 8), iVar4 != 3)
                       ) && (((*(uint *)((int)out + 0xc) = local_60 ^ *(uint *)((int)out + 0xc),
                              iVar4 != 4 &&
                              (*(uint *)((int)out + 0x10) = local_5c ^ *(uint *)((int)out + 0x10),
                              iVar4 != 5)) &&
                             ((*(uint *)((int)out + 0x14) = local_58 ^ *(uint *)((int)out + 0x14),
                              iVar4 != 6 &&
                              ((*(uint *)((int)out + 0x18) = local_54 ^ *(uint *)((int)out + 0x18),
                               iVar4 != 7 &&
                               (*(uint *)((int)out + 0x1c) = local_50 ^ *(uint *)((int)out + 0x1c),
                               iVar4 != 8)))))))) &&
                     ((*(uint *)((int)out + 0x20) = *(uint *)((int)out + 0x20) ^ local_4c,
                      iVar4 != 9 &&
                      (((((*(uint *)((int)out + 0x24) = *(uint *)((int)out + 0x24) ^ local_48,
                          iVar4 != 10 &&
                          (*(uint *)((int)out + 0x28) = *(uint *)((int)out + 0x28) ^ local_44,
                          iVar4 != 0xb)) &&
                         (*(uint *)((int)out + 0x2c) = *(uint *)((int)out + 0x2c) ^ local_40,
                         iVar4 != 0xc)) &&
                        ((*(uint *)((int)out + 0x30) = *(uint *)((int)out + 0x30) ^ local_3c,
                         iVar4 != 0xd &&
                         (*(uint *)((int)out + 0x34) = *(uint *)((int)out + 0x34) ^ local_38,
                         iVar4 != 0xe)))) &&
                       (*(uint *)((int)out + 0x38) = *(uint *)((int)out + 0x38) ^ local_34,
                       iVar4 != 0xf)))))) {
                    *(uint *)((int)out + 0x3c) = *(uint *)((int)out + 0x3c) ^ local_30;
                  }
                  salt_00 = (EVP_MD *)&stack0xffffffd8;
                  pEVar7 = (EVP_MD *)(iVar4 * 4);
                  if (pEVar12 == (EVP_MD *)(iVar4 * 4)) goto LAB_00547348;
                }
                puVar8 = (uchar *)((int)&pEVar7->type + 1);
                salt_00 = (EVP_MD *)(uint)((int)puVar8 < (int)pEVar12);
                bVar1 = *(byte *)((int)out + (int)pEVar7) ^ *(byte *)((int)&local_6c + (int)pEVar7);
                pass = (char *)(uint)bVar1;
                *(byte *)((int)out + (int)pEVar7) = bVar1;
                if (salt_00 != (EVP_MD *)0x0) {
                  pass = (char *)((int)out + (int)puVar8);
                  puVar5 = (uchar *)((int)&pEVar7->type + 2);
                  salt_00 = (EVP_MD *)(uint)((int)puVar5 < (int)pEVar12);
                  *pass = *pass ^ *(byte *)((int)&local_6c + (int)puVar8);
                  if (salt_00 != (EVP_MD *)0x0) {
                    *(byte *)((int)out + (int)puVar5) =
                         *(byte *)((int)out + (int)puVar5) ^ *(byte *)((int)&local_6c + (int)puVar5)
                    ;
                  }
                }
              }
LAB_00547348:
              iVar13 = iVar13 + 1;
            } while (iter != iVar13);
          }
          keylen = keylen - (int)pEVar12;
          local_224 = local_224 + 1;
          out = (uchar *)((int)out + (int)pEVar12);
        } while (keylen != 0);
      }
      (*(code *)PTR_HMAC_CTX_cleanup_006a8bac)(auStack_210);
      iVar4 = 1;
      puVar11 = (undefined4 *)pass;
      pEVar12 = digest;
    }
  }
LAB_0054744c:
  if (local_2c != *(char **)puVar2) {
    pass_00 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pEVar3 = EVP_sha1();
    iVar4 = PKCS5_PBKDF2_HMAC(pass_00,(int)puVar11,(uchar *)salt_00,(int)pEVar12,local_240,pEVar3,
                              iStack_23c,&_gp);
    return iVar4;
  }
  return iVar4;
}

