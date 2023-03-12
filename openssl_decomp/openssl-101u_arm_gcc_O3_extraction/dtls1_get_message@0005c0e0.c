
/* WARNING: Could not reconcile some variable overlaps */

void dtls1_get_message(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                      uint *param_6)

{
  undefined uVar1;
  undefined2 uVar2;
  undefined uVar3;
  undefined uVar4;
  ushort uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  pitem *ppVar9;
  uint *ptr;
  pitem *item;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined *puVar13;
  uint *puVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  uint local_170 [8];
  uint local_150;
  uint local_14c;
  uint local_148;
  undefined4 local_140;
  int local_13c;
  byte local_138;
  byte local_137;
  byte local_136;
  byte local_135;
  undefined local_134;
  undefined local_133;
  byte local_132;
  byte local_131;
  byte local_130;
  byte local_12f;
  byte local_12e;
  byte local_12d;
  undefined auStack_12c [256];
  int local_2c;
  
  iVar8 = param_1[0x16];
  local_2c = __stack_chk_guard;
  if (*(int *)(iVar8 + 0x354) == 0) {
    iVar11 = param_1[0x17];
    memset((void *)(iVar11 + 0x28c),0,0x2c);
    iVar8 = param_1[0x17];
LAB_0005c166:
    *param_6 = 0;
LAB_0005c16c:
    do {
      ppVar9 = pqueue_peek(*(pqueue *)(iVar8 + 0x244));
      if (ppVar9 != (pitem *)0x0) {
        pvVar15 = ppVar9->data;
        iVar8 = param_1[0x17];
        if (*(ushort *)((int)pvVar15 + 8) < *(ushort *)(iVar8 + 0x228)) goto LAB_0005c2b8;
        if ((*(int *)((int)pvVar15 + 0x30) != 0) ||
           (*(ushort *)(iVar8 + 0x228) != *(ushort *)((int)pvVar15 + 8))) goto LAB_0005c190;
        uVar10 = *(uint *)((int)pvVar15 + 0x10);
        pqueue_pop(*(pqueue *)(iVar8 + 0x244));
        iVar8 = dtls1_preprocess_fragment(param_1,pvVar15,param_5);
        if (iVar8 == 0) {
          memcpy((void *)(*(int *)(param_1[0xf] + 4) + 0xc + *(int *)((int)pvVar15 + 0xc)),
                 *(void **)((int)pvVar15 + 0x2c),*(size_t *)((int)pvVar15 + 0x10));
        }
        if (*(int *)((int)pvVar15 + 0x14) != 0) {
          EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar15 + 0x18));
          EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar15 + 0x1c));
        }
        if (*(void **)((int)pvVar15 + 0x2c) != (void *)0x0) {
          CRYPTO_free(*(void **)((int)pvVar15 + 0x2c));
        }
        if (*(void **)((int)pvVar15 + 0x30) != (void *)0x0) {
          CRYPTO_free(*(void **)((int)pvVar15 + 0x30));
        }
        CRYPTO_free(pvVar15);
        pitem_free(ppVar9);
        if (iVar8 == 0) {
          ppVar9 = (pitem *)(uVar10 + 3);
          *param_6 = 1;
          goto LAB_0005c34a;
        }
        ssl3_send_alert(param_1,2,iVar8);
        uVar10 = 0xffffffff;
        param_1[0x11] = 0;
        *param_6 = 0;
        goto LAB_0005c69e;
      }
