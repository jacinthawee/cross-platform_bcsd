
/* WARNING: Could not reconcile some variable overlaps */

uint dtls1_get_message_fragment
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
               int *param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *ptr;
  int *piVar6;
  int *extraout_v1;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint num;
  void *pvVar12;
  int local_16c;
  uint local_168;
  uint local_164;
  uint local_160;
  uint local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  int local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  uint local_13c;
  byte local_138;
  byte local_137;
  byte local_136;
  byte local_135;
  ushort local_134;
  byte local_132;
  byte local_131;
  byte local_130;
  byte local_12f;
  byte local_12e;
  byte local_12d;
  undefined auStack_12c [256];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_pqueue_peek_006a93c4;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar9 = *(undefined4 *)(param_1[0x17] + 0x244);
  *param_5 = 0;
  iVar4 = (*(code *)puVar1)(uVar9);
  if (((iVar4 == 0) || (pvVar12 = *(void **)(iVar4 + 8), *(int *)((int)pvVar12 + 0x30) != 0)) ||
     (*(short *)(param_1[0x17] + 0x228) != *(short *)((int)pvVar12 + 8))) {
    uVar5 = 0;
    if (*param_5 == 0) {
      uVar5 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,&local_138,0xc,0);
      if ((int)uVar5 < 1) {
LAB_004a5b2c:
        param_1[6] = 3;
        *param_5 = 0;
        goto LAB_004a5768;
      }
      if (uVar5 == 0xc) {
        piVar7 = &local_16c;
        iVar4 = param_1[0x17];
        local_168 = (uint)local_137 << 0x10 | (uint)local_136 << 8 | (uint)local_135;
        uVar5 = (uint)local_132 << 0x10 | (uint)local_131 << 8 | (uint)local_130;
        num = (uint)local_12f << 0x10 | (uint)local_12e << 8 | (uint)local_12d;
        local_158 = 0;
        local_154 = 0;
        local_150 = 0;
        local_14c = 0;
        local_148 = 0;
        local_144 = 0;
        local_16c = (uint)local_138 << 0x18;
        local_164 = (uint)local_134 << 0x10;
        local_160 = uVar5;
        local_15c = num;
        if ((*(ushort *)(iVar4 + 0x228) == local_134) ||
           ((*(int *)(iVar4 + 0x254) != 0 && (local_134 == 1)))) {
          if ((num == 0) || (local_168 <= num)) {
            if (((param_1[9] == 0) && (*(int *)(iVar4 + 0x294) == 0)) && (local_138 == 0)) {
              if (((local_137 == 0) && (local_136 == 0)) && (local_135 == 0)) {
                if ((code *)param_1[0x19] != (code *)0x0) {
                  (*(code *)param_1[0x19])(0,*param_1,0x16,&local_138,0xc,param_1,param_1[0x1a]);
                }
                param_1[0x11] = 0;
                uVar5 = dtls1_get_message_fragment(param_1,param_2,param_3,param_4,param_5);
                goto LAB_004a5768;
              }
              uVar9 = 0x353;
              goto LAB_004a5be4;
            }
            iVar4 = dtls1_preprocess_fragment(param_1,piVar7,param_4);
            if (iVar4 == 0) {
              param_1[0xd] = param_3;
              if (num == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = (**(code **)(param_1[2] + 0x34))
                                  (param_1,0x16,*(int *)(param_1[0xf] + 4) + uVar5 + 0xc,num,0);
                if ((int)uVar5 < 1) goto LAB_004a5b2c;
                if (num != uVar5) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfd,0x2f,"d1_both.c",0x374);
                  iVar4 = 0x2f;
                  goto LAB_004a5ba8;
                }
              }
              *param_5 = 1;
              param_1[0x11] = uVar5;
              goto LAB_004a5768;
            }
            goto LAB_004a5ba8;
          }
        }
        else {
          if (local_168 < uVar5 + num) goto LAB_004a589c;
          param_4 = &local_140;
          local_140 = 0;
          local_13c = (uint)local_134;
          ptr = (int *)(*(code *)PTR_pqueue_find_006a93f4)(*(undefined4 *)(iVar4 + 0x244),param_4);
          if ((ptr != (int *)0x0) && (num < local_168)) {
            ptr = (int *)0x0;
          }
          uVar5 = (uint)*(ushort *)(param_1[0x17] + 0x228);
          if (((local_164 >> 0x10 <= uVar5) || (uVar5 + 10 < local_164 >> 0x10)) ||
             ((ptr != (int *)0x0 || ((uVar5 == 0 && (local_16c._0_1_ == '\x14')))))) {
            param_4 = (undefined4 *)0x100;
            if (num == 0) {
              uVar5 = 0xfffffffd;
            }
            else {
              do {
                uVar5 = 0x100;
                if (num < 0x101) {
                  uVar5 = num;
                }
                uVar5 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,auStack_12c,uVar5,0);
                if ((int)uVar5 < 1) {
                  if (ptr == (int *)0x0) goto LAB_004a58a0;
                  goto LAB_004a5adc;
                }
                num = num - uVar5;
                uVar5 = 0xfffffffd;
              } while (num != 0);
            }
            goto LAB_004a5768;
          }
          if (num == 0) goto LAB_004a5dd4;
          if (local_168 <= num) {
            ptr = (int *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
            if (ptr == (int *)0x0) goto LAB_004a589c;
            pvVar12 = CRYPTO_malloc(num,"d1_both.c",0xb9);
            if (pvVar12 == (void *)0x0) {
              uVar5 = 0xffffffff;
              CRYPTO_free(ptr);
              goto LAB_004a58a0;
            }
            ptr[0xb] = (int)pvVar12;
            ptr[0xc] = 0;
            piVar3 = ptr;
            do {
              piVar8 = piVar3;
              piVar6 = piVar7;
              piVar7 = piVar6 + 4;
              iVar11 = piVar6[1];
              iVar10 = piVar6[2];
              iVar4 = piVar6[3];
              *piVar8 = *piVar6;
              piVar8[1] = iVar11;
              piVar8[2] = iVar10;
              piVar8[3] = iVar4;
              piVar3 = piVar8 + 4;
            } while (piVar7 != &local_14c);
            iVar10 = piVar6[5];
            iVar4 = piVar6[6];
            piVar8[4] = *piVar7;
            piVar8[5] = iVar10;
            piVar8[6] = iVar4;
            uVar5 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pvVar12,num,0);
            if ((int)uVar5 < 1) goto LAB_004a5ea0;
            if (num != uVar5) goto LAB_004a5ea0;
            goto LAB_004a5e78;
          }
        }
        uVar5 = dtls1_reassemble_fragment(param_1,piVar7,param_5);
      }
      else {
        uVar9 = 0x327;
LAB_004a5be4:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfd,0xf4,"d1_both.c",uVar9);
        iVar4 = 10;
