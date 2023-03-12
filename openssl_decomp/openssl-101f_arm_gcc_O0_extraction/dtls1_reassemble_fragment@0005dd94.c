
void dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  pitem *item;
  void *pvVar2;
  void *__s;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *ptr;
  size_t __n;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  bool bVar15;
  pitem *local_134;
  int local_130;
  undefined auStack_12c [256];
  int local_2c;
  
  uVar11 = param_2[4];
  local_2c = __TMC_END__;
  if ((uint)param_2[1] < param_2[3] + uVar11) {
LAB_0005ddca:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x108);
    if ((int)uVar4 < 0x454c) {
      uVar4 = 0x454c;
    }
    if (uVar4 < param_2[3] + uVar11) goto LAB_0005ddca;
    local_134 = (pitem *)0x0;
    local_130 = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                               (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
    item = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),(uchar *)&local_134);
    if (item == (pitem *)0x0) {
      __n = param_2[1];
      ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
      if (ptr != (undefined4 *)0x0) {
        if (__n == 0) {
          ptr[0xb] = 0;
          __s = CRYPTO_malloc(0,"d1_both.c",199);
          if (__s != (void *)0x0) {
LAB_0005dff4:
            memset(__s,0,__n);
            ptr[0xc] = __s;
            puVar1 = ptr;
            puVar10 = param_2;
            do {
              puVar9 = puVar10;
              puVar7 = puVar1;
              puVar10 = puVar9 + 4;
              uVar12 = puVar9[1];
              uVar14 = puVar9[2];
              uVar3 = puVar9[3];
              *puVar7 = *puVar9;
              puVar7[1] = uVar12;
              puVar7[2] = uVar14;
              puVar7[3] = uVar3;
              puVar1 = puVar7 + 4;
            } while (puVar10 != param_2 + 8);
            uVar3 = puVar9[5];
            uVar12 = puVar9[6];
            puVar7[4] = *puVar10;
            puVar7[5] = uVar3;
            puVar7[6] = uVar12;
            ptr[3] = 0;
            ptr[4] = ptr[1];
            goto LAB_0005de0e;
          }
        }
        else {
          pvVar2 = CRYPTO_malloc(__n,"d1_both.c",0xb9);
          if (pvVar2 != (void *)0x0) {
            ptr[0xb] = pvVar2;
            __n = __n + 7 >> 3;
            __s = CRYPTO_malloc(__n,"d1_both.c",199);
            if (__s != (void *)0x0) goto LAB_0005dff4;
            CRYPTO_free(pvVar2);
          }
        }
        CRYPTO_free(ptr);
      }
      goto LAB_0005ddca;
    }
    ptr = (undefined4 *)item->data;
LAB_0005de0e:
    if (ptr[0xc] == 0) {
      for (; uVar11 != 0; uVar11 = uVar11 - uVar4) {
        uVar4 = 0x100;
        if (uVar11 < 0x101) {
          uVar4 = uVar11;
        }
        uVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,auStack_12c,uVar4,0);
        if ((int)uVar4 < 1) goto LAB_0005de46;
      }
LAB_0005df58:
      uVar4 = 0xfffffffd;
      goto LAB_0005ddd6;
    }
    uVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,param_2[3] + ptr[0xb],uVar11,0)
    ;
    if (uVar4 == uVar11 && 0 < (int)uVar4) {
      uVar5 = param_2[3];
      if ((int)uVar11 < 9) {
        if ((int)uVar5 < (int)(uVar5 + uVar11)) {
          do {
            iVar6 = (int)uVar5 >> 3;
            uVar13 = uVar5 & 7;
            uVar5 = uVar5 + 1;
            *(byte *)(ptr[0xc] + iVar6) = *(byte *)(ptr[0xc] + iVar6) | (byte)(1 << uVar13);
          } while ((int)uVar5 < (int)(param_2[3] + uVar11));
        }
      }
      else {
        *(byte *)(ptr[0xc] + ((int)uVar5 >> 3)) =
             (&bitmask_start_values)[uVar5 & 7] | *(byte *)(ptr[0xc] + ((int)uVar5 >> 3));
        uVar5 = param_2[3] + uVar11;
        iVar8 = ((int)param_2[3] >> 3) + 1;
        iVar6 = (int)(uVar5 - 1) >> 3;
        if (iVar8 < iVar6) {
          do {
            *(undefined *)(ptr[0xc] + iVar8) = 0xff;
            iVar8 = iVar8 + 1;
            uVar5 = param_2[3] + uVar11;
            iVar6 = (int)(uVar5 - 1) >> 3;
          } while (iVar8 < iVar6);
        }
        *(byte *)(ptr[0xc] + iVar6) =
             *(byte *)((int)&bitmask_end_values + (uVar5 & 7)) | *(byte *)(ptr[0xc] + iVar6);
      }
      uVar11 = param_2[1];
      if ((int)uVar11 < 1) {
        OpenSSLDie("d1_both.c",0x294,"((long)msg_hdr->msg_len) > 0");
        uVar11 = param_2[1];
      }
      pvVar2 = (void *)ptr[0xc];
      iVar6 = (int)(uVar11 - 1) >> 3;
      if (*(char *)((int)pvVar2 + iVar6) == *(char *)((int)&bitmask_end_values + (uVar11 & 7))) {
        iVar6 = iVar6 + -1;
        if (-1 < iVar6) {
          do {
            if (*(char *)((int)pvVar2 + iVar6) != -1) goto LAB_0005ded6;
            bVar15 = iVar6 != 0;
            iVar6 = iVar6 + -1;
          } while (bVar15);
        }
        CRYPTO_free(pvVar2);
        ptr[0xc] = 0;
      }
LAB_0005ded6:
      if (item != (pitem *)0x0) goto LAB_0005df58;
      local_130 = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                                 (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
      local_134 = item;
      item = pitem_new((uchar *)&local_134,ptr);
      if (item != (pitem *)0x0) {
        pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),item);
        uVar4 = 0xfffffffd;
        goto LAB_0005ddd6;
      }
    }
LAB_0005de46:
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
    if (item != (pitem *)0x0) {
      CRYPTO_free(item);
    }
  }
  *param_3 = 0;
LAB_0005ddd6:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}

