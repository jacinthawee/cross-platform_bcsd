
undefined4 dtls1_process_record(int param_1,undefined4 param_2,uint param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  undefined4 auStack_ac [16];
  undefined4 auStack_6c [16];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)(param_1 + 0x4c) + 0xd;
  iVar17 = *(int *)(param_1 + 0x58);
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar18 = *(int *)(param_1 + 0xc0);
  *(int *)(iVar17 + 0x11c) = iVar2;
  if (*(uint *)(iVar17 + 0x110) < 0x4541) {
    iVar8 = *(int *)(param_1 + 8);
    *(int *)(iVar17 + 0x118) = iVar2;
    puVar11 = (undefined4 *)0x0;
    iVar2 = (***(code ***)(iVar8 + 100))();
    if (iVar2 != 0) {
      if (((iVar18 != 0) && (*(int *)(param_1 + 0x80) != 0)) &&
         (iVar18 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x84)),
         iVar18 != 0)) {
        uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x84));
        uVar4 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar3);
        if (0x40 < uVar4) {
          OpenSSLDie("d1_pkt.c",0x1ba,"mac_size <= EVP_MAX_MD_SIZE");
        }
        uVar19 = (*(uint *)(iVar17 + 0x10c) >> 8) + *(int *)(iVar17 + 0x110);
        if ((uVar4 <= uVar19) &&
           ((uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)(*(undefined4 *)(param_1 + 0x80)),
            (uVar5 & 0xf0007) != 2 || (uVar4 + 1 <= uVar19)))) {
          uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)(*(undefined4 *)(param_1 + 0x80));
          if ((uVar5 & 0xf0007) == 2) {
            puVar6 = auStack_6c;
            ssl3_cbc_copy_mac(puVar6,iVar17 + 0x10c,uVar4,uVar19);
            puVar11 = auStack_ac;
            param_3 = 0;
            iVar18 = *(int *)(*(int *)(param_1 + 8) + 100);
            *(uint *)(iVar17 + 0x110) = *(int *)(iVar17 + 0x110) - uVar4;
            iVar18 = (**(code **)(iVar18 + 4))(param_1,puVar11,0);
            if (-1 < iVar18) goto LAB_004a1bdc;
LAB_004a1bf4:
            iVar2 = -1;
          }
          else {
            puVar11 = auStack_ac;
            param_3 = 0;
            iVar20 = *(int *)(iVar17 + 0x118);
            iVar18 = *(int *)(*(int *)(param_1 + 8) + 100);
            iVar8 = *(int *)(iVar17 + 0x110) - uVar4;
            *(int *)(iVar17 + 0x110) = iVar8;
            iVar18 = (**(code **)(iVar18 + 4))(param_1,puVar11,0);
            if ((iVar18 < 0) ||
               (puVar6 = (undefined4 *)(iVar20 + iVar8), puVar11 = puVar6,
               puVar6 == (undefined4 *)0x0)) goto LAB_004a1bf4;
LAB_004a1bdc:
            param_3 = uVar4;
            iVar18 = CRYPTO_memcmp(auStack_ac,puVar6,uVar4);
            puVar11 = puVar6;
            if (iVar18 != 0) goto LAB_004a1bf4;
          }
          if (uVar4 + 0x4400 < *(uint *)(iVar17 + 0x110)) goto LAB_004a1c0c;
          goto LAB_004a1c1c;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x101,0xa0,"d1_pkt.c",0x1ca);
        param_3 = 0x32;
        goto LAB_004a1a70;
      }
