
int __regparm3
i2b_PVK_constprop_4(undefined4 *param_1_00,int *param_2_00,int param_3,code *param_1,void *param_2)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uchar *puVar8;
  size_t sVar9;
  EVP_MD *type;
  EVP_CIPHER *cipher;
  int iVar10;
  undefined *puVar11;
  uchar uVar12;
  int iVar13;
  uchar *puVar14;
  int num;
  uchar *puVar15;
  undefined4 *__s;
  undefined4 *puVar16;
  uchar *puVar17;
  int in_GS_OFFSET;
  uchar *local_4f4;
  int local_4e4;
  EVP_MD_CTX local_4d8;
  EVP_CIPHER_CTX local_4c0;
  uchar local_434 [5];
  undefined4 local_42f;
  undefined4 local_42b;
  undefined2 local_427;
  undefined local_425;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_CIPHER_CTX_init(&local_4c0);
  local_4d8.digest = (EVP_MD *)0x0;
  if (*param_2_00 == 0x74) {
    iVar2 = param_2_00[5];
    uVar4 = BN_num_bits(*(BIGNUM **)(iVar2 + 0xc));
    if (((((uVar4 & 7) == 0) && (iVar3 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x10)), iVar3 == 0xa0)) &&
        (iVar3 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x14)), iVar3 <= (int)uVar4)) &&
       (iVar2 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x1c)), iVar2 < 0xa1)) {
      local_4d8.digest = (EVP_MD *)0x32535344;
      if (uVar4 != 0) {
        iVar2 = (uVar4 + 7 >> 3) * 2 + 0x40;
        goto LAB_08157526;
      }
    }
    else {
      ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x222);
    }
  }
  else if ((*param_2_00 == 6) && (iVar2 = check_bitlen_rsa(), iVar2 != 0)) {
    iVar2 = (iVar2 + 0xfU >> 4) * 5 + 4 + (iVar2 + 7U >> 3) * 2;
LAB_08157526:
    iVar3 = iVar2 + 0x10;
    if (-1 < iVar3) {
      num = (-(uint)(param_3 == 0) & 0xfffffff0) + 0x28 + iVar3;
      if (param_1_00 == (undefined4 *)0x0) goto LAB_08157bd0;
      puVar11 = (undefined *)*param_1_00;
      if (puVar11 == (undefined *)0x0) {
        puVar11 = (undefined *)CRYPTO_malloc(num,"pvkfmt.c",0x330);
        if (puVar11 == (undefined *)0x0) {
          ERR_put_error(9,0x89,0x41,"pvkfmt.c",0x332);
          num = -1;
          goto LAB_08157bd0;
        }
        *param_1_00 = puVar11;
      }
      *puVar11 = 0x1e;
      puVar11[1] = 0xf1;
      puVar11[2] = 0xb5;
      puVar11[3] = 0xb0;
      puVar11[4] = 0;
      puVar11[5] = 0;
      puVar11[6] = 0;
      puVar11[7] = 0;
      if (*param_2_00 == 0x74) {
        puVar11[8] = 2;
        puVar11[9] = 0;
        puVar11[10] = 0;
        puVar11[0xb] = 0;
      }
      else {
        puVar11[8] = 1;
        puVar11[9] = 0;
        puVar11[10] = 0;
        puVar11[0xb] = 0;
      }
      puVar14 = puVar11 + 0x18;
      puVar11[0xd] = 0;
      puVar11[0xe] = 0;
      puVar11[0xf] = 0;
      puVar11[0x11] = 0;
      puVar11[0x12] = 0;
      puVar11[0x13] = 0;
      puVar11[0xc] = param_3 != 0;
      puVar11[0x14] = (char)iVar3;
      puVar11[0x10] = ~-(param_3 == 0) & 0x10;
      puVar11[0x15] = (char)((uint)iVar3 >> 8);
      puVar11[0x16] = (char)((uint)iVar3 >> 0x10);
      puVar11[0x17] = (char)((uint)iVar3 >> 0x18);
      if (param_3 == 0) {
        iVar3 = *param_2_00;
        local_4f4 = (uchar *)0x0;
joined_r0x08157c16:
        if (iVar3 == 0x74) {
          local_4d8.digest = (EVP_MD *)0x0;
          iVar3 = param_2_00[5];
          uVar4 = BN_num_bits(*(BIGNUM **)(iVar3 + 0xc));
          if ((((uVar4 & 7) == 0) &&
              (iVar10 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x10)), iVar10 == 0xa0)) &&
             ((iVar10 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x14)), iVar10 <= (int)uVar4 &&
              (iVar3 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x1c)), iVar3 < 0xa1)))) {
            local_4d8.digest = (EVP_MD *)0x32535344;
            if (uVar4 != 0) {
              uVar12 = '\"';
              iVar3 = 0x2200;
              goto LAB_08157622;
            }
          }
          else {
            ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x222);
          }
        }
        else {
          local_4d8.digest = (EVP_MD *)0x0;
          if ((iVar3 == 6) && (uVar4 = check_bitlen_rsa(), uVar4 != 0)) {
            uVar12 = 0xa4;
            iVar3 = 0xa400;
LAB_08157622:
            *puVar14 = '\a';
            puVar14[1] = '\x02';
            puVar14[2] = '\0';
            puVar14[3] = '\0';
            puVar14[4] = '\0';
            puVar14[5] = uVar12;
            puVar14[6] = '\0';
            puVar14[7] = '\0';
            puVar14[0xc] = (uchar)uVar4;
            puVar14[8] = (uchar)local_4d8.digest;
            puVar14[0xb] = (uchar)((uint)local_4d8.digest >> 0x18);
            puVar14[9] = (uchar)((uint)local_4d8.digest >> 8);
            puVar14[0xd] = (uchar)(uVar4 >> 8);
            puVar14[10] = (uchar)((uint)local_4d8.digest >> 0x10);
            puVar14[0xe] = (uchar)(uVar4 >> 0x10);
            puVar15 = puVar14 + 0x10;
            puVar14[0xf] = (uchar)(uVar4 >> 0x18);
            if (iVar3 == 0x2200) {
              iVar3 = param_2_00[5];
              iVar5 = BN_num_bits(*(BIGNUM **)(iVar3 + 0xc));
              iVar10 = iVar5 + 7;
              if (iVar5 + 7 < 0) {
                iVar10 = iVar5 + 0xe;
              }
              pBVar1 = *(BIGNUM **)(iVar3 + 0xc);
              iVar10 = iVar10 >> 3;
              iVar7 = BN_num_bits(pBVar1);
              iVar5 = iVar7 + 7;
              iVar6 = iVar7 + 0xe;
              if (-1 < iVar5) {
                iVar6 = iVar5;
              }
              iVar6 = iVar6 >> 3;
              BN_bn2bin(pBVar1,puVar15);
              puVar14 = puVar14 + iVar6 + 0xf;
              if (iVar5 < 0) {
                iVar5 = iVar7 + 0x16;
              }
              puVar17 = puVar15;
              if (0 < iVar5 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar14;
                  *puVar14 = uVar12;
                  puVar17 = puVar8;
                  puVar14 = puVar14 + -1;
                } while (puVar15 + (iVar5 >> 4) != puVar8);
              }
              puVar15 = puVar15 + iVar6;
              puVar14 = puVar15;
              if ((0 < iVar10) && (sVar9 = iVar10 - iVar6, 0 < (int)sVar9)) {
                puVar14 = puVar15 + sVar9;
                memset(puVar15,0,sVar9);
              }
              pBVar1 = *(BIGNUM **)(iVar3 + 0x10);
              iVar7 = BN_num_bits(pBVar1);
              iVar5 = iVar7 + 7;
              iVar6 = iVar7 + 0xe;
              if (-1 < iVar5) {
                iVar6 = iVar5;
              }
              iVar6 = iVar6 >> 3;
              BN_bn2bin(pBVar1,puVar14);
              puVar15 = puVar14 + iVar6 + -1;
              if (iVar5 < 0) {
                iVar5 = iVar7 + 0x16;
              }
              puVar17 = puVar14;
              if (0 < iVar5 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar15;
                  *puVar15 = uVar12;
                  puVar17 = puVar8;
                  puVar15 = puVar15 + -1;
                } while (puVar14 + (iVar5 >> 4) != puVar8);
              }
              puVar14 = puVar14 + iVar6;
              sVar9 = 0x14 - iVar6;
              puVar15 = puVar14;
              if (0 < (int)sVar9) {
                puVar15 = puVar14 + sVar9;
                memset(puVar14,0,sVar9);
              }
              pBVar1 = *(BIGNUM **)(iVar3 + 0x14);
              iVar7 = BN_num_bits(pBVar1);
              iVar5 = iVar7 + 7;
              iVar6 = iVar7 + 0xe;
              if (-1 < iVar5) {
                iVar6 = iVar5;
              }
              iVar6 = iVar6 >> 3;
              BN_bn2bin(pBVar1,puVar15);
              puVar14 = puVar15 + iVar6 + -1;
              if (iVar5 < 0) {
                iVar5 = iVar7 + 0x16;
              }
              puVar17 = puVar15;
              if (0 < iVar5 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar14;
                  *puVar14 = uVar12;
                  puVar17 = puVar8;
                  puVar14 = puVar14 + -1;
                } while (puVar8 != puVar15 + (iVar5 >> 4));
              }
              puVar15 = puVar15 + iVar6;
              puVar14 = puVar15;
              if ((0 < iVar10) && (sVar9 = iVar10 - iVar6, 0 < (int)sVar9)) {
                puVar14 = puVar15 + sVar9;
                memset(puVar15,0,sVar9);
              }
              pBVar1 = *(BIGNUM **)(iVar3 + 0x1c);
              iVar10 = BN_num_bits(pBVar1);
              iVar5 = iVar10 + 7;
              iVar3 = iVar10 + 0xe;
              if (-1 < iVar5) {
                iVar3 = iVar5;
              }
              iVar3 = iVar3 >> 3;
              BN_bn2bin(pBVar1,puVar14);
              puVar15 = puVar14 + iVar3 + -1;
              iVar10 = iVar10 + 0x16;
              if (-1 < iVar5) {
                iVar10 = iVar5;
              }
              puVar17 = puVar14;
              if (0 < iVar10 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar15;
                  *puVar15 = uVar12;
                  puVar17 = puVar8;
                  puVar15 = puVar15 + -1;
                } while (puVar14 + (iVar10 >> 4) != puVar8);
              }
              __s = (undefined4 *)(puVar14 + iVar3);
              sVar9 = 0x14 - iVar3;
              puVar16 = __s;
              if (0 < (int)sVar9) {
                puVar16 = (undefined4 *)((int)__s + sVar9);
                memset(__s,0,sVar9);
              }
              *puVar16 = 0xffffffff;
              puVar16[1] = 0xffffffff;
              puVar16[2] = 0xffffffff;
              puVar16[3] = 0xffffffff;
              puVar16[4] = 0xffffffff;
              puVar16[5] = 0xffffffff;
            }
            else {
              iVar3 = param_2_00[5];
              iVar5 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x10));
              iVar10 = iVar5 + 7;
              if (iVar5 + 7 < 0) {
                iVar10 = iVar5 + 0xe;
              }
              iVar5 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x10));
              pBVar1 = *(BIGNUM **)(iVar3 + 0x14);
              iVar6 = iVar5 + 0xf >> 4;
              iVar7 = BN_num_bits(pBVar1);
              iVar13 = iVar7 + 7;
              iVar5 = iVar7 + 0xe;
              if (-1 < iVar13) {
                iVar5 = iVar13;
              }
              iVar5 = iVar5 >> 3;
              BN_bn2bin(pBVar1,puVar15);
              puVar14 = puVar14 + iVar5 + 0xf;
              iVar7 = iVar7 + 0x16;
              if (-1 < iVar13) {
                iVar7 = iVar13;
              }
              puVar17 = puVar15;
              if (0 < iVar7 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar14;
                  *puVar14 = uVar12;
                  puVar17 = puVar8;
                  puVar14 = puVar14 + -1;
                } while (puVar15 + (iVar7 >> 4) != puVar8);
              }
              puVar15 = puVar15 + iVar5;
              sVar9 = 4 - iVar5;
              puVar14 = puVar15;
              if (0 < (int)sVar9) {
                puVar14 = puVar15 + sVar9;
                memset(puVar15,0,sVar9);
              }
              pBVar1 = *(BIGNUM **)(iVar3 + 0x10);
              iVar13 = BN_num_bits(pBVar1);
              iVar5 = iVar13 + 7;
              BN_bn2bin(pBVar1,puVar14);
              iVar7 = iVar13 + 0xe;
              if (-1 < iVar5) {
                iVar7 = iVar5;
              }
              if (iVar5 < 0) {
                iVar5 = iVar13 + 0x16;
              }
              puVar15 = puVar14 + (iVar7 >> 3) + -1;
              puVar17 = puVar14;
              if (0 < iVar5 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar15;
                  *puVar15 = uVar12;
                  puVar17 = puVar8;
                  puVar15 = puVar15 + -1;
                } while (puVar8 != puVar14 + (iVar5 >> 4));
              }
              puVar14 = puVar14 + (iVar7 >> 3);
              pBVar1 = *(BIGNUM **)(iVar3 + 0x1c);
              iVar7 = BN_num_bits(pBVar1);
              iVar13 = iVar7 + 7;
              iVar5 = iVar7 + 0xe;
              if (-1 < iVar13) {
                iVar5 = iVar13;
              }
              iVar5 = iVar5 >> 3;
              BN_bn2bin(pBVar1,puVar14);
              puVar15 = puVar14 + iVar5 + -1;
              iVar7 = iVar7 + 0x16;
              if (-1 < iVar13) {
                iVar7 = iVar13;
              }
              puVar17 = puVar14;
              if (0 < iVar7 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar15;
                  *puVar15 = uVar12;
                  puVar17 = puVar8;
                  puVar15 = puVar15 + -1;
                } while (puVar14 + (iVar7 >> 4) != puVar8);
              }
              puVar14 = puVar14 + iVar5;
              if (iVar6 < 1) {
                pBVar1 = *(BIGNUM **)(iVar3 + 0x20);
                iVar7 = BN_num_bits(pBVar1);
                iVar13 = iVar7 + 7;
                iVar5 = iVar7 + 0xe;
                if (-1 < iVar13) {
                  iVar5 = iVar13;
                }
                iVar5 = iVar5 >> 3;
                BN_bn2bin(pBVar1,puVar14);
                puVar15 = puVar14 + iVar5 + -1;
                iVar7 = iVar7 + 0x16;
                if (-1 < iVar13) {
                  iVar7 = iVar13;
                }
                iVar7 = iVar7 >> 4;
                if (0 < iVar7) goto LAB_08157893;
                puVar14 = puVar14 + iVar5;
LAB_08158100:
                pBVar1 = *(BIGNUM **)(iVar3 + 0x24);
                iVar7 = BN_num_bits(pBVar1);
                iVar13 = iVar7 + 7;
                iVar5 = iVar7 + 0xe;
                if (-1 < iVar13) {
                  iVar5 = iVar13;
                }
                iVar5 = iVar5 >> 3;
                BN_bn2bin(pBVar1,puVar14);
                puVar15 = puVar14 + iVar5 + -1;
                iVar7 = iVar7 + 0x16;
                if (-1 < iVar13) {
                  iVar7 = iVar13;
                }
                iVar7 = iVar7 >> 4;
                if (0 < iVar7) goto LAB_08157932;
                puVar14 = puVar14 + iVar5;
LAB_0815815b:
                pBVar1 = *(BIGNUM **)(iVar3 + 0x28);
                iVar7 = BN_num_bits(pBVar1);
                iVar5 = iVar7 + 7;
                local_4e4 = iVar7 + 0xe;
                if (-1 < iVar5) {
                  local_4e4 = iVar5;
                }
                local_4e4 = local_4e4 >> 3;
                BN_bn2bin(pBVar1,puVar14);
                puVar15 = puVar14 + local_4e4 + -1;
                if (iVar5 < 0) {
                  iVar5 = iVar7 + 0x16;
                }
                iVar5 = iVar5 >> 4;
                if (0 < iVar5) goto LAB_081579d2;
LAB_081579f6:
                puVar14 = puVar14 + local_4e4;
                if (0 < iVar6) goto LAB_08157a04;
                pBVar1 = *(BIGNUM **)(iVar3 + 0x2c);
                iVar7 = BN_num_bits(pBVar1);
                iVar13 = iVar7 + 7;
                iVar5 = iVar7 + 0xe;
                if (-1 < iVar13) {
                  iVar5 = iVar13;
                }
                iVar5 = iVar5 >> 3;
                BN_bn2bin(pBVar1,puVar14);
                puVar15 = puVar14 + iVar5 + -1;
                iVar7 = iVar7 + 0x16;
                if (-1 < iVar13) {
                  iVar7 = iVar13;
                }
                iVar7 = iVar7 >> 4;
                if (0 < iVar7) goto LAB_08157a70;
                puVar15 = puVar14 + iVar5;
              }
              else {
                sVar9 = iVar6 - iVar5;
                puVar17 = puVar14;
                if (0 < (int)sVar9) {
                  puVar17 = puVar14 + sVar9;
                  memset(puVar14,0,sVar9);
                }
                pBVar1 = *(BIGNUM **)(iVar3 + 0x20);
                iVar7 = BN_num_bits(pBVar1);
                iVar13 = iVar7 + 7;
                iVar5 = iVar7 + 0xe;
                if (-1 < iVar13) {
                  iVar5 = iVar13;
                }
                iVar5 = iVar5 >> 3;
                BN_bn2bin(pBVar1,puVar17);
                iVar7 = iVar7 + 0x16;
                if (-1 < iVar13) {
                  iVar7 = iVar13;
                }
                puVar15 = puVar17 + iVar5 + -1;
                iVar7 = iVar7 >> 4;
                puVar14 = puVar17;
                if (iVar7 < 1) {
                  puVar14 = puVar17 + iVar5;
                }
                else {
LAB_08157893:
                  puVar17 = puVar14;
                  do {
                    uVar12 = *puVar17;
                    puVar8 = puVar17 + 1;
                    *puVar17 = *puVar15;
                    *puVar15 = uVar12;
                    puVar17 = puVar8;
                    puVar15 = puVar15 + -1;
                  } while (puVar14 + iVar7 != puVar8);
                  puVar14 = puVar14 + iVar5;
                  if (iVar6 < 1) goto LAB_08158100;
                }
                sVar9 = iVar6 - iVar5;
                puVar17 = puVar14;
                if (0 < (int)sVar9) {
                  puVar17 = puVar14 + sVar9;
                  memset(puVar14,0,sVar9);
                }
                pBVar1 = *(BIGNUM **)(iVar3 + 0x24);
                iVar7 = BN_num_bits(pBVar1);
                iVar13 = iVar7 + 7;
                iVar5 = iVar7 + 0xe;
                if (-1 < iVar13) {
                  iVar5 = iVar13;
                }
                iVar5 = iVar5 >> 3;
                BN_bn2bin(pBVar1,puVar17);
                iVar7 = iVar7 + 0x16;
                if (-1 < iVar13) {
                  iVar7 = iVar13;
                }
                puVar15 = puVar17 + iVar5 + -1;
                iVar7 = iVar7 >> 4;
                puVar14 = puVar17;
                if (iVar7 < 1) {
                  puVar14 = puVar17 + iVar5;
                }
                else {
LAB_08157932:
                  puVar17 = puVar14;
                  do {
                    uVar12 = *puVar17;
                    puVar8 = puVar17 + 1;
                    *puVar17 = *puVar15;
                    *puVar15 = uVar12;
                    puVar17 = puVar8;
                    puVar15 = puVar15 + -1;
                  } while (puVar14 + iVar7 != puVar8);
                  puVar14 = puVar14 + iVar5;
                  if (iVar6 < 1) goto LAB_0815815b;
                }
                sVar9 = iVar6 - iVar5;
                puVar17 = puVar14;
                if (0 < (int)sVar9) {
                  puVar17 = puVar14 + sVar9;
                  memset(puVar14,0,sVar9);
                }
                pBVar1 = *(BIGNUM **)(iVar3 + 0x28);
                iVar7 = BN_num_bits(pBVar1);
                iVar5 = iVar7 + 7;
                local_4e4 = iVar7 + 0xe;
                if (-1 < iVar5) {
                  local_4e4 = iVar5;
                }
                local_4e4 = local_4e4 >> 3;
                BN_bn2bin(pBVar1,puVar17);
                puVar15 = puVar17 + local_4e4 + -1;
                if (iVar5 < 0) {
                  iVar5 = iVar7 + 0x16;
                }
                iVar5 = iVar5 >> 4;
                puVar14 = puVar17;
                if (0 < iVar5) {
LAB_081579d2:
                  puVar17 = puVar14;
                  do {
                    uVar12 = *puVar17;
                    puVar8 = puVar17 + 1;
                    *puVar17 = *puVar15;
                    *puVar15 = uVar12;
                    puVar17 = puVar8;
                    puVar15 = puVar15 + -1;
                  } while (puVar14 + iVar5 != puVar8);
                  goto LAB_081579f6;
                }
                puVar14 = puVar17 + local_4e4;
LAB_08157a04:
                sVar9 = iVar6 - local_4e4;
                puVar17 = puVar14;
                if (0 < (int)sVar9) {
                  puVar17 = puVar14 + sVar9;
                  memset(puVar14,0,sVar9);
                }
                pBVar1 = *(BIGNUM **)(iVar3 + 0x2c);
                iVar7 = BN_num_bits(pBVar1);
                iVar13 = iVar7 + 7;
                iVar5 = iVar7 + 0xe;
                if (-1 < iVar13) {
                  iVar5 = iVar13;
                }
                iVar5 = iVar5 >> 3;
                BN_bn2bin(pBVar1,puVar17);
                iVar7 = iVar7 + 0x16;
                if (-1 < iVar13) {
                  iVar7 = iVar13;
                }
                puVar15 = puVar17 + iVar5 + -1;
                iVar7 = iVar7 >> 4;
                puVar14 = puVar17;
                if (iVar7 < 1) {
                  puVar14 = puVar17 + iVar5;
                }
                else {
LAB_08157a70:
                  puVar17 = puVar14;
                  do {
                    uVar12 = *puVar17;
                    puVar8 = puVar17 + 1;
                    *puVar17 = *puVar15;
                    *puVar15 = uVar12;
                    puVar17 = puVar8;
                    puVar15 = puVar15 + -1;
                  } while (puVar14 + iVar7 != puVar8);
                  puVar14 = puVar14 + iVar5;
                  puVar15 = puVar14;
                  if (iVar6 < 1) goto LAB_08157abd;
                }
                sVar9 = iVar6 - iVar5;
                puVar15 = puVar14;
                if (0 < (int)sVar9) {
                  puVar15 = puVar14 + sVar9;
                  memset(puVar14,0,sVar9);
                }
              }
