
undefined4
padlock_aes_cipher(EVP_CIPHER_CTX *param_1,undefined4 *param_2,undefined4 *param_3,
                  undefined4 *param_4)

{
  void *pvVar1;
  EVP_CIPHER **ppEVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  EVP_CIPHER_CTX *pEVar7;
  ulong uVar8;
  undefined4 *puVar9;
  int iVar10;
  EVP_CIPHER_CTX *pEVar11;
  int iVar12;
  EVP_CIPHER_CTX *pEVar13;
  uchar *puVar14;
  ENGINE *pEVar15;
  uint uVar16;
  byte *pbVar17;
  undefined4 *puVar18;
  undefined *puVar19;
  undefined *puVar20;
  byte *pbVar21;
  EVP_CIPHER *pEVar22;
  uint uVar23;
  undefined4 *puVar24;
  int in_GS_OFFSET;
  byte in_AF;
  bool bVar25;
  byte in_TF;
  byte in_IF;
  byte bVar26;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined auStack_5c [12];
  EVP_CIPHER_CTX *local_50 [3];
  uint local_44;
  uint local_40;
  EVP_CIPHER_CTX *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  int local_20;
  
  bVar26 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar6 = param_1->num;
  local_50[2] = param_1;
  local_34 = param_2;
  local_38 = param_3;
  if (uVar6 != 0) {
    uVar8 = EVP_CIPHER_CTX_flags(param_1);
    puVar19 = auStack_5c;
    if ((uVar8 & 0xf0007) == 3) {
      uVar4 = 0;
      if (0xf < uVar6) goto LAB_081a8f10;
      uVar16 = uVar6;
      if (local_50[2]->encrypt == 0) {
        if (param_4 != (undefined4 *)0x0) {
          do {
            puVar5 = local_38;
            local_38 = (undefined4 *)((int)local_38 + 1);
            puVar9 = (undefined4 *)((int)local_34 + 1);
            param_4 = (undefined4 *)((int)param_4 + -1);
            bVar3 = *(byte *)puVar5;
            uVar16 = uVar6 + 1;
            *(byte *)local_34 = bVar3 ^ param_1->iv[uVar6];
            param_1->iv[uVar6] = bVar3;
            if (0xf < uVar16) break;
            local_34 = puVar9;
            uVar6 = uVar16;
          } while (param_4 != (undefined4 *)0x0);
          local_34 = puVar9;
        }
      }
      else if (param_4 != (undefined4 *)0x0) {
        do {
          puVar5 = (undefined4 *)((int)local_38 + 1);
          puVar9 = (undefined4 *)((int)local_34 + 1);
          bVar3 = *(byte *)local_38 ^ param_1->iv[uVar6];
          param_4 = (undefined4 *)((int)param_4 + -1);
          *(byte *)local_34 = bVar3;
          param_1->iv[uVar6] = bVar3;
          uVar6 = uVar6 + 1;
          if (0xf < uVar6) break;
          local_38 = puVar5;
          local_34 = puVar9;
        } while (param_4 != (undefined4 *)0x0);
        local_34 = puVar9;
        local_38 = puVar5;
        uVar16 = uVar6;
      }
      local_50[2]->num = uVar16 & 0xf;
    }
    else if ((uVar8 & 0xf0007) == 4) {
      uVar4 = 0;
      puVar19 = auStack_5c;
      if (0xf < uVar6) goto LAB_081a8f10;
      if (param_4 != (undefined4 *)0x0) {
        do {
          puVar5 = (undefined4 *)((int)local_38 + 1);
          puVar9 = (undefined4 *)((int)local_34 + 1);
          puVar14 = param_1->iv + uVar6;
          uVar6 = uVar6 + 1;
          param_4 = (undefined4 *)((int)param_4 + -1);
          *(byte *)local_34 = *(byte *)local_38 ^ *puVar14;
          if (0xf < uVar6) break;
          local_38 = puVar5;
          local_34 = puVar9;
        } while (param_4 != (undefined4 *)0x0);
        local_34 = puVar9;
        local_38 = puVar5;
      }
      local_50[2]->num = uVar6 & 0xf;
    }
  }
  pEVar11 = local_50[2];
  puVar20 = auStack_5c;
  uVar4 = 1;
  puVar19 = auStack_5c;
  if (param_4 == (undefined4 *)0x0) goto LAB_081a8f10;
  local_44 = (uint)local_38 & 0xf;
  local_40 = (uint)local_34 & 0xf;
  if (((((uint)local_38 | (uint)local_34) & 0xf) == 0) && (((uint)param_4 & 0xf) == 0)) {
    uVar4 = padlock_aes_cipher_omnivorous(param_4);
    puVar19 = auStack_5c;
    goto LAB_081a8f10;
  }
  local_30 = (undefined4 *)0x200;
  if ((undefined4 *)((uint)param_4 & 0x1ff) != (undefined4 *)0x0) {
    local_30 = (undefined4 *)((uint)param_4 & 0x1ff);
  }
  if (((uint)local_34 & 0xf) == 0) {
    local_50[1] = (EVP_CIPHER_CTX *)0x0;
    puVar5 = local_34;
  }
  else {
    if (local_30 < param_4) {
      puVar5 = (undefined4 *)0x210;
      local_50[1] = (EVP_CIPHER_CTX *)0x200;
    }
    else {
      puVar5 = param_4 + 4;
      local_50[1] = (EVP_CIPHER_CTX *)param_4;
    }
    iVar10 = -((int)puVar5 + 0x1eU & 0xfffffff0);
    puVar20 = auStack_5c + iVar10;
    puVar5 = (undefined4 *)((int)local_50 + iVar10);
  }
  pvVar1 = local_50[2]->cipher_data;
  uVar6 = -(int)pvVar1 & 0xf;
  pEVar7 = (EVP_CIPHER_CTX *)(uVar6 + (int)pvVar1);
  local_3c = pEVar7;
  *(uint *)(puVar20 + -4) =
       (uint)(in_NT & 1) * 0x4000 | (uint)SCARRY4(uVar6,(int)pvVar1) * 0x800 |
       (uint)(bVar26 & 1) * 0x400 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)((int)pEVar7 < 0) * 0x80 | (uint)(pEVar7 == (EVP_CIPHER_CTX *)0x0) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT((uint)pEVar7 & 0xff) & 1U) == 0) * 4 |
       (uint)CARRY4(uVar6,(uint)pvVar1) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  if (((*(uint *)(puVar20 + -4) >> 0x1e & 1) != 0) && (padlock_saved_context != pEVar7)) {
    uVar6 = *(uint *)(puVar20 + -4);
    in_NT = (uVar6 & 0x4000) != 0;
    bVar26 = (uVar6 & 0x400) != 0;
    in_IF = (uVar6 & 0x200) != 0;
    in_TF = (uVar6 & 0x100) != 0;
    in_AF = (uVar6 & 0x10) != 0;
    in_ID = (uVar6 & 0x200000) != 0;
    in_AC = (uVar6 & 0x40000) != 0;
    in_VIP = 0;
    in_VIF = 0;
  }
  *(EVP_CIPHER_CTX **)(puVar20 + -0x10) = pEVar11;
  *(undefined4 *)(puVar20 + -0x14) = 0x81a9015;
  padlock_saved_context = pEVar7;
  uVar8 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(puVar20 + -0x10));
  uVar6 = uVar8 & 0xf0007;
  puVar19 = puVar20;
  if (uVar6 == 2) {
    pEVar15 = *(ENGINE **)(local_50[2]->iv + 4);
    iVar10 = *(int *)(local_50[2]->iv + 8);
    iVar12 = *(int *)(local_50[2]->iv + 0xc);
    local_3c->cipher = *(EVP_CIPHER **)local_50[2]->iv;
    local_3c->engine = pEVar15;
    local_3c->encrypt = iVar10;
    local_3c->buf_len = iVar12;
    while( true ) {
      pEVar11 = local_3c;
      puVar9 = local_38;
      if (local_44 != 0) {
        uVar6 = 0;
        do {
          puVar5[uVar6] = local_38[uVar6];
          uVar6 = uVar6 + 1;
          puVar9 = puVar5;
        } while ((uint)local_30 >> 2 != uVar6);
      }
      local_38 = (undefined4 *)((int)local_30 + (int)local_38);
      uVar6 = (uint)local_30 >> 4;
      *(undefined4 **)(puVar20 + -4) = puVar5;
      xcrypt_cbc(uVar6,pEVar11,pEVar11->oiv,pEVar11->iv,puVar9,puVar5);
      puVar5 = *(undefined4 **)(puVar20 + -4);
      if (local_40 == 0) {
        local_34 = (undefined4 *)((int)local_30 + (int)local_34);
        puVar5 = local_34;
      }
      else {
        uVar6 = 0;
        do {
          local_34[uVar6] = puVar5[uVar6];
          uVar6 = uVar6 + 1;
        } while ((uint)local_30 >> 2 != uVar6);
        local_34 = (undefined4 *)((int)local_30 + (int)local_34);
      }
      param_4 = (undefined4 *)((int)param_4 - (int)local_30);
      if (param_4 == (undefined4 *)0x0) break;
      if (local_3c != pEVar11) {
        pEVar15 = pEVar11->engine;
        iVar10 = pEVar11->encrypt;
        iVar12 = pEVar11->buf_len;
        local_3c->cipher = pEVar11->cipher;
        local_3c->engine = pEVar15;
        local_3c->encrypt = iVar10;
        local_3c->buf_len = iVar12;
      }
      local_30 = (undefined4 *)0x200;
    }
LAB_081a96d2:
    pEVar22 = pEVar11->cipher;
    pEVar15 = pEVar11->engine;
    iVar10 = pEVar11->encrypt;
    iVar12 = pEVar11->buf_len;
LAB_081a96dd:
    *(EVP_CIPHER **)local_50[2]->iv = pEVar22;
    *(ENGINE **)(local_50[2]->iv + 4) = pEVar15;
    *(int *)(local_50[2]->iv + 8) = iVar10;
    *(int *)(local_50[2]->iv + 0xc) = iVar12;
  }
  else {
    if (2 < uVar6) {
      if (uVar6 != 3) {
        if (uVar6 == 4) {
          pEVar15 = *(ENGINE **)(local_50[2]->iv + 4);
          iVar10 = *(int *)(local_50[2]->iv + 8);
          iVar12 = *(int *)(local_50[2]->iv + 0xc);
          local_3c->cipher = *(EVP_CIPHER **)local_50[2]->iv;
          local_3c->engine = pEVar15;
          local_3c->buf_len = iVar12;
          local_3c->encrypt = iVar10;
          puVar9 = (undefined4 *)((uint)local_30 & 0xfffffff0);
          bVar25 = puVar9 == (undefined4 *)0x0;
          uVar6 = (uint)local_30 & 0xf0;
          local_30 = puVar9;
          if (!bVar25) {
            do {
              pEVar11 = local_3c;
              puVar9 = local_38;
              if (local_44 != 0) {
                uVar6 = 0;
                do {
                  puVar5[uVar6] = local_38[uVar6];
                  uVar6 = uVar6 + 1;
                  puVar9 = puVar5;
                } while ((uint)local_30 >> 2 != uVar6);
              }
              local_38 = (undefined4 *)((int)local_30 + (int)local_38);
              uVar6 = (uint)local_30 >> 4;
              *(undefined4 **)(puVar20 + -4) = puVar5;
              xcrypt_ofb(uVar6,pEVar11,pEVar11->oiv,pEVar11->iv,puVar9,puVar5);
              puVar5 = *(undefined4 **)(puVar20 + -4);
              if (local_40 == 0) {
                local_34 = (undefined4 *)((int)local_30 + (int)local_34);
                puVar5 = local_34;
              }
              else {
                uVar6 = 0;
                do {
                  local_34[uVar6] = puVar5[uVar6];
                  uVar6 = uVar6 + 1;
                } while ((uint)local_30 >> 2 != uVar6);
                local_34 = (undefined4 *)((int)local_30 + (int)local_34);
              }
              puVar9 = (undefined4 *)((int)param_4 - (int)local_30);
              local_30 = (undefined4 *)0x200;
              param_4 = puVar9;
            } while (&DAT_0000000f < puVar9);
            bVar25 = puVar9 == (undefined4 *)0x0;
            uVar6 = (uint)puVar9 & 0xff;
            pEVar11 = local_3c;
            if (bVar25) goto LAB_081a96d2;
          }
          local_50[2]->num = (int)param_4;
          *(uint *)(puVar20 + -4) =
               (uint)(in_NT & 1) * 0x4000 | (uint)(bVar26 & 1) * 0x400 | (uint)(in_IF & 1) * 0x200 |
               (uint)(in_TF & 1) * 0x100 | (uint)((int)puVar9 < 0) * 0x80 | (uint)bVar25 * 0x40 |
               (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT(uVar6) & 1U) == 0) * 4 |
               (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
               (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
          pEVar11 = local_3c;
          uVar6 = *(uint *)(puVar20 + -4);
          *(undefined4 **)(puVar20 + -4) = puVar5;
          xcrypt_ecb(1,pEVar11->oiv,pEVar11->iv,pEVar11,pEVar11);
          puVar5 = *(undefined4 **)(puVar20 + -4);
          *(uint *)(puVar20 + -4) =
               (uint)((uVar6 & 0x4000) != 0) * 0x4000 | (uint)((uVar6 & 0x800) != 0) * 0x800 |
               (uint)((uVar6 & 0x400) != 0) * 0x400 | (uint)((uVar6 & 0x200) != 0) * 0x200 |
               (uint)((uVar6 & 0x100) != 0) * 0x100 | (uint)((uVar6 & 0x80) != 0) * 0x80 |
               (uint)((uVar6 & 0x40) != 0) * 0x40 | (uint)((uVar6 & 0x10) != 0) * 0x10 |
               (uint)((uVar6 & 4) != 0) * 4 | (uint)((uVar6 & 1) != 0) |
               (uint)((uVar6 & 0x200000) != 0) * 0x200000 | (uint)((uVar6 & 0x40000) != 0) * 0x40000
          ;
          pEVar11 = local_3c;
          if ((param_4 < (undefined4 *)0x7 ||
               (local_34 < local_38 + 1 && local_38 < local_34 + 1 ||
               local_34 < &local_3c->engine && local_3c < local_34 + 1)) ||
             ((((uint)local_34 | (uint)local_38 | (uint)local_3c) & 3) != 0)) {
            pEVar7 = local_3c;
            puVar9 = local_34;
            puVar24 = local_38;
            do {
              puVar18 = (undefined4 *)((int)puVar9 + 1);
              ppEVar2 = &pEVar7->cipher;
              pEVar7 = (EVP_CIPHER_CTX *)((int)&pEVar7->cipher + 1);
              *(byte *)puVar9 = *(byte *)puVar24 ^ *(byte *)ppEVar2;
              puVar9 = puVar18;
              puVar24 = (undefined4 *)((int)puVar24 + 1);
            } while ((undefined4 *)((int)local_34 + (int)param_4) != puVar18);
          }
          else {
            uVar16 = 0;
            puVar9 = param_4 + -1;
            uVar6 = ((uint)puVar9 >> 2) + 1;
            local_30 = (undefined4 *)(uVar6 * 4);
            do {
              local_34[uVar16] = local_38[uVar16] ^ *(uint *)(local_3c->oiv + uVar16 * 4 + -0x10);
              uVar16 = uVar16 + 1;
            } while (uVar16 < uVar6);
            pbVar17 = (byte *)((int)local_34 + ((uint)puVar9 & 0xfffffffc) + 4);
            pbVar21 = (byte *)((int)local_38 + ((uint)puVar9 & 0xfffffffc) + 4);
            puVar14 = local_3c->oiv + (((uint)puVar9 & 0xfffffffc) - 0xc);
            if (((param_4 != (undefined4 *)(uVar6 * 4)) &&
                (*pbVar17 = *pbVar21 ^ *puVar14, param_4 + -uVar6 != (undefined4 *)0x1)) &&
               (pbVar17[1] = pbVar21[1] ^ puVar14[1], param_4 + -uVar6 != (undefined4 *)0x2)) {
              pbVar17[2] = pbVar21[2] ^ puVar14[2];
            }
          }
          goto LAB_081a96d2;
        }
        goto LAB_081a8f08;
      }
      pEVar15 = *(ENGINE **)(local_50[2]->iv + 4);
      iVar10 = *(int *)(local_50[2]->iv + 8);
      iVar12 = *(int *)(local_50[2]->iv + 0xc);
      local_3c->cipher = *(EVP_CIPHER **)local_50[2]->iv;
      local_3c->engine = pEVar15;
      local_3c->buf_len = iVar12;
      local_3c->encrypt = iVar10;
      local_30 = (undefined4 *)((uint)local_30 & 0xfffffff0);
      if (local_30 == (undefined4 *)0x0) {
LAB_081a92a4:
        pEVar11 = local_3c;
        local_50[2]->num = (int)param_4;
        bVar3 = local_3c->oiv[1];
        bVar25 = (bVar3 & 2) == 0;
        if (bVar25) {
          *(uint *)(puVar20 + -4) =
               (uint)(in_NT & 1) * 0x4000 | (uint)(bVar26 & 1) * 0x400 | (uint)(in_IF & 1) * 0x200 |
               (uint)(in_TF & 1) * 0x100 | (uint)bVar25 * 0x40 | (uint)(in_AF & 1) * 0x10 |
               (uint)(POPCOUNT(bVar3 & 2) == '\0') * 4 | (uint)(in_ID & 1) * 0x200000 |
               (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
               (uint)(in_AC & 1) * 0x40000;
          uVar6 = *(uint *)(puVar20 + -4);
          *(undefined4 **)(puVar20 + -4) = puVar5;
          xcrypt_ecb(1,pEVar11->oiv,pEVar11->iv,pEVar11,pEVar11);
          puVar5 = *(undefined4 **)(puVar20 + -4);
          *(uint *)(puVar20 + -4) =
               (uint)((uVar6 & 0x4000) != 0) * 0x4000 | (uint)((uVar6 & 0x800) != 0) * 0x800 |
               (uint)((uVar6 & 0x400) != 0) * 0x400 | (uint)((uVar6 & 0x200) != 0) * 0x200 |
               (uint)((uVar6 & 0x100) != 0) * 0x100 | (uint)((uVar6 & 0x80) != 0) * 0x80 |
               (uint)((uVar6 & 0x40) != 0) * 0x40 | (uint)((uVar6 & 0x10) != 0) * 0x10 |
               (uint)((uVar6 & 4) != 0) * 4 | (uint)((uVar6 & 1) != 0) |
               (uint)((uVar6 & 0x200000) != 0) * 0x200000 | (uint)((uVar6 & 0x40000) != 0) * 0x40000
          ;
          pEVar11 = local_3c;
          if ((((local_38 < &local_3c->engine && local_3c < local_38 + 1 ||
                local_34 < &local_3c->engine && local_3c < local_34 + 1) ||
               param_4 < (undefined4 *)0x7) || local_34 < local_38 + 1 && local_38 < local_34 + 1)
             || ((((uint)local_38 | (uint)local_3c | (uint)local_34) & 3) != 0)) {
            pEVar7 = local_3c;
            puVar9 = local_34;
            puVar24 = local_38;
            do {
              puVar18 = (undefined4 *)((int)puVar9 + 1);
              bVar26 = *(byte *)puVar24 ^ *(byte *)&pEVar7->cipher;
              *(byte *)puVar9 = bVar26;
              *(byte *)&pEVar7->cipher = bVar26;
              pEVar7 = (EVP_CIPHER_CTX *)((int)&pEVar7->cipher + 1);
              puVar9 = puVar18;
              puVar24 = (undefined4 *)((int)puVar24 + 1);
            } while ((undefined4 *)((int)local_34 + (int)param_4) != puVar18);
          }
          else {
            puVar9 = param_4 + -1;
            uVar6 = 0;
            uVar16 = ((uint)puVar9 >> 2) + 1;
            local_30 = (undefined4 *)(uVar16 * 4);
            do {
              uVar23 = *(uint *)(local_3c->oiv + uVar6 * 4 + -0x10) ^ local_38[uVar6];
              local_34[uVar6] = uVar23;
              *(uint *)(local_3c->oiv + uVar6 * 4 + -0x10) = uVar23;
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar16);
            pbVar17 = (byte *)((int)local_34 + ((uint)puVar9 & 0xfffffffc) + 4);
            pbVar21 = (byte *)((int)local_38 + ((uint)puVar9 & 0xfffffffc) + 4);
            puVar14 = local_3c->oiv + (((uint)puVar9 & 0xfffffffc) - 0xc);
            if (param_4 != (undefined4 *)(uVar16 * 4)) {
              bVar3 = *pbVar21;
              bVar26 = *puVar14;
              *pbVar17 = bVar3 ^ bVar26;
              *puVar14 = bVar3 ^ bVar26;
              if (param_4 + -uVar16 != (undefined4 *)0x1) {
                bVar3 = pbVar21[1];
                bVar26 = puVar14[1];
                pbVar17[1] = bVar3 ^ bVar26;
                puVar14[1] = bVar3 ^ bVar26;
                if (param_4 + -uVar16 != (undefined4 *)0x2) {
                  bVar3 = pbVar21[2];
                  bVar26 = puVar14[2];
                  pbVar17[2] = bVar3 ^ bVar26;
                  puVar14[2] = bVar3 ^ bVar26;
                }
              }
            }
          }
        }
        else {
          local_3c->oiv[1] = (uchar)(bVar3 & 0xfffffffd);
          *(uint *)(puVar20 + -4) =
               (uint)(in_NT & 1) * 0x4000 | (uint)(bVar26 & 1) * 0x400 | (uint)(in_IF & 1) * 0x200 |
               (uint)(in_TF & 1) * 0x100 | (uint)((bVar3 & 0xfd) == 0) * 0x40 |
               (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT(bVar3 & 0xfffffffd) & 1U) == 0) * 4 |
               (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
               (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
          uVar6 = *(uint *)(puVar20 + -4);
          *(undefined4 **)(puVar20 + -4) = puVar5;
          xcrypt_ecb(1,pEVar11->oiv,pEVar11->iv,pEVar11,pEVar11);
          puVar5 = *(undefined4 **)(puVar20 + -4);
          puVar14 = local_3c->oiv + 1;
          *puVar14 = *puVar14 | 2;
          *(uint *)(puVar20 + -4) =
               (uint)((uVar6 & 0x4000) != 0) * 0x4000 | (uint)((uVar6 & 0x400) != 0) * 0x400 |
               (uint)((uVar6 & 0x200) != 0) * 0x200 | (uint)((uVar6 & 0x100) != 0) * 0x100 |
               (uint)((char)*puVar14 < '\0') * 0x80 | (uint)(*puVar14 == 0) * 0x40 |
               (uint)((uVar6 & 0x10) != 0) * 0x10 | (uint)((POPCOUNT(*puVar14) & 1U) == 0) * 4 |
               (uint)((uVar6 & 0x200000) != 0) * 0x200000 | (uint)((uVar6 & 0x40000) != 0) * 0x40000
          ;
          pEVar11 = local_3c;
          if ((((local_3c < local_34 + 1 && local_34 < &local_3c->engine ||
                local_3c < local_38 + 1 && local_38 < &local_3c->engine) ||
               param_4 < (undefined4 *)0x7) || local_34 < local_38 + 1 && local_38 < local_34 + 1)
             || ((((uint)local_3c | (uint)local_38 | (uint)local_34) & 3) != 0)) {
            local_30 = puVar5;
            pEVar7 = local_3c;
            puVar9 = local_34;
            do {
              puVar24 = local_38;
              local_38 = (undefined4 *)((int)local_38 + 1);
              pEVar13 = (EVP_CIPHER_CTX *)((int)&pEVar7->cipher + 1);
              bVar26 = *(byte *)puVar24;
              *(byte *)puVar9 = *(byte *)&pEVar7->cipher ^ bVar26;
              *(byte *)&pEVar7->cipher = bVar26;
              pEVar7 = pEVar13;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
            } while (pEVar13 != (EVP_CIPHER_CTX *)(local_3c->oiv + (int)(param_4 + -4)));
          }
          else {
            puVar9 = param_4 + -1;
            uVar6 = 0;
            uVar16 = ((uint)puVar9 >> 2) + 1;
            do {
              uVar23 = local_38[uVar6];
              local_34[uVar6] = *(uint *)(local_3c->oiv + uVar6 * 4 + -0x10) ^ uVar23;
              *(uint *)(local_3c->oiv + uVar6 * 4 + -0x10) = uVar23;
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar16);
            puVar14 = local_3c->oiv + (((uint)puVar9 & 0xfffffffc) - 0xc);
            pbVar17 = (byte *)((int)local_34 + ((uint)puVar9 & 0xfffffffc) + 4);
            local_30 = (undefined4 *)((int)local_38 + ((uint)puVar9 & 0xfffffffc) + 4);
            if (uVar16 * 4 - (int)param_4 != 0) {
              bVar26 = *(byte *)local_30;
              *pbVar17 = bVar26 ^ *puVar14;
              *puVar14 = bVar26;
              if (param_4 + -uVar16 != (undefined4 *)0x1) {
                bVar26 = *(byte *)((int)local_30 + 1);
                pbVar17[1] = bVar26 ^ puVar14[1];
                puVar14[1] = bVar26;
                if (param_4 + -uVar16 != (undefined4 *)0x2) {
                  bVar26 = *(byte *)((int)local_30 + 2);
                  pbVar17[2] = puVar14[2] ^ bVar26;
                  puVar14[2] = bVar26;
                }
              }
            }
          }
        }
      }
      else {
        while( true ) {
          pEVar11 = local_3c;
          puVar9 = local_38;
          if (local_44 != 0) {
            uVar6 = 0;
            do {
              puVar5[uVar6] = local_38[uVar6];
              uVar6 = uVar6 + 1;
              puVar9 = puVar5;
            } while ((uint)local_30 >> 2 != uVar6);
          }
          local_38 = (undefined4 *)((int)local_30 + (int)local_38);
          uVar6 = (uint)local_30 >> 4;
          *(undefined4 **)(puVar20 + -4) = puVar5;
          xcrypt_cfb(uVar6,pEVar11,pEVar11->oiv,pEVar11->iv,puVar9,puVar5);
          puVar5 = *(undefined4 **)(puVar20 + -4);
          if (local_40 == 0) {
            local_34 = (undefined4 *)((int)local_30 + (int)local_34);
            puVar5 = local_34;
          }
          else {
            uVar6 = 0;
            local_50[0] = pEVar11;
            do {
              local_34[uVar6] = puVar5[uVar6];
              uVar6 = uVar6 + 1;
            } while ((uint)local_30 >> 2 != uVar6);
            local_34 = (undefined4 *)((int)local_30 + (int)local_34);
          }
          param_4 = (undefined4 *)((int)param_4 - (int)local_30);
          if (param_4 < &DAT_00000010) break;
          if (local_3c != pEVar11) {
            pEVar15 = pEVar11->engine;
            iVar10 = pEVar11->encrypt;
            iVar12 = pEVar11->buf_len;
            local_3c->cipher = pEVar11->cipher;
            local_3c->engine = pEVar15;
            local_3c->encrypt = iVar10;
            local_3c->buf_len = iVar12;
          }
          local_30 = (undefined4 *)0x200;
        }
        if (param_4 != (undefined4 *)0x0) {
          if (local_3c != pEVar11) {
            pEVar15 = pEVar11->engine;
            iVar10 = pEVar11->encrypt;
            iVar12 = pEVar11->buf_len;
            local_3c->cipher = pEVar11->cipher;
            local_3c->engine = pEVar15;
            local_3c->encrypt = iVar10;
            local_3c->buf_len = iVar12;
          }
          goto LAB_081a92a4;
        }
      }
      pEVar22 = pEVar11->cipher;
      pEVar15 = pEVar11->engine;
      iVar10 = pEVar11->encrypt;
      iVar12 = pEVar11->buf_len;
      goto LAB_081a96dd;
    }
    if (uVar6 != 1) {
LAB_081a8f08:
      uVar4 = 0;
      goto LAB_081a8f10;
    }
    do {
      pEVar11 = local_3c;
      puVar9 = local_38;
      if (local_44 != 0) {
        uVar6 = 0;
        do {
          puVar5[uVar6] = local_38[uVar6];
          uVar6 = uVar6 + 1;
          puVar9 = puVar5;
        } while ((uint)local_30 >> 2 != uVar6);
      }
      local_38 = (undefined4 *)((int)local_30 + (int)local_38);
      uVar6 = (uint)local_30 >> 4;
      *(undefined4 **)(puVar20 + -4) = puVar5;
      xcrypt_ecb(uVar6,pEVar11->oiv,pEVar11->iv,puVar9,puVar5);
      puVar5 = *(undefined4 **)(puVar20 + -4);
      if (local_40 == 0) {
        local_34 = (undefined4 *)((int)local_30 + (int)local_34);
        puVar5 = local_34;
      }
      else {
        uVar6 = 0;
        do {
          local_34[uVar6] = puVar5[uVar6];
          uVar6 = uVar6 + 1;
        } while ((uint)local_30 >> 2 != uVar6);
        local_34 = (undefined4 *)((int)local_30 + (int)local_34);
      }
      param_4 = (undefined4 *)((int)param_4 - (int)local_30);
      local_30 = (undefined4 *)0x200;
    } while (param_4 != (undefined4 *)0x0);
  }
  if ((local_40 != 0) && (iVar10 = ((uint)local_50[1] >> 2) - 1, (uint)local_50[1] >> 2 != 0)) {
    do {
      iVar10 = iVar10 + -1;
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    } while (iVar10 != -1);
  }
  local_3c->cipher = (EVP_CIPHER *)0x0;
  local_3c->engine = (ENGINE *)0x0;
  local_3c->encrypt = 0;
  local_3c->buf_len = 0;
  uVar4 = 1;
LAB_081a8f10:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar19 + -4) = &UNK_081a9916;
    __stack_chk_fail();
  }
  return uVar4;
}

