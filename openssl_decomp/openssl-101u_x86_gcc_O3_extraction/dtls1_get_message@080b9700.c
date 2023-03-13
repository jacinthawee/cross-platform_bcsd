
/* WARNING: Could not reconcile some variable overlaps */

uint dtls1_get_message(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                      int *param_6)

{
  short *psVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  undefined uVar5;
  pitem *ppVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  void *pvVar10;
  int iVar11;
  undefined uVar12;
  ushort uVar13;
  uint uVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  int in_GS_OFFSET;
  byte bVar18;
  int iVar19;
  uint local_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  undefined4 local_134;
  int local_130;
  byte local_12c;
  byte local_12b;
  byte local_12a;
  byte local_129;
  ushort local_128;
  byte local_126;
  byte local_125;
  byte local_124;
  byte local_123;
  byte local_122;
  byte local_121;
  undefined local_120 [256];
  int local_20;
  
  bVar18 = 0;
  iVar19 = param_1[0x16];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(iVar19 + 0x354) == 0) {
    iVar19 = param_1[0x17];
    *(undefined4 *)(iVar19 + 0x28c) = 0;
    *(undefined4 *)(iVar19 + 0x2b4) = 0;
    puVar16 = (undefined4 *)(iVar19 + 0x290U & 0xfffffffc);
    uVar8 = ((iVar19 + 0x28c) - (int)puVar16) + 0x2cU >> 2;
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
LAB_080b97d0:
    iVar11 = param_1[0x17];
    *param_6 = 0;
LAB_080b97e0:
    while (ppVar6 = pqueue_peek(*(pqueue *)(iVar11 + 0x244)), ppVar6 != (pitem *)0x0) {
      pvVar10 = ppVar6->data;
      iVar11 = param_1[0x17];
      if (*(ushort *)(iVar11 + 0x228) <= *(ushort *)((int)pvVar10 + 8)) {
        if ((*(int *)((int)pvVar10 + 0x30) != 0) ||
           (*(ushort *)((int)pvVar10 + 8) != *(ushort *)(iVar11 + 0x228))) break;
        uVar8 = *(uint *)((int)pvVar10 + 0x10);
        pqueue_pop(*(pqueue *)(iVar11 + 0x244));
        iVar11 = dtls1_preprocess_fragment();
        if (iVar11 == 0) {
          memcpy((void *)(*(int *)(param_1[0xf] + 4) + 0xc + *(int *)((int)pvVar10 + 0xc)),
                 *(void **)((int)pvVar10 + 0x2c),*(size_t *)((int)pvVar10 + 0x10));
        }
        if (*(int *)((int)pvVar10 + 0x14) != 0) {
          EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar10 + 0x18));
          EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar10 + 0x1c));
        }
        if (*(void **)((int)pvVar10 + 0x2c) != (void *)0x0) {
          CRYPTO_free(*(void **)((int)pvVar10 + 0x2c));
        }
        if (*(void **)((int)pvVar10 + 0x30) != (void *)0x0) {
          CRYPTO_free(*(void **)((int)pvVar10 + 0x30));
        }
        CRYPTO_free(pvVar10);
        pitem_free(ppVar6);
        if (iVar11 == 0) {
          *param_6 = 1;
          uVar17 = uVar8 + 3;
          if (uVar8 == 0) goto LAB_080b9bd3;
          goto LAB_080b9ab1;
        }
        ssl3_send_alert(param_1,2,iVar11);
        param_1[0x11] = 0;
        *param_6 = 0;
        uVar8 = 0xffffffff;
        goto LAB_080b9ff6;
      }
      pqueue_pop(*(pqueue *)(iVar11 + 0x244));
      if (*(int *)((int)pvVar10 + 0x14) != 0) {
        EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar10 + 0x18));
        EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar10 + 0x1c));
      }
      if (*(void **)((int)pvVar10 + 0x2c) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)pvVar10 + 0x2c));
      }
      if (*(void **)((int)pvVar10 + 0x30) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)pvVar10 + 0x30));
      }
      CRYPTO_free(pvVar10);
      pitem_free(ppVar6);
      iVar11 = param_1[0x17];
    }
    if (*param_6 != 0) {
LAB_080b9bd3:
      uVar8 = 0;
      uVar17 = 3;
LAB_080b9ab1:
      param_1[0x11] = uVar8;
      goto LAB_080b9ab8;
    }
    uVar8 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,&local_12c,0xc,0);
    bVar4 = local_129;
    bVar3 = local_12b;
    if ((int)uVar8 < 1) goto LAB_080b9bba;
    if (uVar8 == 0xc) {
      uVar8 = (uint)local_12b;
      puVar9 = &local_160;
      for (iVar11 = 0xb; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + (uint)bVar18 * -2 + 1;
      }
      local_160 = local_160 & 0xffffff00 | (uint)local_12c;
      local_15c = uVar8 << 0x10 | (uint)local_12a << 8 | (uint)bVar4;
      uVar13 = local_128 << 8 | local_128 >> 8;
      local_158 = local_158 & 0xffff0000 | (uint)uVar13;
      uVar7 = (uint)local_125 << 8 | (uint)local_126 << 0x10 | (uint)local_124;
      uVar17 = (uint)local_123 << 0x10 | (uint)local_122 << 8 | (uint)local_121;
      local_154 = uVar7;
      local_150 = uVar17;
      if (*(uint *)(param_1[0x16] + 0x110) < uVar17) {
        iVar11 = 0x3a3;
        iVar19 = 0x10f;
        goto LAB_080b9bfe;
      }
      iVar11 = param_1[0x17];
      if ((*(ushort *)(iVar11 + 0x228) != uVar13) &&
         ((*(int *)(iVar11 + 0x254) == 0 || (uVar13 != 1)))) {
        if (local_15c < uVar7 + uVar17) goto LAB_080b9b72;
        local_134 = 0;
        local_130 = (uint)local_128 << 0x10;
        ppVar6 = pqueue_find(*(pqueue *)(iVar11 + 0x244),(uchar *)&local_134);
        if ((ppVar6 == (pitem *)0x0) || (uVar17 != local_15c)) {
          uVar13 = *(ushort *)(param_1[0x17] + 0x228);
          if (((uVar13 < (ushort)local_158) && ((local_158 & 0xffff) <= uVar13 + 10)) &&
             ((uVar13 != 0 || ((char)local_160 != '\x14')))) {
            if (uVar17 != local_15c) {
              uVar8 = dtls1_reassemble_fragment();
              uVar17 = uVar8 + 3;
              goto LAB_080b9ab8;
            }
            uVar8 = 0x454c;
            if (0x454b < (uint)param_1[0x42]) {
              uVar8 = param_1[0x42];
            }
            if ((uVar8 < uVar17) ||
               (puVar9 = (uint *)CRYPTO_malloc(0x34,"d1_both.c",0xb5), puVar9 == (uint *)0x0)) {
LAB_080b9b72:
              uVar17 = 2;
              uVar8 = 0xffffffff;
              goto LAB_080b9b7c;
            }
            if (uVar17 == 0) {
              puVar9[0xb] = 0;
              puVar9[0xc] = 0;
              uVar8 = 0xffffffff;
              *puVar9 = local_160;
              puVar9[1] = local_15c;
              puVar9[2] = local_158;
              puVar9[3] = local_154;
              puVar9[4] = local_150;
              puVar9[5] = local_14c;
              puVar9[6] = local_148;
              puVar9[7] = local_144;
              puVar9[8] = local_140;
              puVar9[9] = local_13c;
              puVar9[10] = local_138;
LAB_080b9e3c:
              uVar17 = uVar8 + 3;
              ppVar6 = pitem_new((uchar *)&local_134,puVar9);
              if (ppVar6 != (pitem *)0x0) {
                uVar17 = 0;
                uVar8 = 0xfffffffd;
                ppVar6 = pqueue_insert(*(pqueue *)(param_1[0x17] + 0x244),ppVar6);
                if (ppVar6 == (pitem *)0x0) {
                  OpenSSLDie("d1_both.c",0x36b,"item != NULL");
                  uVar8 = 0xfffffffd;
                }
                goto LAB_080b9ab8;
              }
            }
            else {
              pvVar10 = CRYPTO_malloc(uVar17,"d1_both.c",0xba);
              if (pvVar10 == (void *)0x0) {
                CRYPTO_free(puVar9);
                goto LAB_080b9b72;
              }
              puVar9[0xb] = (uint)pvVar10;
              puVar9[0xc] = 0;
              *puVar9 = local_160;
              puVar9[1] = local_15c;
              puVar9[2] = local_158;
              puVar9[3] = local_154;
              puVar9[4] = local_150;
              puVar9[5] = local_14c;
              puVar9[6] = local_148;
              puVar9[7] = local_144;
              puVar9[8] = local_140;
              puVar9[9] = local_13c;
              puVar9[10] = local_138;
              uVar8 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pvVar10,uVar17,0);
              if (uVar17 == uVar8) {
                if (0 < (int)uVar8) goto LAB_080b9e3c;
                uVar17 = uVar8 + 3;
              }
              else {
                uVar17 = 2;
                uVar8 = 0xffffffff;
              }
            }
            if (puVar9[5] != 0) {
              EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)puVar9[6]);
              EVP_MD_CTX_destroy((EVP_MD_CTX *)puVar9[7]);
            }
            if ((void *)puVar9[0xb] != (void *)0x0) {
              CRYPTO_free((void *)puVar9[0xb]);
            }
            if ((void *)puVar9[0xc] != (void *)0x0) {
              CRYPTO_free((void *)puVar9[0xc]);
            }
            CRYPTO_free(puVar9);
            goto LAB_080b9b7c;
          }
        }
        goto joined_r0x080b9c99;
      }
      if ((uVar17 != 0) && (uVar17 < local_15c)) {
        uVar8 = dtls1_reassemble_fragment();
        uVar17 = uVar8 + 3;
        goto LAB_080b9ab8;
      }
      if (((param_1[9] != 0) || (*(int *)(iVar11 + 0x298) != 0)) || (local_12c != 0))
      goto LAB_080b9ad0;
      if ((byte)(bVar4 | bVar3 | local_12a) == 0) {
        if ((code *)param_1[0x19] != (code *)0x0) {
          (*(code *)param_1[0x19])(0,*param_1,0x16,&local_12c,0xc,param_1,param_1[0x1a]);
          iVar11 = param_1[0x17];
        }
        param_1[0x11] = 0;
        *param_6 = 0;
        goto LAB_080b97e0;
      }
      iVar19 = 0x3c7;
    }
    else {
      iVar19 = 0x392;
    }
    ERR_put_error(0x14,0xfd,0xf4,"d1_both.c",iVar19);
    uVar8 = 10;
    goto LAB_080b9b3a;
  }
  *(undefined4 *)(iVar19 + 0x354) = 0;
  if ((param_4 < 0) || (param_4 == *(int *)(iVar19 + 0x340))) {
    *param_6 = 1;
    param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
    uVar8 = *(uint *)(iVar19 + 0x33c);
    param_1[0x11] = uVar8;
    goto LAB_080b977f;
  }
  iVar19 = 0x1ef;