LAB_08157abd:
              pBVar1 = *(BIGNUM **)(iVar3 + 0x18);
              iVar5 = BN_num_bits(pBVar1);
              iVar6 = iVar5 + 7;
              iVar3 = iVar5 + 0xe;
              if (-1 < iVar6) {
                iVar3 = iVar6;
              }
              iVar3 = iVar3 >> 3;
              BN_bn2bin(pBVar1,puVar15);
              puVar14 = puVar15 + iVar3 + -1;
              iVar5 = iVar5 + 0x16;
              if (-1 < iVar6) {
                iVar5 = iVar6;
              }
              puVar17 = puVar15;
              if (0 < iVar5 >> 4) {
                do {
                  uVar12 = *puVar17;
                  puVar8 = puVar17 + 1;
                  *puVar17 = *puVar14;
                  *puVar14 = uVar12;
                  puVar17 = puVar8;
                  puVar14 = puVar14 + -1;
                } while (puVar15 + (iVar5 >> 4) != puVar8);
              }
              if ((0 < iVar10 >> 3) && (sVar9 = (iVar10 >> 3) - iVar3, 0 < (int)sVar9)) {
                memset(puVar15 + iVar3,0,sVar9);
              }
            }
          }
        }
        if (param_3 == 0) goto LAB_08157bd0;
        if (param_1 == (code *)0x0) {
          sVar9 = PEM_def_callback(local_420,0x400,1,param_2);
        }
        else {
          sVar9 = (*param_1)(local_420,0x400,1,param_2);
        }
        if ((int)sVar9 < 1) {
          ERR_put_error(9,0x89,0x68,"pvkfmt.c",0x353);
        }
        else {
          EVP_MD_CTX_init(&local_4d8);
          type = EVP_sha1();
          iVar3 = EVP_DigestInit_ex(&local_4d8,type,(ENGINE *)0x0);
          if (((iVar3 != 0) && (iVar3 = EVP_DigestUpdate(&local_4d8,local_4f4,0x10), iVar3 != 0)) &&
             (iVar3 = EVP_DigestUpdate(&local_4d8,local_420,sVar9), iVar3 != 0)) {
            iVar3 = EVP_DigestFinal_ex(&local_4d8,local_434,(uint *)0x0);
            if (iVar3 != 0) {
              EVP_MD_CTX_cleanup(&local_4d8);
              if (param_3 == 1) {
                local_42f = 0;
                local_42b = 0;
                local_427 = 0;
                local_425 = 0;
              }
              cipher = EVP_rc4();
              local_4f4 = local_4f4 + 0x18;
              iVar3 = EVP_EncryptInit_ex(&local_4c0,cipher,(ENGINE *)0x0,local_434,(uchar *)0x0);
              if (iVar3 != 0) {
                OPENSSL_cleanse(local_434,0x14);
                iVar2 = EVP_DecryptUpdate(&local_4c0,local_4f4,(int *)&local_4d8,local_4f4,iVar2 + 8
                                         );
                if ((iVar2 != 0) &&
                   (iVar2 = EVP_DecryptFinal_ex(&local_4c0,local_4f4 + (int)local_4d8.digest,
                                                (int *)&local_4d8), iVar2 != 0)) {
                  EVP_CIPHER_CTX_cleanup(&local_4c0);
                  goto LAB_08157bd0;
                }
              }
              goto LAB_08157bba;
            }
          }
          EVP_MD_CTX_cleanup(&local_4d8);
        }
      }
      else {
        iVar3 = RAND_bytes(puVar14,0x10);
        if (0 < iVar3) {
          iVar3 = *param_2_00;
          local_4f4 = puVar14;
          puVar14 = puVar11 + 0x28;
          goto joined_r0x08157c16;
        }
      }
LAB_08157bba:
      EVP_CIPHER_CTX_cleanup(&local_4c0);
      num = -1;
      goto LAB_08157bd0;
    }
  }
  num = -1;
LAB_08157bd0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return num;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