LAB_004a1c1c:
      if (-1 < iVar2) {
        if (*(int *)(param_1 + 0x88) != 0) {
          if (0x4400 < *(uint *)(iVar17 + 0x110)) {
            uVar12 = 0x8c;
            uVar3 = 0x1f7;
            goto LAB_004a1a58;
          }
          iVar2 = ssl3_do_uncompress(param_1);
          if (iVar2 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x101,0x6b,"d1_pkt.c",0x1fd);
            param_3 = 0x1e;
            goto LAB_004a1a70;
          }
        }
        if (*(uint *)(iVar17 + 0x110) < 0x4001) {
          iVar2 = *(int *)(param_1 + 0x5c);
          iVar18 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar17 + 0x114) = 0;
          *(undefined4 *)(param_1 + 0x50) = 0;
          uVar4 = (uint)*(byte *)(iVar18 + 0xf) - (uint)*(byte *)(iVar2 + 0x217);
          if ((uVar4 & 0x80) == 0) {
            uVar15 = ((uint)*(byte *)(iVar18 + 0xe) - (uint)*(byte *)(iVar2 + 0x216)) +
                     ((int)uVar4 >> 8);
            uVar16 = ((uint)*(byte *)(iVar18 + 0xd) - (uint)*(byte *)(iVar2 + 0x215)) +
                     ((int)uVar15 >> 8);
            uVar21 = ((uint)*(byte *)(iVar18 + 0xc) - (uint)*(byte *)(iVar2 + 0x214)) +
                     ((int)uVar16 >> 8);
            uVar5 = ((uint)*(byte *)(iVar18 + 0xb) - (uint)*(byte *)(iVar2 + 0x213)) +
                    ((int)uVar21 >> 8);
            uVar19 = ((uint)*(byte *)(iVar18 + 10) - (uint)*(byte *)(iVar2 + 0x212)) +
                     ((int)uVar5 >> 8);
            param_3 = uVar15 | uVar16 | uVar21 | uVar5 | uVar19;
            uVar19 = ((uint)*(byte *)(iVar18 + 9) - (uint)*(byte *)(iVar2 + 0x211)) +
                     ((int)uVar19 >> 8);
            puVar11 = (undefined4 *)(param_3 | uVar19);
            puVar9 = (undefined *)
                     (((uint)*(byte *)(iVar18 + 8) - (uint)*(byte *)(iVar2 + 0x210)) +
                     ((int)uVar19 >> 8));
            uVar19 = (uint)puVar9 | (uint)puVar11;
          }
          else {
            uVar16 = ((uint)*(byte *)(iVar18 + 0xe) - (uint)*(byte *)(iVar2 + 0x216)) +
                     ((int)uVar4 >> 8);
            uVar21 = ((uint)*(byte *)(iVar18 + 0xd) - (uint)*(byte *)(iVar2 + 0x215)) +
                     ((int)uVar16 >> 8);
            uVar15 = ((uint)*(byte *)(iVar18 + 0xc) - (uint)*(byte *)(iVar2 + 0x214)) +
                     ((int)uVar21 >> 8);
            uVar5 = ((uint)*(byte *)(iVar18 + 0xb) - (uint)*(byte *)(iVar2 + 0x213)) +
                    ((int)uVar15 >> 8);
            uVar19 = ((uint)*(byte *)(iVar18 + 10) - (uint)*(byte *)(iVar2 + 0x212)) +
                     ((int)uVar5 >> 8);
            puVar11 = (undefined4 *)((uint)*(byte *)(iVar18 + 8) - (uint)*(byte *)(iVar2 + 0x210));
            param_3 = uVar19 & uVar5 & uVar15 & uVar16 & uVar21;
            uVar19 = ((uint)*(byte *)(iVar18 + 9) - (uint)*(byte *)(iVar2 + 0x211)) +
                     ((int)uVar19 >> 8);
            puVar9 = (undefined *)((int)puVar11 + ((int)uVar19 >> 8));
            uVar19 = ~((uint)puVar9 & uVar19 & param_3);
          }
          uVar5 = ((int)puVar9 >> 8) * 0x100;
          if ((uVar19 & 0xff) == 0) {
            uVar5 = (uVar4 & 0xff) + uVar5;
          }
          else {
            uVar5 = uVar5 | 0x80;
          }
          if ((int)uVar5 < 1) {
            param_3 = 1;
            if ((int)-uVar5 < 0x20) {
              puVar11 = *(undefined4 **)(iVar2 + 0x20c);
              uVar3 = 1;
              *(uint *)(iVar2 + 0x20c) = (uint)puVar11 | 1 << (-uVar5 & 0x1f);
            }
            else {
              uVar3 = 1;
            }
          }
          else {
            if ((int)uVar5 < 0x20) {
              *(uint *)(iVar2 + 0x20c) = *(int *)(iVar2 + 0x20c) << (uVar5 & 0x1f) | 1;
            }
            else {
              *(undefined4 *)(iVar2 + 0x20c) = 1;
            }
            puVar11 = *(undefined4 **)(iVar18 + 8);
            uVar3 = 1;
            uVar12 = *(undefined4 *)(iVar18 + 0xc);
            *(undefined4 **)(iVar2 + 0x210) = puVar11;
            *(undefined4 *)(iVar2 + 0x214) = uVar12;
          }
          goto LAB_004a1a88;
        }
        uVar12 = 0x92;
        uVar3 = 0x205;
        goto LAB_004a1a58;
      }
    }
