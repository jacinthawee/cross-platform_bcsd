
undefined4 dtls1_process_record(int param_1,uint *param_2,uint *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *len;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint *puVar20;
  int iVar21;
  undefined4 auStack_ac [16];
  undefined4 auStack_6c [16];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar2 = *(int *)(param_1 + 0x4c) + 0xd;
  iVar18 = *(int *)(param_1 + 0x58);
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar19 = *(int *)(param_1 + 0xc0);
  *(int *)(iVar18 + 0x11c) = iVar2;
  if (*(uint *)(iVar18 + 0x110) < 0x4541) {
    iVar7 = *(int *)(param_1 + 8);
    *(int *)(iVar18 + 0x118) = iVar2;
    puVar9 = (undefined4 *)0x0;
    iVar2 = (***(code ***)(iVar7 + 100))();
    if (iVar2 != 0) {
      if (((iVar19 != 0) && (*(int *)(param_1 + 0x80) != 0)) &&
         (iVar19 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x84)),
         iVar19 != 0)) {
        uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(*(undefined4 *)(param_1 + 0x84));
        len = (uint *)(*(code *)PTR_EVP_MD_size_006a7e3c)(uVar3);
        if (&DAT_00000040 < len) {
          OpenSSLDie("d1_pkt.c",0x201,"mac_size <= EVP_MAX_MD_SIZE");
        }
        puVar20 = (uint *)((*(uint *)(iVar18 + 0x10c) >> 8) + *(int *)(iVar18 + 0x110));
        if ((len <= puVar20) &&
           ((uVar4 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a8108)(*(undefined4 *)(param_1 + 0x80)),
            (uVar4 & 0xf0007) != 2 || ((uint *)((int)len + 1) <= puVar20)))) {
          uVar4 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a8108)(*(undefined4 *)(param_1 + 0x80));
          if ((uVar4 & 0xf0007) == 2) {
            puVar5 = auStack_6c;
            ssl3_cbc_copy_mac(puVar5,iVar18 + 0x10c,len,puVar20);
            puVar9 = auStack_ac;
            param_3 = (uint *)0x0;
            iVar19 = *(int *)(*(int *)(param_1 + 8) + 100);
            *(int *)(iVar18 + 0x110) = *(int *)(iVar18 + 0x110) - (int)len;
            iVar19 = (**(code **)(iVar19 + 4))(param_1,puVar9,0);
            if (-1 < iVar19) goto LAB_0049e468;
LAB_0049e480:
            iVar2 = -1;
          }
          else {
            puVar9 = auStack_ac;
            param_3 = (uint *)0x0;
            iVar21 = *(int *)(iVar18 + 0x118);
            iVar19 = *(int *)(*(int *)(param_1 + 8) + 100);
            iVar7 = *(int *)(iVar18 + 0x110) - (int)len;
            *(int *)(iVar18 + 0x110) = iVar7;
            iVar19 = (**(code **)(iVar19 + 4))(param_1,puVar9,0);
            if ((iVar19 < 0) ||
               (puVar5 = (undefined4 *)(iVar21 + iVar7), puVar9 = puVar5,
               puVar5 == (undefined4 *)0x0)) goto LAB_0049e480;
LAB_0049e468:
            param_3 = len;
            iVar19 = CRYPTO_memcmp(auStack_ac,puVar5,(size_t)len);
            puVar9 = puVar5;
            if (iVar19 != 0) goto LAB_0049e480;
          }
          if (len + 0x1100 < *(uint **)(iVar18 + 0x110)) goto LAB_0049e498;
          goto LAB_0049e4a8;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x101,0xa0,"d1_pkt.c",0x213);
        param_3 = (uint *)&DAT_00000032;
        goto LAB_0049e2f8;
      }
