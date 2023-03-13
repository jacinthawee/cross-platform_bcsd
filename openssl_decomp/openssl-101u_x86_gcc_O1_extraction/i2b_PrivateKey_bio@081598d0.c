
int i2b_PrivateKey_bio(BIO *out,EVP_PKEY *pk)

{
  int iVar1;
  uchar uVar2;
  rsa_st *prVar3;
  BIGNUM *pBVar4;
  dsa_st *pdVar5;
  uint uVar6;
  int iVar7;
  undefined *data;
  int iVar8;
  int iVar9;
  int iVar10;
  uchar *puVar11;
  uchar *puVar12;
  undefined uVar13;
  size_t sVar14;
  uchar *puVar15;
  uchar *puVar16;
  undefined4 *__s;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  int in_GS_OFFSET;
  uchar *local_48;
  int local_38;
  undefined4 local_24;
  
  local_24 = 0;
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  if (pk->type == 0x74) {
    pdVar5 = (pk->pkey).dsa;
    uVar6 = BN_num_bits(pdVar5->p);
    if (((((uVar6 & 7) == 0) && (iVar7 = BN_num_bits(pdVar5->q), iVar7 == 0xa0)) &&
        (iVar7 = BN_num_bits(pdVar5->g), iVar7 <= (int)uVar6)) &&
       (iVar7 = BN_num_bits(pdVar5->priv_key), iVar7 < 0xa1)) {
      local_24 = 0x32535344;
      if (uVar6 != 0) {
        uVar13 = 0x22;
        iVar18 = 0x2200;
        iVar7 = (uVar6 + 7 >> 3) * 2 + 0x40;
        goto LAB_08159940;
      }
    }
    else {
      ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x222);
    }
  }
  else if ((pk->type == 6) && (uVar6 = check_bitlen_rsa(), uVar6 != 0)) {
    uVar13 = 0xa4;
    iVar18 = 0xa400;
    iVar7 = (uVar6 + 0xf >> 4) * 5 + 4 + (uVar6 + 7 >> 3) * 2;
LAB_08159940:
    iVar7 = iVar7 + 0x10;
    data = (undefined *)CRYPTO_malloc(iVar7,"pvkfmt.c",0x1e8);
    if (data != (undefined *)0x0) {
      data[5] = uVar13;
      *data = 7;
      puVar15 = data + 0x10;
      data[1] = 2;
      data[2] = 0;
      data[3] = 0;
      data[4] = 0;
      data[6] = 0;
      data[7] = 0;
      data[8] = (char)local_24;
      data[0xc] = (char)uVar6;
      data[9] = (char)((uint)local_24 >> 8);
      data[0xb] = (char)((uint)local_24 >> 0x18);
      data[10] = (char)((uint)local_24 >> 0x10);
      data[0xd] = (char)(uVar6 >> 8);
      data[0xf] = (char)(uVar6 >> 0x18);
      data[0xe] = (char)(uVar6 >> 0x10);
      prVar3 = (pk->pkey).rsa;
      if (iVar18 == 0x2200) {
        iVar8 = BN_num_bits((BIGNUM *)prVar3->engine);
        iVar18 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar18 = iVar8 + 0xe;
        }
        pBVar4 = (BIGNUM *)prVar3->engine;
        iVar18 = iVar18 >> 3;
        iVar9 = BN_num_bits(pBVar4);
        iVar8 = iVar9 + 7;
        iVar19 = iVar9 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        iVar19 = iVar19 >> 3;
        BN_bn2bin(pBVar4,puVar15);
        puVar16 = data + iVar19 + 0xf;
        if (iVar8 < 0) {
          iVar8 = iVar9 + 0x16;
        }
        puVar12 = puVar15;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar12;
            puVar11 = puVar12 + 1;
            *puVar12 = *puVar16;
            *puVar16 = uVar2;
            puVar12 = puVar11;
            puVar16 = puVar16 + -1;
          } while (puVar15 + (iVar8 >> 4) != puVar11);
        }
        puVar15 = puVar15 + iVar19;
        puVar16 = puVar15;
        if ((0 < iVar18) && (sVar14 = iVar18 - iVar19, 0 < (int)sVar14)) {
          puVar16 = puVar15 + sVar14;
          memset(puVar15,0,sVar14);
        }
        pBVar4 = prVar3->n;
        iVar9 = BN_num_bits(pBVar4);
        iVar8 = iVar9 + 7;
        iVar19 = iVar9 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        iVar19 = iVar19 >> 3;
        BN_bn2bin(pBVar4,puVar16);
        puVar15 = puVar16 + iVar19 + -1;
        if (iVar8 < 0) {
          iVar8 = iVar9 + 0x16;
        }
        puVar12 = puVar16;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar12;
            puVar11 = puVar12 + 1;
            *puVar12 = *puVar15;
            *puVar15 = uVar2;
            puVar12 = puVar11;
            puVar15 = puVar15 + -1;
          } while (puVar16 + (iVar8 >> 4) != puVar11);
        }
        puVar16 = puVar16 + iVar19;
        sVar14 = 0x14 - iVar19;
        puVar15 = puVar16;
        if (0 < (int)sVar14) {
          puVar15 = puVar16 + sVar14;
          memset(puVar16,0,sVar14);
        }
        pBVar4 = prVar3->e;
        iVar9 = BN_num_bits(pBVar4);
        iVar8 = iVar9 + 7;
        iVar19 = iVar9 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        iVar19 = iVar19 >> 3;
        BN_bn2bin(pBVar4,puVar15);
        puVar16 = puVar15 + iVar19 + -1;
        if (iVar8 < 0) {
          iVar8 = iVar9 + 0x16;
        }
        puVar12 = puVar15;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar12;
            puVar11 = puVar12 + 1;
            *puVar12 = *puVar16;
            *puVar16 = uVar2;
            puVar12 = puVar11;
            puVar16 = puVar16 + -1;
          } while (puVar11 != puVar15 + (iVar8 >> 4));
        }
        puVar15 = puVar15 + iVar19;
        puVar16 = puVar15;
        if ((0 < iVar18) && (sVar14 = iVar18 - iVar19, 0 < (int)sVar14)) {
          puVar16 = puVar15 + sVar14;
          memset(puVar15,0,sVar14);
        }
        pBVar4 = prVar3->p;
        iVar19 = BN_num_bits(pBVar4);
        iVar18 = iVar19 + 7;
        iVar8 = iVar19 + 0xe;
        if (-1 < iVar18) {
          iVar8 = iVar18;
        }
        iVar8 = iVar8 >> 3;
        BN_bn2bin(pBVar4,puVar16);
        puVar15 = puVar16 + iVar8 + -1;
        if (iVar18 < 0) {
          iVar18 = iVar19 + 0x16;
        }
        puVar12 = puVar16;
        if (0 < iVar18 >> 4) {
          do {
            uVar2 = *puVar12;
            puVar11 = puVar12 + 1;
            *puVar12 = *puVar15;
            *puVar15 = uVar2;
            puVar12 = puVar11;
            puVar15 = puVar15 + -1;
          } while (puVar11 != puVar16 + (iVar18 >> 4));
        }
        __s = (undefined4 *)(puVar16 + iVar8);
        sVar14 = 0x14 - iVar8;
        puVar17 = __s;
        if (0 < (int)sVar14) {
          puVar17 = (undefined4 *)((int)__s + sVar14);
          memset(__s,0,sVar14);
        }
        *puVar17 = 0xffffffff;
        puVar17[1] = 0xffffffff;
        puVar17[2] = 0xffffffff;
        puVar17[3] = 0xffffffff;
        puVar17[4] = 0xffffffff;
        puVar17[5] = 0xffffffff;
      }
      else {
        iVar8 = BN_num_bits(prVar3->n);
        iVar18 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar18 = iVar8 + 0xe;
        }
        iVar8 = BN_num_bits(prVar3->n);
        pBVar4 = prVar3->e;
        iVar9 = iVar8 + 0xf >> 4;
        iVar10 = BN_num_bits(pBVar4);
        iVar8 = iVar10 + 7;
        iVar19 = iVar10 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        iVar19 = iVar19 >> 3;
        BN_bn2bin(pBVar4,puVar15);
        puVar16 = data + iVar19 + 0xf;
        if (iVar8 < 0) {
          iVar8 = iVar10 + 0x16;
        }
        puVar12 = puVar15;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar12;
            puVar11 = puVar12 + 1;
            *puVar12 = *puVar16;
            *puVar16 = uVar2;
            puVar12 = puVar11;
            puVar16 = puVar16 + -1;
          } while (puVar15 + (iVar8 >> 4) != puVar11);
        }
        puVar15 = puVar15 + iVar19;
        sVar14 = 4 - iVar19;
        local_48 = puVar15;
        if (0 < (int)sVar14) {
          local_48 = puVar15 + sVar14;
          memset(puVar15,0,sVar14);
        }
        pBVar4 = prVar3->n;
        iVar10 = BN_num_bits(pBVar4);
        iVar8 = iVar10 + 7;
        BN_bn2bin(pBVar4,local_48);
        iVar19 = iVar10 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        if (iVar8 < 0) {
          iVar8 = iVar10 + 0x16;
        }
        puVar15 = local_48 + (iVar19 >> 3) + -1;
        puVar16 = local_48;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar16;
            puVar12 = puVar16 + 1;
            *puVar16 = *puVar15;
            *puVar15 = uVar2;
            puVar16 = puVar12;
            puVar15 = puVar15 + -1;
          } while (puVar12 != local_48 + (iVar8 >> 4));
        }
        local_48 = local_48 + (iVar19 >> 3);
        pBVar4 = prVar3->p;
        iVar10 = BN_num_bits(pBVar4);
        iVar8 = iVar10 + 7;
        iVar19 = iVar10 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        iVar19 = iVar19 >> 3;
        BN_bn2bin(pBVar4,local_48);
        puVar15 = local_48 + iVar19 + -1;
        if (iVar8 < 0) {
          iVar8 = iVar10 + 0x16;
        }
        puVar16 = local_48;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar16;
            puVar12 = puVar16 + 1;
            *puVar16 = *puVar15;
            *puVar15 = uVar2;
            puVar16 = puVar12;
            puVar15 = puVar15 + -1;
          } while (local_48 + (iVar8 >> 4) != puVar12);
        }
        local_48 = local_48 + iVar19;
        if (iVar9 < 1) {
          pBVar4 = prVar3->q;
          iVar10 = BN_num_bits(pBVar4);
          iVar19 = iVar10 + 7;
          iVar8 = iVar10 + 0xe;
          if (-1 < iVar19) {
            iVar8 = iVar19;
          }
          iVar8 = iVar8 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + iVar8 + -1;
          if (iVar19 < 0) {
            iVar19 = iVar10 + 0x16;
          }
          iVar19 = iVar19 >> 4;
          if (0 < iVar19) goto LAB_08159c17;
          local_48 = local_48 + iVar8;
LAB_0815a308:
          pBVar4 = prVar3->dmp1;
          iVar10 = BN_num_bits(pBVar4);
          iVar19 = iVar10 + 7;
          iVar8 = iVar10 + 0xe;
          if (-1 < iVar19) {
            iVar8 = iVar19;
          }
          iVar8 = iVar8 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + iVar8 + -1;
          if (iVar19 < 0) {
            iVar19 = iVar10 + 0x16;
          }
          iVar19 = iVar19 >> 4;
          if (0 < iVar19) goto LAB_08159cd0;
          local_48 = local_48 + iVar8;
LAB_0815a380:
          pBVar4 = prVar3->dmq1;
          iVar19 = BN_num_bits(pBVar4);
          iVar8 = iVar19 + 7;
          local_38 = iVar19 + 0xe;
          if (-1 < iVar8) {
            local_38 = iVar8;
          }
          local_38 = local_38 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + local_38 + -1;
          if (iVar8 < 0) {
            iVar8 = iVar19 + 0x16;
          }
          iVar8 = iVar8 >> 4;
          if (0 < iVar8) goto LAB_08159d90;
LAB_08159db6:
          local_48 = local_48 + local_38;
          if (0 < iVar9) goto LAB_08159dce;
          pBVar4 = prVar3->iqmp;
          iVar10 = BN_num_bits(pBVar4);
          iVar19 = iVar10 + 7;
          iVar8 = iVar10 + 0xe;
          if (-1 < iVar19) {
            iVar8 = iVar19;
          }
          iVar8 = iVar8 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + iVar8 + -1;
          if (iVar19 < 0) {
            iVar19 = iVar10 + 0x16;
          }
          iVar19 = iVar19 >> 4;
          if (0 < iVar19) goto LAB_08159e50;
          puVar15 = local_48 + iVar8;
        }
        else {
          sVar14 = iVar9 - iVar19;
          if (0 < (int)sVar14) {
            memset(local_48,0,sVar14);
            local_48 = local_48 + sVar14;
          }
          pBVar4 = prVar3->q;
          iVar10 = BN_num_bits(pBVar4);
          iVar19 = iVar10 + 7;
          iVar8 = iVar10 + 0xe;
          if (-1 < iVar19) {
            iVar8 = iVar19;
          }
          iVar8 = iVar8 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + iVar8 + -1;
          if (iVar19 < 0) {
            iVar19 = iVar10 + 0x16;
          }
          iVar19 = iVar19 >> 4;
          if (iVar19 < 1) {
            local_48 = local_48 + iVar8;
          }
          else {
LAB_08159c17:
            puVar16 = local_48;
            do {
              uVar2 = *puVar16;
              puVar12 = puVar16 + 1;
              *puVar16 = *puVar15;
              *puVar15 = uVar2;
              puVar16 = puVar12;
              puVar15 = puVar15 + -1;
            } while (local_48 + iVar19 != puVar12);
            local_48 = local_48 + iVar8;
            if (iVar9 < 1) goto LAB_0815a308;
          }
          sVar14 = iVar9 - iVar8;
          if (0 < (int)sVar14) {
            memset(local_48,0,sVar14);
            local_48 = local_48 + sVar14;
          }
          pBVar4 = prVar3->dmp1;
          iVar10 = BN_num_bits(pBVar4);
          iVar19 = iVar10 + 7;
          iVar8 = iVar10 + 0xe;
          if (-1 < iVar19) {
            iVar8 = iVar19;
          }
          iVar8 = iVar8 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + iVar8 + -1;
          if (iVar19 < 0) {
            iVar19 = iVar10 + 0x16;
          }
          iVar19 = iVar19 >> 4;
          if (iVar19 < 1) {
            local_48 = local_48 + iVar8;
          }
          else {
LAB_08159cd0:
            puVar16 = local_48;
            do {
              uVar2 = *puVar16;
              puVar12 = puVar16 + 1;
              *puVar16 = *puVar15;
              *puVar15 = uVar2;
              puVar16 = puVar12;
              puVar15 = puVar15 + -1;
            } while (local_48 + iVar19 != puVar12);
            local_48 = local_48 + iVar8;
            if (iVar9 < 1) goto LAB_0815a380;
          }
          sVar14 = iVar9 - iVar8;
          if (0 < (int)sVar14) {
            memset(local_48,0,sVar14);
            local_48 = local_48 + sVar14;
          }
          pBVar4 = prVar3->dmq1;
          iVar19 = BN_num_bits(pBVar4);
          iVar8 = iVar19 + 7;
          local_38 = iVar19 + 0xe;
          if (-1 < iVar8) {
            local_38 = iVar8;
          }
          local_38 = local_38 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + local_38 + -1;
          if (iVar8 < 0) {
            iVar8 = iVar19 + 0x16;
          }
          iVar8 = iVar8 >> 4;
          if (0 < iVar8) {
LAB_08159d90:
            puVar16 = local_48;
            do {
              uVar2 = *puVar16;
              puVar12 = puVar16 + 1;
              *puVar16 = *puVar15;
              *puVar15 = uVar2;
              puVar16 = puVar12;
              puVar15 = puVar15 + -1;
            } while (local_48 + iVar8 != puVar12);
            goto LAB_08159db6;
          }
          local_48 = local_48 + local_38;
LAB_08159dce:
          sVar14 = iVar9 - local_38;
          if (0 < (int)sVar14) {
            memset(local_48,0,sVar14);
            local_48 = local_48 + sVar14;
          }
          pBVar4 = prVar3->iqmp;
          iVar10 = BN_num_bits(pBVar4);
          iVar19 = iVar10 + 7;
          iVar8 = iVar10 + 0xe;
          if (-1 < iVar19) {
            iVar8 = iVar19;
          }
          iVar8 = iVar8 >> 3;
          BN_bn2bin(pBVar4,local_48);
          puVar15 = local_48 + iVar8 + -1;
          if (iVar19 < 0) {
            iVar19 = iVar10 + 0x16;
          }
          iVar19 = iVar19 >> 4;
          if (iVar19 < 1) {
            local_48 = local_48 + iVar8;
          }
          else {
LAB_08159e50:
            puVar16 = local_48;
            do {
              uVar2 = *puVar16;
              puVar12 = puVar16 + 1;
              *puVar16 = *puVar15;
              *puVar15 = uVar2;
              puVar16 = puVar12;
              puVar15 = puVar15 + -1;
            } while (local_48 + iVar19 != puVar12);
            local_48 = local_48 + iVar8;
            puVar15 = local_48;
            if (iVar9 < 1) goto LAB_08159ea3;
          }
          sVar14 = iVar9 - iVar8;
          puVar15 = local_48;
          if (0 < (int)sVar14) {
            puVar15 = local_48 + sVar14;
            memset(local_48,0,sVar14);
          }
        }