LAB_004a1c0c:
    *(undefined4 *)(iVar17 + 0x110) = 0;
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    uVar12 = 0x96;
    uVar3 = 0x197;
LAB_004a1a58:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x101,uVar12,"d1_pkt.c",uVar3);
    param_3 = 0x16;
LAB_004a1a70:
    puVar11 = (undefined4 *)&SUB_00000002;
    ssl3_send_alert(param_1,2,param_3);
    uVar3 = 0;
  }
LAB_004a1a88:
  if (local_2c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar17 = (*(code *)PTR_pqueue_size_006a93b8)(*puVar11);
  if (99 < iVar17) {
    return 0;
  }
  puVar6 = (undefined4 *)CRYPTO_malloc(0x3c,"d1_pkt.c",0xd8);
  iVar17 = (*(code *)PTR_pitem_new_006a93bc)(param_3,puVar6);
  if (puVar6 == (undefined4 *)0x0) {
    if (iVar17 != 0) {
      (*(code *)PTR_pitem_free_006a939c)(iVar17);
    }
  }
  else {
    if (iVar17 != 0) {
      iVar18 = *(int *)(iVar2 + 0x58);
      puVar7 = puVar6 + 6;
      uVar3 = *(undefined4 *)(iVar2 + 0x50);
      *puVar6 = *(undefined4 *)(iVar2 + 0x4c);
      puVar6[1] = uVar3;
      uVar13 = *(undefined4 *)(iVar18 + 0xf0);
      uVar12 = *(undefined4 *)(iVar18 + 0xf4);
      uVar3 = *(undefined4 *)(iVar18 + 0xf8);
      puVar6[2] = *(undefined4 *)(iVar18 + 0xec);
      puVar6[3] = uVar13;
      puVar6[4] = uVar12;
      puVar6[5] = uVar3;
      iVar18 = *(int *)(iVar2 + 0x58);
      puVar10 = (undefined4 *)(iVar18 + 0x10c);
      do {
        uVar14 = *puVar10;
        uVar13 = puVar10[1];
        uVar12 = puVar10[2];
        uVar3 = puVar10[3];
        puVar10 = puVar10 + 4;
        *puVar7 = uVar14;
        puVar7[1] = uVar13;
        puVar7[2] = uVar12;
        puVar7[3] = uVar3;
        puVar1 = PTR_pqueue_insert_006a93c0;
        puVar7 = puVar7 + 4;
      } while (puVar10 != (undefined4 *)(iVar18 + 300));
      *puVar7 = *puVar10;
      *(undefined4 **)(iVar17 + 8) = puVar6;
      iVar18 = (*(code *)puVar1)(*puVar11,iVar17);
      puVar1 = PTR_memset_006aab00;
      if (iVar18 != 0) {
        *(undefined4 *)(iVar2 + 0x4c) = 0;
        *(undefined4 *)(iVar2 + 0x50) = 0;
        (*(code *)puVar1)(*(int *)(iVar2 + 0x58) + 0xec,0,0x10);
        (*(code *)PTR_memset_006aab00)(*(int *)(iVar2 + 0x58) + 0x10c,0,0x24);
        iVar2 = ssl3_setup_buffers(iVar2);
        if (iVar2 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf7,0x44,"d1_pkt.c",0x101);
          CRYPTO_free(puVar6);
          (*(code *)PTR_pitem_free_006a939c)(iVar17);
          return 0;
        }
        return 1;
      }
      CRYPTO_free(puVar6);
      (*(code *)PTR_pitem_free_006a939c)(iVar17);
      return 0;
    }
    CRYPTO_free(puVar6);
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf7,0x44,"d1_pkt.c",0xdf);
  return 0;
}