LAB_0049e4a8:
      if (-1 < iVar2) {
        if (*(int *)(param_1 + 0x88) != 0) {
          if (0x4400 < *(uint *)(iVar18 + 0x110)) {
            uVar11 = 0x8c;
            uVar3 = 0x23f;
            goto LAB_0049e2e0;
          }
          iVar2 = ssl3_do_uncompress(param_1);
          if (iVar2 == 0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x101,0x6b,"d1_pkt.c",0x244);
            param_3 = (uint *)0x1e;
            goto LAB_0049e2f8;
          }
        }
        if (*(uint *)(iVar18 + 0x110) < 0x4001) {
          iVar2 = *(int *)(param_1 + 0x58);
          param_3 = param_2 + 1;
          *(undefined4 *)(iVar18 + 0x114) = 0;
          *(undefined4 *)(param_1 + 0x50) = 0;
          uVar4 = (uint)*(byte *)(iVar2 + 0xf) - (uint)*(byte *)((int)param_2 + 0xb);
          if ((uVar4 & 0x80) == 0) {
            uVar15 = ((uint)*(byte *)(iVar2 + 0xe) - (uint)*(byte *)((int)param_2 + 10)) +
                     ((int)uVar4 >> 8);
            uVar16 = ((uint)*(byte *)(iVar2 + 0xd) - (uint)*(byte *)((int)param_2 + 9)) +
                     ((int)uVar15 >> 8);
            uVar17 = ((uint)*(byte *)(iVar2 + 0xc) - (uint)*(byte *)(param_2 + 2)) +
                     ((int)uVar16 >> 8);
            uVar14 = ((uint)*(byte *)(iVar2 + 0xb) - (uint)*(byte *)((int)param_2 + 7)) +
                     ((int)uVar17 >> 8);
            uVar10 = ((uint)*(byte *)(iVar2 + 10) - (uint)*(byte *)((int)param_2 + 6)) +
                     ((int)uVar14 >> 8);
            puVar9 = (undefined4 *)(uVar15 | uVar16 | uVar17 | uVar14 | uVar10);
            uVar14 = ((uint)*(byte *)(iVar2 + 9) - (uint)*(byte *)((int)param_2 + 5)) +
                     ((int)uVar10 >> 8);
            uVar10 = ((uint)*(byte *)(iVar2 + 8) - (uint)*(byte *)(param_2 + 1)) +
                     ((int)uVar14 >> 8);
            uVar14 = uVar10 | (uint)puVar9 | uVar14;
          }
          else {
            uVar16 = ((uint)*(byte *)(iVar2 + 0xe) - (uint)*(byte *)((int)param_2 + 10)) +
                     ((int)uVar4 >> 8);
            uVar17 = ((uint)*(byte *)(iVar2 + 0xd) - (uint)*(byte *)((int)param_2 + 9)) +
                     ((int)uVar16 >> 8);
            uVar15 = ((uint)*(byte *)(iVar2 + 0xc) - (uint)*(byte *)(param_2 + 2)) +
                     ((int)uVar17 >> 8);
            uVar14 = ((uint)*(byte *)(iVar2 + 0xb) - (uint)*(byte *)((int)param_2 + 7)) +
                     ((int)uVar15 >> 8);
            uVar10 = ((uint)*(byte *)(iVar2 + 10) - (uint)*(byte *)((int)param_2 + 6)) +
                     ((int)uVar14 >> 8);
            puVar9 = (undefined4 *)(uVar10 & uVar14 & uVar15 & uVar16 & uVar17);
            uVar14 = ((uint)*(byte *)(iVar2 + 9) - (uint)*(byte *)((int)param_2 + 5)) +
                     ((int)uVar10 >> 8);
            uVar10 = ((uint)*(byte *)(iVar2 + 8) - (uint)*(byte *)(param_2 + 1)) +
                     ((int)uVar14 >> 8);
            uVar14 = ~(uVar10 & uVar14 & (uint)puVar9);
          }
          uVar10 = ((int)uVar10 >> 8) * 0x100;
          if ((uVar14 & 0xff) == 0) {
            uVar10 = (uVar4 & 0xff) + uVar10;
          }
          else {
            uVar10 = uVar10 | 0x80;
          }
          if ((int)uVar10 < 1) {
            puVar9 = (undefined4 *)0x1;
            if ((int)-uVar10 < 0x20) {
              uVar3 = 1;
              *param_2 = *param_2 | 1 << (-uVar10 & 0x1f);
            }
            else {
              uVar3 = 1;
            }
          }
          else {
            if ((int)uVar10 < 0x20) {
              *param_2 = *param_2 << (uVar10 & 0x1f) | 1;
            }
            else {
              *param_2 = 1;
            }
            uVar3 = 1;
            uVar4 = *(uint *)(iVar2 + 0xc);
            *param_3 = *(uint *)(iVar2 + 8);
            param_2[2] = uVar4;
          }
          goto LAB_0049e310;
        }
        uVar11 = 0x92;
        uVar3 = 0x24b;
        goto LAB_0049e2e0;
      }
    }
