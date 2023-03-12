
void dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  pitem *ppVar2;
  void *__s;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  size_t __n;
  undefined4 uVar13;
  undefined4 *ptr;
  undefined4 uVar14;
  bool bVar15;
  undefined4 local_134;
  int local_130;
  undefined auStack_12c [256];
  int local_2c;
  
  uVar12 = param_2[4];
  local_2c = __stack_chk_guard;
  if ((uint)param_2[1] < param_2[3] + uVar12) {
LAB_0005ba36:
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x108);
    if (uVar5 < 0x454c) {
      uVar5 = 0x454c;
    }
    if (uVar5 < (uint)param_2[1]) goto LAB_0005ba36;
    if (uVar12 == 0) goto LAB_0005bb2a;
    local_134 = 0;
    local_130 = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                               (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
    ppVar2 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),(uchar *)&local_134);
    if (ppVar2 == (pitem *)0x0) {
      __n = param_2[1];
      ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
      if (ptr != (undefined4 *)0x0) {
        if (__n == 0) {
          ptr[0xb] = 0;
          __s = CRYPTO_malloc(0,"d1_both.c",199);
          if (__s != (void *)0x0) {
LAB_0005bba6:
            memset(__s,0,__n);
            ptr[0xc] = __s;
            puVar1 = ptr;
            puVar10 = param_2;
            do {
              puVar9 = puVar10;
              puVar6 = puVar1;
              puVar10 = puVar9 + 4;
              uVar14 = puVar9[1];
              uVar13 = puVar9[2];
              uVar3 = puVar9[3];
              *puVar6 = *puVar9;
              puVar6[1] = uVar14;
              puVar6[2] = uVar13;
              puVar6[3] = uVar3;
              puVar1 = puVar6 + 4;
            } while (puVar10 != param_2 + 8);
            uVar3 = puVar9[5];
            uVar13 = puVar9[6];
            puVar6[4] = *puVar10;
            puVar6[5] = uVar3;
            puVar6[6] = uVar13;
            ptr[3] = 0;
            ptr[4] = ptr[1];
            goto LAB_0005ba88;
          }
        }
        else {
          pvVar4 = CRYPTO_malloc(__n,"d1_both.c",0xba);
          if (pvVar4 != (void *)0x0) {
            ptr[0xb] = pvVar4;
            __n = __n + 7 >> 3;
            __s = CRYPTO_malloc(__n,"d1_both.c",199);
            if (__s != (void *)0x0) goto LAB_0005bba6;
            CRYPTO_free(pvVar4);
          }
        }
        CRYPTO_free(ptr);
      }
      goto LAB_0005ba36;
    }
    ptr = (undefined4 *)ppVar2->data;
    if (ptr[1] != param_2[1]) goto LAB_0005ba36;
LAB_0005ba88:
    if (ptr[0xc] == 0) {
      do {
        uVar5 = 0x100;
        if (uVar12 < 0x101) {
          uVar5 = uVar12;
        }
        uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,auStack_12c,uVar5,0);
        if ((int)uVar5 < 1) goto LAB_0005bcce;
        uVar12 = uVar12 - uVar5;
      } while (uVar12 != 0);
      goto LAB_0005bb2a;
    }
    uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,param_2[3] + ptr[0xb],uVar12,0)
    ;
    if (uVar5 == uVar12) {
      if ((int)uVar12 < 1) {
LAB_0005bcce:
        uVar12 = count_leading_zeroes(ppVar2);
        goto LAB_0005babc;
      }
      uVar7 = param_2[3];
      if ((int)uVar12 < 9) {
        if ((int)uVar7 < (int)(uVar12 + uVar7)) {
          do {
            iVar8 = (int)uVar7 >> 3;
            uVar12 = uVar7 & 7;
            uVar7 = uVar7 + 1;
            *(byte *)(ptr[0xc] + iVar8) = *(byte *)(ptr[0xc] + iVar8) | (byte)(1 << uVar12);
          } while ((int)uVar7 < (int)(param_2[3] + uVar5));
        }
      }
      else {
        *(byte *)(ptr[0xc] + ((int)uVar7 >> 3)) =
             (&bitmask_start_values)[uVar7 & 7] | *(byte *)(ptr[0xc] + ((int)uVar7 >> 3));
        uVar12 = uVar12 + param_2[3];
        iVar11 = ((int)param_2[3] >> 3) + 1;
        iVar8 = (int)(uVar12 - 1) >> 3;
        if (iVar11 < iVar8) {
          do {
            *(undefined *)(ptr[0xc] + iVar11) = 0xff;
            iVar11 = iVar11 + 1;
            uVar12 = param_2[3] + uVar5;
            iVar8 = (int)(uVar12 - 1) >> 3;
          } while (iVar11 < iVar8);
        }
        *(byte *)(ptr[0xc] + iVar8) =
             *(byte *)((int)&bitmask_end_values + (uVar12 & 7)) | *(byte *)(ptr[0xc] + iVar8);
      }
      uVar12 = param_2[1];
      if ((int)uVar12 < 1) {
        OpenSSLDie("d1_both.c",0x2f5,"((long)msg_hdr->msg_len) > 0");
        uVar12 = param_2[1];
      }
      pvVar4 = (void *)ptr[0xc];
      iVar8 = (int)(uVar12 - 1) >> 3;
      if (*(char *)((int)pvVar4 + iVar8) == *(char *)((int)&bitmask_end_values + (uVar12 & 7))) {
        iVar8 = iVar8 + -1;
        if (-1 < iVar8) {
          do {
            if (*(char *)((int)pvVar4 + iVar8) != -1) goto LAB_0005baee;
            bVar15 = iVar8 != 0;
            iVar8 = iVar8 + -1;
          } while (bVar15);
        }
        CRYPTO_free(pvVar4);
        ptr[0xc] = 0;
      }
LAB_0005baee:
      if (ppVar2 != (pitem *)0x0) {
LAB_0005bb2a:
        uVar5 = 0xfffffffd;
        goto LAB_0005ba42;
      }
      ppVar2 = pitem_new((uchar *)&local_134,ptr);
      if (ppVar2 != (pitem *)0x0) {
        ppVar2 = pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),ppVar2);
        if (ppVar2 == (pitem *)0x0) {
          OpenSSLDie("d1_both.c",0x30a,"item != NULL");
        }
        goto LAB_0005bb2a;
      }
      uVar5 = 0xffffffff;
LAB_0005bac0:
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
    }
    else {
      uVar12 = count_leading_zeroes(ppVar2);
      uVar5 = 0xffffffff;
LAB_0005babc:
      if (uVar12 >> 5 != 0) goto LAB_0005bac0;
    }
  }
  *param_3 = 0;
LAB_0005ba42:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}

