
int ssl_parse_clienthello_tlsext
              (int *param_1,ushort **param_2,int param_3,int param_4,undefined4 *param_5)

{
  ushort *puVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  void *pvVar8;
  size_t sVar9;
  void *__s1;
  int iVar10;
  OCSP_RESPID *a;
  _STACK *st;
  X509_EXTENSIONS *pXVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  ushort uVar15;
  undefined4 *puVar16;
  ushort *puVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  ushort *puVar21;
  int in_GS_OFFSET;
  byte bVar22;
  undefined1 *__s2;
  int local_54;
  ushort *local_50;
  uint local_4c;
  ushort *local_24;
  int local_20;
  
  bVar22 = 0;
  iVar14 = param_1[0x16];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar21 = *param_2;
  param_1[0x49] = 0;
  param_1[0x4a] = -1;
  *(undefined4 *)(iVar14 + 0x41c) = 0;
  param_1[0x61] = param_1[0x61] & 0xfffffffc;
  puVar1 = (ushort *)(param_3 + -2 + param_4);
  if ((*(byte *)(param_1 + 0x40) & 0x40) == 0) {
    if (puVar21 < puVar1) goto LAB_080b046f;
LAB_080b0425:
    if ((param_1[100] != 0) && ((*(byte *)((int)param_1 + 0x102) & 4) == 0)) {
      *param_5 = 0x28;
      ERR_put_error(0x14,0x12e,0x152,"t1_lib.c",0x59f);
      local_54 = 0;
      goto LAB_080b044c;
    }
  }
  else {
    if (puVar1 <= puVar21) goto LAB_080b0425;
    if ((puVar21 + 1 <= (ushort *)(param_3 + -4 + param_4)) && (puVar21[1] == 0)) {
      __s1 = (void *)((int)puVar21 + (ushort)(puVar21[2] << 8 | puVar21[2] >> 8) + 6);
      pvVar8 = (void *)(param_3 + param_4);
      if (__s1 <= pvVar8) {
        if ((param_1[0x44] >> 8 == 3) && (0x302 < param_1[0x44])) {
          if ((pvVar8 == (void *)((int)__s1 + 0x22U)) &&
             (iVar12 = memcmp(__s1,kSafariExtensionsBlock_17561,0x12), iVar12 == 0)) {
            sVar9 = 0x10;
            __s2 = kSafariTLS12ExtensionsBlock_17562;
            __s1 = (void *)((int)__s1 + 0x12);
LAB_080b0886:
            iVar12 = memcmp(__s1,__s2,sVar9);
            if (iVar12 == 0) {
              *(undefined *)(iVar14 + 0x420) = 1;
            }
          }
        }
        else if (pvVar8 == (void *)((int)__s1 + 0x12U)) {
          sVar9 = 0x12;
          __s2 = kSafariExtensionsBlock_17561;
          goto LAB_080b0886;
        }
      }
    }
LAB_080b046f:
    local_50 = puVar21 + 1;
    if ((ushort *)((param_4 - (uint)(ushort)(*puVar21 << 8 | *puVar21 >> 8)) + param_3) < local_50)
    goto LAB_080b0425;
    puVar1 = (ushort *)(param_3 + -4 + param_4);
    if (local_50 <= puVar1) {
      puVar17 = puVar21 + 3;
      local_4c = (uint)(ushort)(puVar21[2] << 8 | puVar21[2] >> 8);
      uVar7 = puVar21[1] << 8 | puVar21[1] >> 8;
      if ((int)puVar17 + local_4c <= (uint)(param_3 + param_4)) {
        bVar6 = false;
        bVar5 = false;
LAB_080b04da:
        if ((code *)param_1[0x46] != (code *)0x0) {
          (*(code *)param_1[0x46])(param_1,0,uVar7,puVar17,local_4c,param_1[0x47]);
        }
        uVar15 = (ushort)local_4c;
        if (uVar7 == 0) {
          if (1 < uVar15) {
            local_4c = local_4c - 2 & 0xffff;
            uVar13 = (uint)(ushort)(*puVar17 << 8 | *puVar17 >> 8);
            if (uVar13 <= local_4c) {
              if (3 < uVar13) {
                iVar14 = uVar13 - 3;
                cVar2 = *(char *)(local_50 + 3);
                puVar16 = (undefined4 *)((int)local_50 + 9);
                uVar7 = *(ushort *)((int)local_50 + 7) << 8 | *(ushort *)((int)local_50 + 7) >> 8;
                uVar13 = (uint)uVar7;
                if (iVar14 < (int)uVar13) goto LAB_080b0673;
                uVar18 = param_1[0x49];
                while( true ) {
                  if ((uVar18 == 0) && (cVar2 == '\0')) {
                    local_54 = param_1[0x1b];
                    if (local_54 == 0) {
                      iVar12 = param_1[0x30];
                      if (*(int *)(iVar12 + 0xd0) != 0) goto LAB_080b0673;
                      if (0xff < uVar7) {
                        *param_5 = 0x70;
                        goto LAB_080b044c;
                      }
                      pvVar8 = CRYPTO_malloc(uVar13 + 1,"t1_lib.c",0x423);
                      *(void **)(iVar12 + 0xd0) = pvVar8;
                      if (pvVar8 == (void *)0x0) goto LAB_080b0c2d;
                      iVar12 = param_1[0x30];
                      puVar20 = *(undefined4 **)(iVar12 + 0xd0);
                      if (uVar13 < 4) {
                        if (uVar13 != 0) {
                          *(undefined *)puVar20 = *(undefined *)puVar16;
                          if ((uVar13 & 2) == 0) {
                            iVar12 = param_1[0x30];
                          }
                          else {
                            *(undefined2 *)((int)puVar20 + (uVar13 - 2)) =
                                 *(undefined2 *)((int)puVar16 + (uVar13 - 2));
                            iVar12 = param_1[0x30];
                          }
                        }
                      }
                      else {
                        *puVar20 = *puVar16;
                        *(undefined4 *)((int)puVar20 + (uVar13 - 4)) =
                             *(undefined4 *)((int)puVar16 + (uVar13 - 4));
                        iVar12 = (int)puVar20 -
                                 (int)(undefined4 *)((uint)(puVar20 + 1) & 0xfffffffc);
                        puVar19 = (undefined4 *)((int)puVar16 - iVar12);
                        puVar20 = (undefined4 *)((uint)(puVar20 + 1) & 0xfffffffc);
                        for (uVar18 = iVar12 + uVar13 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
                          *puVar20 = *puVar19;
                          puVar19 = puVar19 + (uint)bVar22 * -2 + 1;
                          puVar20 = puVar20 + (uint)bVar22 * -2 + 1;
                        }
                        iVar12 = param_1[0x30];
                      }
                      *(undefined *)(*(int *)(iVar12 + 0xd0) + uVar13) = 0;
                      pcVar4 = *(char **)(param_1[0x30] + 0xd0);
                      sVar9 = strlen(pcVar4);
                      if (uVar13 != sVar9) {
                        CRYPTO_free(pcVar4);
                        *(undefined4 *)(param_1[0x30] + 0xd0) = 0;
                        *param_5 = 0x70;
                        goto LAB_080b044c;
                      }
                      param_1[0x49] = 1;
                      uVar18 = 1;
                    }
                    else {
                      pcVar4 = *(char **)(param_1[0x30] + 0xd0);
                      if ((pcVar4 != (char *)0x0) && (sVar9 = strlen(pcVar4), sVar9 == uVar13)) {
                        iVar12 = strncmp(pcVar4,(char *)puVar16,uVar13);
                        uVar18 = (uint)(iVar12 == 0);
                      }
                      param_1[0x49] = uVar18;
                    }
                  }
                  uVar13 = iVar14 - uVar13;
                  if ((int)uVar13 < 4) break;
                  puVar21 = (ushort *)((int)puVar16 + 1);
                  iVar14 = uVar13 - 3;
                  cVar2 = *(char *)puVar16;
                  puVar16 = (undefined4 *)((int)puVar16 + 3);
                  uVar7 = *puVar21 << 8 | *puVar21 >> 8;
                  uVar13 = (uint)uVar7;
                  if (iVar14 < (int)uVar13) goto LAB_080b0673;
                }
              }
              if (uVar13 == 0) {
                puVar17 = local_50 + 3;
                goto LAB_080b06db;
              }
            }
          }
        }
        else {
          if (uVar7 != 0xc) {
            if (uVar7 == 0xb) {
              if (*param_1 != 0xfeff) {
                bVar3 = *(byte *)(local_50 + 2);
                uVar13 = (uint)bVar3;
                if (uVar13 != local_4c - 1) goto LAB_080b0673;
                if (param_1[0x1b] == 0) {
                  iVar14 = param_1[0x30];
                  if (*(void **)(iVar14 + 0xd8) != (void *)0x0) {
                    CRYPTO_free(*(void **)(iVar14 + 0xd8));
                    iVar14 = param_1[0x30];
                    *(undefined4 *)(iVar14 + 0xd8) = 0;
                  }
                  *(undefined4 *)(iVar14 + 0xd4) = 0;
                  pvVar8 = CRYPTO_malloc(uVar13,"t1_lib.c",0x475);
                  *(void **)(iVar14 + 0xd8) = pvVar8;
                  if (pvVar8 == (void *)0x0) goto LAB_080b0c2d;
                  iVar14 = param_1[0x30];
                  *(uint *)(iVar14 + 0xd4) = uVar13;
                  puVar16 = *(undefined4 **)(iVar14 + 0xd8);
                  if (uVar13 < 4) {
                    if ((uVar13 != 0) &&
                       (*(undefined *)puVar16 = *(undefined *)((int)local_50 + 5), (bVar3 & 2) != 0)
                       ) {
                      *(undefined2 *)((int)puVar16 + (uVar13 - 2)) =
                           *(undefined2 *)((int)local_50 + uVar13 + 3);
                    }
                  }
                  else {
                    *puVar16 = *(undefined4 *)((int)local_50 + 5);
                    *(undefined4 *)((int)puVar16 + (uVar13 - 4)) =
                         *(undefined4 *)((int)local_50 + uVar13 + 1);
                    iVar14 = (int)puVar16 - (int)(undefined4 *)((uint)(puVar16 + 1) & 0xfffffffc);
                    puVar20 = (undefined4 *)((undefined *)((int)local_50 + 5) + -iVar14);
                    puVar16 = (undefined4 *)((uint)(puVar16 + 1) & 0xfffffffc);
                    for (uVar13 = iVar14 + uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                      *puVar16 = *puVar20;
                      puVar20 = puVar20 + (uint)bVar22 * -2 + 1;
                      puVar16 = puVar16 + (uint)bVar22 * -2 + 1;
                    }
                  }
                }
              }
              goto LAB_080b06db;
            }
            if (uVar7 == 10) {
              if (*param_1 != 0xfeff) {
                uVar13 = (uint)CONCAT11(*(undefined *)(local_50 + 2),
                                        *(undefined *)((int)local_50 + 5));
                if ((local_4c - 2 != uVar13) || (uVar13 == 0)) goto LAB_080b0673;
                if (param_1[0x1b] == 0) {
                  iVar14 = param_1[0x30];
                  if (*(int *)(iVar14 + 0xe0) != 0) goto LAB_080b0673;
                  *(undefined4 *)(iVar14 + 0xdc) = 0;
                  pvVar8 = CRYPTO_malloc(uVar13,"t1_lib.c",0x49a);
                  *(void **)(iVar14 + 0xe0) = pvVar8;
                  if (pvVar8 == (void *)0x0) goto LAB_080b0c2d;
                  iVar14 = param_1[0x30];
                  *(uint *)(iVar14 + 0xdc) = uVar13;
                  memcpy(*(void **)(iVar14 + 0xe0),local_50 + 3,uVar13);
                }
              }
              goto LAB_080b06db;
            }
            if (uVar7 != 0x23) {
              if (uVar7 == 0xff01) {
                iVar14 = ssl_parse_clienthello_renegotiate_ext(param_1,puVar17,local_4c,param_5);
                if (iVar14 == 0) goto LAB_080b0ea8;
                bVar5 = true;
                goto LAB_080b06db;
              }
              if (uVar7 == 0xd) {
                if ((!bVar6) && (1 < uVar15)) {
                  uVar7 = *puVar17;
                  local_4c = local_4c - 2 & 0xffff;
                  puVar17 = local_50 + 3;
                  uVar15 = uVar7 >> 8;
                  uVar13 = (uint)(ushort)(uVar7 << 8 | uVar15);
                  if ((uVar13 == local_4c) &&
                     (((uVar15 & 1) == 0 &&
                      (iVar14 = tls1_process_sigalgs(param_1,puVar17,uVar13), iVar14 != 0)))) {
                    bVar6 = true;
                    goto LAB_080b06db;
                  }
                }
                goto LAB_080b0673;
              }
              if (uVar7 == 5) {
                if ((*param_1 == 0xfeff) || (*(int *)(param_1[0x39] + 0x13c) == 0))
                goto LAB_080b06db;
                if (uVar15 < 5) goto LAB_080b0673;
                puVar17 = (ushort *)((int)local_50 + 5);
                bVar3 = *(byte *)(local_50 + 2);
                param_1[0x4a] = (uint)bVar3;
                if (bVar3 != 1) {
                  param_1[0x4a] = -1;
                  local_4c = local_4c - 1 & 0xffff;
                  goto LAB_080b06db;
                }
                iVar14 = local_4c - 3;
                puVar21 = (ushort *)((int)local_50 + 7);
                uVar7 = *(ushort *)((int)local_50 + 5) << 8 | *(ushort *)((int)local_50 + 5) >> 8;
                uVar13 = (uint)uVar7;
                if (uVar7 <= (ushort)iVar14) {
                  if (uVar13 != 0) {
                    if (3 < uVar13) {
                      puVar17 = (ushort *)((int)local_50 + 9);
                      uVar18 = (uint)(ushort)(*(ushort *)((int)local_50 + 7) << 8 |
                                             *(ushort *)((int)local_50 + 7) >> 8);
                      iVar14 = iVar14 + (-2 - uVar18);
                      iVar12 = uVar13 - (uVar18 + 2);
                      if (-1 < iVar12) {
                        do {
                          puVar21 = (ushort *)((int)puVar17 + uVar18);
                          local_24 = puVar17;
                          a = d2i_OCSP_RESPID((OCSP_RESPID **)0x0,(uchar **)&local_24,uVar18);
                          if (a == (OCSP_RESPID *)0x0) break;
                          if (puVar21 != local_24) {
                            OCSP_RESPID_free(a);
                            *param_5 = 0x32;
                            goto LAB_080b0ea8;
                          }
                          st = (_STACK *)param_1[0x4c];
                          if (st == (_STACK *)0x0) {
                            st = sk_new_null();
                            param_1[0x4c] = (int)st;
                            if (st != (_STACK *)0x0) goto LAB_080b0df3;
LAB_080b0e92:
                            OCSP_RESPID_free(a);
                            *param_5 = 0x50;
                            goto LAB_080b0ea8;
                          }
LAB_080b0df3:
                          iVar10 = sk_push(st,a);
                          if (iVar10 == 0) goto LAB_080b0e92;
                          if (iVar12 == 0) goto LAB_080b0ee4;
                          if (iVar12 < 4) break;
                          puVar17 = puVar21 + 1;
                          uVar18 = (uint)(ushort)(*puVar21 << 8 | *puVar21 >> 8);
                          iVar14 = iVar14 + (-2 - uVar18);
                          iVar12 = iVar12 - (uVar18 + 2);
                          if (iVar12 < 0) break;
                        } while( true );
                      }
                    }
                    goto LAB_080b0f5c;
                  }
                  goto LAB_080b0eea;
                }
                goto LAB_080b0f5c;
              }
              if (uVar7 != 0xf) {
                if (uVar7 == 0x3374) {
                  if (*(int *)(param_1[0x16] + 0x2b4) == 0) {
                    *(undefined4 *)(param_1[0x16] + 0x41c) = 1;
                  }
                }
                else if ((uVar7 == 0xe) &&
                        (iVar14 = ssl_parse_clienthello_use_srtp_ext
                                            (param_1,puVar17,local_4c,param_5), iVar14 != 0))
                goto LAB_080b0ea8;
                goto LAB_080b06db;
              }
              if (*(char *)(local_50 + 2) == '\x01') {
                param_1[0x61] = param_1[0x61] | 1;
                goto LAB_080b06db;
              }
              if (*(char *)(local_50 + 2) == '\x02') {
                param_1[0x61] = param_1[0x61] | 3;
                goto LAB_080b06db;
              }
              *param_5 = 0x2f;
              goto LAB_080b0ea8;
            }
            if (((code *)param_1[0x58] == (code *)0x0) ||
               (iVar14 = (*(code *)param_1[0x58])(param_1,puVar17,local_4c,param_1[0x59]),
               iVar14 != 0)) goto LAB_080b06db;
LAB_080b0c2d:
            *param_5 = 0x50;
            local_54 = 0;
            goto LAB_080b044c;
          }
          if (uVar15 == 0) goto LAB_080b0673;
          bVar3 = *(byte *)(local_50 + 2);
          uVar13 = (uint)bVar3;
          if ((uVar13 == local_4c - 1) && (param_1[0x69] == 0)) {
            puVar16 = (undefined4 *)CRYPTO_malloc(local_4c,"t1_lib.c",0x454);
            param_1[0x69] = (int)puVar16;
            if (puVar16 == (undefined4 *)0x0) {
              local_54 = -1;
              goto LAB_080b044c;
            }
            if (uVar13 < 4) {
              if ((uVar13 != 0) &&
                 (*(undefined *)puVar16 = *(undefined *)((int)local_50 + 5), (bVar3 & 2) != 0)) {
                *(undefined2 *)((int)puVar16 + (uVar13 - 2)) =
                     *(undefined2 *)((int)local_50 + uVar13 + 3);
              }
            }
            else {
              *puVar16 = *(undefined4 *)((int)local_50 + 5);
              *(undefined4 *)((int)puVar16 + (uVar13 - 4)) =
                   *(undefined4 *)((int)local_50 + uVar13 + 1);
              iVar14 = (int)puVar16 - (int)(undefined4 *)((uint)(puVar16 + 1) & 0xfffffffc);
              puVar20 = (undefined4 *)((undefined *)((int)local_50 + 5) + -iVar14);
              puVar16 = (undefined4 *)((uint)(puVar16 + 1) & 0xfffffffc);
              for (uVar18 = iVar14 + uVar13 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
                *puVar16 = *puVar20;
                puVar20 = puVar20 + (uint)bVar22 * -2 + 1;
                puVar16 = puVar16 + (uint)bVar22 * -2 + 1;
              }
            }
            *(undefined *)(param_1[0x69] + uVar13) = 0;
            sVar9 = strlen((char *)param_1[0x69]);
            if (uVar13 == sVar9) goto LAB_080b06db;
          }
        }
LAB_080b0673:
        *param_5 = 0x32;
        local_54 = 0;
        goto LAB_080b044c;
      }
      goto LAB_080b0425;
    }
    bVar5 = false;
LAB_080b0d83:
    *param_2 = local_50;
LAB_080b071c:
    if (!bVar5) goto LAB_080b0425;
  }
  local_54 = 1;
LAB_080b044c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_54;
LAB_080b0ee4:
  if (1 < (ushort)iVar14) {
LAB_080b0eea:
    puVar17 = puVar21 + 1;
    local_4c = iVar14 - 2U & 0xffff;
    uVar13 = (uint)(ushort)(*puVar21 << 8 | *puVar21 >> 8);
    if (uVar13 == local_4c) {
      local_24 = puVar17;
      if (uVar13 != 0) {
        if ((_STACK *)param_1[0x4d] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)param_1[0x4d],X509_EXTENSION_free);
        }
        pXVar11 = d2i_X509_EXTENSIONS((X509_EXTENSIONS **)0x0,(uchar **)&local_24,uVar13);
        param_1[0x4d] = (int)pXVar11;
        if ((pXVar11 == (X509_EXTENSIONS *)0x0) || (local_24 != (ushort *)(uVar13 + (int)puVar17)))
        goto LAB_080b0f5c;
      }
LAB_080b06db:
      local_50 = (ushort *)((int)puVar17 + local_4c);
      if (puVar1 < local_50) goto LAB_080b0d83;
      puVar17 = local_50 + 2;
      uVar7 = *local_50 << 8 | *local_50 >> 8;
      local_4c = (uint)(ushort)(local_50[1] << 8 | local_50[1] >> 8);
      if ((uint)(param_3 + param_4) < local_4c + (int)puVar17) goto LAB_080b071c;
      goto LAB_080b04da;
    }
  }
LAB_080b0f5c:
  *param_5 = 0x32;
LAB_080b0ea8:
  local_54 = 0;
  goto LAB_080b044c;
}

