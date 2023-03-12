
undefined4
ssl_parse_clienthello_tlsext
          (int *param_1,uchar **param_2,int param_3,int param_4,undefined4 *param_5)

{
  byte bVar1;
  uchar uVar2;
  uchar uVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  void *pvVar8;
  size_t sVar9;
  OCSP_RESPID *a;
  _STACK *st;
  X509_EXTENSIONS *pXVar10;
  uint uVar11;
  uchar *puVar12;
  uchar *puVar13;
  uchar *puVar14;
  byte *__s2;
  int iVar15;
  uchar *puVar16;
  uint uVar17;
  char *pcVar18;
  uchar *puVar19;
  uint uVar20;
  uint uVar21;
  uchar *local_2c [2];
  
  iVar15 = param_1[0x16];
  uVar11 = param_1[0x61];
  iVar7 = param_1[0x40];
  puVar14 = *param_2;
  param_1[0x49] = 0;
  param_1[0x4a] = -1;
  *(undefined4 *)(iVar15 + 0x41c) = 0;
  param_1[0x61] = uVar11 & 0xfffffffc;
  puVar12 = (uchar *)(param_4 + -2 + param_3);
  if (iVar7 << 0x19 < 0) {
    if (puVar12 <= puVar14) goto LAB_0005697e;
    if (puVar14 + 2 <= (uchar *)(param_4 + -4 + param_3)) {
      if (CONCAT11(puVar14[2],puVar14[3]) == 0) {
        puVar13 = puVar14 + CONCAT11(puVar14[4],puVar14[5]) + 6;
        puVar12 = (uchar *)(param_3 + param_4);
        if (puVar13 <= puVar12) {
          if ((param_1[0x44] >> 8 == 3) && (0x302 < param_1[0x44])) {
            if ((puVar12 == puVar13 + 0x22) &&
               (iVar7 = memcmp(puVar13,PTR_kSafariExtensionsBlock_20212_00056f48,0x12), iVar7 == 0))
            {
              iVar7 = memcmp(puVar13 + 0x12,PTR_kSafariTLS12ExtensionsBlock_20213_00056f4c,0x10);
joined_r0x00056c24:
              if (iVar7 == 0) {
                *(undefined *)(iVar15 + 0x420) = 1;
              }
            }
          }
          else if (puVar12 == puVar13 + 0x12) {
            iVar7 = memcmp(puVar13,PTR_kSafariExtensionsBlock_20212_00056f48,0x12);
            goto joined_r0x00056c24;
          }
        }
      }
    }
  }
  else if (puVar12 <= puVar14) goto LAB_0005697e;
  puVar12 = puVar14 + 2;
  if (puVar12 <= (uchar *)((param_4 - (uint)CONCAT11(*puVar14,puVar14[1])) + param_3)) {
    puVar13 = (uchar *)(param_3 + param_4 + -4);
    if (puVar13 < puVar12) {
      bVar5 = false;
LAB_00056ece:
      *param_2 = puVar12;
    }
    else {
      puVar16 = puVar14 + 6;
      uVar11 = (uint)CONCAT11(puVar14[4],puVar14[5]);
      sVar4 = CONCAT11(puVar14[2],puVar14[3]);
      if ((uchar *)(param_3 + param_4) < puVar16 + uVar11) goto LAB_0005697e;
      bVar6 = false;
      bVar5 = false;
      puVar14 = puVar16 + uVar11;
      puVar19 = puVar12;
      do {
        puVar12 = puVar14;
        if ((code *)param_1[0x46] != (code *)0x0) {
          (*(code *)param_1[0x46])(param_1,0,sVar4,puVar16,uVar11,param_1[0x47]);
        }
        if (sVar4 == 0) {
          if (uVar11 < 2) {
LAB_00056aec:
            *param_5 = 0x32;
            return 0;
          }
          uVar20 = uVar11 - 2 & 0xffff;
          uVar11 = (uint)CONCAT11(puVar19[4],puVar19[5]);
          if (uVar20 < uVar11) goto LAB_00056aec;
          if (3 < uVar11) {
            iVar7 = uVar11 - 3;
            bVar1 = puVar19[6];
            uVar11 = (uint)CONCAT11(puVar19[7],puVar19[8]);
            if (iVar7 < (int)uVar11) goto LAB_00056aec;
            uVar21 = param_1[0x49];
            __s2 = puVar19 + 9;
            while( true ) {
              uVar17 = (uint)bVar1;
              if ((uVar21 == 0) && (uVar17 == 0)) {
                if (param_1[0x1b] == 0) {
                  iVar15 = param_1[0x30];
                  if (*(int *)(iVar15 + 0xd0) != 0) goto LAB_00056aec;
                  if (0xff < uVar11) {
                    *param_5 = 0x70;
                    return 0;
                  }
                  pvVar8 = CRYPTO_malloc(uVar11 + 1,"t1_lib.c",0x423);
                  *(void **)(iVar15 + 0xd0) = pvVar8;
                  if (pvVar8 == (void *)0x0) goto LAB_00056e12;
                  memcpy(*(void **)(param_1[0x30] + 0xd0),__s2,uVar11);
                  *(undefined *)(*(int *)(param_1[0x30] + 0xd0) + uVar11) = 0;
                  pcVar18 = *(char **)(param_1[0x30] + 0xd0);
                  sVar9 = strlen(pcVar18);
                  if (uVar11 != sVar9) {
                    CRYPTO_free(pcVar18);
                    *(undefined4 *)(param_1[0x30] + 0xd0) = 0;
                    *param_5 = 0x70;
                    return 0;
                  }
                  param_1[0x49] = 1;
                  uVar21 = 1;
                }
                else {
                  pcVar18 = *(char **)(param_1[0x30] + 0xd0);
                  if ((pcVar18 != (char *)0x0) && (sVar9 = strlen(pcVar18), sVar9 == uVar11)) {
                    iVar15 = strncmp(pcVar18,(char *)__s2,uVar11);
                    uVar17 = count_leading_zeroes(iVar15);
                    uVar17 = uVar17 >> 5;
                  }
                  param_1[0x49] = uVar17;
                  uVar21 = uVar17;
                }
              }
              uVar11 = iVar7 - uVar11;
              if ((int)uVar11 < 4) break;
              iVar7 = uVar11 - 3;
              bVar1 = *__s2;
              uVar11 = (uint)CONCAT11(__s2[1],__s2[2]);
              __s2 = __s2 + 3;
              if (iVar7 < (int)uVar11) goto LAB_00056aec;
            }
          }
          if (uVar11 != 0) goto LAB_00056aec;
          puVar12 = puVar19 + uVar20 + 6;
        }
        else if (sVar4 == 0xc) {
          if (((uVar11 == 0) || (uVar20 = (uint)puVar19[4], uVar20 != uVar11 - 1)) ||
             (param_1[0x69] != 0)) goto LAB_00056aec;
          pvVar8 = CRYPTO_malloc(uVar11,"t1_lib.c",0x454);
          param_1[0x69] = (int)pvVar8;
          if (pvVar8 == (void *)0x0) {
            return 0xffffffff;
          }
          memcpy(pvVar8,puVar19 + 5,uVar20);
          *(undefined *)(param_1[0x69] + uVar20) = 0;
          sVar9 = strlen((char *)param_1[0x69]);
          if (uVar20 != sVar9) goto LAB_00056aec;
        }
        else if (sVar4 == 0xb) {
          if (*param_1 == 0xfeff) {
LAB_00056ba2:
            if (sVar4 == 0x3374) {
              if (*(int *)(param_1[0x16] + 0x2b4) == 0) {
                *(undefined4 *)(param_1[0x16] + 0x41c) = 1;
              }
            }
            else if ((sVar4 == 0xe) &&
                    (iVar7 = ssl_parse_clienthello_use_srtp_ext(param_1,puVar16,uVar11,param_5),
                    iVar7 != 0)) {
              return 0;
            }
          }
          else {
            uVar20 = (uint)puVar19[4];
            if (uVar11 - 1 != uVar20) goto LAB_00056aec;
            if (param_1[0x1b] == 0) {
              iVar7 = param_1[0x30];
              if (*(void **)(iVar7 + 0xd8) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar7 + 0xd8));
                iVar7 = param_1[0x30];
                *(undefined4 *)(iVar7 + 0xd8) = 0;
              }
              *(undefined4 *)(iVar7 + 0xd4) = 0;
              pvVar8 = CRYPTO_malloc(uVar11 - 1,"t1_lib.c",0x475);
              *(void **)(iVar7 + 0xd8) = pvVar8;
              if (pvVar8 == (void *)0x0) goto LAB_00056e12;
              iVar7 = param_1[0x30];
              *(uint *)(iVar7 + 0xd4) = uVar20;
              memcpy(*(void **)(iVar7 + 0xd8),puVar19 + 5,uVar20);
            }
          }
        }
        else if (sVar4 == 10) {
          if (*param_1 != 0xfeff) {
            sVar9 = uVar11 - 2;
            if ((sVar9 != (uint)puVar19[5] + (uint)puVar19[4] * 0x100) || (sVar9 == 0))
            goto LAB_00056aec;
            if (param_1[0x1b] == 0) {
              iVar7 = param_1[0x30];
              if (*(int *)(iVar7 + 0xe0) != 0) goto LAB_00056aec;
              *(undefined4 *)(iVar7 + 0xdc) = 0;
              pvVar8 = CRYPTO_malloc(sVar9,"t1_lib.c",0x49a);
              *(void **)(iVar7 + 0xe0) = pvVar8;
              if (pvVar8 == (void *)0x0) goto LAB_00056e12;
              iVar7 = param_1[0x30];
              *(size_t *)(iVar7 + 0xdc) = sVar9;
              memcpy(*(void **)(iVar7 + 0xe0),puVar19 + 6,sVar9);
            }
          }
        }
        else if (sVar4 == 0x23) {
          if (((code *)param_1[0x58] != (code *)0x0) &&
             (iVar7 = (*(code *)param_1[0x58])(param_1,puVar16,uVar11,param_1[0x59]), iVar7 == 0)) {
LAB_00056e12:
            *param_5 = 0x50;
            return 0;
          }
        }
        else if (sVar4 == -0xff) {
          iVar7 = ssl_parse_clienthello_renegotiate_ext(param_1,puVar16,uVar11,param_5);
          if (iVar7 == 0) {
            return 0;
          }
          bVar5 = true;
        }
        else if (sVar4 == 0xd) {
          if (uVar11 < 2) {
            bVar6 = true;
          }
          if (bVar6) goto LAB_00056aec;
          uVar20 = uVar11 - 2 & 0xffff;
          if (((uVar20 != CONCAT11(puVar19[4],puVar19[5])) || ((uVar11 - 2 & 1) != 0)) ||
             (iVar7 = tls1_process_sigalgs(param_1,puVar19 + 6,uVar20), iVar7 == 0))
          goto LAB_00056aec;
          puVar12 = puVar19 + 6 + uVar20;
          bVar6 = true;
        }
        else if (sVar4 == 5) {
          if ((*param_1 != 0xfeff) && (*(int *)(param_1[0x39] + 0x13c) != 0)) {
            if (uVar11 < 5) goto LAB_00056aec;
            bVar1 = puVar19[4];
            param_1[0x4a] = (uint)bVar1;
            if (bVar1 == 1) {
              uVar20 = uVar11 - 3 & 0xffff;
              uVar21 = (uint)CONCAT11(puVar19[5],puVar19[6]);
              if (uVar20 < uVar21) goto LAB_00057014;
              puVar12 = puVar19 + 7;
              if (uVar21 != 0) {
                if (uVar21 < 4) goto LAB_00057014;
                puVar14 = puVar19 + 9;
                uVar17 = (uint)CONCAT11(puVar19[7],puVar19[8]);
                uVar20 = (uVar11 - 5) - uVar17;
                iVar7 = uVar21 + (-2 - uVar17);
                while( true ) {
                  if (iVar7 < 0) goto LAB_00057014;
                  uVar20 = uVar20 & 0xffff;
                  local_2c[0] = puVar14;
                  a = d2i_OCSP_RESPID((OCSP_RESPID **)0x0,local_2c,uVar17);
                  puVar12 = puVar14 + uVar17;
                  if (a == (OCSP_RESPID *)0x0) goto LAB_00057014;
                  if (puVar12 != local_2c[0]) {
                    OCSP_RESPID_free(a);
                    *param_5 = 0x32;
                    return 0;
                  }
                  st = (_STACK *)param_1[0x4c];
                  if (st == (_STACK *)0x0) {
                    st = sk_new_null();
                    param_1[0x4c] = (int)st;
                    if (st == (_STACK *)0x0) {
                      OCSP_RESPID_free(a);
                      *param_5 = 0x50;
                      return 0;
                    }
                  }
                  puVar14 = puVar12 + 2;
                  iVar15 = sk_push(st,a);
                  if (iVar15 == 0) {
                    OCSP_RESPID_free(a);
                    *param_5 = 0x50;
                    return 0;
                  }
                  if (iVar7 < 1) break;
                  if (iVar7 < 4) goto LAB_00057014;
                  uVar17 = (uint)CONCAT11(*puVar12,puVar12[1]);
                  uVar20 = uVar20 + (-2 - uVar17);
                  iVar7 = iVar7 + (-2 - uVar17);
                }
                if (uVar20 < 2) goto LAB_00057014;
              }
              uVar2 = *puVar12;
              uVar3 = puVar12[1];
              puVar12 = puVar12 + 2;
              uVar11 = uVar20 - 2 & 0xffff;
              if (uVar11 != CONCAT11(uVar2,uVar3)) {
LAB_00057014:
                *param_5 = 0x32;
                return 0;
              }
              local_2c[0] = puVar12;
              if (uVar11 != 0) {
                if ((_STACK *)param_1[0x4d] != (_STACK *)0x0) {
                  sk_pop_free((_STACK *)param_1[0x4d],X509_EXTENSION_free + 1);
                }
                pXVar10 = d2i_X509_EXTENSIONS((X509_EXTENSIONS **)0x0,local_2c,uVar11);
                param_1[0x4d] = (int)pXVar10;
                if ((pXVar10 == (X509_EXTENSIONS *)0x0) ||
                   (local_2c[0] != puVar12 + CONCAT11(uVar2,uVar3))) goto LAB_00057014;
                puVar12 = puVar12 + uVar11;
              }
            }
            else {
              param_1[0x4a] = -1;
              puVar12 = puVar19 + (uVar11 - 1 & 0xffff) + 5;
            }
          }
        }
        else {
          if (sVar4 != 0xf) goto LAB_00056ba2;
          if (puVar19[4] == '\x01') {
            param_1[0x61] = param_1[0x61] | 1;
          }
          else {
            if (puVar19[4] != '\x02') {
              *param_5 = 0x2f;
              return 0;
            }
            param_1[0x61] = param_1[0x61] | 3;
          }
        }
        if (puVar13 < puVar12) goto LAB_00056ece;
        puVar16 = puVar12 + 4;
        uVar11 = (uint)CONCAT11(puVar12[2],puVar12[3]);
        sVar4 = CONCAT11(*puVar12,puVar12[1]);
        puVar14 = puVar16 + uVar11;
        puVar19 = puVar12;
      } while (puVar16 + uVar11 <= (uchar *)(param_3 + param_4));
    }
    if (bVar5) {
      return 1;
    }
  }
LAB_0005697e:
  if ((param_1[100] != 0) && ((param_1[0x40] & 0x40000U) == 0)) {
    *param_5 = 0x28;
    ERR_put_error(0x14,0x12e,0x152,"t1_lib.c",0x59f);
    return 0;
  }
  return 1;
}

