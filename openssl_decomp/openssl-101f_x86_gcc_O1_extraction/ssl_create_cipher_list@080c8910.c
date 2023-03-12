
_STACK * ssl_create_cipher_list(int param_1,_STACK **param_2,_STACK **param_3,char *param_4)

{
  int **ppiVar1;
  void *pvVar2;
  void **ppvVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  void **ptr;
  int *piVar9;
  void **ppvVar10;
  undefined1 *puVar11;
  _STACK *st;
  _STACK *p_Var12;
  void **ppvVar13;
  void **ppvVar14;
  uint uVar15;
  void **ppvVar16;
  void **ppvVar17;
  uint uVar18;
  void **ppvVar19;
  void **ppvVar20;
  char *pcVar21;
  int iVar22;
  char *pcVar23;
  int in_GS_OFFSET;
  bool bVar24;
  byte bVar25;
  char *local_58;
  int local_44;
  void **local_2c;
  ENGINE *local_28;
  int local_24;
  int local_20;
  
  bVar25 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_58 = param_4;
  local_2c = (void **)0x0;
  if ((param_3 == (_STACK **)0x0 || param_2 == (_STACK **)0x0) || (param_4 == (char *)0x0)) {
    st = (_STACK *)0x0;
    goto LAB_080c93af;
  }
  local_28 = (ENGINE *)0x0;
  local_24 = 0;
  pEVar4 = EVP_PKEY_asn1_find_str(&local_28,"gost94",-1);
  if (pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(&local_24,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar4);
  }
  if (local_28 != (ENGINE *)0x0) {
    ENGINE_finish(local_28);
  }
  bVar24 = local_24 == 0;
  local_28 = (ENGINE *)0x0;
  local_24 = 0;
  uVar5 = (-(uint)bVar24 & 0x100) + 0x28;
  pEVar4 = EVP_PKEY_asn1_find_str(&local_28,"gost2001",-1);
  if (pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(&local_24,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar4);
  }
  if (local_28 != (ENGINE *)0x0) {
    ENGINE_finish(local_28);
  }
  uVar15 = 0xffffffe9;
  uVar6 = uVar5 | 0x200;
  if (local_24 != 0) {
    uVar6 = uVar5;
  }
  uVar5 = 0x216;
  if ((uVar6 & 0x300) == 0x300) {
    uVar15 = 0xfffffde9;
  }
  else {
    uVar5 = 0x16;
  }
  uVar7 = -(uint)(ssl_cipher_methods._40_4_ == 0) & 0x400 |
          -(uint)(ssl_cipher_methods._4_4_ == 0) & 2 | (uint)(ssl_cipher_methods._0_4_ == 0) |
          -(uint)(ssl_cipher_methods._8_4_ == 0) & 4 | -(uint)(ssl_cipher_methods._12_4_ == 0) & 8 |
          -(uint)(ssl_cipher_methods._16_4_ == 0) & 0x10 |
          -(uint)(ssl_cipher_methods._24_4_ == 0) & 0x40 |
          -(uint)(ssl_cipher_methods._28_4_ == 0) & 0x80 |
          -(uint)(ssl_cipher_methods._48_4_ == 0) & 0x1000 |
          -(uint)(ssl_cipher_methods._52_4_ == 0) & 0x2000 |
          -(uint)(ssl_cipher_methods._32_4_ == 0) & 0x100 |
          -(uint)(ssl_cipher_methods._36_4_ == 0) & 0x200 |
          -(uint)(ssl_cipher_methods._44_4_ == 0) & 0x800;
  if (ssl_digest_methods._12_4_ == 0) {
    uVar18 = 8;
  }
  else {
    uVar18 = -(uint)(ssl_mac_pkey_id._12_4_ == 0) & 8;
  }
  uVar18 = -(uint)(ssl_digest_methods._8_4_ == 0) & 4 |
           -(uint)(ssl_digest_methods._4_4_ == 0) & 2 | (uint)(ssl_digest_methods._0_4_ == 0) |
           -(uint)(ssl_digest_methods._16_4_ == 0) & 0x10 |
           -(uint)(ssl_digest_methods._20_4_ == 0) & 0x20 | uVar18;
  iVar8 = (**(code **)(param_1 + 0x54))();
  ptr = (void **)CRYPTO_malloc(iVar8 * 0x14,"ssl_ciph.c",0x56a);
  if (ptr == (void **)0x0) {
    iVar8 = 0x56d;
LAB_080c94df:
    ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",iVar8);
    st = (_STACK *)0x0;
  }
  else {
    if (iVar8 < 1) {
LAB_080c9468:
      ppvVar17 = (void **)0x0;
      ppvVar10 = ppvVar17;
      ppvVar20 = ppvVar17;
      ppvVar14 = local_2c;
    }
    else {
      local_44 = 0;
      iVar22 = 0;
      do {
        piVar9 = (int *)(**(code **)(param_1 + 0x58))(iVar22);
        if (((((piVar9 != (int *)0x0) && (*piVar9 != 0)) && ((piVar9[3] & uVar5) == 0)) &&
            (((piVar9[4] & uVar6) == 0 && ((piVar9[5] & uVar7) == 0)))) &&
           ((piVar9[6] & uVar18) == 0)) {
          ppiVar1 = (int **)(ptr + local_44 * 5);
          *ppiVar1 = piVar9;
          ppiVar1[3] = (int *)0x0;
          ppiVar1[4] = (int *)0x0;
          ppiVar1[1] = (int *)0x0;
          local_44 = local_44 + 1;
        }
        iVar22 = iVar22 + 1;
      } while (iVar8 != iVar22);
      if (local_44 == 0) goto LAB_080c9468;
      ptr[4] = (void *)0x0;
      local_2c = ptr;
      if (local_44 != 1) {
        ptr[3] = ptr + 5;
        if (local_44 != 2) {
          ppvVar10 = ptr + 10;
          do {
            ppvVar10[-2] = ppvVar10;
            ppvVar17 = ppvVar10 + 5;
            ppvVar10[-1] = ppvVar10 + -10;
            ppvVar10 = ppvVar17;
          } while (ptr + local_44 * 5 != ppvVar17);
        }
        local_2c = ptr + local_44 * 5 + -5;
        local_2c[4] = ptr + local_44 * 5 + -10;
      }
      local_2c[3] = (void *)0x0;
      ppvVar10 = ptr;
      ppvVar20 = ptr;
      ppvVar17 = ptr;
      ppvVar14 = local_2c;
    }
    while ((ppvVar19 = ppvVar10, ppvVar10 = local_2c, ppvVar16 = local_2c, ppvVar13 = ppvVar17,
           ppvVar20 != (void **)0x0 && (ppvVar14 != ppvVar20))) {
      ppvVar10 = (void **)ppvVar19[3];
      ppvVar20 = ppvVar19;
      if (((*(byte *)((int)*ppvVar19 + 0xc) & 0x80) != 0) && (ppvVar19[1] == (void *)0x0)) {
        if (ppvVar19 != local_2c) {
          pvVar2 = ppvVar19[4];
          if (ppvVar19 == ppvVar17) {
            ppvVar17 = ppvVar10;
          }
          ppvVar13 = ppvVar10;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
            ppvVar13 = (void **)ppvVar19[3];
          }
          if (ppvVar13 != (void **)0x0) {
            ppvVar13[4] = pvVar2;
          }
          local_2c[3] = ppvVar19;
          ppvVar19[4] = local_2c;
          ppvVar19[3] = (void *)0x0;
          local_2c = ppvVar19;
        }
        ppvVar19[1] = (void *)0x1;
      }
    }
    while ((ppvVar20 = ppvVar10, ppvVar10 = ppvVar13, ppvVar14 = ppvVar13, ppvVar19 = local_2c,
           ppvVar16 != (void **)0x0 && (ppvVar16 != ppvVar17))) {
      ppvVar10 = (void **)ppvVar20[4];
      ppvVar16 = ppvVar20;
      if (((*(byte *)((int)*ppvVar20 + 0xc) & 0x80) != 0) && (ppvVar20[1] != (void *)0x0)) {
        if (ppvVar20 != ppvVar13) {
          pvVar2 = ppvVar20[3];
          if (ppvVar20 == local_2c) {
            local_2c = ppvVar10;
          }
          ppvVar14 = ppvVar10;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0x10) = ppvVar10;
            ppvVar14 = (void **)ppvVar20[4];
          }
          if (ppvVar14 != (void **)0x0) {
            ppvVar14[3] = pvVar2;
          }
          ppvVar13[4] = ppvVar20;
          ppvVar20[3] = ppvVar13;
          ppvVar20[4] = (void *)0x0;
          ppvVar13 = ppvVar20;
        }
        ppvVar20[1] = (void *)0x0;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar10 = ppvVar13, ppvVar20 = ppvVar13, ppvVar16 = ppvVar19,
           ppvVar14 != (void **)0x0 && (ppvVar14 != local_2c))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar14 = ppvVar17;
      if (((*(uint *)((int)*ppvVar17 + 0x14) & 0x30c0) != 0) && (ppvVar17[1] == (void *)0x0)) {
        if (ppvVar17 != ppvVar19) {
          pvVar2 = ppvVar17[4];
          if (ppvVar17 == ppvVar13) {
            ppvVar13 = ppvVar10;
          }
          ppvVar20 = ppvVar10;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
            ppvVar20 = (void **)ppvVar17[3];
          }
          if (ppvVar20 != (void **)0x0) {
            ppvVar20[4] = pvVar2;
          }
          ppvVar19[3] = ppvVar17;
          ppvVar17[4] = ppvVar19;
          ppvVar17[3] = (void *)0x0;
          ppvVar19 = ppvVar17;
        }
        ppvVar17[1] = (void *)0x1;
      }
    }
    while ((ppvVar3 = ppvVar10, ppvVar10 = ppvVar13, ppvVar17 = ppvVar13, ppvVar14 = ppvVar16,
           ppvVar20 != (void **)0x0 && (ppvVar20 != ppvVar19))) {
      ppvVar10 = (void **)ppvVar3[3];
      ppvVar20 = ppvVar3;
      if (ppvVar3[1] == (void *)0x0) {
        if (ppvVar3 != ppvVar16) {
          pvVar2 = ppvVar3[4];
          if (ppvVar3 == ppvVar13) {
            ppvVar13 = ppvVar10;
          }
          ppvVar17 = ppvVar10;
          if (pvVar2 != (void *)0x0) {
            *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
            ppvVar17 = (void **)ppvVar3[3];
          }
          if (ppvVar17 != (void **)0x0) {
            ppvVar17[4] = pvVar2;
          }
          ppvVar16[3] = ppvVar3;
          ppvVar3[4] = ppvVar16;
          ppvVar3[3] = (void *)0x0;
          ppvVar16 = ppvVar3;
        }
        ppvVar3[1] = (void *)0x1;
      }
    }
    while ((ppvVar20 = ppvVar10, ppvVar10 = ppvVar13, ppvVar19 = ppvVar13, ppvVar3 = ppvVar14,
           ppvVar17 != (void **)0x0 && (ppvVar17 != ppvVar16))) {
      ppvVar10 = (void **)ppvVar20[3];
      ppvVar17 = ppvVar20;
      if (((*(byte *)((int)*ppvVar20 + 0x18) & 1) != 0) &&
         ((ppvVar20[1] != (void *)0x0 && (ppvVar20 != ppvVar14)))) {
        pvVar2 = ppvVar20[4];
        if (ppvVar20 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar19 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar19 = (void **)ppvVar20[3];
        }
        if (ppvVar19 != (void **)0x0) {
          ppvVar19[4] = pvVar2;
        }
        ppvVar14[3] = ppvVar20;
        ppvVar20[4] = ppvVar14;
        ppvVar20[3] = (void *)0x0;
        ppvVar14 = ppvVar20;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar10 = ppvVar13, ppvVar20 = ppvVar13, ppvVar16 = ppvVar3,
           ppvVar19 != (void **)0x0 && (ppvVar19 != ppvVar14))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar19 = ppvVar17;
      if (((*(byte *)((int)*ppvVar17 + 0x10) & 4) != 0) &&
         ((ppvVar17[1] != (void *)0x0 && (ppvVar17 != ppvVar3)))) {
        pvVar2 = ppvVar17[4];
        if (ppvVar17 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar20 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar20 = (void **)ppvVar17[3];
        }
        if (ppvVar20 != (void **)0x0) {
          ppvVar20[4] = pvVar2;
        }
        ppvVar3[3] = ppvVar17;
        ppvVar17[4] = ppvVar3;
        ppvVar17[3] = (void *)0x0;
        ppvVar3 = ppvVar17;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar10 = ppvVar13, ppvVar14 = ppvVar13, ppvVar19 = ppvVar16,
           ppvVar20 != (void **)0x0 && (ppvVar20 != ppvVar3))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar20 = ppvVar17;
      if (((*(byte *)((int)*ppvVar17 + 0x10) & 0x10) != 0) &&
         ((ppvVar17[1] != (void *)0x0 && (ppvVar17 != ppvVar16)))) {
        pvVar2 = ppvVar17[4];
        if (ppvVar17 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar14 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar14 = (void **)ppvVar17[3];
        }
        if (ppvVar14 != (void **)0x0) {
          ppvVar14[4] = pvVar2;
        }
        ppvVar16[3] = ppvVar17;
        ppvVar17[4] = ppvVar16;
        ppvVar17[3] = (void *)0x0;
        ppvVar16 = ppvVar17;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar10 = ppvVar13, ppvVar20 = ppvVar13, ppvVar3 = ppvVar19,
           ppvVar14 != (void **)0x0 && (ppvVar14 != ppvVar16))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar14 = ppvVar17;
      if (((*(byte *)((int)*ppvVar17 + 0xc) & 1) != 0) &&
         ((ppvVar17[1] != (void *)0x0 && (ppvVar17 != ppvVar19)))) {
        pvVar2 = ppvVar17[4];
        if (ppvVar17 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar20 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar20 = (void **)ppvVar17[3];
        }
        if (ppvVar20 != (void **)0x0) {
          ppvVar20[4] = pvVar2;
        }
        ppvVar19[3] = ppvVar17;
        ppvVar17[4] = ppvVar19;
        ppvVar17[3] = (void *)0x0;
        ppvVar19 = ppvVar17;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar10 = ppvVar13, ppvVar14 = ppvVar13, ppvVar16 = ppvVar3,
           ppvVar20 != (void **)0x0 && (ppvVar20 != ppvVar19))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar20 = ppvVar17;
      if (((*(byte *)((int)*ppvVar17 + 0xd) & 1) != 0) &&
         ((ppvVar17[1] != (void *)0x0 && (ppvVar17 != ppvVar3)))) {
        pvVar2 = ppvVar17[4];
        if (ppvVar17 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar14 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar14 = (void **)ppvVar17[3];
        }
        if (ppvVar14 != (void **)0x0) {
          ppvVar14[4] = pvVar2;
        }
        ppvVar3[3] = ppvVar17;
        ppvVar17[4] = ppvVar3;
        ppvVar17[3] = (void *)0x0;
        ppvVar3 = ppvVar17;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar10 = ppvVar13, ppvVar20 = ppvVar13, ppvVar19 = ppvVar16,
           ppvVar14 != (void **)0x0 && (ppvVar14 != ppvVar3))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar14 = ppvVar17;
      if (((*(byte *)((int)*ppvVar17 + 0xc) & 0x10) != 0) &&
         ((ppvVar17[1] != (void *)0x0 && (ppvVar17 != ppvVar16)))) {
        pvVar2 = ppvVar17[4];
        if (ppvVar17 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar20 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar20 = (void **)ppvVar17[3];
        }
        if (ppvVar20 != (void **)0x0) {
          ppvVar20[4] = pvVar2;
        }
        ppvVar16[3] = ppvVar17;
        ppvVar17[4] = ppvVar16;
        ppvVar17[3] = (void *)0x0;
        ppvVar16 = ppvVar17;
      }
    }
    while ((ppvVar17 = ppvVar10, ppvVar20 != (void **)0x0 && (ppvVar20 != ppvVar16))) {
      ppvVar10 = (void **)ppvVar17[3];
      ppvVar20 = ppvVar17;
      if (((*(byte *)((int)*ppvVar17 + 0x14) & 4) != 0) &&
         ((ppvVar17[1] != (void *)0x0 && (ppvVar17 != ppvVar19)))) {
        pvVar2 = ppvVar17[4];
        if (ppvVar17 == ppvVar13) {
          ppvVar13 = ppvVar10;
        }
        ppvVar14 = ppvVar10;
        if (pvVar2 != (void *)0x0) {
          *(void ***)((int)pvVar2 + 0xc) = ppvVar10;
          ppvVar14 = (void **)ppvVar17[3];
        }
        if (ppvVar14 != (void **)0x0) {
          ppvVar14[4] = pvVar2;
        }
        ppvVar19[3] = ppvVar17;
        ppvVar17[4] = ppvVar19;
        ppvVar17[3] = (void *)0x0;
        ppvVar19 = ppvVar17;
      }
    }
    iVar22 = ssl_cipher_strength_sort();
    ppvVar10 = ppvVar19;
    ppvVar20 = ppvVar19;
    ppvVar17 = ppvVar13;
    if (iVar22 != 0) {
      while ((ppvVar14 = ppvVar10, ppvVar20 != (void **)0x0 && (ppvVar13 != ppvVar20))) {
        ppvVar10 = (void **)ppvVar14[4];
        ppvVar20 = ppvVar14;
        if (ppvVar14[1] != (void *)0x0) {
          if (ppvVar14 != ppvVar17) {
            pvVar2 = ppvVar14[3];
            if (ppvVar14 == ppvVar19) {
              ppvVar19 = ppvVar10;
            }
            ppvVar16 = ppvVar10;
            if (pvVar2 != (void *)0x0) {
              *(void ***)((int)pvVar2 + 0x10) = ppvVar10;
              ppvVar16 = (void **)ppvVar14[4];
            }
            if (ppvVar16 != (void **)0x0) {
              ppvVar16[3] = pvVar2;
            }
            ppvVar17[4] = ppvVar14;
            ppvVar14[3] = ppvVar17;
            ppvVar14[4] = (void *)0x0;
            ppvVar17 = ppvVar14;
          }
          ppvVar14[1] = (void *)0x0;
        }
      }
      ppvVar10 = (void **)CRYPTO_malloc(iVar8 * 4 + 0x128,"ssl_ciph.c",0x5aa);
      if (ppvVar10 == (void **)0x0) {
        CRYPTO_free(ptr);
        iVar8 = 0x5ae;
        goto LAB_080c94df;
      }
      ppvVar14 = ppvVar10;
      for (ppvVar20 = ppvVar17; ppvVar20 != (void **)0x0; ppvVar20 = (void **)ppvVar20[3]) {
        *ppvVar14 = *ppvVar20;
        ppvVar14 = ppvVar14 + 1;
      }
      puVar11 = cipher_aliases;
      do {
        if (((((*(uint *)(puVar11 + 0xc) == 0) || ((uVar15 & *(uint *)(puVar11 + 0xc)) != 0)) &&
             ((*(uint *)(puVar11 + 0x10) == 0 || ((~uVar6 & *(uint *)(puVar11 + 0x10)) != 0)))) &&
            ((*(uint *)(puVar11 + 0x14) == 0 || ((~uVar7 & *(uint *)(puVar11 + 0x14)) != 0)))) &&
           ((*(uint *)(puVar11 + 0x18) == 0 || ((~uVar18 & *(uint *)(puVar11 + 0x18)) != 0)))) {
          *ppvVar14 = puVar11;
          ppvVar14 = ppvVar14 + 1;
        }
        puVar11 = puVar11 + 0x30;
        bVar24 = puVar11 == ssl_handshake_digest_flag;
      } while (!bVar24);
      *ppvVar14 = (void *)0x0;
      iVar8 = 7;
      pcVar21 = param_4;
      pcVar23 = "DEFAULT";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar24 = *pcVar21 == *pcVar23;
        pcVar21 = pcVar21 + (uint)bVar25 * -2 + 1;
        pcVar23 = pcVar23 + (uint)bVar25 * -2 + 1;
      } while (bVar24);
      if (bVar24) {
        iVar8 = ssl_cipher_process_rulestr(ppvVar10);
        local_58 = param_4 + 7;
        if (param_4[7] == ':') {
          local_58 = param_4 + 8;
        }
        if (iVar8 == 0) {
          CRYPTO_free(ppvVar10);
          goto LAB_080c941e;
        }
      }
      if (*local_58 == '\0') {
        CRYPTO_free(ppvVar10);
      }
      else {
        iVar8 = ssl_cipher_process_rulestr(ppvVar10);
        CRYPTO_free(ppvVar10);
        if (iVar8 == 0) goto LAB_080c941e;
      }
      st = sk_new_null();
      if (st != (_STACK *)0x0) {
        for (; ppvVar17 != (void **)0x0; ppvVar17 = (void **)ppvVar17[3]) {
          while (ppvVar17[1] != (void *)0x0) {
            sk_push(st,*ppvVar17);
            ppvVar17 = (void **)ppvVar17[3];
            if (ppvVar17 == (void **)0x0) goto LAB_080c933b;
          }
        }
LAB_080c933b:
        CRYPTO_free(ptr);
        p_Var12 = sk_dup(st);
        if (p_Var12 == (_STACK *)0x0) {
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
          *param_3 = p_Var12;
          sk_set_cmp_func(p_Var12,ssl_cipher_ptr_id_cmp);
          sk_sort(*param_3);
        }
        goto LAB_080c93af;
      }
    }
LAB_080c941e:
    CRYPTO_free(ptr);
    st = (_STACK *)0x0;
  }
LAB_080c93af:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return st;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

