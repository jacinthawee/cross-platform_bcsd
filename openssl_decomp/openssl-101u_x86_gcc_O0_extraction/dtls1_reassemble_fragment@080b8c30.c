
uint __regparm3 dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte bVar4;
  pitem *ppVar5;
  undefined4 *ptr;
  void *__s;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  int in_GS_OFFSET;
  size_t local_138;
  undefined4 local_128;
  int local_124;
  undefined local_120 [256];
  int local_20;
  
  uVar10 = param_2[4];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((uint)param_2[1] < param_2[3] + uVar10) {
LAB_080b8c76:
    uVar8 = 0xffffffff;
  }
  else {
    uVar8 = 0x454c;
    if (0x454b < *(uint *)(param_1 + 0x108)) {
      uVar8 = *(uint *)(param_1 + 0x108);
    }
    if (uVar8 < (uint)param_2[1]) goto LAB_080b8c76;
    if (uVar10 == 0) goto LAB_080b8de8;
    local_128 = 0;
    local_124 = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                               (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
    ppVar5 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),(uchar *)&local_128);
    if (ppVar5 == (pitem *)0x0) {
      local_138 = param_2[1];
      ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
      if (ptr != (undefined4 *)0x0) {
        if (local_138 == 0) {
          ptr[0xb] = 0;
          __s = CRYPTO_malloc(0,"d1_both.c",199);
          if (__s != (void *)0x0) {
LAB_080b8e8c:
            memset(__s,0,local_138);
            ptr[0xc] = __s;
            *ptr = *param_2;
            uVar2 = param_2[1];
            ptr[1] = uVar2;
            ptr[2] = param_2[2];
            ptr[3] = param_2[3];
            ptr[4] = param_2[4];
            ptr[5] = param_2[5];
            ptr[6] = param_2[6];
            ptr[7] = param_2[7];
            ptr[8] = param_2[8];
            ptr[9] = param_2[9];
            uVar3 = param_2[10];
            ptr[4] = uVar2;
            ptr[3] = 0;
            ptr[10] = uVar3;
            goto LAB_080b8d1c;
          }
        }
        else {
          pvVar7 = CRYPTO_malloc(local_138,"d1_both.c",0xba);
          if (pvVar7 != (void *)0x0) {
            ptr[0xb] = pvVar7;
            local_138 = local_138 + 7 >> 3;
            __s = CRYPTO_malloc(local_138,"d1_both.c",199);
            if (__s != (void *)0x0) goto LAB_080b8e8c;
            CRYPTO_free(pvVar7);
          }
        }
        CRYPTO_free(ptr);
      }
      goto LAB_080b8c76;
    }
    ptr = (undefined4 *)ppVar5->data;
    if (ptr[1] != param_2[1]) goto LAB_080b8c76;
    if (ptr[0xc] == 0) {
      do {
        uVar8 = 0x100;
        if (uVar10 < 0x101) {
          uVar8 = uVar10;
        }
        uVar8 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,local_120,uVar8,0);
        if ((int)uVar8 < 1) goto LAB_080b8d4a;
        uVar10 = uVar10 - uVar8;
      } while (uVar10 != 0);
      goto LAB_080b8de8;
    }
LAB_080b8d1c:
    uVar8 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,param_2[3] + ptr[0xb],uVar10,0)
    ;
    if (uVar10 == uVar8) {
      if ((int)uVar10 < 1) goto LAB_080b8d4a;
      if ((int)uVar10 < 9) {
        iVar6 = param_2[3];
        if (iVar6 < (int)(uVar10 + iVar6)) {
          do {
            pbVar11 = (byte *)((iVar6 >> 3) + ptr[0xc]);
            bVar4 = (byte)iVar6;
            iVar6 = iVar6 + 1;
            *pbVar11 = *pbVar11 | (byte)(1 << (bVar4 & 7));
          } while (iVar6 < (int)(param_2[3] + uVar10));
        }
      }
      else {
        pbVar11 = (byte *)(((int)param_2[3] >> 3) + ptr[0xc]);
        *pbVar11 = *pbVar11 | *(byte *)((int)&bitmask_start_values + (param_2[3] & 7));
        local_138 = param_2[3] + uVar10;
        iVar9 = ((int)param_2[3] >> 3) + 1;
        iVar6 = (int)(local_138 - 1) >> 3;
        if (iVar9 < iVar6) {
          do {
            *(undefined *)(ptr[0xc] + iVar9) = 0xff;
            iVar9 = iVar9 + 1;
            local_138 = param_2[3] + uVar10;
            iVar6 = (int)(local_138 - 1) >> 3;
          } while (iVar9 < iVar6);
        }
        *(byte *)(iVar6 + ptr[0xc]) =
             *(byte *)(iVar6 + ptr[0xc]) | *(byte *)((int)&bitmask_end_values + (local_138 & 7));
      }
      uVar10 = param_2[1];
      if ((int)uVar10 < 1) {
        OpenSSLDie("d1_both.c",0x2f5,"((long)msg_hdr->msg_len) > 0");
        uVar10 = param_2[1];
      }
      pvVar7 = (void *)ptr[0xc];
      iVar6 = (int)(uVar10 - 1) >> 3;
      if (*(char *)((int)pvVar7 + iVar6) == *(char *)((int)&bitmask_end_values + (uVar10 & 7))) {
        iVar9 = iVar6 + -1;
        if (iVar9 < 0) {
LAB_080b9082:
          CRYPTO_free(pvVar7);
          ptr[0xc] = 0;
        }
        else {
          cVar1 = *(char *)((int)pvVar7 + iVar6 + -1);
          while (cVar1 == -1) {
            iVar9 = iVar9 + -1;
            if (iVar9 == -1) goto LAB_080b9082;
            cVar1 = *(char *)((int)pvVar7 + iVar9);
          }
        }
      }
      if (ppVar5 != (pitem *)0x0) {
LAB_080b8de8:
        uVar8 = 0xfffffffd;
        goto LAB_080b8c82;
      }
      ppVar5 = pitem_new((uchar *)&local_128,ptr);
      if (ppVar5 != (pitem *)0x0) {
        ppVar5 = pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),ppVar5);
        if (ppVar5 == (pitem *)0x0) {
          OpenSSLDie("d1_both.c",0x30a,"item != NULL");
        }
        goto LAB_080b8de8;
      }
      uVar8 = 0xffffffff;
LAB_080b8d55:
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
      uVar8 = 0xffffffff;
LAB_080b8d4a:
      if (ppVar5 == (pitem *)0x0) goto LAB_080b8d55;
    }
  }
  *param_3 = 0;
LAB_080b8c82:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