LAB_0049e498:
    *(undefined4 *)(iVar18 + 0x110) = 0;
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    uVar11 = 0x96;
    uVar3 = 0x1dc;
LAB_0049e2e0:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x101,uVar11,"d1_pkt.c",uVar3);
    param_3 = (uint *)&DAT_00000016;
LAB_0049e2f8:
    puVar9 = (undefined4 *)&SUB_00000002;
    ssl3_send_alert(param_1,2,param_3);
    uVar3 = 0;
  }
LAB_0049e310:
  if (local_2c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar5 = (undefined4 *)CRYPTO_malloc(0x3c,"d1_pkt.c",0xe6);
  iVar18 = (*(code *)PTR_pitem_new_006a829c)(param_3,puVar5);
  if (puVar5 == (undefined4 *)0x0) {
    if (iVar18 != 0) {
      (*(code *)PTR_pitem_free_006a8278)(iVar18);
    }
  }
  else {
    puVar6 = puVar5 + 6;
    if (iVar18 != 0) {
      iVar19 = *(int *)(iVar2 + 0x58);
      uVar3 = *(undefined4 *)(iVar2 + 0x50);
      *puVar5 = *(undefined4 *)(iVar2 + 0x4c);
      puVar5[1] = uVar3;
      uVar12 = *(undefined4 *)(iVar19 + 0xf0);
      uVar11 = *(undefined4 *)(iVar19 + 0xf4);
      uVar3 = *(undefined4 *)(iVar19 + 0xf8);
      puVar5[2] = *(undefined4 *)(iVar19 + 0xec);
      puVar5[3] = uVar12;
      puVar5[4] = uVar11;
      puVar5[5] = uVar3;
      iVar19 = *(int *)(iVar2 + 0x58);
      puVar8 = (undefined4 *)(iVar19 + 0x10c);
      do {
        uVar13 = *puVar8;
        uVar12 = puVar8[1];
        uVar11 = puVar8[2];
        uVar3 = puVar8[3];
        puVar8 = puVar8 + 4;
        *puVar6 = uVar13;
        puVar6[1] = uVar12;
        puVar6[2] = uVar11;
        puVar6[3] = uVar3;
        puVar1 = PTR_memset_006a99f4;
        puVar6 = puVar6 + 4;
      } while (puVar8 != (undefined4 *)(iVar19 + 300));
      *puVar6 = *puVar8;
      *(undefined4 **)(iVar18 + 8) = puVar5;
      *(undefined4 *)(iVar2 + 0x4c) = 0;
      *(undefined4 *)(iVar2 + 0x50) = 0;
      (*(code *)puVar1)(*(int *)(iVar2 + 0x58) + 0xec,0,0x10);
      (*(code *)PTR_memset_006a99f4)(*(int *)(iVar2 + 0x58) + 0x10c,0,0x24);
      iVar2 = ssl3_setup_buffers(iVar2);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_pqueue_insert_006a82a0)(*puVar9,iVar18);
        if (iVar2 != 0) {
          return 1;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf7,0x44,"d1_pkt.c",0x113);
        if ((void *)puVar5[2] != (void *)0x0) {
          CRYPTO_free((void *)puVar5[2]);
        }
        CRYPTO_free(puVar5);
        (*(code *)PTR_pitem_free_006a8278)(iVar18);
        return 0xffffffff;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf7,0x44,"d1_pkt.c",0x109);
      if ((void *)puVar5[2] != (void *)0x0) {
        CRYPTO_free((void *)puVar5[2]);
      }
      CRYPTO_free(puVar5);
      (*(code *)PTR_pitem_free_006a8278)(iVar18);
      return 0xffffffff;
    }
    CRYPTO_free(puVar5);
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf7,0x44,"d1_pkt.c",0xee);
  return 0xffffffff;
}