LAB_004a5ba8:
        ssl3_send_alert(param_1,2,iVar4);
        uVar5 = 0xffffffff;
        param_1[0x11] = 0;
        *param_5 = 0;
      }
      goto LAB_004a5768;
    }
  }
  else {
    uVar5 = *(uint *)((int)pvVar12 + 0x10);
    (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(param_1[0x17] + 0x244));
    param_4 = (undefined4 *)dtls1_preprocess_fragment(param_1,pvVar12,param_4);
    if (param_4 == (undefined4 *)0x0) {
      (*(code *)PTR_memcpy_006aabf4)
                (*(int *)(param_1[0xf] + 4) + *(int *)((int)pvVar12 + 0xc) + 0xc,
                 *(undefined4 *)((int)pvVar12 + 0x2c),*(undefined4 *)((int)pvVar12 + 0x10));
    }
    if (*(int *)((int)pvVar12 + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)((int)pvVar12 + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)((int)pvVar12 + 0x1c));
    }
    if (*(void **)((int)pvVar12 + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar12 + 0x2c));
    }
    if (*(void **)((int)pvVar12 + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar12 + 0x30));
    }
    CRYPTO_free(pvVar12);
    (*(code *)PTR_pitem_free_006a939c)(iVar4);
    if (param_4 != (undefined4 *)0x0) {
      ssl3_send_alert(param_1,2,param_4);
      uVar5 = 0xffffffff;
      param_1[0x11] = 0;
      *param_5 = 0;
      goto LAB_004a5768;
    }
    *param_5 = 1;
  }
  param_1[0x11] = uVar5;
LAB_004a5768:
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    piVar7 = extraout_v1;
LAB_004a5dd4:
    ptr = (int *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
    if (ptr == (int *)0x0) {
LAB_004a589c:
      uVar5 = 0xffffffff;
LAB_004a58a0:
      *param_5 = 0;
    }
    else {
      ptr[0xb] = 0;
      ptr[0xc] = 0;
      piVar3 = ptr;
      do {
        piVar8 = piVar7;
        piVar6 = piVar3;
        piVar7 = piVar8 + 4;
        iVar11 = piVar8[1];
        iVar10 = piVar8[2];
        iVar4 = piVar8[3];
        *piVar6 = *piVar8;
        piVar6[1] = iVar11;
        piVar6[2] = iVar10;
        piVar6[3] = iVar4;
        piVar3 = piVar6 + 4;
      } while (piVar7 != &local_14c);
      uVar5 = 0xffffffff;
      iVar10 = piVar8[5];
      iVar4 = piVar8[6];
      piVar6[4] = *piVar7;
      piVar6[5] = iVar10;
      piVar6[6] = iVar4;
LAB_004a5e78:
      param_4[1] = 0;
      local_140 = 0;
      local_13c = local_13c & 0xffff0000 | (uint)local_164._0_2_;
      iVar4 = (*(code *)PTR_pitem_new_006a93bc)(param_4,ptr);
      if (iVar4 == 0) {
LAB_004a5ea0:
        if (ptr[5] != 0) {
          (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(ptr[6]);
          (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(ptr[7]);
        }
        if ((void *)ptr[0xb] != (void *)0x0) {
          CRYPTO_free((void *)ptr[0xb]);
        }
        if ((void *)ptr[0xc] != (void *)0x0) {
          CRYPTO_free((void *)ptr[0xc]);
        }
LAB_004a5adc:
        CRYPTO_free(ptr);
        *param_5 = 0;
      }
      else {
        (*(code *)PTR_pqueue_insert_006a93c0)(*(undefined4 *)(param_1[0x17] + 0x244),iVar4);
        uVar5 = 0xfffffffd;
      }
    }
  }
  return uVar5;
}