LAB_080b9d3a:
  ERR_put_error(0x14,0xfc,0xf4,"d1_both.c",iVar19);
  ssl3_send_alert(param_1,2,10);
  *param_6 = 0;
  uVar8 = 0xffffffff;
LAB_080b977f:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
joined_r0x080b9c99:
  if (uVar17 == 0) {
    uVar17 = 0;
    uVar8 = 0xfffffffd;
  }
  else {
    uVar8 = 0x100;
    if (uVar17 < 0x101) {
      uVar8 = uVar17;
    }
    uVar8 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,local_120,uVar8,0);
    if (0 < (int)uVar8) goto LAB_080b9ca0;
    uVar17 = uVar8 + 3;
LAB_080b9b7c:
    *param_6 = 0;
  }
  goto LAB_080b9ab8;
LAB_080b9ca0:
  uVar17 = uVar17 - uVar8;
  goto joined_r0x080b9c99;
LAB_080b9ad0:
  uVar8 = dtls1_preprocess_fragment();
  if (uVar8 != 0) {
LAB_080b9b3a:
    ssl3_send_alert(param_1,2,uVar8);
    param_1[0x11] = 0;
    *param_6 = 0;
    uVar8 = 0xffffffff;
    goto LAB_080b977f;
  }
  uVar14 = 0;
  if ((uVar17 == 0) ||
     (uVar8 = (**(code **)(param_1[2] + 0x34))
                        (param_1,0x16,*(int *)(param_1[0xf] + 4) + 0xc + uVar7,uVar17,0),
     uVar14 = uVar17, 0 < (int)uVar8)) {
    if (uVar8 != uVar14) {
      iVar11 = 1000;
      iVar19 = 0x2f;
LAB_080b9bfe:
      ERR_put_error(0x14,0xfd,iVar19,"d1_both.c",iVar11);
      uVar8 = 0x2f;
      goto LAB_080b9b3a;
    }
    uVar17 = uVar8 + 3;
    *param_6 = 1;
    param_1[0x11] = uVar8;
    param_1[0xd] = param_3;
  }
  else {
LAB_080b9bba:
    param_1[6] = 3;
    uVar17 = uVar8 + 3;
    *param_6 = 0;
  }