LAB_0005c190:
      uVar12 = *param_6;
      if (uVar12 != 0) {
        uVar10 = 0;
        ppVar9 = (pitem *)0x3;
LAB_0005c34a:
        param_1[0x11] = uVar10;
        goto LAB_0005c34c;
      }
      uVar10 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,&local_138,0xc,0);
      if ((int)uVar10 < 1) {
        param_1[6] = 3;
        ppVar9 = (pitem *)(uVar10 + 3);
        *param_6 = 0;
        goto LAB_0005c34c;
      }
      if (uVar10 != 0xc) {
        iVar8 = 0x392;
LAB_0005c436:
        iVar16 = 10;
        ERR_put_error(0x14,0xfd,0xf4,"d1_both.c",iVar8);
        goto LAB_0005c448;
      }
      uVar17 = (uint)local_12e << 8 | (uint)local_12f << 0x10 | (uint)local_12d;
      uVar18 = (uint)local_131 << 8 | (uint)local_132 << 0x10 | (uint)local_130;
      local_170[1] = (uint)local_136 << 8 | (uint)local_137 << 0x10 | (uint)local_135;
      uVar5 = CONCAT11(local_134,local_133);
      local_170[2] = (uint)uVar5;
      local_170[0] = (uint)local_138;
      local_170[3] = uVar18;
      local_170[4] = uVar17;
      local_170[5] = uVar12;
      local_170[6] = uVar12;
      local_170[7] = uVar12;
      local_150 = uVar12;
      local_14c = uVar12;
      local_148 = uVar12;
      if (*(uint *)(param_1[0x16] + 0x110) < uVar17) {
        iVar16 = 0x2f;
        ERR_put_error(0x14,0xfd,0x10f,"d1_both.c",0x3a3);
        goto LAB_0005c448;
      }
      iVar8 = param_1[0x17];
      if ((*(ushort *)(iVar8 + 0x228) != uVar5) && ((*(int *)(iVar8 + 0x254) == 0 || (uVar5 != 1))))
      {
        if (local_170[1] < uVar18 + uVar17) goto LAB_0005c466;
        local_140 = 0;
        local_13c = (uint)CONCAT11(local_133,local_134) << 0x10;
        ppVar9 = pqueue_find(*(pqueue *)(iVar8 + 0x244),(uchar *)&local_140);
        if ((ppVar9 != (pitem *)0x0) && (uVar17 != local_170[1])) {
          ppVar9 = (pitem *)0x0;
        }
        uVar10 = (uint)*(ushort *)(param_1[0x17] + 0x228);
        if (((((local_170[2] & 0xffff) <= uVar10) || (uVar10 + 10 < (local_170[2] & 0xffff))) ||
            (ppVar9 != (pitem *)0x0)) || ((uVar10 == 0 && ((char)local_170[0] == '\x14')))) {
          if (uVar17 != 0) goto LAB_0005c5e2;
          goto LAB_0005c62a;
        }
        if (uVar17 != local_170[1]) goto LAB_0005c4b0;
        uVar10 = param_1[0x42];
        if (uVar10 < 0x454c) {
          uVar10 = 0x454c;
        }
        if ((uVar17 <= uVar10) &&
           (ptr = (uint *)CRYPTO_malloc(0x34,"d1_both.c",0xb5), ptr != (uint *)0x0)) {
          if (uVar17 != 0) {
            pvVar15 = CRYPTO_malloc(uVar17,"d1_both.c",0xba);
            if (pvVar15 != (void *)0x0) {
              ptr[0xb] = (uint)pvVar15;
              ptr[0xc] = 0;
              puVar6 = ptr;
              puVar7 = local_170;
              do {
                puVar19 = puVar7;
                puVar14 = puVar6;
                uVar10 = puVar19[1];
                uVar12 = puVar19[2];
                uVar18 = puVar19[3];
                *puVar14 = *puVar19;
                puVar14[1] = uVar10;
                puVar14[2] = uVar12;
                puVar14[3] = uVar18;
                puVar6 = puVar14 + 4;
                puVar7 = puVar19 + 4;
              } while (puVar19 + 4 != &local_150);
              uVar10 = puVar19[5];
              uVar12 = puVar19[6];
              puVar14[4] = puVar19[4];
              puVar14[5] = uVar10;
              puVar14[6] = uVar12;
              uVar10 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,ptr[0xb],uVar17,0);
              if (uVar17 == uVar10) {
                if (0 < (int)uVar10) goto LAB_0005c59a;
                ppVar9 = (pitem *)(uVar10 + 3);
              }
              else {
                ppVar9 = (pitem *)0x2;
                uVar10 = 0xffffffff;
              }
              goto LAB_0005c722;
            }
            CRYPTO_free(ptr);
            goto LAB_0005c466;
          }
          ptr[0xb] = 0;
          ptr[0xc] = 0;
          puVar6 = local_170;
          puVar7 = ptr;
          do {
            puVar19 = puVar7;
            puVar14 = puVar6;
            uVar10 = puVar14[1];
            uVar12 = puVar14[2];
            uVar17 = puVar14[3];
            *puVar19 = *puVar14;
            puVar19[1] = uVar10;
            puVar19[2] = uVar12;
            puVar19[3] = uVar17;
            puVar6 = puVar14 + 4;
            puVar7 = puVar19 + 4;
          } while (puVar14 + 4 != &local_150);
          uVar10 = 0xffffffff;
          uVar12 = puVar14[5];
          uVar17 = puVar14[6];
          puVar19[4] = puVar14[4];
          puVar19[5] = uVar12;
          puVar19[6] = uVar17;
LAB_0005c59a:
          item = pitem_new((uchar *)&local_140,ptr);
          ppVar9 = (pitem *)(uVar10 + 3);
          if (item == (pitem *)0x0) {
LAB_0005c722:
            if (ptr[5] != 0) {
              EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ptr[6]);
              EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[7]);
            }
            if ((void *)ptr[0xb] != (void *)0x0) {
              CRYPTO_free((void *)ptr[0xb]);
            }
            if ((void *)ptr[0xc] != (void *)0x0) {
              CRYPTO_free((void *)ptr[0xc]);
            }
            CRYPTO_free(ptr);
            goto LAB_0005c46c;
          }
          ppVar9 = pqueue_insert(*(pqueue *)(param_1[0x17] + 0x244),item);
          if (ppVar9 != (pitem *)0x0) goto LAB_0005c62a;
          OpenSSLDie("d1_both.c",0x36b,"item != NULL");
          uVar10 = 0xfffffffd;
          goto LAB_0005c34c;
        }
