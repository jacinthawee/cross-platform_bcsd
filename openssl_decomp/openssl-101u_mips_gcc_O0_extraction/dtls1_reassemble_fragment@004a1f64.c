
uint dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  uint uVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  byte *pbVar15;
  void *pvVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  uint uVar20;
  undefined4 *ptr;
  undefined4 local_134;
  uint local_130;
  undefined auStack_12c [256];
  void *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar20 = param_2[4];
  local_2c = *(void **)PTR___stack_chk_guard_006a9ae8;
  if ((uint)param_2[1] < uVar20 + param_2[3]) {
LAB_004a2040:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x108);
    if (uVar4 < 0x454c) {
      uVar4 = 0x454c;
    }
    if (uVar4 < (uint)param_2[1]) goto LAB_004a2040;
    if (uVar20 == 0) goto LAB_004a2190;
    local_134 = 0;
    local_130 = (uint)*(ushort *)(param_2 + 2);
    iVar5 = (*(code *)PTR_pqueue_find_006a82d8)
                      (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244),&local_134);
    if (iVar5 == 0) {
      uVar4 = param_2[1];
      ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
      if (ptr == (undefined4 *)0x0) goto LAB_004a2040;
      if (uVar4 == 0) {
        ptr[0xb] = 0;
        pvVar6 = CRYPTO_malloc(0,"d1_both.c",199);
        if (pvVar6 != (void *)0x0) {
LAB_004a2264:
          (*(code *)PTR_memset_006a99f4)(pvVar6,0,uVar4);
          ptr[0xc] = pvVar6;
          puVar3 = ptr;
          puVar12 = param_2;
          do {
            puVar11 = puVar12;
            puVar7 = puVar3;
            puVar12 = puVar11 + 4;
            uVar19 = puVar11[1];
            uVar18 = puVar11[2];
            uVar14 = puVar11[3];
            *puVar7 = *puVar11;
            puVar7[1] = uVar19;
            puVar7[2] = uVar18;
            puVar7[3] = uVar14;
            puVar3 = puVar7 + 4;
          } while (puVar12 != param_2 + 8);
          uVar18 = puVar11[5];
          uVar14 = puVar11[6];
          puVar7[4] = *puVar12;
          puVar7[5] = uVar18;
          puVar7[6] = uVar14;
          ptr[3] = 0;
          ptr[4] = ptr[1];
          goto LAB_004a2094;
        }
      }
      else {
        pvVar16 = CRYPTO_malloc(uVar4,"d1_both.c",0xba);
        if (pvVar16 != (void *)0x0) {
          ptr[0xb] = pvVar16;
          uVar4 = uVar4 + 7 >> 3;
          pvVar6 = CRYPTO_malloc(uVar4,"d1_both.c",199);
          if (pvVar6 != (void *)0x0) goto LAB_004a2264;
          CRYPTO_free(pvVar16);
        }
      }
      uVar4 = 0xffffffff;
      CRYPTO_free(ptr);
    }
    else {
      ptr = *(undefined4 **)(iVar5 + 8);
      if (ptr[1] != param_2[1]) goto LAB_004a2040;
      if (ptr[0xc] == 0) {
        do {
          uVar4 = 0x100;
          if (uVar20 < 0x101) {
            uVar4 = uVar20;
          }
          uVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,auStack_12c,uVar4,0);
          if ((int)uVar4 < 1) goto LAB_004a20cc;
          uVar20 = uVar20 - uVar4;
          uVar4 = 0xfffffffd;
        } while (uVar20 != 0);
        goto LAB_004a204c;
      }