LAB_080b9ab8:
  if (1 < uVar17) goto code_r0x080b9ac1;
  goto LAB_080b97d0;
code_r0x080b9ac1:
  if ((int)uVar8 < 1) {
LAB_080b9ff6:
    if (*param_6 == 0) goto LAB_080b977f;
  }
  if ((param_4 < 0) || (param_4 == *(int *)(param_1[0x16] + 0x340))) {
    puVar15 = *(undefined **)(param_1[0xf] + 4);
    iVar11 = *(int *)(iVar19 + 0x290);
    *puVar15 = *(undefined *)(iVar19 + 0x28c);
    uVar5 = (undefined)((uint)iVar11 >> 8);
    puVar15[2] = uVar5;
    uVar12 = (undefined)((uint)iVar11 >> 0x10);
    puVar15[1] = uVar12;
    puVar15[3] = (char)iVar11;
    puVar15[4] = *(undefined *)(iVar19 + 0x295);
    uVar2 = *(undefined2 *)(iVar19 + 0x294);
    puVar15[10] = uVar5;
    puVar15[6] = 0;
    puVar15[7] = 0;
    puVar15[8] = 0;
    puVar15[9] = uVar12;
    puVar15[0xb] = (char)iVar11;
    puVar15[5] = (char)uVar2;
    if (*param_1 == 0x100) {
      puVar15 = puVar15 + 0xc;
    }
    else {
      iVar11 = iVar11 + 0xc;
    }
    ssl3_finish_mac(param_1,puVar15,iVar11);
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(0,*param_1,0x16,puVar15,iVar11,param_1,param_1[0x1a]);
    }
    *(undefined4 *)(iVar19 + 0x28c) = 0;
    *(undefined4 *)(iVar19 + 0x2b4) = 0;
    puVar16 = (undefined4 *)(iVar19 + 0x290U & 0xfffffffc);
    uVar8 = ((iVar19 + 0x28c) - (int)puVar16) + 0x2cU >> 2;
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar16 = 0;
      puVar16 = puVar16 + (uint)bVar18 * -2 + 1;
    }
    if (*(int *)(param_1[0x17] + 0x254) == 0) {
      psVar1 = (short *)(param_1[0x17] + 0x228);
      *psVar1 = *psVar1 + 1;
    }
    param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
    uVar8 = param_1[0x11];
    goto LAB_080b977f;
  }
  iVar19 = 0x206;
  goto LAB_080b9d3a;
}