LAB_0005c466:
        ppVar9 = (pitem *)0x2;
        uVar10 = 0xffffffff;
        goto LAB_0005c46c;
      }
      uVar10 = uVar17;
      if (uVar17 != 0) {
        uVar10 = 1;
      }
      if ((uVar17 == 0 || uVar17 <= local_170[1]) && (uVar17 != 0 && local_170[1] != uVar17)) {
LAB_0005c4b0:
        uVar10 = dtls1_reassemble_fragment(param_1,local_170,param_6);
        ppVar9 = (pitem *)(uVar10 + 3);
        goto LAB_0005c34c;
      }
      if (((param_1[9] != 0) || (*(int *)(iVar8 + 0x298) != 0)) || (local_138 != 0))
      goto LAB_0005c354;
      if (((local_137 != 0) || (local_136 != 0)) || (local_135 != 0)) {
        iVar8 = 0x3c7;
        goto LAB_0005c436;
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(0,*param_1,0x16,&local_138,0xc,param_1,param_1[0x1a]);
        iVar8 = param_1[0x17];
      }
      param_1[0x11] = 0;
      *param_6 = 0;
    } while( true );
  }
  *(undefined4 *)(iVar8 + 0x354) = 0;
  if ((param_4 < 0) || (*(int *)(iVar8 + 0x340) == param_4)) {
    uVar10 = *(uint *)(iVar8 + 0x33c);
    iVar8 = *(int *)(param_1[0xf] + 4);
    *param_6 = 1;
    param_1[0x11] = uVar10;
    param_1[0x10] = iVar8 + 0xc;
    goto LAB_0005c13e;
  }
  iVar8 = 0x1ef;
LAB_0005c63a:
  ERR_put_error(0x14,0xfc,0xf4,"d1_both.c",iVar8);
  ssl3_send_alert(param_1,2,10);
  uVar10 = 0xffffffff;
  *param_6 = 0;
LAB_0005c13e:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
LAB_0005c2b8:
  pqueue_pop(*(pqueue *)(iVar8 + 0x244));
  if (*(int *)((int)pvVar15 + 0x14) != 0) {
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar15 + 0x18));
    EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar15 + 0x1c));
  }
  if (*(void **)((int)pvVar15 + 0x2c) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)pvVar15 + 0x2c));
  }
  if (*(void **)((int)pvVar15 + 0x30) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)pvVar15 + 0x30));
  }
  CRYPTO_free(pvVar15);
  pitem_free(ppVar9);
  iVar8 = param_1[0x17];
  goto LAB_0005c16c;