LAB_08159ea3:
        pBVar4 = prVar3->d;
        iVar9 = BN_num_bits(pBVar4);
        iVar8 = iVar9 + 7;
        iVar19 = iVar9 + 0xe;
        if (-1 < iVar8) {
          iVar19 = iVar8;
        }
        iVar19 = iVar19 >> 3;
        BN_bn2bin(pBVar4,puVar15);
        puVar16 = puVar15 + iVar19 + -1;
        if (iVar8 < 0) {
          iVar8 = iVar9 + 0x16;
        }
        puVar12 = puVar15;
        if (0 < iVar8 >> 4) {
          do {
            uVar2 = *puVar12;
            puVar11 = puVar12 + 1;
            *puVar12 = *puVar16;
            *puVar16 = uVar2;
            puVar12 = puVar11;
            puVar16 = puVar16 + -1;
          } while (puVar15 + (iVar8 >> 4) != puVar11);
        }
        if ((0 < iVar18 >> 3) && (sVar14 = (iVar18 >> 3) - iVar19, 0 < (int)sVar14)) {
          memset(puVar15 + iVar19,0,sVar14);
        }
      }
      if (-1 < iVar7) {
        iVar18 = BIO_write(out,data,iVar7);
        CRYPTO_free(data);
        if (iVar18 == iVar7) goto LAB_08159f6a;
      }
    }
  }
  iVar7 = -1;
LAB_08159f6a:
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}

