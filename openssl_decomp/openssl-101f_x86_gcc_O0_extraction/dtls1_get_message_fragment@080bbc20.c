
uint __regparm3
dtls1_get_message_fragment
          (undefined4 *param_1_00,undefined4 param_2_00,pitem *param_3,undefined4 param_1,
          int *param_2)

{
  ushort uVar1;
  pitem *ppVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 *ptr;
  int iVar5;
  uint uVar6;
  uint num;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int in_GS_OFFSET;
  byte bVar11;
  char *pcVar12;
  undefined4 uVar13;
  char local_160;
  uint local_15c;
  ushort local_158;
  uint local_154;
  uint local_150;
  undefined4 local_134;
  int local_130;
  char local_12c;
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
  
  bVar11 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  *param_2 = 0;
  ppVar2 = pqueue_peek(*(pqueue *)(param_1_00[0x17] + 0x244));
  if (((ppVar2 == (pitem *)0x0) || (pvVar4 = ppVar2->data, *(int *)((int)pvVar4 + 0x30) != 0)) ||
     (*(short *)(param_1_00[0x17] + 0x228) != *(short *)((int)pvVar4 + 8))) {
    uVar6 = 0;
    if (*param_2 != 0) goto LAB_080bbc85;
    uVar6 = (**(code **)(param_1_00[2] + 0x34))(param_1_00,0x16,&local_12c,0xc,0);
    if ((int)uVar6 < 1) {
      param_1_00[6] = 3;
      *param_2 = 0;
      goto LAB_080bbc8a;
    }
    if (uVar6 == 0xc) {
      puVar3 = (undefined4 *)&local_160;
      for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + (uint)bVar11 * -2 + 1;
      }
      local_160 = local_12c;
      local_15c = (uint)local_12b << 0x10 | (uint)local_12a << 8 | (uint)local_129;
      local_158 = local_128 << 8 | local_128 >> 8;
      uVar7 = (uint)local_126 << 0x10 | (uint)local_125 << 8 | (uint)local_124;
      num = (uint)local_121 | (uint)local_122 << 8 | (uint)local_123 << 0x10;
      iVar5 = param_1_00[0x17];
      local_154 = uVar7;
      local_150 = num;
      if ((*(ushort *)(iVar5 + 0x228) != local_158) &&
         ((*(int *)(iVar5 + 0x254) == 0 || (local_158 != 1)))) {
        if (local_15c < uVar7 + num) goto LAB_080bbe32;
        local_134 = 0;
        local_130 = (uint)local_128 << 0x10;
        param_3 = pqueue_find(*(pqueue *)(iVar5 + 0x244),(uchar *)&local_134);
        if ((param_3 == (pitem *)0x0) || (num < local_15c)) {
          uVar1 = *(ushort *)(param_1_00[0x17] + 0x228);
          if (local_158 <= uVar1) {
            param_3 = (pitem *)0x0;
            goto LAB_080bbf5a;
          }
          param_3 = (pitem *)0x0;
          if ((uVar1 + 10 < (uint)local_158) || ((uVar1 == 0 && (local_160 == '\x14'))))
          goto LAB_080bbf5a;
          if (num != 0) {
            if (num < local_15c) goto LAB_080bc0b8;
            puVar3 = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
            if (puVar3 != (undefined4 *)0x0) {
              uVar13 = 0xb9;
              pcVar12 = "d1_both.c";
              ptr = puVar3;
              pvVar4 = CRYPTO_malloc(num,"d1_both.c",0xb9);
              if (pvVar4 != (void *)0x0) {
                ptr[0xb] = pvVar4;
                ptr[0xc] = 0;
                puVar8 = (undefined4 *)&local_160;
                puVar10 = ptr;
                for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar10 = *puVar8;
                  puVar8 = puVar8 + (uint)bVar11 * -2 + 1;
                  puVar10 = puVar10 + (uint)bVar11 * -2 + 1;
                }
                uVar6 = (**(code **)(param_1_00[2] + 0x34))
                                  (param_1_00,0x16,pvVar4,num,0,pcVar12,uVar13,puVar3);
                if ((0 < (int)uVar6) && (uVar6 == num)) goto LAB_080bc1dc;
                goto LAB_080bc21c;
              }
              CRYPTO_free(ptr);
            }
LAB_080bbe32:
            uVar6 = 0xffffffff;
LAB_080bbe37:
            *param_2 = 0;
            goto LAB_080bbc8a;
          }
          ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
          if (ptr == (undefined4 *)0x0) goto LAB_080bbe32;
          ptr[0xb] = 0;
          ptr[0xc] = 0;
          puVar3 = (undefined4 *)&local_160;
          puVar8 = ptr;
          for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar3;
            puVar3 = puVar3 + (uint)bVar11 * -2 + 1;
            puVar8 = puVar8 + (uint)bVar11 * -2 + 1;
          }
          uVar6 = 0xffffffff;
LAB_080bc1dc:
          puVar3 = &local_134;
          for (iVar5 = 2; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar3 = 0;
            puVar3 = puVar3 + (uint)bVar11 * -2 + 1;
          }
          local_130 = CONCAT13((char)local_158,CONCAT12((char)(local_158 >> 8),(short)local_130));
          ppVar2 = pitem_new((uchar *)&local_134,ptr);
          if (ppVar2 == (pitem *)0x0) {
LAB_080bc21c:
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
            goto LAB_080bbe37;
          }
          pqueue_insert(*(pqueue *)(param_1_00[0x17] + 0x244),ppVar2);
        }
        else {
LAB_080bbf5a:
          for (; num != 0; num = num - uVar6) {
            uVar6 = 0x100;
            if (num < 0x101) {
              uVar6 = num;
            }
            uVar6 = (**(code **)(param_1_00[2] + 0x34))(param_1_00,0x16,local_120,uVar6,0);
            if ((int)uVar6 < 1) {
              if (param_3 != (pitem *)0x0) {
                CRYPTO_free(param_3);
              }
              goto LAB_080bbe37;
            }
          }
        }
        uVar6 = 0xfffffffd;
        goto LAB_080bbc8a;
      }
      if ((num != 0) && (num < local_15c)) {
LAB_080bc0b8:
        uVar6 = dtls1_reassemble_fragment(param_2,param_3,param_2_00);
        goto LAB_080bbc8a;
      }
      if (((param_1_00[9] != 0) || (*(int *)(iVar5 + 0x294) != 0)) || (local_12c != '\0')) {
        iVar5 = dtls1_preprocess_fragment();
        if (iVar5 == 0) {
          param_1_00[0xd] = param_3;
          uVar6 = 0;
          uVar9 = 0;
          if ((num != 0) &&
             (uVar6 = (**(code **)(param_1_00[2] + 0x34))
                                (param_1_00,0x16,*(int *)(param_1_00[0xf] + 4) + 0xc + uVar7,num,0),
             uVar9 = num, (int)uVar6 < 1)) {
            param_1_00[6] = 3;
            *param_2 = 0;
            goto LAB_080bbc8a;
          }
          if (uVar6 == uVar9) {
            *param_2 = 1;
            param_1_00[0x11] = uVar6;
            goto LAB_080bbc8a;
          }
          ERR_put_error(0x14,0xfd,0x2f,"d1_both.c",0x374);
          iVar5 = 0x2f;
        }
        goto LAB_080bc04a;
      }
      if ((byte)(local_129 | local_12b | local_12a) == 0) {
        if ((code *)param_1_00[0x19] != (code *)0x0) {
          (*(code *)param_1_00[0x19])(0,*param_1_00,0x16,&local_12c,0xc,param_1_00,param_1_00[0x1a])
          ;
        }
        param_1_00[0x11] = 0;
        uVar6 = dtls1_get_message_fragment(param_1,param_2);
        goto LAB_080bbc8a;
      }
      iVar5 = 0x353;
    }
    else {
      iVar5 = 0x327;
    }
    ERR_put_error(0x14,0xfd,0xf4,"d1_both.c",iVar5);
    iVar5 = 10;
  }
  else {
    uVar6 = *(uint *)((int)pvVar4 + 0x10);
    pqueue_pop(*(pqueue *)(param_1_00[0x17] + 0x244));
    iVar5 = dtls1_preprocess_fragment();
    if (iVar5 == 0) {
      memcpy((void *)(*(int *)(param_1_00[0xf] + 4) + 0xc + *(int *)((int)pvVar4 + 0xc)),
             *(void **)((int)pvVar4 + 0x2c),*(size_t *)((int)pvVar4 + 0x10));
    }
    if (*(int *)((int)pvVar4 + 0x14) != 0) {
      EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar4 + 0x18));
      EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar4 + 0x1c));
    }
    if (*(void **)((int)pvVar4 + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar4 + 0x2c));
    }
    if (*(void **)((int)pvVar4 + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar4 + 0x30));
    }
    CRYPTO_free(pvVar4);
    pitem_free(ppVar2);
    if (iVar5 == 0) {
      *param_2 = 1;
LAB_080bbc85:
      param_1_00[0x11] = uVar6;
      goto LAB_080bbc8a;
    }
  }
LAB_080bc04a:
  ssl3_send_alert(param_1_00,2,iVar5);
  param_1_00[0x11] = 0;
  *param_2 = 0;
  uVar6 = 0xffffffff;
LAB_080bbc8a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