LAB_0005c5e2:
  uVar10 = 0x100;
  if (uVar17 < 0x101) {
    uVar10 = uVar17;
  }
  uVar10 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,auStack_12c,uVar10,0);
  if (0 < (int)uVar10) goto LAB_0005c5de;
  ppVar9 = (pitem *)(uVar10 + 3);
LAB_0005c46c:
  *param_6 = 0;
  goto LAB_0005c34c;
LAB_0005c5de:
  uVar17 = uVar17 - uVar10;
  if (uVar17 == 0) goto LAB_0005c62a;
  goto LAB_0005c5e2;
LAB_0005c62a:
  ppVar9 = (pitem *)0x0;
  uVar10 = 0xfffffffd;
LAB_0005c34c:
  if ((pitem *)0x1 < ppVar9) goto LAB_0005c382;
  iVar8 = param_1[0x17];
  goto LAB_0005c166;
LAB_0005c354:
  iVar16 = dtls1_preprocess_fragment(param_1,local_170,param_5);
  if (iVar16 != 0) {
LAB_0005c448:
    ssl3_send_alert(param_1,2,iVar16);
    uVar10 = 0xffffffff;
    param_1[0x11] = 0;
    *param_6 = 0;
    goto LAB_0005c13e;
  }
  if ((uVar10 != 0) &&
     (uVar10 = (**(code **)(param_1[2] + 0x34))
                         (param_1,0x16,*(int *)(param_1[0xf] + 4) + 0xc + uVar18,uVar17,0),
     (int)uVar10 < 1)) {
    param_1[6] = 3;
    ppVar9 = (pitem *)(uVar10 + 3);
    *param_6 = 0;
    goto LAB_0005c34c;
  }
  if (uVar10 != uVar17) {
    iVar16 = 0x2f;
    ERR_put_error(0x14,0xfd,0x2f,"d1_both.c",1000);
    goto LAB_0005c448;
  }
  *param_6 = 1;
  param_1[0xd] = param_3;
  param_1[0x11] = uVar10;
LAB_0005c382:
  if ((int)uVar10 < 1) {
LAB_0005c69e:
    if (*param_6 == 0) goto LAB_0005c13e;
  }
  if ((param_4 < 0) || (*(int *)(param_1[0x16] + 0x340) == param_4)) {
    iVar8 = *(int *)(iVar11 + 0x290);
    uVar1 = *(undefined *)(iVar11 + 0x28c);
    puVar13 = *(undefined **)(param_1[0xf] + 4);
    uVar3 = (undefined)((uint)iVar8 >> 0x10);
    puVar13[1] = uVar3;
    uVar4 = (undefined)((uint)iVar8 >> 8);
    puVar13[2] = uVar4;
    puVar13[3] = (char)iVar8;
    *puVar13 = uVar1;
    puVar13[4] = (char)((ushort)*(undefined2 *)(iVar11 + 0x294) >> 8);
    uVar2 = *(undefined2 *)(iVar11 + 0x294);
    puVar13[9] = uVar3;
    puVar13[10] = uVar4;
    puVar13[5] = (char)uVar2;
    puVar13[0xb] = (char)iVar8;
    puVar13[6] = 0;
    puVar13[7] = 0;
    puVar13[8] = 0;
    if (*param_1 == 0x100) {
      puVar13 = puVar13 + 0xc;
    }
    else {
      iVar8 = iVar8 + 0xc;
    }
    ssl3_finish_mac(param_1,puVar13,iVar8);
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(0,*param_1,0x16,puVar13,iVar8,param_1,param_1[0x1a]);
    }
    memset((void *)(iVar11 + 0x28c),0,0x2c);
    iVar8 = param_1[0x17];
    if (*(int *)(iVar8 + 0x254) == 0) {
      *(short *)(iVar8 + 0x228) = *(short *)(iVar8 + 0x228) + 1;
    }
    uVar10 = param_1[0x11];
    param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
    goto LAB_0005c13e;
  }
  iVar8 = 0x206;
  goto LAB_0005c63a;
}