LAB_004a2094:
      uVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x34))
                        (param_1,0x16,ptr[0xb] + param_2[3],uVar20,0);
      if (uVar20 == uVar4) {
        if ((int)uVar20 < 1) goto LAB_004a20cc;
        if ((int)uVar20 < 9) {
          uVar4 = param_2[3];
          if ((int)uVar4 < (int)(uVar20 + uVar4)) {
            do {
              uVar8 = uVar4 & 7;
              pbVar15 = (byte *)(ptr[0xc] + ((int)uVar4 >> 3));
              uVar4 = uVar4 + 1;
              *pbVar15 = (byte)(1 << uVar8) | *pbVar15;
            } while ((int)uVar4 < (int)(uVar20 + param_2[3]));
          }
        }
        else {
          pbVar15 = (byte *)(ptr[0xc] + ((int)param_2[3] >> 3));
          *pbVar15 = *(byte *)((int)&bitmask_start_values + (param_2[3] & 7)) | *pbVar15;
          uVar4 = uVar20 + param_2[3];
          iVar13 = ((int)param_2[3] >> 3) + 1;
          iVar17 = (int)(uVar4 - 1) >> 3;
          if (iVar13 < iVar17) {
            do {
              puVar10 = (undefined *)(ptr[0xc] + iVar13);
              iVar13 = iVar13 + 1;
              *puVar10 = 0xff;
              uVar4 = uVar20 + param_2[3];
              iVar17 = (int)(uVar4 - 1) >> 3;
            } while (iVar13 < iVar17);
          }
          *(byte *)(ptr[0xc] + iVar17) =
               *(byte *)((int)&bitmask_end_values + (uVar4 & 7)) | *(byte *)(ptr[0xc] + iVar17);
        }
        uVar20 = param_2[1];
        if ((int)uVar20 < 1) {
          OpenSSLDie("d1_both.c",0x2f5,"((long)msg_hdr->msg_len) > 0");
          uVar20 = param_2[1];
        }
        pvVar16 = (void *)ptr[0xc];
        iVar13 = (int)(uVar20 - 1) >> 3;
        pcVar9 = (char *)((int)pvVar16 + iVar13);
        iVar13 = iVar13 + -1;
        if (*pcVar9 == *(char *)((int)&bitmask_end_values + (uVar20 & 7))) {
          if (iVar13 < 0) {
LAB_004a2124:
            CRYPTO_free(pvVar16);
            ptr[0xc] = 0;
          }
          else {
            cVar1 = *(char *)((int)pvVar16 + iVar13);
            while (cVar1 == -1) {
              if ((char *)((int)pvVar16 + 1) == pcVar9) goto LAB_004a2124;
              cVar1 = pcVar9[-2];
              pcVar9 = pcVar9 + -1;
            }
          }
        }
        if (iVar5 != 0) {
LAB_004a2190:
          uVar4 = 0xfffffffd;
          goto LAB_004a204c;
        }
        iVar5 = (*(code *)PTR_pitem_new_006a829c)(&local_134,ptr);
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_pqueue_insert_006a82a0)
                            (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244),iVar5);
          if (iVar5 == 0) {
            OpenSSLDie("d1_both.c",0x30a,"item != NULL");
          }
          goto LAB_004a2190;
        }
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 0xffffffff;
LAB_004a20cc:
        if (iVar5 != 0) goto LAB_004a2044;
      }
      if (ptr[5] != 0) {
        (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(ptr[6]);
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(ptr[7]);
      }
      if ((void *)ptr[0xb] != (void *)0x0) {
        CRYPTO_free((void *)ptr[0xb]);
      }
      if ((void *)ptr[0xc] != (void *)0x0) {
        CRYPTO_free((void *)ptr[0xc]);
      }
      CRYPTO_free(ptr);
    }
  }
LAB_004a2044:
  *param_3 = 0;
LAB_004a204c:
  if (local_2c == *(void **)puVar2) {
    return uVar4;
  }
  pvVar16 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar20 = *(uint *)((int)pvVar16 + 0x14);
  if (uVar20 != 0) {
    (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(*(undefined4 *)((int)pvVar16 + 0x18));
    uVar20 = (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(*(undefined4 *)((int)pvVar16 + 0x1c));
  }
  if (*(void **)((int)pvVar16 + 0x2c) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)pvVar16 + 0x2c));
  }
  if (*(void **)((int)pvVar16 + 0x30) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)pvVar16 + 0x30));
  }
  CRYPTO_free(pvVar16);
  return uVar20;
}

