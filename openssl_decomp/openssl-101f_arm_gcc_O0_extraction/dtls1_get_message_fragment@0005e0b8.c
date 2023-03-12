
/* WARNING: Could not reconcile some variable overlaps */

void dtls1_get_message_fragment
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               uint *param_5)

{
  ushort uVar1;
  uint *puVar2;
  pqueue pq;
  pitem *ppVar3;
  uint uVar4;
  _pitem *p_Var5;
  pitem *ppVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  pitem *ppVar10;
  void *pvVar11;
  uint num;
  uint uVar12;
  uint *puVar13;
  uint local_170 [2];
  void *local_168;
  _pitem *local_164;
  uint local_160 [4];
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
  
  local_2c = __TMC_END__;
  pq = *(pqueue *)(param_1[0x17] + 0x244);
  *param_5 = 0;
  ppVar3 = pqueue_peek(pq);
  if (((ppVar3 == (pitem *)0x0) || (pvVar11 = ppVar3->data, *(int *)((int)pvVar11 + 0x30) != 0)) ||
     (*(short *)(param_1[0x17] + 0x228) != *(short *)((int)pvVar11 + 8))) {
    uVar9 = *param_5;
    uVar4 = 0;
    if (uVar9 == 0) {
      uVar8 = 0xc;
      uVar4 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,&local_138,0xc,0);
      if ((int)uVar4 < 1) {
        uVar8 = 3;
      }
      if ((int)uVar4 < 1) {
        param_1[6] = uVar8;
        *param_5 = 0;
        goto LAB_0005e100;
      }
      if (uVar4 == 0xc) {
        iVar7 = param_1[0x17];
        uVar1 = CONCAT11(local_134,local_133);
        local_170[1] = (uint)local_136 << 8 | (uint)local_137 << 0x10 | (uint)local_135;
        uVar12 = (uint)local_131 << 8 | (uint)local_132 << 0x10 | (uint)local_130;
        num = (uint)local_12e << 8 | (uint)local_12f << 0x10 | (uint)local_12d;
        local_168 = (void *)(uint)uVar1;
        local_170[0] = (uint)local_138;
        local_164 = (_pitem *)uVar12;
        local_160[0] = num;
        local_160[1] = uVar9;
        local_160[2] = uVar9;
        local_160[3] = uVar9;
        local_150 = uVar9;
        local_14c = uVar9;
        local_148 = uVar9;
        if ((*(ushort *)(iVar7 + 0x228) != uVar1) &&
           ((*(int *)(iVar7 + 0x254) == 0 || (uVar1 != 1)))) {
          if (local_170[1] < uVar12 + num) goto LAB_0005e1f8;
          local_140 = 0;
          local_13c = (uint)CONCAT11(local_133,local_134) << 0x10;
          ppVar3 = pqueue_find(*(pqueue *)(iVar7 + 0x244),(uchar *)&local_140);
          if ((ppVar3 != (pitem *)0x0) && (num < local_170[1])) {
            ppVar3 = (pitem *)0x0;
          }
          uVar4 = (uint)*(ushort *)(param_1[0x17] + 0x228);
          if ((((((uint)local_168 & 0xffff) <= uVar4) || (uVar4 + 10 < ((uint)local_168 & 0xffff)))
              || (ppVar3 != (pitem *)0x0)) || ((uVar4 == 0 && ((char)local_170[0] == '\x14')))) {
            for (; num != 0; num = num - uVar4) {
              uVar4 = 0x100;
              if (num < 0x101) {
                uVar4 = num;
              }
              uVar4 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,auStack_12c,uVar4,0);
              if ((int)uVar4 < 1) {
                if (ppVar3 != (pitem *)0x0) goto LAB_0005e36a;
                goto LAB_0005e1fc;
              }
            }
LAB_0005e458:
            uVar4 = 0xfffffffd;
            goto LAB_0005e100;
          }
          if (num == 0) {
            ppVar3 = (pitem *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
            if (ppVar3 == (pitem *)0x0) goto LAB_0005e1f8;
            ppVar3[2].next = (_pitem *)0x0;
            *(undefined4 *)ppVar3[3].priority = 0;
            puVar2 = local_170;
            ppVar6 = ppVar3;
            do {
              ppVar10 = ppVar6;
              puVar13 = puVar2;
              uVar4 = puVar13[1];
              pvVar11 = (void *)puVar13[2];
              p_Var5 = (_pitem *)puVar13[3];
              *(uint *)ppVar10->priority = *puVar13;
              *(uint *)(ppVar10->priority + 4) = uVar4;
              ppVar10->data = pvVar11;
              ppVar10->next = p_Var5;
              puVar2 = puVar13 + 4;
              ppVar6 = ppVar10 + 1;
            } while (puVar13 + 4 != &local_150);
            uVar4 = 0xffffffff;
            uVar9 = puVar13[5];
            pvVar11 = (void *)puVar13[6];
            *(uint *)ppVar10[1].priority = puVar13[4];
            *(uint *)(ppVar10[1].priority + 4) = uVar9;
            ppVar10[1].data = pvVar11;
LAB_0005e508:
            local_140 = 0;
            local_13c = (uint)CONCAT11((char)local_168,(char)((uint)local_168 >> 8)) << 0x10;
            ppVar6 = pitem_new((uchar *)&local_140,ppVar3);
            if (ppVar6 != (pitem *)0x0) {
              pqueue_insert(*(pqueue *)(param_1[0x17] + 0x244),ppVar6);
              goto LAB_0005e458;
            }
LAB_0005e52c:
            if (*(int *)(ppVar3[1].priority + 4) != 0) {
              EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ppVar3[1].data);
              EVP_MD_CTX_destroy((EVP_MD_CTX *)ppVar3[1].next);
            }
            if (ppVar3[2].next != (_pitem *)0x0) {
              CRYPTO_free(ppVar3[2].next);
            }
            if (*(void **)ppVar3[3].priority != (void *)0x0) {
              CRYPTO_free(*(void **)ppVar3[3].priority);
            }
LAB_0005e36a:
            CRYPTO_free(ppVar3);
          }
          else {
            if (num < local_170[1]) goto LAB_0005e372;
            ppVar3 = (pitem *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
            if (ppVar3 != (pitem *)0x0) {
              p_Var5 = (_pitem *)CRYPTO_malloc(num,"d1_both.c",0xb9);
              if (p_Var5 != (_pitem *)0x0) {
                ppVar3[2].next = p_Var5;
                *(undefined4 *)ppVar3[3].priority = 0;
                ppVar6 = ppVar3;
                puVar2 = local_170;
                do {
                  puVar13 = puVar2;
                  ppVar10 = ppVar6;
                  uVar4 = puVar13[1];
                  pvVar11 = (void *)puVar13[2];
                  p_Var5 = (_pitem *)puVar13[3];
                  *(uint *)ppVar10->priority = *puVar13;
                  *(uint *)(ppVar10->priority + 4) = uVar4;
                  ppVar10->data = pvVar11;
                  ppVar10->next = p_Var5;
                  ppVar6 = ppVar10 + 1;
                  puVar2 = puVar13 + 4;
                } while (puVar13 + 4 != &local_150);
                uVar4 = puVar13[5];
                pvVar11 = (void *)puVar13[6];
                *(uint *)ppVar10[1].priority = puVar13[4];
                *(uint *)(ppVar10[1].priority + 4) = uVar4;
                ppVar10[1].data = pvVar11;
                uVar4 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,ppVar3[2].next,num,0);
                if ((num == uVar4) && (0 < (int)uVar4)) goto LAB_0005e508;
                goto LAB_0005e52c;
              }
              CRYPTO_free(ppVar3);
            }
LAB_0005e1f8:
            uVar4 = 0xffffffff;
          }
LAB_0005e1fc:
          *param_5 = 0;
          goto LAB_0005e100;
        }
        uVar9 = num;
        if (num != 0) {
          uVar9 = 1;
        }
        if ((num == 0 || num <= local_170[1]) && (num != 0 && local_170[1] != num)) {
LAB_0005e372:
          uVar4 = dtls1_reassemble_fragment(param_1,local_170,param_5);
          goto LAB_0005e100;
        }
        if (((param_1[9] == 0) && (*(int *)(iVar7 + 0x294) == 0)) && (local_138 == 0)) {
          if (((local_137 == 0) && (local_136 == 0)) && (local_135 == 0)) {
            if ((code *)param_1[0x19] != (code *)0x0) {
              (*(code *)param_1[0x19])(0,*param_1,0x16,&local_138,0xc,param_1,param_1[0x1a]);
            }
            param_1[0x11] = 0;
            uVar4 = dtls1_get_message_fragment(param_1,param_2,param_3,param_4,param_5);
            goto LAB_0005e100;
          }
          iVar7 = 0x353;
          goto LAB_0005e3e4;
        }
        uVar4 = dtls1_preprocess_fragment(param_1,local_170,param_4);
        if (uVar4 == 0) {
          param_1[0xd] = param_3;
          if ((uVar9 != 0) &&
             (uVar4 = (**(code **)(param_1[2] + 0x34))
                                (param_1,0x16,*(int *)(param_1[0xf] + 4) + 0xc + uVar12,num,0),
             uVar9 = uVar4, (int)uVar4 < 1)) {
            param_1[6] = 3;
            *param_5 = 0;
            goto LAB_0005e100;
          }
          if (uVar9 == num) {
            *param_5 = 1;
            uVar4 = uVar9;
          }
          if (uVar9 == num) {
            param_1[0x11] = uVar9;
            goto LAB_0005e100;
          }
          uVar4 = 0x2f;
          ERR_put_error(0x14,0xfd,0x2f,"d1_both.c",0x374);
        }
      }
      else {
        iVar7 = 0x327;
LAB_0005e3e4:
        uVar4 = 10;
        ERR_put_error(0x14,0xfd,0xf4,"d1_both.c",iVar7);
      }
      ssl3_send_alert(param_1,2,uVar4);
      uVar4 = 0xffffffff;
      param_1[0x11] = 0;
      *param_5 = 0;
      goto LAB_0005e100;
    }
  }
  else {
    uVar4 = *(uint *)((int)pvVar11 + 0x10);
    pqueue_pop(*(pqueue *)(param_1[0x17] + 0x244));
    iVar7 = dtls1_preprocess_fragment(param_1,pvVar11,param_4);
    if (iVar7 == 0) {
      memcpy((void *)(*(int *)(param_1[0xf] + 4) + 0xc + *(int *)((int)pvVar11 + 0xc)),
             *(void **)((int)pvVar11 + 0x2c),*(size_t *)((int)pvVar11 + 0x10));
    }
    if (*(int *)((int)pvVar11 + 0x14) != 0) {
      EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar11 + 0x18));
      EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar11 + 0x1c));
    }
    if (*(void **)((int)pvVar11 + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar11 + 0x2c));
    }
    if (*(void **)((int)pvVar11 + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar11 + 0x30));
    }
    CRYPTO_free(pvVar11);
    pitem_free(ppVar3);
    if (iVar7 != 0) {
      ssl3_send_alert(param_1,2,iVar7);
      uVar4 = 0xffffffff;
      param_1[0x11] = 0;
      *param_5 = 0;
      goto LAB_0005e100;
    }
    *param_5 = 1;
  }
  param_1[0x11] = uVar4;
LAB_0005e100:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}

