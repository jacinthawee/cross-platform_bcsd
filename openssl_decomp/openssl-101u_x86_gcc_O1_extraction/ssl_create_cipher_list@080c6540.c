
_STACK * ssl_create_cipher_list(int param_1,_STACK **param_2,_STACK **param_3,char *param_4)

{
  int **ppiVar1;
  void *pvVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  int iVar4;
  int iVar5;
  void **ptr;
  int *piVar6;
  void **ppvVar7;
  void **ppvVar8;
  undefined1 *puVar9;
  _STACK *st;
  _STACK *p_Var10;
  void **ppvVar11;
  void **ppvVar12;
  uint uVar13;
  void **ppvVar14;
  void **ppvVar15;
  void **ppvVar16;
  char *pcVar17;
  uint uVar18;
  uint uVar19;
  char *pcVar20;
  int in_GS_OFFSET;
  bool bVar21;
  byte bVar22;
  uint local_64;
  char *local_54;
  int local_44;
  uint local_40;
  void **local_2c;
  ENGINE *local_28;
  int local_24;
  int local_20;
  
  bVar22 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_54 = param_4;
  local_2c = (void **)0x0;
  if ((param_3 == (_STACK **)0x0 || param_2 == (_STACK **)0x0) || (param_4 == (char *)0x0)) {
    st = (_STACK *)0x0;
    goto LAB_080c6fdf;
  }
  local_28 = (ENGINE *)0x0;
  local_24 = 0;
  pEVar3 = EVP_PKEY_asn1_find_str(&local_28,"gost94",-1);
  if ((pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (iVar4 = EVP_PKEY_asn1_get0_info
                        (&local_24,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3),
     0 < iVar4)) {
    if (local_28 != (ENGINE *)0x0) goto LAB_080c65ee;
LAB_080c65fa:
    iVar4 = (-(uint)(local_24 == 0) & 0x100) + 0x200;
    uVar18 = (-(uint)(local_24 == 0) & 0x100) + 0x228;
    local_64 = (-(uint)(local_24 == 0) & 0x100) + 0x28;
  }
  else {
    local_24 = 0;
    if (local_28 != (ENGINE *)0x0) {
LAB_080c65ee:
      ENGINE_finish(local_28);
      goto LAB_080c65fa;
    }
    iVar4 = 0x300;
    uVar18 = 0x328;
    local_64 = 0x128;
  }
  local_28 = (ENGINE *)0x0;
  local_24 = 0;
  pEVar3 = EVP_PKEY_asn1_find_str(&local_28,"gost2001",-1);
  if ((pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (iVar5 = EVP_PKEY_asn1_get0_info
                        (&local_24,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3),
     0 < iVar5)) {
    if (local_28 != (ENGINE *)0x0) goto LAB_080c6681;
LAB_080c668d:
    if (local_24 == 0) goto LAB_080c700c;
    local_40 = 0xffffffe9;
    uVar19 = 0x16;
  }
  else {
    local_24 = 0;
    if (local_28 != (ENGINE *)0x0) {
LAB_080c6681:
      ENGINE_finish(local_28);
      goto LAB_080c668d;
    }
LAB_080c700c:
    local_40 = 0xfffffde9;
    if (iVar4 != 0x300) {
      local_40 = 0xffffffe9;
    }
    uVar19 = 0x16;
    local_64 = uVar18;
    if (iVar4 == 0x300) {
      uVar19 = 0x216;
    }
  }
  uVar18 = -(uint)(ssl_cipher_methods._40_4_ == 0) & 0x400 |
           -(uint)(ssl_cipher_methods._4_4_ == 0) & 2 | (uint)(ssl_cipher_methods._0_4_ == 0) |
           -(uint)(ssl_cipher_methods._8_4_ == 0) & 4 | -(uint)(ssl_cipher_methods._12_4_ == 0) & 8
           | -(uint)(ssl_cipher_methods._16_4_ == 0) & 0x10 |
           -(uint)(ssl_cipher_methods._24_4_ == 0) & 0x40 |
           -(uint)(ssl_cipher_methods._28_4_ == 0) & 0x80 |
           -(uint)(ssl_cipher_methods._48_4_ == 0) & 0x1000 |
           -(uint)(ssl_cipher_methods._52_4_ == 0) & 0x2000 |
           -(uint)(ssl_cipher_methods._32_4_ == 0) & 0x100 |
           -(uint)(ssl_cipher_methods._36_4_ == 0) & 0x200 |
           -(uint)(ssl_cipher_methods._44_4_ == 0) & 0x800;
  if (ssl_digest_methods._12_4_ == 0) {
    uVar13 = 8;
  }
  else {
    uVar13 = -(uint)(ssl_mac_pkey_id._12_4_ == 0) & 8;
  }
  uVar13 = -(uint)(ssl_digest_methods._8_4_ == 0) & 4 |
           -(uint)(ssl_digest_methods._4_4_ == 0) & 2 | (uint)(ssl_digest_methods._0_4_ == 0) |
           -(uint)(ssl_digest_methods._16_4_ == 0) & 0x10 |
           -(uint)(ssl_digest_methods._20_4_ == 0) & 0x20 | uVar13;
  iVar4 = (**(code **)(param_1 + 0x54))();
  ptr = (void **)CRYPTO_malloc(iVar4 * 0x14,"ssl_ciph.c",0x584);
  if (ptr == (void **)0x0) {
    iVar4 = 0x586;
LAB_080c7184:
    ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",iVar4);
    st = (_STACK *)0x0;
  }
  else {
    if (iVar4 < 1) {
LAB_080c70d0:
      ppvVar7 = (void **)0x0;
    }
    else {
      local_44 = 0;
      iVar5 = 0;
      do {
        piVar6 = (int *)(**(code **)(param_1 + 0x58))(iVar5);
        if (((((piVar6 != (int *)0x0) && (*piVar6 != 0)) && ((piVar6[3] & uVar19) == 0)) &&
            (((piVar6[4] & local_64) == 0 && ((piVar6[5] & uVar18) == 0)))) &&
           ((piVar6[6] & uVar13) == 0)) {
          ppiVar1 = (int **)(ptr + local_44 * 5);
          *ppiVar1 = piVar6;
          ppiVar1[3] = (int *)0x0;
          ppiVar1[4] = (int *)0x0;
          ppiVar1[1] = (int *)0x0;
          local_44 = local_44 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar4 != iVar5);
      if (local_44 == 0) goto LAB_080c70d0;
      ptr[4] = (void *)0x0;
      local_2c = ptr;
      if (local_44 != 1) {
        ptr[3] = ptr + 5;
        if (local_44 != 2) {
          ppvVar7 = ptr + 10;
          do {
            ppvVar7[-2] = ppvVar7;
            ppvVar8 = ppvVar7 + 5;
            ppvVar7[-1] = ppvVar7 + -10;
            ppvVar7 = ppvVar8;
          } while (ptr + local_44 * 5 != ppvVar8);
        }
        local_2c = ptr + local_44 * 5 + -5;
        local_2c[4] = ptr + local_44 * 5 + -10;
      }
      local_2c[3] = (void *)0x0;
      ppvVar7 = ptr;
    }
    ppvVar8 = local_2c;
    ppvVar12 = ppvVar7;
    if (local_2c != (void **)0x0) {
      do {
        if (ppvVar7 == (void **)0x0) break;
        ppvVar11 = (void **)ppvVar7[3];
        if (((*(byte *)((int)*ppvVar7 + 0xc) & 0x80) != 0) && (ppvVar7[1] == (void *)0x0)) {
          if (ppvVar7 != ppvVar8) {
            pvVar2 = ppvVar7[4];
            if (ppvVar7 == ppvVar12) {
              ppvVar12 = ppvVar11;
            }
            ppvVar16 = ppvVar11;
            if (pvVar2 != (void *)0x0) {
              *(void ***)((int)pvVar2 + 0xc) = ppvVar11;
              ppvVar16 = (void **)ppvVar7[3];
            }
            if (ppvVar16 != (void **)0x0) {
              ppvVar16[4] = pvVar2;
            }
            ppvVar8[3] = ppvVar7;
            ppvVar7[4] = ppvVar8;
            ppvVar7[3] = (void *)0x0;
            ppvVar8 = ppvVar7;
          }
          ppvVar7[1] = (void *)0x1;
        }
        bVar21 = local_2c != ppvVar7;
        ppvVar7 = ppvVar11;
      } while (bVar21);
    }
    ppvVar7 = ppvVar12;
    ppvVar11 = ppvVar8;
    if (ppvVar12 != (void **)0x0) {
      do {
        if (ppvVar8 == (void **)0x0) break;
        ppvVar16 = (void **)ppvVar8[4];
        if (((*(byte *)((int)*ppvVar8 + 0xc) & 0x80) != 0) && (ppvVar8[1] != (void *)0x0)) {
          if (ppvVar8 != ppvVar7) {
            pvVar2 = ppvVar8[3];
            if (ppvVar8 == ppvVar11) {
              ppvVar11 = ppvVar16;
            }
            ppvVar15 = ppvVar16;
            if (pvVar2 != (void *)0x0) {
              *(void ***)((int)pvVar2 + 0x10) = ppvVar16;
              ppvVar15 = (void **)ppvVar8[4];
            }
            if (ppvVar15 != (void **)0x0) {
              ppvVar15[3] = pvVar2;
            }
            ppvVar7[4] = ppvVar8;
            ppvVar8[3] = ppvVar7;
            ppvVar8[4] = (void *)0x0;
            ppvVar7 = ppvVar8;
          }
          ppvVar8[1] = (void *)0x0;
        }
        bVar21 = ppvVar8 != ppvVar12;
        ppvVar8 = ppvVar16;
      } while (bVar21);
    }
    ppvVar12 = (void **)0x0;
    ppvVar8 = ppvVar7;
    ppvVar16 = ppvVar11;
    while ((ppvVar15 = ppvVar8, ppvVar15 != (void **)0x0 && (ppvVar12 != ppvVar11))) {
      ppvVar8 = (void **)ppvVar15[3];
      ppvVar12 = ppvVar15;
      if (((*(uint *)((int)*ppvVar15 + 0x14) & 0x30c0) != 0) && (ppvVar15[1] == (void *)0x0)) {
        if (ppvVar15 != ppvVar16) {
          pvVar2 = ppvVar15[4];
          if (ppvVar15 == ppvVar7) {
            ppvVar7 = ppvVar8;
          }
          ppvVar14 = ppvVar8;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar8;
            ppvVar14 = (void **)ppvVar15[3];
          }
          if (ppvVar14 != (void **)0x0) {
            ppvVar14[4] = pvVar2;
          }
          ppvVar16[3] = ppvVar15;
          ppvVar15[4] = ppvVar16;
          ppvVar15[3] = (void *)0x0;
          ppvVar16 = ppvVar15;
        }
        ppvVar15[1] = (void *)0x1;
      }
    }
    ppvVar12 = (void **)0x0;
    ppvVar8 = ppvVar7;
    ppvVar11 = ppvVar16;
    while ((ppvVar15 = ppvVar8, ppvVar15 != (void **)0x0 && (ppvVar12 != ppvVar16))) {
      ppvVar8 = (void **)ppvVar15[3];
      ppvVar12 = ppvVar15;
      if (ppvVar15[1] == (void *)0x0) {
        if (ppvVar15 != ppvVar11) {
          pvVar2 = ppvVar15[4];
          if (ppvVar15 == ppvVar7) {
            ppvVar7 = ppvVar8;
          }
          ppvVar14 = ppvVar8;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar8;
            ppvVar14 = (void **)ppvVar15[3];
          }
          if (ppvVar14 != (void **)0x0) {
            ppvVar14[4] = pvVar2;
          }
          ppvVar11[3] = ppvVar15;
          ppvVar15[4] = ppvVar11;
          ppvVar15[3] = (void *)0x0;
          ppvVar11 = ppvVar15;
        }
        ppvVar15[1] = (void *)0x1;
      }
    }
    ppvVar12 = (void **)0x0;
    ppvVar8 = ppvVar7;
    ppvVar16 = ppvVar11;
    while ((ppvVar15 = ppvVar8, ppvVar15 != (void **)0x0 && (ppvVar12 != ppvVar11))) {
      ppvVar8 = (void **)ppvVar15[3];
      ppvVar12 = ppvVar15;
      if (((*(byte *)((int)*ppvVar15 + 0x18) & 1) != 0) &&
         ((ppvVar15[1] != (void *)0x0 && (ppvVar15 != ppvVar16)))) {
        pvVar2 = ppvVar15[4];
        if (ppvVar15 == ppvVar7) {
          ppvVar7 = ppvVar8;
        }
        ppvVar14 = ppvVar8;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar8;
          ppvVar14 = (void **)ppvVar15[3];
        }
        if (ppvVar14 != (void **)0x0) {
          ppvVar14[4] = pvVar2;
        }
        ppvVar16[3] = ppvVar15;
        ppvVar15[4] = ppvVar16;
        ppvVar15[3] = (void *)0x0;
        ppvVar16 = ppvVar15;
      }
    }
    ppvVar8 = ppvVar7;
    ppvVar12 = ppvVar16;
    if (ppvVar16 != (void **)0x0) {
      do {
        if (ppvVar8 == (void **)0x0) break;
        ppvVar11 = (void **)ppvVar8[3];
        if ((((*(byte *)((int)*ppvVar8 + 0x10) & 4) != 0) && (ppvVar8[1] != (void *)0x0)) &&
           (ppvVar8 != ppvVar12)) {
          pvVar2 = ppvVar8[4];
          if (ppvVar8 == ppvVar7) {
            ppvVar7 = ppvVar11;
          }
          ppvVar15 = ppvVar11;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar11;
            ppvVar15 = (void **)ppvVar8[3];
          }
          if (ppvVar15 != (void **)0x0) {
            ppvVar15[4] = pvVar2;
          }
          ppvVar12[3] = ppvVar8;
          ppvVar8[4] = ppvVar12;
          ppvVar8[3] = (void *)0x0;
          ppvVar12 = ppvVar8;
        }
        bVar21 = ppvVar8 != ppvVar16;
        ppvVar8 = ppvVar11;
      } while (bVar21);
    }
    ppvVar11 = (void **)0x0;
    ppvVar8 = ppvVar7;
    ppvVar16 = ppvVar12;
    while ((ppvVar15 = ppvVar8, ppvVar15 != (void **)0x0 && (ppvVar11 != ppvVar12))) {
      ppvVar8 = (void **)ppvVar15[3];
      ppvVar11 = ppvVar15;
      if (((*(byte *)((int)*ppvVar15 + 0x10) & 0x10) != 0) &&
         ((ppvVar15[1] != (void *)0x0 && (ppvVar15 != ppvVar16)))) {
        pvVar2 = ppvVar15[4];
        if (ppvVar15 == ppvVar7) {
          ppvVar7 = ppvVar8;
        }
        ppvVar14 = ppvVar8;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar8;
          ppvVar14 = (void **)ppvVar15[3];
        }
        if (ppvVar14 != (void **)0x0) {
          ppvVar14[4] = pvVar2;
        }
        ppvVar16[3] = ppvVar15;
        ppvVar15[4] = ppvVar16;
        ppvVar15[3] = (void *)0x0;
        ppvVar16 = ppvVar15;
      }
    }
    ppvVar8 = ppvVar7;
    ppvVar12 = ppvVar16;
    if (ppvVar16 != (void **)0x0) {
      do {
        if (ppvVar8 == (void **)0x0) break;
        ppvVar11 = (void **)ppvVar8[3];
        if ((((*(byte *)((int)*ppvVar8 + 0xc) & 1) != 0) && (ppvVar8[1] != (void *)0x0)) &&
           (ppvVar8 != ppvVar12)) {
          pvVar2 = ppvVar8[4];
          if (ppvVar8 == ppvVar7) {
            ppvVar7 = ppvVar11;
          }
          ppvVar15 = ppvVar11;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar11;
            ppvVar15 = (void **)ppvVar8[3];
          }
          if (ppvVar15 != (void **)0x0) {
            ppvVar15[4] = pvVar2;
          }
          ppvVar12[3] = ppvVar8;
          ppvVar8[4] = ppvVar12;
          ppvVar8[3] = (void *)0x0;
          ppvVar12 = ppvVar8;
        }
        bVar21 = ppvVar8 != ppvVar16;
        ppvVar8 = ppvVar11;
      } while (bVar21);
    }
    ppvVar11 = (void **)0x0;
    ppvVar8 = ppvVar7;
    ppvVar16 = ppvVar12;
    while ((ppvVar15 = ppvVar8, ppvVar15 != (void **)0x0 && (ppvVar11 != ppvVar12))) {
      ppvVar8 = (void **)ppvVar15[3];
      ppvVar11 = ppvVar15;
      if (((*(byte *)((int)*ppvVar15 + 0xd) & 1) != 0) &&
         ((ppvVar15[1] != (void *)0x0 && (ppvVar15 != ppvVar16)))) {
        pvVar2 = ppvVar15[4];
        if (ppvVar15 == ppvVar7) {
          ppvVar7 = ppvVar8;
        }
        ppvVar14 = ppvVar8;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar8;
          ppvVar14 = (void **)ppvVar15[3];
        }
        if (ppvVar14 != (void **)0x0) {
          ppvVar14[4] = pvVar2;
        }
        ppvVar16[3] = ppvVar15;
        ppvVar15[4] = ppvVar16;
        ppvVar15[3] = (void *)0x0;
        ppvVar16 = ppvVar15;
      }
    }
    ppvVar8 = ppvVar7;
    ppvVar12 = ppvVar16;
    if (ppvVar16 != (void **)0x0) {
      do {
        if (ppvVar8 == (void **)0x0) break;
        ppvVar11 = (void **)ppvVar8[3];
        if ((((*(byte *)((int)*ppvVar8 + 0xc) & 0x10) != 0) && (ppvVar8[1] != (void *)0x0)) &&
           (ppvVar8 != ppvVar12)) {
          pvVar2 = ppvVar8[4];
          if (ppvVar8 == ppvVar7) {
            ppvVar7 = ppvVar11;
          }
          ppvVar15 = ppvVar11;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar11;
            ppvVar15 = (void **)ppvVar8[3];
          }
          if (ppvVar15 != (void **)0x0) {
            ppvVar15[4] = pvVar2;
          }
          ppvVar12[3] = ppvVar8;
          ppvVar8[4] = ppvVar12;
          ppvVar8[3] = (void *)0x0;
          ppvVar12 = ppvVar8;
        }
        bVar21 = ppvVar8 != ppvVar16;
        ppvVar8 = ppvVar11;
      } while (bVar21);
    }
    ppvVar8 = ppvVar12;
    ppvVar11 = ppvVar7;
    if (ppvVar12 != (void **)0x0) {
      do {
        if (ppvVar7 == (void **)0x0) break;
        ppvVar16 = (void **)ppvVar7[3];
        if ((((*(byte *)((int)*ppvVar7 + 0x14) & 4) != 0) && (ppvVar7[1] != (void *)0x0)) &&
           (ppvVar7 != ppvVar8)) {
          pvVar2 = ppvVar7[4];
          if (ppvVar7 == ppvVar11) {
            ppvVar11 = ppvVar16;
          }
          ppvVar15 = ppvVar16;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar16;
            ppvVar15 = (void **)ppvVar7[3];
          }
          if (ppvVar15 != (void **)0x0) {
            ppvVar15[4] = pvVar2;
          }
          ppvVar8[3] = ppvVar7;
          ppvVar7[4] = ppvVar8;
          ppvVar7[3] = (void *)0x0;
          ppvVar8 = ppvVar7;
        }
        bVar21 = ppvVar7 != ppvVar12;
        ppvVar7 = ppvVar16;
      } while (bVar21);
    }
    iVar5 = ssl_cipher_strength_sort();
    if (iVar5 != 0) {
      ppvVar7 = ppvVar11;
      ppvVar12 = ppvVar8;
      if (ppvVar11 != (void **)0x0) {
        do {
          if (ppvVar8 == (void **)0x0) break;
          ppvVar16 = (void **)ppvVar8[4];
          if (ppvVar8[1] != (void *)0x0) {
            if (ppvVar8 != ppvVar7) {
              pvVar2 = ppvVar8[3];
              if (ppvVar8 == ppvVar12) {
                ppvVar12 = ppvVar16;
              }
              ppvVar15 = ppvVar16;
              if (pvVar2 != (void *)0x0) {
                *(void ***)((int)pvVar2 + 0x10) = ppvVar16;
                ppvVar15 = (void **)ppvVar8[4];
              }
              if (ppvVar15 != (void **)0x0) {
                ppvVar15[3] = pvVar2;
              }
              ppvVar7[4] = ppvVar8;
              ppvVar8[3] = ppvVar7;
              ppvVar8[4] = (void *)0x0;
              ppvVar7 = ppvVar8;
            }
            ppvVar8[1] = (void *)0x0;
          }
          bVar21 = ppvVar11 != ppvVar8;
          ppvVar8 = ppvVar16;
        } while (bVar21);
      }
      ppvVar8 = (void **)CRYPTO_malloc(iVar4 * 4 + 300,"ssl_ciph.c",0x5d5);
      if (ppvVar8 == (void **)0x0) {
        CRYPTO_free(ptr);
        iVar4 = 0x5d8;
        goto LAB_080c7184;
      }
      ppvVar11 = ppvVar8;
      for (ppvVar12 = ppvVar7; ppvVar12 != (void **)0x0; ppvVar12 = (void **)ppvVar12[3]) {
        *ppvVar11 = *ppvVar12;
        ppvVar11 = ppvVar11 + 1;
      }
      puVar9 = cipher_aliases;
      do {
        if ((((*(uint *)(puVar9 + 0xc) == 0) || ((local_40 & *(uint *)(puVar9 + 0xc)) != 0)) &&
            (((*(uint *)(puVar9 + 0x10) == 0 || ((~local_64 & *(uint *)(puVar9 + 0x10)) != 0)) &&
             ((*(uint *)(puVar9 + 0x14) == 0 || ((~uVar18 & *(uint *)(puVar9 + 0x14)) != 0)))))) &&
           ((*(uint *)(puVar9 + 0x18) == 0 || ((~uVar13 & *(uint *)(puVar9 + 0x18)) != 0)))) {
          *ppvVar11 = puVar9;
          ppvVar11 = ppvVar11 + 1;
        }
        puVar9 = puVar9 + 0x30;
        bVar21 = puVar9 == ssl_handshake_digest_flag;
      } while (!bVar21);
      *ppvVar11 = (void *)0x0;
      iVar4 = 7;
      pcVar17 = param_4;
      pcVar20 = "DEFAULT";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar21 = *pcVar17 == *pcVar20;
        pcVar17 = pcVar17 + (uint)bVar22 * -2 + 1;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        iVar4 = ssl_cipher_process_rulestr(ppvVar8);
        local_54 = param_4 + 7;
        if (param_4[7] == ':') {
          local_54 = param_4 + 8;
        }
        if (iVar4 == 0) {
          CRYPTO_free(ppvVar8);
          goto LAB_080c7088;
        }
      }
      if (*local_54 == '\0') {
        CRYPTO_free(ppvVar8);
      }
      else {
        iVar4 = ssl_cipher_process_rulestr(ppvVar8);
        CRYPTO_free(ppvVar8);
        if (iVar4 == 0) goto LAB_080c7088;
      }
      st = sk_new_null();
      if (st != (_STACK *)0x0) {
        for (; ppvVar7 != (void **)0x0; ppvVar7 = (void **)ppvVar7[3]) {
          while (ppvVar7[1] == (void *)0x0) {
            ppvVar7 = (void **)ppvVar7[3];
            if (ppvVar7 == (void **)0x0) goto LAB_080c6f6b;
          }
          sk_push(st,*ppvVar7);
        }
LAB_080c6f6b:
        CRYPTO_free(ptr);
        p_Var10 = sk_dup(st);
        if (p_Var10 == (_STACK *)0x0) {
          sk_free(st);
          st = (_STACK *)0x0;
        }
        else {
          if (*param_2 != (_STACK *)0x0) {
            sk_free(*param_2);
          }
          *param_2 = st;
          if (*param_3 != (_STACK *)0x0) {
            sk_free(*param_3);
          }
          *param_3 = p_Var10;
          sk_set_cmp_func(p_Var10,ssl_cipher_ptr_id_cmp);
          sk_sort(*param_3);
        }
        goto LAB_080c6fdf;
      }
    }
LAB_080c7088:
    CRYPTO_free(ptr);
    st = (_STACK *)0x0;
  }
LAB_080c6fdf:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return st;
}

